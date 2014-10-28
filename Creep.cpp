#include "Creep.h"
#include "Map.h"
#include <iostream>

using namespace std;

// Constructors
Creep::Creep()
{
	hitPoints = 50;
	speed = 1;
	defense = 1;
	reward = 10;
	strength = 10;
	locationX = 0;
	locationY = 0;
	direction = Direction::RIGHT;
}

Creep::Creep(int hp, int speed, int defense, int reward, int strength, int locationX, int locationY, Direction direction)
{
	this->hitPoints = hp;
	this->speed = speed;
	this->defense = defense;
	this->reward = reward;
	this->strength = strength;
	this->locationX = locationX;
	this->locationY = locationY;
	this->direction = direction;
}


// Getters
int Creep::getHitPoints() const
{
	return hitPoints;
}

int Creep::getSpeed() const
{
	return speed;
}

int Creep::getDefense() const
{
	return defense;
}

int Creep::getReward() const
{
	return reward;
}

int Creep::getStrength() const
{
	return strength;
}

int Creep::getLocationX() const
{
	return locationX;
}

int Creep::getLocationY() const
{
	return locationY;
}

Direction Creep::getDirection() const
{
	return direction;
}

// Setters
void Creep::setHitPoints(int hp)
{
	this->hitPoints = hp;
}

void Creep::setSpeed(int speed)
{
	this->speed = speed;
}

void Creep::setDefense(int defense)
{
	this->defense = defense;
}

void Creep::setReward(int reward)
{
	this->reward = reward;
}

void Creep::setStrength(int strength)
{
	this->strength = strength;
}

void Creep::setLocationX(int locationX)
{
	this->locationX = locationX;
}
void Creep::setLocationY(int locationY)
{
	this->locationY = locationY;
}

void Creep::setDirection(Direction direction)
{
	this->direction = direction;
}

// Custom methods

// Prints out the current values of a creep's attributes
void Creep::printCreep() const
{
	std::cout << "hitpoints: " << hitPoints << std::endl;
	std::cout << "speed: " << speed << std::endl;
	std::cout << "defense: " << defense << std::endl;
	std::cout << "reward: " << reward << std::endl;
	std::cout << "strength: " << strength << std::endl;
	std::cout << "locationX " << locationX << std::endl;
	std::cout << "locationY " << locationY << std::endl;
	std::cout << endl;
}

// Moves a creep on the map according to the direction they are going in
void Creep::move(Map *map)
{
	// initialize variables to the creep's current location
	int mapLocationX = this->locationX;
	int mapLocationY = this->locationY;

	// creep's location back to path tile
	//map->setTile(mapLocationX, mapLocationY, TILE_TYPE);

	// change x,y coordinates of an alien according to movement direction
	if (direction == Direction::LEFT)
	{
		this->locationX = mapLocationX - 1;
	}
	else if (direction == Direction::RIGHT)
	{
		this->locationX = mapLocationX + 1;
	}
	else if (direction == Direction::UP)
	{
		this->locationY = mapLocationY + 1;
	}
	else
	{
		this->locationY = mapLocationY - 1;
	}

	// set new map location to enemy position
	//map->setTile(this->locationX, this->locationY, MapTile::CREEP);
}

// Check if a creep is able to move in a specific direction
void Creep::checkMove(Map *map)
{
	Direction creepDirection = this->direction;
	int locationX = this->locationX;
	int locationY = this->locationY;

	// if a creep's project direction is an ENVIRONMENT tile,
	// check the other directions if it is able to move (there is a path there) and set the direction to that creep
	// else, move along the current direction
	if (creepDirection == Direction::LEFT)
	{
		if (map->getTile(locationX - 1, locationY) == MapTile::ENVIRONMENT) {
			if (map->getTile(locationX, locationY - 1) == MapTile::PATH) {
				direction = Direction::DOWN;
				Creep::move(map);
			}

			if (map->getTile(locationX, locationY + 1) == MapTile::PATH) {
				direction = Direction::UP;
				Creep::move(map);
			}
		}
		else {
			Creep::move(map);
		}
	}
	else if (creepDirection == Direction::RIGHT)
	{
		if (map->getTile(locationX + 1, locationY) == MapTile::ENVIRONMENT)
		{

			if (map->getTile(locationX, locationY - 1) == MapTile::PATH) {
				direction = Direction::DOWN;
				Creep::move(map);
			}

			if (map->getTile(locationX, locationY + 1) == MapTile::PATH) {
				direction = Direction::UP;
				Creep::move(map);
			}
		}
		else {
			Creep::move(map);
		}
	}
	else if (creepDirection == Direction::UP)
	{
		if (map->getTile(locationX, locationY + 1) == MapTile::ENVIRONMENT)
		{
			if (map->getTile(locationX - 1, locationY) == MapTile::PATH) {
				direction = Direction::LEFT;
				Creep::move(map);
			}

			if (map->getTile(locationX + 1, locationY) == MapTile::PATH) {
				direction = Direction::RIGHT;
				Creep::move(map);
			}
		}
		else {
			Creep::move(map);
		}
	}
	else
	{
		if (map->getTile(locationX, locationY - 1) == MapTile::ENVIRONMENT)
		{
			if (map->getTile(locationX - 1, locationY) == MapTile::PATH) {
				direction = Direction::LEFT;
				Creep::move(map);
			}

			if (map->getTile(locationX + 1, locationY) == MapTile::PATH) {
				direction = Direction::RIGHT;
				Creep::move(map);
			}
		}
		else {
			Creep::move(map);
		}
	}
}

// Checks if a creep has entered an end tile
bool Creep::checkEndTile(Map* map, Player* player)
{
	Direction direction = this->direction;
	int locationX = this->locationX;
	int locationY = this->locationY;

	bool creepAtEndTile = false;

	// if the direction the creep is going in has an end tile, set boolean to true
	if (direction == Direction::LEFT)
	{
		if (map->getTile(locationX - 1, locationY) == MapTile::END_TILE) {
			creepAtEndTile = true;
		}
	}
	else if (direction == Direction::RIGHT)
	{
		if (map->getTile(locationX + 1, locationY) == MapTile::END_TILE) {
			creepAtEndTile = true;
		}
	}
	else if (direction == Direction::UP)
	{
		if (map->getTile(locationX, locationY + 1) == MapTile::END_TILE) {
			creepAtEndTile = true;
		}
	}
	else
	{
		if (map->getTile(locationX, locationY - 1) == MapTile::END_TILE) {
			creepAtEndTile = true;
		}
	}

	// if the creep is at an end tile
	if (creepAtEndTile) {
		// remove coins from player according to value of creep's strength
		player->setCoins(player->getCoins() - strength);

		// set tile creep was on back to path
		//map->setTile(locationX, locationY, MapTile::PATH);
	}

	// return if a creep has landed on the end tile
	return creepAtEndTile;
}

void Creep::damageCreep(Player *player, int damage)
{
	hitPoints = hitPoints - damage;

	if (hitPoints <= 0) {
		player->setCoins(player->getCoins() + reward);
	}
}

// Destructor
Creep::~Creep()
{

}
