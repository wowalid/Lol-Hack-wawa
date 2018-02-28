#pragma once
#include "Offsets.h"
#include "ObjectManager.h"
#include <vector>
#include "MousePointer.h"
class Orbwalker
{
public:
	Object * player;
	Offsets* offsets = new Offsets();
	Object** ObjMgr;
	void Attack(Object* target, bool isMinion);
	void MoveToPosition(D3DVECTOR *position);
	void MoveToTarget(Object* target);
	std::vector<Object*> getAttackableUnitInRange();
	float Distance(Object* A, Object* B);
	double ClickerDelay = 0.1;
	float movetimer = 0;
	float attacktimer = 0;
	void ResetMoveTimer();
	void ResetAttackTimer();

	double CalcMoveDelay();

	double CalcAttackDelay();

	double CalcAttackTime();

	double CalcWindup();

	bool MoveReady();

	bool AttackReady();

	void Orbwalk(Object* Target, bool hasTarget);

	void LastHit();
	void LaneClear();

	bool CanMove();
		//typedef void(__thiscall* fnIssueOrder) (Object* thisPtr, DWORD dwOrder, D3DVECTOR* TargetPos, Object* TargetPtr, bool attackLoc, bool isPassive, DWORD isNetworked);
//	Move = 2,
//		Attack = 3,
//		Stop = 10,

};

