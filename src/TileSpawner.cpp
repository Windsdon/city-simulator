/*
 * TileSpawner.cpp
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#include "TileSpawner.h"

sf::Texture TileSpawner::spawnerTexture;

TileSpawner::TileSpawner(int x, int y): Tile(x, y), rect(sf::Vector2f(1.0, 1.0)) {
	rect.setTexture(&spawnerTexture, true);
}

void TileSpawner::render(sf::RenderTarget& target, sf::RenderStates& states){
	target.draw(rect, states);
}

bool TileSpawner::spawnNext(Vehicle*& v){
	if(spawnList.empty()){
		return false;
	}

	if(spawnList.front() != nullptr){
		v = spawnList.front();
		spawnList.pop();
		return true;
	}

	return false;
}

void TileSpawner::addVehicle(Vehicle* v){
	v->x = x;
	v->y = y;

	spawnList.push(v);
}
