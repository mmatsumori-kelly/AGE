//
//  Strings.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/26/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Strings.h"
#include <functional>
#include <sstream>



/* Trim Functions */
std::string age::StringTrimL(const std::string &in_str) {
	std::string str = in_str;
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return str;
}
std::string age::StringTrimR(const std::string &in_str) {
	std::string str = in_str;
	str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
	return str;
}




/* Split Functions */
std::vector<std::string> age::StringSplitByChar(const std::string &str, const char delim) {
	std::stringstream test(str);
	std::string segment;
	std::vector<std::string> seglist;
	
	while(std::getline(test, segment, delim))
	{
		seglist.push_back(segment);
	}
	return seglist;
}