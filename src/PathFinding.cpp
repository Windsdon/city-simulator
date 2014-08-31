/*
 * PathFinding.cpp
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#include "PathFinding.h"
#include <queue>

vector<Tile*> PathFinding::path(Tile* startTile, Tile* endTile,
		vector<vector<Node*> >& map) {
	vector<Tile*> path;

	if (startTile == endTile || startTile->getType() == TileType::Colour
			|| startTile->getType() == TileType::Destructor) {
		return path;
	}

	unsigned int sizeY = map.size();
	unsigned int sizeX = map[0].size();

	Node* nodeStart;
	Node* nodeEnd;

	for (unsigned int i = 0; i < sizeY; i++) {
		for (unsigned int j = 0; j < sizeX; j++) {
			Node* node = map[i][j];

			if(node->tile == startTile){
				nodeStart = node;
				node->score = 0;
				continue;
			}

			if(node->tile == endTile){
				nodeEnd = node;
			}

			node->score = infinity;
		}
	}

	return path;
}

vector<vector<PathFinding::Node*> > PathFinding::createSearchMap(
		const vector<vector<Tile*> >& tiles) {
	unsigned int sizeY = tiles.size();
	unsigned int sizeX = tiles[0].size();

	vector<vector<Node*> > map(sizeY, vector<Node*>(sizeX, 0));

	for (unsigned int i = 0; i < sizeY; i++) {
		for (unsigned int j = 0; j < sizeX; j++) {
			map[i][j] = new Node(tiles[i][j], j, i);
		}
	}

	return map;
}

