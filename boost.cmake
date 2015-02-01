###FIND PYTHON SHIT

find_package(PythonLibs 2.7 REQUIRED)
if(PYTHONLIBS_FOUND)
    set(PYTHON_LIBRARY "/usr/lib64/libpython2.7.so")
    set(PYTHON_INCLUDE_DIR    "/usr/include/python2.7/")
    include_directories("${PYTHON_INCLUDE_DIRS}")
else()
  message(FATAL_ERROR "Unable to find PythonLibs.")
endif()

### FIND BOOST THINGS
find_package(Boost)
if(Boost_FOUND)
  include_directories("${Boost_INCLUDE_DIRS}")
  ###############################################
  # Setup Boost
  set(Boost_USE_STATIC_LIBS     ON)
  set(Boost_USE_MULTITHREADED    ON)
  set(Boost_USE_STATIC_RUNTIME     ON)
  find_package(Boost COMPONENTS python)

elseif(NOT Boost_FOUND)
  message(FATAL_ERROR "Unable to find correct Boost version. Did you set BOOST_ROOT?")
endif()
