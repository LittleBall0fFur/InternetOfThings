#ifndef YGGDRASIL_VISUALS_COLOR_IMPLEMENTATION
#define YGGDRASIL_VISUALS_COLOR_IMPLEMENTATION

namespace yggdrasil
{

inline namespace visuals
{

Color::Color(void) noexcept
	: r{ 0 },
	  g{ 0 },
	  b{ 0 }
{
	//Empty.
}

Color::Color(const uint8_t red, const uint8_t green, const uint8_t blue) noexcept
	: r{ red },
	  g{ green },
	  b{ blue }
{
	//Empty.
}

Color::Color(const uint32_t color) noexcept
	: r{ static_cast<uint8_t>((color >>  0) & 0xFF) },
	  g{ static_cast<uint8_t>((color >>  8) & 0xFF) },
	  b{ static_cast<uint8_t>((color >> 16) & 0xFF) }
{
	//Empty.
}


Color::operator uint32_t(void) const noexcept
{
	uint32_t color = (r << 0) & (g << 8) & (b << 16);

	return color;
}

const uint8_t& Color::operator[](const uint8_t n) const noexcept
{
	return raw[n];
}

uint8_t& Color::operator[](const uint8_t n) noexcept
{
	return raw[n];
}

}

}

#endif
