#ifndef YGGDRASIL_VISUALS_LEDCONTROLLER_HEADER
#define YGGDRASIL_VISUALS_LEDCONTROLLER_HEADER

#include <wiringPi.h>

#include "hardware/pca9685.h"
#include "visuals/Color.hpp"

namespace yggdrasil
{

inline namespace visuals
{

class LEDController final
{

public:

	static constexpr uint8_t DEFAULT_ADDRESS = 0x40;

	static constexpr uint8_t LED_COUNT = 5;
	static constexpr float DEFAULT_BRIGHTNESS = 0.75;


	using LEDBuffer_T = Color[LED_COUNT];


	/**
	 *	LEDController Constructor
	 *
	 *	@param i2cAddress The I2C Address of the PCA9685 LED Driver. Only required when the address has been changed manually.
	 */
	LEDController(uint8_t i2cAddress = DEFAULT_ADDRESS) noexcept;

	LEDController(const LEDController&) = delete;
	LEDController(LEDController&&) = default;

	LEDController& operator=(const LEDController&) = delete;
	LEDController& operator=(LEDController&&) = default;


	const Color& getLED(uint8_t n) const noexcept;
	void setLED(uint8_t n, const Color& new_value) noexcept;

	const LEDBuffer_T& getAllLEDs(void) const noexcept;
	void setAllLEDs(const LEDBuffer_T& new_ledBuffer) noexcept;

	float getBrightness(void) const noexcept;
	void setBrightness(float new_brightness) noexcept;

	/**
	 *	Update LED display.
	 *
	 *	Writes all data from the buffer to the LED driver.
	 */
	void update(void) noexcept;


	~LEDController(void) = default;

private:

	static constexpr uint16_t PIN_BASE = 300;
	static constexpr float FREQUENCY = 200.0F;


	int m_pca9685Accessor;

	LEDBuffer_T m_ledBuffer;
	float m_brightness;

};

}

}

//Include implementation to allow inlining.
#include "LEDController.cpp"

#endif
