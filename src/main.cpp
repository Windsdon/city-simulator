/*
 * main.cpp
 *
 *  Created on: 31/08/2014
 *      Author: Windsdon
 */

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "City.h"
#include "TileRoad.h"
#include "TileSpawner.h"
#include "TileDestructor.h"
#include "TileIntersection.h"

using namespace sf;
using namespace std;

int main(int argc, char **argv) {
	cout << "" << endl;
	VideoMode vm(720, 720);
	RenderWindow window(vm, "City", Style::Close);

	TileRoad::texture.loadFromFile("res/road.png");
	TileSpawner::texture.loadFromFile("res/spawner.png");
	TileIntersection::texture.loadFromFile("res/intersection.png");
	TileDestructor::texture.loadFromFile("res/destructor.png");

	City test(20, 20);

	sf::Clock clock;
	sf::Time extra = sf::seconds(0);
	sf::Time tickTime = sf::seconds(0.5);

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}

		if((clock.getElapsedTime() + extra) >= tickTime){
			extra += clock.restart() - tickTime;
			test.doTick();
		}

		window.clear(sf::Color::Black);

		test.render(window, (clock.getElapsedTime() + extra).asSeconds()/tickTime.asSeconds());

		window.display();
	}
}

