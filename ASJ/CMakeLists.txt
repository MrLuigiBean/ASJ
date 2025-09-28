# CMakeList.txt : CMake project for ASJ, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ASJ")

find_package(cargs CONFIG REQUIRED)

# Add source to this project's executable.
add_executable (ASJ "main.cpp")

target_link_libraries(ASJ PRIVATE cargs)

# Thank you https://stackoverflow.com/a/50306091/30412497 !
set_target_properties(ASJ PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Executable")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ASJ PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
