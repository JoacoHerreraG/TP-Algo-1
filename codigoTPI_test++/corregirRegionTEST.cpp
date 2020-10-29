#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "../auxiliares.h"

using namespace std;


TEST(corregirRegionTEST, cuatroHogares) {

//                              Región
//                                 v
    eph_h th = {{334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
                {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
                {1366, 2017, 1, 2, 1, 1, 1, 3, 2, 1},
                {1388, 2017, 1, 3, 5, 0, 4, 2, 2, 2}};

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {960,  3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {1366, 1, 2017, 1, 1, 2, 92, -1, 0, -1,    6},
                {1388, 1, 2017, 1, 0, 1, 67, 1,  3, 20000, 1}};

//                                    Región
//                                       v
    eph_h esperado = {{334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
                      {960,  2017, 1, 1, 5, 0, 1, 4, 1, 2},
                      {1366, 2017, 1, 2, 5, 1, 1, 3, 2, 1},
                      {1388, 2017, 1, 3, 5, 0, 4, 2, 2, 2}};

    corregirRegion(th, ti);
    EXPECT_EQ( th, esperado );
}

TEST(corregirRegionTEST, unSoloHogarSinRegionGba) {

    eph_h th = {{334, 2017, 1, 1, 2, 0, 1, 3, 1, 2}};
    eph_i ti = {{334, 1, 2017, 1, 0, 1, 36, 1, 3, 16300, 1}};
    th[0][REGION] = 2;
    eph_h th_esperado = th;

    corregirRegion(th, ti);

    EXPECT_EQ(th_esperado, th);
}
