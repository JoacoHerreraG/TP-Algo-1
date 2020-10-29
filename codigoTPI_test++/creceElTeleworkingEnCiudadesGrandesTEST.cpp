#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(creceElTeleworkingEnCiudadesGrandesTEST, crece) {

//                                   +500 Tipo  Lugar para trabajar
//                                     v  v        v
    eph_h t1h = {{334,  2017, 1, 1, 2, 1, 1, 3, 1, 2},  // Esta no: Sin lugar para trabajar
                 {960,  2017, 1, 1, 1, 1, 1, 4, 1, 1},
                 {1366, 2017, 1, 2, 5, 1, 3, 3, 2, 1},  // Esta no: Hotel
                 {1388, 2017, 1, 3, 4, 0, 1, 2, 2, 1}}; // Esta no: menos 500

//                                                      Ubicación
//                                                          v
    eph_i t1i = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},  // Esta no: Sin lugar para trabajar
                 {960,  3, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                 {1366, 1, 2017, 1, 1, 2, 92, 1,  0, -1,    1},  // Esta no: Hotel
                 {960,  2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                 {960,  1, 2017, 1, 0, 2, 19, 1,  0, 0,     6},
                 {1388, 1, 2017, 1, 0, 1, 67, 1,  3, 20000, 6}}; // Esta no: menos 500

//                                   +500 Tipo  Lugar para trabajar
//                                     v  v        v
    eph_h t2h = {{334,  2018, 1, 1, 2, 1, 1, 3, 1, 2},  // Esta no: Sin lugar para trabajar
                 {960,  2018, 1, 1, 1, 1, 1, 4, 1, 1},
                 {1366, 2018, 1, 2, 5, 1, 3, 3, 2, 1},  // Esta no: Hotel
                 {1388, 2018, 1, 3, 4, 0, 1, 2, 2, 1}}; // Esta no: menos 500

//                                                      Ubicación
//                                                          v
    eph_i t2i = {{334,  1, 2018, 1, 0, 1, 36, 1,  3, 16300, 6},  // Esta no: Sin lugar para trabajar
                 {960,  3, 2018, 1, 1, 2, 51, 1,  4, 1280,  6},
                 {1366, 1, 2018, 1, 1, 2, 92, 1,  0, -1,    1},  // Esta no: Hotel
                 {960,  2, 2018, 1, 0, 2, 20, 1,  3, 7000,  1},
                 {960,  1, 2018, 1, 0, 2, 19, 1,  0, 0,     6},
                 {1388, 1, 2018, 1, 0, 1, 67, 1,  3, 20000, 6}}; // Esta no: menos 500

    EXPECT_EQ( true, creceElTeleworkingEnCiudadesGrandes(t1h, t1i, t2h, t2i) );
}


TEST(creceElTeleworkingEnCiudadesGrandesTEST, nocrece) {

//                                   +500 Tipo  Lugar para trabajar
//                                     v  v        v
    eph_h t1h = {{334,  2015, 1, 1, 2, 1, 1, 3, 1, 2},  // Esta no: Sin lugar para trabajar
                 {960,  2015, 1, 1, 1, 1, 1, 4, 1, 1},
                 {1366, 2015, 1, 2, 5, 1, 3, 3, 2, 1},  // Esta no: Hotel
                 {1388, 2015, 1, 3, 4, 0, 1, 2, 2, 1}}; // Esta no: menos 500

//                                                      Ubicación
//                                                          v
    eph_i t1i = {{334,  1, 2015, 1, 0, 1, 36, 1,  3, 16300, 1},  // Esta no: Sin lugar para trabajar
                 {960,  3, 2015, 1, 1, 2, 51, 1,  4, 1280,  1},
                 {1366, 1, 2015, 1, 1, 2, 92, 1,  0, -1,    1},  // Esta no: Hotel
                 {960,  2, 2015, 1, 0, 2, 20, 1,  3, 7000,  1},
                 {960,  1, 2015, 1, 0, 2, 19, 1,  0, 0,     6},
                 {1388, 1, 2015, 1, 0, 1, 67, 1,  3, 20000, 6}}; // Esta no: menos 500

//                                   +500 Tipo  Lugar para trabajar
//                                     v  v        v
    eph_h t2h = {{334,  2017, 1, 1, 2, 1, 1, 3, 1, 2},  
                 {960,  2017, 1, 1, 1, 1, 1, 4, 1, 1},
                 {1366, 2017, 1, 2, 5, 1, 3, 3, 2, 1},  
                 {1388, 2017, 1, 3, 4, 0, 1, 2, 2, 1}}; 

//                                                      Ubicación
//                                                          v
    eph_i t2i = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},  
                 {960,  3, 2017, 1, 1, 2, 51, 1,  4, 1280,  2},
                 {1366, 1, 2017, 1, 1, 2, 92, 1,  0, -1,    1},  
                 {960,  2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                 {960,  1, 2017, 1, 0, 2, 19, 1,  0, 0,     1},
                 {1388, 1, 2017, 1, 0, 1, 67, 1,  3, 20000, 1}}; 

    EXPECT_EQ( false, creceElTeleworkingEnCiudadesGrandes(t1h, t1i, t2h, t2i) );
}


