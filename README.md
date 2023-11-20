# dragonfly
## a collaborative C++ game engine

## requirements for contribution/code style
### C++20

### commit messages
- they can be silly
- keep informative if possible
- preferably brief

### to oop or not to oop
#### no formal rules, just keep in mind these guidelines
- this is not java; no need to have everything be an object
- "If the only tool you have is a hammer, you will start treating all your problems like a nail"
- don't treat oop as the only option, keep it simple or procedural when possible
- using classes is graet for interfaces and for containerizing functionality

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
- `root/include/` for header files
- `root/src/` for implementation files
- `root/libs/` for external libraries
- `root/build/` for all buildsystem related things
  
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
- left oriented asterisk pointer types
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
- please document all exposed functions and tid-bits inside headers with an overview of the interface (no need for describing implementation behavior as long as it's not observable to the user)
- make sure the user knows about any side-effect the function might produce 

#### example:
```cpp
/* returns a hash of the str using algorithm X */
u64 hash(std::string_view str);
```

### classes
#### names
- lowercase
- kept in appropriate namepsace
```cpp
namespace dfly::audio {
	struct sound {
		...
	};
}
```

#### general code-style 
- general use of snake_case
- no prefix like `_` or `m_`, just regular names
- structs that are not primitive datatypes must be marked with a leading ``c_``
- access variables using `this->...` always
- call member functions/methods using `method(...)`
- inline member functions inside headers must not rely on any external functions
- inline member functions inside headers must not use any types from lower in the composition hierarchy
- use ``struct`` always
- all members of a struct should be public
- implementation functions that are not to be used by other parts of the code must be defined in the
  	implementation of that header file
- arguments of any functor (functions, lambdas, callables, func-decls, ...) must have a leading underscore
- do not write getters and setters if they dont handle any external logic
- avoid RAII -> constructors and destructor have to always be pure functions (!)
- outside of the functions that interface with external code pure functions are preferable
- make use of RVO and nRVO when possible
- dont use const-references of types smaller than gp-registers 
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
