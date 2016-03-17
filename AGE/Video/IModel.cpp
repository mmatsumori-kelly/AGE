//
//  IModel.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "../Strings.h"
#include "IModel.h"
#include "SimpleModel.h"

using namespace age;
using namespace age::video;






IModel* age::video::LoadModel(const age::File &file, ModelType type) {
	switch ( type ) {
		case AGE_MODEL_SMDL: return SimpleModel::Load(file);
		case AGE_MODEL_AUTO: {
			if ( StringEndsWith(file.GetPath(), ".smdl") ) {
				return SimpleModel::Load(file);
			}
		}; break;
		default : return nullptr;
	}
	return nullptr;
}



