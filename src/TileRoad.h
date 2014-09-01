/*
 * TileRoad.h
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#pragma once

#include "Tile.h"

class TileRoad: public Tile {
	public:
		TileRoad(int d, int x, int y);
		virtual void render(sf::RenderTarget& target, sf::RenderStates& states);
		TileType getType() {
			return TileType::Road;
		}

		int move;

		static sf::Texture texture;

	private:
		sf::RectangleShape rect;
};

