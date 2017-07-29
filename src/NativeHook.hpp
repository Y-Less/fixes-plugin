#pragma once

#include <stdexcept>
#include <list>

#include <subhook/subhook.h>
#include <sampgdk/interop.h>

#include "NativeFuncGen.hpp"
#include "NativeCast.hpp"

#define PLUGIN_NATIVES_HAS_HOOK

namespace plugin_natives
{
	void Load(void **ppData);

	class NativeHookBase
	{
	public:
		void Init()
		{
			// If a known native matches the stored name, install the hook.
			//Install(NULL);
		}

		void Enable()
		{
			hook_.Install();
		}

		void Disable()
		{
			hook_.Remove();
		}

		bool IsEnabled() const
		{
			return hook_.IsInstalled();
		}

	protected:
		bool Recursing()
		{
			// Get if we are already in the native, and then flip it.
			bool
				ret = recursing_;
			recursing_ = !ret;
			return ret;
		}

		NativeHookBase(unsigned int count, char const * const name, AMX_NATIVE replacement)
		:
			count_(count * sizeof (cell)),
			name_(name),
			replacement_(replacement),
			hook_(),
			amx_(0),
			params_(0),
			recursing_(false)
		{
			if (!all_)
				all_ = new std::list<NativeHookBase *>();
			if (all_)
				all_->push_back(this);
		}

		~NativeHookBase() = default;

		subhook::Hook & GetHook() { return hook_; }

		AMX * GetAMX() const { return amx_; }
		cell * GetParams() const { return params_; }
		
		cell CallDoOuter(AMX * amx, cell * params)
		{
			cell
				ret = 0;
			if (amx && params)
			{
				// Check that there are enough parameters.
				amx_ = amx;
				params_ = params;
				recursing_ = true;
				try
				{
					if (count_ > (unsigned int)params[0])
						throw std::invalid_argument("Insufficient arguments.");
					subhook::ScopedHookRemove
						undo(&hook_);
					ret = this->CallDoInner(amx, params);
				}
				catch (std::exception & e)
				{
					char
						msg[1024];
					sprintf(msg, "Exception in %s: \"%s\"", name_, e.what());
					Log(LogLevel::ERROR, msg);
				}
				catch (...)
				{
					char
						msg[1024];
					sprintf(msg, "Unknown exception in in %s", name_);
					Log(LogLevel::ERROR, msg);
					recursing_ = false;
					params_ = 0;
					amx_ = 0;
					throw;
				}
				recursing_ = false;
				params_ = 0;
				amx_ = 0;
			}
			return (cell)ret;
		}

	private:
		virtual cell CallDoInner(AMX *, cell *) = 0;

		friend int AmxLoad(AMX * amx);

		NativeHookBase() = delete;
		NativeHookBase(NativeHookBase const &) = delete;
		NativeHookBase(NativeHookBase const &&) = delete;
		NativeHookBase const & operator=(NativeHookBase const &) const = delete;
		NativeHookBase const & operator=(NativeHookBase const &&) const = delete;

		unsigned int
			count_;

		char const * const
			name_;

		AMX_NATIVE const
			replacement_;

		subhook::Hook
			hook_;

		AMX *
			amx_;

		cell *
			params_;

		bool
			recursing_;

		static std::list<NativeHookBase *> *
			all_;
	};

	template <typename FUNC_TYPE>
	class NativeHook {};

	// A pretty horrible combination of templates that make hooks quite seamless.
	template <typename RET>
	class NativeHook0 : protected NativeHookBase
	{
	public:
		typedef RET (*implementation_t)();

		class ScopedCall
		{
		public:
			inline RET operator()()
			{
				return original_();
			}

			~ScopedCall()
			{
				if (removed_)
					hook_.Install();
			}

		private:
			ScopedCall(subhook::Hook & hook, implementation_t original)
				:
				hook_(hook),
				original_(original),
				removed_(hook.Remove())
			{
			}

			ScopedCall(ScopedCall const &) = default;
			ScopedCall & operator=(ScopedCall const &) = default;

			ScopedCall(ScopedCall && that)
				:
				hook_(std::move(that.hook_)),
				original_(std::move(that.original_)),
				removed_(std::move(that.removed_))
			{
				that.removed_ = false;
			}

			ScopedCall & operator=(ScopedCall const &&) = delete;

			ScopedCall() = delete;

			friend class NativeHook0<RET>;

			subhook::Hook &
				hook_;

			implementation_t const
				original_;

			bool
				removed_;
		};

		inline RET operator()()
		{
			RET
				ret;
			if (Recursing())
			{
				subhook::ScopedHookRemove
					undo(&GetHook());
				ret = original_();
			}
			else
			{
				ret = Do();
			}
			Recursing();
			return ret;
		}

		ScopedCall operator*()
		{
			ScopedCall
				ret(GetHook(), original_);
			return ret;
		}

	protected:
		NativeHook0(char const * const name, implementation_t original, AMX_NATIVE replacement) : NativeHookBase(0, name, replacement), original_(original) {}
		~NativeHook0() = default;

