#ifndef YGGDRASIL_INTERFACE_LEDCONTROLLER_IMPLEMENTATION
#define YGGDRASIL_INTERFACE_LEDCONTROLLER_IMPLEMENTATION

#include "interface/LEDController.hpp"

LEDController* LEDController_create(const int i2cAddress)
{
	return new LEDController{ i2cAddress };
}


int LEDController_getLED(const LEDController* instance, int n)
{
	return static_cast<uint32_t>(instance->getLED(n));
}

void LEDController_setLED(LEDController* instance, int n, int color)
{
	instance->setLED(n, Color{ color });
}

float LEDController_getBrightness(const LEDController* instance)
{
	return instance->getBrightness();
}

void LEDController_setBrightness(LEDController* instance, float new_brightness)
{
	instance->setBrightness(new_brightness);
}

void LEDController_update(LEDController* instance)
{
	instance->update();
}


void LEDController_delete(LEDController* instance)
{
	delete instance;
}

#endif
