#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

#define UMBRAL 0.001

TEST(desigualdadTotalTresHogares,indiceGini){
    eph_h th = {
            {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {200,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
            {334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
    };

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 90, 1},
                {334,  2, 2017, 1, 0, 1, 36, 1,  3, 90, 1},
                {200,  2, 2017, 1, 0, 1, 36, 1,  3, 0, 1},
                {960,  3, 2017, 1, 1, 2, 51, 1,  4, 0,  1},
                {960,  2, 2017, 1, 1, 2, 51, 1,  4, 0,  1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 0,  1}};

    EXPECT_TRUE(flotante_valido(0.5 - (1.0/2)*(1.0/3),indiceGini(th,ti),UMBRAL));
}

TEST(igualdadTotalDosHogares,indiceGini){
    eph_h th = {
            {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
    };

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 1, 1},
                {334,  2, 2017, 1, 0, 1, 36, 1,  3, 1, 1},
                {960,  3, 2017, 1, 1, 2, 51, 1,  4, 1,  1},
                {960,  2, 2017, 1, 1, 2, 51, 1,  4, 1,  1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 1,  1}};

    EXPECT_TRUE(flotante_valido(0,indiceGini(th,ti),UMBRAL));
}


TEST(hogaresConIngresosNoInformados,indiceGini){
    eph_h th = {
            {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {200,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
            {334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
    };

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 90, 1},
                {334,  2, 2017, 1, 0, 1, 36, 1,  3, -1, 1},
                {200,  2, 2017, 1, 0, 1, 36, 1,  3, -1, 1},
                {960,  3, 2017, 1, 1, 2, 51, 1,  4, -1,  1},
                {960,  2, 2017, 1, 1, 2, 51, 1,  4, -1,  1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, -1,  1}};

    EXPECT_TRUE(flotante_valido(0.5 - (1.0/2)*(1.0/3),indiceGini(th,ti),UMBRAL));
}

