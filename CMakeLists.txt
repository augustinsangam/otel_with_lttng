cmake_minimum_required(VERSION 3.22.1)

# Setup vcpkg script with CMake (note: should be placed before project() call)
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

project(otel_with_lttng)

set(CMAKE_CXX_STANDARD 11)

# Autodetect vcpkg toolchain
include($ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

find_package(CURL)
find_package(LTTngUST REQUIRED)
find_package(opentelemetry-cpp CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)


# target = otel_with_lttng
add_executable(otel_with_lttng)
target_include_directories(otel_with_lttng PRIVATE
    ${OPENTELEMETRY_CPP_INCLUDE_DIRS}
    ${LTTNGUST_CPP_INCLUDE_DIRS}
    ${NLOHMANN_JSON_INCLUDE_DIRS}
    ${PROTOBUF_CPP_INCLUDE_DIRS}
    ${GRPC_CPP_INCLUDE_DIRS})
target_link_libraries(otel_with_lttng PRIVATE
    ${OPENTELEMETRY_CPP_LIBRARIES}
    ${LTTNGUST_CPP_LIBRARIES}
    ${NLOHMANN_JSON_CPP_LIBRARIES}
    ${PROTOBUF_CPP_CPP_LIBRARIES}
    ${GRPC_CPP_CPP_LIBRARIES}
    lttng-ust
    dl)

target_include_directories(otel_with_lttng PRIVATE include)
target_sources(otel_with_lttng PRIVATE
    src/main.cpp
    src/lttng_span_exporter.cpp)
