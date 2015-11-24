# core library public header include file
set(CORE_HEADER ${INCROOT}.hpp)

# core library additional include files
set(INC
	${INCROOT}_types.hpp
	${INCROOT}/classes/AssetManager.hpp
	${INCROOT}/classes/VersionInfo.hpp
	${INCROOT}/interfaces/IAssetHandler.hpp
	${INCROOT}/interfaces/ILogger.hpp
	${INCROOT}/templates/TArray.hpp
	${INCROOT}/templates/TArray2D.hpp
	${INCROOT}/templates/TArray3D.hpp
	${INCROOT}/templates/TAsset.hpp
	${INCROOT}/templates/TAssetHandler.hpp
	${INCROOT}/templates/TList.hpp
	${INCROOT}/templates/TParser.hpp
	${INCROOT}/templates/TTimer.hpp
	${INCROOT}/loggers/FatalLogger.hpp
	${INCROOT}/loggers/FileLogger.hpp
	${INCROOT}/loggers/ScopeLogger.hpp
	${INCROOT}/loggers/StringLogger.hpp
	${INCROOT}/loggers/Log_macros.hpp
	${INCROOT}/loggers/onullstream
	${INCROOT}/utils/MathUtil.hpp
	${INCROOT}/utils/StringUtil.hpp
)

# core library source files
set(SRC
	${SRCROOT}/classes/AssetManager.cpp
	${SRCROOT}/classes/VersionInfo.cpp
	${SRCROOT}/interfaces/IAssetHandler.cpp
	${SRCROOT}/interfaces/ILogger.cpp
	${SRCROOT}/loggers/FatalLogger.cpp
	${SRCROOT}/loggers/FileLogger.cpp
	${SRCROOT}/loggers/ScopeLogger.cpp
	${SRCROOT}/loggers/StringLogger.cpp
	${SRCROOT}/utils/MathUtil.cpp
	${SRCROOT}/utils/StringUtil.cpp
)

if(BUILD_SHARED_LIBS)
  # define the gexl-core target
  gexl_add_library(gexl
                  HEADER        ${CORE_HEADER}
                  HEADER_DIR    ${INCROOT}
                  INCLUDES      ${INC}
                  SOURCES       ${SRC}
                  EXTERNAL_LIBS )
else()
  # define the gexl-core target (for a static build, we use depends to remove LNK4006 and LNK4221 errors with Visual Studio)
  gexl_add_library(gexl
                  HEADER        ${CORE_HEADER}
                  HEADER_DIR    ${INCROOT}
                  INCLUDES      ${INC}
                  SOURCES       ${SRC}
                  DEPENDS       )
endif()
