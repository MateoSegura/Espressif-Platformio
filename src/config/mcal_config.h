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
 *                                                                                                 Platforms
 *--------------------------------------------------------------------------------------------------------*/
#define MCAL_PLATFORM_TEMPLATE 0
#define MCAL_PLATFORM_ESPRESSIF 1
#define MCAL_PLATFORM_IMXRT1050 2

#define MCAL_PLATFORM_ID_CONFIG MCAL_PLATFORM_TEMPLATE // <----- Change to the correct platform

/*----------------------------------------------------------------------------------------------------------
 *                                                                                                   Version
 *--------------------------------------------------------------------------------------------------------*/
#define MCAL_SW_MAJOR_VERSION 1
#define MCAL_SW_MINOR_VERSION 0
#define MCAL_SW_PATCH_VERSION 0

/*----------------------------------------------------------------------------------------------------------
 *                                                                                               Debug Flags
 *--------------------------------------------------------------------------------------------------------*/
#define MCAL_UART_DEBUG
#define MCAL_I2C_DEBUG
#define MCAL_SPI_DEBUG

/*----------------------------------------------------------------------------------------------------------
 *                                                                                                       I2C
 *--------------------------------------------------------------------------------------------------------*/

/**
 * EoF
 */