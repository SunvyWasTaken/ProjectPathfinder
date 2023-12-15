@echo off
set currentPath=%cd%

ECHO Initializing vcpkg
ECHO =============================
cmd /c "cd lib/vcpkg && bootstrap-vcpkg.bat -disableMetrics"

ECHO Initializing vcpkg packages
ECHO =============================
cd lib/vcpkg
vcpkg install sfml
vcpkg install imgui
vcpkg install imgui-sfml

ECHO Initializing CMake project
ECHO =============================
cd %currentPath%
cmake -DCMAKE_TOOLCHAIN_FILE=%currentPath%/lib/vcpkg/scripts/buildsystems/vcpkg.cmake -S %currentPath% -B %currentPath%/build

ECHO =============================
ECHO Install done

PAUSE