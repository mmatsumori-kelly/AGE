//
//  Player.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Player__
#define __AGE__Player__

#include "Entity.h"

namespace shootergame {
	
	
	
	
	class Player : public Entity {
		
		
	public:
		Player();
		
		
		virtual void Update(const age::UpdateInfo &info) override;
		virtual void Render(const age::UpdateInfo &info) override;
		
	};
	
	
}

#endif /* defined(__AGE__Player__) */
