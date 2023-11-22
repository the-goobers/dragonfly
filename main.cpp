#include <iostream>
#include "dragonfly/types.hpp"
#include "dragonfly/engine.hpp"

int main(int argc, char** argv) {
	dfly::engine e{};
	dfly::renderer::gl_compat r{};
	dfly::window w{};

	if (e.init() != 0) {
		return 1;
	}

	if (w.init(800, 600, "title") != 0) {
		return 2;
	}

	r.window = &w;

	if (r.init() != 0) {
		return 3;
	}

	e.window = &w;
	e.renderer = &r;

	return e.run();
}
