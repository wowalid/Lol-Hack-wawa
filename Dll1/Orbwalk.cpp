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
		offsets->tIssueOrder(this->player, 3, vec, target, 1, isMinion, true);
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
				if (Distance(this->player, obj) < 600 && obj->mHP>0) {

					
					if (obj->Name.getString()) {
						char* nom = obj->Name.getString();

						if ((obj->Type->Type == 5 || obj->Type->Type == 3) && (obj->Team == 300||obj->Team==200)) {
							objets.push_back(obj);
							cout << "Name : " << nom << endl;
							cout << "Team : " << obj->Team << endl;
 							cout << "X : " << obj->X << endl;
							cout << "Y : " << obj->Y << endl;
							cout << "Z : " << player->Z << endl;
						}

					}


				}
			}


		}
	}
	cout << "Team : " << player->Team << endl;
	cout << "Taille : " << objets.size() << endl;
	return objets;
}
