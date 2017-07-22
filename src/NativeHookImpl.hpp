template <typename RET, NATIVE_HOOK_TEMPLATE>
class NATIVE_HOOK_NAME : public NativeHookBase
{
public:
	typedef RET (*native_t)(NATIVE_HOOK_TYPES);

	class ScopedCall : private subhook::ScopedHookRemove
	{
	public:
		inline RET operator()(NATIVE_HOOK_PARAMETERS)
		{
			return native_(NATIVE_HOOK_CALLING);
		}

		ScopedCall(ScopedCall const &&) = default;
		ScopedCall const & operator(ScopedCall const &&) const = default;

		~ScopedCall() = default;
	private:
		ScopedCall(subhook::Hook & hook, native_t native) : ScopedHookRemove(&hook), native_(native) {}
		
		ScopedCall const & operator(ScopedCall const &) const = delete;
		ScopedCall(ScopedCall const &) = delete;
		ScopedCall() = delete;

		friend class NATIVE_HOOK_NAME<RET>;

		native_t const
			native_;
	};

	inline RET operator()(NATIVE_HOOK_PARAMETERS)
	{
		return native_(NATIVE_HOOK_CALLING);
	}

	NATIVE_HOOK_NAME<RET>::ScopedCall operator*()
	{
		NATIVE_HOOK_NAME<RET>::ScopedCall
			ret(GetHook(), GetNative());
		return ret;
	}

protected:
	NATIVE_HOOK_NAME(char const * const name, native_t native) : NativeHookBase(name), native_(native) {}

private:
	native_t const
		native_;
};

template <NATIVE_HOOK_TEMPLATE>
class NATIVE_HOOK_NAME<void, NATIVE_HOOK_TYPES> : public NativeHookBase
{
public:
	typedef void (*native_t)(NATIVE_HOOK_TYPES);

	class ScopedCall : private subhook::ScopedHookRemove
	{
	public:
		inline void operator()(NATIVE_HOOK_PARAMETERS)
		{
			native_(NATIVE_HOOK_CALLING);
		}

		ScopedCall(ScopedCall const &&) = default;
		ScopedCall const & operator(ScopedCall const &&) const = default;

		~ScopedCall() = default;
	private:
		ScopedCall(subhook::Hook & hook, native_t native) : ScopedHookRemove(&hook), native_(native) {}
		
		ScopedCall const & operator(ScopedCall const &) const = delete;
		ScopedCall(ScopedCall const &) = delete;
		ScopedCall() = delete;

		friend class NATIVE_HOOK_NAME<void>;

		native_t const
			native_;
	};

	inline void operator()(NATIVE_HOOK_PARAMETERS)
	{
		native_(NATIVE_HOOK_CALLING);
	}

	NATIVE_HOOK_NAME<void>::ScopedCall operator*()
	{
		NATIVE_HOOK_NAME<void>::ScopedCall
			ret(GetHook(), GetNative());
		return ret;
	}

protected:
	NATIVE_HOOK_NAME(char const * const name, native_t native) : NativeHookBase(name), native_(native) {}

private:
	native_t const
		native_;
};

template <typename RET, NATIVE_HOOK_TEMPLATE>
class NativeHook<RET(NATIVE_HOOK_TYPES)> : public NATIVE_HOOK_NAME<RET, NATIVE_HOOK_TYPES> { protected: NativeHook(char const * const name, NATIVE_HOOK_NAME<RET, NATIVE_HOOK_TYPES>::native_t native) : NATIVE_HOOK_NAME(name, native) {} };

