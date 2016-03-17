//
//  OBJModel.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/13/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "OBJModel.h"
#include "../Strings.h"
#include <fstream>

using namespace age;
using namespace age::video;


OBJModel::~OBJModel() {
	
}

OBJModel* OBJModel::Load(const age::File &file) {
	std::vector<FVec3> vertices, normals;
	std::vector<FVec2> uvs;
	std::vector<IVec3> faces;
	
	
	std::ifstream input;
	std::string line;
	
	
	input.open(file.GetPath().c_str());
	
	if ( input.good() ) {
		while ( std::getline(input, line) ) {
			std::vector<std::string> tokens = StringSplitByChar(line, ' ');
			
			// Check tokens
			if ( tokens.size() > 0 ) {
				const std::string &command = tokens[0];
				if ( command.compare("v") == 0 ) {
					vertices.push_back(FVec3(std::stof(tokens[1]), std::stof(tokens[2]), std::stof(tokens[3])));
				}
				else if ( command.compare("vt") == 0 ) {
					uvs.push_back(FVec2(std::stof(tokens[1]), std::stof(tokens[2])));
				}
				else if ( command.compare("vn") == 0 ) {
					normals.push_back(FVec3(std::stof(tokens[1]), std::stof(tokens[2]), std::stof(tokens[3])));
				}
				else if ( command.compare("f") == 0 ) {
					faces.push_back(IVec3(std::stoi(tokens[1]), std::stoi(tokens[2]), std::stoi(tokens[3])));
				}
			}
			
		}
		input.close();
		
		
		
		std::vector<VertexInfo> vertex_data;
		vertex_data.reserve(faces.size() * 3);
		
//		for (const IVec3 &face : faces) {
////			vertex_data.push_back(vertic)
//		}
		
		return nullptr; 
		
		
	}
	else return nullptr;
}


void OBJModel::Render() {
	
}


