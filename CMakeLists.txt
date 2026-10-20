#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  


# Version minima requerida de cmake
cmake_minimum_required(VERSION 3.10)
# Nombre del proyecto
project(classgen)

set(CMAKE_CXX_STANDARD 17)

# Ruta de destino del ejecutable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

# Nombre del ejecutable y clases
add_executable(classgen # nombre del ejecutable
	src/main.cpp
	src/logic/FileManagement.cpp
	src/view/View.cpp
	src/presenter/Presenter.cpp
)

# Directorios
include_directories(src src/logic src/presenter src/view src/model)








