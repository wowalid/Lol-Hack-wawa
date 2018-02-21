#pragma once
#include "Offsets.h"
class Orbwalker
{
public:
	Object * player;
	void Attack(Object* target, bool isMinion);
	void MoveToPosition(D3DVECTOR *position);
	void MoveToTarget(Object* target);
	void getNearestAttackableUnit();
	//typedef void(__thiscall* fnIssueOrder) (Object* thisPtr, DWORD dwOrder, D3DVECTOR* TargetPos, Object* TargetPtr, bool attackLoc, bool isPassive, DWORD isNetworked);
//	Move = 2,
//		Attack = 3,
//		Stop = 10,

};

