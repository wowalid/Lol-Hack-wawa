#pragma once
#include "Offsets.h"
#include "ObjectManager.h"
#include <vector>
class Orbwalker
{
public:
	Object * player;
	Object** ObjMgr;
	void Attack(Object* target, bool isMinion);
	void MoveToPosition(D3DVECTOR *position);
	void MoveToTarget(Object* target);
	std::vector<Object*> getAttackableUnitInRange();
	float Distance(Object* A, Object* B);
	//typedef void(__thiscall* fnIssueOrder) (Object* thisPtr, DWORD dwOrder, D3DVECTOR* TargetPos, Object* TargetPtr, bool attackLoc, bool isPassive, DWORD isNetworked);
//	Move = 2,
//		Attack = 3,
//		Stop = 10,

};

