// Consumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>
#include <iostream>


typedef int(* LPFNDLLFUNC)(int a);
typedef int(*LPFNDLLFUNC1)(LPCWSTR name, UINT_PTR offset, int a);

int main()
{
    std::cout << "Hello World!\n";
	HINSTANCE hDLL1, hDLL2;               // Handle to DLL
	LPFNDLLFUNC myFunc;
	LPFNDLLFUNC1 myFunc1;
	HRESULT hrReturnVal;
	auto a = L"RealDLL";
	auto b = L"WrapperDll";
	hDLL1 = LoadLibrary(a);
	UINT_PTR offset;
	if (NULL != hDLL1)
	{
		myFunc = (LPFNDLLFUNC)GetProcAddress(hDLL1, "test");
		if (NULL != myFunc)
		{
			offset = (UINT_PTR)myFunc - (UINT_PTR)hDLL1;
			hDLL2 = LoadLibrary(b);
			if (NULL != hDLL2) {
				myFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL2, "test");
				if (NULL != myFunc1) {
					hrReturnVal = myFunc1(a, offset, 7);
					std::cout << (hrReturnVal == myFunc(7)) << std::endl;
				}
				else
				{
					// report the error
					hrReturnVal = ERROR_DELAY_LOAD_FAILED;
				}
				FreeLibrary(hDLL2);
			}
			else
			{
				// report the error
				hrReturnVal = ERROR_DELAY_LOAD_FAILED;
			}
		}
		else
		{
			// report the error
			hrReturnVal = ERROR_DELAY_LOAD_FAILED;
		}
		FreeLibrary(hDLL1);
	}
	else
	{
		hrReturnVal = ERROR_DELAY_LOAD_FAILED;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
