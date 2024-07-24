In this README file, I will tell you about the task that needed to be completed, and my solution is in the file Unique_ptr.h

Condition

C++ provides a template class std::unique_ptr for safe operation with dynamically allocated memory (and other resources). In std::unique_ptr, all the necessary operations are overloaded to work comfortably with objects as if they were ordinary pointers (which also clear memory for themselves). Objects of this class are considered the only owners of the resource they point to, so these objects cannot be copied, but they can be moved - transfer ownership to another object. Using std::unique_ptr imposes almost no additional computing costs, so using it is as efficient as using regular pointers, and at the same time much safer.

Task

Implement the UniquePtr template, a simplified analogue of the smart pointer class with unique ownership, std::unique_ptr (C++11).

Implementation Details

The template class must support:

The default constructor (creates a null pointer).
Constructor from the pointer (saves the pointer to the object).
The copy constructor and copying assignment should be omitted.
The moving constructor and the moving assignment must transfer ownership of the object.
The Release() method, which weans the class from owning the current resource and returns a pointer to it.
The Reset method(T* ptr = nullptr) changes the pointer owned by the object (the old resource is deleted).
The Swap(UniquePtr&) method.
The Get() method that returns a pointer to an object.
Dereference operator operator*.
The "arrow" operator is operator->.
An explicit conversion operator to bool (operator bool).
