# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/mnt/c/Users/LAB1223/Desktop/PTSD-Practice-Giraffe-Adventure/PTSD"
  "/mnt/c/Users/LAB1223/Desktop/PTSD-Practice-Giraffe-Adventure/_deps/ptsd-build"
  "/mnt/c/Users/LAB1223/Desktop/PTSD-Practice-Giraffe-Adventure/_deps/ptsd-subbuild/ptsd-populate-prefix"
  "/mnt/c/Users/LAB1223/Desktop/PTSD-Practice-Giraffe-Adventure/_deps/ptsd-subbuild/ptsd-populate-prefix/tmp"
  "/mnt/c/Users/LAB1223/Desktop/PTSD-Practice-Giraffe-Adventure/_deps/ptsd-subbuild/ptsd-populate-prefix/src/ptsd-populate-stamp"
  "/mnt/c/Users/LAB1223/Desktop/PTSD-Practice-Giraffe-Adventure/_deps/ptsd-subbuild/ptsd-populate-prefix/src"
  "/mnt/c/Users/LAB1223/Desktop/PTSD-Practice-Giraffe-Adventure/_deps/ptsd-subbuild/ptsd-populate-prefix/src/ptsd-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/c/Users/LAB1223/Desktop/PTSD-Practice-Giraffe-Adventure/_deps/ptsd-subbuild/ptsd-populate-prefix/src/ptsd-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/c/Users/LAB1223/Desktop/PTSD-Practice-Giraffe-Adventure/_deps/ptsd-subbuild/ptsd-populate-prefix/src/ptsd-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
