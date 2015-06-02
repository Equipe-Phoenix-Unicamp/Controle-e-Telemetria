package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class cnt001c_template
{
  protected static String nl;
  public static synchronized cnt001c_template create(String lineSeparator)
  {
    nl = lineSeparator;
    cnt001c_template result = new cnt001c_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[CNT001.c]*/" + NL + "" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2014, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without**" + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : DAVE App Developer                                              **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Jan 24, 2014                                           **" + NL + "*******************************************************************************/" + NL + "" + NL + "" + NL + "/**" + NL + " * @file CNT001.c" + NL + " *" + NL + " * @brief This file contains CCU4_EventCounter_CNT001 App API definitions" + NL + " * This app counts the number of events. Event could be the rising edge or" + NL + " * falling edge or both edges of the input signal." + NL + " * Input signal can be given through GPIO or any other peripheral like ERU," + NL + " * CCU4,8" + NL + " */" + NL + "" + NL + "/* Revision History\t" + NL + " * 01 Nov 2012   v1.0.12   Taken as a base version\t\t\t\t\t\t\t\t\t\t\t\t\t\t     " + NL + " * 10 Dec 2012   v1.0.14   DBG002 Macros are added" + NL + " * 07 Feb 2013 \t v1.0.16   Repetitive Status updation in Event APIs is removed" + NL + " * 23 Jan 2014   v1.0.22   Error codes are added in various functions, that can " + NL + " *                         be logged with DBG002 App.\t\t\t\t   " + NL + " */" + NL + "" + NL + "/******************************************************************************" + NL + " **                      Author(s) Identity                                   **" + NL + " *******************************************************************************" + NL + " **                                                                           **" + NL + " ** Initials     Name                                                         **" + NL + " ** SK           DAVE App Developer                                           **" + NL + " ** --------------------------------------------------------------------------**" + NL + "" + NL + " *******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + " ** INCLUDE FILES                                                             **" + NL + " *******************************************************************************/" + NL + "#include <DAVE3.h>" + NL + "#include \"../../inc/CNT001/CNT001.h\"" + NL;
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = "  " + NL + "/*****************************************************************************" + NL + "              DUMMY DEFINTIONS OF DEBUG LOG MACROS" + NL + "*****************************************************************************/" + NL + "/*These definitions are included here to avoid compilation errors," + NL + " since the DBG002 app is not part of the project. All the macros are defined" + NL + " as empty*/ " + NL + "#ifndef _DBG002_H_" + NL + "" + NL + "#define DBG002_RegisterCallBack(A,B,C)" + NL + "#define DBG002_I(e) " + NL + "#define DBG002_IG(e,g) " + NL + "#define DBG002_IH(e,h) " + NL + "#define DBG002_IP(e,p) " + NL + "#define DBG002_IGH(e,g,h) " + NL + "#define DBG002_IGP(e,g,p) " + NL + "#define DBG002_IHP(e,h,p) " + NL + "#define DBG002_IGHP(e,g,h,p) " + NL + "#define DBG002_N(e) " + NL + "#define DBG002_NG(e,g) " + NL + "#define DBG002_NH(e,h) " + NL + "#define DBG002_NP(e,p) " + NL + "#define DBG002_NGH(e,g,h) " + NL + "#define DBG002_NGP(e,g,p) " + NL + "#define DBG002_NHP(e,h,p) " + NL + "#define DBG002_NGHP(e,g,h,p) " + NL + "#define DBG002_ID(e) " + NL + "#define DBG002_IS(e) " + NL + "#define DBG002_ISG(e,g) " + NL + "#define DBG002_SAFETY_CRITICAL(groupid,messageid,length,value)" + NL + "#define DBG002_CRITICAL(groupid,messageid,length,value)" + NL + "#define DBG002_ERROR(groupid,messageid,length,value)" + NL + "#define DBG002_WARNING(groupid,messageid,length,value)" + NL + "#define DBG002_INFO(groupid,messageid,length,value)" + NL + "#define DBG002_TRACE(groupid,messageid,length,value)" + NL + "#define DBG002_FUNCTION_ENTRY(GID, Status) " + NL + "#define DBG002_FUNCTION_EXIT(GID, Status) " + NL + "#define DBG002_MESSAGEID_LITERAL " + NL + "#endif/* End of defintions of dummy Debug Log macros*/";
  protected final String TEXT_4 = "                  " + NL + "" + NL + "#define APP_GID DBG002_GID_CNT001" + NL + "" + NL + "#define CNT001_STATUS_LEN 4U" + NL + "/*******************************************************************************" + NL + " **                      Private Type Definitions                             **" + NL + " ******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + " **                 Private Function Declarations:" + NL + " ******************************************************************************/" + NL + "/**" + NL + " * @brief This function initializes the app." + NL + " *" + NL + " * @param [in] HandlePtr pointer to the Instance variable<BR>" + NL + " *" + NL + " * @return  NOne <BR>" + NL + " *" + NL + " * <b>Reentrancy:  Yes</b><BR>" + NL + " * <b>Sync/Async:  Synchronous</b><BR>" + NL + " */" + NL + "" + NL + "status_t CNT001_lInit(const CNT001_HandleType *HandlePtr );" + NL + "" + NL + "/*******************************************************************************" + NL + " **                      Global Constant Definitions                          **" + NL + " ******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + " **                      Global Variable Definitions                          **" + NL + " ******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + " **                      Private Constant Definitions                         **" + NL + " ******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + " **                 Function like macro definitions                           **" + NL + " ******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + " **                      Private Function Definitions                         **" + NL + " ******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + " **                      Public Function Definitions                          **" + NL + " ******************************************************************************/" + NL + "/**" + NL + " * @cond INTERNAL_DOCS" + NL + " */" + NL;
  protected final String TEXT_5 = NL + NL + "/** This function initializes the app */" + NL + "void CNT001_Init(void)" + NL + "{" + NL + "  status_t status = (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + NL;
  protected final String TEXT_6 = NL + "  CCU4GLOBAL_Init();" + NL + "  status = CNT001_lInit( &CNT001_Handle";
  protected final String TEXT_7 = ");" + NL + "    " + NL + "    /* Start the app if \"Start after initialization\" is selected */" + NL + "  if(status == (uint32_t)DAVEApp_SUCCESS)" + NL + "  {" + NL + "\tDBG002_N(status != DAVEApp_SUCCESS);" + NL + "    if(CNT001_Handle";
  protected final String TEXT_8 = ".StartControl == (uint8_t)SET)" + NL + "    {" + NL + "      status = CNT001_Start( &CNT001_Handle";
  protected final String TEXT_9 = ");" + NL + "\t  DBG002_N(status != DAVEApp_SUCCESS);" + NL + "    }" + NL + "  }" + NL + "  else" + NL + "  {" + NL + "\t DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "  }";
  protected final String TEXT_10 = NL + "}" + NL + "" + NL + "/* This Function initializes the CCU4_CCy slice and the App. Local function" + NL + " *  is used to initialize all the instances of the app." + NL + " */" + NL + "status_t CNT001_lInit(const CNT001_HandleType *HandlePtr )" + NL + "{" + NL + "" + NL + "  status_t status = (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "" + NL + "  CCU4_CC4_TypeDef *CCU4Ptr;          /*Pointer to the CCU4 Structure */" + NL + "" + NL + "  CCU4_GLOBAL_TypeDef *CCU4KernelPtr; /* Pointer to the CCU4 Kernel Structure */" + NL + "  CCU4Ptr = HandlePtr->CC4Ptr;" + NL + "  CCU4KernelPtr = HandlePtr->CC4KernalPtr;" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "  do" + NL + "  {" + NL + "    /*<<<DD_CNT001_API_1_1>>>*/" + NL + "" + NL + "    if (HandlePtr->DynamicHandlePtr->State != CNT001_UNINITIALIZED)" + NL + "    {" + NL + "      DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "      break;" + NL + "    }/* End of \"if(HandlePtr->DynamicHandlePtr->State != CNT001_UNINITIALIZED)\"*/" + NL + "" + NL + "    /*<<<DD_CNT001_API_1_2>>>*/" + NL + "    /* Set the Input Selector Register */" + NL + "    /* Step1: Clear the  EV0EM & LPF0M bit fields */" + NL + "    CCU4Ptr->INS &= (uint32_t)~((CCU4_CC4_INS_EV0EM_Msk )| \\" + NL + "        (uint32_t)(CCU4_CC4_INS_LPF0M_Msk ) \\" + NL + "    );" + NL + "    /*Step2: Set the Bit */" + NL + "    CCU4Ptr->INS |= (uint32_t)((((uint32_t)HandlePtr->CountingEventEdge <<" + NL + "        CCU4_CC4_INS_EV0EM_Pos)& (uint32_t)CCU4_CC4_INS_EV0EM_Msk) | \\" + NL + "        (((uint32_t)HandlePtr->Lpf   << \\" + NL + "            CCU4_CC4_INS_LPF0M_Pos)& (uint32_t)CCU4_CC4_INS_LPF0M_Msk)" + NL + "    );" + NL + "" + NL + "    /* Set CNT001_EVENT0 as External Counting function in CMC Register*/" + NL + "    WR_REG(CCU4Ptr->CMC, (uint32_t)CCU4_CC4_CMC_CNTS_Msk,\\" + NL + "\t                   (uint32_t)CCU4_CC4_CMC_CNTS_Pos,(uint32_t)CNT001_EVENT0);" + NL + "" + NL + "    /* If Gating enabled , Set CNT001_EVENT1 as external gating signal*/" + NL + "    if (HandlePtr->ExternalGatingSignal)" + NL + "    {" + NL + "      CCU4Ptr->INS |= (((uint32_t)HandlePtr->GatingLevel  << CCU4_CC4_INS_EV1LM_Pos )\\" + NL + "          & (uint32_t)CCU4_CC4_INS_EV1LM_Msk);" + NL + "      CCU4Ptr->CMC |= (((uint32_t)CNT001_EVENT1  << CCU4_CC4_CMC_GATES_Pos)\\" + NL + "          & (uint32_t)CCU4_CC4_CMC_GATES_Msk);" + NL + "      if((uint32_t)HandlePtr->GatingLevel == (uint8_t)RESET)" + NL + "      {" + NL + "        CCU4Ptr->INS |= (((uint32_t)0x01  << CCU4_CC4_INS_EV1EM_Pos )\\" + NL + "            & (uint32_t)CCU4_CC4_INS_EV1EM_Msk);" + NL + "      }" + NL + "      else" + NL + "      {" + NL + "        CCU4Ptr->INS |= (((uint32_t)0x02  << CCU4_CC4_INS_EV1EM_Pos )\\" + NL + "            & (uint32_t)CCU4_CC4_INS_EV1EM_Msk);" + NL + "      }" + NL + "    }/*End of \"if( HandlePtr->ExternalGatingSignal)\" */" + NL + "" + NL + "    /* Clear the Timer Values( DITC, TCC, TRBC bit fields in TCCLR Register ) */" + NL + "    CCU4Ptr->TCCLR |= CNT001_CCU4_TCCLR_CLEAR;" + NL + "" + NL + "    /* Set edge-aligned mode in the TC Register */" + NL + "    WR_REG(CCU4Ptr->TC,(uint32_t)CCU4_CC4_TC_TCM_Msk,\\" + NL + "\t         (uint32_t)CCU4_CC4_TC_TCM_Pos,(uint32_t)CNT001_EDGE_ALIGNED_MODE );" + NL + "" + NL + "    /*Set Compare register value with the user defined value */" + NL + "    WR_REG(CCU4Ptr->CRS, (uint32_t)CCU4_CC4_CRS_CRS_Msk,\\" + NL + "\t           (uint32_t)CCU4_CC4_CRS_CRS_Pos, (uint32_t)HandlePtr->CountMatch);" + NL + "" + NL + "    /* Set Period register Value as maximum*/" + NL + "    WR_REG(CCU4Ptr->PRS, (uint32_t)CCU4_CC4_PRS_PRS_Msk,\\" + NL + "\t               (uint32_t)CCU4_CC4_PRS_PRS_Pos, (uint32_t)CNT001_MAX_EVENTS);" + NL + "" + NL + "    /* Request SW shadow transfer */" + NL + "    CCU4KernelPtr->GCSS |=" + NL + "        (uint32_t)(((uint32_t)0x01 << ((uint32_t)4 * (uint32_t)HandlePtr->CCUInUse)) |" + NL + "            ((uint32_t)0x01 << (((uint32_t)4 * (uint32_t)HandlePtr->CCUInUse) + 1U)) |" + NL + "            ((uint32_t)0x01 << (((uint32_t)4 * (uint32_t)HandlePtr->CCUInUse) + 2U)));" + NL + "" + NL + "    /* Clear all interrupts */" + NL + "    CCU4Ptr->SWR = CNT001_ALL_CCU4_INTR_CLEAR;" + NL + "" + NL + "    /* Enable configured interrupts */" + NL + "    CCU4Ptr->INTE |= HandlePtr->InterruptControl;" + NL + "" + NL + "    /*Initialize global variables */" + NL + "    HandlePtr->DynamicHandlePtr->EvtCounterValue = 0x00U;" + NL + "    HandlePtr->DynamicHandlePtr->NewCountMatch = HandlePtr->CountMatch;" + NL + "" + NL + "    /* Set the App State to Initialized */" + NL + "    HandlePtr->DynamicHandlePtr->State = CNT001_INITIALIZED;" + NL + "" + NL + "    status = (uint32_t)DAVEApp_SUCCESS;" + NL + "  }while(0);" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return status;" + NL + "}" + NL + "" + NL + "" + NL + "/* This Function resets the CCU4_CCy slice and the app */" + NL + "status_t CNT001_Deinit(const CNT001_HandleType *HandlePtr )" + NL + "{" + NL + "  status_t status = (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef *CCU4Ptr;              /* Pointer to the CCU4 Register Set  */" + NL + "  CCU4_GLOBAL_TypeDef *CCU4KernelPtr; /* Pointer to the CCU4 Kernel Register Set */" + NL + "  CCU4Ptr = HandlePtr->CC4Ptr;" + NL + "  CCU4KernelPtr = HandlePtr->CC4KernalPtr;" + NL + "" + NL + "" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "    /*<<<DD_CNT001_API_2_1>>> */" + NL + "    /* If current state is running, then stop the App first */" + NL + "    if (HandlePtr->DynamicHandlePtr->State == CNT001_UNINITIALIZED)" + NL + "    {" + NL + "      DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "    }" + NL + "    /*End of \"if( HandlePtr->DynamicHandlePtr->State == CNT001_RUNNING )\" */" + NL + "    else" + NL + "    {" + NL + "    /* Clear the Run Bit  in TCCLR register */" + NL + "    CCU4Ptr->TCCLR |= CNT001_CCU4_TCCLR_CLEAR;" + NL + "    /* Clear  the Interrupts in SWR register */" + NL + "    CCU4Ptr->SWR =  CNT001_ALL_CCU4_INTR_CLEAR ;" + NL + "    /* Disable the Interrupts in INTE Register */" + NL + "    CCU4Ptr->INTE = CNT001_CCUx_INTE_RESET;" + NL + "    /*<<<DD_CNT001_API_2_2>>> */" + NL + "    /* Set the  IDLE mode */" + NL + "    CCU4KernelPtr->GIDLS |= (uint32_t)(((uint32_t)0x01 << \\" + NL + "\t          ((uint32_t)CCU4_GIDLS_SS0I_Pos + (uint32_t)HandlePtr->CCUInUse)));" + NL + "    /* Reset Input Selector Register */" + NL + "    CCU4Ptr->INS = CNT001_CCUx_INS_RESET;" + NL + "    /* Reset CMC Register */" + NL + "    CCU4Ptr->CMC = CNT001_CCUx_CMC_RESET;" + NL + "    /* Reset TC Register */" + NL + "    CCU4Ptr->TC = CNT001_CCUx_TC_RESET;" + NL + "    /* Reset CRS Register */" + NL + "    CCU4Ptr->CRS =  CNT001_CCUx_CRS_RESET;" + NL + "    /* Reset PRS Register */" + NL + "    CCU4Ptr->PRS = CNT001_CCUx_PRS_RESET;" + NL + "    /*Clear dynamic structure variables.*/" + NL + "    HandlePtr->DynamicHandlePtr->EvtCounterValue = 0x00U;" + NL + "    HandlePtr->DynamicHandlePtr->NewCountMatch  = 0x00U;" + NL + "    /* Set the state to Uninitialized */" + NL + "    HandlePtr->DynamicHandlePtr->State = CNT001_UNINITIALIZED;" + NL + "    status = (uint32_t)DAVEApp_SUCCESS;" + NL + "    }  " + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return status;" + NL + "}" + NL + "" + NL + "/* This Function starts the CCU4_CCy slice timer and starts the app. */" + NL + "status_t  CNT001_Start(const CNT001_HandleType * HandlePtr )" + NL + "{" + NL + "  status_t status = (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef *CCU4Ptr;              /* Pointer to the CCU4 Register set */" + NL + "" + NL + "  CCU4_GLOBAL_TypeDef *CCU4KernelPtr; /* Pointer to the CCU4 Kernel Register set */" + NL + "  CCU4Ptr = HandlePtr->CC4Ptr;" + NL + "  CCU4KernelPtr = HandlePtr->CC4KernalPtr;" + NL + "" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "  /*<<<DD_CNT001_API_3_1>>> */" + NL + "    if (HandlePtr->DynamicHandlePtr->State != CNT001_INITIALIZED)" + NL + "    {" + NL + "      DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "    }/*End of \"if( HandlePtr->DynamicHandlePtr->State != CNT001_INITIALIZED )\" */" + NL + "    else" + NL + "    {" + NL + "    /*<<<DD_CNT001_API_3_2>>> */" + NL + "    /* Clear IDLE mode. */" + NL + "    SET_BIT(CCU4KernelPtr->GIDLC," + NL + "        ((uint32_t)CCU4_GIDLC_CS0I_Pos + (uint32_t)HandlePtr->CCUInUse));" + NL + "" + NL + "    /* Set the Run bit of the Slice in TCSET Register */" + NL + "    SET_BIT( CCU4Ptr->TCSET,CCU4_CC4_TCSET_TRBS_Pos );" + NL + "" + NL + "    /* Set the App State to Running State */" + NL + "    HandlePtr->DynamicHandlePtr->State = CNT001_RUNNING;" + NL + "    status = (uint32_t)DAVEApp_SUCCESS;" + NL + "    }" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return status;" + NL + "}" + NL + "" + NL + "/* This Function stops the CCU4_CCy slice timer and stops the app*/" + NL + "status_t CNT001_Stop(const CNT001_HandleType *HandlePtr )" + NL + "{" + NL + "  status_t status = (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef *CCU4Ptr;              /* Pointer to the CCU4 Register set */" + NL + "" + NL + "  CCU4_GLOBAL_TypeDef *CCU4KernelPtr; /* Pointer to the CCU4 Kernel Register set */" + NL + "  CCU4Ptr = HandlePtr->CC4Ptr;" + NL + "  CCU4KernelPtr = HandlePtr->CC4KernalPtr;" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "    /*<<<DD_CNT001_API_4_1>>>*/" + NL + "    if (HandlePtr->DynamicHandlePtr->State != CNT001_RUNNING)" + NL + "    {" + NL + "      DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "    }" + NL + "    else" + NL + "    {" + NL + "    /*<<<DD_CNT001_API_4_2>>>*/" + NL + "    /* Clear the Run Bit  in TCCLR register */" + NL + "    CCU4Ptr->TCCLR |= CNT001_CCU4_TCCLR_CLEAR;" + NL + "    /* Clear  the Interrupts in SWR register */" + NL + "    CCU4Ptr->SWR =  CNT001_ALL_CCU4_INTR_CLEAR ;" + NL + "" + NL + "    /* Set the  IDLE mode in GIDLS Register */" + NL + "    CCU4KernelPtr->GIDLS |= (uint32_t)(((uint32_t)0x01 << \\" + NL + "\t          ((uint32_t)CCU4_GIDLS_SS0I_Pos + (uint32_t)HandlePtr->CCUInUse)));" + NL + "" + NL + "    HandlePtr->DynamicHandlePtr->EvtCounterValue = 0x00U;" + NL + "    HandlePtr->DynamicHandlePtr->NewCountMatch  = 0x00U;" + NL + "    HandlePtr->DynamicHandlePtr->State = CNT001_INITIALIZED;" + NL + "    status = (uint32_t)DAVEApp_SUCCESS;" + NL + "    }" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return status;" + NL + "}" + NL + "" + NL + "/* This Function gets the timer count value which is the number of events counted till now */" + NL + "status_t CNT001_GetEvtCountValue(const CNT001_HandleType *HandlePtr, uint32_t *NumEvents )" + NL + "{" + NL + "  status_t status = (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef *CCU4Ptr;               /* Pointer to the CCU4 Register set */" + NL + "  CCU4Ptr = HandlePtr->CC4Ptr;" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "  " + NL + "    /*<<<DD_CNT001_API_5_1>>>*/" + NL + "    if (HandlePtr->DynamicHandlePtr->State == CNT001_UNINITIALIZED)" + NL + "    {" + NL + "      DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "    }" + NL + "    else" + NL + "    {" + NL + "    *NumEvents = RD_REG(CCU4Ptr->TIMER, (uint32_t)CCU4_CC4_TIMER_TVAL_Msk,\\" + NL + "\t                                         (uint32_t)CCU4_CC4_TIMER_TVAL_Pos);" + NL + "    status = (uint32_t)DAVEApp_SUCCESS;" + NL + "    }" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return status;" + NL + "}" + NL + "" + NL + "" + NL + "/* This Function reads the Count Match value. At this value, compare match interrupt is generated" + NL + " *  if it is enabled */" + NL + "status_t CNT001_GetCountMatch(const CNT001_HandleType *HandlePtr, uint32_t* CompRegVal)" + NL + "{" + NL + "  status_t status = (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "    /*<<<DD_CNT001_API_6_1>>>  */" + NL + "    if (HandlePtr->DynamicHandlePtr->State == CNT001_UNINITIALIZED)" + NL + "    {" + NL + "      DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "    }" + NL + "    else" + NL + "    {" + NL + "    /*<<<DD_CNT001_API_6_2>>>  */" + NL + "    *CompRegVal = HandlePtr->DynamicHandlePtr->NewCountMatch;" + NL + "    status = (uint32_t)DAVEApp_SUCCESS;" + NL + "    }" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return status;" + NL + "}" + NL + "" + NL + "/* This Function sets the event Count Match. This is the compare register value of the CCU4x_CCy slice */" + NL + "status_t CNT001_SetCountMatch(const CNT001_HandleType *HandlePtr, uint32_t CountMatch)" + NL + "{" + NL + "  status_t status = (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef *CCU4Ptr;            /* Pointer to the CCU4 Register set */" + NL + "" + NL + "  CCU4_GLOBAL_TypeDef *CCU4KernelPtr; /* Pointer to the CCU4 Kernel Register set */" + NL + "  CCU4Ptr = HandlePtr->CC4Ptr;" + NL + "  CCU4KernelPtr = HandlePtr->CC4KernalPtr;" + NL + "" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "    /*<<<DD_CNT001_API_7_1>>>*/" + NL + "    if (HandlePtr->DynamicHandlePtr->State != CNT001_INITIALIZED)" + NL + "    {" + NL + "      DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "    }" + NL + "    else if( CountMatch > CNT001_EVENT_COUNT_MAX   )" + NL + "    {" + NL + "      status = (uint32_t)CNT001_OUT_OF_RANGE_ERROR;" + NL + "    }" + NL + "    else" + NL + "    {" + NL + "      /*<<<DD_CNT001_API_7_5>>>*/" + NL + "      /* Update the Count match value in CRS Register */" + NL + "      WR_REG(CCU4Ptr->CRS, (uint32_t)CCU4_CC4_CRS_CRS_Msk, \\" + NL + "\t                                 (uint32_t)CCU4_CC4_CRS_CRS_Pos,CountMatch);" + NL + "  " + NL + "      /* Request SW Shadow Transfer */" + NL + "      CCU4KernelPtr->GCSS |=" + NL + "          (uint32_t)((0x01UL << ((uint32_t)4 * (uint32_t)HandlePtr->CCUInUse)));" + NL + "  " + NL + "      /* Update the Dynamic HandlePtr */" + NL + "      HandlePtr->DynamicHandlePtr ->NewCountMatch = CountMatch;" + NL + "      status = (uint32_t)DAVEApp_SUCCESS;" + NL + "    }" + NL + "" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return status;" + NL + "}" + NL + "" + NL + "/* This Function reads the timer status */" + NL + "status_t  CNT001_GetTimerStatus(const CNT001_HandleType *HandlePtr, uint32_t* Status)" + NL + "{" + NL + "  status_t status = (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef *CCU4Ptr;                 /* Pointer to the CCU4 Register set */" + NL + "  CCU4Ptr = HandlePtr->CC4Ptr;" + NL + "" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "    /*<<<DD_CNT001_API_8_1>>> */" + NL + "    if (HandlePtr->DynamicHandlePtr->State == CNT001_UNINITIALIZED)" + NL + "    {" + NL + "      DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "    }" + NL + "    else" + NL + "    {" + NL + "    /*<<<DD_CNT001_API_8_2>>> */" + NL + "    /* Get the Status of the Timer */" + NL + "    *Status = RD_REG( CCU4Ptr->TCST, (uint32_t)CCU4_CC4_TCST_TRB_Msk,\\" + NL + "\t                                           (uint32_t)CCU4_CC4_TCST_TRB_Pos);" + NL + "    status = (uint32_t)DAVEApp_SUCCESS;" + NL + "    }" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return status;" + NL + "}" + NL + "" + NL + "/* This function enables the given event */" + NL + "status_t CNT001_EnableEvent" + NL + "(" + NL + "    const CNT001_HandleType * HandlePtr," + NL + "    const CNT001_EventNameType Event" + NL + ")" + NL + "{" + NL + "  status_t Status =  (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef* CC4yRegsPtr = HandlePtr->CC4Ptr;" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "  if (HandlePtr->DynamicHandlePtr->State == CNT001_UNINITIALIZED)" + NL + "  {" + NL + "\tDBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "  }" + NL + "  else" + NL + "  {" + NL + "    SET_BIT(CC4yRegsPtr->INTE, (uint8_t) Event);" + NL + "    Status =  (uint32_t)DAVEApp_SUCCESS;" + NL + "  }" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return (Status);" + NL + "}" + NL + "" + NL + "/**" + NL + " * This function clears the enable event bit for the event given in the argument." + NL + " */" + NL + "status_t CNT001_DisableEvent" + NL + "(" + NL + "    const CNT001_HandleType * HandlePtr," + NL + "    const CNT001_EventNameType Event" + NL + ")" + NL + "{" + NL + "  status_t Status = (uint32_t) CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef* CC4yRegsPtr = HandlePtr->CC4Ptr;" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "  if (HandlePtr->DynamicHandlePtr->State == CNT001_UNINITIALIZED)" + NL + "  {" + NL + "\tDBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "  }" + NL + "  else" + NL + "  {" + NL + "    CLR_BIT(CC4yRegsPtr->INTE, (uint8_t) Event);" + NL + "    Status = (uint32_t) DAVEApp_SUCCESS;" + NL + "  }" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return (Status);" + NL + "}" + NL + "" + NL + "/**" + NL + " * This function clears the interrupt by software." + NL + " */" + NL + "status_t CNT001_ClearPendingEvent" + NL + "(" + NL + "    const CNT001_HandleType * HandlePtr," + NL + "    const CNT001_EventNameType Event" + NL + ")" + NL + "{" + NL;
  protected final String TEXT_11 = "  status_t Status =  (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef* CC4yRegsPtr = HandlePtr->CC4Ptr;" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "  if (HandlePtr->DynamicHandlePtr->State == CNT001_UNINITIALIZED)" + NL + "  {" + NL + "\tDBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "  }" + NL + "  else" + NL + "  {" + NL + "    SET_BIT(CC4yRegsPtr->SWR,  (uint8_t)Event);" + NL + "    Status =  (uint32_t)DAVEApp_SUCCESS;" + NL + "  }" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return (Status);" + NL + "}" + NL + "" + NL + "/**" + NL + " * This function sets the interrupt by software Interrupt pulse is generated" + NL + " * if source is enabled." + NL + " */" + NL + "status_t CNT001_SetPendingEvent" + NL + "(" + NL + "    const CNT001_HandleType * HandlePtr," + NL + "    const CNT001_EventNameType Event" + NL + ")" + NL + "{" + NL + "  status_t Status =  (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef* CC4yRegsPtr = HandlePtr->CC4Ptr;" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "  if (HandlePtr->DynamicHandlePtr->State == CNT001_UNINITIALIZED)" + NL + "  {" + NL + "\tDBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "  }" + NL + "  else" + NL + "  {" + NL + "    SET_BIT(CC4yRegsPtr->SWS,  (uint8_t)Event);" + NL + "    Status =  (uint32_t)DAVEApp_SUCCESS;" + NL + "  }" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return (Status);" + NL + "}" + NL + "" + NL + "/**" + NL + " * This function checks whether given interrupt is set" + NL + " */" + NL + "status_t CNT001_GetPendingEvent" + NL + "(" + NL + "    const CNT001_HandleType * HandlePtr," + NL + "    const CNT001_EventNameType Event," + NL + "    uint8_t* EvtStatus" + NL + ")" + NL + "{" + NL + "  status_t Status =  (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef* CC4yRegsPtr = HandlePtr->CC4Ptr;" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "" + NL + "  if (HandlePtr->DynamicHandlePtr->State == CNT001_UNINITIALIZED)" + NL + "  {" + NL + "\t DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "  }" + NL + "  else" + NL + "  {" + NL + "    if(RD_REG(CC4yRegsPtr->INTS, ((uint32_t)0x01<<(uint8_t)Event),(uint8_t)Event))" + NL + "    {" + NL + "      *EvtStatus = (uint8_t)SET;" + NL + "    }" + NL + "    else" + NL + "    {" + NL + "      *EvtStatus = (uint8_t)RESET;" + NL + "    }" + NL + "    /* *EvtStatus = RD_REG(CC4yRegsPtr->INTS,  (0x01<<(uint8_t)Event),(uint8_t)Event) ?\\" + NL + "\t (uint8_t)SET : (uint8_t)RESET;\t*/" + NL + "    Status =  (uint32_t)DAVEApp_SUCCESS;" + NL + "  }" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return (Status);" + NL + "}" + NL + "" + NL + "/**" + NL + " * This function resets the timer to zero." + NL + " */" + NL + "status_t CNT001_ResetCounter" + NL + "(" + NL + "    const CNT001_HandleType * HandlePtr" + NL + ")" + NL + "{" + NL + "  status_t Status =  (uint32_t)CNT001_OPER_NOT_ALLOWED_ERROR;" + NL + "  CCU4_CC4_TypeDef* CC4yRegsPtr = HandlePtr->CC4Ptr;" + NL + "  DBG002_FUNCTION_ENTRY(APP_GID, (uint32_t)CNT001_FUNCTION_ENTRY);" + NL + "  /* This function is not allowed in the UNINITIALIZED state */" + NL + "  if (HandlePtr->DynamicHandlePtr->State == CNT001_UNINITIALIZED)" + NL + "  {" + NL + "\tDBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, CNT001_STATUS_LEN, &status);" + NL + "  }" + NL + "  /* Clear the timer in TCCLR register */" + NL + "  else" + NL + "  {" + NL + "    CC4yRegsPtr->TCCLR |=  CNT001_CLEAR_COUNTER;" + NL + "    Status = (uint32_t)DAVEApp_SUCCESS;" + NL + "  }" + NL + "  DBG002_FUNCTION_EXIT(APP_GID, (uint32_t)CNT001_FUNCTION_EXIT);" + NL + "  return (Status);" + NL + "" + NL + "}" + NL + "" + NL + "" + NL + "/**" + NL + " * @endcond" + NL + " */" + NL + "/*CODE_BLOCK_END*/";
  protected final String TEXT_12 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String TempApps = null;
   String MyAppName = null;
   ArrayList<String> apps;
   String TempLowerApps = null; 
   boolean DBGApp = false;   
   apps=(ArrayList<String>)(app.getApps());
        for (int k = 0; k < apps.size(); k++) {
              TempApps = apps.get(k);
//            if(app.isAppInitProvider(apps.get(k)) == true) {
              MyAppName = TempApps.substring(TempApps.indexOf("/app/") + 5, TempApps.lastIndexOf("/"));
              TempLowerApps = MyAppName.toLowerCase();
              if (TempLowerApps.equalsIgnoreCase("dbg002")) {DBGApp = true;}   
//   }  
  } 
    stringBuffer.append(TEXT_2);
     if (!DBGApp) { 
    stringBuffer.append(TEXT_3);
     } 
    stringBuffer.append(TEXT_4);
     String AppBaseuri = "app/cnt001/"; 
     String appInst  = null; 
    stringBuffer.append(TEXT_5);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/cnt001/"));
for (String appIns : appsList ) {
    appInst = appIns.substring(appIns.lastIndexOf("/")+1);
    stringBuffer.append(TEXT_6);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_7);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_8);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_9);
    }
    stringBuffer.append(TEXT_10);
    stringBuffer.append(TEXT_11);
    stringBuffer.append(TEXT_12);
    return stringBuffer.toString();
  }
}
