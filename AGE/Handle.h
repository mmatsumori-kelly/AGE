//
//  Handle.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Handle__
#define __AGE__Handle__

#include <type_traits>
#include "Debug.h"

namespace age {
	
	template <typename T> class Handle;
	
	/** Represents a handleable object */
	class IRefCounted {
		template <typename T> friend class Handle;
	private:
		int ref_count;
	public:
		IRefCounted() : ref_count(1) { }
		virtual ~IRefCounted() { }
		
		void AddReference() {
			ref_count++;
		}
		int RemoveReference() {
			return (--ref_count);
		}
	};
	
	
	
	/** A handle used for holding Reference-Countable objects */
	template <typename T> class Handle {
		template <typename U> friend class Handle;
		T *target;
		
		void DecRef() {
			if ( target && target->RemoveReference() == 0 ) {
				delete target;
				target = nullptr;
			}
				
		}
		
	public:
		
		inline Handle() : target(nullptr) {
			
		}
		template <typename U>
		inline Handle(U *target) : target(target) {
			static_assert(std::is_same<T, U>::value || std::is_base_of<T, U>::value, "Handle value type must be derived from original type");
			if ( target != nullptr )
				target->AddReference();
		}
		template <typename U>
		inline Handle(const Handle<U> &other) {
			static_assert(std::is_same<T, U>::value || std::is_base_of<T, U>::value, "Handle value type must be derived from original type");
			target = other.target;
			if ( target ) target->AddReference();
		}
		inline ~Handle() {
			DecRef();
		}
		
		
		/** Returns the reference count for the target */
		inline long GetReferenceCount() const {
			return (target == nullptr) ? 0 : target->ref_count;
		}
		
		
		/** Operators */
		inline T* Get() {
			return target;
		}
		inline T* operator ->() {
			return target;
		}
		inline T& operator *() {
			return *target;
		}
		
		inline bool operator ==(const Handle<T> &other) const {
			return target == other.target;
		}
		inline bool operator ==(void *ptr) const {
			return target == ptr;
		}
		inline bool operator !=(const Handle<T> &other) const {
			return target != other.target;
		}
		inline bool operator !=(void *ptr) const {
			return target != ptr;
		}
		template <typename U>
		inline operator U*() {
			return (U*)target;
		}
		
		
		template <typename U>
		inline Handle<T> &operator =(Handle<U> &right) {
			if ( this == &right ) return *this;
			else if ( right.target ) right->AddReference();
			
			DecRef();
			target = right.target;
			return *this;
		}
	};
	
	
	
}

#endif /* defined(__AGE__Handle__) */
