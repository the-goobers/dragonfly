#include "engine.hpp"
#include <GLFW/glfw3.h>
#include <exception>

namespace dfly {
	int engine::init() {
		if (!glfwInit()) {
			return 1;
		}
		
		return 0;
	}
};