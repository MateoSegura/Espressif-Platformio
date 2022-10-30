/**
 * @ANZE_COPYRIGHT_START
 *
 * This file contains sensitive information that is privileged, confidential and/or exempt from
 * disclosure under applicable law. This file is the PROPRIETARY property of ANZE Engineering.
 *
 * @ANZE_COPYRIGHT_END
 *
 * @file error_no.h
 * @author Mateo Segura
 * @date 10/22/2022
 * @brief Error Numbers
 */

#pragma once

// FreeRTOS includes
#include "freertos/FreeRTOS.h"

/*----------------------------------------------------------------------------------------------------------
 *                                                                                             General Erros
 *--------------------------------------------------------------------------------------------------------*/
#define errUNKNOWN ((BaseType_t)-1000)
#define errINIT_FAIL ((BaseType_t)-1001)
#define errNULL_CONFIG ((BaseType_t)-1002)
#define errINVALID_INIT_PARAMS ((BaseType_t)-1003)
#define errINVALID_HARDWARE_INSTANCE ((BaseType_t)-1004)
#define errINTERFACE_NOT_SUPPORTED ((BaseType_t)-1005)

/*----------------------------------------------------------------------------------------------------------
 *                                                                               Boot Errors ( 1001 - 1101 )
 *--------------------------------------------------------------------------------------------------------*/

/**
 * EoF
 */
