include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0 # release-1.13.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file (GLOB_RECURSE TEST_FILES "*.cc")

add_executable(
  test_exe
  ${TEST_FILES}
)
target_link_libraries(
    test_exe
  GTest::gtest_main
  SpiderWebDB
)

target_include_directories(test_exe PUBLIC
						  "${PROJECT_SOURCE_DIR}/include"
                          "${PROJECT_SOURCE_DIR}/include/core"
                          "${PROJECT_SOURCE_DIR}/include/core/node"
                          "${PROJECT_SOURCE_DIR}/include/core/relation"
                          "${PROJECT_SOURCE_DIR}/include/core/feature"
                          "${PROJECT_SOURCE_DIR}/include/core/db"
                          "${PROJECT_SOURCE_DIR}/include/core/utils"
						  )

include(GoogleTest)
gtest_discover_tests(test_exe)