#pragma once

#include <stdexcept>

#include <subhook/subhook.h>
#include <sampgdk/a_samp.h>
#include <sampgdk/a_players.h>
#include <sampgdk/a_vehicles.h>
#include <sampgdk/a_objects.h>
#include <sampgdk/a_actor.h>
#include <sampgdk/a_http.h>

#include "ParamCast.hpp"

#define HOOK_TYPE_WITHOUT_PARAMS_int(...)   int
#define HOOK_TYPE_WITHOUT_PARAMS_float(...) float
#define HOOK_TYPE_WITHOUT_PARAMS_bool(...)  bool
#define HOOK_TYPE_WITHOUT_PARAMS_void(...)  void
#define HOOK_TYPE_WITHOUT_PARAMS_cell(...)  cell

#define HOOK_TYPE_WITHOUT_RETURN_int(...)   (__VA_ARGS__)
#define HOOK_TYPE_WITHOUT_RETURN_float(...) (__VA_ARGS__)
#define HOOK_TYPE_WITHOUT_RETURN_bool(...)  (__VA_ARGS__)
#define HOOK_TYPE_WITHOUT_RETURN_void(...)  (__VA_ARGS__)
#define HOOK_TYPE_WITHOUT_RETURN_cell(...)  (__VA_ARGS__)

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
		hook_.IsInstalled();
	}

protected:
	typedef cell (*hooked_t)(AMX *, cell *);

	NativeHookBase(char const * const name, hooked_t hooked) : name_(name), hooked_(hooked), hook_(), amx_(0), params_(0) {}
	~NativeHookBase() = default;

	subhook::Hook & GetHook() { return hook_; }

	AMX * GetAMX() const { return amx_; }
	cell * GetParams() const { return params_; }
	
	cell CallDoOuter(unsigned int count, AMX * amx, cell * params)
	{
		cell
			ret = 0;
		if (amx && params)
		{
			// Check that there are enough parameters.
			if (count * sizeof (cell) > (unsigned int)params[0])
				throw std::invalid_argument("Insufficient arguments.");
			subhook::ScopedHookRemove
				undo(&hook_);
			amx_ = amx;
			params_ = params;
			ret = this->CallDoInner(amx, params);
			params_ = 0;
			amx_ = 0;
		}
		return (cell)ret;
	}

private:
	virtual cell CallDoInner(AMX *, cell *) = 0;

	NativeHookBase() = delete;
	NativeHookBase(NativeHookBase const &) = delete;
	NativeHookBase(NativeHookBase const &&) = delete;
	NativeHookBase const & operator=(NativeHookBase const &) const = delete;
	NativeHookBase const & operator=(NativeHookBase const &&) const = delete;

	char const * const
		name_;

	hooked_t const
		hooked_;

	subhook::Hook
		hook_;

	AMX *
		amx_;

	cell *
		params_;
};

template <typename FUNC_TYPE>
class NativeHook {};

// A pretty horrible combination of templates that make hooks quite seamless.
template <typename RET>
class NativeHook0 : protected NativeHookBase
{
public:
	typedef RET (*native_t)();
	const unsigned int PARAMS = 0;

	class ScopedCall
	{
	public:
		inline RET operator()()
		{
			return native_();
		}

		~ScopedCall()
		{
			if (removed_)
				hook_.Install();
		}

	private:
		ScopedCall(subhook::Hook & hook, native_t native)
			:
			hook_(hook),
			native_(native),
			removed_(hook.Remove())
		{
		}

		ScopedCall(ScopedCall const &) = default;
		ScopedCall & operator=(ScopedCall const &) = default;

		ScopedCall(ScopedCall && that)
			:
			hook_(std::move(that.hook_)),
			native_(std::move(that.native_)),
			removed_(std::move(that.removed_))
		{
			that.removed_ = false;
		}

		ScopedCall & operator=(ScopedCall const &&) = delete;

		ScopedCall() = delete;

		friend class NativeHook0<RET>;

		subhook::Hook &
			hook_;

		native_t const
			native_;

		bool
			removed_;
	};

	inline RET operator()()
	{
		return native_();
	}

	ScopedCall operator*()
	{
		ScopedCall
			ret(GetHook(), native_);
		return ret;
	}

protected:
	NativeHook0(char const * const name, native_t native, hooked_t hooked) : NativeHookBase(name, hooked), native_(native) {}
	~NativeHook0() = default;

private:
	cell CallDoInner(AMX *, cell *)
	{
		RET
			ret = this->Do();
		return *(cell *)&ret;
	}

