cmake_minimum_required(VERSION 3.6)
project(analisisHabitacional)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES main.cpp
        auxiliares.cpp
        ejercicios.cpp
        Funciones_TPI.cpp
        codigoTPI_test++/esEncuestaValidaTEST.cpp
        codigoTPI_test++/histHabitacionalTEST.cpp
        codigoTPI_test++/laCasaEstaQuedandoChicaTEST.cpp
        codigoTPI_test++/creceElTeleworkingEnCiudadesGrandesTEST.cpp
        codigoTPI_test++/ordenarRegionYCODUSUTEST.cpp
        codigoTPI_test++/muestraHomogeneaTEST.cpp
        codigoTPI_test++/corregirRegionTEST.cpp
        codigoTPI_test++/indiceGiniTEST.cpp)

add_executable(analisisHabitacional ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "-g -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(analisisHabitacional gtest gtest_main)
