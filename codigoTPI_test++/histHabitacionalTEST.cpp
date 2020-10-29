#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(histHabitacionalTEST, escaleraArriba) {

//                              Región   #Habitaciones
//                                 v        v
    eph_h th = {{334,  2017, 1, 1, 1, 0, 1, 3, 1, 2},
                {960,  2017, 1, 1, 1, 0, 1, 2, 1, 2},
                {1366, 2017, 1, 2, 1, 1, 1, 1, 1, 1},
                {1550, 2017, 1, 3, 2, 0, 1, 5, 2, 2}, // Esta no: Es de otra región
                {1388, 2017, 1, 3, 1, 0, 1, 2, 2, 2},
                {18,   2017, 1, 3, 1, 0, 1, 3, 2, 2},
                {1500, 2017, 1, 3, 1, 0, 1, 3, 2, 2}};

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1500, 1, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1550, 1, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {18,   1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {1366, 1, 2017, 1, 1, 2, 92, -1, 0, -1,    6},
                {1388, 1, 2017, 1, 0, 1, 67, 1,  3, 20000, 1},
                {1388, 2, 2017, 1, 0, 1, 67, 1,  3, 20000, 1}};

    vector<int> resultado_esperado = {1, 2, 3};
    EXPECT_EQ( resultado_esperado, histHabitacional(th, ti, 1) );
}

TEST(histHabitacionalTEST, escaleraAbajo) {

//                              Región   #Habitaciones
//                                 v        v
    eph_h th = {{334,  2017, 1, 1, 1, 0, 1, 1, 1, 2},
                {960,  2017, 1, 1, 1, 0, 1, 2, 1, 2},
                {1366, 2017, 1, 2, 1, 1, 1, 1, 1, 1},
                {1550, 2017, 1, 3, 2, 0, 1, 5, 2, 2}, // Esta no: Es de otra región
                {1888, 2017, 1, 3, 1, 0, 2, 2, 2, 2}, // Esta no: Es Depto.
                {1388, 2017, 1, 3, 1, 0, 1, 2, 2, 2},
                {18,   2017, 1, 3, 1, 0, 1, 1, 1, 2},
                {1500, 2017, 1, 3, 1, 0, 1, 3, 2, 2}};

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1500, 1, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1550, 1, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {18,   1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {1366, 1, 2017, 1, 1, 2, 92, -1, 0, -1,    6},
                {1388, 1, 2017, 1, 0, 1, 67, 1,  3, 20000, 1},
                {1888, 1, 2017, 1, 0, 1, 67, 1,  3, 20000, 1}};

    vector<int> resultado_esperado = {3, 2, 1};
    EXPECT_EQ( resultado_esperado, histHabitacional(th, ti, 1) );
}


TEST(histHabitacionalTEST, eph2016_NOA) {
    eph_h th;
    eph_i ti;
    leerEncuesta ( "eph_3c_2016_100", th, ti );

    vector<int> resultado_esperado = {0, 4, 3, 2, 0, 2};
    EXPECT_EQ( resultado_esperado, histHabitacional(th, ti, 2) );
}


TEST(histHabitacionalTEST, eph2018_PATAGONIA) {
    eph_h th;
    eph_i ti;
    leerEncuesta ( "eph_3c_2018", th, ti );

    vector<int> resultado_esperado = {154, 428, 690, 481, 145, 50, 19, 2, 3, 0, 1 };
    EXPECT_EQ( resultado_esperado, histHabitacional(th, ti, 6) );
}