	virtual RET Do() const = 0;

	native_t const
		native_;
};

// Template specialisation for void returns, since they can't use "return X()".
template <>
class NativeHook0<void> : protected NativeHookBase
{
public:
	typedef void (*native_t)();

	class ScopedCall
	{
	public:
		inline void operator()()
		{
			native_();
		}

		~ScopedCall()
		{
			if (removed_)
				hook_.Install();
		}

	private:
		ScopedCall(subhook::Hook & hook, native_t native)
			:
			hook_(hook),
			native_(native),
			removed_(hook.Remove())
		{
		}

		ScopedCall(ScopedCall const &) = default;
		ScopedCall & operator=(ScopedCall const &) = default;

		ScopedCall(ScopedCall && that)
			:
			hook_(std::move(that.hook_)),
			native_(std::move(that.native_)),
			removed_(std::move(that.removed_))
		{
			that.removed_ = false;
		}

		ScopedCall & operator=(ScopedCall const &&) = delete;

		ScopedCall() = delete;

		friend class NativeHook0<void>;

		subhook::Hook &
			hook_;

		native_t const
			native_;

		bool
			removed_;
	};

	inline void operator()()
	{
		native_();
	}

	ScopedCall operator*()
	{
		ScopedCall
			ret(GetHook(), native_);
		return ret;
	}

protected:
	NativeHook0(char const * const name, native_t native, hooked_t hooked) : NativeHookBase(name, hooked), native_(native) {}
	~NativeHook0() = default;

private:
	cell CallDoInner(AMX *, cell *)
	{
		this->Do();
		return 1;
	}

	virtual void Do() const = 0;

	native_t const
		native_;
};

template <typename RET>
class NativeHook<RET()> : public NativeHook0<RET> { protected: static unsigned int const PARAMS = 0; NativeHook(char const * const name, native_t native, hooked_t hooked) : NativeHook0(name, native, hooked) {} };

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
// handle class pointers.  Doing that would negate needing a different class
// for every hook type, even when the parameters are the same, but this was is
// probably not much more generated code, and vastly simpler.
// 
// The inheritance from `NativeHookBase` is protected, because we don't want
// normal users getting in to that data.  However, we do want them to be able to
// use the common `IsEnabled` method, so re-export it.
#define HOOK(func,type) \
	extern class CHook_##func : public NativeHook<type>                         \
	{                                                                           \
	public:                                                                     \
		CHook_##func() :                                                        \
			NativeHook<type>(#func, &sampgdk_##func, &PreDo) {}                 \
                                                                                \
		using NativeHookBase::IsEnabled();                                      \
                                                                                \
	private:                                                                    \
		static cell PreDo(AMX * amx, cell * params)                             \
		{                                                                       \
			try                                                                 \
			{                                                                   \
				return FIXES_##func.CallDoOuter(NativeHook<type>::PARAMS, amx, params); \
			}                                                                   \
			catch (std::exception & e)                                          \
			{                                                                   \
				Log(LogLevel::ERROR, "Exception thrown in " #func ":");         \
				Log(LogLevel::ERROR, e.what());                                 \
			}                                                                   \
			return 0;                                                           \
		}                                                                       \
                                                                                \
		HOOK_TYPE_WITHOUT_PARAMS_##type Do HOOK_TYPE_WITHOUT_RETURN_##type const; \
	} FIXES_##func;                                                             \

#if 0

// Example:

// In the NATIVES.hpp header:
#undef  SetPlayerPos
HOOK(SetPlayerPos, bool(int playerid, float x, float y, float z));
#define SetPlayerPos FIXES_SetPlayerPos
#define BAD_SetPlayerPos *FIXES_SetPlayerPos

// In your code:
HOOK(SetPlayerPos, bool(int playerid, float x, float y, float z))
{
	// Implementation here...
}

#endif

#include "../NATIVES.hpp"

#undef HOOK

#define HOOK(func,type) \
	CHook_##func FIXES_##func;                                                  \
	HOOK_TYPE_WITHOUT_PARAMS_##type CHook_##func::Do HOOK_TYPE_WITHOUT_RETURN_##type const

