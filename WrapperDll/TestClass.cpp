#include "pch.h"
#include "TestClass.h"

typedef int(*LPFNDLLFUNC)(int a);

int test(LPCWSTR name, UINT_PTR offset, int a) {

	HINSTANCE hDLL;
	LPFNDLLFUNC myFunc;
	int hrReturnVal;
	hDLL = LoadLibraryEx(name, NULL, DONT_RESOLVE_DLL_REFERENCES | LOAD_LIBRARY_AS_DATAFILE);
	if (NULL != hDLL)
	{
		myFunc = (LPFNDLLFUNC)((UINT_PTR)hDLL + offset);
		if (NULL != myFunc)
		{
			hrReturnVal = myFunc(a);
		}
		else
		{
			// report the error
			hrReturnVal = ERROR_DELAY_LOAD_FAILED;
		}
		FreeLibrary(hDLL);
	}
	else
	{
		hrReturnVal = ERROR_DELAY_LOAD_FAILED;
	}
	return hrReturnVal;
}