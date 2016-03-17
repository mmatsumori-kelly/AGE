//
//  Scripting.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/8/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Scripting__
#define __AGE__Scripting__

#include "../File.h"
#include <LuaBridge/LuaBridge.h>

namespace age {
	namespace scripting {
		
		
		
		
		
		
		/* A lua engine */
		class LuaState {
			lua_State *state;
			
			static void OpenLibs(LuaState *state);
			static void ReportErrors(lua_State *L, const int status);
			
		public:
			LuaState() : state(luaL_newstate()) {
				OpenLibs(this);
			}
			LuaState(LuaState &other) = delete;
			LuaState(const LuaState &other) = delete;
			~LuaState() {
				if ( state != nullptr ) lua_close(state);
			}
			
			/** Executes a file */
			inline bool ExecFile(const File &file) {
				int err = luaL_dofile(state, file.GetPath().c_str());
				ReportErrors(state, err);
				return err != 0;
			}
			
			/** Executes a string */
			inline bool ExecString(const std::string &code) {
				luaL_loadstring(state, code.c_str());
				int err = lua_pcall(state, 0, LUA_MULTRET, 0);
				ReportErrors(state, err);
				return err != 0;
			}
			
			inline bool operator() (const std::string &code) {
				return ExecString(code);
			}
			
			
			
			/** Returns the lua state */
			inline lua_State* GetState() const {
				return state;
			}
			/** Returns the global namespace */
			inline luabridge::Namespace GetGlobalNamespace() {
				return luabridge::getGlobalNamespace(state);
			}
			/** Returns a global variable */
			inline luabridge::LuaRef GetGlobal(const std::string &name) {
				return luabridge::getGlobal(state, name.c_str());
			}
			/** Returns a global variable */
			template <typename T>
			inline void SetGlobal(const std::string &name, const T& value) {
				return luabridge::setGlobal(state, value, name.c_str());
			}
			
			inline luabridge::LuaRef operator[](const std::string &name) {
				return GetGlobal(name);
			}
			
			
			template <typename... Args>
			inline void SafeCall(const luabridge::LuaRef &ref, const Args&... args) {
				if ( !ref.isNil() ) ref(args...);
			}
			inline void SafeCall(luabridge::LuaRef &ref) {
				if ( !ref.isNil() ) ref();
			}
			
			
			inline operator lua_State*() {
				return state;
			}
		};
		
		

		
		
		
		
	}
}

#endif /* defined(__AGE__Scripting__) */
