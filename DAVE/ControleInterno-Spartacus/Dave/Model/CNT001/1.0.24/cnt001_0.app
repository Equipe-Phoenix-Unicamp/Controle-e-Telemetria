<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="CNT001" description="This App counts the number of &#xA; external events on the input pin. &#xA; Event can be Rising egde, &#xA; Falling egde or both edges.&#xA;Compare match interrupt can be &#xA; enabled for event count match. &#xA; Period match interrupt can be &#xA; enabled to count the rollovers." descriptionURL="/doc/html/group___c_n_t001.html" URI="http://www.infineon.com/1.0.24/app/cnt001/0" userLabel="LocalCounter">
  <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../PWMSP001/1.0.34/pwmsp001_0.app#//@consumed.97"/>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Global" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_globalsignal_vs" requiredSignalResource="slice/global_signal">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Input" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_input_vs" requiredSignalResource="slice/gp0_unsync">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Gating" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_gate_vs" requiredSignalResource="slice/gp1_unsync">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Status" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_output_vs" requiredSignalResource="slice/st">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Event Edge Interrupt" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_evtedgetinterrupt_vs" requiredSignalResource="slice/e0as">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Event Count Match Interrupt" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_comparematch_vs" requiredSignalResource="slice/cmds_cmus">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Gating Interrupt" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_gateinterrupt_vs" requiredSignalResource="slice/e1as">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Rollover Interrupt" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_periodmatch_vs" requiredSignalResource="slice/pmus_omds">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Active Edge for Counting" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_activecountingedge" downWardmappedList="//@consumed.16">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <toolTipHelpDescription>This allows the user to select the active edge for counting external signal</toolTipHelpDescription>
    <item name="Rising Edge" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value === 0){&#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == -1) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);                &#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 2){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 3){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }    &#xD;&#xA;                  &#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_activecountingedge/0" downWardmappedList="//@consumed.16" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Every Rising edge of the input signal is counted.</toolTipHelpDescription>
    </item>
    <item name="Falling Edge " evalFunction="            &#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value === 0){&#xD;&#xA;              }else if(value === 1){&#xD;&#xA;                SCM.setIntValue(Res,2);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == -1) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);                &#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 2){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 3){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }    &#xD;&#xA;                  &#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_activecountingedge/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Every Falling edge of the input signal is counted</toolTipHelpDescription>
    </item>
    <item name="Both Edges" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value === 0){&#xD;&#xA;              }else if(value === 1){&#xD;&#xA;                SCM.setIntValue(Res,3);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == -1) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);                &#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 2){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 3){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }    &#xD;&#xA;                  &#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_activecountingedge/2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Both the edges of the input signal are counted.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Gating signal Configuration" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempgating&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempgating&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_externalgating" downWardmappedList="//@consumed.0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <toolTipHelpDescription>This allows user to configure the gating signal level to enable counting</toolTipHelpDescription>
    <item name="Disable" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempgating&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;              &#x9;SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;              else&#xD;&#xA;              {&#xD;&#xA;              &#x9;SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempgating&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if(value == 1){              &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else{&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_externalgating/0" downWardmappedList="//@consumed.0" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Gating is disabled</toolTipHelpDescription>
    </item>
    <item name="Gating Level High" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev1lm&quot;); &#xD;&#xA;              var Res1 = SCM.getResource(&quot;cnt001_tempgating&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;&#x9;&#x9;&#x9;  if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;                SCM.setIntValue(Res1,2);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempgating&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == 2) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);                &#xD;&#xA;              }else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_externalgating/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Gating signal is active high</toolTipHelpDescription>
    </item>
    <item name="Gating Level Low" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/evlm&quot;); &#xD;&#xA;              var Res1 = SCM.getResource(&quot;cnt001_tempgating&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;&#x9;&#x9;&#x9; if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;                SCM.setIntValue(Res1,3);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempgating&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == 3) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_externalgating/2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Gating signal is active low</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Configuration of the Low Pass filter" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_lpfconfig" downWardmappedList="//@consumed.17">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows the user to configure LPF filtering on the input. The number of cycles are the CCU Clock cycles.</toolTipHelpDescription>
    <item name="Disable" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;                var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value === 0){&#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == -1) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);                &#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 2){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 3){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_lpfconfig/0" downWardmappedList="//@consumed.17" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>LPF Disabled</toolTipHelpDescription>
    </item>
    <item name="3 CCU cycles" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value === 0){&#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == -1) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);                &#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 2){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 3){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_lpfconfig/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>3 cycles for LPF</toolTipHelpDescription>
    </item>
    <item name="5 CCU cycles" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value === 0){&#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,2);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == -1) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);                &#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 2){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 3){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_lpfconfig/2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>5 cycles for LPF</toolTipHelpDescription>
    </item>
    <item name="7 CCU cycles" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value === 0){&#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,3);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == -1) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);                &#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 2){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else if(value == 3){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_lpfconfig/3" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>7 cycles for LPF</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Start" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempstart&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempstart&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_erwstart" downWardmappedList="//@consumed.1" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows user to configure whether this app should be started&#xD;
during initialization. The start of App means CCU slice is ready to count the configured edges.</toolTipHelpDescription>
    <item name="Start During initialization" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempstart&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;              else{&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempstart&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if(value == 1){ &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else if(value == -1){ &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else { &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_erwstart/0" downWardmappedList="//@consumed.1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Start the app during Initialization.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Count Match Interrupt" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempcountmatch&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempcountmatch&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_erwcountmatch" downWardmappedList="//@consumed.3" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <toolTipHelpDescription>This allows user to configure whether compare match interrupt&#xD;
to be enabled during initialization.</toolTipHelpDescription>
    <item name="Enable at initialization" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempcountmatch&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempcountmatch&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if(value == 1){ &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else if(value == -1){ &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else { &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_erwcountmatch/0" downWardmappedList="//@consumed.3" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Enable Event Count Match (Compare match) interrupt at initialization.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Rollover Interrupt" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_temprollover&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_temprolllover&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_erwrollover" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
    <toolTipHelpDescription>This allows user to configure whether period match interrupt&#xD;
to be enabled during initialization.</toolTipHelpDescription>
    <item name="Enable at initialization" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_temprolllover&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_temprolllover&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if(value == 1){ &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else if(value == -1){ &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else { &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_erwrollover/0" downWardmappedList="//@consumed.2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Enable Rollover (period match) interrupt at initialization.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Gating Interrupt" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempgatingint&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempgatingint&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_erwgating" downWardmappedList="//@consumed.4" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows user to configure whether gating interrupt&#xD;
to be enabled during initialization.</toolTipHelpDescription>
    <item name="Enable at initialization" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempgatingint&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempgatingint&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if(value == 1){ &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else if(value == -1){ &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else { &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_erwgating/0" downWardmappedList="//@consumed.4" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Enable gating (Event 1) interrupt at initialization.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Event edge Interrupt" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempevtedge&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempevtedge&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_erweventedge" downWardmappedList="//@consumed.5" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <toolTipHelpDescription>This allows user to configure whether input event interrupt&#xD;
to be enabled during initialization.</toolTipHelpDescription>
    <item name="Enable at initialization" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempevtedge&quot;);&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;cnt001_tempevtedge&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if(value == 1){ &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else if(value == -1){ &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else { &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;          " URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_erweventedge/0" downWardmappedList="//@consumed.5" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Enable input event edge (Event 0) interrupt at initialization.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Count match" evalFunction="&#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;            var value = SCM.getIntValue(currentResource);&#xD;&#xA;            var Res0 = SCM.getResource(&quot;slice/crs/crs&quot;);&#xD;&#xA;            SCM.setIntValue(Res0, value);&#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;            var Res0 = SCM.getResource(&quot;slice/crs/crs&quot;);&#xD;&#xA;            var value = SCM.getIntValue(Res0);&#xD;&#xA;            SCM.setIntValue(currentResource, value);            &#xD;&#xA;          }&#xD;&#xA;" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_countmatch" downWardmappedList="//@consumed.34" maxValue="FFFF" minValue="1">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="7D0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="1e"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1e"/>
    <toolTipHelpDescription>This allows user to configure the count match value for the App. Range: 1- 65535</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function is used to initialize the APP" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_init" APIName="CNT001_Init">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This will reset the CCU4_CCy slice registers to default state." URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_deinit" APIName="CNT001_Deinit">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This API will start the App" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_start" APIName="CNT001_Start">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This API will stop the App" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_stop" APIName="CNT001_Stop">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This API will get the current count value" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_getevtcountvalue" APIName="CNT001_GetEvtCountValue">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This will get the current value of the count match" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_getcountmatch" APIName="CNT001_GetCountMatch">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This API will set the new value for the count match parameter" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_setcountmatch" APIName="CNT001_SetCountMatch">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This API returns the current status of the timer" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_gettimerstatus" APIName="CNT001_GetTimerStatus">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will enable the event." URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_enableevent" APIName="CNT001_EnableEvent">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will disable the event." URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_disableevent" APIName="CNT001_DisableEvent">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will reset the event." URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_clearpendingevent" APIName="CNT001_ClearPendingEvent">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will enable the event." URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_setpendingevent" APIName="CNT001_SetPendingEvent">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will check whether given event is set." URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_getpendingevent" APIName="CNT001_GetPendingEvent">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_tempgating" upWardMappingList="//@provided.9 //@provided.9/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_tempstart" upWardMappingList="//@provided.11 //@provided.11/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_temprolllover" upWardMappingList="//@provided.13/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_tempcountmatch" upWardMappingList="//@provided.12 //@provided.12/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_tempgatingint" upWardMappingList="//@provided.14 //@provided.14/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/cnt001_tempevtedge" upWardMappingList="//@provided.15 //@provided.15/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice">
    <downWardmappedList xsi:type="ResourceModel:ResourceGroup" href="../../CCU40/CCU40_0.dd#//@provided.3"/>
    <requiredResource uriString="peripheral/ccu4/*/cc4/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/ccu4globalapp">
    <downWardmappedList xsi:type="ResourceModel:App" href="../../CCU4GLOBAL/1.0.22/ccu4global_0.app#/"/>
    <requiredResource uriString="app/ccu4global/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/cmds_cmus" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU40/CCU40_0.dd#//@provided.4"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/st" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU40/CCU40_0.dd#//@provided.5"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/gidls_ssi" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.6"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/gidlc_csi" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.7"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/gcss_sse" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.8"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/gcss_sdse" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.9"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/gcss_spse" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.10"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/ins" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.11"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/ins/ev0em" upWardMappingList="//@provided.8 //@provided.8/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.11/@bitFields.3"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/ins/lpf0m" upWardMappingList="//@provided.10 //@provided.10/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.11/@bitFields.9"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/ins/ev1lm" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.11/@bitFields.7"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/cmc" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.12"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/tcst" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.13"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/tcset" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.14"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/tcclr" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.15"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/tc" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.16"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/psl" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.17"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/dit" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.18"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/dits" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.19"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/psc" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.20"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/fpc" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.21"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/fpcs" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.22"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/pr" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.23"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/prs" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.24"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/cr" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.25"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/crs" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.26"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/crs/crs" upWardMappingList="//@provided.16" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1e"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.26/@bitFields.0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1e"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/timer" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.27"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/c0v" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.28"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/c1v" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.29"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/c2v" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.30"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/c3v" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.31"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/ints" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.32"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/inte" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.33"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/inte/pme" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.33/@bitFields.0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/inte/cmue" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.33/@bitFields.2"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/inte/e1ae" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU40/CCU40_0.dd#//@provided.33/@bitFields.5"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/srs" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.34"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/sws" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.35"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/swr" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU40/CCU40_0.dd#//@provided.36"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/ccu4globalapp/ccu4global_irclock" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <downWardmappedList xsi:type="ResourceModel:IntegerParameter" href="../../CCU4GLOBAL/1.0.22/ccu4global_0.app#//@provided.2"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="78"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/gp1_unsync" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU40/CCU40_0.dd#//@provided.37"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/global_signal" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU40/CCU40_0.dd#//@provided.38"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/e0as" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU40/CCU40_0.dd#//@provided.39"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/pmus_omds" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU40/CCU40_0.dd#//@provided.40"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/gp0_unsync" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU40/CCU40_0.dd#//@provided.41"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cnt001/0/slice/e1as" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU40/CCU40_0.dd#//@provided.42"/>
  </consumed>
  <propertyConstants name="uridevice" value="device">
    <propertyConstants name="uriPeri_CCU4" value="peripheral/ccu4/">
      <propertyConstants name="uricnt001App" value="app/cnt001/"/>
    </propertyConstants>
  </propertyConstants>
  <categoryDescription description="Peripheral related Apps" name="Peripheral Specific Apps">
    <subCategory description="Timer-Capture-Compare" name="Timer-Capture-Compare">
      <subCategory description="CAPCOM4" name="Capture/Compare Unit 4 (CAPCOM4)"/>
    </subCategory>
  </categoryDescription>
  <categoryDescription description="Basic Applications" name="Basic Applications">
    <subCategory description="Apps related to Capture/Compare" name="Time Processing">
      <subCategory description="Signal Capture" name="Signal Capture"/>
    </subCategory>
  </categoryDescription>
  <manifestInfo version="1.0.22">
    <keywords>Event Counter</keywords>
    <keywords>CCU4 External Count</keywords>
    <keywords>CNT001</keywords>
    <keywords>Counter</keywords>
    <properties xsi:type="ResourceModel:AppProperties_1_0" initProvider="true"/>
  </manifestInfo>
  <datagenerate fileName="CNT001.c" templateFileName="CNT001c.jet"/>
  <datagenerate fileName="CNT001.h" fileType="HFILE" templateFileName="CNT001.hdt" templateEngine="NONE" fileAction="COPY"/>
  <datagenerate fileName="CNT001_Conf.c" templateFileName="CNT001Confc.jet"/>
  <datagenerate fileName="CNT001_Conf.h" fileType="HFILE" templateFileName="CNT001Confh.jet"/>
  <connections sourceSignal="ccu4globalapp/ccu4global_globalsignal_vs" targetSignal="app/cnt001/0/cnt001_globalsignal_vs"/>
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
  <softwareIdList>45.0204.3</softwareIdList>
  <softwareIdList>45.0204.2</softwareIdList>
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
