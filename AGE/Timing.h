//
//  Time.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/23/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Time__
#define __AGE__Time__

namespace age {
	
	
	/** A high-precision time */
	typedef class HighPrecisionDuration {
		unsigned long long nanoseconds;
		
	public:
		/** Zero time */
		inline HighPrecisionDuration() : nanoseconds(0) {
			
		}
		/** Time in nanoseconds */
		inline HighPrecisionDuration(unsigned long long nanoseconds) : nanoseconds(nanoseconds) {
			
		}
		
		
		/** Returns the current time */
		static HighPrecisionDuration Now();
		
		
		
		
		/** Returns the time in nanoseconds */
		inline unsigned long long Nanoseconds() const {
			return nanoseconds;
		}
		/** Returns the time in milliseconds */
		inline double Milliseconds()       const {
			return (long double)nanoseconds / 1e6;
		}
		/** Returns the time in second */
		inline double Seconds()            const {
			return nanoseconds / 1e9;
		}
		/** Returns the time in minutes */
		inline double Minutes()            const {
			return (long double)nanoseconds / 60e9;
		}
		/** Returns the time in hours */
		inline double Hours()              const {
			return (long double)nanoseconds / 36e11;
		}
		
		
		/* Operators */
		inline HighPrecisionDuration operator +(const HighPrecisionDuration &other) const {
			return nanoseconds + other.nanoseconds;
		}
		inline HighPrecisionDuration operator -(const HighPrecisionDuration &other) const {
			return nanoseconds - other.nanoseconds;
		}
		inline HighPrecisionDuration operator *(double scalar)                      const {
			return (unsigned long long)(nanoseconds * scalar);
		}
		inline HighPrecisionDuration operator /(double inv_scalar)                  const {
			return (inv_scalar == 0) ? 0 : (unsigned long long)(nanoseconds / inv_scalar);
		}
		
		inline HighPrecisionDuration &operator +=(const HighPrecisionDuration &other)     {
			nanoseconds += other.nanoseconds;
			return *this;
		}
		inline HighPrecisionDuration &operator -=(const HighPrecisionDuration &other)     {
			nanoseconds -= other.nanoseconds;
			return *this;
		}
		inline HighPrecisionDuration &operator *=(double scalar)                          {
			nanoseconds *= scalar;
			return *this;
		}
		inline HighPrecisionDuration &operator /=(double inv_scalar)                      {
			if ( inv_scalar == 0 ) nanoseconds = 0;
			else nanoseconds /= inv_scalar;
			return *this;
		}
		
	} Time, Duration;
	
	
	
	
	
	
	
	
	
	/** A timer class */
	class Timer {
		Time start_time;
		
	public:
		inline Timer() {
			
		}
		
		
		/** Starts the timer */
		inline void Start()       {
			start_time = Time::Now();
		}
		/** Returns the current time on this timer */
		inline Duration GetTime() {
			return Time::Now() - start_time;
		}
	};
	
	
	

	
	
	
	
	
}

#endif /* defined(__AGE__Time__) */
