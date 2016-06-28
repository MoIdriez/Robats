/*
 * Main.cpp
 *
 *  Created on: 8 Jun 2016
 *      Author: midries
 */
#include "Hover.cpp"
// Please only use this to run whatever you want
int main(int argc, char **argv) {
	try {
		Hover g;
		g.run();
	} catch(char const* msg) {
		std::cout << msg;
	}
}


