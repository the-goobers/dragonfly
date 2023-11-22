#ifndef DRAGONFLY_RENDERER_RENDERER_HPP
#define DRAGONFLY_RENDERER_RENDERER_HPP

#include "../types.hpp"
#include "../window.hpp"

namespace dfly::renderer {
	enum class type {
		custom = 0,
		none = 0,
		gl_compat,
		gl_modern,
	};

	/* default renderer interface (not to be instantiated) */
	struct renderer {
		dfly::window* window = nullptr;

		renderer() = default;
		~renderer() = default;

		/* initializes renderer */
		virtual int init() = 0;
		/* draws a frame */
		virtual void draw() = 0;
	};

	struct gl_compat : renderer {
		/* initializes renderer */
		int init() override;
		/* draws a frame */
		void draw() override;
	};
}

#endif