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

template<typename T>
inline T clamp(const T& value, const T& min, const T& max)
{
	return (value < min) ? min :
	       (value > max) ? max : value;
}

}

LEDController::LEDController(const uint8_t i2cAddress) noexcept
	:	m_ledBuffer{},
		m_brightness{ DEFAULT_BRIGHTNESS }
{
	//Ensure WiringPi is setup.
	wiringPiSetup();

	m_pca9685FileDescriptor = pca9685Setup(PIN_BASE, i2cAddress, FREQUENCY);

	//Ensure LED's are off.
	pca9685PWMReset(m_pca9685FileDescriptor);
}


const Color& LEDController::getLED(const uint8_t n) const noexcept
{
	return m_ledBuffer[n];
}

void LEDController::setLED(const uint8_t n, const Color& new_value) noexcept
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

float LEDController::getBrightness(void) const noexcept
{
	return m_brightness;
}

void LEDController::setBrightness(const float new_brightness) noexcept
{
	m_brightness = clamp(new_brightness, 0.0F, 1.0F);
}

void LEDController::update(void) noexcept
{
	uint8_t current_channel = 0;

	for (auto led : m_ledBuffer)
	{
		for (auto element : led.raw)
		{
			pca9685PWMWrite(m_pca9685FileDescriptor, current_channel++, 0, RGBElementToPWMTicks(element) * m_brightness);
		}
	}
}

}

}

#endif
