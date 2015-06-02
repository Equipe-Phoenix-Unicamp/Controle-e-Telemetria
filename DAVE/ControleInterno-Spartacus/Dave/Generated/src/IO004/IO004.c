/*******************************************************************************
**  DAVE App Name : IO004       App Version: 1.0.22               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*CODE_BLOCK_BEGIN[IO004.c]*/
/*******************************************************************************
 Copyright (c) 2012, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without**
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Mar 16, 2013                                           **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PAE        App Developer                                                   **
*******************************************************************************/
/**
 * @file   IO004.c
 *
 * @brief  IO_Digital _IO004 App
 *
 * This app can be used to configure a IO Pin when the output shall be 
 * controlled by software or when it required  just as a input I/O.IO002 App can 
 * be used in any case except when the output shall be controlled by software.			
 *
 *	Note: 
 *	The App GUI configures the Port Pin as GPIO in input mode by default.
 */
/* Revision History 
 *
 * 01 Jan 2013  v1.0.12  Disabled Pad Class & Pad driver configuration for 
 *                       XMC1000.
 * 16 Mar 2013  v1.0.14  Modified OMR register configuration (Direct assignment 
 *                       without reading) to upgrade performance.
 *
 */
/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/

/** Inclusion of header file */
#include <DAVE3.h>

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                 Function like macro definitions                            **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
/** @ingroup IO004_Func
 * @{
 */

