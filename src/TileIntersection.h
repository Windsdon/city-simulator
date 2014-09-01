/*
 * TileIntersection.h
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#pragma once

#include "Tile.h"
#include "Intersection.h"

class Intersection;

class TileIntersection: public Tile {
	public:
		TileIntersection(Intersection*, int x, int y);
		virtual void render(sf::RenderTarget& target, sf::RenderStates& states);
		TileType getType() {
			return TileType::Intersection;
		}

		static sf::Texture texture;

	private:
		sf::RectangleShape rect;
		Intersection *control;
};

