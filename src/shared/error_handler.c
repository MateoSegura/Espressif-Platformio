/**
 * @ANZE_COPYRIGHT_START
 *
 * This file contains sensitive information that is privileged, confidential and/or exempt from
 * disclosure under applicable law. This file is the PROPRIETARY property of ANZE Engineering.
 *
 * @ANZE_COPYRIGHT_END
 *
 * @file error_handler.h
 * @author Mateo Segura
 * @date 09/08/2022
 * @brief Error Handling Macros
 */

#include "error_handler.h"

// Standard incldue
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

// RTOS includes
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// ANZE includes
#include "global_config.h"

/*------------------------------------------------------------------------------------------------
 *                                                                                        Main App
 *----------------------------------------------------------------------------------------------*/

/**
 * @brief Handle the warn macro
 *
 * @param file Source file name where warn was called
 * @param line Source file line number where warn was called
 * @param format String describing the error
 * @param ... variable arguments for format expansion (like printf)
 *
 * Log non-critical errors where a flag must be raised, but system can continue working
 *   DEBUG: print text with file & line number to the console
 *   RELEASE: (no printf) store the error, but continue operation
 */
void handle_warning(const char *func, const char *file, const uint32_t line, const char *format, ...)
{
    va_list args;

    // using static to reduce stack usage
    static char warnText[128];

    // Expand error text
    va_start(args, format);
    vsnprintf(warnText, sizeof(warnText), format, args);
    warnText[sizeof(warnText) - 1] = '\0';
    va_end(args);

    LOG("%s:%u:%s WARN: %s\n", file, line, func, warnText);
}

/**
 * @brief Handle the ERROR macro
 *
 * @param file Source file name where ERROR was called
 * @param line Source file line number where ERROR was called
 * @param format String describing the error
 * @param ... variable arguments for format expansion (like printf)
 *
 * Disable interrupts, log some info, write to flash, and proceed to _lastSteps()
 */
void handle_error(const char *func, const char *file, const uint32_t line, const char *format, ...)
{
    va_list args;

    // using static to reduce stack usage
    static char errorText[128];

    // Expand error text
    va_start(args, format);
    vsnprintf(errorText, sizeof(errorText), format, args);
    errorText[sizeof(errorText) - 1] = '\0';
    va_end(args);

    LOG("\n%s:%u:%s ERROR: %s\n", file, line, func, errorText);

#ifdef DEBUG
    // Simply halt the application
    if (xTaskGetSchedulerState() == taskSCHEDULER_RUNNING)
    {
        vTaskSuspendAll();
        while (true)
            ;
    }
#else
    LOG("Reboot...\n\n");
    esp_restart();
#endif
}

/**
 * EoF
 */