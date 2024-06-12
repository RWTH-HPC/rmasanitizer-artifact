# Part of the MUST Project, under BSD-3-Clause Licensg
# See https://hpc.rwth-aachen.de/must/LICENSE for license information.
# SPDX-License-Identifier: BSD-3-Clause

# @file CMakeLists.txt
#  CMake file for vector clock tests
#
# @author Felix Tomski
# @date 29.06.2021
#

# Modified version of configureTest in MTHelperMacros.cmake
FUNCTION (configureVectorClockTest 
        inLayoutSpecName #Filepath of layout template
        outLayoutSpecName  #Filepath of layout specification to generate
        l0Mods                      #List of modules on layer 0, format: "<Mod0Name>:<Mod0Group>;<Mod1Name>:<Mod1Group>;..."
        l1Mods                      #List of modules on layer 1
        numPlaces               #Number of processes used for process 0
        )

        SET (outLayoutSpecName ${outLayoutSpecName})
        SET (l0Mods ${l0Mods})
        SET (l1Mods ${l1Mods})
        SET (numApps ${numApps})

        #Calculate important variables for the run script
        MATH (EXPR totalProcs  "${numPlaces} * 1")
        
        #Calculate variables for layout spec
        SET(levels "0" "1")
        FOREACH (level ${levels})
            SET (level${level}ModString "")
            FOREACH (module ${l${level}Mods})
                STRING (REGEX MATCH "^[^:]*" modName ${module})
                STRING (REGEX MATCH "[^:]*$" modGroup ${module})
            
                SET (level${level}ModString "${level${level}ModString} \n<analysis name=\"${modName}\" group=\"${modGroup}\"></analysis>")    
            ENDFOREACH (module)
        ENDFOREACH (level)
        
        #Configure the layout specification
        CONFIGURE_FILE(${inLayoutSpecName} ${outLayoutSpecName})
ENDFUNCTION (configureVectorClockTest)


FUNCTION (addVectorClockTest
        framework
        familyName
        srcName
        numPlaces
        l0Mods
        l1Mods
        regex
        )

    GET_FILENAME_COMPONENT(testName "${familyName}/${srcName}" NAME_WE)
    addTestExecutable (${testName} "${familyName}/${srcName}")
    
    configureVectorClockTest (
        ${CMAKE_CURRENT_SOURCE_DIR}/layout.${framework}.template.xml
        ${CMAKE_CURRENT_BINARY_DIR}/${testName}Layout.xml
        "${l0Mods}"
        "${l1Mods}"
        ${numPlaces}
        )
    
    ADD_TEST(NAME ${testName} COMMAND
        bash ${MUSTRUN} 
            --must:timeout ${MUSTRUN_TIMEOUT}
            --must:np ${MPIEXEC_NUMPROC_FLAG} 
            --must:mpiexec mpiexec.hydra
            --must:layout ${CMAKE_CURRENT_BINARY_DIR}/${testName}Layout.xml 
            ${MPIEXEC_NUMPROC_FLAG} ${numPlaces} $<TARGET_FILE:${testName}> 
    )

    SET_TESTS_PROPERTIES (${testName} PROPERTIES PASS_REGULAR_EXPRESSION ${regex})
    
ENDFUNCTION (addVectorClockTest)

addVectorClockTest("MPI" "PointToPoint" "VCP2PMixed.cpp" 3 "" "" "shutdown")
addVectorClockTest("MPI" "PointToPoint" "VCP2PBlockingSync.cpp" 2 "" "" "shutdown")
addVectorClockTest("MPI" "PointToPoint" "VCP2PBlockingAsync.cpp" 2 "" "" "shutdown")
addVectorClockTest("MPI" "PointToPoint" "VCP2PNonblockingAsync.cpp" 2 "" "" "shutdown")

