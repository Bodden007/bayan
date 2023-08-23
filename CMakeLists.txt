cmake_minimum_required(VERSION 3.26)
project(bayan VERSION 0.1.0 LANGUAGES C CXX)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project (bayan VERSION ${PROJECT_VERSION})

set (CMAKE_CXX_STANDARD 20) 

set (BOOST_ROOT "C:/boost") 

add_executable(bayan src/main.cpp
src/models/parser.cpp
src/models/sortingData.cpp
src/models/crc.cpp
src/models/compareFile.cpp)

target_include_directories(bayan
    PRIVATE
    includes/
)

find_package (Boost REQUIRED COMPONENTS filesystem system 
program_options REQUIRED)

if (Boost_FOUND)
    include_directories (SYSTEM ${Boost_INCLUDE_DIR})    
    target_link_libraries (bayan ${Boost_LIBRARIES}) 
endif ()
install(TARGETS bayan RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()
