#pragma once

struct fix_description_s
{
public:
	// Can't have these as `std::string` and use `constexpr` in the same class.
	char const * const Problem;
	char const * const Solution;
	char const * const See;
	char const * const Author;
	char const * const Topic;
	char const * const FixedIn;

	constexpr fix_description_s() : fix_description_s(0, 0, 0, 0, 0, 0) {}
	constexpr fix_description_s(
		char const * const problem,
		char const * const solution,
		char const * const see,
		char const * const author,
		char const * const topic,
		char const * const fixedIn)
	:
		Problem(problem), Solution(solution), See(see), Author(author), Topic(topic), FixedIn(fixedIn) {}
	constexpr fix_description_s problem(char const * const problem) { return { problem, Solution, See, Author, Topic, FixedIn }; }
	constexpr fix_description_s solution(char const * const solution) { return { Problem, solution, See, Author, Topic, FixedIn }; }
	constexpr fix_description_s see(char const * const see) { return { Problem, Solution, see, Author, Topic, FixedIn }; }
	constexpr fix_description_s author(char const * const author) { return { Problem, Solution, See, author, Topic, FixedIn }; }
	constexpr fix_description_s topic(char const * const topic) { return { Problem, Solution, See, Author, topic, FixedIn }; }
	constexpr fix_description_s fixed_in(char const * const fixedIn) { return { Problem, Solution, See, Author, Topic, fixedIn }; }
};

template <int T>
class DeclaredFix
{
public:
	explicit DeclaredFix(struct fix_description_s const && description) : description_m(description) {}

	inline operator bool() const
	{
		return (T != 0);
	}

private:
	struct fix_description_s const
		description_m;
};

// This code can detect pre-processor defined symbols that may not exist, may
// not have a value given, or may be 0 or 1.
#define FIXES_IF__FIXES_DEFINED_ FIXES_NIL_,1
#define FIXES_IF_0_FIXES_DEFINED_ FIXES_NIL_,0
#define FIXES_IF_1_FIXES_DEFINED_ FIXES_NIL_,1

#define FIXES_CHECK_DEFINED_(a) FIXES_CHECK_DEFINED_2_(a)
#define FIXES_CHECK_DEFINED_2_(a) FIXES_CHECK_DEFINED_3_((FIXES_IF_##a##_FIXES_DEFINED_,2))

#define FIXES_CHECK_DEFINED_3_(a) FIXES_CHECK_DEFINED_4_ a
#define FIXES_CHECK_DEFINED_4_(ignore,result,...) result

#define FIXES_REMOVE_BRACKETS_(...) __VA_ARGS__

#define FIX(name) ((bool)FIX_##name##_)

#ifndef DEFINE_FIX
	// If this symbol already exists, it is probably doing something special.
	// Otherwise, just use this to define the fix as `extern` by default, so
	// that all files can check if the various fixes exist.
	#define DEFINE_FIX(name,comments) extern DeclaredFix<FIXES_CHECK_DEFINED_(name)> const FIX_##name##_;
#endif

#include "../README.hpp"

#undef DEFINE_FIX

