#pragma once

template <int T>
class DeclaredFix
{
public:
	DeclaredFix() : disabled_(false) {}
	
	inline bool operator !() const
	{
		// We use `operator !` instead of `operator ==` or `operator bool`
		// (cast) so that we can invert the check and use `if ... else ...` in
		// the macro to avoid a common macro pitfall.  It should compile to the
		// same thing in the end.
		switch (T)
		{
		case 0:
			return true;
		case 1:
			return false;
		default:
			return disabled_;
		}
	}
	
	void Enable()
	{
		disabled_ = false;
	}
	
	void Disable()
	{
		disabled_ = true;
	}
	
private:
	bool
		disabled_;
};

#if defined FORWARD_FIXES
	#define DEFINE_FIX(name,comments) \
		class DeclaredFix_##name : public DeclaredFix<FIXES_CHECK_DEFINED_(FIX_##name)>
#else
	#define DEFINE_FIX(name,comments) \
		class DeclaredFix_##name : public DeclaredFix<FIXES_CHECK_DEFINED_(FIX_##name)>
#endif

// I'm hoping this will frequently optimise to nothing.
//#define FIX(a) if (!FIXES_##name##_)(void)0;else (void)FIXES_##name##_

// This code can detect pre-processor defined symbols that may not exist, may
// not have a value given, or may be 0 or 1.
#define FIXES_IF__FIXES_DEFINED_ FIXES_NIL_,1
#define FIXES_IF_0_FIXES_DEFINED_ FIXES_NIL_,0
#define FIXES_IF_1_FIXES_DEFINED_ FIXES_NIL_,1

#define FIXES_CHECK_DEFINED_(a) FIXES_CHECK_DEFINED_2_(a)
#define FIXES_CHECK_DEFINED_2_(a) FIXES_CHECK_DEFINED_3_((FIXES_IF_##a##_FIXES_DEFINED_,2))

#define FIXES_CHECK_DEFINED_3_(a) FIXES_CHECK_DEFINED_4_ a
#define FIXES_CHECK_DEFINED_4_(ignore,result,...) result

//#define FIXES_REMOVE_BRACKETS_(...) __VA_ARGS__
//
#define FIX(name) FIX_##name##_
//
//#ifndef DEFINE_FIX
//	// If this symbol already exists, it is probably doing something special.
//	// Otherwise, just use this to define the fix as `extern` by default, so
//	// that all files can check if the various fixes exist.
//	#define DEFINE_FIX(name,comments) extern DeclaredFix<FIXES_CHECK_DEFINED_(name)> const FIX_##name##_;
//#endif

#include "../README.hpp"

#undef DEFINE_FIX

