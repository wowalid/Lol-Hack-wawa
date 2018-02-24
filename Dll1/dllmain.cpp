// dllmain.cpp : Définit le point d'entrée pour l'application DLL.

#include "stdafx.h"
#include "Offsets.h"
#include "Player.h"
#include "ObjectManager.h"
#include <iostream>
#include "Object.h"
#include "Orbwalk.h"
#include "MousePointer.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

DWORD WINAPI runBot(LPVOID lpParam) {
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

	Orbwalker* orb = new Orbwalker();
	Offsets* offsets = new Offsets();
	orb->player = *(Object**)(offsets->oLocalPlayer);
	Object** ObjManager = *(Object***)(offsets->ObjManager);
	ObjectManager* objMgr = (ObjectManager*)(offsets->ObjManager);
	
	int size = objMgr->size;
	cout << size << endl;
	while (!GetAsyncKeyState(VK_F6))
	{
		if (GetAsyncKeyState(VK_SPACE)<0)
		{
			/*for (int i = 0; i < 20; i++) {
				Object* obj = ObjManager[i];
				if (obj) 
				{  
					if (obj->Name) {
						cout << obj->Name << endl;
					}

					
				}
			}*/
			MousePointer* mouse = new MousePointer();
			DWORD Localp = *(DWORD*)((DWORD)GetModuleHandle(NULL) + 0x02DB2160);
			float		positionX = *(float*)(Localp + 0x100);
			float	positionY = *(float*)(Localp + 0x104);
			float	positionZ = *(float*)(Localp + 0x108);

			cout << positionX - mouse->mousePos->x << endl;
			cout << positionY - mouse->mousePos->y << endl;
			cout << positionZ - mouse->mousePos->z << endl;
			orb->MoveToPosition(mouse->mousePos);

		}
		Sleep(1);
	}


	return 1;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		MessageBoxA(NULL, "Injection reussie!\n", "Wawa hack", MB_OK | MB_TOPMOST);
		CreateThread(NULL, 0, &runBot, NULL, 0, NULL);
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

