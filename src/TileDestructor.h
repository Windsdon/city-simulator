/*
 * TileDestructor.h
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#pragma once

#include "Tile.h"

class TileDestructor: public Tile {
	public:
		TileDestructor(int x, int y);
		virtual void render(sf::RenderTarget& target, sf::RenderStates& states);
		TileType getType() {
			return TileType::Destructor;
		}

		static sf::Texture texture;

	private:
		sf::RectangleShape rect;
};

