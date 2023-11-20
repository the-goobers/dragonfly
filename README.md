# dragonfly
## a collaborative C++ game engine

## requirements for contribution/code style
### C++17

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

#### example:
```cpp
/* returns a hash of the str using algorithm X */
u64 hash(std::string& str);
```

### classes
#### names
- lowercase
- kept in appropriate namepsace
```cpp
namespace dfly::audio {
	class sound {
		...
	};
}
```

#### member names
- no prefix like `_` or `m_`, just regular names
- access variables using `this->...` always
- call member functions/methods using `method(...)`
```cpp
/* header and source combination for example simplicity */

class example {
public:
	usize index;

	void setIndex(usize index) {
		this->index = index;
	}
	
	u8 test() {
		setIndex(8);
		return 8;
	}
};
```

#### declaration
```cpp
/* foo.hpp */

class Foo {
public:
	Foo();
	...
	void setId(u32 id);

private:
	u32 id;
};
```

#### implementation
```cpp
/* foo.cpp */

void Foo::setId(u32 id) {
	this->id = id;
}
```