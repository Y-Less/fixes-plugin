template <typename RET, NATIVE_HOOK_TEMPLATE>
class NATIVE_HOOK_NAME : public NativeHookBase
{
public:
	typedef RET (*native_t)(NATIVE_HOOK_TYPES);

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
			ret(hook_, native_);
		return ret;
	}

protected:
	NATIVE_HOOK_NAME(char const * const name, native_t native, hooked_t hooked, subhook::Hook & hook) : NativeHookBase(name, hooked), native_(native), hook_(hook) {}
	~NATIVE_HOOK_NAME() = default;

private:
	subhook::Hook &
		hook_;

	native_t const
		native_;
};

template <NATIVE_HOOK_TEMPLATE>
class NATIVE_HOOK_NAME<void, NATIVE_HOOK_TYPES> : public NativeHookBase
{
public:
	typedef void (*native_t)(NATIVE_HOOK_TYPES);

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
			ret(hook_, native_);
		return ret;
	}

protected:
	NATIVE_HOOK_NAME(char const * const name, native_t native, hooked_t hooked, subhook::Hook & hook) : NativeHookBase(name, hooked), native_(native), hook_(hook) {}
	~NATIVE_HOOK_NAME() = default;

private:
	subhook::Hook &
		hook_;

	native_t const
		native_;
};

template <typename RET, NATIVE_HOOK_TEMPLATE>
class NativeHook<RET(NATIVE_HOOK_TYPES)> : public NATIVE_HOOK_NAME<RET, NATIVE_HOOK_TYPES> { protected: NativeHook(char const * const name, native_t native, hooked_t hooked, subhook::Hook & hook) : NATIVE_HOOK_NAME(name, native, hooked, hook) {} };

