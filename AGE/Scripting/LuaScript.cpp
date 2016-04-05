//
//  Scripting.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/8/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "LuaScript.h"
#include "../Vector.h"
#include "../GUI/Display.h"
#include <iostream>
#include "../Scene/SceneManager.h"
#include "../Scene/ActorNode.h"

using namespace age;
using namespace age::scripting;
using namespace age::gui;
using namespace age::scene;











void LuaState::OpenLibs(LuaState *state)
{
	luaopen_io(state->state);
	luaopen_base(state->state);
	luaopen_table(state->state);
	luaopen_string(state->state);
	luaopen_math(state->state);
	luaL_openlibs(state->state);
	
	state->GetGlobalNamespace()
	
	.beginClass<Duration>("Duration")
	.addFunction("Seconds", &Duration::Seconds)
	.endClass()
	
	.beginClass<UpdateInfo>("UpdateInfo")
	.addData("delta_time", &UpdateInfo::delta_time)
	.endClass()
	
	
	// Vectors
	.beginClass<FVec3>("FVec3")
	.addConstructor<void(*)(float, float, float)>()
	.addData("x", &FVec3::x)
	.addData("y", &FVec3::y)
	.addData("z", &FVec3::z)
	.endClass()
	.beginClass<FVec2>("FVec2")
	.addConstructor<void(*)(float, float)>()
	.addData("x", &FVec2::x)
	.addData("y", &FVec2::y)
	.endClass()
	.beginClass<IVec3>("IVec3")
	.addConstructor<void(*)(int, int, int)>()
	.addData("x", &IVec3::x)
	.addData("y", &IVec3::y)
	.addData("z", &IVec3::z)
	.endClass()
	.beginClass<IVec2>("IVec2")
	.addConstructor<void(*)(int, int)>()
	.addData("x", &IVec2::x)
	.addData("y", &IVec2::y)
	.endClass()
	
	
	// Input
	.beginClass<Keyboard>("Keyboard")
	.addFunction("IsPressed", &Keyboard::IsKeyNamePressed)
	.endClass()
	
	.beginClass<Mouse>("Mouse")
	.addFunction("IsPressed", &Mouse::IsButtonPressed)
	.addFunction("GetX", &Mouse::GetX)
	.addFunction("GetY", &Mouse::GetY)
	.addFunction("GetDX", &Mouse::GetDeltaX)
	.addFunction("GetDY", &Mouse::GetDeltaY)
	.endClass()
	
	.beginClass<Display>("Display")
	.addFunction("GetMouse", &Display::GetMouse)
	.addFunction("GetKeyboard", &Display::GetKeyboard)
	.endClass()
	
	
	// Scene
	.beginClass<ActorNode>("ActorNode")
	.addFunction("GetPosition", &ActorNode::GetPosition)
	.addFunction("GetRotation", &ActorNode::GetRotation)
	.addFunction("GetVelocity", &ActorNode::GetVelocity)
	.addFunction("SetPosition", &ActorNode::SetPosition)
	.addFunction("SetRotation", &ActorNode::SetRotation)
	.addFunction("SetVelocity", &ActorNode::SetVelocity)
	.endClass()
	
	.beginClass<Camera>("Camera")
	.addFunction("SetPosition", &Camera::SetPosition)
	.addFunction("SetRotation", &Camera::SetRotation)
	.addFunction("Translate", &Camera::Move)
	.addFunction("Rotate", &Camera::Rotate)
	.addFunction("GetPosition", &Camera::GetPosition)
	.addFunction("GetRotation", &Camera::GetRotation)
	.addFunction("GetUpVector", &Camera::GetUpVector)
	.addFunction("GetForwardVector", &Camera::GetForwardVector)
	.addFunction("GetRightVector", &Camera::GetRightVector)
	.endClass()
	
	
	.beginClass<SceneManager>("SceneManager")
	.addFunction("GetCamera", &SceneManager::GetCamera)
	.endClass()
	
	
	
	// Scripting
	.beginClass<LuaState>("LuaState")
	.addConstructor<void(*)()>()
	.addFunction("ExecFile", &LuaState::ExecFile)
	.addFunction("ExecString", &LuaState::ExecString)
	.addFunction("GetGlobal", &LuaState::GetGlobal)
	.endClass()
	;
	
	state->SetGlobal("this_state", state);
}
void LuaState::ReportErrors(lua_State *L, const int status) {
	if ( status != 0 ) {
		std::cerr << "Lua Error: " << lua_tostring(L, -1) << std::endl;
		lua_pop(L, 1); // remove error message
	}
}











