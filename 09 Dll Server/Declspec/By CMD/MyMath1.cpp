#include<Windows.h>
#include"MyMath1.h"

BOOL WINAPI dllMain(HINSTANCE hDll, DWORD dwReasone, LPVOID lpReserrved)
{
	//code
	switch (dwReasone)
	{
	case DLL_PROCESS_ATTACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;

	default:
		break;
	}

	return TRUE;
}

__declspec(dllexport) int MakeSquare(int num)
{
	//code
	return num * num;
}
