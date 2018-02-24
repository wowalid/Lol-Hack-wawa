#pragma once
#include "D3DVECTOR.h"
#include "Offsets.h"
class MousePointer
{
public:
	Offsets* off = new Offsets();
	DWORD mouse = *(DWORD*)((DWORD)GetModuleHandle(NULL) + 0x1502754);
	float x = *(float*)(mouse + 0x90);
	float y = *(float*)(mouse + 0x98);
	float z = *(float*)(mouse + 0xA0);
	D3DVECTOR* mousePos = new D3DVECTOR(x,z,y);

};//Size=0x0438

