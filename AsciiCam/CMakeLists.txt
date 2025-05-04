cmake_minimum_required(VERSION 3.10)
project(AsciiCam CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MACOSX_RPATH ON)

find_package(OpenCV REQUIRED COMPONENTS 
    core 
    imgproc 
    videoio 
    highgui 
    imgcodecs 
    gapi
)

add_executable(AsciiCam
    src/main.cpp
    include/DedSecSymbols.h
)

target_link_libraries(AsciiCam PRIVATE ${OpenCV_LIBS})

set_target_properties(AsciiCam PROPERTIES
    INSTALL_RPATH "@loader_path"
    MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/Info.plist"
)

set_target_properties(AsciiCam PROPERTIES
    MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/Info.plist"
) #хз особо не нужно, просто для apple так надо(info.plist), но и без него работает 