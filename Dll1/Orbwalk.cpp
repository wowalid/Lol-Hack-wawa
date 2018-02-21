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
