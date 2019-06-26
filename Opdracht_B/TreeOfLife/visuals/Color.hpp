#ifndef YGGDRASIL_VISUALS_COLOR_HEADER
#define YGGDRASIL_VISUALS_COLOR_HEADER

namespace yggdrasil
{

inline namespace visuals
{

struct Color final
{

	union
	{

		struct
		{
			uint8_t r, g, b;
		};

		uint8_t raw[3];

	};

	Color(void) noexcept;

	Color(uint8_t red, uint8_t green, uint8_t blue) noexcept;
	explicit Color(uint32_t color) noexcept;


	explicit operator uint32_t(void) const noexcept;

	const uint8_t& operator[](uint8_t n) const noexcept;
	uint8_t& operator[](uint8_t n) noexcept;

};

}

}

//Include implementation to allow inlining.
#include "Color.cpp"

#endif
