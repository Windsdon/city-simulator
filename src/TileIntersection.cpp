/*
 * TileIntersection.cpp
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#include "TileIntersection.h"

sf::Texture TileIntersection::texture;

TileIntersection::TileIntersection(Intersection* i, int x, int y) :
		Tile(x, y), rect(sf::Vector2f(1.0, 1.0)), control(i) {
	rect.setTexture(&texture, true);
}

void TileIntersection::render(sf::RenderTarget& target,
		sf::RenderStates& states) {
	target.draw(rect, states);

}
