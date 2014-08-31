/*
 * Vehicle.cpp
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#include "Vehicle.h"

Vehicle::Vehicle(queue<Move> moveList, int x, int y) :
		x(x), y(y), moveList(moveList), rect(sf::Vector2f(0.7, 0.7)) {
	rect.setFillColor(sf::Color(200, 200, 200));
	rect.move(0.15, 0.15);
}

bool Vehicle::nextMove(int& x, int& y) {

	if (moveList.empty()) {
		return false;
	}

	Move m = moveList.front();

	x = m.x + (m.relative ? this->x : 0);
	y = m.y + (m.relative ? this->y : 0);

	return true;
}

void Vehicle::nextMove() {
	moveList.pop();
}

void Vehicle::render(sf::RenderTarget& target, sf::RenderStates& states) {
	target.draw(rect, states);
}

