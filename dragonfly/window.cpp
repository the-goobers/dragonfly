#include "window.hpp"
#include <GLFW/glfw3.h>
#include <string>

namespace dfly {
	int window::init(u32 width, u32 height, std::string_view title) {
		this->width = width;
		this->height = height;

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		this->internal.window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
		if (this->internal.window == NULL) {
			return 1;
		}

		return 0;
	}

	void window::swap() {
		glfwSwapBuffers(this->internal.window);
	}
}