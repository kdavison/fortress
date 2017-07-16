cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(CEF_DOWNLOAD_ROOT http://opensource.spotify.com/cefbuilds)
if(MSVC) #windows
  set(CEF_DOWNLOAD "${CEF_DOWNLOAD_ROOT}/cef_binary_3.3071.1634.g9cc59c8_windows64.tar.bz2")
  set(CEF_DOWNLOAD_HASH 12b3b5eb0155db9c5a39502b104ab01642a18774)
elseif(APPLE)
  if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CEF_DOWNLOAD "${CEF_DOWNLOAD_ROOT}/cef_binary_3.3071.1637.gcb6cf75_macosx64.tar.bz2")
    set(CEF_DOWNLOAD_HASH 510a777e782b95050f3e2846bac1918840987728)
  else()
    #not supported
  endif()
elseif(UNIX AND NOT APPLE)
  set(CEF_DOWNLOAD "${CEF_DOWNLOAD_ROOT}/cef_binary_3.3071.1636.g2718da5_linux64.tar.bz2")
  set(CEF_DOWNLOAD_HASH 517532af36f0b53e4821c9f52672c3a6232a19ef)
endif()

set(CEF_CMAKE_OPTIONS
  -G "Unix Makefiles"
  -DCMAKE_BUILD_TYPE=Release
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)

ExternalProject_Add(
  project_cef
  PREFIX cef
  URL ${CEF_DOWNLOAD}
  URL_HASH SHA1=${CEF_DOWNLOAD_HASH}
  CMAKE_ARGS ${CEF_CMAKE_OPTIONS}
  BUILD_COMMAND $(MAKE) libcef_dll_wrapper
#  INSTALL_COMMAND $(MAKE) install
  INSTALL_COMMAND pwd &&
    ${CMAKE_COMMAND} -E copy libcef_dll_wrapper/libcef_dll_wrapper.a ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libcef_dll_wrapper.a &&
    ${CMAKE_COMMAND} -E copy_directory ../project_cef/Release ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} &&
    ${CMAKE_COMMAND} -E copy_directory ../project_cef/include ${ARTIFACT_DIRECTORY}/include/cef/include &&
    ${CMAKE_COMMAND} -E copy_directory ../project_cef/Resources ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
)


