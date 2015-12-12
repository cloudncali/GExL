
# include the GExL specific macros
include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

# add the GExL sources path
include_directories(${PROJECT_SOURCE_DIR}/src)

# set the output directory for GExL libraries
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

# set the source directory for include and source files
set(INCROOT ${PROJECT_SOURCE_DIR}/include/GExL)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/GExL)

# GExL needs to export symbols when build so define the export flag
add_definitions(-DGExL_EXPORTS)

# Library public header include file
set(HEADER ${INCROOT}/GExL/GExL.hpp)

# Library additional include files
set(INC
	${INCROOT}/GExL_types.hpp
	${INCROOT}/utils/TTimer.hpp
	${INCROOT}/utils/MathUtil.hpp
	${INCROOT}/utils/Math_types.hpp
	${INCROOT}/utils/StringUtil.hpp
	${INCROOT}/utils/String_types.hpp
	${INCROOT}/utils/TParser.hpp
	${INCROOT}/assets/AssetManager.hpp
	${INCROOT}/assets/IAssetHandler.hpp
	${INCROOT}/assets/TAsset.hpp
	${INCROOT}/assets/TAssetHandler.hpp	
	${INCROOT}/logger/FatalLogger.hpp
	${INCROOT}/logger/FileLogger.hpp
	${INCROOT}/logger/ScopeLogger.hpp
	${INCROOT}/logger/StringLogger.hpp
	${INCROOT}/logger/ILogger.hpp
	${INCROOT}/logger/Log_macros.hpp
	${INCROOT}/container/TList.hpp
	${INCROOT}/container/TArray.hpp
	${INCROOT}/container/TArray2D.hpp
	${INCROOT}/container/TArray3D.hpp
	${INCROOT}/logger/onullstream
)

# core library source files
set(SRC
	${SRCROOT}/utils/MathUtil.cpp
	${SRCROOT}/utils/StringUtil.cpp
	${SRCROOT}/assets/AssetManager.cpp
	${SRCROOT}/assets/IAssetHandler.cpp
	${SRCROOT}/logger/FatalLogger.cpp
	${SRCROOT}/logger/FileLogger.cpp
	${SRCROOT}/logger/ScopeLogger.cpp
	${SRCROOT}/logger/StringLogger.cpp
	${SRCROOT}/logger/ILogger.cpp
)

if(BUILD_SHARED_LIBS)
  # define the gexl target
  gexl_add_library(gexl
                  HEADER        ${HEADER}
                  HEADER_DIR    ${INCROOT}
                  INCLUDES      ${INC}
                  SOURCES       ${SRC}
                  EXTERNAL_LIBS )
else()
  # define the gexl-core target (for a static build, we use depends to remove LNK4006 and LNK4221 errors with Visual Studio)
  gexl_add_library(gexl
                  HEADER        ${HEADER}
                  HEADER_DIR    ${INCROOT}
                  INCLUDES      ${INC}
                  SOURCES       ${SRC}
                  DEPENDS       )
endif()

# install Config header include file
install(FILES ${INCROOT}/Config.hpp
        DESTINATION include/GExL
        COMPONENT dev)