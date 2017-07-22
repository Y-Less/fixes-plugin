#pragma once

class NativeHookBase
{
public:
	void Init()
	{
		// If a known native matches the stored name, install the hook.
		Install(native);
	}

protected:
	NativeHookBase(char const * const name) : name_(name) {}

	template <typename T>
	inline ScopedHookCall<T> MakeBaseCall(subhook::Hook hook)
	{
		return ScopedHookCall(hook);
	}

	virtual subhook::Hook & GetHook() const = 0;
	virtual void Install(void * src) = 0;

private:
	NativeHookBase() = delete;
	~NativeHookBase() = delete;
	NativeHookBase(NativeHookBase const &) = delete;
	NativeHookBase(NativeHookBase const &&) = delete;
	NativeHookBase const & operator(NativeHookBase const &) const = delete;
	NativeHookBase const & operator(NativeHookBase const &&) const = delete;

	char const * const
		name_;
};

template <typename FUNC_TYPE>
class NativeHook {};

// A pretty horrible combination of templates that make hooks quite seamless.
template <typename RET>
class NativeHook0 : public NativeHookBase
{
public:
	typedef RET (*native_t)();

	class ScopedCall : private subhook::ScopedHookRemove
	{
	public:
		inline RET operator()()
		{
			return native_();
		}

		ScopedCall(ScopedCall const &&) = default;
		ScopedCall const & operator(ScopedCall const &&) const = default;

		~ScopedCall() = default;
	private:
		ScopedCall(subhook::Hook & hook, native_t native) : ScopedHookRemove(&hook), native_(native) {}
		
		ScopedCall const & operator(ScopedCall const &) const = delete;
		ScopedCall(ScopedCall const &) = delete;
		ScopedCall() = delete;

		friend class NativeHook0<RET>;

		native_t const
			native_;
	};

	inline RET operator()()
	{
		return native_();
	}

	NativeHook0<RET>::ScopedCall operator*()
	{
		NativeHook0<RET>::ScopedCall
			ret(GetHook(), GetNative());
		return ret;
	}

protected:
	NativeHook0(char const * const name, native_t native) : NativeHookBase(name), native_(native) {}

private:
	native_t const
		native_;
};

// Template specialisation for void returns, since they can't use "return X()".
class NativeHook0<void> : public NativeHookBase
{
public:
	typedef void (*native_t)();

	class ScopedCall : private subhook::ScopedHookRemove
	{
	public:
		inline void operator()()
		{
			native_();
		}

		ScopedCall(ScopedCall const &&) = default;
		ScopedCall const & operator(ScopedCall const &&) const = default;

		~ScopedCall() = default;
	private:
		ScopedCall(subhook::Hook & hook, native_t native) : ScopedHookRemove(&hook), native_(native) {}
		
		ScopedCall const & operator(ScopedCall const &) const = delete;
		ScopedCall(ScopedCall const &) = delete;
		ScopedCall() = delete;

		friend class NativeHook0<void>;

		native_t const
			native_;
	};

	inline void operator()()
	{
		native_();
	}

	NativeHook0<void>::ScopedCall operator*()
	{
		NativeHook0<void>::ScopedCall
			ret(GetHook(), GetNative());
		return ret;
	}

protected:
	NativeHook0(char const * const name, native_t native) : NativeHookBase(name), native_(native) {}

private:
	native_t const
		native_;
};

template <typename RET>
class NativeHook<RET()> : public NativeHook0<RET> { protected: NativeHook(char const * const name, NativeHook0<RET>::native_t native) : NativeHook0(name, native) {} };

// Defer declaring the other classes to a super macro file.
#define NATIVE_HOOK_TEMPLATE   typename A
#define NATIVE_HOOK_NAME       NativeHook1
#define NATIVE_HOOK_TYPES      A
#define NATIVE_HOOK_PARAMETERS A a
#define NATIVE_HOOK_CALLING    a
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B
#define NATIVE_HOOK_NAME       NativeHook2
#define NATIVE_HOOK_TYPES      A, B
#define NATIVE_HOOK_PARAMETERS A a, B b
#define NATIVE_HOOK_CALLING    a, b
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C
#define NATIVE_HOOK_NAME       NativeHook3
#define NATIVE_HOOK_TYPES      A, B, C
#define NATIVE_HOOK_PARAMETERS A a, B b, C c
#define NATIVE_HOOK_CALLING    a, b, c
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D
#define NATIVE_HOOK_NAME       NativeHook4
#define NATIVE_HOOK_TYPES      A, B, C, D
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d
#define NATIVE_HOOK_CALLING    a, b, c, d
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E
#define NATIVE_HOOK_NAME       NativeHook5
#define NATIVE_HOOK_TYPES      A, B, C, D, E
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e
#define NATIVE_HOOK_CALLING    a, b, c, d, e
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F
#define NATIVE_HOOK_NAME       NativeHook6
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G
#define NATIVE_HOOK_NAME       NativeHook7
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H
#define NATIVE_HOOK_NAME       NativeHook8
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I
#define NATIVE_HOOK_NAME       NativeHook9
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J
#define NATIVE_HOOK_NAME       NativeHook10
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K
#define NATIVE_HOOK_NAME       NativeHook11
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L
#define NATIVE_HOOK_NAME       NativeHook12
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K, L
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k, l
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L, typename M
#define NATIVE_HOOK_NAME       NativeHook13
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K, L, M
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l, M m
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k, l, m
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L, typename M, typename N
#define NATIVE_HOOK_NAME       NativeHook14
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K, L, M, N
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l, M m, N n
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k, l, m, n
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L, typename M, typename N, typename O
#define NATIVE_HOOK_NAME       NativeHook15
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K, L, M, N, O
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l, M m, N n, O o
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

#define NATIVE_HOOK_TEMPLATE   typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L, typename M, typename N, typename O, typename P
#define NATIVE_HOOK_NAME       NativeHook16
#define NATIVE_HOOK_TYPES      A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P
#define NATIVE_HOOK_PARAMETERS A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l, M m, N n, O o, P p
#define NATIVE_HOOK_CALLING    a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p
#include "NativeHookImpl.hpp"
#undef NATIVE_HOOK_TEMPLATE
#undef NATIVE_HOOK_NAME
#undef NATIVE_HOOK_TYPES
#undef NATIVE_HOOK_PARAMETERS
#undef NATIVE_HOOK_CALLING

// The hooks and calls for each class are always static, because otherwise it
// would make installing hooks MUCH harder - we would need stubs that could
// handle class pointers.  Doing that would negate needing a different class
// for every hook type, even when the parameters are the same, but this was is
// probably not much more generated code, and vastly simpler.
#define HOOK_NATIVE(func,type) \
	class hooked_##func##_ : public NativeHook<type>                           \
	{                                                                          \
	public:                                                                    \
		hooked_##func##_() : NativeHook<type>(#func, &sampgdk_##func) {}       \
                                                                               \
	protected:                                                                 \
		virtual subhook::Hook & GetHook() const { return hook_; }              \
		virtual void Install(void * src) { hook_.Install(src, (void *)&Do); }  \
                                                                               \
	private:                                                                   \
		static cell Do(AMX * amx, cell * params);                              \
                                                                               \
		static subhook::Hook                                                   \
			hook_;                                                             \
	};                                                                         \
	hooked_##func;                                                             \
	subhook::Hook hooked_##func_::hook_

#if 0

// Example:
#undef  SetPlayerPos
HOOK_NATIVE(SetPlayerPos, bool(int, float, float, float));
#define SetPlayerPos hooked_SetPlayerPos

#endif

