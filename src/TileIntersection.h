/*
 * TileIntersection.h
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#pragma once

#include "Tile.h"

class TileIntersection: public Tile {
	public:
		TileIntersection(int x, int y);
		virtual void render(sf::RenderTarget& target, sf::RenderStates& states);
		TileType getType() {
			return TileType::Intersection;
		}
};

