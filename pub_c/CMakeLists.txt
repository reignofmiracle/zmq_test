project ("pub_c")

# gcc
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# pub_c
add_executable(
    main
    main.cpp)

target_link_libraries(
    main
    zmq)