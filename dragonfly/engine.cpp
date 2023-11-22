#include "engine.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

namespace dfly {
	int engine::init() {
		if (!glfwInit()) {
			return 1;
		}

		glfwSetErrorCallback(engine::glfw_error_callback);
		
		return 0;
	}

	int engine::run() {
		if (this->window == nullptr) {
			return 1;
		}

		if (this->renderer == nullptr) {
			return 2;
		}

		while (!glfwWindowShouldClose(this->window->internal.window)) {
			this->renderer->draw();
			this->window->swap();
			glfwPollEvents();
		}
		glfwTerminate();

		return 0;
	}

	void engine::glfw_error_callback(int err, const char * msg) {
		std::cout << "GLFW error " << err << ": " << msg << "\n";
	}
};