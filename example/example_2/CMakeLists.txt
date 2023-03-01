file (GLOB EXAMPLE_2_FILES "./*.cpp")

add_executable( example_2 ${EXAMPLE_2_FILES})

target_include_directories(example_2 PUBLIC
						  "${PROJECT_SOURCE_DIR}/include"
                          "${PROJECT_SOURCE_DIR}/include/core"
                          "${PROJECT_SOURCE_DIR}/include/core/node"
                          "${PROJECT_SOURCE_DIR}/include/core/relation"
                          "${PROJECT_SOURCE_DIR}/include/core/feature"
                          "${PROJECT_SOURCE_DIR}/include/core/db"
                          "${PROJECT_SOURCE_DIR}/include/core/utils"
                          "${PROJECT_SOURCE_DIR}/include/core/query"
						  )

target_link_libraries(example_2
                      SpiderWebDB
                      pthread)