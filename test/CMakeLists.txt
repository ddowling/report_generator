# Test programs
include_directories(../src)

add_executable(report_test report_test.cpp)
target_link_libraries(report_test report_generator)

add_executable(test_line_draw test_line_draw.cpp)

add_executable(test_wordwrap test_wordwrap.cpp)
target_link_libraries(test_wordwrap report_generator)

add_executable(test_file test_file.cpp)
target_link_libraries(test_file report_generator)
