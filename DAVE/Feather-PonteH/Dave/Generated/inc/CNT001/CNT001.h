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
** AUTHOR   : DAVE App Developer                                              **
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
** SK           DAVE App Developer                                            **
** ---------------------------------------------------------------------------**
**                                                                            **
*******************************************************************************/

/**
 * @file CNT001.h
 *
 * @brief This header file contains the data structures and function prototypes of
 * CCU4_EventCounter_CNT001 App
 */

/* Revision History
 * 01 Nov 2012	 v1.0.12   taken as base version														     
 * 10 Dec 2012   v1.0.14   DBG002 Macros are added
 * 27 Sep 2013   v1.0.20   Added C++ support
 */
#ifndef EVTCOUNTER_H_
#define EVTCOUNTER_H_

/*****************************************************************************
 * INCLUDE FILES
 *****************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include <DAVE3.h>

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/** Macro to define the maximum event count value*/
#define CNT001_EVENT_COUNT_MAX                    (0xFFFFU)

/** Macro to define Timer Shadow Period Value in PRS register */
/*<<<DD_CNT001_MACRO_4>>>*/
#define CNT001_MAX_EVENTS                        (0xFFFFU)

/** Macro to clear all the Interrupts in the SWR register of CCU4x */
/*<<<DD_CNT001_MACRO_2>>>*/
#define CNT001_ALL_CCU4_INTR_CLEAR               (0x00000F0FU)

/** Macro to reset the Input Selector Register in both CCU4    */
#define CNT001_CCUx_INS_RESET                    (0xFFFF0000U)

/** Macro to reset the Connection Matrix Control in both CCU4    */
#define CNT001_CCUx_CMC_RESET                    (0x00000000U)

/** Macro to Clear TCCLR Register in CCU4   */
#define CNT001_CCU4_TCCLR_CLEAR                   (0x00000007U)

/** Macro to Clear TC Register in CCU4  */
#define CNT001_CCUx_TC_RESET                       (0x00000000U)

/** Macro to reset CRS Register in CCU4 */
#define CNT001_CCUx_CRS_RESET                     (0x00000000U)

/** Macro to reset PRS Register in CCU4 */
#define CNT001_CCUx_PRS_RESET                     (0x00000000U)

/** Macro to reset Interrupt Enable Register in CCU4 */
#define CNT001_CCUx_INTE_RESET                     (0x00000000U)

/** Macro to clear the timer */
#define CNT001_CLEAR_COUNTER          (0x02U)

