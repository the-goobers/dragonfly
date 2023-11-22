#include <iostream>
#include "dragonfly/types.hpp"
#include "dragonfly/engine.hpp"

int main(int argc, char** argv) {
	dfly::engine e{};

	e.init(dfly::renderer::type::gl_compat);
	return e.run();
}
