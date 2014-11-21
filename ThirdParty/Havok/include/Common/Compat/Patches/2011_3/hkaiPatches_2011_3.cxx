/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2014 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

// AI specific product patches applied to release 2011_3.
// This file is #included by hkaiPatches_2011_3.cpp

HK_PATCH_BEGIN("hkaiNavMeshSimplificationUtilsSettings", 10, "hkaiNavMeshSimplificationUtilsSettings", 11)
        HK_PATCH_MEMBER_ADDED_REAL("aabbReplacementAreaFraction", 1.200000f)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiAdaptiveRanger", 0)
	HK_PATCH_MEMBER_ADDED_REAL("curRange", 1.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiCharacter", 23, "hkaiCharacter", 24)
	HK_PATCH_MEMBER_ADDED("adaptiveRanger", TYPE_STRUCT, "hkaiAdaptiveRanger", 0)
	HK_PATCH_DEPENDS("hkaiAdaptiveRanger", 0)
	HK_PATCH_MEMBER_DEFAULT_SET_BYTE("useNewAvoidance", 1)
	//HK_PATCH_FUNCTION(hkaiCharacter_23_to_24)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiAvoidanceSolverAvoidanceProperties", 6, "hkaiAvoidanceSolverAvoidanceProperties", 7)
	HK_PATCH_MEMBER_ADDED_INT("maxNeighbors", 16)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiAvoidanceSolverMovementProperties", 3, "hkaiAvoidanceSolverMovementProperties", 4)
	HK_PATCH_MEMBER_DEFAULT_SET_BYTE("useAngularConstraints", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiJumpDetectionSettingsTrajectory", 0)
	HK_PATCH_MEMBER_ADDED("points", TYPE_ARRAY_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED_REAL("width", 0.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiJumpDetectionSettingsJumpDescription", 0)
	HK_PATCH_MEMBER_ADDED("trajectory", TYPE_STRUCT, "hkaiJumpDetectionSettingsTrajectory", 0)
	HK_PATCH_MEMBER_ADDED("collidingTrajectories", TYPE_ARRAY_STRUCT, "hkaiJumpDetectionSettingsTrajectory", 0)
	HK_PATCH_MEMBER_ADDED_REAL("requiredPortion", 0.000000f)
	HK_PATCH_MEMBER_ADDED("blockingTrajectories", TYPE_ARRAY_STRUCT, "hkaiJumpDetectionSettingsTrajectory", 0)
	HK_PATCH_MEMBER_ADDED("requiredTrajectories", TYPE_ARRAY_STRUCT, "hkaiJumpDetectionSettingsTrajectory", 0)
	HK_PATCH_MEMBER_ADDED_REAL("setback", 0.000000f)
	HK_PATCH_MEMBER_ADDED_BYTE("reverseDirection", 0)
	HK_PATCH_MEMBER_ADDED_INT("startEdgeData", 0)
	HK_PATCH_MEMBER_ADDED_INT("endEdgeData", 0)
	HK_PATCH_MEMBER_ADDED_REAL("traversalCost", 0.000000f)
	HK_PATCH_DEPENDS("hkaiJumpDetectionSettingsTrajectory", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiJumpDetectionSettings", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("jumpDescriptions", TYPE_ARRAY_STRUCT, "hkaiJumpDetectionSettingsJumpDescription", 0)
	HK_PATCH_MEMBER_ADDED("up", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED_REAL("navMeshStartZoneSearchHalfHeight", 0.500000f)
	HK_PATCH_MEMBER_ADDED_REAL("geometryStartZoneSearchHalfHeight", 0.500000f)
	HK_PATCH_MEMBER_ADDED_REAL("geometryEndZoneSearchHalfHeight", 0.500000f)
	HK_PATCH_MEMBER_ADDED_REAL("startZoneMergeDistance", 0.500000f)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkaiJumpDetectionSettingsJumpDescription", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiNavMeshPathSearchParameters", 6, "hkaiNavMeshPathSearchParameters", 7)
	HK_PATCH_MEMBER_ADDED("new_up", TYPE_TUPLE_INT, HK_NULL, 3)
	HK_PATCH_FUNCTION(hkaiNavMeshPathSearchParameters_6_to_7)
	HK_PATCH_MEMBER_REMOVED("up", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_RENAMED("new_up", "up")
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiStreamingSetGraphConnection", 0)
	HK_PATCH_MEMBER_ADDED_INT("nodeIndex", -1)
	HK_PATCH_MEMBER_ADDED_INT("oppositeNodeIndex", -1)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiStreamingSetVolumeConnection", 0)
	HK_PATCH_MEMBER_ADDED_INT("cellIndex", -1)
	HK_PATCH_MEMBER_ADDED_INT("oppositeCellIndex", -1)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiDirectedGraphInstanceFreeBlockList", 0)
	HK_PATCH_MEMBER_ADDED("blocks", TYPE_ARRAY_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiDirectedGraphInstance", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED_INT("sectionUid", hkUint32(-1) )
	HK_PATCH_MEMBER_ADDED_INT("runtimeId", -1)
	HK_PATCH_MEMBER_ADDED("originalGraph", TYPE_OBJECT, "hkaiDirectedGraphExplicitCost", 0)
	HK_PATCH_MEMBER_ADDED("nodeMap", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("instancedNodes", TYPE_ARRAY_STRUCT, "hkaiDirectedGraphExplicitCostNode", 0)
	HK_PATCH_MEMBER_ADDED("ownedEdges", TYPE_ARRAY_STRUCT, "hkaiDirectedGraphExplicitCostEdge", 0)
	HK_PATCH_MEMBER_ADDED("userEdgeCount", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("transform", TYPE_VEC_16, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("freeEdgeBlocks", TYPE_ARRAY_STRUCT, "hkaiDirectedGraphInstanceFreeBlockList", 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkaiDirectedGraphExplicitCostEdge", 1)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkaiDirectedGraphExplicitCost", 5)
	HK_PATCH_DEPENDS("hkaiDirectedGraphExplicitCostNode", 0)
	HK_PATCH_DEPENDS("hkaiDirectedGraphInstanceFreeBlockList", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiStreamingSetNavMeshConnection", 0)
	HK_PATCH_MEMBER_ADDED_INT("faceIndex", -1)
	HK_PATCH_MEMBER_ADDED_INT("edgeIndex", -1)
	HK_PATCH_MEMBER_ADDED_INT("oppositeFaceIndex", -1)
	HK_PATCH_MEMBER_ADDED_INT("oppositeEdgeIndex", -1)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiStreamingSet", 0)
	HK_PATCH_MEMBER_ADDED_INT("thisUid", hkUint32(-1) )
	HK_PATCH_MEMBER_ADDED_INT("oppositeUid", hkUint32(-1) )
	HK_PATCH_MEMBER_ADDED("meshConnections", TYPE_ARRAY_STRUCT, "hkaiStreamingSetNavMeshConnection", 0)
	HK_PATCH_MEMBER_ADDED("graphConnections", TYPE_ARRAY_STRUCT, "hkaiStreamingSetGraphConnection", 0)
	HK_PATCH_MEMBER_ADDED("volumeConnections", TYPE_ARRAY_STRUCT, "hkaiStreamingSetVolumeConnection", 0)
	HK_PATCH_DEPENDS("hkaiStreamingSetGraphConnection", 0)
	HK_PATCH_DEPENDS("hkaiStreamingSetNavMeshConnection", 0)
	HK_PATCH_DEPENDS("hkaiStreamingSetVolumeConnection", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiUserEdgeUtilsUserEdgeSetup", 1, "hkaiUserEdgeUtilsUserEdgeSetup", 2)
	HK_PATCH_MEMBER_ADDED_VEC_4("worldUpA", 0.000000f,0.000000f,0.000000f,0.000000f)
	HK_PATCH_MEMBER_ADDED_VEC_4("worldUpB", 0.000000f,0.000000f,0.000000f,0.000000f)
	HK_PATCH_MEMBER_ADDED_BYTE("space", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiDirectedGraphExplicitCost", 5, "hkaiDirectedGraphExplicitCost", 6)
	HK_PATCH_MEMBER_ADDED("streamingSets", TYPE_ARRAY_STRUCT, "hkaiStreamingSet", 0)
	HK_PATCH_FUNCTION(hkaiDirectedGraphExplicitCost_5_to_6)
	HK_PATCH_MEMBER_REMOVED("sectionUid", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("runtimeId", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("externalEdges", TYPE_ARRAY_STRUCT, "hkaiDirectedGraphExplicitCostExternalEdgeInfo", 0)
	HK_PATCH_MEMBER_REMOVED("sectionDependencies", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkaiDirectedGraphExplicitCostExternalEdgeInfo", 0)
	HK_PATCH_DEPENDS("hkaiStreamingSet", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiNavMeshInstance", 2, "hkaiNavMeshInstance", 3)
	HK_PATCH_MEMBER_ADDED_INT("sectionUid", 0)
	HK_PATCH_MEMBER_ADDED_INT("runtimeId", 0)
	HK_PATCH_FUNCTION(hkaiNavMeshInstance_2_to_3)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiStreamingCollectionInstanceInfo", 2, "hkaiStreamingCollectionInstanceInfo", 3)
	HK_PATCH_MEMBER_REMOVED("clusterGraph", TYPE_OBJECT, "hkaiDirectedGraphExplicitCost", 0)
	HK_PATCH_MEMBER_ADDED("clusterGraphInstance", TYPE_OBJECT, "hkaiDirectedGraphInstance", 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkaiDirectedGraphExplicitCost", 5)
	HK_PATCH_DEPENDS("hkaiDirectedGraphInstance", 0)
HK_PATCH_END()


HK_PATCH_BEGIN("hkaiSilhouetteRecorderInstanceLoadedEvent", 0, "hkaiSilhouetteRecorderInstanceLoadedEvent", 1)
	HK_PATCH_MEMBER_REMOVED("graph", TYPE_OBJECT, "hkaiDirectedGraphExplicitCost", 0)
	HK_PATCH_MEMBER_ADDED("graph", TYPE_OBJECT, "hkaiDirectedGraphInstance", 0)
	HK_PATCH_DEPENDS("hkaiDirectedGraphExplicitCost", 5)
	HK_PATCH_DEPENDS("hkaiDirectedGraphInstance", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiSilhouetteRecorderGraphLoadedEvent", 0, "hkaiSilhouetteRecorderGraphLoadedEvent", 1)
	HK_PATCH_MEMBER_REMOVED("graph", TYPE_OBJECT, "hkaiDirectedGraphExplicitCost", 0)
	HK_PATCH_MEMBER_ADDED("graph", TYPE_OBJECT, "hkaiDirectedGraphInstance", 0)
	HK_PATCH_DEPENDS("hkaiDirectedGraphExplicitCost", 5)
	HK_PATCH_DEPENDS("hkaiDirectedGraphInstance", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiNavMesh", 12, "hkaiNavMesh", 13)
	HK_PATCH_MEMBER_ADDED("streamingSets", TYPE_ARRAY_STRUCT, "hkaiStreamingSet", 0)
	HK_PATCH_FUNCTION(hkaiNavMesh_12_to_13)
	HK_PATCH_MEMBER_REMOVED("sectionUid", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("runtimeId", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("sectionDependencies", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkaiStreamingSet", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiNavMeshEdge", 6, "hkaiNavMeshEdge", 7)
	HK_PATCH_MEMBER_REMOVED("oppositeSectionUid", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiDirectedGraphExplicitCostExternalEdgeInfo", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("nodeIndex", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("edgeKey", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("targetUid", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiSilhouetteRecorderSilhouettesSteppedEvent", 1, "hkaiSilhouetteRecorderSilhouettesSteppedEvent", 2)
	HK_PATCH_MEMBER_ADDED("updatedSections", TYPE_STRUCT, "hkBitField", 0)
	HK_PATCH_DEPENDS("hkBitField", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiNavVolumeInstanceCellInstance", 0)
	HK_PATCH_MEMBER_ADDED("startEdgeIndex", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("numEdges", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiNavVolumeInstance", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkReferencedObject")
	HK_PATCH_MEMBER_ADDED("originalVolume", TYPE_OBJECT, "hkaiNavVolume", 0)
	HK_PATCH_MEMBER_ADDED("cellMap", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("instancedCells", TYPE_ARRAY_STRUCT, "hkaiNavVolumeInstanceCellInstance", 0)
	HK_PATCH_MEMBER_ADDED("ownedEdges", TYPE_ARRAY_STRUCT, "hkaiNavVolumeEdge", 0)
	HK_PATCH_MEMBER_ADDED_INT("sectionUid", 0)
	HK_PATCH_MEMBER_ADDED_INT("runtimeId", 0)
	HK_PATCH_MEMBER_ADDED("translation", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkaiNavVolume", 8)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkaiNavVolumeCell", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkaiNavVolumeEdge", 1)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiWorld", 28, "hkaiWorld", 29)
	HK_PATCH_MEMBER_REMOVED("streamingManager", TYPE_OBJECT, "hkaiStreamingManager", 0)
	HK_PATCH_DEPENDS("hkaiStreamingManager", 6)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiSilhouetteRecorderWorldConnectedEvent", 0, "hkaiSilhouetteRecorderWorldConnectedEvent", 1)
	HK_PATCH_MEMBER_REMOVED("streamingManager", TYPE_OBJECT, "hkaiStreamingManager", 0)
	HK_PATCH_DEPENDS("hkaiStreamingManager", 6)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiSilhouetteRecorderVolumeLoadedEvent", 0, "hkaiSilhouetteRecorderVolumeLoadedEvent", 1)
	HK_PATCH_MEMBER_REMOVED("volume", TYPE_OBJECT, "hkaiNavVolume", 0)
	HK_PATCH_MEMBER_ADDED("volume", TYPE_OBJECT, "hkaiNavVolumeInstance", 0)
	HK_PATCH_DEPENDS("hkaiNavVolume", 8)
	HK_PATCH_DEPENDS("hkaiNavVolumeInstance", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiStreamingCollectionInstanceInfo", 3, "hkaiStreamingCollectionInstanceInfo", 4)
	HK_PATCH_MEMBER_REMOVED("volumePtr", TYPE_OBJECT, "hkaiNavVolume", 0)
	HK_PATCH_MEMBER_ADDED("volumeInstancePtr", TYPE_OBJECT, "hkaiNavVolumeInstance", 0)
	HK_PATCH_DEPENDS("hkaiNavVolume", 8)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkaiNavVolumeInstance", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiStreamingManager", 6, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_PARENT_SET("hkReferencedObject", HK_NULL)
	HK_PATCH_MEMBER_REMOVED("sections", TYPE_ARRAY_STRUCT, "hkaiStreamingManagerSectionInfo", 0)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkaiStreamingManagerSectionInfo", 6)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiStreamingManagerSectionInfo", 6, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("uid", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("meshPtr", TYPE_OBJECT, "hkaiNavMesh", 0)
	HK_PATCH_MEMBER_REMOVED("meshGraphPtr", TYPE_OBJECT, "hkaiDirectedGraphExplicitCost", 0)
	HK_PATCH_MEMBER_REMOVED("volumePtr", TYPE_OBJECT, "hkaiNavVolume", 0)
	HK_PATCH_MEMBER_REMOVED("referenceCount", TYPE_INT, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkaiNavVolume", 8)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkaiNavMesh", 13)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
	HK_PATCH_DEPENDS("hkaiDirectedGraphExplicitCost", 6)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiNavVolumeExternalEdgeInfo", 0, HK_NULL, HK_CLASS_REMOVED)
	HK_PATCH_MEMBER_REMOVED("edgeIndex", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("cellIndex", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("oppositeUid", TYPE_INT, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiNavVolume", 8, "hkaiNavVolume", 9)
	HK_PATCH_MEMBER_ADDED("streamingSets", TYPE_ARRAY_STRUCT, "hkaiStreamingSet", 0)
	HK_PATCH_FUNCTION(hkaiNavVolume_9_to_10)
	HK_PATCH_MEMBER_REMOVED("sectionUid", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("runtimeId", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("externalEdges", TYPE_ARRAY_STRUCT, "hkaiNavVolumeExternalEdgeInfo", 0)
	HK_PATCH_MEMBER_REMOVED("streamingDependencies", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkaiStreamingSet", 0)
	HK_PATCH_DEPENDS("hkaiNavVolumeExternalEdgeInfo", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiDirectedGraphExplicitCostNode", 0, "hkaiDirectedGraphExplicitCostNode", 1)
	HK_PATCH_MEMBER_RENAMED("edgeStartIndex", "startEdgeIndex")
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiUserEdgeUtilsUserEdgePair", 0, "hkaiUserEdgeUtilsUserEdgePair", 1)
	HK_PATCH_MEMBER_RENAMED("meshUidA", "instanceUidA")
	HK_PATCH_MEMBER_RENAMED("meshUidB", "instanceUidB")
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiNavVolumePathSearchParameters", 1, "hkaiNavVolumePathSearchParameters", 2)
	HK_PATCH_MEMBER_ADDED("new_up", TYPE_TUPLE_INT, HK_NULL, 3)
	HK_PATCH_FUNCTION(hkaiNavVolumePathSearchParameters_1_to_2)
	HK_PATCH_MEMBER_REMOVED("up", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_RENAMED("new_up", "up")
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiPlaneVolume", 0, "hkaiPlaneVolume", 1)
	HK_PATCH_MEMBER_ADDED_BYTE("isInverted", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiCharacter", 24, "hkaiCharacter", 25)
	HK_PATCH_MEMBER_ADDED_BYTE("avoidanceSolverType", 0)
	HK_PATCH_MEMBER_ADDED_BYTE("nearbyBoundariesSearchType", 1)
	HK_PATCH_FUNCTION(hkaiCharacter_24_to_25)
	HK_PATCH_MEMBER_REMOVED("useNewAvoidance", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiLocalSteeringInput", 3, "hkaiLocalSteeringInput", 4)
	HK_PATCH_MEMBER_RENAMED("useNewAvoidance", "useSamplingAvoidanceSolver")
	HK_PATCH_MEMBER_ADDED_REAL("wallFollowingFactor", 0.000000f)
	HK_PATCH_MEMBER_ADDED("collisionPenalty", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("penetrationPenalty", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiAvoidanceSolverMovementProperties", 4, "hkaiAvoidanceSolverMovementProperties", 5)
	HK_PATCH_MEMBER_ADDED_BYTE("kinematicConstraintType", 2)
	HK_PATCH_FUNCTION(hkaiAvoidanceSolverMovementProperties_4_to_5)
	HK_PATCH_MEMBER_REMOVED("useAngularConstraints", TYPE_BYTE, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiPlaneVolume", 1, "hkaiPlaneVolume", 2)
	HK_PATCH_MEMBER_ADDED("aabb", TYPE_STRUCT, "hkAabb", 0)
	HK_PATCH_DEPENDS("hkAabb", 0)
	HK_PATCH_FUNCTION(hkaiPlaneVolume_1_to_2)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiAvoidanceSolverAvoidanceProperties", 7, "hkaiAvoidanceSolverAvoidanceProperties", 8)
	HK_PATCH_MEMBER_DEFAULT_SET_REAL("boundaryLimitTime", 0.300000f)
	HK_PATCH_MEMBER_DEFAULT_SET_REAL("limitObstacleDistance", 1.000000f)
	HK_PATCH_MEMBER_DEFAULT_SET_REAL("limitObstacleVelocity", 0.500000f)
	HK_PATCH_MEMBER_DEFAULT_SET_REAL("limitBoundaryDistance", 0.400000f)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiLineOfSightUtilLineOfSightOutput", 0)
	HK_PATCH_MEMBER_ADDED("visitedEdgesOut", TYPE_ARRAY_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("distancesOut", TYPE_ARRAY_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("pointsOut", TYPE_ARRAY_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED_BYTE("doNotExceedArrayCapacity", 0)
	HK_PATCH_MEMBER_ADDED_INT("numIterationsOut", 0)
	HK_PATCH_MEMBER_ADDED("finalFaceKey", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED_REAL("accumulatedDistance", 0.000000f)
	HK_PATCH_MEMBER_ADDED("finalPoint", TYPE_VEC_4, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiLineOfSightUtilInputBase", 0)
	HK_PATCH_MEMBER_ADDED("startPoint", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("up", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("startFaceKey", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("maxNumberOfIterations", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("agentInfo", TYPE_STRUCT, "hkaiAgentTraversalInfo" , 0)
	HK_PATCH_MEMBER_ADDED_REAL("searchRadius", -1.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("maximumPathLength", HK_REAL_MAX)
	HK_PATCH_MEMBER_ADDED("costModifier", TYPE_OBJECT, "hkaiNavMeshCostModifier", 0)
	HK_PATCH_MEMBER_ADDED_BYTE("outputEdgesOnFailure", 0)
	HK_PATCH_MEMBER_ADDED_BYTE("projectedRadiusCheck", 1)
	HK_PATCH_MEMBER_ADDED("exactInternalVertexHandling", TYPE_BYTE, HK_NULL,0)
	HK_PATCH_MEMBER_ADDED_BYTE("isWallClimbing", 0)
	HK_PATCH_MEMBER_ADDED("mode", TYPE_BYTE, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkaiAgentTraversalInfo", 1)
	HK_PATCH_DEPENDS("hkBaseObject", 0)
	HK_PATCH_DEPENDS("hkaiNavMeshCostModifier", 2)
	HK_PATCH_DEPENDS("hkReferencedObject", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiLineOfSightUtilDirectPathInput", 0)
	HK_PATCH_PARENT_SET(HK_NULL, "hkaiLineOfSightUtilInputBase")
	HK_PATCH_MEMBER_ADDED("direction", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkaiLineOfSightUtilInputBase", 0)
HK_PATCH_END()

HK_PATCH_BEGIN(HK_NULL, HK_CLASS_ADDED, "hkaiLineOfSightUtilLineOfSightInput", 0 )
	HK_PATCH_PARENT_SET(HK_NULL, "hkaiLineOfSightUtilInputBase")
	HK_PATCH_MEMBER_ADDED("goalPoint", TYPE_VEC_4, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED("goalFaceKey", TYPE_INT, HK_NULL, 0)
	HK_PATCH_DEPENDS("hkaiLineOfSightUtilInputBase", 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiNavMeshPathSearchParameters", 7, "hkaiNavMeshPathSearchParameters", 8)
	HK_PATCH_MEMBER_ADDED_BYTE("projectedRadiusCheck", 1)
	HK_PATCH_MEMBER_ADDED_REAL("searchSphereRadius", -1.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("searchCapsuleRadius", -1.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiPathfindingUtilFindPathInput", 9, "hkaiPathfindingUtilFindPathInput", 10)
	HK_PATCH_FUNCTION(hkaiPathfindingUtilFindPathInput_9_to_10)
	HK_PATCH_MEMBER_REMOVED("searchSphereRadius", TYPE_REAL, HK_NULL, 0)
	HK_PATCH_MEMBER_REMOVED("searchCapsuleRadius", TYPE_REAL, HK_NULL, 0)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiCharacter", 25, "hkaiCharacter", 26)
	HK_PATCH_MEMBER_ADDED_INT("maxNeighbors", 16)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiAvoidanceSolverAvoidanceProperties", 8, "hkaiAvoidanceSolverAvoidanceProperties", 9)
	HK_PATCH_MEMBER_REMOVED("maxNeighbors", TYPE_INT, HK_NULL, 0)
	HK_PATCH_MEMBER_ADDED_REAL("wallFollowingFactor", 0.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("collisionPenalty", 1.000000f)
	HK_PATCH_MEMBER_ADDED_REAL("penetrationPenalty", 100.000000f)
HK_PATCH_END()

HK_PATCH_BEGIN("hkaiWorldCharacterStepCallbackContext", 0, "hkaiWorldCharacterStepSerializableContext", 1)
	 HK_PATCH_MEMBER_ADDED_REAL("timestep", 0.033333f)
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
