
# include the GExL specific macros
include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

# add the GExL sources path
include_directories(${PROJECT_SOURCE_DIR}/examples/Case)

# set the output directory for GExL libraries
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

# set the source directory for include and source files
set(INCROOT ${PROJECT_SOURCE_DIR}/examples/Case)
set(SRCROOT ${PROJECT_SOURCE_DIR}/examples/Case)


# core library source files
set(SRC
	${SRCROOT}/Case.cpp
)

add_executable(Case ${SRC})
target_link_libraries(Case gexl)