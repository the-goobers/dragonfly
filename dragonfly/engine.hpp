#ifndef DRAGONFLY_ENGINE_HPP
#define DRAGONFLY_ENGINE_HPP

#include "types.hpp"
#include "window.hpp"
#include "renderer/renderer.hpp"

namespace dfly {
	struct engine {
		window* window = nullptr;
		renderer::renderer* renderer = nullptr;

		engine() = default;
		~engine() = default;

		int init();
		int run();

		static void glfw_error_callback(int err, const char* msg);
	};
}

#endif