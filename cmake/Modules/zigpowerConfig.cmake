INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_ZIGPOWER zigpower)

FIND_PATH(
    ZIGPOWER_INCLUDE_DIRS
    NAMES zigpower/api.h
    HINTS $ENV{ZIGPOWER_DIR}/include
        ${PC_ZIGPOWER_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    ZIGPOWER_LIBRARIES
    NAMES gnuradio-zigpower
    HINTS $ENV{ZIGPOWER_DIR}/lib
        ${PC_ZIGPOWER_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ZIGPOWER DEFAULT_MSG ZIGPOWER_LIBRARIES ZIGPOWER_INCLUDE_DIRS)
MARK_AS_ADVANCED(ZIGPOWER_LIBRARIES ZIGPOWER_INCLUDE_DIRS)

