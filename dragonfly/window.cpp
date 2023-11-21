#include "window.hpp"
#include <GLFW/glfw3.h>
#include <string>

namespace dfly {
	int window::init(u32 width, u32 height, std::string& title) {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		this->internal.window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(this->internal.window);
	}
}