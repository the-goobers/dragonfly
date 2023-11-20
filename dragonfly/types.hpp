#ifndef DRAGONFLY_TYPES_HPP
#define DRAGONFLY_TYPES_HPP

#include <cstdint>
#include <cstddef>

namespace dfly {
	using u0 = void;

	using u8 = std::uint8_t;
	using u16 = std::uint16_t;
	using u32 = std::uint32_t;
	using u64 = std::uint64_t;
	using s8 = std::int8_t;
	using s16 = std::int16_t;
	using s32 = std::int32_t;
	using s64 = std::int64_t;
	using f32 = float;
	using f64 = double;

	using usize = std::size_t;
	using uptr = std::uintptr_t;
	using ptrdiff = std::ptrdiff_t;
}

#endif
