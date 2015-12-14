set(EXAMPLE_NAME SDLAssets)
# include the GExL specific macros
include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

# add the GExL sources path
include_directories(${PROJECT_SOURCE_DIR}/examples/${EXAMPLE_NAME})

# set the output directory for GExL libraries
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

# set the source directory for include and source files
set(INCROOT ${PROJECT_SOURCE_DIR}/examples/${EXAMPLE_NAME})
set(SRCROOT ${PROJECT_SOURCE_DIR}/examples/${EXAMPLE_NAME})

set(INC 
	${INCROOT}/FontAsset.hpp
	${INCROOT}/FontHandler.hpp
	${INCROOT}/MusicAsset.hpp
	${INCROOT}/MusicHandler.hpp	
	${INCROOT}/TextureAsset.hpp
	${INCROOT}/TextureHandler.hpp
)
# source files
set(SRC
	${SRCROOT}/FontAsset.cpp
	${SRCROOT}/FontHandler.cpp
	${SRCROOT}/MusicAsset.cpp
	${SRCROOT}/MusicHandler.cpp
	${SRCROOT}/TextureAsset.cpp
	${SRCROOT}/TextureHandler.cpp
	${SRCROOT}/Texture.cpp
	${SRCROOT}/SDLAssets.cpp
)
find_package(SDL2 REQUIRED)
find_package (SDL2_image REQUIRED)
find_package (SDL2_ttf REQUIRED)
find_package (SDL2_mixer REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2MIXER_INCLUDE_DIR} )
add_executable(${EXAMPLE_NAME} ${SRC} ${INC})

TARGET_LINK_LIBRARIES(${EXAMPLE_NAME} ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY} ${SDL2TTF_LIBRARY} ${SDL2MIXER_LIBRARY})
TARGET_LINK_LIBRARIES(${EXAMPLE_NAME} gexl)