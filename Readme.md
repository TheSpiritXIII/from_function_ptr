from_function_ptr
=================
from_function_ptr is a small library that converts one function pointer type to
another, granted that the function type you're converting has a matching prefix
of parameters.

from_function_ptr works by creating a functor. There are no hacks whatsoever.
Results are 99.9% guaranteed to work on any platform with every compiler that
supports variadic templates (c++11).

This is useful if you are restricted to a C-based API and are not able to use
std::function and need function pointers (and also too lazy to create a proxy
function).

License
-------
            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                    Version 2, December 2004

 Copyright (C) 2014 Daniel Hrabovcak

 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. You just DO WHAT THE FUCK YOU WANT TO.

Usage
-----
To use, simply include from_function_ptr.hpp in your project.

Example
-------
```c++
#include <iostream>
#include "from_function_ptr.hpp"

void do_nothing()
{
	std::cout << "PROXY FUNCTION!";
}

int main()
{
	// Convert from void(*)() to void(*)(int)
	// For first set of templates:
	//  Return type is void.
	//  Function has no other parameters, so nothing else is included there.
	// For second set of templates:
	//  Convert function 'do_nothing'.
	//  Add an extra 'int' parameter
	void (*some_function)(int) =
		from_function_ptr<void>::with<do_nothing, int>::function;
	some_function(4); // Valid
	return 0;
}
```
