// TODO: Fix freertos include folder

// FreeRTOS includes
#include "freertos/FreeRTOS.h"
#include "error_handler.h"

void app_main()
{
  while (true)
  {
    LOG("Hello world\n");
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}