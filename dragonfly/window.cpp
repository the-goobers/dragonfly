#include "window.hpp"
#include <GLFW/glfw3.h>
#include <string>

namespace dfly {
	int window::init(u32 width, u32 height, std::string_view title, renderer::type renderer_type) {
		this->width = width;
		this->height = height;
		this->renderer_type = renderer_type;

		switch (this->renderer_type) {
			case renderer::type::automatic:
				this->renderer_type = renderer::type::gl_compat;
			case renderer::type::gl_compat:
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
				break;
			case renderer::type::gl_modern:
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
				break;
			default:
			case renderer::type::custom:
				glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
				break;
		}

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