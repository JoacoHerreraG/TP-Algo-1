#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(esEncuestaValidaTEST, valida) {

    eph_h th = {{334,  2017, 1, 1, 6, 0, 1, 3, 1, 2},
                {960,  2017, 1, 1, 2, 0, 1, 4, 1, 2},
                {1366, 2017, 1, 2, 4, 1, 1, 3, 2, 1},
                {1388, 2017, 1, 3, 2, 0, 4, 2, 2, 2}};

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {960,  3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {1366, 1, 2017, 1, 1, 2, 92, -1, 0, -1,    6},
                {1388, 1, 2017, 1, 0, 1, 67, 1,  3, 20000, 1}};

    EXPECT_TRUE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaSinHogares) {

    eph_h th = {};

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {960,  3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {1366, 1, 2017, 1, 1, 2, 92, -1, 0, -1,    6},
                {1388, 1, 2017, 1, 0, 1, 67, 1,  3, 20000, 1}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}


TEST(esEncuestaValidaTEST, invalidaSinTodosLosAtributosIndividuos) {
    eph_h th = {{334, 2017, 1, 1, 6, 0, 1, 3, 1, 2}};
    eph_i ti = {{334},
                {334, 2017}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaHogaresSinIndividuos) {
    eph_h th = {{334, 2017, 1, 1, 6, 0, 1, 3, 1, 2},
                {960,  2017, 1, 1, 2, 0, 1, 4, 1, 2}};
    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaHogaresCodusuRepetidos) {
    eph_h th = {{334, 2017, 1, 1, 6, 0, 1, 3, 1, 2},
                {334,  2017, 1, 1, 2, 0, 1, 4, 1, 2}};
    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaIndividuosCodusuYComponenteRepetidos) {
    eph_h th = {{334, 2017, 1, 1, 6, 0, 1, 3, 1, 2}};
    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {334, 1, 2017, 1, 1, 2, 92, -1, 0, -1, 6}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}


TEST(esEncuestaValidaTEST, invalidaDistintoAnioEntreHogaresEIndividuos) {
    eph_h th = {{334, 2017, 1, 1, 6, 0, 1, 3, 1, 2},
                {960,  2017, 1, 1, 2, 0, 1, 4, 1, 2}};
    eph_i ti = {{334,  1, 2018, 1, 0, 1, 36, 1,  3, 16300, 1},
                {960,  1, 2018, 1, 0, 1, 36, 1,  3, 16300, 1}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaDistintoTrimestreEntreHogaresEIndividuos) {
    eph_h th = {{334, 2017, 1, 1, 6, 0, 1, 3, 1, 2},
                {960,  2017, 1, 1, 2, 0, 1, 4, 1, 2}};
    eph_i ti = {{334,  1, 2017, 2, 0, 1, 36, 1,  3, 16300, 1},
                {960,  1, 2017, 2, 0, 1, 36, 1,  3, 16300, 1}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaDormitoriosMayoresAHabitaciones) {
    //                              cantidad de dormitorios
    //           cantidad de habitaciones__   |
    //                                     |  |
    //                                     v  v
    eph_h th = {{334, 2017, 2, 1, 6, 0, 1, 1, 2, 2}};
    eph_i ti = {{334,  1, 2017, 2, 0, 1, 36, 1,  3, 16300, 1}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaMasDe20MiembrosEnElHogar) {
    eph_h th = {{334, 2017, 2, 1, 6, 0, 1, 3, 1, 2}};
    eph_i ti;

    for (int i = 1; i <= 21; i++) {
        individuo individuo_actual = {334, 1, 2017, 2, 0, 1, 36, 1, 3, 16300, 1};
        individuo_actual[COMPONENTE] = i;
        ti.push_back(individuo_actual);
    }

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaTrimestreNegativo) {
    eph_h th = {{234, 2017, -2, 1, 6, 0, 1, 3, 1, 2}};
    eph_i ti = {{234, 1, 2017, -2, 0, 1, 36, 1, 3, 16300, 1}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, validaAnioNegativo) {
    eph_h th = {{234, -345, 4, 1, 6, 0, 1, 3, 1, 2}};
    eph_i ti = {{234, 1, -345, 4, 0, 1, 36, 1, 3, 16300, 1}};
    EXPECT_TRUE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, indDistintoTrim) {
    eph_h th = {{334, 2017, 1, 1, 6, 0, 1, 3, 1, 2},
                {960,  2017, 1, 1, 2, 0, 1, 4, 1, 2}};
    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {960,  1, 2018, 2, 0, 1, 36, 1,  3, 16300, 1}};
    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, hogDistintoTrim) {
    eph_h th = {{334, 2017, 1, 1, 6, 0, 1, 3, 1, 2},
                {960,  2018, 2, 1, 2, 0, 1, 4, 1, 2}};
    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {960,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1}};
    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, indSinHog) {
    eph_h th = {{334,  2017, 1, 1, 6, 0, 1, 3, 1, 2}};
    eph_i ti = {{960,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1}};
    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, hogFueraDeRango) {
    eph_h th = {{234, 2017, 4, 1, 6, 0, 1, 3, 1, 3}};
    eph_i ti = {{234, 1, 2017, 4, 0, 1, 36, 1, 3, 16300, 1}};
    EXPECT_FALSE(esEncuestaValida(th, ti));
}