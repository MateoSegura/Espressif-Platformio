#include "global_config.h"
#include "error_handler.h"

// FreeRTOS includes
#include "rtos.h"

// MCAL includes
#include "i2c.h"

void app_main()
{
  static I2C_ConfigType i2cConfig = {
      .pinSda = 0,
      .pinScl = 1,
  };
  BaseType_t status = I2C_Init(0, &i2cConfig);

  if (status != pdTRUE)
    ERROR("Tu mama we\n");

  while (true)
  {
    LOG("Hello world\n");
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}