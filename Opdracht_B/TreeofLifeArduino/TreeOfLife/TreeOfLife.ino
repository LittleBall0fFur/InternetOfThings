#include "visuals/LEDController.hpp"
using namespace yggdrasil;

LEDController controller{};

void setup(void) noexcept
{
  Wire.begin();
  Wire.setClock(400000);
  controller.begin();
}

void loop(void) noexcept
{
  for (uint8_t led = 0; led < LEDController::LED_COUNT; led++)
  {
    controller.setLED(led, CRGB{ 64, 0, 0 }); //turn LED red.
  }

  controller.update(); //push buffer to LED Driver.

  delay(5000);
}
