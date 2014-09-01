/*
 * TileSpawner.h
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#pragma once

#include <queue>

#include "Tile.h"
#include "Vehicle.h"

class TileSpawner: public Tile {
	public:
		TileSpawner(int x, int y);
		virtual void render(sf::RenderTarget& target, sf::RenderStates& states);
		TileType getType() {
			return TileType::Spawner;
		}

		static sf::Texture texture;

		bool spawnNext(Vehicle*&);
		void addVehicle(Vehicle*);

	private:
		sf::RectangleShape rect;
		queue<Vehicle*> spawnList;
};

