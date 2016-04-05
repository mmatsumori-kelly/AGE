//
//  Debug.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/25/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Debug__
#define __AGE__Debug__

#include <string>
#include <iostream>
#include "Vector.h"

namespace age {
	
	
	/** Returns a formatted time string */
	std::string GetFormattedTime(const std::string &format);
	
	
	
	/** Logs a message to the console */
	template <typename ...Args> inline void LogWithType(const std::string &type, const std::string &message, const Args&... args) {
		static bool locked = false;
		
		
		while ( locked ) continue;
		
		locked = true;
		
		printf("%s", type.c_str());
		printf("%s", GetFormattedTime("[%D %X]: ").c_str());
		printf(message.c_str(), args...);
		printf("\n");
		
		locked = false;
	}
	/** Logs a message to the console */
	template <typename ...Args> inline void LogMessage(const std::string &message, const Args&... args) {
		LogWithType("MESSAGE", message, args...);
	}
	/** Logs a warning to the console */
	template <typename ...Args> void LogWarning(const std::string &warning, const Args&... args) {
		LogWithType("WARNING", warning, args...);
	}
	/** Logs an error to the console */
	template <typename ...Args> void LogError  (const std::string &error, const Args&... args) {
		LogWithType("ERROR  ", error, args...);
	}
	
	
	
	
	/** Crashes the program if the condition is false, and prints the error message */
	inline void Assert(bool condition, const std::string &error_message) {
		if ( !condition ) {
			LogError("Assertion Failed: %s", error_message.c_str());
			exit(1);
		}
	}
	
	
	
	
	void PrintOpenGLErrors();
	
	
	const char endline = '\n';
	
	
	static struct SecondMessage {
		
	public:
		
		template <typename T>
		inline SecondMessage& operator <<(const T &t) {
			std::cout << t;
			return *this;
		}
		
	} second_message;
	
	static struct FirstMessage {
		std::string type_str;
		
	public:
		FirstMessage(const std::string &type_str) : type_str(type_str) { }
		
		
		template <typename T>
		inline SecondMessage& operator <<(const T &t) {
			std::cout << type_str << GetFormattedTime("[%D %X]: ") << t;
			return second_message;
		}
		inline SecondMessage& operator <<(const age::FVec3 &vec) {
			std::cout << type_str << GetFormattedTime("[%D %X]: {") << vec.x << ", " << vec.y << ", " << vec.z << "}";
			return second_message;
		}
		inline SecondMessage& operator <<(const age::DVec3 &vec) {
			std::cout << type_str << GetFormattedTime("[%D %X]: {") << vec.x << ", " << vec.y << ", " << vec.z << "}";
			return second_message;
		}
		
	} message("MESSAGE"), error("ERROR  ");
	
	
}

#endif /* defined(__AGE__Debug__) */
