/*
 * PathFinding.h
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#pragma once

#include <vector>
#include <limits>
#include "Tile.h"

using namespace std;

class PathFinding {
	private:
		struct Node {
				int score;
				Node* parent;
				Tile* tile;
				int x;
				int y;

				Node(Tile* tile, int x, int y) {
					this->tile = tile;
					score = 0;
					parent = nullptr;
					this->x = x;
					this->y = y;
				}
		};
	public:
		static vector<Tile*> path(Tile* start, Tile* end,
				vector<vector<Node*> >& map);

		static vector<vector<Node*> > createSearchMap(
				const vector<vector<Tile*> >& tiles);

		static const int infinity = numeric_limits<int>::max();

	private:
		PathFinding() {
		}
};

