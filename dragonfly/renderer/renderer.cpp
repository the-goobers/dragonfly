#include <glad/glad.h>
#include "renderer.hpp"
#include <GLFW/glfw3.h>
#include <gl/GL.h>

namespace dfly::renderer {
	int gl_compat::init() {
		if (gladLoadGL() != 0) {
			return 1;
		}

		this->window = window;

		return 0;
	}

	void gl_compat::draw() {
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}