{
  "id" : 1554234501483,
  "name" : "ParsingTestMaster",
  "comment" : null,
  "relativeDirectory" : "TestPlans4Parsing",
  "variables" : [ {
    "id" : 1554234508051,
    "name" : "Var1",
    "comment" : "MISSING_COMMENT",
    "variableType" : null
  }, {
    "id" : 1554234511544,
    "name" : "Var2",
    "comment" : "MISSING_COMMENT",
    "variableType" : null
  }, {
    "id" : 1554234514877,
    "name" : "Var3",
    "comment" : "MISSING_COMMENT",
    "variableType" : null
  } ],
  "masterPlan" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : {
    "id" : 1554289445396,
    "name" : "1554289445396",
    "comment" : null,
    "enabled" : true,
    "conditionString" : null,
    "pluginName" : "DefaultPlugin",
    "variables" : [ 1554234508051, 1554234511544, 1554234514877 ],
    "quantifiers" : [ {
      "id" : 1554289489406,
      "name" : "NEW_QUANTIFIER",
      "comment" : "MISSING_COMMENT",
      "quantifierType" : "ALL",
      "scope" : 1554234522334,
      "sorts" : [ "y" ]
    }, {
      "id" : 1554289499009,
      "name" : "NEW_QUANTIFIER",
      "comment" : "MISSING_COMMENT",
      "quantifierType" : "ALL",
      "scope" : 1554234527864,
      "sorts" : [ "z" ]
    }, {
      "id" : 1554289460359,
      "name" : "NEW_QUANTIFIER",
      "comment" : "MISSING_COMMENT",
      "quantifierType" : "ALL",
      "scope" : 1554234501483,
      "sorts" : [ "X" ]
    } ]
  },
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1554234527864,
    "name" : "Ep",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "ServiceRobotsTasks.tsk#1528875085489",
    "state" : 1554234522334,
    "plan" : 1554234501483
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1554234522334,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : 1554234527864,
    "parentPlan" : 1554234501483,
    "abstractPlans" : [ "ServiceRobots/PutDown.pml#1553186313956", "TestPlans4Parsing/PT1.pty#1554119168374", "ServiceRobots/Behaviours/DriveToPOI.beh#1553249791474" ],
    "variableBindings" : [ {
      "id" : 1554234562783,
      "name" : "1554234562783",
      "comment" : null,
      "variable" : 1554234508051,
      "subPlan" : "ServiceRobots/PutDown.pml#1553186313956",
      "subVariable" : "ServiceRobots/PutDown.pml#1553506241307"
    }, {
      "id" : 1554234569612,
      "name" : "1554234569612",
      "comment" : null,
      "variable" : 1554234511544,
      "subPlan" : "TestPlans4Parsing/PT1.pty#1554119168374",
      "subVariable" : "TestPlans4Parsing/PT1.pty#1554219723962"
    }, {
      "id" : 1554234575012,
      "name" : "1554234575012",
      "comment" : null,
      "variable" : 1554234514877,
      "subPlan" : "ServiceRobots/Behaviours/DriveToPOI.beh#1553249791474",
      "subVariable" : "ServiceRobots/Behaviours/DriveToPOI.beh#1554219723963"
    } ],
    "outTransitions" : [ ],
    "inTransitions" : [ ]
  } ],
  "transitions" : [ ],
  "synchronisations" : [ ]
}