void IO004_Init(void)
{
   /* <<<DD_IO004_API_1>>> */

	   

  /* Configuration of 1 Port 0 based on User configuration */
  IO004_Handle0.PortRegs->OMR = 0U<< 0;
  
  IO004_Handle0.PortRegs->PDR0   &= (uint32_t)(~(PORT1_PDR0_PD0_Msk));
  IO004_Handle0.PortRegs->PDR0   |= (uint32_t)((4UL << PORT1_PDR0_PD0_Pos) & \
                                          PORT1_PDR0_PD0_Msk);
  IO004_Handle0.PortRegs->IOCR0 |= (0U << 3);   

  /* Configuration of 1 Port 3 based on User configuration */
  IO004_Handle1.PortRegs->OMR = 1U<< 3;
  
  IO004_Handle1.PortRegs->PDR0   &= (uint32_t)(~(PORT1_PDR0_PD3_Msk));
  IO004_Handle1.PortRegs->PDR0   |= (uint32_t)((4UL << PORT1_PDR0_PD3_Pos) & \
                                          PORT1_PDR0_PD3_Msk);
  IO004_Handle1.PortRegs->IOCR0 |= (0U << 27);   

  /* Configuration of 2 Port 8 based on User configuration */
  IO004_Handle10.PortRegs->OMR = 0U<< 8;
  
  IO004_Handle10.PortRegs->PDR1  &= (uint32_t)(~(PORT2_PDR1_PD8_Msk));
  IO004_Handle10.PortRegs->PDR1  |= (uint32_t)((4UL << PORT2_PDR1_PD8_Pos) & \
                                     PORT2_PDR1_PD8_Msk);
  IO004_Handle10.PortRegs->IOCR8 |= (0U << 3);   

  /* Configuration of 2 Port 5 based on User configuration */
  IO004_Handle11.PortRegs->OMR = 0U<< 5;
  
  IO004_Handle11.PortRegs->PDR0   &= (uint32_t)(~(PORT2_PDR0_PD5_Msk));
  IO004_Handle11.PortRegs->PDR0   |= (uint32_t)((4UL << PORT2_PDR0_PD5_Pos) & \
                                          PORT2_PDR0_PD5_Msk);
  IO004_Handle11.PortRegs->IOCR4 |= (0U << 11);   

  /* Configuration of 2 Port 4 based on User configuration */
  IO004_Handle12.PortRegs->OMR = 0U<< 4;
  
  IO004_Handle12.PortRegs->PDR0   &= (uint32_t)(~(PORT2_PDR0_PD4_Msk));
  IO004_Handle12.PortRegs->PDR0   |= (uint32_t)((4UL << PORT2_PDR0_PD4_Pos) & \
                                          PORT2_PDR0_PD4_Msk);
  IO004_Handle12.PortRegs->IOCR4 |= (0U << 3);   

  /* Configuration of 2 Port 3 based on User configuration */
  IO004_Handle13.PortRegs->OMR = 0U<< 3;
  
  IO004_Handle13.PortRegs->PDR0   &= (uint32_t)(~(PORT2_PDR0_PD3_Msk));
  IO004_Handle13.PortRegs->PDR0   |= (uint32_t)((4UL << PORT2_PDR0_PD3_Pos) & \
                                          PORT2_PDR0_PD3_Msk);
  IO004_Handle13.PortRegs->IOCR0 |= (0U << 27);   

  /* Configuration of 2 Port 2 based on User configuration */
  IO004_Handle14.PortRegs->OMR = 0U<< 2;
  
  IO004_Handle14.PortRegs->PDR0   &= (uint32_t)(~(PORT2_PDR0_PD2_Msk));
  IO004_Handle14.PortRegs->PDR0   |= (uint32_t)((4UL << PORT2_PDR0_PD2_Pos) & \
                                          PORT2_PDR0_PD2_Msk);
  IO004_Handle14.PortRegs->IOCR0 |= (0U << 19);   

  /* Configuration of 1 Port 2 based on User configuration */
  IO004_Handle2.PortRegs->OMR = 0U<< 2;
  
  IO004_Handle2.PortRegs->PDR0   &= (uint32_t)(~(PORT1_PDR0_PD2_Msk));
  IO004_Handle2.PortRegs->PDR0   |= (uint32_t)((4UL << PORT1_PDR0_PD2_Pos) & \
                                          PORT1_PDR0_PD2_Msk);
  IO004_Handle2.PortRegs->IOCR0 |= (0U << 19);   

  /* Configuration of 5 Port 7 based on User configuration */
  IO004_Handle3.PortRegs->OMR = 0U<< 7;
  
  IO004_Handle3.PortRegs->PDR0   &= (uint32_t)(~(PORT5_PDR0_PD7_Msk));
  IO004_Handle3.PortRegs->PDR0   |= (uint32_t)((4UL << PORT5_PDR0_PD7_Pos) & \
                                          PORT5_PDR0_PD7_Msk);
  IO004_Handle3.PortRegs->IOCR4 |= (0U << 27);   

  /* Configuration of 5 Port 6 based on User configuration */
  IO004_Handle4.PortRegs->OMR = 0U<< 6;
  
  IO004_Handle4.PortRegs->PDR0   &= (uint32_t)(~(PORT5_PDR0_PD6_Msk));
  IO004_Handle4.PortRegs->PDR0   |= (uint32_t)((4UL << PORT5_PDR0_PD6_Pos) & \
                                          PORT5_PDR0_PD6_Msk);
  IO004_Handle4.PortRegs->IOCR4 |= (0U << 19);   

  /* Configuration of 5 Port 9 based on User configuration */
  IO004_Handle5.PortRegs->OMR = 0U<< 9;
  
  IO004_Handle5.PortRegs->PDR1  &= (uint32_t)(~(PORT5_PDR1_PD9_Msk));
  IO004_Handle5.PortRegs->PDR1  |= (uint32_t)((4UL << PORT5_PDR1_PD9_Pos) & \
                                     PORT5_PDR1_PD9_Msk);
  IO004_Handle5.PortRegs->IOCR8 |= (0U << 11);   

  /* Configuration of 3 Port 3 based on User configuration */
  IO004_Handle6.PortRegs->OMR = 0U<< 3;
  
  IO004_Handle6.PortRegs->PDR0   &= (uint32_t)(~(PORT3_PDR0_PD3_Msk));
  IO004_Handle6.PortRegs->PDR0   |= (uint32_t)((4UL << PORT3_PDR0_PD3_Pos) & \
                                          PORT3_PDR0_PD3_Msk);
  IO004_Handle6.PortRegs->IOCR0 |= (0U << 27);   

  /* Configuration of 1 Port 8 based on User configuration */
  IO004_Handle7.PortRegs->OMR = 0U<< 8;
  
  IO004_Handle7.PortRegs->PDR1  &= (uint32_t)(~(PORT1_PDR1_PD8_Msk));
  IO004_Handle7.PortRegs->PDR1  |= (uint32_t)((4UL << PORT1_PDR1_PD8_Pos) & \
                                     PORT1_PDR1_PD8_Msk);
  IO004_Handle7.PortRegs->IOCR8 |= (0U << 3);   

  /* Configuration of 0 Port 7 based on User configuration */
  IO004_Handle8.PortRegs->OMR = 0U<< 7;
  
  IO004_Handle8.PortRegs->PDR0   &= (uint32_t)(~(PORT0_PDR0_PD7_Msk));
  IO004_Handle8.PortRegs->PDR0   |= (uint32_t)((0UL << PORT0_PDR0_PD7_Pos) & \
                                          PORT0_PDR0_PD7_Msk);
  IO004_Handle8.PortRegs->IOCR4 |= (0U << 27);   

  /* Configuration of 5 Port 8 based on User configuration */
  IO004_Handle9.PortRegs->OMR = 0U<< 8;
  
  IO004_Handle9.PortRegs->PDR1  &= (uint32_t)(~(PORT5_PDR1_PD8_Msk));
  IO004_Handle9.PortRegs->PDR1  |= (uint32_t)((4UL << PORT5_PDR1_PD8_Pos) & \
                                     PORT5_PDR1_PD8_Msk);
  IO004_Handle9.PortRegs->IOCR8 |= (0U << 3);
}

