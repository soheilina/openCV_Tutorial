file (GLOB SRC_FILES 
    #${PROJECT_SOURCE_DIR}/*.h
    #${PROJECT_SOURCE_DIR}/**/*.h
    #${PROJECT_SOURCE_DIR}/*.hpp
    #${PROJECT_SOURCE_DIR}/**/*.hpp
    #${PROJECT_SOURCE_DIR}/*.c
    #${PROJECT_SOURCE_DIR}/**/*.c
    ${PROJECT_SOURCE_DIR}/*.cpp 
    ${PROJECT_SOURCE_DIR}/**/*.cpp
)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/header ${CMAKE_SOURCE_DIR}/test ${CMAKE_SOURCE_DIR}/resource)
find_package(OpenCV REQUIRED)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)