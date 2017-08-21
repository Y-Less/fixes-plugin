#pragma once

namespace fixes
{
	class DeclaredFixBase
	{
	public:
		// TODO: Register this fix as existing, so that we can have a dynamic
		// list of enablable and disablable fixes.  Needs the name.
//		DeclaredFixBase() {}
		
		virtual inline operator bool() const = 0;
		virtual inline bool operator !() const = 0;
		virtual void Enable() = 0;
		virtual void Disable() = 0;
		virtual void OnPlayerConnect(playerid) {};
	};
	
	template <int T>
	class DeclaredFix : public DeclaredFixBase
	{
	public:
		DeclaredFix() : enabled_(T != -1) {}
		
		inline operator bool() const
		{
			// I'm hoping this will frequently optimise to nothing.
			switch (T)
			{
			case 0:
				return false;
			case 1:
				return true;
			default:
				return enabled_;
			}
		}
		
		inline bool operator !() const
		{
			// I'm hoping this will frequently optimise to nothing.
			switch (T)
			{
			case 0:
				return true;
			case 1:
				return false;
			default:
				return !enabled_;
			}
		}
		
		void Enable()
		{
			enabled_ = true;
		}
		
		void Disable()
		{
			enabled_ = false;
		}
		
	private:
		bool
			enabled_;
	};
};

#define DECL_FIX(name) \
	fixes::FIXES_##name fixes::FIXES_##name##_

#define DEFN_FIX(name) \
	extern class FIXES_##name : public ::fixes::DeclaredFix<FIXES_CHECK_DEFINED_(FIX_##name)>



// This code can detect pre-processor defined symbols that may not exist, may
// not have a value given, or may be -1, 0 or 1:
//   
//   (undefined) or `2` - Default, enabled, but disablable.
//   -1 - Disabled, but can be enabled.
//   0 - Disabled, can't be enabled.
//   1 - Enabled, can't be disabled.
//   
#define FIXES_IF__FIXES_DEFINED_ FIXES_NIL_,1
#define FIXES_IF_0_FIXES_DEFINED_ FIXES_NIL_,0
#define FIXES_IF_1_FIXES_DEFINED_ FIXES_NIL_,1
#define FIXES_IF_ FIXES_NIL_,-1,

#define FIXES_CHECK_DEFINED_(a) FIXES_CHECK_DEFINED_2_(a)
#define FIXES_CHECK_DEFINED_2_(a) FIXES_CHECK_DEFINED_3_((FIXES_IF_##a##_FIXES_DEFINED_,2))

#define FIXES_CHECK_DEFINED_3_(a) FIXES_CHECK_DEFINED_4_ a
#define FIXES_CHECK_DEFINED_4_(ignore,result,...) result

#define FIX(name) FIXES_##name##_
#define FIXES(name) fixes::FIXES_##name
// Use check inversion to avoid the common macro pitfall of having single line
// if statements in macros in other single line if statements - the `else`s get
// mixed up unless you do it this way.
#define TRY_FIX(name) if (!FIXES_##name##_)(void)0;else FIXES_##name##_
#define RETURN_FIX(name) if (!FIXES_##name##_)(void)0;else return FIXES_##name##_

#include "../README.hpp"

#undef DEFINE_FIX

