#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <stdio.h>
#include "context.h"
#include "processor.h"

#include "regex.h"


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

__declspec(dllexport) void WINAPI Copy(int argc, char* argv[])
{
	execution_context cont = SetupContext(argc, argv);
	if (!cont)
	{
		return;
	}

	if (!PerformOperation(cont))
	{
		CleanUp(cont);
		return;
	}
	CleanUp(cont);
}
