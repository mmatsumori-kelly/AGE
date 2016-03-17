//
//  Time.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/23/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Timing.h"
#include <chrono>

using namespace age;









HighPrecisionDuration HighPrecisionDuration::Now() {
	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}





