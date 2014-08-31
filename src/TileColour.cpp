/*
 * TileColor.cpp
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#include "TileColour.h"

TileColour::TileColour(sf::Color colour, int x, int y): Tile(x, y), colour(colour) {

}

void TileColour::render(sf::RenderTarget& target, sf::RenderStates& states){
	sf::RectangleShape rect(sf::Vector2f(1.0, 1.0));
	rect.setFillColor(colour);
	target.draw(rect, states);
}

