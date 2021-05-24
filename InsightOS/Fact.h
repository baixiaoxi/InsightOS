#pragma once

#if _WIN32 || _WIN64
#define XP_WIN
#ifdef _WIN64
#define X64
#endif
#endif

#if __GNUC__
#if __x86_64__ || __ppc64__
#define X64
#endif
#endif

class Fact {
public:
	virtual bool test() = 0;
};
