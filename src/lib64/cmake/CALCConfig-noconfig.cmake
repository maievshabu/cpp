#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "CALC::CALC" for configuration ""
set_property(TARGET CALC::CALC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(CALC::CALC PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/mnt/c/work/untitled/src/lib64/libCALC.so"
  IMPORTED_SONAME_NOCONFIG "libCALC.so"
  )

list(APPEND _cmake_import_check_targets CALC::CALC )
list(APPEND _cmake_import_check_files_for_CALC::CALC "/mnt/c/work/untitled/src/lib64/libCALC.so" )

# Import target "CALC::CALC-STATIC" for configuration ""
set_property(TARGET CALC::CALC-STATIC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(CALC::CALC-STATIC PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "/mnt/c/work/untitled/src/lib64/libCALC-STATIC.a"
  )

list(APPEND _cmake_import_check_targets CALC::CALC-STATIC )
list(APPEND _cmake_import_check_files_for_CALC::CALC-STATIC "/mnt/c/work/untitled/src/lib64/libCALC-STATIC.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
