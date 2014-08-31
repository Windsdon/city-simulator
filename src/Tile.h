/*
 * TIle.h
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "Vehicle.h"

enum class TileType {
	Road, Intersection, Spawner, Destructor, Colour
};

class Tile {
	public:
		Tile(int x, int y);
		virtual TileType getType() = 0;
		virtual void render(sf::RenderTarget& target, sf::RenderStates& states) = 0;
		virtual ~Tile() {
		}

		int x, y;

		bool occupied;
		Vehicle* v;
};

