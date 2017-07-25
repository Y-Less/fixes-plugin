template <typename RET, NATIVE_HOOK_TEMPLATE>
class NATIVE_HOOK_NAME : protected NativeHookBase
{
public:
	typedef RET (*native_t)(NATIVE_HOOK_TYPES);
	typedef RET (NATIVE_HOOK_NAME<void, NATIVE_HOOK_TYPES>::*replacement_t)(NATIVE_HOOK_TYPES);

	class ScopedCall
	{
	public:
		inline RET operator()(NATIVE_HOOK_PARAMETERS)
		{
			return native_(NATIVE_HOOK_CALLING);
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

		friend class NATIVE_HOOK_NAME<RET, NATIVE_HOOK_TYPES>;

		subhook::Hook &
			hook_;

		native_t const
			native_;

		bool
			removed_;
	};

	inline RET operator()(NATIVE_HOOK_PARAMETERS)
	{
		return native_(NATIVE_HOOK_CALLING);
	}

	ScopedCall operator*() const
	{
		ScopedCall
			ret(GetHook(), native_);
		return ret;
	}

protected:
	NATIVE_HOOK_NAME(char const * const name, native_t native, hooked_t hooked) : NativeHookBase(name, hooked), native_(native) {}
	~NATIVE_HOOK_NAME() = default;

private:
	cell CallDoInner(AMX * amx, cell * params)
	{
		#if NATIVE_HOOK_NUMBER >= 1
			ParamCast<A> a(amx, params, 1);
		#endif
		#if NATIVE_HOOK_NUMBER >= 2
			ParamCast<B> b(amx, params, 2);
		#endif
		#if NATIVE_HOOK_NUMBER >= 3
			ParamCast<C> c(amx, params, 3);
		#endif
		#if NATIVE_HOOK_NUMBER >= 4
			ParamCast<D> d(amx, params, 4);
		#endif
		#if NATIVE_HOOK_NUMBER >= 5
			ParamCast<E> e(amx, params, 5);
		#endif
		#if NATIVE_HOOK_NUMBER >= 6
			ParamCast<F> f(amx, params, 6);
		#endif
		#if NATIVE_HOOK_NUMBER >= 7
			ParamCast<G> g(amx, params, 7);
		#endif
		#if NATIVE_HOOK_NUMBER >= 8
			ParamCast<H> h(amx, params, 8);
		#endif
		#if NATIVE_HOOK_NUMBER >= 9
			ParamCast<I> i(amx, params, 9);
		#endif
		#if NATIVE_HOOK_NUMBER >= 10
			ParamCast<J> j(amx, params, 0);
		#endif
		#if NATIVE_HOOK_NUMBER >= 11
			ParamCast<K> k(amx, params, 1);
		#endif
		#if NATIVE_HOOK_NUMBER >= 12
			ParamCast<L> l(amx, params, 2);
		#endif
		#if NATIVE_HOOK_NUMBER >= 13
			ParamCast<M> m(amx, params, 3);
		#endif
		#if NATIVE_HOOK_NUMBER >= 14
			ParamCast<N> n(amx, params, 4);
		#endif
		#if NATIVE_HOOK_NUMBER >= 15
			ParamCast<O> o(amx, params, 5);
		#endif
		#if NATIVE_HOOK_NUMBER >= 16
			ParamCast<P> p(amx, params, 6);
		#endif
			RET
				ret = this->Do(NATIVE_HOOK_CALLING);
			return *(cell *)&ret;
	}

	virtual RET Do(NATIVE_HOOK_PARAMETERS) const = 0;

	native_t const
		native_;
};

template <NATIVE_HOOK_TEMPLATE>
class NATIVE_HOOK_NAME<void, NATIVE_HOOK_TYPES> : protected NativeHookBase
{
public:
	typedef void (*native_t)(NATIVE_HOOK_TYPES);
	typedef void (NATIVE_HOOK_NAME<void, NATIVE_HOOK_TYPES>::*replacement_t)(NATIVE_HOOK_TYPES);

	class ScopedCall
	{
	public:
		inline void operator()(NATIVE_HOOK_PARAMETERS)
		{
			native_(NATIVE_HOOK_CALLING);
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

		friend class NATIVE_HOOK_NAME<void, NATIVE_HOOK_TYPES>;

		subhook::Hook &
			hook_;

		native_t const
			native_;

		bool
			removed_;
	};

	inline void operator()(NATIVE_HOOK_PARAMETERS)
	{
		native_(NATIVE_HOOK_CALLING);
	}

	ScopedCall operator*() const
	{
		ScopedCall
			ret(GetHook(), native_);
		return ret;
	}

protected:
	NATIVE_HOOK_NAME(char const * const name, native_t native, hooked_t hooked) : NativeHookBase(name, hooked), native_(native) {}
	~NATIVE_HOOK_NAME() = default;

private:
	cell CallDoInner(AMX * amx, cell * params)
	{
		#if NATIVE_HOOK_NUMBER >= 1
			ParamCast<A> a(amx, params, 1);
		#endif
		#if NATIVE_HOOK_NUMBER >= 2
			ParamCast<B> b(amx, params, 2);
		#endif
		#if NATIVE_HOOK_NUMBER >= 3
			ParamCast<C> c(amx, params, 3);
		#endif
		#if NATIVE_HOOK_NUMBER >= 4
			ParamCast<D> d(amx, params, 4);
		#endif
		#if NATIVE_HOOK_NUMBER >= 5
			ParamCast<E> e(amx, params, 5);
		#endif
		#if NATIVE_HOOK_NUMBER >= 6
			ParamCast<F> f(amx, params, 6);
		#endif
		#if NATIVE_HOOK_NUMBER >= 7
			ParamCast<G> g(amx, params, 7);
		#endif
		#if NATIVE_HOOK_NUMBER >= 8
			ParamCast<H> h(amx, params, 8);
		#endif
		#if NATIVE_HOOK_NUMBER >= 9
			ParamCast<I> i(amx, params, 9);
		#endif
		#if NATIVE_HOOK_NUMBER >= 10
			ParamCast<J> j(amx, params, 0);
		#endif
		#if NATIVE_HOOK_NUMBER >= 11
			ParamCast<K> k(amx, params, 1);
		#endif
		#if NATIVE_HOOK_NUMBER >= 12
			ParamCast<L> l(amx, params, 2);
		#endif
		#if NATIVE_HOOK_NUMBER >= 13
			ParamCast<M> m(amx, params, 3);
		#endif
		#if NATIVE_HOOK_NUMBER >= 14
			ParamCast<N> n(amx, params, 4);
		#endif
		#if NATIVE_HOOK_NUMBER >= 15
			ParamCast<O> o(amx, params, 5);
		#endif
		#if NATIVE_HOOK_NUMBER >= 16
			ParamCast<P> p(amx, params, 6);
		#endif
			this->Do(NATIVE_HOOK_CALLING);
			return 1;
	}

	virtual void Do(NATIVE_HOOK_PARAMETERS) const = 0;

	native_t const
		native_;
};

template <typename RET, NATIVE_HOOK_TEMPLATE>
class NativeHook<RET(NATIVE_HOOK_TYPES)> : public NATIVE_HOOK_NAME<RET, NATIVE_HOOK_TYPES> { protected: static unsigned int const PARAMS = NATIVE_HOOK_NUMBER; NativeHook(char const * const name, native_t native, hooked_t hooked) : NATIVE_HOOK_NAME(name, native, hooked) {} };