addVectorClockTest("MPI" "Collective" "VCCollBlockingAllToOne.cpp" 12 "" "" "shutdown")
addVectorClockTest("MPI" "Collective" "VCCollBlockingAllToAllOdd.cpp" 13 "" "" "shutdown")
addVectorClockTest("MPI" "Collective" "VCCollNonblockingAllToOne.cpp" 4 "" "" "shutdown")
addVectorClockTest("MPI" "Collective" "VCCollBlockingOneToAll.cpp" 12 "" "" "shutdown")
addVectorClockTest("MPI" "Collective" "VCCollBlockingAllToAll.cpp" 12 "" "" "shutdown")
addVectorClockTest("MPI" "Collective" "VCCollNonblockingAllToAll.cpp" 4 "" "" "shutdown")



addVectorClockTest("MPI" "RMA" "VCRMALockUnlock.cpp" 2 "" "" "shutdown")
addVectorClockTest("MPI" "RMA" "VCRMAFence.cpp" 4 "" "" "shutdown")
addVectorClockTest("MPI" "RMA" "VCRMAGeneralActiveTarget.cpp" 3 "" "" "shutdown")
addVectorClockTest("MPI" "RMA" "VCRMAGeneralActiveTargetMultiple.cpp" 5 "" "" "shutdown")

addVectorClockTest("MPI" "Annotations" "VCAnnotateTick.cpp" 3 "" "" "shutdown")
addVectorClockTest("MPI" "Annotations" "VCAnnotateProcessSignalWait.cpp" 3 "" "" "shutdown")
addVectorClockTest("MPI" "Annotations" "VCAnnotateProcessSignalWaitTransitive.cpp" 3 "" "" "shutdown")
addVectorClockTest("MPI" "Annotations" "VCAnnotateResourceSignalWait.cpp" 3 "" "" "shutdown")

if (ENABLE_GASPI)
addVectorClockTest("GASPI" "GASPI" "VCGASPIWriteBlockRace.cpp" 2 "" "" "shutdown")
addVectorClockTest("GASPI" "GASPI" "VCGASPIGroupBlock.cpp" 3 "" "" "shutdown")
addVectorClockTest("GASPI" "GASPI" "VCGASPIWriteNotify.cpp" 2 "" "" "shutdown")
addVectorClockTest("GASPI" "GASPI" "VCGASPINotify.cpp" 2 "" "" "shutdown")
addVectorClockTest("GASPI" "GASPI" "VCGASPINotifyNondeterm.cpp" 3 "" "" "shutdown")
addVectorClockTest("GASPI" "GASPI" "VCGASPIWaitMultiple.cpp" 3 "" "" "shutdown")
addVectorClockTest("GASPI" "GASPI" "VCGASPIPassive.cpp" 2 "" "" "shutdown")
endif()

if (ENABLE_OPENSHMEM)
addVectorClockTest("SHMEM" "OpenSHMEM" "VCBarrier.cpp" 4 "" "" "shutdown")
addVectorClockTest("SHMEM" "OpenSHMEM" "VCBarrierAll.cpp" 4 "" "" "shutdown")
addVectorClockTest("SHMEM" "OpenSHMEM" "VCBroadcast.cpp" 4 "" "" "shutdown")
addVectorClockTest("SHMEM" "OpenSHMEM" "VCAllocFree.cpp" 3 "" "" "shutdown")
addVectorClockTest("SHMEM" "OpenSHMEM" "VCLock.cpp" 3 "" "" "shutdown")
addVectorClockTest("SHMEM" "OpenSHMEM" "VCWaitUntil.cpp" 4 "" "" "shutdown")
addVectorClockTest("SHMEM" "OpenSHMEM" "VCTeamSplitStridedSimple.cpp" 10 "" "" "shutdown")
addVectorClockTest("SHMEM" "OpenSHMEM" "VCTeamSplitStridedNested.cpp" 12 "" "" "shutdown")
addVectorClockTest("SHMEM" "OpenSHMEM" "VCTeamSplit2D.cpp" 12 "" "" "shutdown")
endif()
