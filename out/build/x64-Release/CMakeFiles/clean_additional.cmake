# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "hospital\\CMakeFiles\\tables_init_autogen.dir\\AutogenUsed.txt"
  "hospital\\CMakeFiles\\tables_init_autogen.dir\\ParseCache.txt"
  "hospital\\CMakeFiles\\test_autogen.dir\\AutogenUsed.txt"
  "hospital\\CMakeFiles\\test_autogen.dir\\ParseCache.txt"
  "hospital\\tables_init_autogen"
  "hospital\\test_autogen"
  )
endif()
