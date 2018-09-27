<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1470041057806" name="ASPFindFreeDockingStationMaster" comment="" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647" masterPlan="true" utilityFunction="" utilityThreshold="0.1">
  <vars id="1470043579268" name="DockingStationVar" comment="" Type=""/>
  <runtimeCondition id="1470042926317" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>Serve/ASPFindFreeDockingStationMaster.pml#1470043579268</vars>
  </runtimeCondition>
  <states id="1470041057808" name="SearchForFreeDockingStation" comment="" entryPoint="1470041057809">
    <parametrisation id="1470043878556" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/SearchForDockingStationAsp.beh#1470041810334</subplan>
      <subvar>Behaviours/SearchForDockingStationAsp.beh#1470043788379</subvar>
      <var>Serve/ASPFindFreeDockingStationMaster.pml#1470043579268</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">Behaviours/SearchForDockingStationAsp.beh#1470041810334</plans>
    <outTransitions>Serve/ASPFindFreeDockingStationMaster.pml#1470041207327</outTransitions>
  </states>
  <states id="1470041204046" name="Charge" comment="">
    <plans xsi:type="alica:Behaviour">Behaviours/ChargingDefault.beh#1447958115909</plans>
    <inTransitions>Serve/ASPFindFreeDockingStationMaster.pml#1470041207327</inTransitions>
    <outTransitions>Serve/ASPFindFreeDockingStationMaster.pml#1470042247718</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1470042244415" name="NewSuccessState" comment="">
    <inTransitions>Serve/ASPFindFreeDockingStationMaster.pml#1470042247718</inTransitions>
  </states>
  <transitions id="1470041207327" name="MISSING_NAME" comment="docked | fully charged (child success)" msg="">
    <preCondition id="1470041208746" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/ASPFindFreeDockingStationMaster.pml#1470041057808</inState>
    <outState>Serve/ASPFindFreeDockingStationMaster.pml#1470041204046</outState>
  </transitions>
  <transitions id="1470042247718" name="MISSING_NAME" comment="accu full" msg="">
    <preCondition id="1470042249132" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/ASPFindFreeDockingStationMaster.pml#1470041204046</inState>
    <outState>Serve/ASPFindFreeDockingStationMaster.pml#1470042244415</outState>
  </transitions>
  <entryPoints id="1470041057809" name="MISSING_NAME" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>taskrepository.tsk#1414681164704</task>
    <state>Serve/ASPFindFreeDockingStationMaster.pml#1470041057808</state>
  </entryPoints>
</alica:Plan>