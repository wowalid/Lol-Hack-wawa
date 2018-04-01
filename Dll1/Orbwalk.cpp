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
	D3DVECTOR* pos = new D3DVECTOR(X, Y, Z);
	MousePointer* mouse = new MousePointer();
	
	if (this->Distance(pos, mouse->mousePos)>=80) {
		offsets->tIssueOrder(this->player, 2, position, nullptr, 0, 0, 0);
	}



}
//return self:Time() - OMenu.Adv.AAD:Value() + GetLatency()*.5 - self.LastAttack >= (1000/(GetAttackSpeed(myHero)*self.BaseAttackSpeed))
//return self:Time() - OMenu.Adv.MD : Value() + GetLatency()*.5 - self.LastAttack >= (1000 / (GetAttackSpeed(myHero)*self.BaseWindUp))
//self.BaseWindUp = 1 / (spellProc.windUpTime * GetAttackSpeed(myHero))
//self.BaseAttackSpeed = 1 / (spellProc.animationTime * GetAttackSpeed(myHero))
bool Orbwalker::CanMove() {

	float BaseWindUp = offsets->tGetAttackCastDelay(player, 1) ;
	if (player->mAttackSpeedMod > 2) {
		return offsets->getClock() - this->movetimer + 0.2 >= BaseWindUp;
	}
	else {
		return offsets->getClock() - this->movetimer +0.2 >= BaseWindUp/offsets->tGetAttackDelay(player,1);
	}
	cout << "AttackCastDelay : " << offsets->tGetAttackCastDelay(player, 1) << endl; 
}

bool Orbwalker::CanAttack() {
	float BaseAnimationTime = 1/ (player->mAttackSpeedMod / offsets->tGetAttackDelay(player, 1));
	 
	return offsets->getClock() - this->attacktimer + 0.3 >= BaseAnimationTime;
	
	
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

float Orbwalker::Distance(D3DVECTOR* A, D3DVECTOR* B) {
	float dist = 0;

	dist = sqrt((A->x - B->x)*(A->x - B->x) + (A->y - B->y)*(A->y - B->y) + (A->z - B->z)*(A->z - B->z));

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
			if (obj->Champion==5121 && this->CanAttack()) {
				cout << "champ :" << obj->Champion << endl;
				cout << "champ :" << obj->Name.getString() << endl;
				attacktimer = offsets->getClock();
				movetimer = offsets->getClock();
				Attack(obj, 1);
				break;
			}
		}
	}

	if (this->CanMove()){
		MoveToPosition(mouse->mousePos);
	
	}
}

void Orbwalker::LastHit() {
	MousePointer* mouse = new MousePointer();
	if (getAttackableUnitInRange().size() > 0) {
		for (Object* obj : getAttackableUnitInRange()) {
			if (obj->mHP < 100 && this->CanAttack()) {
				attacktimer = offsets->getClock();
				movetimer = offsets->getClock();
				Attack(obj, 1);
				break;
			}
		}
	}


	if (this->CanMove()) {
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