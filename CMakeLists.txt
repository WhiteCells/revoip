cmake_minimum_required(VERSION 3.10)

project(voip LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(3rd/spdlog)

set(SRC
    src/singleton.hpp
    src/logger.cc
    src/io_context_pool.cc
    src/server/gui_ws_server.cc
    src/server/ws_session.cc
    src/dialplan_queue.cc
    src/thread_pool.cc
    src/main.cc
)

option(VOIP_SSL "Enable SSL")
option(FEATURE "Feature to build: REMINDER or ROBOT" "REMINDER")

set(FEATURE "REMINDER")
set(VOIP_SSL ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} ${SRC})

if(VOIP_SSL)
    message(">>> target compile definition VOIP_SSL")
    target_compile_definitions(${PROJECT_NAME} PRIVATE VOIP_SSL)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    ${Boost_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME} PRIVATE
    ../third_party/src/lib_json
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    spdlog::spdlog_header_only
    libjsoncpp.a
    /usr/local/lib/libjrtp.so
    ${Boost_LIBRARIES}
    pjsua2-x86_64-pc-linux-gnu 
    pjsua-x86_64-pc-linux-gnu 
    pjsip-ua-x86_64-pc-linux-gnu 
    pjsip-simple-x86_64-pc-linux-gnu 
    pjsip-x86_64-pc-linux-gnu 
    pjmedia-codec-x86_64-pc-linux-gnu 
    pjmedia-videodev-x86_64-pc-linux-gnu 
    pjmedia-audiodev-x86_64-pc-linux-gnu 
    pjmedia-x86_64-pc-linux-gnu 
    pjnath-x86_64-pc-linux-gnu 
    pjlib-util-x86_64-pc-linux-gnu 
    pj-x86_64-pc-linux-gnu 
    srtp-x86_64-pc-linux-gnu 
    resample-x86_64-pc-linux-gnu 
    gsmcodec-x86_64-pc-linux-gnu 
    speex-x86_64-pc-linux-gnu 
    ilbccodec-x86_64-pc-linux-gnu 
    g7221codec-x86_64-pc-linux-gnu 
    yuv-x86_64-pc-linux-gnu 
    webrtc-x86_64-pc-linux-gnu  
    opus 
    ssl 
    crypto 
    vpx 
    upnp 
    ixml 
    uuid 
    rt 
    pthread  
    asound 
    avdevice 
    avformat 
    avcodec 
    swscale 
    avutil 
    v4l2 
    opencore-amrnb 
    opencore-amrwb
    bcg729
)
