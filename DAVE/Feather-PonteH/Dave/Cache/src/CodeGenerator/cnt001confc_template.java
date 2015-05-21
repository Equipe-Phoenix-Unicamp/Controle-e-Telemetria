package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class cnt001confc_template
{
  protected static String nl;
  public static synchronized cnt001confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    cnt001confc_template result = new cnt001confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[CNT001Conf.c]*/" + NL + "" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2013, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without**" + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : DAVE App Developer                                              **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/Yes]: Yes                                      **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : December 10, 2013                                      **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK           DAVE App Developer                                            **" + NL + "*******************************************************************************/";
  protected final String TEXT_2 = NL + "/**" + NL + " * @file  CNT001_Conf.c" + NL + " * @App Version CNT001 <";
  protected final String TEXT_3 = ">" + NL + " * @brief This file has the App instance configurations" + NL + "" + NL + " *" + NL + " */" + NL + "/* Revision History\t" + NL + " * 01 Nov 2012   v1.0.12   Taken as a base version\t\t" + NL + " * 10 Dec 2012   v1.0.14   Sliceuri static definition is removed" + NL + "" + NL + " */" + NL + "#include <DAVE3.h>" + NL;
  protected final String TEXT_4 = NL;
  protected final String TEXT_5 = NL;
  protected final String TEXT_6 = NL;
  protected final String TEXT_7 = NL + NL + "CNT001_DynamicDataType CNT001_DynamicHandle";
  protected final String TEXT_8 = " =" + NL + "{" + NL + "  .EvtCounterValue = 0x00U," + NL + "  .NewCountMatch = 0x00U," + NL + "  .State = CNT001_UNINITIALIZED" + NL + "};" + NL + "" + NL + "const CNT001_HandleType CNT001_Handle";
  protected final String TEXT_9 = " =" + NL + "{" + NL + " " + NL + "  .CountingEventEdge = ";
  protected final String TEXT_10 = "CNT001_FALLINGEDGE,";
  protected final String TEXT_11 = "CNT001_BOTHEDGES,";
  protected final String TEXT_12 = "CNT001_RISINGEDGE,";
  protected final String TEXT_13 = NL + "  .CountMatch = ";
  protected final String TEXT_14 = "U," + NL + "  .ExternalGatingSignal = ";
  protected final String TEXT_15 = "0U,";
  protected final String TEXT_16 = "1U,";
  protected final String TEXT_17 = "  " + NL + "  .GatingLevel = ";
  protected final String TEXT_18 = "CNT001_ACTIVELOW,";
  protected final String TEXT_19 = "CNT001_ACTIVEHIGH,";
  protected final String TEXT_20 = " " + NL + "  .Lpf = ";
  protected final String TEXT_21 = "U, " + NL + "  .CCUInUse = CNT001_SLICE";
  protected final String TEXT_22 = "," + NL + "  .CC4KernalPtr= (CCU4_GLOBAL_TypeDef*) CCU4";
  protected final String TEXT_23 = "_BASE," + NL + "  .CC4Ptr= (CCU4_CC4_TypeDef*)CCU4";
  protected final String TEXT_24 = "_CC4";
  protected final String TEXT_25 = "," + NL + "  .DynamicHandlePtr= &CNT001_DynamicHandle";
  protected final String TEXT_26 = "," + NL + "  .StartControl = ";
  protected final String TEXT_27 = "U," + NL + "  .InterruptControl = 0x";
  protected final String TEXT_28 = "U," + NL + "  " + NL + "" + NL + "};  " + NL + "  ";
  protected final String TEXT_29 = NL + "// This app is not mapped to any CCU4 slice.";
  protected final String TEXT_30 = NL + "/*CODE_BLOCK_END*/";
  protected final String TEXT_31 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/cnt001/"; 
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri) );
    stringBuffer.append(TEXT_3);
     String SliceUri = null; 
     String kernelNo = null; 
     String sliceNo = null; 
    stringBuffer.append(TEXT_4);
     String appInst  = null; 
    stringBuffer.append(TEXT_5);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/cnt001/"));
for (String appIns : appsList ) {
    appInst = appIns.substring(appIns.lastIndexOf("/")+1);
    stringBuffer.append(TEXT_6);
     SliceUri = app.getMappedUri(AppBaseuri + appInst +"/slice"); 
     if ((SliceUri != null) && (SliceUri.trim() != "")) { 
     kernelNo = SliceUri.substring(SliceUri.indexOf("/ccu4")+6,SliceUri.indexOf("/cc4/")); 
     sliceNo = SliceUri.substring(SliceUri.length() -1); 
     int interrupt = (app.getIntegerValue(AppBaseuri + appInst + "/cnt001_erwcountmatch/0") << 2) | app.getIntegerValue(AppBaseuri + appInst + "/cnt001_erwrollover/0") 
|(app.getIntegerValue(AppBaseuri + appInst + "/cnt001_erwgating/0") << 9)|(app.getIntegerValue(AppBaseuri + appInst + "/cnt001_erweventedge/0") << 8);
    stringBuffer.append(TEXT_7);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_8);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_9);
     if (app.getIntegerValue(AppBaseuri + appInst + "/slice/ins/ev0em") == 2){
    stringBuffer.append(TEXT_10);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/slice/ins/ev0em") == 3){
    stringBuffer.append(TEXT_11);
    } else {
    stringBuffer.append(TEXT_12);
    }
    stringBuffer.append(TEXT_13);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/slice/crs/crs"));
    stringBuffer.append(TEXT_14);
     if  (app.getIntegerValue(AppBaseuri + appInst + "/cnt001_externalgating/0") == 1){
    stringBuffer.append(TEXT_15);
    } else {
    stringBuffer.append(TEXT_16);
    }
    stringBuffer.append(TEXT_17);
     if  (app.getIntegerValue(AppBaseuri + appInst + "/cnt001_externalgating/2") == 1){
    stringBuffer.append(TEXT_18);
    } else {
    stringBuffer.append(TEXT_19);
    }
    stringBuffer.append(TEXT_20);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/slice/ins/lpf0m") );
    stringBuffer.append(TEXT_21);
    stringBuffer.append(sliceNo);
    stringBuffer.append(TEXT_22);
    stringBuffer.append( kernelNo);
    stringBuffer.append(TEXT_23);
    stringBuffer.append( kernelNo);
    stringBuffer.append(TEXT_24);
    stringBuffer.append(sliceNo);
    stringBuffer.append(TEXT_25);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_26);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/cnt001_erwstart/0"));
    stringBuffer.append(TEXT_27);
    stringBuffer.append( Integer.toHexString(interrupt) );
    stringBuffer.append(TEXT_28);
    }
    else {
    stringBuffer.append(TEXT_29);
    }
    }
    stringBuffer.append(TEXT_30);
    stringBuffer.append(TEXT_31);
    return stringBuffer.toString();
  }
}
