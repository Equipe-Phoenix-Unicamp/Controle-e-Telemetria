/*******************************************************************************
**  DAVE App Name : NVIC002       App Version: 1.0.26               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/



/*CODE_BLOCK_BEGIN[NVIC002_Conf.h]*/
/**************************************************************************//**
 *
 * Copyright (C) 2013 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with 
 * Infineon's microcontrollers.  
 * This file can be freely distributed within development tools that are 
 * supporting such microcontrollers. 
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000/XMC1000 Series   			                  **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Oct 08, 2013                                           **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** SNR          App Developer                                                 **
*******************************************************************************/

/**
 * @file   NVIC002_Conf.h
 *
 * @App    Version NVIC002 <1.0.26>
 *
 * @brief  Configuration file generated based on UI settings 
 *         of NVIC002 App
 *
 */
/* Revision History	
 * 18  Feb 2013   v1.0.12 
 * 08  Oct 2013   v1.0.20 Updated as per coding guidelines
 */
#ifndef _NVIC002_CONF_H_
#define _NVIC002_CONF_H_

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
@Defines
****************************************************************************/
#define DEBUG_APP false
  
/* User defined function mapped to IRQ_Hdlr_16 */
#define GlobalResultEvent    IRQ_Hdlr_16 


/**
 * @ingroup NVIC002_constants
 * @{
 */
#define NVIC002_NUM_INSTANCES 1U
/**
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif  /* ifndef _NVIC002_CONF_H_ */
/*CODE_BLOCK_END*/

