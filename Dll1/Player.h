#pragma once
#include "Offsets.h"
#include "D3DVECTOR.h"


class Player
{	
public : 
	DWORD Localp = *(DWORD*)((DWORD)GetModuleHandle(NULL)+ 0x02DB2160);
	float		positionX = *(float*)(Localp + 0x100);
		float	positionY = *(float*)(Localp + 0x104);
		float	positionZ = *(float*)(Localp + 0x108);
		/*	currentMana = *(float*)(Localp + 0x02CC);
			maxMana = *(float*)(Localp + 0x02DC);
			currentHealth = *(float*)(Localp + 0x0660);
			maxHealth = *(float*)(Localp + 0x0668);
			baseManaRegen = *(float*)(Localp + 0x08E0);
			manaRegen = *(float*)(Localp + 0x08F0);
			bonusAD = *(float*)(Localp + 0x09CC);
			ap1 = *(float*)(Localp + 0x09D4);
			ad1 = *(float*)(Localp + 0x0A48);
			ad2 = *(float*)(Localp + 0x100);
			armor = *(float*)(Localp + 0x0A70);
			bonusArmor = *(float*)(Localp + 0x0A74);//0x0A74
			magicResist = *(float*)(Localp + 0x0A78); //0x0A78
			bonusMagicResist = *(float*)(Localp + 0x0A7C); //0x0A7C
			baseHealthRegen = *(float*)(Localp + 0x0A80); //0x0A80
			healthRegen = *(float*)(Localp + 0x0A84); //0x0A84
			moveSpeed = *(float*)(Localp + 0x0A88); //0x0A88
			currentArmor = *(float*)(Localp + 0x0F98); //0x0F98
			bonusArmor2 = *(float*)(Localp + 0x0FA8); //0x0FA8
			currentMR = *(float*)(Localp + 0x0FB8);//0x0FB8
			currentGold = *(float*)(Localp + 0x1220); //0x1220
			goldSinceStart = *(float*)(Localp + 0x1230); //0x1230
			bonusMR = *(float*)(Localp + 0x17C8);//0x17C8 //0x17CC*/
	
}; //Size=0x1838

