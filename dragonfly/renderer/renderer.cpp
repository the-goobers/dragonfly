#include "renderer.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <gl/GL.h>

namespace dfly::renderer {
	/* dfly::renderer::renderer */
	void renderer::draw() {
		
	}

	/* dfly::renderer::gl_compat */
	gl_compat::gl_compat() {
		glfwMakeContextCurrent(glfwGetCurrentContext());
		gladLoadGL();
		glViewport(0, 0, 800, 600);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	void gl_compat::draw() {
		
	}
}