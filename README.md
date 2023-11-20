# dragonfly
## a collaborative C++ game engine

## requirements for contribution/code style
### C++20

### commit messages
- they can be silly
- keep informative if possible
- preferably brief

### general naming conventions
- macros are `SCREAMING_SNAKE` case and prefixed with `DRAGONFLY_`
	```cpp
 	#define DRAGONFLY_MACRO_THAT_DOES_SOMETHING()
 	```
- regular variables and arguments are `snake_case`
- functors are to be `snake_case`
- objects are to be `snake_case`
	- datatype structs are `snake_case` post-fixed with `_t`, like so `structure_t`
	- regular methodic structs have no post-fix
- namespaces are to be `snake_case`

### to oop or not to oop
#### no formal rules, just keep in mind these guidelines
- this is not java; no need to have everything be an object
- "If the only tool you have is a hammer, you will start treating all your problems like a nail"
- don't treat oop as the only option, keep it simple or procedural when possible
- using objects is great for interfaces and for containerizing functionality

### inheritance
- try to avoid inheritance
- use composition when possible
- inheritance for generic interfaces is a valid use in this project

### namespaces
- main dragonfly namespace is `dfly`
- sub-systems of dragonfly can have their own namespace
	- renderer `dfly::renderer`
	- audio `dfly::audio`
	- ui `dfly::ui`

### files
- `.cpp` for C++ source files/implementations
- `.hpp` for C++ headers

### folder structure
- `./dragonfly/` for dragonfly engine headers and implementation
- `./libs/` for external libraries
- `./build/` for all build system related things
  
### header guards
```cpp
/* dragonfly/file.hpp */

#ifndef DRAGONFLY_FILE_HPP
#define DRAGONFLY_FILE_HPP

...

#endif

/* dragonfly/path/to/file.hpp */

#ifndef DRAGONFLY_PATH_TO_FILE_HPP
#define DRAGONFLY_PATH_TO_FILE_HPP

...

#endif
```

### types
- use the declared types in dragonfly/types.hpp
	- uN for unsigned integer of N bits
	- sN for signed integer of N bits
	- fN for float of N bits
- bool for booleans
- left-oriented asterisk pointer types
	- `type* name;`
	- `u32* ptr;`

### functions
```cpp
/* template */
type func(type arg);
type func(type arg) {
	...
}

/* example */
s32 foo(u8 byte);
s32 foo(u8 byte) {
	...
}
```

### comments/documentation
- use /* ... */ for all non-temporary comments
- please document all exposed functions and tidbits inside headers with an overview of the interface (no need for describing implementation behavior as long as it's not observable to the user)
- make sure the user knows about any side-effect the function might produce 

#### example:
```cpp
/* returns a hash of the str using algorithm X */
u64 hash(std::string_view str);
```

### classes
#### names
- lowercase
- kept in appropriate namespaces
```cpp
namespace dfly::audio {
	struct sound {
		...
	};
}
```

#### general code-style 
- general use of snake_case
- members have no prefixes
- datatype structs are post-fixed with `_t` (no methods)
- access variables using `this->...` always
- call member functions/methods using `method(...)` without using `this` pointer
- inline member functions inside headers must not rely on any external functions
- inline member functions inside headers must not use any types from lower in the composition hierarchy
- use `struct` always
- all members of a struct should be public
- implementation functions that are not to be used by other parts of the code must be defined in the implementation/source file
- do not write getters and setters if they don't handle any external logic
- avoid RAII -> constructors and destructors have to always be pure functions (!)
- outside of the functions that interface with external code pure functions are preferable
- make use of RVO and nRVO when possible
- don't use const-references of types smaller than gp-registers 
```cpp
/* header and source combination for example simplicity */

struct c_example {
	usize index;

	u8 test() {
		index = 8;
		return index;
	}
};
```

#### declaration
```cpp
/* foo.hpp */

struct c_foo {
	u32 id;

	Foo() = default;
	...
	u32 calculate() const;

};
```

#### implementation
```cpp
/* foo.cpp */
#include <external_dependency.hpp>

inline u32 calculate_impl(u32 _id)
{
	return external::calc(_id);
}

u32 c_foo::calculate()
{
	return calculate_impl(this->id);
}
```
