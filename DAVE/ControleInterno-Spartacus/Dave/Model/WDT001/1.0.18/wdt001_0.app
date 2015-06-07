<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="WDT001" description="App to configure the Watch Dog Timer" descriptionURL="/doc/html/group___window___watchdog___timer___w_d_t001_app.html" mode="SHARABLE" URI="http://www.infineon.com/1.0.18/app/wdt001/0">
  <provided xsi:type="ResourceModel:VirtualSignal" name="Service Request Event" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_srv_request" requiredSignalResource="wdt/wdt_srv_request">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Pre-warning Event" URI="http://www.infineon.com/1.0.18/app/wdt001/0/gcu_intprewarn_int" requiredSignalResource="gcu_intprewarn/int" canExpose="false">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Enable Pre-warning Event" evalFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;function ForwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;wdt/ctr/pre&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value = SCM.getIntValue(currentResource);  &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(Res,value);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;function BackwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;wdt/ctr/pre&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value = SCM.getIntValue(Res); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if (value == -1) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,0);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;} else {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,value);&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_erwprewarnenable" downWardmappedList="//@consumed.12" multipleSelections="true">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>Pre-warning alarm to allow corrective action via 
software recovery routine to bring system back from 
the non-responsive state into normal operation</toolTipHelpDescription>
    <item name="Enable" evalFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;function ForwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value = SCM.getIntValue(currentResource);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;wdt/ctr/pre&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var XMC1xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA; &#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var WDT_Enable = SCM.getResource(&quot;nvic_sr101/NVIC_SR101_erwPreWarningEventEnableInt/0&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if (value == 1 ) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;    SCM.setIntValue(Res,1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if(XMC1xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;  &#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(WDT_Enable,1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;} else if (value === 0 ) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(Res,0);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if(XMC1xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;  &#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(WDT_Enable,0);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;function BackwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;wdt/ctr/pre&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value = SCM.getIntValue(Res); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if (value == -1) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,0);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;} else {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,value);&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_erwprewarnenable/0" downWardmappedList="//@consumed.12" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Interrupt Behavior on Pre-warning Event" evalFunction="&#xD;&#xA;&#x9;&#x9;&#x9;    function ForwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;    {&#xD;&#xA;&#x9;&#x9;&#x9;    var value = SCM.getIntValue(currentResource);&#xD;&#xA;&#x9;&#x9;&#x9;    var Res = SCM.getResource(&quot;wdt001_EventtriggerTemp&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;    SCM.setIntValue(Res,value);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;var dep1 = &quot;DependentApp&quot;;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;var XMC4xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;4&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;if(XMC4xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;{   &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;var NvicRes1 = SCM.getResource(&quot;nvic_scu001&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;SCM.setStringValue(NvicRes1,dep1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;var ExcepRes1 = SCM.getResource(&quot;excp001&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;SCM.setStringValue(ExcepRes1,dep1); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;else&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;var NvicRes1 = SCM.getResource(&quot;nvic_sr101&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;SCM.setStringValue(NvicRes1,dep1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}        &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;    function BackwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;    {&#xD;&#xA;&#x9;&#x9;&#x9;    var Res = SCM.getResource(&quot;wdt001_EventtriggerTemp&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;    var value = SCM.getIntValue(Res);&#xD;&#xA;&#x9;&#x9;&#x9;    SCM.setIntValue(currentResource,value);&#xD;&#xA;&#x9;&#x9;&#x9;  }&#xD;&#xA;      &#x9;&#x9;" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt0001_eventtrigger_prewarning" downWardmappedList="//@consumed.2 //@consumed.9 //@consumed.8">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>The Pre-warning event can generate a regular interrupt
