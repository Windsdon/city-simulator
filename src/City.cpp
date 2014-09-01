/*
 * City.cpp
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#include "City.h"

#include "TileColour.h"
#include "TileRoad.h"
#include "TileSpawner.h"
#include "TileIntersection.h"
#include "TileDestructor.h"

#include <set>
#include <iostream>

City::City(int sizeX, int sizeY) :
		tiles(sizeY, vector<Tile*>(sizeY, nullptr)), sizeX(sizeX), sizeY(sizeY) {

	//////////
	queue<Move> moves;
	for (int i = 0; i < 19; i++) {
		moves.push(Move(1, 0, true));
	}
	for (int i = 0; i < 19; i++) {
		moves.push(Move(0, 1, true));
	}
	//////////

	Intersection *intersection = new Intersection();

	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			if (!i && !j) {
				TileSpawner *spawner = new TileSpawner(j, i);
				tiles[i][j] = spawner;
				spawners.push_back((TileSpawner*) tiles[i][j]);
				for (int i = 0; i < 10; i++) {
					Vehicle *v = new Vehicle(moves, 0, 0);
					v->px = -1;
					spawner->addVehicle(v);
				}
				continue;
			}
			if (!i && j == (sizeX - 1)) {
				tiles[i][j] = new TileIntersection(intersection, j, i);
				continue;
			}
			if (i == (sizeY - 1) && j == (sizeX - 1)) {
				tiles[i][j] = new TileDestructor(j, i);
				continue;
			}
			if (!i) {
				tiles[i][j] = new TileRoad(0, j, i);
				continue;
			}
			if (j == (sizeX - 1)) {
				tiles[i][j] = new TileRoad(1, j, i);
				continue;
			}
			tiles[i][j] = new TileColour(sf::Color(60, 60, 60), j, i);
		}
	}

}

void City::registerVehicle(Vehicle* v) {
	if (v->x >= 0 && v->x < sizeX && v->y >= 0 && v->y < sizeY) {
		if (!tiles[v->y][v->x]->occupied) {
			vehicles.push_back(v);
			tiles[v->y][v->x]->occupied = true;
			tiles[v->y][v->x]->v = v;
		} else {
			cerr << "Vehicle registered in occupied tile" << endl;
		}
	} else {
		cerr << "Vehicle registered in invalid position" << endl;
	}
}

void City::render(sf::RenderTarget& target, float completion) {

	//Calculate scaling
	int windowSizeX = target.getSize().x;
	int windowSizeY = target.getSize().y;

	double scaleX = windowSizeX / ((double) sizeX);
	double scaleY = windowSizeY / ((double) sizeY);
	double scale = min(scaleX, scaleY);

	int xStart = (windowSizeX - scale * sizeX) / 2;
	int yStart = (windowSizeY - scale * sizeY) / 2;

	//draw tiles
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			sf::RenderStates states;
			states.transform.translate(xStart, yStart).scale(scale, scale).translate(
					j, i);
			tiles[i][j]->render(target, states);
		}
	}

	//draw cars
	int carsCount = vehicles.size();
	for (int i = 0; i < carsCount; i++) {
		Vehicle *car = vehicles[i];

		sf::RenderStates states;
		states.transform.translate(xStart, yStart).scale(scale, scale).translate(
				completion * (car->x) + (1 - completion) * car->px,
				completion * car->y + (1 - completion) * car->py);

		car->render(target, states);
	}
}

Tile* City::getTileAt(int x, int y) {
	return tiles[y][x];
}

void City::updateTrigger(set<Tile*>& l, int x, int y) {
	//BUG: Handle intersections
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (!i && !j) {
				continue;
			}
			int px = x + i;
			int py = y + j;

			if (px < 0 || px >= sizeX || py < 0 || py >= sizeY) {
				continue;
			}

			cout << "added tile " << px << " " << py << endl;

			l.insert(getTileAt(px, py));
		}
	}
}

void City::doTick() {
	int carsCount = vehicles.size();

	set<Vehicle*> update;

	for (int i = 0; i < carsCount; i++) {
		Vehicle *car = vehicles[i];
		car->moved = false;
		update.insert(car);
	}

	cout << "Update list filled" << endl;

	while (!update.empty()) {
		Vehicle *car = *(update.begin());
		int toX, toY;

		cout << "Trying to move " << car << " at " << car->x << " " << car->y
				<< endl;

		car->px = car->x;
		car->py = car->y;

		if (car->nextMove(toX, toY)) {
			Tile* dest = getTileAt(toX, toY);

			if (!dest->occupied) {
				cout << "Moving..." << endl;

				dest->v = car;
				getTileAt(car->x, car->y)->occupied = false;

				set<Tile*> updateList;
				cout << "Generating update list" << endl;
				updateTrigger(updateList, car->x, car->y);
				cout << "List generated" << endl;
				for (set<Tile*>::iterator it = updateList.begin();
						it != updateList.end(); ++it) {
					cout << "Searching vehicle at " << *it << endl;
					if ((*it)->occupied) {
						cout << "Found. Checking move status of " << (*it)->v
								<< endl;
						if ((*it)->v->moved) {
							continue;
						}
						update.insert((*it)->v);
						cout << "Added " << (*it)->v << endl;
					}
				}

				car->x = toX;
				car->y = toY;
				car->nextMove();
				car->moved = true;

				dest->occupied = true;
			}
		}

		update.erase(car);
	}

	cout << "Processing spawners" << endl;

	for (unsigned int i = 0; i < spawners.size(); i++) {
		if (!spawners[i]->occupied) {
			Vehicle* v;
			if (spawners[i]->spawnNext(v)) {
				cout << "Vehicle spawned" << endl;
				registerVehicle(v);
			}
		}
	}
}

