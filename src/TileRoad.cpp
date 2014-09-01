/*
 * TileRoad.cpp
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#include "TileRoad.h"

#include<iostream>
using namespace std;

sf::Texture TileRoad::texture;

TileRoad::TileRoad(int d, int x, int y) :
		Tile(x, y), move(d), rect(sf::Vector2f(1.0, 1.0)) {
	rect.setTexture(&texture, true);
	rect.setOrigin(sf::Vector2f(0.5, 0.5));
	rect.rotate(90 * move);
	rect.move(0.5, 0.5);
}

void TileRoad::render(sf::RenderTarget& target, sf::RenderStates& states) {
	target.draw(rect, states);
}
