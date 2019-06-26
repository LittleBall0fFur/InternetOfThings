#ifndef YGGDRASIL_WRAPPER_LEDCONTROLLER_HEADER
#define YGGDRASIL_WRAPPER_LEDCONTROLLER_HEADER

#include "visuals/Color.hpp"
#include "visuals/LEDController.hpp"

extern "C"
{

int LEDController_getLED(int n);
void LEDController_setLED(int n, int color);

float LEDController_getBrightness(void);
void LEDController_setBrightness(float new_brightness);

void LEDController_update(void);

}

//Include implementation to allow inlining.
#include "wrapper/LEDController.ipp"

#endif
