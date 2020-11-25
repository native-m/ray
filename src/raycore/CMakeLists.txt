# raycore

file(GLOB_RECURSE
     RC_SOURCE_FILES
     CONFIGURE_DEPENDS
     "*.cpp"
     "*.c")

file(GLOB_RECURSE
     RC_HEADER_FILES
     CONFIGURE_DEPENDS
     "*.hpp")

add_library(raycore)
target_sources(raycore
               PRIVATE ${RC_SOURCE_FILES}
               PRIVATE ${RC_HEADER_FILES})
target_include_directories(raycore
                           PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
                           PUBLIC ${CMAKE_SOURCE_DIR}/deps/entt/include
                           PRIVATE ${CMAKE_SOURCE_DIR}/deps/stb/include)
target_precompile_headers(raycore
                          PRIVATE $<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeader.hpp>)
