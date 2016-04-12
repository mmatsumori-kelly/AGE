//
//  main.cpp
//  Test
//
//  Created by Mitchell Matsumori-Kelly on 2/23/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Game.h"


int main(int argc, const char * argv[]) {
	shootergame::Game *game = new shootergame::Game();
	game->Start();
	delete game;
}