TEST(creceElTeleworkingEnCiudadesGrandesTEST, eph2016a2018) {
    eph_h t1h;
    eph_i t1i;
    leerEncuesta ( "eph_3c_2016_1000", t1h, t1i );

    eph_h t2h;
    eph_i t2i;
    leerEncuesta ( "eph_3c_2018_1000", t2h, t2i );

    EXPECT_EQ( true, creceElTeleworkingEnCiudadesGrandes(t1h, t1i, t2h, t2i) );
}
TEST(creceElTeleworkingEnCiudadesGrandesTEST, nadieTrabaja) {
    eph_h t1h = {{334,  2017, 1, 1, 2, 1, 1, 3, 1, 2},  // Esta no: Sin lugar para trabajar
                 {960,  2017, 1, 1, 1, 1, 1, 4, 1, 1},
                 {1366, 2017, 1, 2, 5, 1, 3, 3, 2, 1},  // Esta no: Hotel
                 {1388, 2017, 1, 3, 4, 0, 1, 2, 2, 1}};

    eph_i t1i = {{334,  1, 2017, 1, 0, 1, 36, 0,  3, 16300, 1},  // Esta no: Sin lugar para trabajar
                 {960,  3, 2017, 1, 1, 2, 51, 0,  4, 1280,  1},
                 {1366, 1, 2017, 1, 1, 2, 92, 0,  0, -1,    1},  // Esta no: Hotel
                 {960,  2, 2017, 1, 0, 2, 20, 0,  3, 7000,  1},
                 {960,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                 {1388, 1, 2017, 1, 0, 1, 67, 0,  3, 20000, 6}};

    eph_h t2h = {{334,  2018, 1, 1, 2, 1, 1, 3, 1, 2},  // Esta no: Sin lugar para trabajar
                 {960,  2018, 1, 1, 1, 1, 1, 4, 1, 1},
                 {1366, 2018, 1, 2, 5, 1, 3, 3, 2, 1},  // Esta no: Hotel
                 {1388, 2018, 1, 3, 4, 0, 1, 2, 2, 1}};

    eph_i t2i = {{334,  1, 2018, 1, 0, 1, 36, 0,  3, 16300, 6},  // Esta no: Sin lugar para trabajar
                 {960,  3, 2018, 1, 1, 2, 51, 0,  4, 1280,  6},
                 {1366, 1, 2018, 1, 1, 2, 92, 0,  0, -1,    1},  // Esta no: Hotel
                 {960,  2, 2018, 1, 0, 2, 20, 0,  3, 7000,  1},
                 {960,  1, 2018, 1, 0, 2, 19, 0,  0, 0,     6},
                 {1388, 1, 2018, 1, 0, 1, 67, 0,  3, 20000, 6}};
    EXPECT_EQ( false, creceElTeleworkingEnCiudadesGrandes(t1h, t1i, t2h, t2i));
}
