//
//  Environment.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/26/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Environment.h"
#include <unistd.h>

using namespace age;

#if __IS_UNIX
#include <pwd.h>
#endif





Environment Environment::singleton = Environment();
Environment::Environment() {
	
	
	/* Unix Platform */
#if __IS_UNIX
	uid_t uid = geteuid();
	struct passwd *pw = getpwuid(uid);
	
	
	if ( pw ) {
		user_name = pw->pw_name;
		user_folder = File(pw->pw_dir);
	}
	
#endif
	
}
Environment::~Environment() {
	
}

