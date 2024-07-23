cmake_minimum_required(VERSION 3.19)

project(PVZHooker)


aux_source_directory(. SOURCE_FILES)

add_library(PVZHooker SHARED ${SOURCE_FILES})

# add_executable(PVZHooker ${SOURCE_FILES})

# add_library(PVZHooker SHARED breeze_pvz_cheater_utils_PVZHooker.h PVZHooker.cpp)
# add_executable(PVZHooker breeze_pvz_cheater_utils_PVZHooker.h PVZHooker.cpp PVZTools.cpp PVZTools.h)
# 设置 JNI 路径
set(JNI_PATH C:/1Data/1Environment/Java/java1.8/jdk1.8/include)

# 指定 JNI
target_include_directories(PVZHooker PUBLIC ${JNI_PATH})

target_include_directories(PVZHooker PUBLIC ${JNI_PATH}/win32)