void IO004_DisableOutputDriver(const IO004_HandleType* Handle,IO004_InputModeType Mode)
{
  uint8_t Pin = Handle->PortPin;
  /* <<<DD_IO004_API_2>>> */
  if(Pin < 4U)
  {
    Handle->PortRegs->IOCR0  =  (uint32_t)(Handle->PortRegs->IOCR0 & ~(0x0000001FUL << (3U+(Pin*8U))));
    Handle->PortRegs->IOCR0 |= (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));
  } else if ((Pin >= 4U) && (Pin <= 7U))
  {
    Pin = Pin - 4U;
    Handle->PortRegs->IOCR4  =  (uint32_t)(Handle->PortRegs->IOCR4 & ~(0x0000001FUL << (3U+(Pin*8U))));
    Handle->PortRegs->IOCR4 |=  (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));
  } else if ((Pin >= 8U) && (Pin <= 11U))
  {
    Pin = Pin - 8U;
    Handle->PortRegs->IOCR8  =  (uint32_t)(Handle->PortRegs->IOCR8 & ~(0x0000001FUL << (3U+(Pin*8U))));
    Handle->PortRegs->IOCR8 |=  (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));
  } else if ((Pin >= 12U) && (Pin <= 15U))
  {
    Pin = Pin - 12U;
    Handle->PortRegs->IOCR12  =  (uint32_t)(Handle->PortRegs->IOCR12 & ~(0x0000001FUL << (3U+(Pin*8U))));
    Handle->PortRegs->IOCR12 |=  (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));
  }
  else
  {
	  /*Not supposed to be here */
  }

}

void IO004_EnableOutputDriver(const IO004_HandleType* Handle,IO004_OutputModeType Mode)
{

  uint8_t Pin = Handle->PortPin;
  /* <<<DD_IO004_API_2>>> */
  if(Pin < 4U)
  {
    Handle->PortRegs->IOCR0  =  (uint32_t)(Handle->PortRegs->IOCR0 & ~(0x0000001FUL << (3U+(Pin*8U))));
    Handle->PortRegs->IOCR0 |=  (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));
  } else if ((Pin >= 4U) && (Pin <= 7U))
  {
    Pin = Pin - 4U;
    Handle->PortRegs->IOCR4  =  (uint32_t)(Handle->PortRegs->IOCR4 & ~(0x0000001FUL << (3U+(Pin*8U))));
    Handle->PortRegs->IOCR4 |=  (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));
  } else if ((Pin >= 8U) && (Pin <= 11U))
  {
    Pin = Pin - 8U;
    Handle->PortRegs->IOCR8  =  (uint32_t)(Handle->PortRegs->IOCR8 & ~(0x0000001FUL << (3U+(Pin*8U))));
    Handle->PortRegs->IOCR8 |=  (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));
  } else if ((Pin >= 12U) && (Pin <= 15U))
  {
    Pin = Pin - 12U;
    Handle->PortRegs->IOCR12  =  (uint32_t)(Handle->PortRegs->IOCR12 & ~(0x0000001FUL << (3U+(Pin*8U))));
    Handle->PortRegs->IOCR12 |=  (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));
  }
  else
  {
	  /*Not supposed to be here */
  }
}

/**
*@}
*/	

/*CODE_BLOCK_END*/


