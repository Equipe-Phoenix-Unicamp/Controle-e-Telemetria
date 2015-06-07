/******************************************************************************
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
** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : September 27, 2013                                     **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PAE        App Developer                                                   **
*******************************************************************************/
/**
 * @file WDT001.h
 *
 * @brief  Header file for WatchDog Timer (WDT001) App.
 *
 */
/* Revision History
 * 09 Jan 2013 v1.0.6   Base Version for porting
 * 27 Sep 2013 v1.0.12  C++ support added
 */
 #ifndef WDT001_H_
 #define WDT001_H_
/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include <DAVE3.h>
/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/
/**
 * @ingroup WDT001_publicparam
 * @{
 */
/**
 * This data type to describe the possible status values returned
 *        by APIs of the App.
 */
typedef enum WDT001_StatusType
{
  /**
  * @cond INTERNAL_DOCS
  * @param MODULENAME WDT001
  * @endcond
  */
  /**
  * Debuglog Function Entry
  */
  /**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING1 WDT001_FUN_ENTRY
  * @param STRCODESTRING1 Entered function \%s
  * @endcond
  */
  WDT001_FUN_ENTRY = 1,
  /**
  *  Debuglog Function Exit
  */
  /**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING2 WDT001_FUN_EXIT
  * @param STRCODESTRING2 Exited function \%s
  * @endcond
  */
  WDT001_FUN_EXIT
  /*
  ERRORCODEEND
  */
}WDT001_StatusType;
/**
 * @}
 */
/******************************************************************************
** FUNCTION PROTOTYPES                                                       **
******************************************************************************/
/**
 * @ingroup WDT001_apidoc
 * @{
 */

/**
 * @brief    Function initializes the App based on the UI configurable items.
 *
 *
 * @return  NONE
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *  #include <DAVE3.h>
 *  int main(void)
 *  {
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init(); // WDT001_Init() is called within DAVE_Init()
 *    // ... Use code needs to be added here
 *    while(1)
 *    {
 *    
 *    }
 *     
 *  }
 * @endcode<BR> </p>
 *
 */
void WDT001_Init(void);

/**
 *@}
 */

/**
 * @ingroup WDT001_apidoc
 * @{
 */

/**
 * @brief   Macro to disable the WDT module
 *
 *
 * @return     NONE
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *  #include <DAVE3.h>
 * 
 *  int main(void)
 *  {
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init();
 *    WDT001_Enable();
 *    //...
  *   WDT001_Disable();
 *  }
 * @endcode<BR> </p>
 *
 */
#define  WDT001_Disable()  (WDT->CTR &= ~((uint32_t)1 << WDT_CTR_ENB_Pos))

/**
 * @brief      Macro enables the WDT Module.
 *
 * @return     NONE
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *  #include <DAVE3.h>
 * 
 *  int main(void)
 *  {
 *    //Initializes Apps configurations ...
 *    DAVE_Init();
 *    WDT001_Enable();
 *    //...
  *   WDT001_Disable();
 *  }
 * @endcode<BR> </p>
 *
 */

#define  WDT001_Enable()  (WDT->CTR |= (uint32_t)1 << WDT_CTR_ENB_Pos)

/**
 * @brief      Macro services the WDT module, by writing the
 *             magic word which results in  a reload of the timer
 *
 *
 * @param[in]  MagicWord
 *
 * @return     NONE
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *  #include <DAVE3.h>
 * 
 *  int main(void)
 *  {
 *    uint32_t MagicWord = 0xABADCAFE;	
 *    //Initializes Apps configurations ...
 *    DAVE_Init();
 *    WDT001_Enable();
 *    //...
 *    WDT001_Service(MagicWord);
 *  }
 * @endcode<BR> </p>
 *
 */
#define WDT001_Service(MagicWord)  (WDT->SRV = MagicWord)

/**
 * @brief   Macro to clear pre-warning alarm status flag
 *
 * @return     NONE
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *  #include <DAVE3.h>
 * 
 *  int main(void)
 *  {
 *    uint32_t MagicWord = 0xABADCAFE;	
 *    // Initializes Apps configurations ...
 *    DAVE_Init();
 *    WDT001_Enable();
 *    //...
 *    WDT001_ClrTimeOutFlag();
 *  }
 * @endcode<BR> </p>
 *
 */
#define WDT001_ClrTimeOutFlag()   (WDT->WDTCLR = WDT_WDTCLR_ALMC_Msk)

/**
 * @brief    Macro to read Pre-Alarm Status flag
 *
 *
 * @return    Register Value
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *  #include <DAVE3.h>
 * 
 *  int main(void)
 *  {
 *    bool Flag = FALSE;	
 *    // Initializes Apps configurations ...
 *    DAVE_Init();
 *    WDT001_Enable();
 *    //...
 *    Flag =  WDT001_ReadAlarmFlag();
 *  }
 * @endcode<BR> </p>
 *
 */
#define   WDT001_ReadAlarmFlag()  (WDT->WDTSTS)


/**
 * @brief  Macro to read actual value of watchdog timer
 *
 *
 * @return     uint32_t ( current value of WDT timer )
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *  #include <DAVE3.h>
 * 
 *  int main(void)
 *  {
 *    uint32_t TimerCount = 0;	
 *    //Initializes Apps configurations ...
 *    DAVE_Init();
 *    WDT001_Enable();
 *    //...
 *    TimerCount = WDT001_GetTimer();
 *  }
 * @endcode<BR> </p>
 *
 */
#define WDT001_GetTimer()        (WDT->TIM)

/**
 *@}
 */
#ifdef __cplusplus
}
#endif

#endif /* WDT001_H_ */

