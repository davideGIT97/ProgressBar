# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/progress_bar_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/progress_bar_autogen.dir/ParseCache.txt"
  "progress_bar_autogen"
  )
endif()
