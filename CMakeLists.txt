cmake_minimum_required(VERSION 3.5)
project(modbus_server)
#set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

SET(TOOLCHAIN_DIR  /opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu)
set(CMAKE_SYSROOT  /opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc)
SET(CMAKE_FIND_ROOT_PATH  ${TOOLCHAIN_DIR} ${CMAKE_SYSROOT})
SET(CMAKE_C_COMPILER     ${TOOLCHAIN_DIR}/bin/aarch64-linux-gcc)
SET(CMAKE_CXX_COMPILER   ${TOOLCHAIN_DIR}/bin/aarch64-linux-gnu-g++)
SET(CMAKE_ASM_COMPILER   ${TOOLCHAIN_DIR}/bin/aarch64-linux-gcc)

set(CMAKE_CXX_FLAGS "${GNU_FLAGS} ")
set(CMAKE_C_FLAGS "${GNU_FLAGS}  ")
set(CMAKE_CPU_TYPE "aarch64")

#定义函数，用于递归添加头文件
function(include_sub_directories_recursively root_dir)
    if (IS_DIRECTORY ${root_dir})               #当前路径是一个目录吗，是的话就加入到包含目录
        message("include dir: " ${root_dir})
        include_directories(${root_dir})
    endif()

    file(GLOB ALL_SUB RELATIVE ${root_dir} ${root_dir}/*) #获得当前目录下的所有文件，让如ALL_SUB列表中
    foreach(sub ${ALL_SUB})
        if (IS_DIRECTORY ${root_dir}/${sub})
            include_sub_directories_recursively(${root_dir}/${sub}) #对子目录递归调用，包含
        endif()
    endforeach()
endfunction()

message("CMAKE_SOURCE_DIR=" ${CMAKE_SOURCE_DIR})
include_sub_directories_recursively(${CMAKE_SOURCE_DIR}/include) # 对子目录递归调用，包含

FILE(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

include_directories(/app/aarch64/escu/include
        /app/aarch64/escu/device/data/api/include)
link_directories(/app/aarch64/escu/lib
        /app/aarch64/escu/device/data/api/lib/)

message(sourcefile=${SOURCE_FILES})

LINK_LIBRARIES(dl)
LINK_LIBRARIES(modbus)
LINK_LIBRARIES(pthread)
LINK_LIBRARIES(keyshm)
LINK_LIBRARIES(emushm)
#LINK_LIBRARIES(pcsshm)
LINK_LIBRARIES(esccusoe)
LINK_LIBRARIES(zlog)
LINK_LIBRARIES(arrayshm)
LINK_LIBRARIES(data-api-pcs-all-x)

add_executable(modbusTcpSrv main.cpp  ${SOURCE_FILES} src/soe.cpp include/soe.h)

INSTALL(TARGETS modbusTcpSrv
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/out-${CMAKE_CPU_TYPE}/app/${CMAKE_CPU_TYPE}/lems/service/modbusTcp/
        )

install(CODE "execute_process(COMMAND dos2unix ${CMAKE_SOURCE_DIR}/dep/DEBIAN/changelog)")
install(CODE "execute_process(COMMAND dos2unix ${CMAKE_SOURCE_DIR}/dep/DEBIAN/control)")
install(CODE "execute_process(COMMAND dos2unix ${CMAKE_SOURCE_DIR}/dep/DEBIAN/postinst)")
install(CODE "execute_process(COMMAND dos2unix ${CMAKE_SOURCE_DIR}/dep/DEBIAN/postrm)")
install(CODE "execute_process(COMMAND dos2unix ${CMAKE_SOURCE_DIR}/dep/DEBIAN/preinst)")
install(CODE "execute_process(COMMAND dos2unix ${CMAKE_SOURCE_DIR}/dep/DEBIAN/prerm)")

INSTALL (DIRECTORY ${CMAKE_SOURCE_DIR}/dep/DEBIAN DESTINATION ${CMAKE_SOURCE_DIR}/out-${CMAKE_CPU_TYPE}/)

# 安装 modbus 协议先关 json 文件
# 配置文件不进行拷贝由 eda 工具进行导出
# INSTALL (DIRECTORY ${CMAKE_SOURCE_DIR}/config DESTINATION  ${CMAKE_SOURCE_DIR}/out-${CMAKE_CPU_TYPE}/app/${CMAKE_CPU_TYPE}/lems/service/modbusTcp/)

# 安装服务配置文件
SET(SOURCE_FILE ${CMAKE_SOURCE_DIR}/modbus.conf)
SET(LOG_FILE ${CMAKE_SOURCE_DIR}/modbus_log.conf)
SET(INSTALL_DIR ${CMAKE_SOURCE_DIR}/out-${CMAKE_CPU_TYPE}/app/${CMAKE_CPU_TYPE}/lems/service/modbusTcp/)
INSTALL(FILES ${SOURCE_FILE} DESTINATION ${INSTALL_DIR})
INSTALL(FILES ${LOG_FILE} DESTINATION ${INSTALL_DIR})

install(CODE "execute_process(COMMAND chmod 755 ${CMAKE_SOURCE_DIR}/out-${CMAKE_CPU_TYPE}/DEBIAN -Rf)")
install(CODE "execute_process(COMMAND dpkg-deb -b ${CMAKE_SOURCE_DIR}/out-${CMAKE_CPU_TYPE}/ ${CMAKE_SOURCE_DIR}/out-${CMAKE_CPU_TYPE})")
