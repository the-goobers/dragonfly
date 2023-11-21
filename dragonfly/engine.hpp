#ifndef DRAGONFLY_ENGINE_HPP
#define DRAGONFLY_ENGINE_HPP

#include "types.hpp"
#include "window.hpp"
#include "renderer/renderer.hpp"

namespace dfly {
	struct engine {
		window window{};
		renderer::renderer renderer{};

		engine() = default;
		~engine() = default;

		int init();
	};
}

#endif