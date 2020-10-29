#ifndef ETPH_EJERCICIOS_H
#define ETPH_EJERCICIOS_H

#include <iostream>
#include <vector>

#include "definiciones.h"

using namespace std;

bool esEncuestaValida(eph_h th, eph_i ti);
vector<int> histHabitacional(eph_h th, eph_i ti, int region);
vector<float> laCasaEstaQuedandoChica(eph_h th, eph_i ti);
bool creceElTeleworkingEnCiudadesGrandes(eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i);
void ordenarRegionYCodusu(eph_h& th, eph_i& ti);
vector<hogar> muestraHomogenea(eph_h th, eph_i ti);
void corregirRegion(eph_h& th, eph_i ti);
float indiceGini(eph_h th, eph_i ti);

#endif //ETPH_EJERCICIOS_H
