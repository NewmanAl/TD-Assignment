#pragma once

#include <vector>
#include "Map.h"
#include "Player.h"

using namespace std;

// Enum
enum Direction { UP, DOWN, LEFT, RIGHT };

// Enum representing each type of map tiles
enum MapTile { ENVIRONMENT = 0, PATH = 1, CREEP = 4, END_TILE = 5 };

// class definition
class Creep {

public:
	Creep();
	Creep(int hp, int speed, int defense, int reward, int strength, int locationX, int locationY, Direction dir);
	virtual ~Creep();

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
	void damageCreep(Player *player, int damage);

private:
	int hitPoints;
	int speed;
	int defense;
	int reward;
	int strength;
	int locationX;
	int locationY;
	Direction direction;
};