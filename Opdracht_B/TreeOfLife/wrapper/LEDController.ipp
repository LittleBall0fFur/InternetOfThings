#ifndef YGGDRASIL_WRAPPER_LEDCONTROLLER_IMPLEMENTATION
#define YGGDRASIL_WRAPPER_LEDCONTROLLER_IMPLEMENTATION

#include "wrapper/LEDController.hpp"

namespace /* IMPLEMENTATION DETAILS */
{

LEDController ledController{};

}

int LEDController_getLED(int n)
{
	return static_cast<uint32_t>(ledController.getLED(n));
}

void LEDController_setLED(int n, int color)
{
	ledController.setLED(n, Color{ color });
}

float LEDController_getBrightness(void)
{
	return ledController.getBrightness();
}

void LEDController_setBrightness(float new_brightness)
{
	ledController.setBrightness(new_brightness);
}

void LEDController_update(void)
{
	ledController.update();
}

#endif
