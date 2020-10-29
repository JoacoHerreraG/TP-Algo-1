#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"


bool esEncuestaValida(eph_h th, eph_i ti) {
    return esValida(th, ti);
}


//Para generar el vector de respuesta, se encuentra su largo correcta para saber hasta cuándo iterar.


vector<int> histHabitacional(eph_h th, eph_i ti, int region) {
    vector<int> res = {};
    int max = maxCantDeAmbientes(th, region);
    for (int i = 0; i < max; ++i) {
        int contadorAmbientes = 0;
        for (int j = 0; j < th.size(); ++j) {
            if (th[j][REGION] == region && esCasa(th[j]) && th[j][IV2] == i + 1) {
                contadorAmbientes++;
            }
        }
        res.push_back(contadorAmbientes);
    }
    return res;
}

vector<float> laCasaEstaQuedandoChica(eph_h th, eph_i ti) {
    vector<float> res(CANTIDAD_DE_REGIONES);
    for (int i = 0; i < CANTIDAD_DE_REGIONES; ++i) {
        int hogaresHC = cantHogaresValidosConHC(th, ti, i + 1);
        int hogaresValidos = cantHogaresValidos(th, ti, i + 1);
        float proporcion = 0;
        if (hogaresValidos > 0) {
            proporcion = (float) hogaresHC / (float) hogaresValidos;
        }
        res[i] = proporcion;
    }
    return res;
}

bool creceElTeleworkingEnCiudadesGrandes(eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i) {
    return (proporcionTeleworking(t1h, t1i) < proporcionTeleworking(t2h, t2i));
}

void ordenarRegionYCodusu(eph_h &th, eph_i &ti) {
    if (!estanOrdenadosPorRegionYCodusu(th)) {
        ordenarHogPorReg(th);
        ordenarHogPorCod(th);
    }
    if (!estanOrdenadosPorCodusuDeHogarYComponente(ti, th)) {
        ordenarIndPorCodDeHog(ti, th);
        ordenarIndPorComp(ti);
    }
}

vector<hogar> muestraHomogenea(eph_h th, eph_i ti) {
    vector<vector<int> > ingresos{};
    ingresos = listarIngresosDeHogares(th,
                                       ti);// Almaceno los ingresos de cada hogar junto con su índice correspondiente.
    selectionSortEspecial(
            ingresos);// Ordenamiento de menor a mayor de las tuplas según su sda. componente, el ingreso del hogar correspondiente.
    vector<int> indicesDeHogares = solMaximalMuestraHomogenea(
            ingresos); // Generamos un vector que da la respuesta en función de las posiciones de las tuplas en ingresos.
    vector<hogar> res;
    if (indicesDeHogares.size() > 2) {
        for (int j = 0; j <
                        indicesDeHogares.size(); ++j) { // Recuperamos, para cada posición, el índice de hogar al cual se refería la posición.
            indicesDeHogares[j] = ingresos[indicesDeHogares[j]][0];
        }
        for (int i = 0; i <
                        indicesDeHogares.size(); ++i) { // Ahora podemos generar la respuesta pues tenemos explícitamente los índices.
            res.push_back(th[indicesDeHogares[i]]);
        }

    }
    return res;
}

void corregirRegion(eph_h &th, eph_i ti) {
    soloModificaRegionGBAaPampeana(th);
}

float indiceGini(eph_h th, eph_i ti) {
    float areaIgualdadTotal = 0.5;
    if (tablaHogaresOrdenadaPorIngresosPerCapita(th, ti)) {
        return areaObservada(th, ti) / areaIgualdadTotal;
    } else {
        return 0;
    }
}