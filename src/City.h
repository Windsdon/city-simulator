/*
 * City.h
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#pragma once

#include <vector>
#include <set>
#include <SFML/Graphics.hpp>

#include "Vehicle.h"
#include "Tile.h"
#include "TileSpawner.h"

using namespace std;

class City {
	public:
		City(int sizeX, int sizeY);

		void render(sf::RenderTarget& target);

		/*
		 * Make the cars move!
		 */
		void doTick();

		void registerVehicle(Vehicle*);

		Tile* getTileAt(int x, int y);

		void updateTrigger(set<Tile*>& l, int x, int y);

	private:
		vector<vector<Tile*> > tiles;
		int sizeX, sizeY;
		vector<Vehicle*> vehicles;

		vector<TileSpawner*> spawners;

};
