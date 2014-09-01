/*
 * Vehicle.h
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#pragma once

#include <queue>
#include <SFML/Graphics.hpp>

using namespace std;

/*
 * Represents the next place the vehicle should move to
 */
struct Move {
		int x;
		int y;
		bool relative;

		Move(int x, int y, bool relative): x(x), y(y), relative(relative){
		}
};

class Vehicle {
	public:
		Vehicle(queue<Move>, int x, int y);

		void render(sf::RenderTarget& target, sf::RenderStates& states);
		/*
		 * get the coordinates for the next move (absolute)
		 */
		bool nextMove(int &x, int &y);
		/*
		 * pop from the list
		 */
		void nextMove();

		int x, y;
		int px, py;
		bool moved;

	private:
		queue<Move> moveList;
		sf::RectangleShape rect;
};

