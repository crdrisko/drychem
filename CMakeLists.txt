### Top level cmake script for Utilities-API ###
cmake_minimum_required(VERSION 3.12.0)
project(Utilities-API VERSION 1.0.0)


### Compilation Options ###
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if (CMAKE_COMPILER_IS_GNUCXX)
    add_definitions("-Wno-psabi")
endif()


### Files / Directories ###
set(SOURCES 
    src/markupFile.cpp
    src/mathUtilities.cpp
    src/stringUtilities.cpp
    src/textFile.cpp)

set(BASH_FILES
    scripts/changeCase.sh
    scripts/compiler.sh
    scripts/errorHandling.sh
    scripts/fileMaker.sh
    scripts/linkLogin.sh
    scripts/modifyFiles.sh
    scripts/remover.sh
    scripts/showArguments.sh
    scripts/showOptions.sh)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY 
    ${PROJECT_BINARY_DIR}/lib
    CACHE PATH 
    "Single directory for all shared libraries.")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 
    ${PROJECT_BINARY_DIR}/bin
    CACHE PATH 
    "Single directory for all executables.")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY 
    ${PROJECT_BINARY_DIR}/lib
    CACHE PATH 
    "Single directory for all static libraries.")


### Libraries / Executables ###
add_library(utilities-api SHARED ${SOURCES})
add_library(utilities-api-static STATIC ${SOURCES})


### Installation ###
install(TARGETS utilities-api utilities-api-static
        DESTINATION lib)
        
install(DIRECTORY src/include/
        DESTINATION include/utilities-api)

foreach(BASH_FILE ${BASH_FILES})
    ## Remove bash extensions and make scripts executable ##
    get_filename_component(filename "${BASH_FILE}" NAME_WE)

    configure_file(${BASH_FILE} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${filename}" @ONLY)

    install(FILES "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${filename}"
            DESTINATION bin
            PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE 
                        GROUP_READ             GROUP_EXECUTE 
                        WORLD_READ             WORLD_EXECUTE)
endforeach()


### Unit Testing ###
option(build_all_tests "Build all unit tests in the test directory." OFF)

if (build_all_tests)
    include(CTest)
    include(GoogleTest)

    enable_testing()

    ## Function to create a new test based off the pre-defined naming template ##
    function(new_test testname interiorDirectory)
        add_executable(test${testname}Functions test/${interiorDirectory}/test${testname}Functions.cpp)

        target_link_libraries(test${testname}Functions ${GTEST_LIBRARIES} utilities-api)
        
        gtest_discover_tests(test${testname}Functions 
                             WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test/${interiorDirectory})
    endfunction(new_test)

    ## Function to create a new test based off the pre-defined naming template for unit conversions ##
    function(new_conversion_test testname)
        new_test(${testname}Conversion TestPhysicalQuantities/${testname})
    endfunction(new_conversion_test)

    ## Locate GTest ##
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    ## Create all tests ##
    new_test(Error TestErrors)
    new_test(Math TestMath)
    new_test(String TestStrings)
    new_test(File TestFiles)
    new_test(MiscellaneousUnit TestPhysicalQuantities/MiscellaneousUnitFunctions)
    new_test(SI_UnitConversion TestPhysicalQuantities/SI_UnitPrefixes)

    new_conversion_test(AmountOfSubstance)
    new_conversion_test(Angle)
    new_conversion_test(Area)
    new_conversion_test(ElectricCharge)
    new_conversion_test(Energy)
    new_conversion_test(Length)
    new_conversion_test(MagneticFluxDensity)
    new_conversion_test(Mass)
    new_conversion_test(MolarEnergy)
    new_conversion_test(Pressure)
    new_conversion_test(Temperature)
    new_conversion_test(Time)
    new_conversion_test(Volume)
endif()
