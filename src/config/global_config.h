/**
 * @ANZE_COPYRIGHT_START
 *
 * This file contains sensitive information that is privileged, confidential and/or exempt from
 * disclosure under applicable law. This file is the PROPRIETARY property of ANZE Engineering.
 *
 * @ANZE_COPYRIGHT_END
 *
 * @file global_config.h
 * @author Mateo Segura
 * @date 10/22/2022
 * @brief Global project configuration
 */
#pragma once

/*----------------------------------------------------------------------------------------------------------
 *                                                                                               Debug Flags
 *--------------------------------------------------------------------------------------------------------*/
#define DEBUG

// MCU
#ifdef DEBUG
#define DEBUG_BOOT
#define DEBUG_I2C
#endif // DEBUG

// External Hardware
#ifdef DEBUG
#define DEBUG_ENV_SENSOR
#endif // DEBUG

/**
 * EoF
 */