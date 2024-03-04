include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        f8d7d77c06936315286eb55f8de22cd23c188571 #release 1.14.0
)
FetchContent_MakeAvailable(googletest)

add_executable(part1_test part1_test.cpp)
target_compile_options(part1_test PRIVATE -fsanitize=address)
target_link_options(part1_test PRIVATE -fsanitize=address)
target_link_libraries(part1_test
  PRIVATE
  node
  gtest_main
  gmock_main)

add_executable(part2_test part2_test.cpp)
target_compile_options(part2_test PRIVATE -fsanitize=address)
target_link_options(part2_test PRIVATE -fsanitize=address)
target_link_libraries(part2_test  
  PRIVATE
  linked_list
  gtest_main
  gmock_main)

include(GoogleTest)
gtest_discover_tests(part1_test)
gtest_discover_tests(part2_test)
