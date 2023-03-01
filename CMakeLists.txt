cmake_minimum_required(VERSION 3.9)

# set the project name and version
project(SpiderWebDB VERSION 0.0.1)

configure_file(SpiderWebDBConfig.h.in ${PROJECT_SOURCE_DIR}/include/SpiderWebDBConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES /usr/local/lib ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

option(DEBUG "Enable Debug" OFF)
if(DEBUG)
	add_compile_options(
		-O0  #no optimization
		-g   #generate debug info
	)

endif(DEBUG)

# add the library

file (GLOB SRC_FILES "src/*.cpp"
                     "src/core/*.cpp" 
                     "src/core/node/*.cpp"
                     "src/core/relation/*.cpp"
                     "src/core/feature/*.cpp"
                     "src/core/db/*.cpp"
                     "src/core/utils/*.cpp"
                     "src/core/query/*.cpp"
                    )

add_library(SpiderWebDB SHARED ${SRC_FILES})

target_include_directories(SpiderWebDB PUBLIC
						  "${PROJECT_SOURCE_DIR}/include"
                          "${PROJECT_SOURCE_DIR}/include/core"
                          "${PROJECT_SOURCE_DIR}/include/core/node"
                          "${PROJECT_SOURCE_DIR}/include/core/relation"
                          "${PROJECT_SOURCE_DIR}/include/core/feature"
                          "${PROJECT_SOURCE_DIR}/include/core/db"
                          "${PROJECT_SOURCE_DIR}/include/core/utils"
                          "${PROJECT_SOURCE_DIR}/include/core/query"
						  )

target_link_libraries(SpiderWebDB
                          pthread)

add_subdirectory("example")
add_subdirectory("test")