//
//  main.cpp
//  Test
//
//  Created by Mitchell Matsumori-Kelly on 2/23/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Game.h"

using namespace age;
using namespace age::scene;
using namespace age::video;



int main(int argc, const char * argv[]) {
	using namespace age;
	
	
	shootergame::Game::Current()->Start();
	
	return 0;
}