	private:
		cell CallDoInner(AMX *, cell *)
		{
			RET
				ret = this->Do();
			return *(cell *)&ret;
		}

		virtual RET Do() const = 0;

		implementation_t const
			original_;
	};

	// Template specialisation for void returns, since they can't use "return X()".
	template <>
	class NativeHook0<void> : protected NativeHookBase
	{
	public:
		typedef void (*implementation_t)();

		class ScopedCall
		{
		public:
			inline void operator()()
			{
				original_();
			}

			~ScopedCall()
			{
				if (removed_)
					hook_.Install();
			}

		private:
			ScopedCall(subhook::Hook & hook, implementation_t original)
				:
				hook_(hook),
				original_(original),
				removed_(hook.Remove())
			{
			}

			ScopedCall(ScopedCall const &) = default;
			ScopedCall & operator=(ScopedCall const &) = default;

			ScopedCall(ScopedCall && that)
				:
				hook_(std::move(that.hook_)),
				original_(std::move(that.original_)),
				removed_(std::move(that.removed_))
			{
				that.removed_ = false;
			}

			ScopedCall & operator=(ScopedCall const &&) = delete;

			ScopedCall() = delete;

			friend class NativeHook0<void>;

			subhook::Hook &
				hook_;

			implementation_t const
				original_;

			bool
				removed_;
		};

		inline void operator()()
		{
			if (Recursing())
			{
				subhook::ScopedHookRemove
					undo(&GetHook());
				original_();
			}
			else
			{
				Do();
			}
			Recursing();
		}

		ScopedCall operator*()
		{
			ScopedCall
				ret(GetHook(), original_);
			return ret;
		}

	protected:
		NativeHook0(char const * const name, implementation_t original, AMX_NATIVE replacement) : NativeHookBase(0, name, replacement), original_(original) {}
		~NativeHook0() = default;

	private:
		cell CallDoInner(AMX *, cell *)
		{
			this->Do();
			return 1;
		}

		virtual void Do() const = 0;

		implementation_t const
			original_;
	};

	template <typename RET>
	class NativeHook<RET()> : public NativeHook0<RET> { NativeHook(char const * const name, implementation_t original, AMX_NATIVE replacement) : NativeHook0(name, original, replacement) {} };
};

#if defined PLUGIN_NATIVES_STORAGE
namespace plugin_natives
{
	std::list<NativeHookBase *> *
		NativeHookBase::all_;

	void Load(void **ppData)
	{
	}
};
#endif

// Defer declaring the other classes to a super macro file.
#define NATIVE_HOOK_TEMPLATE   typename A
#define NATIVE_HOOK_NAME       NativeHook1
#define NATIVE_HOOK_TYPES      A
#define NATIVE_HOOK_PARAMETERS A a
#define NATIVE_HOOK_CALLING    a
#define NATIVE_HOOK_NUMBER     1
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B
#define NATIVE_HOOK_NAME       NativeHook2
#define NATIVE_HOOK_TYPES      A, B
#define NATIVE_HOOK_PARAMETERS A a, B b
#define NATIVE_HOOK_CALLING    a, b
#define NATIVE_HOOK_NUMBER     2
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C
#define NATIVE_HOOK_NAME       NativeHook3
#define NATIVE_HOOK_TYPES      A, B, C
#define NATIVE_HOOK_PARAMETERS A a, B b, C c
#define NATIVE_HOOK_CALLING    a, b, c
#define NATIVE_HOOK_NUMBER     3
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D
#define NATIVE_HOOK_NAME       NativeHook4
#define NATIVE_HOOK_TYPES      A, B, C, D
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d
#define NATIVE_HOOK_CALLING    a, b, c, d
#define NATIVE_HOOK_NUMBER     4
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E
#define NATIVE_HOOK_NAME       NativeHook5
#define NATIVE_HOOK_TYPES      A, B, C, D, E
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e
#define NATIVE_HOOK_CALLING    a, b, c, d, e
#define NATIVE_HOOK_NUMBER     5
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F
#define NATIVE_HOOK_NAME       NativeHook6
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f
#define NATIVE_HOOK_NUMBER     6
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G
#define NATIVE_HOOK_NAME       NativeHook7
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g
#define NATIVE_HOOK_NUMBER     7
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H
#define NATIVE_HOOK_NAME       NativeHook8
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h
#define NATIVE_HOOK_NUMBER     8
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I
#define NATIVE_HOOK_NAME       NativeHook9
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i
#define NATIVE_HOOK_NUMBER     9
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J
#define NATIVE_HOOK_NAME       NativeHook10
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j
#define NATIVE_HOOK_NUMBER     10
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K
#define NATIVE_HOOK_NAME       NativeHook11
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k
#define NATIVE_HOOK_NUMBER     11
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L
#define NATIVE_HOOK_NAME       NativeHook12
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K, L
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k, l
#define NATIVE_HOOK_NUMBER     12
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L, typename M
#define NATIVE_HOOK_NAME       NativeHook13
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K, L, M
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l, M m
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k, l, m
#define NATIVE_HOOK_NUMBER     13
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L, typename M, typename N
#define NATIVE_HOOK_NAME       NativeHook14
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K, L, M, N
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l, M m, N n
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k, l, m, n
#define NATIVE_HOOK_NUMBER     14
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L, typename M, typename N, typename O
#define NATIVE_HOOK_NAME       NativeHook15
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K, L, M, N, O
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l, M m, N n, O o
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
#define NATIVE_HOOK_NUMBER     15
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L, typename M, typename N, typename O, typename P
#define NATIVE_HOOK_NAME       NativeHook16
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l, M m, N n, O o, P p
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p
#define NATIVE_HOOK_NUMBER     16
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_NUMBER
#undef NATIVE_HOOK_CALLING
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TEMPLATE

