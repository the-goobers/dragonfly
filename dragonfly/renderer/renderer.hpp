#ifndef DRAGONFLY_RENDERER_RENDERER_HPP
#define DRAGONFLY_RENDERER_RENDERER_HPP

#include "../types.hpp"

namespace dfly::renderer {
	/* default renderer interface (not to be instantiated) */
	struct renderer {
		renderer() = default;
		~renderer() = default;
		
		/* draws a frame */
		virtual void draw();
	};

	struct gl_compat : renderer {
		gl_compat();
		~gl_compat();
		
		/* draws a frame */
		void draw() override;
	};
}

#endif