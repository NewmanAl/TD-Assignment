/*#pragma once

#include <vector>
#include "Map.h"
#include "Player.h"

using namespace std;

// class definition
class Creep{

public:
	Creep();
	Creep(int hp, int speed, int defense, int reward, int strength, int locationX, int locationY);
	virtual ~Creep();

	// Enum
	enum Direction { UP, DOWN, LEFT, RIGHT };

	// getters
	int getHitPoints() const;
	int getSpeed() const;
	int getDefense() const;
	int getReward() const;
	int getStrength() const;
	int getLocationX() const;
	int getLocationY() const;
	Direction getDirection() const;

	// setters
	void setHitPoints(int hp);
	void setSpeed(int speed);
	void setDefense(int defense);
	void setReward(int reward);
	void setStrength(int strength);
	void setLocationX(int locationX);
	void setLocationY(int locationY);
	void setDirection(Direction direction);

	// Custom methods
	void printCreep() const;
	void move(Map *map);
	void checkMove(Map *map);
	bool checkEndTile(Map *map, Player *player);

private:
	int hitPoints;
	int speed;
	int defense;
	int reward;
	int strength;
	int locationX;
	int locationY;
	Direction direction;
};*/
// test