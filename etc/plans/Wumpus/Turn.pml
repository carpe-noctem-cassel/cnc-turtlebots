<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1489674129255" name="Turn" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Wumpus" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1489674153775" name="NewState" comment="" entryPoint="1489674153776">
    <outTransitions>#1489674256879</outTransitions>
    <outTransitions>#1489674310751</outTransitions>
    <outTransitions>#1489674362167</outTransitions>
    <outTransitions>#1489674397808</outTransitions>
  </states>
  <states id="1489674243749" name="Move" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Wumpus/Move.beh#1489674705705</plans>
    <inTransitions>#1489674256879</inTransitions>
    <outTransitions>#1489746560731</outTransitions>
  </states>
  <states id="1489674300902" name="PickUp" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Wumpus/Wumpus.beh#1489674671969</plans>
    <inTransitions>#1489674310751</inTransitions>
    <outTransitions>#1489746557017</outTransitions>
  </states>
  <states id="1489674354389" name="Shoot" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Wumpus/Shoot.beh#1489674687663</plans>
    <inTransitions>#1489674362167</inTransitions>
    <outTransitions>#1489746558972</outTransitions>
  </states>
  <states id="1489674390527" name="Leave" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Wumpus/Leave.beh#1489674658684</plans>
    <inTransitions>#1489674397808</inTransitions>
    <outTransitions>#1489746554764</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1489746552131" name="NewSuccessState" comment="">
    <inTransitions>#1489746554764</inTransitions>
    <inTransitions>#1489746557017</inTransitions>
    <inTransitions>#1489746558972</inTransitions>
    <inTransitions>#1489746560731</inTransitions>
  </states>
  <transitions id="1489674256879" name="MISSING_NAME" comment="No Stench and no breeze and no gold" msg="">
    <preCondition id="1489674258430" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489674153775</inState>
    <outState>#1489674243749</outState>
  </transitions>
  <transitions id="1489674310751" name="MISSING_NAME" comment="Gold on current tile" msg="">
    <preCondition id="1489674311741" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489674153775</inState>
    <outState>#1489674300902</outState>
  </transitions>
  <transitions id="1489674362167" name="MISSING_NAME" comment="Have arrow and wumpus close" msg="">
    <preCondition id="1489674364780" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489674153775</inState>
    <outState>#1489674354389</outState>
  </transitions>
  <transitions id="1489674397808" name="MISSING_NAME" comment="Have gold and on own exit" msg="">
    <preCondition id="1489674399440" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489674153775</inState>
    <outState>#1489674390527</outState>
  </transitions>
  <transitions id="1489746554764" name="MISSING_NAME" comment="succ" msg="">
    <preCondition id="1489746556848" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489674390527</inState>
    <outState>#1489746552131</outState>
  </transitions>
  <transitions id="1489746557017" name="MISSING_NAME" comment="succ" msg="">
    <preCondition id="1489746558803" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489674300902</inState>
    <outState>#1489746552131</outState>
  </transitions>
  <transitions id="1489746558972" name="MISSING_NAME" comment="succ" msg="">
    <preCondition id="1489746560602" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489674354389</inState>
    <outState>#1489746552131</outState>
  </transitions>
  <transitions id="1489746560731" name="MISSING_NAME" comment="succ" msg="">
    <preCondition id="1489746562418" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489674243749</inState>
    <outState>#1489746552131</outState>
  </transitions>
  <entryPoints id="1489674153776" name="MISSING_NAME" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1489674153775</state>
  </entryPoints>
</alica:Plan>
