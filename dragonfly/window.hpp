#ifndef DRAGONFLY_WINDOW_HPP
#define DRAGONFLY_WINDOW_HPP

#include "types.hpp"
#include <string>

namespace dfly {
	struct window_internal_t {
		GLFWwindow * window;
	};

	struct window {
		u32 width{};
		u32 height{};
		struct window_internal_t internal{};

		window() = default;
		~window() = default;

		/* creates the window */
		int init(u32 width, u32 height, std::string& title);
		/* updates window events and window input */
		void update();
		/* requests a back-buffer frame swap */
		void swap();
	};
}

#endif