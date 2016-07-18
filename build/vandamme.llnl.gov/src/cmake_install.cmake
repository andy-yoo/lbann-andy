# Install script for directory: /Users/vanessen1/Research/DeepLearning/lbann.git/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/vanessen1/Research/DeepLearning/lbann.git/build/vandamme.llnl.gov")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/vanessen1/Research/DeepLearning/lbann.git/build/vandamme.llnl.gov/src/data_readers/cmake_install.cmake")
  include("/Users/vanessen1/Research/DeepLearning/lbann.git/build/vandamme.llnl.gov/src/layers/cmake_install.cmake")
  include("/Users/vanessen1/Research/DeepLearning/lbann.git/build/vandamme.llnl.gov/src/models/cmake_install.cmake")
  include("/Users/vanessen1/Research/DeepLearning/lbann.git/build/vandamme.llnl.gov/src/optimizers/cmake_install.cmake")
  include("/Users/vanessen1/Research/DeepLearning/lbann.git/build/vandamme.llnl.gov/src/callbacks/cmake_install.cmake")
  include("/Users/vanessen1/Research/DeepLearning/lbann.git/build/vandamme.llnl.gov/src/io/cmake_install.cmake")
  include("/Users/vanessen1/Research/DeepLearning/lbann.git/build/vandamme.llnl.gov/src/utils/cmake_install.cmake")
  include("/Users/vanessen1/Research/DeepLearning/lbann.git/build/vandamme.llnl.gov/src/regularization/cmake_install.cmake")

endif()

