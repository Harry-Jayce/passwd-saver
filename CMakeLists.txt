
# cmake version constraints
cmake_minimum_required(VERSION 3.23.0 FATAL_ERROR)


# c++ compiler settings
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# project declare_n:
project(try-modern-cmake 
    VERSION 1.0)
# cannot beftore project, otherwise FATAL_ERROR
enable_language(CXX)

# check things is right
message("## CXX_COMPILER_ID: " ${CMAKE_CXX_COMPILER_ID})
message("## CXX_STANDARD: " ${CMAKE_CXX_STANDARD})

cmake_path(SET main_cpp "./src/main.cpp")
message("## src: ${main_cpp}")
add_executable(isolate.out )
target_sources(isolate.out PRIVATE ${main_cpp})

# if platform == linux-x86-64b
# if proj-build-mode == debug

cmake_path(SET debug-output "../debug-linux-x86-64b/")

# set exe parent-dir
set_target_properties(isolate.out PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${debug-output})



# lib_shared-harry_fs
add_library(_shared-harry_fs SHARED "./src/harry_fs.cpp")
# find header
# because isolate.out(target) link _share-harry-fs
# PUBLIC: to find the target of this target, open the public dependencies.
target_include_directories(_shared-harry_fs PUBLIC "./include")

# compiler flags
target_compile_options(
    _shared-harry_fs 
    # turn off Exceptions
    # global
    PUBLIC
    -fno-exceptions
)

# cannot move libxxx.so, else exe cannot run, unless to rebuild code
set_target_properties(_shared-harry_fs PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${debug-output})

# linking
target_link_libraries(
    isolate.out
    PRIVATE
    _shared-harry_fs
)


# else if proj-build-mode == debug
