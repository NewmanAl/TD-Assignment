#pragma once

#include <vector>
#include <iostream>
#include "Creep.h"
#include "Map.h"

using namespace std;

class CreepSquad
{
public:
	CreepSquad(Map* map);
	void move(Player *player);
	void resetCreepSquad(int level);
	virtual ~CreepSquad();

private:
	vector<Creep*> creepSquad;
	Map* map;
};

