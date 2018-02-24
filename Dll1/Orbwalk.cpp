#include "stdafx.h"
#include "Orbwalk.h"

void Orbwalker::Attack(Object * target, bool isMinion)
{
	Offsets *offsets = new Offsets();
	//offsets->tIssueOrder(this->player, 3, target->position, target, 1, isMinion, target->networkId);
}

void Orbwalker::MoveToPosition(D3DVECTOR* position)
{
	Offsets *offsets = new Offsets();
	DWORD Localp = *(DWORD*)((DWORD)GetModuleHandle(NULL) + 0x02DB2160);
	float		positionX = *(float*)(Localp + 0x100);
	float	positionY = *(float*)(Localp + 0x104);
	float	positionZ = *(float*)(Localp + 0x108);
	offsets->tIssueOrder(this->player, 2, position, nullptr, 0, 0, 0);

}

void Orbwalker::MoveToTarget(Object * target)
{
	Offsets *offsets = new Offsets();
	//offsets->tIssueOrder(this->player, 2, target->position, target, 1, 0, target->networkId);
}

void Orbwalker::getNearestAttackableUnit()
{

}
