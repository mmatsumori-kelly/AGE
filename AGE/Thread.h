//
//  Thread.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/25/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Thread__
#define __AGE__Thread__

#include <thread>



namespace age {
	
	
	/** Use for thread-safe variables */
	template <typename T> using Atomic = std::atomic<T>;
	
	
	/** A runnable function for a single thread of execution */
	template <typename ReturnType, typename... Args>
	class RunnableFunction {
		std::function<ReturnType(Args...)> function;
		
		
		
	public:
		RunnableFunction() : function(nullptr) {
			
		}
		RunnableFunction(ReturnType (*function)(Args...))   {
			this->function = function;
		}
		
		
		/** Runs the function */
		inline void Run(Args... args) {
			function(args...);
		}
		
	};
	
	
	
	
	
	
	
	/** Thread utility class */
	class Thread {
		std::thread *thread;
		RunnableFunction<void, void*> *current_function;
		
		Atomic<bool> is_running;
		
		
		static inline void RunThread(Thread *thread, void *user_ptr) {
			thread->is_running = true;
			thread->current_function->Run(user_ptr);
			thread->is_running = false;
		}
		
	public:
		Thread() : thread(nullptr), current_function(nullptr) {
			
		}
		Thread(const Thread& other) = delete;
		~Thread() {
			if ( thread != nullptr ) Join();
			delete thread;
			delete current_function;
		}
		
		
		
		/** Checks if the thread is running */
		inline bool IsRunning()        {
			return is_running.load();
		}
		/** Checks if this thread is joinable */
		inline bool IsJoinable() const {
			return (thread != nullptr) ? thread->joinable() : false;
		}
		/** Waits for this thread of execution to complete */
		void Join();
		
		
		
		/** Starts the thread */
		void Start(void (*function)(void*), void *user_ptr, bool wait_for_thread_start);
	};
	
	
	
}


#endif /* defined(__AGE__Thread__) */
