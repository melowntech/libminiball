# bump version here
set(miniball_VERSION 1.1)

set(miniball_DEPENDS )

define_module(LIBRARY miniball=${miniball_VERSION}
  DEPENDS
  BuildSystem>=1.13
  )

set(miniball_SOURCES
  miniball.hpp miniball.cpp
)

add_library(miniball STATIC ${miniball_SOURCES})
buildsys_library(miniball)
target_link_libraries(miniball ${MODULE_LIBRARIES})
target_compile_definitions(miniball PRIVATE ${MODULE_DEFINITIONS})