// The hooks and calls for each class are always static, because otherwise it
// would make installing hooks MUCH harder - we would need stubs that could
// handle class pointers.  Doing that would negate needing a different class for
// every hook type, even when the parameters are the same, but this way is
// probably not much more generated code, and vastly simpler.
// 
// The inheritance from `NativeHookBase` is protected, because we don't want
// normal users getting in to that data.  However, we do want them to be able to
// use the common `IsEnabled` method, so re-export it.
#define HOOK_DECL(func,type) \
	extern "C" SAMP_NATIVES_RETURN(type) _cdecl                                 \
	    NATIVE_##func SAMP_NATIVES_WITHOUT_RETURN_##type ;                      \
	                                                                            \
	namespace plugin_natives                                                    \
	{                                                                           \
	    extern class Native_##func : public NativeHook<type>                    \
	    {                                                                       \
	    public:                                                                 \
	        Native_##func() :                                                   \
	            NativeHook<type>(#func, &sampgdk_##func, &Call) {}              \
	                                                                            \
	        using NativeHookBase::IsEnabled;                                    \
	                                                                            \
	    private:                                                                \
	        friend SAMP_NATIVES_RETURN(type) _cdecl                             \
	            ::NATIVE_##func SAMP_NATIVES_WITHOUT_RETURN_##type ;            \
	                                                                            \
	        static cell AMX_NATIVE_CALL                                         \
	            Call(AMX * amx, cell * params)                                  \
	        {                                                                   \
	            return ::plugin_natives::func.CallDoOuter(amx, params);         \
	        }                                                                   \
	                                                                            \
	        SAMP_NATIVES_RETURN(type)                                           \
	            Do SAMP_NATIVES_WITHOUT_RETURN_##type const;                    \
	    } func;                                                                 \
	}

#if 0

// Example:

// In you header:
#undef SetPlayerPos
HOOK_DECL(SetPlayerPos, bool(int playerid, float x, float y, float z));

// In your code:
HOOK_DEFN(SetPlayerPos, bool(int playerid, float x, float y, float z))
{
	// Implementation here...
	gLastX[playerid] = x;
	gLastY[playerid] = y;
	// No need to worry about hooks for this function - they are removed while
	// the hook is running.
	return SetPlayerPos(playerid, x, y, z);
}

#endif

// We can't pass exceptions to another module easily, so just don't...
// 
// I quite like this:
//   
//   SAMP_NATIVES_MAYBE_RETURN(type) {};
//   
// If there is a return type, it will compile as:
//   
//   return {};
//   
// Which means "return default value" in new C++ versions.  If there is no
// return type (void), it will compile as:
//   
//   {};
//   
// Which means nothing.
#define HOOK_DEFN(func,type) \
	extern "C" SAMP_NATIVES_RETURN(type) _cdecl                                 \
	    NATIVE_##func(SAMP_NATIVES_PARAMETERS(type))                            \
	{                                                                           \
	    __pragma(comment(linker, "/EXPORT:_" #func "=_NATIVE_" #func));         \
	    try                                                                     \
	    {                                                                       \
	        SAMP_NATIVES_MAYBE_RETURN(type)                                     \
	            ::plugin_natives::func(SAMP_NATIVES_CALLING(type));             \
	    }                                                                       \
	    catch (std::exception & e)                                              \
	    {                                                                       \
	        char                                                                \
	            msg[1024];                                                      \
	        sprintf(msg, "Exception in _" #func ": \"%s\"", e.what());          \
	        Log(LogLevel::ERROR, msg);                                          \
	    }                                                                       \
	    catch (...)                                                             \
	    {                                                                       \
	        Log(LogLevel::ERROR, "Unknown exception in _" #func);               \
	    }                                                                       \
	    if (!::plugin_natives::func.Recursing())                                \
	        ::plugin_natives::func.Recursing();                                 \
	    SAMP_NATIVES_MAYBE_RETURN(type) {};                                     \
	}                                                                           \
	                                                                            \
	plugin_natives::Native_##func plugin_natives::func;                         \
	SAMP_NATIVES_RETURN(type)                                                   \
	    plugin_natives::Native_##func::                                         \
	    Do SAMP_NATIVES_WITHOUT_RETURN_##type const

#define HOOK_DECLARE HOOK_DECL
#define HOOK_DEFINE  HOOK_DEFN

