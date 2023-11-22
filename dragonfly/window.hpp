#ifndef DRAGONFLY_WINDOW_HPP
#define DRAGONFLY_WINDOW_HPP

#include "types.hpp"
#include <string>
#include <GLFW/glfw3.h>

namespace dfly {
	struct window_internal_t {
		GLFWwindow * window;
	};

	struct window {
		bool closed = false;

		u32 width{};
		u32 height{};
		window_internal_t internal{};

		window() = default;
		~window() = default;

		/* creates the window */
		int init(u32 width, u32 height, std::string_view title);
		/* requests a back-buffer frame swap */
		void swap();
	};
}

#endif