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

#pragma once

// Standard incldue
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// RTOS includes
#include "rtos.h"

// AMV includes
#include "error_no.h"
#include "global_config.h"

/*----------------------------------------------------------------------------------------------------------
 *                                                                                     Error Handling Macros
 *--------------------------------------------------------------------------------------------------------*/

/**
 * LOG() - Use like "printf" to log general information to the console
 *   DEBUG: print text to the console (semihosting or UART; configured above)
 *   RELEASE: do nothing
 */
#ifdef DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

/**
 * WARN() - log non-critical errors where a flag must be raised, but the system can continue working
 *   DEBUG: print text with file & line number to the console
 *   RELEASE: (no printf) store the error, and continue
 */

void handle_warning(const char *func, const char *file, const uint32_t line, const char *format, ...);
#define WARN(...) handle_warning(__func__, __FILE__, __LINE__, __VA_ARGS__)

/**
 * ERROR() - log critical errors where the system can no longer operate
 *   DEBUG: print error text with file and line to the console, store the error, and hang
 *   RELEASE: (no printf) store the error, and reset
 */
void handle_error(const char *func, const char *file, const uint32_t line, const char *format, ...);
#define ERROR(...) handle_error(__func__, __FILE__, __LINE__, __VA_ARGS__)

/**
 * EoF
 */