/*
 * TileColor.h
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#pragma once

#include "Tile.h"

class TileColour: public Tile {
	public:
		TileColour(sf::Color colour, int x, int y);
		virtual void render(sf::RenderTarget& target, sf::RenderStates& states);
		TileType getType() {
			return TileType::Colour;
		}

	private:
		sf::Color colour;
};
