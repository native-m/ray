# ray

file(GLOB_RECURSE
     RAY_SOURCE_FILES
     CONFIGURE_DEPENDS
     "*.cpp"
     "*.c")

file(GLOB_RECURSE
     RAY_HEADER_FILES
     CONFIGURE_DEPENDS
     "*.hpp")

add_executable(ray)
target_sources(ray
               PRIVATE ${RAY_SOURCE_FILES}
               PRIVATE ${RAY_HEADER_FILES})
target_link_libraries(ray
                      PRIVATE raycore)
