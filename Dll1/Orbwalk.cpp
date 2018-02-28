#include "stdafx.h"
#include "Orbwalk.h"
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
void Orbwalker::Attack(Object * target, bool isMinion)
{
	Offsets *offsets = new Offsets();
	D3DVECTOR* vec = new D3DVECTOR(target->X, target->Y, target->Z);
	if (target!=nullptr) {
		
		//offsets->tIssueOrder(this->player, 10, nullptr, nullptr, 0, 0, 0);
		offsets->tIssueOrder(this->player, 3, vec, target, 1, isMinion, 0);
	}
	
}

void Orbwalker::MoveToPosition(D3DVECTOR* position)
{
	Offsets *offsets = new Offsets();
	float X = this->player->X;
	float Y = this->player->Y;
	float Z = this->player->Z;

	if (position->y < 150 && position->x >500 && position->z > 500) {
		offsets->tIssueOrder(this->player, 2, position, nullptr, 0, 0, 0);
	}



}

void Orbwalker::MoveToTarget(Object * target)
{
	Offsets *offsets = new Offsets();
	//offsets->tIssueOrder(this->player, 2, target->position, target, 1, 0, target->networkId);
}

float Orbwalker::Distance(Object* A, Object* B) {
	float dist = 0;

	dist = sqrt((A->X - B->X)*(A->X - B->X) + (A->Y - B->Y)*(A->Y - B->Y) + (A->Z - B->Z)*(A->Z - B->Z));

	return dist;
}

std::vector<Object*> Orbwalker::getAttackableUnitInRange()
{
	Offsets *offsets = new Offsets();
	std::vector<Object*> objets;
	float dist = 100000;
	for (int i = 0; i < 10000; i++) {
		Object* obj = ObjMgr[i];
		if (ObjMgr[i] == NULL) {
			continue;
		}
		if (obj)
		{
			if (obj->mHP) {
				if (Distance(this->player, obj) < player->AttackRange && obj->mHP>0) {

					
					if (obj->Name.getString()) {
						char* nom = obj->Name.getString();

						if ((obj->Type->Type == 5 || obj->Type->Type == 3) && (obj->Team == 300||obj->Team==200)) {
							objets.push_back(obj);
							//cout << "Name : " << nom << endl;
							float Delay = offsets->tGetAttackDelay(obj, i);
							/*cout << "Attackdelay : " << Delay << endl;
							cout << "Team : " << obj->Team << endl;
							cout << "Index : " << obj->Index << endl;
 							cout << "X : " << obj->X << endl;
							cout << "Y : " << obj->Y << endl;
							cout << "Z : " << player->Z << endl;*/
						}

					}


				}
			}


		}
	}
	return objets;
}

static double ClickerDelay = 0.1;

void Orbwalker::ResetMoveTimer()
{
	movetimer = offsets->getClock();
}
void Orbwalker::ResetAttackTimer()
{
	attacktimer = offsets->getClock();
}
double Orbwalker::CalcMoveDelay()
{
	cout << (offsets->getClock() - movetimer) << endl;
	return (offsets->getClock() - movetimer);
}
double Orbwalker::CalcAttackDelay()
{ 
	cout << (offsets->getClock() - attacktimer) << endl;
	return (offsets->getClock() - attacktimer);
}
double Orbwalker::CalcAttackTime()
{
	return offsets->tGetAttackDelay(player, 1);
}
double Orbwalker::CalcWindup()
{
	cout << (offsets->tGetAttackCastDelay(player, 1)) / (offsets->tGetAttackDelay(player, 1)) << endl;
	return (offsets->tGetAttackCastDelay(player, 1))/(offsets->tGetAttackDelay(player,1));

}
bool Orbwalker::MoveReady()
{
	if (CalcMoveDelay() > ClickerDelay)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Orbwalker::AttackReady()
{
	if (CalcAttackDelay() > CalcAttackTime())
	{
		return true;
	}
	else {
		return false;
	}
}


void Orbwalker::LaneClear() {
	MousePointer* mouse = new MousePointer();
	
	if (getAttackableUnitInRange().size() > 0) {
		for (Object* obj : getAttackableUnitInRange()) {
			if (obj->Champion==5121 && offsets->getClock()+0.8>= attacktimer + offsets->tGetAttackDelay(player,1)) {
				cout << "champ :" << obj->Champion << endl;
				cout << "champ :" << obj->Name.getString() << endl;
				attacktimer = offsets->getClock();
				movetimer = offsets->getClock();
				Attack(obj, 1);
				break;
			}
		}
	}

	if (offsets->getClock() + 0.7 >= movetimer + offsets->tGetAttackCastDelay(player, 1)){
		MoveToPosition(mouse->mousePos);
	}
}

void Orbwalker::LastHit() {
	MousePointer* mouse = new MousePointer();
	if (getAttackableUnitInRange().size() > 0) {
		for (Object* obj : getAttackableUnitInRange()) {
			if (obj->mHP < 100 && offsets->getClock() >= attacktimer + offsets->tGetAttackDelay(player, 1)) {
				attacktimer = offsets->getClock();
				movetimer = offsets->getClock();
				Attack(obj, 1);
				break;
			}
		}
	}


	if (offsets->getClock() + 0.5 >= movetimer + offsets->tGetAttackCastDelay(player, 1)) {
		MoveToPosition(mouse->mousePos);
	}
}

void Orbwalker::Orbwalk(Object* Target, bool hasTarget)
{
	MousePointer* mouse = new MousePointer();
	if (!hasTarget) {
			MoveToPosition(mouse->mousePos);
			

	}
	else {
		if (AttackReady() && getAttackableUnitInRange().size() > 0)
		{
			if (MoveReady())
			{
				Attack(Target, 1);
				ResetAttackTimer();
			}
		}
		if (!AttackReady() && getAttackableUnitInRange().size() > 0)
		{
			if (CalcAttackDelay() > CalcWindup())
			{
				MoveToPosition(mouse->mousePos);
				ResetMoveTimer();
			}
		}
		if (MoveReady() && getAttackableUnitInRange().size() < 1)
		{
			MoveToPosition(mouse->mousePos);
			ResetMoveTimer();
		}
	}

}