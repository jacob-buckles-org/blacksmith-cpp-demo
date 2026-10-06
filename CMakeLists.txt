cmake_minimum_required(VERSION 3.24)
project(blacksmith_cpp_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include(FetchContent)
set(ABSL_PROPAGATE_CXX_STD ON)
set(ABSL_BUILD_TESTING OFF)
set(BUILD_GMOCK OFF)
set(INSTALL_GTEST OFF)
FetchContent_Declare(absl
  URL https://github.com/abseil/abseil-cpp/archive/refs/tags/20260526.0.tar.gz
  URL_HASH SHA256=6e1aee535473414164bf83e4ebc40240dec71a4701f8a642d906e95bea1aea0c)
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.tar.gz
  URL_HASH SHA256=6e3191c1455468b3fc35a417fb565c1c5071aee1b7e7f85e30cf48a98d37d8b5)
FetchContent_MakeAvailable(absl googletest)

enable_testing()
include(GoogleTest)

function(demo_test name src)
  add_executable(${name} ${src})
  target_link_libraries(${name} PRIVATE ${ARGN} GTest::gtest_main)
  gtest_discover_tests(${name})
endfunction()

add_library(marketdata libs/marketdata/feed_parser.cc)
target_include_directories(marketdata PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(marketdata PUBLIC absl::status absl::statusor absl::strings)
demo_test(feed_parser_test libs/marketdata/feed_parser_test.cc marketdata)

add_library(orderbook libs/orderbook/order_book.cc)
target_link_libraries(orderbook PUBLIC marketdata absl::btree absl::flat_hash_map)
demo_test(order_book_test libs/orderbook/order_book_test.cc orderbook)

add_library(pricing libs/pricing/black_scholes.cc)
target_include_directories(pricing PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
demo_test(black_scholes_test libs/pricing/black_scholes_test.cc pricing)

add_library(risk libs/risk/limits.cc)
target_link_libraries(risk PUBLIC marketdata absl::flat_hash_map absl::status absl::strings)
demo_test(limits_test libs/risk/limits_test.cc risk)

file(GLOB SIGNAL_SRCS CONFIGURE_DEPENDS libs/signals/generated/*.cc)
add_library(signals ${SIGNAL_SRCS})
target_link_libraries(signals PUBLIC marketdata)
demo_test(signals_test libs/signals/signals_test.cc signals absl::flat_hash_set)

add_executable(matcher services/matcher/main.cc)
target_link_libraries(matcher PRIVATE marketdata orderbook pricing signals absl::flat_hash_map absl::str_format)
