file (GLOB EXAMPLE_1_FILES "./*.cpp")

add_executable( example_1 ${EXAMPLE_1_FILES})

target_include_directories(example_1 PUBLIC
						  "${PROJECT_SOURCE_DIR}/include"
                          "${PROJECT_SOURCE_DIR}/include/core"
                          "${PROJECT_SOURCE_DIR}/include/core/node"
                          "${PROJECT_SOURCE_DIR}/include/core/relation"
                          "${PROJECT_SOURCE_DIR}/include/core/feature"
                          "${PROJECT_SOURCE_DIR}/include/core/db"
                          "${PROJECT_SOURCE_DIR}/include/core/utils"
						  )

target_link_libraries(example_1
                      SpiderWebDB
                      pthread)