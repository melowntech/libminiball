# bump version here
set(miniball_VERSION 1.0)

set(miniball_DEPENDS )

define_module(LIBRARY miniball=${miniball_VERSION}
  DEPENDS)

set(miniball_SOURCES
  miniball.hpp miniball.cpp
)

add_library(miniball STATIC ${miniball_SOURCES})
buildsys_library(miniball)
target_link_libraries(miniball ${MODULE_LIBRARIES})
buildsys_target_compile_definitions(miniball ${MODULE_DEFINITIONS})