It can be optionally promoted to an NMI request</toolTipHelpDescription>
    <item name="Event generates a Regular Interrupt" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            { &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;wdt001_EventtriggerTemp&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);       &#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;var dep1 = &quot;DependentApp&quot;;&#xD;&#xA;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9; var XMC4xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;4&quot;);&#xD;&#xA;&#x9;&#x9;&#x9; if(XMC4xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9; {   &#xD;&#xA;&#x9;&#x9;&#x9; var NvicRes1 = SCM.getResource(&quot;nvic_scu001&quot;); &#xD;&#xA;&#x9;&#x9;&#x9; SCM.setStringValue(NvicRes1,dep1);&#xD;&#xA;&#x9;&#x9;&#x9; var ExcepRes1 = SCM.getResource(&quot;excp001&quot;); &#xD;&#xA;&#x9;&#x9;&#x9; SCM.setStringValue(ExcepRes1,dep1);&#xD;&#xA;&#x9;&#x9;&#x9;    &#x9;}&#xD;&#xA;&#x9;&#x9;&#x9; else&#xD;&#xA;&#x9;&#x9;&#x9; {&#xD;&#xA;&#x9;&#x9;&#x9;  var Interrupt_Enable = SCM.getResource(&quot;nvic_sr101/NVIC_SR101_erwEnableInt/0&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;  SCM.setIntValue(Interrupt_Enable,1);&#xD;&#xA;&#x9;&#x9;&#x9; &#xD;&#xA;&#x9;&#x9;&#x9; var NvicRes1 = SCM.getResource(&quot;nvic_sr101&quot;);&#xD;&#xA;&#x9;&#x9;&#x9; SCM.setStringValue(NvicRes1,dep1);&#xD;&#xA;&#x9;&#x9;&#x9;    &#x9;} &#xD;&#xA;&#x9;&#x9;&#x9;  &#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;wdt001_EventtriggerTemp&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value === 0 ) { &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }       &#xD;&#xA;            " URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt0001_eventtrigger_prewarning/0" downWardmappedList="//@consumed.2 //@consumed.9 //@consumed.8" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>The Pre-warning Event generates a regular interrupt.
