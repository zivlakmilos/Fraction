#
# This file is part of Fraction C++ library (https://github.com/zivlakmilos/Fraction).
# Copyright (c) 2020 Miloš Zivlak (milos@zivlak.rs).
# 
# This program is free software: you can redistribute it and/or modify  
# it under the terms of the GNU General Public License as published by  
# the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License 
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 2.8.11)
project(Fraction)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(include/)
include_directories(${CMAKE_BINARY_DIR})

set(project_SRC
    src/fraction.cpp

    src/main.cpp
)

# Tell CMake to create the rrf executable
add_executable(fraction ${project_SRC} ${project_INCLUDE})

# Tell CMake to link the rrf executable
target_link_libraries(fraction)

# Install the executable
install(TARGETS fraction DESTINATION bin)
