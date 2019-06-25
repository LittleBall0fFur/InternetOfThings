#ifndef YGGDRASIL_VISUALS_LEDCONTROLLER_HEADER
#define YGGDRASIL_VISUALS_LEDCONTROLLER_HEADER

/* INTERNAL ARDUINO LIBRARIES */
#include <Arduino.h>
#include <Wire.h>

/* EXTERMAL ARDUINO LIBRARIES */
#include <FastLED.h>
#include <PCA9685.h>

namespace yggdrasil
{

inline namespace visuals
{

class LEDController final
{

public:

	static constexpr uint8_t LED_COUNT = 5;


	using LEDBuffer_T = CRGB[LED_COUNT];


	/**
	 *	LEDController Constructor
	 *
	 *	@param i2c The 'TwoWire' instance through which the class communicates with the LED Driver. Can be omitted, unless a specific 'TwoWire' instance has to be used.
	 */
	LEDController(TwoWire& i2c = Wire) noexcept;

	LEDController(const LEDController&) = delete;
	LEDController(LEDController&&) = default;

	LEDController& operator=(const LEDController&) = delete;
	LEDController& operator=(LEDController&&) = default;


	/**
	 *	Start hardware communication.
	 *
	 *	This function must be called within the Arduino 'setup' function, directly or indirectly (e.g. by a function called from within 'setup').
	 *
	 *	@param i2cAddress The I2C address of the LED driver.
	 */
	void begin(uint8_t i2cAddress = 0) noexcept;

	const CRGB& getLED(uint8_t n) const noexcept;
	void setLED(uint8_t n, const CRGB& new_value) noexcept;

	const LEDBuffer_T& getAllLEDs(void) const noexcept;
	void setAllLEDs(const LEDBuffer_T& new_ledBuffer) noexcept;

	/**
	 *	Update LED display.
	 *
	 *	Writes all data from the buffer to the LED driver.
	 */
	void update(void) noexcept;


	~LEDController(void) = default;

private:

	PCA9685 m_ledDriver;
	LEDBuffer_T m_ledBuffer;

};

}

}

//Include implementation to allow inlining.
#include "LEDController.cpp"

#endif
