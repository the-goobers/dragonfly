#include "engine.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

namespace dfly {
	int engine::init(renderer::type renderer_type) {
		if (!glfwInit()) {
			return 1;
		}
		glfwSetErrorCallback(engine::glfw_error_callback);

		this->renderer_type = renderer_type;
		this->window = new dfly::window();
		switch (this->renderer_type) {
			case renderer::type::automatic:
				this->renderer_type = renderer::type::gl_compat;
			case renderer::type::gl_compat:
				this->renderer = new renderer::gl_compat();
				break;
			case renderer::type::gl_modern:
				return 2;
				break;
			default:
			case renderer::type::custom:
				return 3;
				break;
		}
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