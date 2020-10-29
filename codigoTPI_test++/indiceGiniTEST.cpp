#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

#define UMBRAL 0.001

TEST(indiceGini, desigualdadTotalTresHogares){
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

    assert(esEncuestaValida(th,ti));
    float b = 1 * (1.0/2) * (1.0/3);
    EXPECT_TRUE(flotante_valido(1 - 2*b,indiceGini(th,ti),UMBRAL));
}

TEST(indiceGini, igualdadTotalDosHogares){
    eph_h th = {
            {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
    };

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 1, 1},
                {334,  2, 2017, 1, 0, 1, 36, 1,  3, 1, 1},
                {960,  3, 2017, 1, 1, 2, 51, 1,  4, 1,  1},
                {960,  2, 2017, 1, 1, 2, 51, 1,  4, 1,  1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 1,  1}};

    assert(esEncuestaValida(th,ti));
    float b = 1.0/2;
    EXPECT_TRUE(flotante_valido(1-2*b,indiceGini(th,ti),UMBRAL));
}


TEST(indiceGini, hogaresConIngresosNoInformados){
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

    assert(esEncuestaValida(th,ti));
    float b = 1 * (1.0/2) * (1.0/3);
    EXPECT_TRUE(flotante_valido(1-2*b,indiceGini(th,ti),UMBRAL));
}

TEST(indiceGini, dosHogares){
    eph_h th = {
            {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
    };

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 90, 1},
                 {960,  3, 2017, 1, 1, 2, 51, 1,  4, 10,  1},
                 {960,  2, 2017, 1, 0, 2, 20, 1,  3, 10,  1},
                 {960,  1, 2017, 1, 0, 2, 19, 0,  0, 10,  6}};

    assert(esEncuestaValida(th,ti));
    float b = (1.0/10)*(1.0/2)*(1.0/2) + (1.0/10)*(1.0/2) + (9.0/10)*(1.0/2)*(1.0/2);
    EXPECT_TRUE(flotante_valido(1-2*b,indiceGini(th,ti),UMBRAL));
}

TEST(indiceGini, encuestaDesordenada){
    eph_h th = {
            {334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
            {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {200,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
    };

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 90, 1},
                {334,  2, 2017, 1, 0, 1, 36, 1,  3, 90, 1},
                {200,  2, 2017, 1, 0, 1, 36, 1,  3, 0, 1},
                {960,  3, 2017, 1, 1, 2, 51, 1,  4, 0,  1},
                {960,  2, 2017, 1, 1, 2, 51, 1,  4, 0,  1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 0,  1}};

    assert(esEncuestaValida(th,ti));
    float b = 1 * (1.0/2) * (1.0/3);
    EXPECT_FALSE(flotante_valido(1 - 2*b,indiceGini(th,ti),UMBRAL));
}
