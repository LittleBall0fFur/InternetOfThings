#ifndef YGGDRASIL_VISUALS_LEDCONTROLLER_IMPLEMENTATION
#define YGGDRASIL_VISUALS_LEDCONTROLLER_IMPLEMENTATION

#include "LEDController.hpp"

namespace yggdrasil
{

inline namespace visuals
{

namespace /* utilities */
{

inline uint16_t RGBElementToPWMTicks(const uint8_t element) noexcept
{
	return (element / 255.0) * 4095;
}

}

LEDController::LEDController(TwoWire& i2c) noexcept
	:	m_ledDriver{ i2c },
		ledBuffer{ 0, 0, 0 }
{
	//Empty.
}

void LEDController::begin(const uint8_t i2cAddress) noexcept
{
	m_ledDriver.init(i2cAddress);
}

void LEDController::update(void) noexcept
{
	uint8_t current_channel = 0;

	for (auto led : ledBuffer)
	{
		for (auto element : led.raw)
		{
			m_ledDriver.setChannelPWM(current_channel++, RGBElementToPWMTicks(element));
		}
	}
}

}

}

#endif
