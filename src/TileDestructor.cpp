/*
 * TileDestructor.cpp
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#include "TileDestructor.h"

sf::Texture TileDestructor::texture;

TileDestructor::TileDestructor(int x, int y) :
		Tile(x, y), rect(sf::Vector2f(1.0, 1.0)) {
	rect.setTexture(&texture, true);
}

void TileDestructor::render(sf::RenderTarget& target,
		sf::RenderStates& states) {
	target.draw(rect, states);

}

