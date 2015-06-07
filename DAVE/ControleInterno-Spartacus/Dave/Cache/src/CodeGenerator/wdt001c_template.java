package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class wdt001c_template
{
  protected static String nl;
  public static synchronized wdt001c_template create(String lineSeparator)
  {
    nl = lineSeparator;
    wdt001c_template result = new wdt001c_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = "/*CODE_BLOCK_BEGIN[WDT001.c]*/" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2013, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without** " + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : App Developer                                                   **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Apr 04, 2013                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                      Author(s) Identity                                    **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** PAE        App Developer                                                   **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * @file WDT001.c" + NL + " *" + NL + " * @brief  Watch Dog Timer App" + NL + " *" + NL + " */" + NL + "/* Revision History" + NL + " * 11 Jan 2013 v1.0.6 Base Version for porting" + NL + " * 04 Apr 2013 v1.0.8 device based code generation for clk gating and SCU interrupt unmasking is added" + NL + " */" + NL + "/*******************************************************************************" + NL + " ** INCLUDE FILES                                                             **" + NL + " ******************************************************************************/" + NL + "#include <DAVE3.h>" + NL;
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = "  " + NL + "/*****************************************************************************" + NL + "              DUMMY DEFINTIONS OF DEBUG LOG MACROS" + NL + "*****************************************************************************/" + NL + "/*These definitions are included here to avoid compilation errors," + NL + " since the DBG002 app is not part of the project. All the macros are defined" + NL + " as empty*/ " + NL + "#ifndef _DBG002_H_" + NL + "" + NL + "#define DBG002_RegisterCallBack(A,B,C)" + NL + "#define DBG002_I(e) " + NL + "#define DBG002_IG(e,g) " + NL + "#define DBG002_IH(e,h) " + NL + "#define DBG002_IP(e,p) " + NL + "#define DBG002_IGH(e,g,h) " + NL + "#define DBG002_IGP(e,g,p) " + NL + "#define DBG002_IHP(e,h,p) " + NL + "#define DBG002_IGHP(e,g,h,p) " + NL + "#define DBG002_N(e) " + NL + "#define DBG002_NG(e,g) " + NL + "#define DBG002_NH(e,h) " + NL + "#define DBG002_NP(e,p) " + NL + "#define DBG002_NGH(e,g,h) " + NL + "#define DBG002_NGP(e,g,p) " + NL + "#define DBG002_NHP(e,h,p) " + NL + "#define DBG002_NGHP(e,g,h,p) " + NL + "#define DBG002_ID(e) " + NL + "#define DBG002_IS(e) " + NL + "#define DBG002_ISG(e,g) " + NL + "#define DBG002_SAFETY_CRITICAL(groupid,messageid,length,value)" + NL + "#define DBG002_CRITICAL(groupid,messageid,length,value)" + NL + "#define DBG002_ERROR(groupid,messageid,length,value)" + NL + "#define DBG002_WARNING(groupid,messageid,length,value)" + NL + "#define DBG002_INFO(groupid,messageid,length,value)" + NL + "#define DBG002_TRACE(groupid,messageid,length,value)" + NL + "#define DBG002_FUNCTION_ENTRY(GID, Status) " + NL + "#define DBG002_FUNCTION_EXIT(GID, Status) " + NL + "" + NL + "#endif/* End of definitions of dummy Debug Log macros*/";
  protected final String TEXT_4 = "      " + NL + NL;
  protected final String TEXT_5 = NL;
  protected final String TEXT_6 = NL;
  protected final String TEXT_7 = NL;
  protected final String TEXT_8 = NL;
  protected final String TEXT_9 = NL;
  protected final String TEXT_10 = NL;
  protected final String TEXT_11 = NL;
  protected final String TEXT_12 = NL + "/*******************************************************************************" + NL + "**                      Private Macro Definitions                             **" + NL + "*******************************************************************************/" + NL + "" + NL + "#define APP_GID DBG002_GID_WDT001" + NL + "/*******************************************************************************" + NL + "**                      Extern Declaration                                    **" + NL + "*******************************************************************************/";
  protected final String TEXT_13 = NL + "/*User defined Event Handler function */  " + NL + "extern void ";
  protected final String TEXT_14 = "(uint32_t CbArg);";
  protected final String TEXT_15 = NL + NL + NL + "/*******************************************************************************" + NL + "**                      Public Function Definitions                           **" + NL + "*******************************************************************************/" + NL + "" + NL + " /* Function initializes the App based on the UI configurable items  */" + NL + "void  WDT001_Init(void) " + NL + "{" + NL + "  /*<<<DD_WDT001_API_1>>> */" + NL + "  DBG002_FUNCTION_ENTRY(DBG002_GID_WDT001,WDT001_FUN_ENTRY);";
  protected final String TEXT_16 = NL + "   /* Deassert the clock gating under SCU module to enable the WDT peripheral" + NL + "   */";
  protected final String TEXT_17 = NL + "       if (!((uint32_t)SCU_CLK->CGATCLR0 & (uint32_t)SCU_CLK_CGATCLR0_WDT_Pos)){ " + NL + "       SCU_GENERAL->PASSWD = 0x000000C0UL;" + NL + "       WR_REG(SCU_CLK->CLKCR, SCU_CLK_CLKCR_CNTADJ_Msk, SCU_CLK_CLKCR_CNTADJ_Pos,CLK002_DELAYCNT);" + NL + "       SET_BIT(SCU_CLK->CGATCLR0, SCU_CLK_CGATCLR0_WDT_Pos);" + NL + "       while ((uint32_t)SCU_CLK->CLKCR & (uint32_t)SCU_CLK_CLKCR_VDDC2LOW_Msk)" + NL + "       {" + NL + "       \t    ;" + NL + "       }" + NL + "       SCU_GENERAL->PASSWD = 0x000000C3UL;" + NL + "       }";
  protected final String TEXT_18 = NL + "   SET_BIT(SCU_CLK->CGATCLR2, SCU_CLK_CGATCLR2_WDT_Pos);";
  protected final String TEXT_19 = " " + NL + "  /* Reset the WDT Unit*/" + NL + "  RESET001_DeassertReset(PER2_WDT);";
  protected final String TEXT_20 = NL + "  /* Configure Window Lower Bound*/" + NL + "  WDT->WLB = 0x";
  protected final String TEXT_21 = "UL;" + NL + "  /* Configure Window Upper Bound*/   " + NL + "  WDT->WUB = 0x";
  protected final String TEXT_22 = "UL;" + NL + "  " + NL + "  /* Configure pre-warning interrupt enable" + NL + "  and Service Indication pulse width*/" + NL + "  WDT->CTR |= (uint32_t)\\" + NL + "    ((((uint32_t)";
  protected final String TEXT_23 = " << WDT_CTR_SPW_Pos) & WDT_CTR_SPW_Msk) | \\" + NL + "\t  ((uint32_t)";
  protected final String TEXT_24 = " << WDT_CTR_PRE_Pos)); " + NL + "" + NL + "  ";
  protected final String TEXT_25 = NL + "  /* Enable Pre-warning Interrupt in SCU */" + NL + "  SCU_INTERRUPT->SRMSK |= (uint32_t)1 << SCU_INTERRUPT_SRMSK_PRWARN_Pos;";
  protected final String TEXT_26 = NL + "  /* Register User defined Event Handler function */  " + NL + "  NVIC_SCU001_RegisterCallback(NVIC_SCU001_PRWARN,&";
  protected final String TEXT_27 = ",0U);";
  protected final String TEXT_28 = NL + "  NVIC_SR101_RegisterCallback(NVIC_SR101_PRWARN,&";
  protected final String TEXT_29 = ",0U);";
  protected final String TEXT_30 = "  ";
  protected final String TEXT_31 = NL + "  DBG002_FUNCTION_EXIT(DBG002_GID_WDT001,WDT001_FUN_EXIT);" + NL + "}" + NL + "" + NL + "/*CODE_BLOCK_END*/" + NL;
  protected final String TEXT_32 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
     String AppBaseuri = "app/wdt001/";
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
     int Is44Device = -1; 
    stringBuffer.append(TEXT_5);
     int Is42Device = -1; 
    stringBuffer.append(TEXT_6);
     int Is45Device = -1; 
    stringBuffer.append(TEXT_7);
     int Is1xDevice = -1; 
    stringBuffer.append(TEXT_8);
     Is45Device = ((app.getSoftwareId().substring(0,2).compareTo("45")==0)?1:0); 
    stringBuffer.append(TEXT_9);
     Is44Device = ((app.getSoftwareId().substring(0,2).compareTo("44")==0)?1:0); 
    stringBuffer.append(TEXT_10);
     Is42Device = ((app.getSoftwareId().substring(0,2).compareTo("42")==0)?1:0); 
    stringBuffer.append(TEXT_11);
     Is1xDevice = ((app.getSoftwareId().substring(0,1).compareTo("1")==0)?1:0); 
    stringBuffer.append(TEXT_12);
     if (app.getIntegerValue(AppBaseuri + "0/wdt001_erwPreWarnEnable/0") == 1 ){
     if (app.getIntegerValue(AppBaseuri + "0/WDT0001_Eventtrigger_prewarning/0") == 1 ){
    String PreWarnHandler = app.getStringValue(AppBaseuri + "0/wdt001_irwPreWarnCallbackFunc");
if((PreWarnHandler != null) && (PreWarnHandler != "")) { 
    stringBuffer.append(TEXT_13);
    stringBuffer.append(PreWarnHandler);
    stringBuffer.append(TEXT_14);
     }} 
     } 
    stringBuffer.append(TEXT_15);
     String MappedUri = null; 
     String appInst  = null; 
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/wdt001/"));
  for (String appIns : appsList ) {
  appInst = appIns.substring(appIns.lastIndexOf("/")+1);
  MappedUri = app.getMappedUri(AppBaseuri + appInst + "/wdt"); 
  if((MappedUri != null) && (MappedUri != "")){
    if ((Is44Device==1)||(Is42Device==1)||(Is1xDevice==1))
   {
    stringBuffer.append(TEXT_16);
    if (Is1xDevice==1){ 
    stringBuffer.append(TEXT_17);
    }else{
    stringBuffer.append(TEXT_18);
    }}
    if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1))
  {
    stringBuffer.append(TEXT_19);
    }
    stringBuffer.append(TEXT_20);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst +"/wdt001_irwLowerBoundSerWindow") );
    stringBuffer.append(TEXT_21);
    stringBuffer.append( app.getHexValue(AppBaseuri + appInst +"/wdt001_irwUpperBoundSerWindow") );
    stringBuffer.append(TEXT_22);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/wdt001_irwPulseWidth") - 1);
    stringBuffer.append(TEXT_23);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/wdt001_erwPreWarnEnable/0") );
    stringBuffer.append(TEXT_24);
     if (app.getIntegerValue(AppBaseuri + appInst +"/wdt001_erwPreWarnEnable/0") == 1 ){
    if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1))
  {
    stringBuffer.append(TEXT_25);
    }
     if (app.getIntegerValue(AppBaseuri + appInst +"/WDT0001_Eventtrigger_prewarning/0") == 1 ){
    String EventHandler = app.getStringValue(AppBaseuri + appInst +"/wdt001_irwPreWarnCallbackFunc");
    if((EventHandler != null) && (EventHandler != "")) { 
    if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1))
      {
    stringBuffer.append(TEXT_26);
    stringBuffer.append(EventHandler);
    stringBuffer.append(TEXT_27);
     } else {
    stringBuffer.append(TEXT_28);
    stringBuffer.append(EventHandler);
    stringBuffer.append(TEXT_29);
    } } 
    }}
    stringBuffer.append(TEXT_30);
    }}
    stringBuffer.append(TEXT_31);
    stringBuffer.append(TEXT_32);
    return stringBuffer.toString();
  }
}
