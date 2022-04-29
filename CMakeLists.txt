cmake_minimum_required(VERSION 3.0)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER /apps/stone/bin/gcc)
set(CMAKE_CXX_COMPILER /apps/stone/bin/g++)
project(stone)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include (cmake/utils.cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")
set(CMAKE_C_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")



include_directories(.)
include_directories(/apps/stone/include)
include_directories(/usr/local/include)
#include_directories(/usr/local/include/mysql)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdpart)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdpart/tinyxml2-7.0.1)
include_directories(/usr/include)
include_directories(/usr/include/jsoncpp/)
link_directories(/apps/stone/lib)
link_directories(/apps/stone/lib64)
link_directories(/usr/lib)
link_directories(/usr/local/lib/)
link_directories(/usr/lib64)
#link_directories(/usr/lib64/mysql)
option(BUILD_TEST "ON for complile test" OFF)

find_package(Boost REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()


set(LIB_SRC
    src/address.cpp
    src/bytearray.cpp
    src/config.cpp
    src/db/sqlite3.cpp
    src/email/email.cpp
    src/env.cpp
    src/daemon.cpp
    src/fd_manager.cpp
    src/fiber.cpp
    src/http/http.cpp
    src/http/http_connection.cpp
    src/http/http_parser.cpp
    src/http/http_session.cpp
    src/http/session_data.cpp
    src/http/http_server.cpp
    src/http/servlet.cpp
    src/hook.cpp
    src/iomanager.cpp
    src/library.cpp
    src/log.cpp
    src/module.cpp
    src/mutex.cpp
    src/scheduler.cpp
    src/socket.cpp
    src/stream.cpp
    src/socket_stream.cpp
    src/tcp_server.cpp
    src/timer.cpp
    src/thread.cpp
    src/util.cpp
    src/util/json_util.cpp
    src/util/hash_util.cpp
    src/application.cpp
    )

ragelmaker(src/http/http11_parser.rl LIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/http)
ragelmaker(src/http/httpclient_parser.rl LIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/http)
ragelmaker(src/uri.rl LIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(stone SHARED ${LIB_SRC})
force_redefine_file_macro_for_sources(stone)
#add_library(stone_static STATIC ${LIB_SRC})
#SET_TARGET_PROPERTIES (stone_static PROPERTIES OUTPUT_NAME "stone")

find_library(PTHREAD pthread)
#set(LIBS ${LIBS} stone)
#set(LIBS ${LIBS} dl)
#set(LIBS ${LIBS} ${YAMLCPP})
#set(LIBS ${LIBS} ${PTHREAD})

set(LIBS
        stone 
        dl
        pthread
        sqlite3
        tinyxml2
        jsoncpp
yaml-cpp -ldl
        )
#stone_add_executable(test_util "tests/test_util.cpp" stone "${LIBS}")
#stone_add_executable(test_hashmultimap "tests/test_hashmultimap.cpp" stone "${LIBS}")
#stone_add_executable(test_hashmap "tests/test_hashmap.cpp" stone "${LIBS}")
#stone_add_executable(test_dict "tests/test_dict.cpp" stone "${LIBS}")
#stone_add_executable(test_array "tests/test_array.cpp" stone "${LIBS}")
set(BUILD_TEST OFF)
if(BUILD_TEST)
stone_add_executable(test1 "tests/test.cpp" stone "${LIBS}")
stone_add_executable(test_config "tests/test_config.cpp" stone "${LIBS}")
stone_add_executable(test_thread "tests/test_thread.cpp" stone "${LIBS}")
stone_add_executable(test_fiber "tests/test_fiber.cpp" stone "${LIBS}")
stone_add_executable(test_scheduler "tests/test_scheduler.cpp" stone "${LIBS}")
stone_add_executable(test_iomanager "tests/test_iomanager.cpp" stone "${LIBS}")
stone_add_executable(test_hook "tests/test_hook.cpp" stone "${LIBS}")
stone_add_executable(test_address "tests/test_address.cpp" stone "${LIBS}")
stone_add_executable(test_socket "tests/test_socket.cpp" stone "${LIBS}")
#stone_add_executable(test_bytearray "tests/test_bytearray.cpp" stone "${LIBS}")
stone_add_executable(test_http "tests/test_http.cpp" stone "${LIBS}")
stone_add_executable(test_http_parser "tests/test_http_parser.cpp" stone "${LIBS}")
stone_add_executable(test_tcp_server "tests/test_tcp_server.cpp" stone "${LIBS}")
stone_add_executable(echo_server "examples/echo_server.cpp" stone "${LIBS}")
stone_add_executable(test_http_server "tests/test_http_server.cpp" stone "${LIBS}")
#stone_add_executable(test_uri "tests/test_uri.cpp" stone "${LIBS}")
stone_add_executable(my_http_server "samples/my_http_server.cpp" stone "${LIBS}")

#stone_add_executable(echo_server_udp "examples/echo_server_udp.cpp" stone "${LIBS}")
#stone_add_executable(echo_udp_client "examples/echo_udp_client.cpp" stone "${LIBS}")

stone_add_executable(test_daemon "tests/test_daemon.cpp" stone "${LIBS}")
#stone_add_executable(test_env "tests/test_env.cpp" stone "${LIBS}")
#stone_add_executable(test_ws_server "tests/test_ws_server.cpp" stone "${LIBS}")
#stone_add_executable(test_ws_client "tests/test_ws_client.cpp" stone "${LIBS}")
stone_add_executable(test_application "tests/test_application.cpp" stone "${LIBS}")

#stone_add_executable(test_http_connection "tests/test_http_connection.cpp" stone "${LIBS}")
#stone_add_executable(test_lru "tests/test_lru.cpp" stone "${LIBS}")
#stone_add_executable(test_timed_cache "tests/test_timed_cache.cpp" stone "${LIBS}")
#stone_add_executable(test_timed_lru_cache "tests/test_timed_lru_cache.cpp" stone "${LIBS}")
#stone_add_executable(test_zlib_stream "tests/test_zlib_stream.cpp" stone "${LIBS}")

endif()
#stone_add_executable(test_crypto "tests/test_crypto.cpp" stone "${LIBS}")
#stone_add_executable(test_sqlite3 "tests/test_sqlite3.cpp" stone "${LIBS}")
#stone_add_executable(test_rock "tests/test_rock.cpp" stone "${LIBS}")
#stone_add_executable(test_email  "tests/test_email.cpp" stone "${LIBS}")
#stone_add_executable(test_mysql "tests/test_mysql.cpp" stone "${LIBS}")
#stone_add_executable(test_nameserver "tests/test_nameserver.cpp" stone "${LIBS}")
#stone_add_executable(test_bitmap "tests/test_bitmap.cpp" stone "${LIBS}")
#stone_add_executable(test_zkclient "tests/test_zookeeper.cpp" stone "${LIBS}")
#stone_add_executable(test_service_discovery "tests/test_service_discovery.cpp" stone "${LIBS}")

set(ORM_SRCS
    src/orm/table.cpp
    src/orm/column.cpp
    src/orm/index.cpp
    src/orm/orm.cpp
    src/orm/util.cpp
    )
stone_add_executable(orm "${ORM_SRCS}" stone "${LIBS}")

#add_library(test_module SHARED tests/test_module.cpp)

stone_add_executable(bin_stone "src/main.cpp" stone "${LIBS}")
set_target_properties(bin_stone PROPERTIES OUTPUT_NAME "stone")

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/orm_out)
#set(OLIBS ${LIBS} orm_data)
#src_add_executable(test_orm "tests/test_orm.cpp" orm_data "${OLIBS}")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

