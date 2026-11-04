add_executable(complex_test complex_test.cpp)
target_link_libraries(complex_test PRIVATE complex)

add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test PRIVATE rational)
target_include_directories(rational_test PRIVATE ${CMAKE_SOURCE_DIR}/prj.thirdparty)