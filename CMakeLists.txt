cmake_minimum_required(VERSION 3.24)
project(blockchianOpenSSL)

set(CMAKE_CXX_STANDARD 17)

add_executable(blockchianOpenSSL main.cpp blockchain.h forward.h avl.h node.h record.h block.h chainhash.h reader.h)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

target_link_libraries(blockchianOpenSSL ${OPENSSL_LIBRARIES})
