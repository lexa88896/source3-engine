/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2014 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

// Behavior specific product patches applied to release 2010_1.
// This file is #included by hkbPatches_2010_1.cpp

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbHandIkDriverInfo", 0)
    HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
    HK_PATCH_MEMBER_ADDED("hands", TYPE_ARRAY_STRUCT, "hkbHandIkDriverInfoHand", 0)
    HK_PATCH_MEMBER_ADDED_INT("fadeInOutCurve", 0)
    HK_PATCH_DEPENDS("hkBaseObject", 0)
    HK_PATCH_DEPENDS("hkbHandIkDriverInfoHand", 0)
    HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbHandIkDriverInfoHand", 0)
    HK_PATCH_MEMBER_ADDED_VEC_4("elbowAxisLS", 0.000000f,0.000000f,0.000000f,0.000000f)
    HK_PATCH_MEMBER_ADDED_VEC_4("backHandNormalLS", 0.000000f,0.000000f,0.000000f,0.000000f)
    HK_PATCH_MEMBER_ADDED_VEC_4("handOffsetLS", 0.000000f,0.000000f,0.000000f,0.000000f)
    HK_PATCH_MEMBER_ADDED_VEC_4("handOrienationOffsetLS", 0.000000f,0.000000f,0.000000f,1.000000f)
    HK_PATCH_MEMBER_ADDED_REAL("maxElbowAngleDegrees", 180.000000f)
    HK_PATCH_MEMBER_ADDED_REAL("minElbowAngleDegrees", 0.000000f)
    HK_PATCH_MEMBER_ADDED_INT("shoulderIndex", -1)
    HK_PATCH_MEMBER_ADDED_INT("shoulderSiblingIndex", -1)
    HK_PATCH_MEMBER_ADDED_INT("elbowIndex", -1)
    HK_PATCH_MEMBER_ADDED_INT("elbowSiblingIndex", -1)
    HK_PATCH_MEMBER_ADDED_INT("wristIndex", -1)
    HK_PATCH_MEMBER_ADDED_BYTE("enforceEndPosition", 1)
    HK_PATCH_MEMBER_ADDED_BYTE("enforceEndRotation", 0)
    HK_PATCH_MEMBER_ADDED_CSTRING("localFrameName", HK_NULL)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbHandIkControlData", 1, "hkbHandIkControlData", 2)
    HK_PATCH_MEMBER_ADDED_POINTER("targetHandle", "hkbHandle", 0)
	HK_PATCH_MEMBER_RENAMED("positionOnFraction", "transformOnFraction")
    HK_PATCH_MEMBER_ADDED_REAL("extrapolationTimeStep", 0.000000f)
    HK_PATCH_MEMBER_ADDED_REAL("handleChangeSpeed", 1.000000f)
    HK_PATCH_MEMBER_ADDED_INT("handleChangeMode", 0)
	HK_PATCH_MEMBER_ADDED_BYTE("fixUp", 0)
    HK_PATCH_DEPENDS("hkBaseObject", 0)
    HK_PATCH_DEPENDS("hkbHandle", 1)
    HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterData", 6, "hkbCharacterData", 7)
    HK_PATCH_MEMBER_ADDED("handIkDriverInfo", TYPE_OBJECT, "hkbHandIkDriverInfo", 0)
    HK_PATCH_DEPENDS("hkbHandIkDriverInfo", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbSceneModifierListSceneModifierEntry", 0, "hkbSceneModifierListSceneModifierEntry", 1)
	HK_PATCH_MEMBER_REMOVED("postSceneModifier", TYPE_OBJECT, "hkbModifier",0)
	HK_PATCH_DEPENDS("hkbNode", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkbModifier", 0)
	HK_PATCH_DEPENDS("hkbBindable", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbLookAtModifier", 1, "hkbLookAtModifier", 2)
	HK_PATCH_MEMBER_ADDED_VEC_4("eyePositionHS", 0.000000f,0.000000f,0.000000f,0.000000f)
	HK_PATCH_MEMBER_ADDED("isTargetInsideLimitCone", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbJigglerModifier", 0, "hkbJigglerModifier", 1)
	HK_PATCH_MEMBER_ADDED_INT("jiggleCoordinates", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbEventBase", 0)
	HK_PATCH_MEMBER_ADDED_INT("id", -1)
	HK_PATCH_MEMBER_ADDED("payload", TYPE_OBJECT, "hkbEventPayload", 0)
	HK_PATCH_DEPENDS("hkbEventPayload", 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbEventProperty", 0, "hkbEventProperty", 1)
	HK_PATCH_PARENT_SET("hkbEvent", "hkbEventBase")
HK_PATCH_END()

HK_PATCH_BEGIN("hkbEvent", 0, "hkbEvent", 1)
	HK_PATCH_PARENT_SET(HK_NULL, "hkbEventBase")
	HK_PATCH_MEMBER_REMOVED("id", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("payload", TYPE_OBJECT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbStateMachineEventPropertyArray", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("events", TYPE_ARRAY_STRUCT, "hkbEventProperty", 0 )
	HK_PATCH_DEPENDS("hkbEventProperty", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkbEventBase", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbStateMachineStateInfo", 3, "hkbStateMachineStateInfo", 4)
	HK_PATCH_MEMBER_ADDED("enterNotifyEvents", TYPE_OBJECT, "hkbStateMachineEventPropertyArray", 0)
	HK_PATCH_MEMBER_ADDED("exitNotifyEvents", TYPE_OBJECT, "hkbStateMachineEventPropertyArray", 0)
	HK_PATCH_FUNCTION(hkbStateMachineStateInfo_3_to_4)
	HK_PATCH_MEMBER_REMOVED("enterNotifyEvent", TYPE_STRUCT, "hkbEventProperty", 0)
	HK_PATCH_MEMBER_REMOVED("exitNotifyEvent", TYPE_STRUCT, "hkbEventProperty", 0)
	HK_PATCH_DEPENDS("hkbEventProperty", 1)
	HK_PATCH_DEPENDS("hkbEventBase", 0)
	HK_PATCH_DEPENDS("hkbStateMachineEventPropertyArray", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbPoseMatchingGenerator", 1, "hkbPoseMatchingGenerator", 2)
	HK_PATCH_MEMBER_ADDED_INT("startMatchingEventId", -1)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbStateMachineDelayedTransitionInfo", 0, "hkbStateMachineDelayedTransitionInfo", 1)
	HK_PATCH_MEMBER_ADDED("timeDelayed", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbCharacterSteppedInfo", 0)
    HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
    HK_PATCH_MEMBER_ADDED("characterId", TYPE_INT, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("deltaTime", TYPE_REAL, HK_NULL, 0)
    HK_PATCH_DEPENDS("hkBaseObject", 0)
    HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbEventRaisedInfo", 0, "hkbEventRaisedInfo", 1)
	HK_PATCH_MEMBER_ADDED("senderId", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbLookAtModifier", 2, "hkbLookAtModifier", 3)
	HK_PATCH_MEMBER_RENAMED("headForwardHS", "headForwardLS")
	HK_PATCH_MEMBER_RENAMED("headRightHS", "neckRightLS")
    HK_PATCH_MEMBER_ADDED_VEC_4("neckForwardLS", 0.000000f,1.000000f,0.000000f,0.000000f)
	HK_PATCH_FUNCTION(hkbLookAtModifier_2_to_3)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbBehaviorInfoIdToNamePair", 0)
	HK_PATCH_MEMBER_ADDED("behaviorName", TYPE_CSTRING, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("nodeName", TYPE_CSTRING, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("toolType", TYPE_BYTE, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("id", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbBehaviorInfo", 0, "hkbBehaviorInfo", 1)
	HK_PATCH_MEMBER_ADDED("idToNamePairs", TYPE_ARRAY_STRUCT, "hkbBehaviorInfoIdToNamePair", 0)
	HK_PATCH_DEPENDS("hkbBehaviorInfoIdToNamePair", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbDemoConfigCharacterInfo", 2, "hkbDemoConfigCharacterInfo", 3)
	HK_PATCH_MEMBER_RENAMED("characterDataFilename", "overrideCharacterDataFilename")
	HK_PATCH_MEMBER_RENAMED("behaviorFilename", "overrideBehaviorFilename")
HK_PATCH_END()

HK_PATCH_BEGIN("hkbRigidBodyRagdollControlData", 0, "hkbRigidBodyRagdollControlData", 1)
	HK_PATCH_MEMBER_DEFAULT_SET_REAL("durationToBlend", 0.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbActiveNodesInfo", 0, "hkbActiveNodesInfo", 1)
	HK_PATCH_MEMBER_REMOVED("activeNodes", TYPE_ARRAY_STRUCT, "hkbActiveNodesInfoActiveNode", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbActiveNodesInfo", 1, HK_NULL, HK_CLASS_REMOVED)
   HK_PATCH_PARENT_SET("hkReferencedObject", HK_NULL)
   HK_PATCH_MEMBER_REMOVED("characterId", TYPE_INT, HK_NULL, 0)
   HK_PATCH_MEMBER_REMOVED("activeEventIds", TYPE_ARRAY_INT, HK_NULL, 0)
   HK_PATCH_MEMBER_REMOVED("activeVariableIds", TYPE_ARRAY_INT, HK_NULL, 0)
   HK_PATCH_DEPENDS("hkBaseObject", 0)
   HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbActiveNodesInfoActiveNode", 0, HK_NULL, HK_CLASS_REMOVED)
   HK_PATCH_MEMBER_REMOVED("nodeName", TYPE_CSTRING, HK_NULL, 0)
   HK_PATCH_MEMBER_REMOVED("userData0", TYPE_INT, HK_NULL, 0)
   HK_PATCH_MEMBER_REMOVED("userData1", TYPE_INT, HK_NULL, 0)
   HK_PATCH_MEMBER_REMOVED("id", TYPE_INT, HK_NULL, 0)
   HK_PATCH_MEMBER_REMOVED("type", TYPE_BYTE, HK_NULL, 0)
   HK_PATCH_MEMBER_REMOVED("depth", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbBlendingTransitionEffect", 0, "hkbBlendingTransitionEffect", 1)
	HK_PATCH_MEMBER_DEFAULT_SET_INT("flags", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbCharacterAddedInfo", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("characterId", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("instanceName", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("templateName", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("fullPathToProject", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("skeleton", TYPE_OBJECT, "hkaSkeleton", 0)
	HK_PATCH_MEMBER_ADDED("worldFromModel", TYPE_VEC_12, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("poseModelSpace", TYPE_ARRAY_VEC_12, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkaSkeleton", 3)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterSteppedInfo", 0, "hkbCharacterSteppedInfo", 1)
	HK_PATCH_MEMBER_ADDED("worldFromModel", TYPE_VEC_12, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("poseModelSpace", TYPE_ARRAY_VEC_12, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterInfo", 0, "hkbCharacterInfo", 1)
	HK_PATCH_MEMBER_REMOVED("instanceName", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("templateName", TYPE_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("fullPathToProject", TYPE_CSTRING, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterSkinInfo", 0, "hkbCharacterSkinInfo", 1)
	HK_PATCH_MEMBER_ADDED("hasRagdoll", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbExpressionCondition", 0, "hkbExpressionCondition", 1)
	HK_PATCH_MEMBER_REMOVED("compiledExpressionSet", TYPE_OBJECT, "hkbCompiledExpressionSet", 0)
	HK_PATCH_DEPENDS("hkbCompiledExpressionSet", 1)
HK_PATCH_END()
HK_PATCH_BEGIN("hkbEvaluateExpressionModifier", 0, "hkbEvaluateExpressionModifier", 1)
	HK_PATCH_MEMBER_REMOVED("compiledExpressionSet", TYPE_OBJECT, "hkbCompiledExpressionSet", 0)
	HK_PATCH_DEPENDS("hkbCompiledExpressionSet", 1)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbHandIkDriverInfoHand", 0, "hkbHandIkDriverInfoHand", 1)
	HK_PATCH_MEMBER_DEFAULT_SET_VEC_4("elbowAxisLS", 0.000000f,1.000000f,0.000000f,0.000000f)
	HK_PATCH_MEMBER_DEFAULT_SET_VEC_4("backHandNormalLS", 0.000000f,1.000000f,0.000000f,0.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbHandIkModifierHand", 2, "hkbHandIkModifierHand", 3)
	HK_PATCH_MEMBER_DEFAULT_SET_VEC_4("elbowAxisLS", 0.000000f,1.000000f,0.000000f,0.000000f)
	HK_PATCH_MEMBER_DEFAULT_SET_VEC_4("backHandNormalLS", 0.000000f,1.000000f,0.000000f,0.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterStringData", 4, "hkbCharacterStringData", 5)
	HK_PATCH_MEMBER_ADDED("mirroredSyncPointSubstringsA", TYPE_ARRAY_CSTRING, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("mirroredSyncPointSubstringsB", TYPE_ARRAY_CSTRING, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbPoweredRagdollControlData", 2, "hkbPoweredRagdollControlData", 3)
	HK_PATCH_MEMBER_DEFAULT_SET_REAL("maxForce", 50.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbSceneModifierList", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkbModifier", HK_NULL)
	HK_PATCH_MEMBER_REMOVED("sceneModifierEntries", TYPE_ARRAY_STRUCT, "hkbSceneModifierListSceneModifierEntry", 0)
	HK_PATCH_DEPENDS("hkbNode", 1)
	HK_PATCH_DEPENDS("hkbSceneModifierListSceneModifierEntry", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkbModifier", 0)
	HK_PATCH_DEPENDS("hkbBindable", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbSceneModifierListSceneModifierEntry", 1, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("sceneModifier", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbProjectData", 1, "hkbProjectData", 2)
	HK_PATCH_MEMBER_REMOVED("attachmentSetups", TYPE_ARRAY_OBJECT, "hkbAttachmentSetup", 0)
	HK_PATCH_DEPENDS("hkbAttachmentSetup", 1)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterSkinInfo", 1, "hkbCharacterSkinInfo", 2)
    HK_PATCH_MEMBER_REMOVED("skinIds", TYPE_ARRAY_INT, HK_NULL, 0)
    HK_PATCH_MEMBER_REMOVED("hasRagdoll", TYPE_BYTE, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("deformableSkins", TYPE_ARRAY_INT, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("rigidSkins", TYPE_ARRAY_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterSteppedInfo", 1, "hkbCharacterSteppedInfo", 2)
    HK_PATCH_MEMBER_ADDED("rigidAttachmentTransforms", TYPE_ARRAY_VEC_12, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbSetBehaviorCommand", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("characterId", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("behavior", TYPE_OBJECT, "hkbBehaviorGraph", 0)
	HK_PATCH_MEMBER_ADDED("rootGenerator", TYPE_OBJECT, "hkbGenerator", 0)
	HK_PATCH_MEMBER_ADDED("referencedBehaviors", TYPE_ARRAY_OBJECT, "hkbBehaviorGraph", 0)
	HK_PATCH_MEMBER_ADDED("startStateIndex", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("randomizeSimulation", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkbNode", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkbGenerator", 0)
	HK_PATCH_DEPENDS("hkbBindable", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkbBehaviorGraph", 1)
HK_PATCH_END()


HK_PATCH_BEGIN("hkbSetNodePropertyCommand", 0, "hkbSetNodePropertyCommand", 1)
	HK_PATCH_MEMBER_ADDED_INT("padding", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterInfo", 1, "hkbCharacterInfo", 2)
	HK_PATCH_MEMBER_ADDED_INT("padding", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbBehaviorEventsInfo", 0, "hkbBehaviorEventsInfo", 1)
	HK_PATCH_MEMBER_ADDED_INT("padding", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbSetBehaviorCommand", 0, "hkbSetBehaviorCommand", 1)
	HK_PATCH_MEMBER_ADDED_INT("padding", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbEventRaisedInfo", 1, "hkbEventRaisedInfo", 2)
	HK_PATCH_MEMBER_ADDED_INT("padding", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkbCharacterControlCommand", 0, "hkbCharacterControlCommand", 1)
	HK_PATCH_MEMBER_ADDED_INT("padding", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbBehaviorGraphInternalStateInfo", 1)
    HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
    HK_PATCH_MEMBER_ADDED("characterId", TYPE_INT, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("internalState", TYPE_OBJECT, "hkbBehaviorGraphInternalState", 0)
    HK_PATCH_MEMBER_ADDED("auxiliaryNodeInfo", TYPE_ARRAY_OBJECT, "hkbAuxiliaryNodeInfo", 0)
    HK_PATCH_MEMBER_ADDED("activeEventIds", TYPE_ARRAY_INT, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("activeVariableIds", TYPE_ARRAY_INT, HK_NULL, 0)
    HK_PATCH_DEPENDS("hkBaseObject", 0)
    HK_PATCH_DEPENDS("hkbBehaviorGraphInternalState", 0)
    HK_PATCH_DEPENDS("hkbAuxiliaryNodeInfo", 1)
    HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbClientCharacterState", 1)
    HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
    HK_PATCH_MEMBER_ADDED("deformableSkinIds", TYPE_ARRAY_INT, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("rigidSkinIds", TYPE_ARRAY_INT, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("externalEventIds", TYPE_ARRAY_INT, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("auxiliaryInfo", TYPE_ARRAY_OBJECT, "hkbAuxiliaryNodeInfo", 0)
    HK_PATCH_MEMBER_ADDED("activeEventIds", TYPE_ARRAY_INT, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("activeVariableIds", TYPE_ARRAY_INT, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("characterId", TYPE_INT, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("instanceName", TYPE_CSTRING, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("templateName", TYPE_CSTRING, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("fullPathToProject", TYPE_CSTRING, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("behaviorData", TYPE_OBJECT, "hkbBehaviorGraphData", 0)
    HK_PATCH_MEMBER_ADDED("behaviorInternalState", TYPE_OBJECT, "hkbBehaviorGraphInternalState", 0)
    HK_PATCH_MEMBER_ADDED("visible", TYPE_BYTE, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("elapsedSimulationTime", TYPE_REAL, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("skeleton", TYPE_OBJECT, "hkaSkeleton", 0)
    HK_PATCH_MEMBER_ADDED("worldFromModel", TYPE_VEC_12, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("poseModelSpace", TYPE_ARRAY_VEC_12, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("rigidAttachmentTransforms", TYPE_ARRAY_VEC_12, HK_NULL, 0)
    HK_PATCH_DEPENDS("hkBaseObject", 0)
    HK_PATCH_DEPENDS("hkbAuxiliaryNodeInfo", 1)
    HK_PATCH_DEPENDS("hkbBehaviorGraphData", 2)
    HK_PATCH_DEPENDS("hkbBehaviorGraphInternalState", 0)
    HK_PATCH_DEPENDS("hkReferencedObject", 0)
    HK_PATCH_DEPENDS("hkaSkeleton", 3)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkbAuxiliaryNodeInfo", 1)
    HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
    HK_PATCH_MEMBER_ADDED("type", TYPE_BYTE, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("depth", TYPE_BYTE, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("referenceBehaviorName", TYPE_CSTRING, HK_NULL, 0)
    HK_PATCH_MEMBER_ADDED("selfTransitionNames", TYPE_ARRAY_CSTRING, HK_NULL, 0)
    HK_PATCH_DEPENDS("hkBaseObject", 0)
    HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

/*
 * Havok SDK - NO SOURCE PC DOWNLOAD, BUILD(#20140907)
 * 
 * Confidential Information of Havok.  (C) Copyright 1999-2014
 * Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
 * Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
 * rights, and intellectual property rights in the Havok software remain in
 * Havok and/or its suppliers.
 * 
 * Use of this software for evaluation purposes is subject to and indicates
 * acceptance of the End User licence Agreement for this product. A copy of
 * the license is included with this software and is also available at www.havok.com/tryhavok.
 * 
 */
