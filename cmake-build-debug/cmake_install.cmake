# Install script for directory: /home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp/modbusTcpSrv" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp/modbusTcpSrv")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp/modbusTcpSrv"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp/modbusTcpSrv")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp" TYPE EXECUTABLE FILES "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/cmake-build-debug/modbusTcpSrv")
  if(EXISTS "$ENV{DESTDIR}/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp/modbusTcpSrv" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp/modbusTcpSrv")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp/modbusTcpSrv"
         OLD_RPATH "/app/aarch64/escu/lib:/app/aarch64/escu/device/data/api/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp/modbusTcpSrv")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND dos2unix /home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/dep/DEBIAN/changelog)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND dos2unix /home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/dep/DEBIAN/control)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND dos2unix /home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/dep/DEBIAN/postinst)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND dos2unix /home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/dep/DEBIAN/postrm)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND dos2unix /home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/dep/DEBIAN/preinst)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND dos2unix /home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/dep/DEBIAN/prerm)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64//DEBIAN")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/" TYPE DIRECTORY FILES "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/dep/DEBIAN")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp/modbus.conf")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp" TYPE FILE FILES "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/modbus.conf")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp/modbus_log.conf")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/app/aarch64/lems/service/modbusTcp" TYPE FILE FILES "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/modbus_log.conf")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND chmod 755 /home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/DEBIAN -Rf)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND dpkg-deb -b /home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64/ /home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/out-aarch64)
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/huanglingjie/MyProject/tmp/tmp.pfEV66cmZr88888/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
