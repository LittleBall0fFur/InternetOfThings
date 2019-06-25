#ifndef YGGDRASIL_VISUALS_LEDCONTROLLER_IMPLEMENTATION
#define YGGDRASIL_VISUALS_LEDCONTROLLER_IMPLEMENTATION

#include "LEDController.hpp"

namespace yggdrasil
{

inline namespace visuals
{

namespace /* utilities */
{

using LEDBuffer_T = LEDController::LEDBuffer_T;


inline uint16_t RGBElementToPWMTicks(const uint8_t element) noexcept
{
	return (element / 255.0) * 4095;
}

}

LEDController::LEDController(TwoWire& i2c) noexcept
	:	m_ledDriver{ i2c },
		m_ledBuffer{ 0, 0, 0 }
{
	//Empty.
}


void LEDController::begin(const uint8_t i2cAddress) noexcept
{
	m_ledDriver.init(i2cAddress);
}


const CRGB& LEDController::getLED(const uint8_t n) const noexcept
{
	return m_ledBuffer[n];
}

void LEDController::setLED(const uint8_t n, const CRGB& new_value) noexcept
{
	m_ledBuffer[n] = new_value;
}

const LEDBuffer_T& LEDController::getAllLEDs(void) const noexcept
{
	return m_ledBuffer;
}

void LEDController::setAllLEDs(const LEDBuffer_T& new_ledBuffer) noexcept
{
	for (uint8_t led = 0; led < LED_COUNT; led++)
	{
		m_ledBuffer[led] = new_ledBuffer[led];
	}
}


void LEDController::update(void) noexcept
{
	uint8_t current_channel = 0;

	for (auto led : m_ledBuffer)
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
