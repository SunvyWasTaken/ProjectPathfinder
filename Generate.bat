@echo off
set currentPath=%cd%

ECHO Initializing CMake project
ECHO =============================
cd %currentPath%
cmake -DCMAKE_TOOLCHAIN_FILE=%currentPath%/vcpkg/scripts/buildsystems/vcpkg.cmake -S %currentPath% -B %currentPath%/build

ECHO =============================
ECHO Install done

PAUSE