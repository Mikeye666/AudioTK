
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
if(COMPILER_SUPPORTS_CXX14)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
else(COMPILER_SUPPORTS_CXX14)
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} doesn't support C++14.")
  CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
  if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  else(COMPILER_SUPPORTS_CXX11)
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} doesn't support C++11.")
  endif(COMPILER_SUPPORTS_CXX11)
endif(COMPILER_SUPPORTS_CXX14)

if(ENABLE_PROFILE_INFO)
  CHECK_CXX_COMPILER_FLAG("-fopt-info" COMPILER_SUPPORTS_fopt_info)
  if(COMPILER_SUPPORTS_fopt_info)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopt-info")
  else(COMPILER_SUPPORTS_fopt_info)
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} doesn't support -fopt-info.")
  endif(COMPILER_SUPPORTS_fopt_info)
endif(ENABLE_PROFILE_INFO)

CHECK_CXX_COMPILER_FLAG("-Werror=inconsistent-missing-override" COMPILER_HAS_INCONSISTENT_MISSING_OVERRIDE)
if(COMPILER_HAS_INCONSISTENT_MISSING_OVERRIDE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=inconsistent-missing-override")
else(COMPILER_HAS_INCONSISTENT_MISSING_OVERRIDE)
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} doesn't support -Werror=inconsistent-missing-override.")
endif(COMPILER_HAS_INCONSISTENT_MISSING_OVERRIDE)

if(DISABLE_EIGEN_WARNINGS)
  CHECK_CXX_COMPILER_FLAG("-Wno-deprecated-declarations" COMPILER_SUPPORTS_DEPRECATED_DECLARATIONS)
  if(COMPILER_SUPPORTS_DEPRECATED_DECLARATIONS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
  else(COMPILER_SUPPORTS_DEPRECATED_DECLARATIONS)
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} doesn't support -Wno-deprecated-declarations.")
  endif(COMPILER_SUPPORTS_DEPRECATED_DECLARATIONS)

  CHECK_CXX_COMPILER_FLAG("-Wno-ignored-attributes" COMPILER_SUPPORTS_IGNORED_ATTRIBUTES)
  if(COMPILER_SUPPORTS_IGNORED_ATTRIBUTES)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-ignored-attributes")
  else(COMPILER_SUPPORTS_IGNORED_ATTRIBUTES)
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} doesn't support -Wno-ignored-attributes.")
  endif(COMPILER_SUPPORTS_IGNORED_ATTRIBUTES)
endif(DISABLE_EIGEN_WARNINGS)
