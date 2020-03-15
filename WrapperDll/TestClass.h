// MathLibrary.h - Contains declarations of math functions
#pragma once

#ifdef TESTCLASS_EXPORTS
#define TESTCLASS_API __declspec(dllexport)
#else
#define TESTCLASS_API __declspec(dllimport)
#endif

extern  "C" TESTCLASS_API int test(LPCWSTR name, UINT_PTR offset, int a);