#ifndef YGGDRASIL_INTERFACE_LEDCONTROLLER_HEADER
#define YGGDRASIL_INTERFACE_LEDCONTROLLER_HEADER

#include "visuals/Color.hpp"
#include "visuals/LEDController.hpp"
using namespace yggdrasil::visuals;

extern "C"
{

LEDController* LEDController_create(int i2cAddress = LEDController::DEFAULT_ADDRESS);


int LEDController_getLED(const LEDController* instance, int n);
void LEDController_setLED(LEDController* instance, int n, int color);

float LEDController_getBrightness(const LEDController* instance);
void LEDController_setBrightness(LEDController* instance, float new_brightness);

void LEDController_update(LEDController* instance);


void LEDController_delete(LEDController* instance);

}

//Include implementation to allow inlining.
#include "interface/LEDController.cpp"

#endif
