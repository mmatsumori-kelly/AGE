//
//  File.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/26/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "File.h"
#include "Environment.h"
#include "Strings.h"
#include <sys/stat.h>
#include <dirent.h>
#include <fstream>
using namespace age;

/* File */
File::File() : path(Environment::Current()->GetUserFolder().GetPath()) {
	
}
File::File(const std::string &path) {
	const size_t strlen = path.length();
	
	// Some string manipulation
	if ( StringEndsWith(path, '/') ) this->path = (strlen == 1) ? path : path.substr(0, strlen - 1);
	else if ( strlen == 0 ) this->path = Environment::Current()->GetUserFolder().GetPath();
	else this->path = path;
}



bool File::IsDirectory() const {
#if __IS_UNIX
	struct stat st;
	return (stat(path.c_str(), &st) == 0) && (st.st_mode & S_IFDIR);
#endif
}
bool File::Exists() const {
#if __IS_UNIX
	struct stat st;
	return (stat(path.c_str(), &st) == 0);
#endif
}
void File::MakeDirectory() const {
	if ( !Exists() )
		mkdir(GetPath().c_str(), 0777);
}

bool File::WriteText(const std::string &text, bool append) const {
	if ( IsDirectory() ) return false;
	else {
		
		// Open a file
		std::ofstream ofs;
		ofs.open(path, append ? (std::ofstream::out | std::ofstream::app) : std::ofstream::out);
		
		// If it's good, write to it
		if ( ofs.good() ) {
			ofs << text;
			ofs.close();
		}
		else return false;
	}
	
	return true;
}
std::string File::ReadText(bool *fail_check) const {
	if ( fail_check != nullptr ) *fail_check = true;
	
	// If it's a directory we've failed
	if ( IsDirectory() ) {
		if ( fail_check != nullptr ) *fail_check = false;
		return "";
	}
	else {
		
		// Open the file
		std::ifstream ifs;
		ifs.open(path);
		
		// Check if it's good
		if ( ifs.good() ) {
			std::string text;
			
			// Reserve memory
			ifs.seekg(0, std::ios::end);
			text.reserve(ifs.tellg());
			ifs.seekg(0, std::ios::beg);
			
			// Read the file
			text.assign((std::istreambuf_iterator<char>(ifs)),
						std::istreambuf_iterator<char>());
			
			
			// Close the file
			ifs.close();
			return text;
		}
		else {
			if ( fail_check != nullptr ) *fail_check = false;
			return "";
		}
	}
}
std::vector<std::string> File::ReadLines()   const {
	// If it's a directory or doesn't exist, return nothing
	if ( IsDirectory() || !Exists() ) return {};
	// Read the file and split it by newline characters
	else return StringSplitByChar(ReadText(), '\n');
}


std::vector<File> File::GetChildren() const {
	std::vector<File> out;
	
	if ( Exists() ) {
		DIR *dir;
		class dirent *ent;
		class stat st;
		
		// Open the directory
		dir = opendir(GetPath().c_str());
		
		// Loop through its contents
		while ((ent = readdir(dir)) != NULL) {
			const std::string file_name = ent->d_name;
			const std::string full_file_name = GetPath() + "/" + file_name;
			
			
			// This directory
			if ( file_name[0] == '.' ) continue;
			// Failure
			if (stat(full_file_name.c_str(), &st) == -1) continue;
			// Directory
			if ( (st.st_mode & S_IFDIR) != 0 ) continue;
			
			// Add the file name
			out.push_back(full_file_name);
		}
		
		// Close the directory
		closedir(dir);
	}
	
	// Return the files
	return out;
}