#define CNT001_EDGE_ALIGNED_MODE        (0x00U)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/**
 * @ingroup CNT001_publicparam
 * @{
 */
/*******************************************************************************
 *                                ENUMERATIONS                                **
 ******************************************************************************/
/**
 * This enumerates the state of the App.
 */
typedef enum CNT001_StateType
{
  /**
   * This is the Default state of an APP after power on reset.
   */
  CNT001_UNINITIALIZED,
  /**
   * This is the INITIALIZED state in which APP is initialized as per selected
   * parameters.
   */
  CNT001_INITIALIZED,
  /**
   * This state indicates that CCU4_CCy or CCU8_CCY slice is running in count 
   * mode.
   */
  CNT001_RUNNING
}CNT001_StateType;


/**
 * This will enumerate the error codes which will be returned from a function.
 */
typedef enum CNT001_ErrorCodesType
{
  /**
   * This code would be returned when any operation is not possible cause that
   * operation was tried in invalid state
   */
  /**
   * @cond INTERNAL_DOCS
   * @param MODULENAME CNT001
   * @endcond
   */

    /**
     * @cond INTERNAL_DOCS
     * @param ERRCODESTRING CNT001_OPER_NOT_ALLOWED_ERROR
     * @param STRCODESTRING Function execution is not allowed in the current state
     * @endcond
     **/
  CNT001_OPER_NOT_ALLOWED_ERROR = 1,
  /**
   * This code is returned when parameter passed to API are invalid
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING CNT001_INVALID_PARAM_ERROR
   * @param STRCODESTRING Input parameter is not valid
   * @endcond
  */ 
  CNT001_INVALID_PARAM_ERROR,
  /**
   * This code is returned when number of events exceed 4294967295 (32-bit).
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING CNT001_OUT_OF_RANGE_ERROR
   * @param STRCODESTRING number of events exceed 4294967295 (32-bit)
   * @endcond
   */
  CNT001_OUT_OF_RANGE_ERROR,

  /** Debug log messages */
  /**
   * Message Id for function Entry
   */
  /*
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING CNT001_FUN_ENTRY
   * @param STRCODESTRING Entered Function %s
   * @endcond
  */ 
  CNT001_FUNCTION_ENTRY,
  /**
   * Message ID for function exit
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING CNT001_FUN_EXIT
   * @param STRCODESTRING Exited Function %s
   * @endcond
  */ 
  CNT001_FUNCTION_EXIT,
}CNT001_ErrorCodesType;

/**
 * This enumerates the CCUx peripheral used by this APP.
 */
typedef enum CNT001_CCUInUseType
{
  /**
   * This is slice 0 of CCU40 module
   */
  CNT001_SLICE0,
  /**
   * This is slice 1 of CCU40 module
   */
  CNT001_SLICE1,
  /**
   * This is slice 2 of CCU40 module
   */
  CNT001_SLICE2,
  /**
   * This is slice 3 of CCU40 module
   */
  CNT001_SLICE3,
}CNT001_CCUInUseType;

typedef enum CNT001_EventNameType
{
  /**
   * This is the period match interrupt
   */
  CNT001_ROLLOVEREVENT = 0,
  /**
   * This is the Compare match interrupt
   */
  CNT001_CountMatchEvent = 2,
  /**
   * This is the event for configured input edge detection. Event 0 interrupt
   */
  CNT001_InputEventEdge = 8, 
  /**
   * This is the event for gating signal. Event 1 interrupt
   */
  CNT001_GatingEvent = 9, 

}CNT001_EventNameType;

/**
* This enumerates the gating level
*/
typedef enum CNT001_GatingLevelType
{
  /**
   * Gating functionality is active on high level
   */
  CNT001_ACTIVEHIGH,
  /**
   * Gating functionality is active on low level
   */
  CNT001_ACTIVELOW
}CNT001_GatingLevelType;

/**
* This enumerates the event number used by different functions 
*/
typedef enum CNT001_EventType
{
/*<<<DD_CNT001_MACRO_5>>>*/
/**Event0 of the CCU*/
  CNT001_EVENT0=1,
/**Event1 of the CCU*/
  CNT001_EVENT1,
/** Event2 of the CCU */
  CNT001_EVENT2
}CNT001_EventType;

/**
 * This enumerates the Triggering egde on which events to be counted.
 */
typedef enum CNT001_CountingEdgeType{
    /**
     * Counting on rising edge
     */
    CNT001_RISINGEDGE = 1,
    /**
     * Counting on falling edge
     */
    CNT001_FALLINGEDGE,
    /**
     * Counting on both edges
     */
    CNT001_BOTHEDGES
}CNT001_CountingEdgeType;

/**
 * This structure holds the parameters which change at run time.
 */
typedef struct CNT001_DynamicDataType
{
/**
 * This is the number of events.
 */
uint32_t EvtCounterValue;
/**
 * This is the modified event counter match value.
 */
uint32_t NewCountMatch;
/**
 * This enumerates the state of the App.
 */
CNT001_StateType State;

}CNT001_DynamicDataType;

/**
 * This structure holds all the static configuration parameters of the Event
 * Counter APP.
 */
typedef struct CNT001_HandleType
{
/**
 * This is the event edge - Rising edge, Falling edge or both edges.
 */
CNT001_CountingEdgeType CountingEventEdge;
/**
 * This is event counter match value. This is the Compare register value.
 */
const uint32_t CountMatch;
/**
 * This tells whether external gating signal is required or not
 */
const uint8_t ExternalGatingSignal;
/**
 * This will indicate the active level of the external gating signal.
 */
const CNT001_GatingLevelType GatingLevel;
/**
 * This is the low pass filter setting for external signal.
 */
const uint8_t Lpf;
/**
 * This enumerates the CCUx peripheral used by this APP.
 */
CNT001_CCUInUseType CCUInUse;
/**
 * This is the pointer to the structure which holds the parameters which change
 * at run time.
 */
CNT001_DynamicDataType * DynamicHandlePtr;
/**
 * This is the pointer to the CCU4 Kernel Registers.
 */
CCU4_GLOBAL_TypeDef* CC4KernalPtr;
/**
 * This is the pointer to the CCU4 Slice Registers.
 */
CCU4_CC4_TypeDef* CC4Ptr;
/**
 * This decides whether to start the app after initialization
 */
const uint8_t StartControl;
/**
 * This decides whether to enable interrupts at initialization time. This 
 * stores the information in a format of 32-bit register (INTE) with a 
 * bit-field for each interrupt.
 */
const uint32_t InterruptControl;
}CNT001_HandleType;


/**
 * @}
 */
/**
 * @ingroup CNT001_apidoc
 * @{
 */
/*******************************************************************************
** FUNCTION PROTOTYPES                                                        **
*******************************************************************************/

/**
 * This function initializes the CCU4_CCy slice with the configured
 * parameters to count the number of events. <BR>
 *
 * @return None <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 *   @code
 *   #include <DAVE3.h>
 * int main(void)
 * {
 *    DAVE_Init(); //CNT001_Init is called within DAVE_Init
 *    return 0;
 * }
 @endcode
 */
void CNT001_Init(void);

/**
 * This function will reset the App.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful.<BR><BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
  @code
  *   #include <DAVE3.h>
  * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//CNT001_Init is called within DAVE_Init
 *    ...
 *    //Call the deinit function to reset the app to default values.
 *    Status = CNT001_Deinit((CNT001_HandleType*)&CNT001_Handle0);
 *    return 0;
 * }
 @endcode
 */
status_t CNT001_Deinit(const CNT001_HandleType* HandlePtr);

/**
 * This function will start this APP which will start the CCU4_CCy slice.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful
 * CNT001_OPER_NOT_ALLOWED: If the function is called in
 * CNT001_UNINTIALIZED State.<BR><BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
   @code
 * #include <DAVE3.h>  
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init(); //CNT001_Init is called within DAVE_Init
 *    //This will be called by Init() if "Start after initialization" checkbox
 *    is checked.
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0); 
 *    ...
 *    return 0;
 * }
 @endcode
 */
status_t CNT001_Start(const CNT001_HandleType* HandlePtr);

/**
 * This function will stop this APP which will stop the CCU4_CCy slice.This
 * function does not disable the interrupts. It's user's responsibility to 
 * Disable the Interrupts.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful
 * CNT001_OPER_NOT_ALLOWED: If the function is called when not in
 * CNT001_RUNNING State.<BR><BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init(); //CNT001_Init is called withinh DAVE_Init
 *    //This will be called by Init() if "Start after initialization" checkbox 
 *    is checked.
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0); 
 *    Status = CNT001_Stop((CNT001_HandleType*)&CNT001_Handle0);
 *    return 0; 
 * }
 @endcode
 */
status_t CNT001_Stop(const CNT001_HandleType* HandlePtr);

/**
 * This function will return the timer value which is the number of events
 * captured till now.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[out] NumEvents Event count match value<BR>
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful
 * CNT001_OPER_NOT_ALLOWED: If the function is called when in
 * CNT001_UNINITIALIZED State.<BR><BR>
 *
 * <b>Reentrant: yes</b><BR><BR>
 * <b>Sync/Async:  Synchronous</b>
 
  * @code
  * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();
 *    //Clear and Enable compare match event if it is not initialized "Enable 
 *    at initialization" checkbox is not checked.
 *     //CNT001_ClearPendingEvent((CNT001_HandleType*)&CNT001_Handle0,\
 *     CNT001_CountMatchEvent);
 *     //CNT001_EnableEvent((CNT001_HandleType*)&CNT001_Handle0,\
 *     CNT001_CountMatchEvent);

 *    //Start the app if "Start after initialization" checkbox is not checked.
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0);
 *    while(1);
 *    return Status;
 * }
 * //This is the compare match interrupt handler called from the NVIC.
 * //This app reads the event counter value when compare match interrupt comes
 *
 * void CNT001_InterruptHandler()
 * {
 *    uint8_t EvtStatus = 0;
 *    uint32_t CountVal;
 *    status_t Status;
 *
 *    //Check if compare match interrupt
 *    Status = CNT001_GetPendingEvent((CNT001_HandleType*)&CNT001_Handle0, \
 *    CNT001_CountMatchEvent, &EvtStatus);
      if(EvtStatus == (uint8_t)SET)
      {
         Status = CNT001_GetEvtCountValue((CNT001_HandleType*)&CNT001_Handle0,\
          &CountVal);
         CNT001_ClearPendingEvent((CNT001_HandleType*)&CNT001_Handle0, \
         CNT001_CountMatchEvent);
         CNT001_ResetCounter((CNT001_HandleType*)&CNT001_Handle0);
      }
  }
*
 @endcode
 */
status_t CNT001_GetEvtCountValue(const CNT001_HandleType* HandlePtr, \
    uint32_t* NumEvents);

/**
 * This function will read the compare register value of the timer slice.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[out] CompRegVal event count match value<BR>
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful
 * CNT001_OPER_NOT_ALLOWED: If the function is called when in
 * CNT001_UNINITIALIZED State.<BR><BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    uint32_t CountComp = 0;
 *    status_t Status;
 *    DAVE_Init();
 *    //Start the app
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0);
 *    //Read the count match
 *    Status = CNT001_GetCountMatch((CNT001_HandleType*)&CNT001_Handle0,\
 *     &CountComp);
 *    while(1);
 *    return Status;
 * }
 @endcode
 */
status_t CNT001_GetCountMatch(const CNT001_HandleType* HandlePtr, \
    uint32_t* CompRegVal);

/**
 * This function will modify the compare value of the timer. Event counter is
 * compared with this value.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[in] CountMatch event count match value<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful
 * CNT001_OPER_NOT_ALLOWED: If the function is called when in
 * CNT001_UNINITIALIZED State.
 * CNT001_OUT_OF_RANGE: if the count value is above 2^16-1<BR><BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    uint32_t CountComp = 10000;
 *    status_t Status;
 *    //Start the app
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0);
 *    //Set the count match to generate the compare match interrupt
 *    Status = CNT001_SetCountMatch((CNT001_HandleType*)&CNT001_Handle0, \
 *    CountComp);
 *    return Status;
 * }
 @endcode
 */
status_t CNT001_SetCountMatch(const CNT001_HandleType* HandlePtr, \
    uint32_t CountMatch);

/**
 * This function will read the timer status - Running or Idle.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[out] Status state of the timer value<BR>
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful
 * CNT001_OPER_NOT_ALLOWED: If the function is called when in
 * CNT001_UNINITIALIZED State.<BR><BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint32_t TimerStatus;
 *    //Start the app
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0);
 *    //Read the timer status
 *    Status = CNT001_GetTimerStatus((CNT001_HandleType*)&CNT001_Handle0, \
*     &TimerStatus);
 *    if(TimerStatus == (uint8_t)SET)
 *    {
 *      //timer is running
 *    }
 *    return Status;
 * }
 @endcode
 */
status_t CNT001_GetTimerStatus(const CNT001_HandleType* HandlePtr, \
    uint32_t* Status);

/**
 * @brief This function will enable the event. This should be called by the 
 * user first for interrupt handling.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [in] Event Event to be enabled <BR>
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CNT001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CNT001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    uint32_t Count = 0;
 *    status_t Status;
 *    DAVE_Init();
 *    //Enable compare match event if it is not initialized "Enable at 
 *    initialization" checkbox is not checked.
 *    CNT001_EnableEvent((CNT001_HandleType*)&CNT001_Handle0, \
 *    CNT001_CountMatchEvent);

 *    //Start the app if "Start after initialization" checkbox is not checked.
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0);
 *    while(1);
 *    return Status;
 * }
 *  @endcode
 */
status_t CNT001_EnableEvent
(
     const CNT001_HandleType * HandlePtr,
     const CNT001_EventNameType Event
);

/**
 * @brief This function will disable the event.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [in] Event Event to be disabled <BR>
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CNT001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CNT001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    uint32_t Count = 0;
 *    status_t Status;
 *    DAVE_Init();
 *    //Disable compare match event 
 *    CNT001_DisableEvent((CNT001_HandleType*)&CNT001_Handle0, \
 *    CNT001_CountMatchEvent);

 *    //Start the app if "Start after initialization" checkbox is not checked.
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0);
 *    while(1);
 *    return Status;
 * }
 *  @endcode
 */
status_t CNT001_DisableEvent
(
    const CNT001_HandleType * HandlePtr,
    const CNT001_EventNameType Event
);

/**
 * @brief This function will clear the pending event. After servicing the 
 * interrupt this function should be called to clear the pending bit.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [in] Event Event to be cleared <BR>
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CNT001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CNT001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    uint32_t Count = 0;
 *    status_t Status;
 *    DAVE_Init();
 *    //Start the app if "Start after initialization" checkbox is not checked.
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0);
 *    while(1);
 *    return Status;
 * }
 * //This is the count match interrupt handler called from the NVIC.
 * //This app reads the event counter value when compare match interrupt comes
 *
 * void CNT001_InterruptHandler()
*  {
*     status_t Status;
*     Status = CNT001_ClearPendingEvent((CNT001_HandleType*)&CNT001_Handle0,\
*     CNT001_CountMatchEvent);
*  }
*   @endcode
 */
status_t CNT001_ClearPendingEvent
(
    const CNT001_HandleType * HandlePtr,
    const CNT001_EventNameType Event
);

/**
 * @brief This function will set the event by software. This should not be
 * called from interrupt routine as it will result in the infinite loop.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [in] Event Event to be set <BR>
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CNT001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CNT001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    uint32_t Count = 0;
 *    status_t Status;
 *    DAVE_Init();
 *    //Start the app if "Start after initialization" checkbox is not checked.
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0);
 *    //Set the count match event
 *    Status = CNT001_SetPendingEvent((CNT001_HandleType*)&CNT001_Handle0, \
 *    CNT001_CountMatchEvent);
 *    while(1);
 *    return Status;
 * }
 * @endcode
 */
status_t CNT001_SetPendingEvent
(
    const CNT001_HandleType * HandlePtr,
    const CNT001_EventNameType Event
);

/**
 * @brief This function will check whether given event is set.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [in] Event Event to be set <BR>
 * @param [in] EvtStatus Status of the event whether it is set <BR>
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CNT001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CNT001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 *  @code
 *  #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint8_t EvtStatus = 0;
 *    DAVE_Init();
 *    //Start the app if "Start after initialization" checkbox is not checked.
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0);
 *    //Read the number of events counted till now
 *    while(1)
 *    {
 *       Status = CNT001_GetPendingEvent((CNT001_HandleType*)&CNT001_Handle0, \
 *       CNT001_CountMatchEvent, &EvtStatus);
 *       if(EvtStatus == (uint8_t)SET)
 *       {
 *         //Count match event has occurred.
 *       }
 *    }
 *    return Status;
 * }
 *
 @endcode
 */
status_t CNT001_GetPendingEvent
(
    const CNT001_HandleType * HandlePtr,
    const CNT001_EventNameType Event,
    uint8_t* EvtStatus
);


/**
 * @brief This function will reset the counter.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CNT001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CNT001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 *  @code
 *  #include <DAVE3.h>
 * int main(void)
 * {
 *    uint32_t Count = 0;
 *    status_t Status;
 *    uint8_t EvtStatus = 0;
 *    DAVE_Init();
 *    //Start the app if "Start after initialization" checkbox is not checked.
 *    Status = CNT001_Start((CNT001_HandleType*)&CNT001_Handle0);
 *    //Read the number of events counted till now
 *    while(1)
 *    {
 *       Status = CNT001_GetPendingEvent((CNT001_HandleType*)&CNT001_Handle0, \
 *       CNT001_CountMatchEvent, &EvtStatus);
 *       if(EvtStatus == (uint8_t)SET)
 *       {
 *         //Count match event has occurred.
 *         //This will reset the timer to 0 counts.
 *         CNT001_ResetCounter((CNT001_HandleType*)&CNT001_Handle0);
 *       }
 *    }
 *    return Status;
 * }
 *
 @endcode
 */

status_t CNT001_ResetCounter
(
  const CNT001_HandleType * HandlePtr
);

#include "CNT001_Conf.h"

/**
 * @}
 */
#ifdef __cplusplus
}
#endif

#endif /* EVTCOUNTER_H_ */
