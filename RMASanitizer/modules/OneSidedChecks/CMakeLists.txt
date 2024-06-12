# Part of the MUST Project, under BSD-3-Clause License
# See https://hpc.rwth-aachen.de/must/LICENSE for license information.
# SPDX-License-Identifier: BSD-3-Clause

# @file CMakeLists.txt
#       CMake file for modules of directory modules/OneSidedChecks.
#
# @author Simon Schwitanski 
# @date 22.05.2017
#

INCLUDE_DIRECTORIES(BEFORE . AppThrAnn Common RMAOp OriginChecks RMASanitize RMAWrapper)

#Install headers
MUST_INSTALL(FILES
    OneSidedChecksApi.h
    Common/DataPool.h
    AppThrAnn/I_AppThrAnn.h
    AppThrAnn/AppThrAnn.h
    AppThrAnn/AppThrAnn.cpp
    AppThrAnn/I_TSanSyncClockRecorder.h
    AppThrAnn/TSanSyncClockRecorder.h
    RMASanitize/I_RMASanitize.h
    RMASanitize/RMASanitize.h
    RMASanitize/RMASanitizeTypes.h
    RMAOp/I_RMAOp.h
    RMAOp/RMAOp.h
    RMAOp/I_OriginRMAOp.h
    RMAOp/OriginRMAOp.h
    RMAOp/I_TargetRMAOp.h
    RMAOp/TargetRMAOp.h
    RaceChecks/TSan/I_OriginChecks.h
    RaceChecks/TSan/I_TargetChecks.h
    RaceChecks/List/I_RaceChecksList.h
    RMAWrapper/I_MPIRMAWrapper.h
    RMAWrapper/MPIRMAWrapper.h
    RMAWrapper/I_SHMEMRMAWrapper.h
    RMAWrapper/SHMEMRMAWrapper.h
    RMAWrapper/I_GASPIRMAWrapper.h
    RMAWrapper/GASPIRMAWrapper.h
    ../ResourceTracking/Utility/HandleInfoBase.h
    DESTINATION include)

set(ISL_SOURCES "RaceChecks/List/IntervalSkipList/MemAccess.cpp;RaceChecks/List/IntervalSkipList/IntervalSkiplist.cpp;RaceChecks/List/IntervalSkipList/ISLInterval.cpp;RaceChecks/List/IntervalSkipList/ISLNode.cpp;")

#Build and install modules 
GTI_MAC_ADD_MODULE (appThrAnn "AppThrAnn/AppThrAnn.cpp;${BASE_SOURCES}" "CXX")
GTI_MAC_ADD_MODULE (tSanSyncClockRecorder "AppThrAnn/TSanSyncClockRecorder.cpp;${BASE_SOURCES}" "CXX")
GTI_MAC_ADD_MODULE (originChecks "RaceChecks/TSan/OriginChecks.cpp;${BASE_SOURCES}" "CXX")
GTI_MAC_ADD_MODULE (targetChecks "RaceChecks/TSan/TargetChecks.cpp;../../externals/GTI/modules/utility/Clock.cpp;${BASE_SOURCES}" "CXX")
# GTI_MAC_ADD_MODULE (raceChecksList "RaceChecks/List/RaceChecksList.cpp;../../externals/GTI/modules/utility/Clock.cpp;${BASE_SOURCES};${ISL_SOURCES}" "CXX")
# set_target_properties(raceChecksList
#         PROPERTIES
#         CXX_STANDARD 17
#         CXX_STANDARD_REQUIRED ON)

GTI_MAC_ADD_MODULE (RMASanitize "RMASanitize/RMASanitize.cpp;../ResourceTracking/Datatype/StridedBlock.cpp;../../externals/GTI/modules/utility/Clock.cpp;../ResourceTracking/Utility/HandleInfoBase.cpp;RMASanitize/OriginRMAMap.cpp;RMAOp/RMAOp.cpp;RMAOp/OriginRMAOp.cpp;RMAOp/TargetRMAOp.cpp;${BASE_SOURCES}" "CXX")

GTI_MAC_ADD_MODULE (MPIRMAWrapper "RMAWrapper/MPIRMAWrapper.cpp;../ResourceTracking/Datatype/StridedBlock.cpp;${BASE_SOURCES}" "CXX")
IF (ENABLE_OPENSHMEM)
INCLUDE_DIRECTORIES(../ResourceTracking/ShmemTeam)
INCLUDE_DIRECTORIES(../ResourceTracking/ShmemSegment)
GTI_MAC_ADD_MODULE (SHMEMRMAWrapper "RMAWrapper/SHMEMRMAWrapper.cpp;${BASE_SOURCES}" "CXX")
ENDIF(ENABLE_OPENSHMEM)
IF (ENABLE_GASPI)
GTI_MAC_ADD_MODULE (GASPIRMAWrapper "RMAWrapper/GASPIRMAWrapper.cpp;${BASE_SOURCES}" "CXX")
ENDIF(ENABLE_GASPI)
ADD_SUBDIRECTORY(TSanIntercept)
