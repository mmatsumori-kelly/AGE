//
//  Thread.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/25/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Thread.h"

using namespace age;





/** Waits for this thread of execution to complete */
void Thread::Join()             {
	if ( thread != nullptr && thread->joinable() ) {
		thread->join();
	}
}
void Thread::Start(void (*function)(void*), void *user_ptr, bool wait_for_thread_start) {
	if ( thread == nullptr ) {
		current_function = new RunnableFunction<void, void*>(function);
		thread = new std::thread(Thread::RunThread, this, user_ptr);
		if ( wait_for_thread_start ) {
			while ( !IsRunning() );
		}
	}
}