The NVIC_SCU001 App is consumed when this selection is made.
The Pre-warning Event Signal is connected to NVIC_SCU001 App.
Please provide the Event Handler name below.</toolTipHelpDescription>
    </item>
    <item name="Event generates an NMI Request" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            { &#xD;&#xA;&#x9;&#x9;&#x9;  var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;wdt001_EventtriggerTemp&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);       &#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              } &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;var dep1 = &quot;DependentApp&quot;;&#xD;&#xA;&#x9;&#x9;&#x9; &#x9;var NvicRes1 = SCM.getResource(&quot;nvic_scu001&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;SCM.setStringValue(NvicRes1,dep1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;var ExcepRes1 = SCM.getResource(&quot;excp001&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;SCM.setStringValue(ExcepRes1,dep1);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;             var XMC1xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA;&#x9;&#x9;&#x9; if(XMC1xxx==0){&#xD;&#xA;              var reserved = SCM.getReserverd();&#xD;&#xA;        &#x9;  SCM.setValue(currentResource,reserved);&#xD;&#xA;&#x9;&#x9;&#x9;  }&#xD;&#xA;&#x9;&#x9;&#x9;  else&#xD;&#xA;&#x9;&#x9;&#x9;  {&#x9;         &#xD;&#xA; &#x9;&#x9;&#x9;  var Res = SCM.getResource(&quot;wdt001_EventtriggerTemp&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value === 1 ) { &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;&#x9;&#x9;&#x9;}&#xD;&#xA;            }       &#xD;&#xA;            " URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt0001_eventtrigger_prewarning/1" downWardmappedList="//@consumed.2 //@consumed.9 //@consumed.8" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>The Pre-warning Event generates an NMI request.
The EXCP001 App is consumed when this selection is made.
The Pre-warning Event Signal is connected to EXCP001 App.
Please configure EXCP001 to handle NMI.</toolTipHelpDescription>
    </item>
    <item name="dummy" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            { &#xD;&#xA;&#x9;&#x9;&#x9;  var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;wdt001_EventtriggerTemp&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);       &#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              } &#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var reserved = SCM.getReserverd();&#xD;&#xA;        &#x9;  SCM.setValue(currentResource,reserved);&#x9;&#x9;&#x9; &#xD;&#xA;            }       &#xD;&#xA;            " URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt0001_eventtrigger_prewarning/2" downWardmappedList="//@consumed.2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:Reserved" value="Reserved"/>
      <toolTipHelpDescription>This is added just to create the dropdown instead of radio button</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Service indication pulse width" evalFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;function ForwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;                       &#xD;&#xA;&#x9; &#x9;&#x9;&#x9;&#x9;&#x9;var XMC4xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;4&quot;);  &#xD;&#xA;&#x9;   &#x9;&#x9;&#x9; &#x9;&#x9;if(XMC4xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9; {                  &#xD;&#xA;&#x9;            &#x9;&#x9;var clkRes = SCM.getResource(&quot;clockapp/clk001_erwWDTClkEnable&quot;);    &#xD;&#xA;&#x9;                    SCM.setIntValue(clkRes,1);&#xD;&#xA;&#x9;&#x9;&#x9;  &#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value = SCM.getIntValue(currentResource);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;wdt/ctr/spw&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;    SCM.setIntValue(Res,(value - 1));&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;function BackwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;wdt/ctr/spw&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value = SCM.getIntValue(Res); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if (value == -1) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;} else {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,(value + 1));&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}             &#xD;&#xA;                " URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_irwpulsewidth" downWardmappedList="//@consumed.21 //@consumed.13" maxValue="FF" minValue="1">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <localValue xsi:type="ResourceModel:StringValue" value="1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <toolTipHelpDescription>The WDT module can optionally generate an 
external service indication signal. The pulse 
width of this signal in terms of WDT clock 
cycles can be entered here.</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Lower bound service window" evalFunction="   &#xD;&#xA;                   function ForwardMapping()&#xD;&#xA;                   {&#xD;&#xA;                      var Res2 = SCM.getResource(&quot;wdt001_lbdummy&quot;);    &#xD;&#xA;                      var value = SCM.getIntValue(currentResource); &#xD;&#xA;                      SCM.setIntValue(Res2,value);&#xD;&#xA; &#x9;&#x9;&#x9;&#x9;&#x9;  var upper_bound = SCM.getResource(&quot;wdt001_irwUpperBoundSerWindow&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  SCM.setMinMaxValue(upper_bound,(value+1),4294967295,1);&#xD;&#xA;                   }&#xD;&#xA;                   function BackwardMapping()&#xD;&#xA;                   {&#xD;&#xA;                      var Res0 = SCM.getResource(&quot;wdt001_lbdummy&quot;); &#xD;&#xA;                      var value0 = SCM.getIntValue(Res0);&#xD;&#xA;                      SCM.setIntValue(currentResource,value0);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9; &#xD;&#xA;                   }&#xD;&#xA;                " URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_irwlowerboundserwindow" downWardmappedList="//@consumed.3" maxValue="FFFFFFFE" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>Attempt to service WDT while counter value remains below the Window Lower Bound results in immediate reset.</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Actual Lower Bound time" evalFunction="   &#xD;&#xA;                   function ForwardMapping()&#xD;&#xA;                   {&#xD;&#xA;                      var Res2 = SCM.getResource(&quot;wdt001_lbdummy&quot;);&#xD;&#xA;                      var LBValue = SCM.getIntValue(Res2);&#xD;&#xA; &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var XMC4xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;4&quot;);  &#xD;&#xA;&#x9;   &#x9;&#x9;&#x9; &#x9;  if(XMC4xxx==0)&#xD;&#xA;                      var clkres = SCM.getResource(&quot;clockapp/clk001_irwwdtactualfreq&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  else&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var clkres = SCM.getResource(&quot;clockapp2/clk002_standbyclock&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var clock = SCM.getDoubleValue(clkres);&#xD;&#xA;                   }&#xD;&#xA;                   function BackwardMapping()&#xD;&#xA;                   {&#xD;&#xA;                      var Res2 = SCM.getResource(&quot;wdt001_lbdummy&quot;);&#xD;&#xA;                      var LBValue = SCM.getIntValue(Res2);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var XMC4xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;4&quot;);  &#xD;&#xA;&#xD;&#xA;&#x9;   &#x9;&#x9;&#x9; &#x9;  if(XMC4xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  {&#xD;&#xA;                      var clkres = SCM.getResource(&quot;clockapp/clk001_irwwdtactualfreq&quot;);&#xD;&#xA;                      var clock = SCM.getDoubleValue(clkres);&#xD;&#xA;                      }&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  else&#xD;&#xA;                      {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var clkres = SCM.getResource(&quot;clockapp2/clk002_standbyclock&quot;);&#xD;&#xA;                      var clock = SCM.getDoubleValue(clkres);&#xD;&#xA;                      clock = clock/1000;&#xD;&#xA;                      }&#xD;&#xA;&#xD;&#xA;                      var temp = LBValue;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var Result = (temp)/(clock);&#xD;&#xA;                      Result = Result.toFixed(5);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  SCM.setDoubleValue(currentResource,(Result));&#xD;&#xA;                   }&#xD;&#xA;                " URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_irwactuallowerboundtime" maxValue="FFFFFFFFFFFF" minValue="0">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>Actual Lower Bound time.</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Upper bound service window" evalFunction="   &#xD;&#xA;                   function ForwardMapping()&#xD;&#xA;                   {&#xD;&#xA;                      var Res2 = SCM.getResource(&quot;wdt001_ubdummy&quot;);    &#xD;&#xA;                      var value = SCM.getIntValue(currentResource); &#xD;&#xA;                      SCM.setIntValue(Res2,value);&#xD;&#xA;                   }&#xD;&#xA;                   function BackwardMapping()&#xD;&#xA;                   {&#xD;&#xA;                      var Res0 = SCM.getResource(&quot;wdt001_ubdummy&quot;); &#xD;&#xA;                      var value0 = SCM.getIntValue(Res0);&#xD;&#xA;                      SCM.setIntValue(currentResource,value0);&#xD;&#xA; &#x9;&#x9;&#x9;&#x9;&#x9;  var lower_bound = SCM.getResource(&quot;wdt001_irwUpperBoundSerWindow&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  SCM.setMinMaxValue(lower_bound,0,(value-1),1);&#xD;&#xA;                   }&#xD;&#xA;                " URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_irwupperboundserwindow" downWardmappedList="//@consumed.4" maxValue="ffffffff" minValue="1">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="FFFFFFFF"/>
    <localValue xsi:type="ResourceModel:StringValue" value="ffffff"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="ffffff"/>
    <toolTipHelpDescription>The WDT triggers an reset request when the timer is
crossing the upper bound value without pre-warning enabled.
With pre-warning enabled the first crossing triggers
 a watchdog alarm and the second crossing triggers a system reset</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Actual Upper Bound time" evalFunction="   &#xD;&#xA;                   function ForwardMapping()&#xD;&#xA;                   {&#xD;&#xA;                      var Res3 = SCM.getResource(&quot;wdt001_ubdummy&quot;);&#xD;&#xA;                      var LBValue = SCM.getIntValue(Res3);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var XMC4xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;4&quot;);  &#xD;&#xA;&#x9;   &#x9;&#x9;&#x9; &#x9;  if(XMC4xxx==0)&#xD;&#xA;                      var clkres = SCM.getResource(&quot;clockapp/clk001_irwwdtactualfreq&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  else&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var clkres = SCM.getResource(&quot;clockapp2/clk002_standbyclock&quot;);&#xD;&#xA;                      var clock = SCM.getDoubleValue(clkres);&#xD;&#xA;                   }&#xD;&#xA;                   function BackwardMapping()&#xD;&#xA;                   {&#xD;&#xA;                      var Res3 = SCM.getResource(&quot;wdt001_ubdummy&quot;);&#xD;&#xA;                      var UBValue = SCM.getIntValue(Res3);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var XMC4xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;4&quot;); &#xD;&#xA; &#xD;&#xA;&#x9;   &#x9;&#x9;&#x9; &#x9;  if(XMC4xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  {&#xD;&#xA;                      var clkres = SCM.getResource(&quot;clockapp/clk001_irwwdtactualfreq&quot;);&#xD;&#xA;                      var clock = SCM.getDoubleValue(clkres);&#xD;&#xA;                      }&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  else&#xD;&#xA;                      {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var clkres = SCM.getResource(&quot;clockapp2/clk002_standbyclock&quot;);&#xD;&#xA;                      var clock = SCM.getDoubleValue(clkres);&#xD;&#xA;                      clock = clock/1000;&#xD;&#xA;                      }&#xD;&#xA; &#xD;&#xA;                      var temp = UBValue;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var Result = (temp)/(clock);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;   Result = Result.toFixed(5);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  SCM.setDoubleValue(currentResource,(Result));&#xD;&#xA;                   }&#xD;&#xA;           &#xD;&#xA;                " URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_irwactualupperboundtime" maxValue="FFFFFFFFFFFF" minValue="0">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="4085d867ab756430"/>
    <toolTipHelpDescription>Actual Upper Bound time.</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:StringParameter" name="Pre-warning Event" evalFunction="&#xD;&#xA;&#x9;&#x9;          function ForwardMapping()&#xD;&#xA;&#x9;&#x9;          {&#xD;&#xA;&#x9;&#x9;            var Res0 = SCM.getResource(&quot;wdt001_EventtriggerTemp&quot;); &#xD;&#xA;&#x9;&#x9;            var value0 = SCM.getIntValue(Res0); &#xD;&#xA;&#x9;&#x9;          }&#xD;&#xA;&#x9;&#x9;          function BackwardMapping()&#xD;&#xA;&#x9;&#x9;          {&#xD;&#xA;&#x9;&#x9;            var Res0 = SCM.getResource(&quot;wdt001_EventtriggerTemp&quot;); &#xD;&#xA;&#x9;&#x9;            var value0 = SCM.getIntValue(Res0); &#xD;&#xA;&#x9;&#x9;            if((value0 === 0)){&#xD;&#xA;&#x9;&#x9;              SCM.setStringValue(currentResource, &quot;Generates Interrupt. Please provide handler below&quot;);&#xD;&#xA;&#x9;&#x9;            }&#xD;&#xA;&#x9;&#x9;            else  if((value0 === 1)){&#xD;&#xA;&#x9;&#x9;              SCM.setStringValue(currentResource, &quot;Generates NMI. Please configure NMI in EXCP001 app&quot;);&#xD;&#xA;&#x9;&#x9;            }&#xD;&#xA;&#x9;&#x9;            else{&#xD;&#xA;&#x9;&#x9;              SCM.setStringValue(currentResource,&quot; &quot;);&#xD;&#xA;&#x9;&#x9;          }&#xD;&#xA;&#x9;&#x9;        }&#xD;&#xA;&#x9;&#x9;        " URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_erostring1">
    <defaultValue xsi:type="ResourceModel:StringValue" value="Generates regular Interrupt. Please provide handler below"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Generates regular Interrupt. Please provide handler below"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Generates regular Interrupt. Please provide handler below"/>
    <toolTipHelpDescription>Selected trigger setting (non-editable)</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:StringParameter" name="User defined Pre-warning Event Handler" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_irwprewarncallbackfunc">
    <defaultValue xsi:type="ResourceModel:StringValue" value=""/>
    <localValue xsi:type="ResourceModel:StringValue" value=""/>
    <globalValue xsi:type="ResourceModel:StringValue" value=""/>
    <toolTipHelpDescription>User defined callback function of type: 
 typedef void (*NVIC_SCU001_CallbackType)(uint32_t CbArg) or typedef void (*NVIC_SR101_CallbackType)(uint32_t CbArg);
 This callback function is called on a Pre-warning Event.</toolTipHelpDescription>
  </provided>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="function resourceCondition() {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var value1 = Solver.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;if(value1  == 0 ) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  return false;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;return true;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp">
    <downWardmappedList xsi:type="ResourceModel:App" href="../../CLK001/1.0.44/clk001_0.app#/"/>
    <requiredResource uriString="app/clk001/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="function resourceCondition() {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var value1 = Solver.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;if(value1  == 0 ) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  return true;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;return false;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp2">
    <requiredResource uriString="app/clk002/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_eventtriggertemp" upWardMappingList="//@provided.3 //@provided.3/@item.0 //@provided.3/@item.1 //@provided.3/@item.2 //@provided.9" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_lbdummy" upWardMappingList="//@provided.5 //@provided.6" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt001_ubdummy" upWardMappingList="//@provided.7 //@provided.8" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="ffffff"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="ffffff"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt">
    <downWardmappedList xsi:type="ResourceModel:ResourceGroup" href="../../WDT/WDT_0.dd#//@provided.0"/>
    <requiredResource uriString="peripheral/wdt/0/wdt" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/gcu_intprewarn">
    <downWardmappedList xsi:type="ResourceModel:ResourceGroup" href="../../SCU/SCU_0.dd#//@provided.55"/>
    <requiredResource uriString="peripheral/scu/0/gcu/interrupt/prewarn" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="function resourceCondition() {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var XMC1xxx = Solver.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;if(XMC1xxx  == 0 ) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  return false;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;return true;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}" URI="http://www.infineon.com/1.0.18/app/wdt001/0/resetapp">
    <downWardmappedList xsi:type="ResourceModel:App" href="../../RESET001/1.0.14/reset001_0.app#/"/>
    <requiredResource uriString="app/reset001/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="function resourceCondition() {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;  var XMC4xxx = Solver.getSoftwareId().substring(0,1).compareTo(&quot;4&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;  if(XMC4xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;  {&#xD;&#xA;&#x9;&#x9;          var Res = Solver.getResource(&quot;wdt001_EventtriggerTemp&quot;);&#xD;&#xA;&#x9;&#x9;          var value = Solver.getIntValue(Res);&#xD;&#xA;&#x9;&#x9;          if (value == 1)&#xD;&#xA;&#x9;&#x9;          {&#xD;&#xA;&#x9;&#x9;            return true; &#xD;&#xA;&#x9;&#x9;           } &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;  }&#xD;&#xA;&#x9;&#x9;          return false;&#xD;&#xA;&#x9;&#x9;        }" URI="http://www.infineon.com/1.0.18/app/wdt001/0/excp001" upWardMappingList="//@provided.3 //@provided.3/@item.0 //@provided.3/@item.1">
    <localValue xsi:type="ResourceModel:StringValue" value="DependentApp"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="DependentApp"/>
    <requiredResource uriString="app/excp001/0" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="function resourceCondition() {&#xD;&#xA; &#x9;&#x9;&#x9;&#x9;  var XMC4xxx = Solver.getSoftwareId().substring(0,1).compareTo(&quot;4&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;  if(XMC4xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;  {&#x9;&#x9;&#x9;          &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var Res = Solver.getResource(&quot;wdt001_EventtriggerTemp&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;          var value = Solver.getIntValue(Res);&#xD;&#xA;&#x9;&#x9;&#x9;          if (value == 0)&#xD;&#xA;&#x9;&#x9;&#x9;          {&#xD;&#xA;&#x9;&#x9;&#x9;            return true; &#xD;&#xA;&#x9;&#x9;&#x9;          } &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;          return false;&#xD;&#xA;&#x9;&#x9;&#x9;        }" URI="http://www.infineon.com/1.0.18/app/wdt001/0/nvic_scu001" upWardMappingList="//@provided.3 //@provided.3/@item.0 //@provided.3/@item.1">
    <localValue xsi:type="ResourceModel:StringValue" value="DependentApp"/>
    <downWardmappedList xsi:type="ResourceModel:App" href="../../NVIC_SCU001/1.0.18/nvic_scu001_0.app#/"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="DependentApp"/>
    <requiredResource uriString="app/nvic_scu001/0" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="function resourceCondition() {&#xD;&#xA;&#x9;&#x9;&#x9;          var XMC1xxx = Solver.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;  &#x9;  if(XMC1xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;  &#x9;  {&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  var Res = Solver.getResource(&quot;wdt001_EventtriggerTemp&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;          var value = Solver.getIntValue(Res);&#xD;&#xA;&#x9;&#x9;&#x9;          if (value == 0)&#xD;&#xA;&#x9;&#x9;&#x9;          {&#xD;&#xA;&#x9;&#x9;&#x9;            return true; &#xD;&#xA;&#x9;&#x9;&#x9;            } &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  }&#xD;&#xA;&#x9;&#x9;&#x9;          return false;&#xD;&#xA;&#x9;&#x9;&#x9;        }" URI="http://www.infineon.com/1.0.18/app/wdt001/0/nvic_sr101">
    <requiredResource uriString="app/nvic_sr101/0" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt/wdt_srv_request" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../WDT/WDT_0.dd#//@provided.1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt/ctr/pre" upWardMappingList="//@provided.2 //@provided.2/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../WDT/WDT_0.dd#//@provided.2"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt/ctr/spw" upWardMappingList="//@provided.4" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../WDT/WDT_0.dd#//@provided.3"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt/ctr/enb" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../WDT/WDT_0.dd#//@provided.4"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt/wlb/wlb" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../WDT/WDT_0.dd#//@provided.5"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt/wub/wub" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="ffffffff"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../WDT/WDT_0.dd#//@provided.6"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="ffffffff"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt/srv/srv" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../WDT/WDT_0.dd#//@provided.7"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt/tim/tim" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../WDT/WDT_0.dd#//@provided.8"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt/wdtsts/alms" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/wdt/wdtclr/almc" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp/clk001_erwwdtclkenable" upWardMappingList="//@provided.4" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <downWardmappedList xsi:type="ResourceModel:EnumerationParameter" href="../../CLK001/1.0.44/clk001_0.app#//@provided.38"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp/clk001_iroactualfreqsystem" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <downWardmappedList xsi:type="ResourceModel:IntegerParameter" href="../../CLK001/1.0.44/clk001_0.app#//@provided.21"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="78"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp/clk001_erwwdtclksource" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <downWardmappedList xsi:type="ResourceModel:EnumerationParameter" href="../../CLK001/1.0.44/clk001_0.app#//@provided.39"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp/clk001_erwwdtclksource/0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <downWardmappedList xsi:type="ResourceModel:EnumItem" href="../../CLK001/1.0.44/clk001_0.app#//@provided.39/@item.0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp/clk001_erwwdtclksource/1" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:EnumItem" href="../../CLK001/1.0.44/clk001_0.app#//@provided.39/@item.1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp/clk001_erwwdtclksource/2" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:EnumItem" href="../../CLK001/1.0.44/clk001_0.app#//@provided.39/@item.2"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp/clk001_erwwdtclkdiv" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <downWardmappedList xsi:type="ResourceModel:IntegerParameter" href="../../CLK001/1.0.44/clk001_0.app#//@provided.40"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp/clk001_irwwdtactualfreq" upWardMappingList="//@provided.6 //@provided.8" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="5dc0"/>
    <downWardmappedList xsi:type="ResourceModel:IntegerParameter" href="../../CLK001/1.0.44/clk001_0.app#//@provided.37"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="5dc0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp/clk001_irwinteroscreffreq" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="18"/>
    <downWardmappedList xsi:type="ResourceModel:IntegerParameter" href="../../CLK001/1.0.44/clk001_0.app#//@provided.16"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="18"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/nvic_sr101/nvic_sr101_erwenableint/0" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/nvic_sr101/nvic_sr101_erwprewarningeventenableint/0" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/clockapp2/clk002_standbyclock" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/wdt001/0/gcu_intprewarn/int" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../SCU/SCU_0.dd#//@provided.56"/>
  </consumed>
  <propertyConstants name="uriDevice" value="device/">
    <propertyConstants name="uriPeri_wdt" value="peripheral/wdt/0/">
      <propertyConstants name="uri_gcu" value="peripheral/scu/0/gcu/">
        <propertyConstants name="uri_clockapp" value="app/clk001/">
          <propertyConstants name="uri_clockapp2" value="app/clk002/">
            <propertyConstants name="uri_resetapp" value="app/reset001/"/>
          </propertyConstants>
        </propertyConstants>
      </propertyConstants>
    </propertyConstants>
  </propertyConstants>
  <categoryDescription description="Basic Applications" name="Basic Applications">
    <subCategory description="Time Processing" name="Time Processing">
      <subCategory description="Timer" name="Timer"/>
    </subCategory>
  </categoryDescription>
  <manifestInfo version="1.0.18">
    <keywords>Window Watchdog Timer</keywords>
    <keywords>WatchDog</keywords>
    <keywords>WDT001</keywords>
    <keywords>Watch Dog</keywords>
    <properties xsi:type="ResourceModel:AppProperties_1_0" initProvider="true" singleton="true"/>
  </manifestInfo>
  <datagenerate fileName="WDT001.h" fileType="HFILE" templateFileName="WDT001.hdt" templateEngine="NONE" fileAction="COPY"/>
  <datagenerate fileName="WDT001.c" templateFileName="WDT001c.jet"/>
  <datagenerate fileName="WDT001_Conf.c" templateFileName="WDT001Confc.jet"/>
  <connections sourceSignal="app/wdt001/0/gcu_intprewarn_int" targetSignal="nvic_scu001/scunode_vs" constraintFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;function resourceCondition(){&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var XMC4xxx = Solver.getSoftwareId().substring(0,1).compareTo(&quot;4&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; &#x9;&#x9;if(XMC4xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; &#x9;&#x9; {&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = Solver.getResource(&quot;wdt001_EventtriggerTemp&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;            var value = Solver.getIntValue(Res);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res1 = Solver.getResource(&quot;wdt001_erwPreWarnEnable/0&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value1 = Solver.getIntValue(Res1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if((value1 == 1) &amp;&amp; (value == 0))&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;   return true;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;  }&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;return false;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;"/>
  <connections sourceSignal="app/wdt001/0/gcu_intprewarn_int" targetSignal="nvic_sr101/scunode_vs" constraintFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;function resourceCondition(){&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var XMC1xxx = Solver.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; &#x9;&#x9;if(XMC1xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; &#x9;&#x9; {&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = Solver.getResource(&quot;wdt001_EventtriggerTemp&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;            var value = Solver.getIntValue(Res);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res1 = Solver.getResource(&quot;wdt001_erwPreWarnEnable/0&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value1 = Solver.getIntValue(Res1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if((value1 == 1) &amp;&amp; (value == 0))&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;   return true;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;  }&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;return false;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;"/>
  <connections sourceSignal="app/wdt001/0/gcu_intprewarn_int" targetSignal="excp001/excp001_nmi_vs" constraintFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;function resourceCondition(){&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var XMC4xxx = Solver.getSoftwareId().substring(0,1).compareTo(&quot;4&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; &#x9;&#x9;&#x9;if(XMC4xxx==0)&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; &#x9;&#x9;&#x9; {&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = Solver.getResource(&quot;wdt001_EventtriggerTemp&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;            var value = Solver.getIntValue(Res);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res1 = Solver.getResource(&quot;wdt001_erwPreWarnEnable/0&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var value1 = Solver.getIntValue(Res1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;if((value1 == 1) &amp;&amp; (value == 1))&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;   return true;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;  }&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;return false;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;"/>
  <softwareIdList>45.0.1</softwareIdList>
  <softwareIdList>45.0.2</softwareIdList>
  <softwareIdList>45.0.3</softwareIdList>
  <softwareIdList>45.2.3</softwareIdList>
  <softwareIdList>45.4.2</softwareIdList>
  <softwareIdList>45.4.3</softwareIdList>
  <softwareIdList>45.0200.1</softwareIdList>
  <softwareIdList>45.0200.2</softwareIdList>
  <softwareIdList>45.0200.3</softwareIdList>
  <softwareIdList>45.0202.3</softwareIdList>
  <softwareIdList>45.0204.2</softwareIdList>
  <softwareIdList>45.0204.3</softwareIdList>
  <softwareIdList>44.0.3</softwareIdList>
  <softwareIdList>44.00.5</softwareIdList>
  <softwareIdList>44.02.3</softwareIdList>
  <softwareIdList>44.02.5</softwareIdList>
  <softwareIdList>42.00.5</softwareIdList>
  <softwareIdList>42.0.6</softwareIdList>
  <softwareIdList>42.04.5</softwareIdList>
  <softwareIdList>42.04.6</softwareIdList>
  <softwareIdList>11.0100.7</softwareIdList>
  <softwareIdList>11.0100.9</softwareIdList>
  <softwareIdList>12.0100.7</softwareIdList>
  <softwareIdList>12.0101.7</softwareIdList>
  <softwareIdList>12.0102.9</softwareIdList>
  <softwareIdList>12.0102.8</softwareIdList>
  <softwareIdList>13.0102.7</softwareIdList>
  <softwareIdList>13.0101.9</softwareIdList>
  <softwareIdList>13.0101.7</softwareIdList>
  <softwareIdList>42.0200.5</softwareIdList>
  <softwareIdList>42.0204.5</softwareIdList>
  <softwareIdList>42.0204.6</softwareIdList>
  <softwareIdList>42.0200.6</softwareIdList>
  <softwareIdList>42.0208.6</softwareIdList>
  <softwareIdList>44.0200.5</softwareIdList>
  <softwareIdList>44.0202.3</softwareIdList>
  <softwareIdList>44.0202.5</softwareIdList>
  <softwareIdList>44.0200.3</softwareIdList>
  <softwareIdList>45.0300.1</softwareIdList>
  <softwareIdList>45.0300.3</softwareIdList>
  <softwareIdList>45.0302.3</softwareIdList>
  <softwareIdList>45.0304.2</softwareIdList>
  <softwareIdList>45.0300.2</softwareIdList>
  <softwareIdList>45.0304.3</softwareIdList>
  <softwareIdList>11.0100.10</softwareIdList>
  <softwareIdList>11.0100.11</softwareIdList>
  <softwareIdList>12.0101.11</softwareIdList>
  <softwareIdList>12.0102.10</softwareIdList>
  <softwareIdList>12.0102.11</softwareIdList>
  <softwareIdList>13.0101.10</softwareIdList>
  <softwareIdList>13.0101.11</softwareIdList>
  <softwareIdList>13.0102.10</softwareIdList>
  <softwareIdList>13.0102.11</softwareIdList>
  <softwareIdList>13.0102.9</softwareIdList>
</ResourceModel:App>
