#ifndef DRAGONFLY_WINDOW_HPP
#define DRAGONFLY_WINDOW_HPP

#include "types.hpp"
#include "renderer/renderer.hpp"
#include <string>
#include <GLFW/glfw3.h>

namespace dfly {
	struct window_internal_t {
		GLFWwindow * window;
	};

	struct window {
		renderer::type renderer_type = renderer::type::none;
		bool closed = false;

		u32 width{};
		u32 height{};
		window_internal_t internal{};

		window() = default;
		~window() = default;

		/* creates the window with automatic renderer type */
		inline int init(u32 width, u32 height, std::string_view title) { init(width, height, title, renderer::type::automatic); }
		/* creates the window with explicit renderer type */
		int init(u32 width, u32 height, std::string_view title, renderer::type renderer_type);
		/* requests a back-buffer frame swap */
		void swap();
	};
}

#endif