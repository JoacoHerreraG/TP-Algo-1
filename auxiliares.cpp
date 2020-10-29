//
// Created by Ralo on 14/04/2019.
//
#include "definiciones.h"
#include "auxiliares.h"




//Auxiliares para esEncuestaValida




bool vacia(vector<vector<int> > &encuesta) {
    bool size = encuesta.size() == 0;
    return size;
}

bool esMatriz(vector<vector<int> > encuesta) {
    for (int i = 0; i < encuesta.size(); ++i) {
        if (encuesta[0].size() != encuesta[i].size()) {
            return false;
        }
    }
    return true;
}

bool cantidadCorrectaDeColumnasI(eph_i &ti) {
    return ti[0].size() == 11;
}

bool cantidadCorrectaDeColumnasH(eph_h &th) {
    return th[0].size() == 10;
}

bool hayHogarConCodigo(eph_h &th, int c) {
    bool existe = false;
    for (int i = 0; i < th.size(); ++i) {
        if (th[i][HOGCODUSU] == c) {
            existe = true;
        }
    }
    return existe;
}

bool hayIndividuosSinHogares(eph_i &ti, eph_h &th) {
    bool existen = false;
    for (int i = 0; i < ti.size(); ++i) {
        if (!hayHogarConCodigo(th, ti[i][INDCODUSU])) {
            existen = true;
        }
    }
    return existen;
}

bool hayIndividuoConCodigo(eph_i &ti, int c) {
    for (int i = 0; i < ti.size(); ++i) {
        if (ti[i][INDCODUSU] == c) {
            return true;
        }
    }
    return false;
}

bool hayHogaresSinIndividuos(eph_i &ti, eph_h &th) {
    for (int i = 0; i < th.size(); ++i) {
        if (!hayIndividuoConCodigo(ti, th[i][HOGCODUSU])) {
            return true;
        }
    }
    return false;
}

bool mismoCodusuYComponente(individuo a, individuo b) {
    return (a[INDCODUSU] == b[INDCODUSU] && a[COMPONENTE] == b[COMPONENTE]);
}

bool hayRepetidosI(eph_i &ti) {
    int i = 0;
    while (i < ti.size()) {
        for (int j = i + 1; j < ti.size(); ++j) {
            if (mismoCodusuYComponente(ti[i], ti[j])) {
                return true;
            }
        }
        i++;
    }
    return false;
}

bool hayRepetidosH(eph_h &th) {
    int i = 0;
    while (i < th.size()) {
        for (int j = i + 1; j < th.size(); ++j) {
            if (th[i][HOGCODUSU] == th[j][HOGCODUSU]) {
                return true;
            }
        }
        i++;
    }
    return false;
}

bool mismoAnioYTrimestre(eph_i &ti, eph_h &th) {
    bool res = true;
    for (int i = 1; i < ti.size(); ++i) {
        if (ti[0][INDANIO] != ti[i][INDANIO] && ti[0][INDTRIMESTRE] != ti[i][INDTRIMESTRE]) {
            res = false;
        }
    }
    for (int j = 1; j < th.size(); ++j) {
        if (th[0][HOGANIO] != th[j][HOGANIO] && th[0][HOGTRIMESTRE] != th[j][HOGTRIMESTRE]) {
            res = false;
        }
    }
    return (res && (ti[0][INDANIO] == th[0][HOGANIO] && ti[0][INDTRIMESTRE] == th[0][HOGTRIMESTRE]));
}

bool esSuHogar(hogar &h, individuo &i) {
    return (h[HOGCODUSU] == i[INDCODUSU]);
}

int cantidadHabitantes(hogar &h, eph_i &ti) {
    int contador = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (esSuHogar(h, ti[i])) {
            contador++;
        }
    }
    return contador;
}

bool menosDe21MiembrosPorHogar(eph_h &th, eph_i &ti) {
    for (int i = 0; i < th.size(); ++i) {
        if (cantidadHabitantes(th[i], ti) >= 21) {
            return false;
        }
    }
    return true;
}

bool cantidadValidaDormitorios(eph_h &th) {
    for (int i = 0; i < th.size(); ++i) {
        if (th[i][IV2] < th[i][II3]) {
            return false;
        }
    }
    return true;
}

bool valoresEnRangoI(eph_i &ti) {
    bool enRango = true;
    for (int i = 0; i < ti.size(); ++i) {
        if (!individuoValido(ti[i])) {
            enRango = false;
        }
    }
    return enRango;
}

bool individuoValido(individuo &i) {
    return (i[INDCODUSU] > 0 && i[COMPONENTE] > 0 && (0 < i[INDTRIMESTRE] && i[INDTRIMESTRE] <= 4) &&
            (0 < i[CH4] && i[CH4] <= 2) && i[CH6] >= 0 && (i[NIVEL_ED] == 0 || i[NIVEL_ED] == 1) &&
            (-1 <= i[ESTADO] && i[ESTADO] <= 1) && (0 <= i[CAT_OCUP] && i[CAT_OCUP] <= 4) &&
            (-1 == i[p47T] || 0 <= i[p47T]) && (0 < i[PP04G] && i[PP04G] <= 10));
}

bool valoresEnRangoH(eph_h &th) {
    bool enRango = true;
    for (int i = 0; i < th.size(); ++i) {
        if (!hogarValido(th[i])) {
            enRango = false;
        }
    }
    return enRango;
}

bool hogarValido(hogar &h) {
    return (h[HOGCODUSU] > 0 && (h[HOGTRIMESTRE] > 0 && h[HOGTRIMESTRE] <= 4) && (h[II7] > 0 && h[II7] <= 3) &&
            (0 < h[REGION] && h[REGION] <= 6) && (h[MAS_500] == 0 || h[MAS_500] == 1) &&
            (0 < h[IV1] && h[IV1] <= 5) && h[IV2] > 0 && h[II2] >= 1 && (h[II3] == 1 || h[II3] == 2));
}

bool esValida(eph_h &th, eph_i &ti) {
    return (!vacia(th) && !vacia(ti) && esMatriz(th) && esMatriz(ti) && cantidadCorrectaDeColumnasI(ti) &&
            cantidadCorrectaDeColumnasH(th) && !hayIndividuosSinHogares(ti, th) && !hayHogaresSinIndividuos(ti, th) &&
            !hayRepetidosI(ti) && !hayRepetidosH(th) && mismoAnioYTrimestre(ti, th) &&
            menosDe21MiembrosPorHogar(th, ti) &&
            cantidadValidaDormitorios(th) && valoresEnRangoI(ti) && valoresEnRangoH(th));
}




//Auxiliares para histHabitacional




int maxCantDeAmbientes(eph_h &th, int region) {
    int l = th.size();
    int max = 0;
    for (int i = 0; i < l; ++i) {
        if (th[i][REGION] == region && th[i][IV1] == 1) {
            if (th[i][IV2] > max) {
                max = th[i][IV2];
            } else {
                continue;
            }
        }
    }
    return max;
}

bool esCasa(hogar &h) {
    return h[IV1] == 1;
}




//Auxiliares para laCasaEstaQuedandoChica




int cantHogaresValidos(eph_h &th, eph_i &ti, int region) {
    int contadorHogares = 0;
    for (int i = 0; i < th.size(); ++i) {
        if (esHogarValido(th[i], region)) {
            contadorHogares++;
        }
    }
    return contadorHogares;
}

int cantHogaresValidosConHC(eph_h &th, eph_i &ti, int region) {
    int contadorHogaresHC = 0;
    for (int i = 0; i < th.size(); ++i) {
        if (esHogarValido(th[i], region) && esHogarHC(th[i], ti)) {
            contadorHogaresHC++;
        }
    }
    return contadorHogaresHC;
}

bool esHogarHC(hogar &h, eph_i &ti) {
    int cantHabitantes = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (h[HOGCODUSU] == ti[i][INDCODUSU]) {
            cantHabitantes++;
        }
    }
    return (cantHabitantes > h[II2] * 3);
}

bool esHogarValido(hogar &h, int region) {
    return (h[REGION] == region && h[IV1] == 1 && h[MAS_500] == 0);
}




//Auxiliares para creceElTeleworkingEnCiudadesGrandes




float proporcionTeleworking(eph_h &th, eph_i &ti) {
    float indTrabaja = (float) cantIndividuosQueTrabajan(th, ti);
    float indTrabajaHog = (float) cantIndividuosTrabajandoEnSuVivienda(th, ti);
    if (indTrabaja > 0) {
        return (indTrabajaHog / indTrabaja);
    } else {
        return 0;
    }
}

int cantIndividuosQueTrabajan(eph_h &th, eph_i &ti) {
    int contador = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (trabaja(ti[i]) && individuoEnHogarValido(ti[i], th)) {
            contador++;
        }
    }
    return contador;
}

int cantIndividuosTrabajandoEnSuVivienda(eph_h &th, eph_i &ti) {
    int contador = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (trabaja(ti[i]) && trabajaEnSuVivienda(ti[i], th) && individuoEnHogarValido(ti[i], th)) {
            contador++;
        }
    }
    return contador;
}

bool esDeCiudadGrande(individuo &i, eph_h &th) {
    int k = indiceDeHogar(i, th);
    return (th[k][MAS_500] == 1);
}

bool suHogarTieneEspaciosReservadosParaElTrabajo(individuo &i, eph_h &th) {
    int k = indiceDeHogar(i, th);
    return (tieneEspaciosReservadosParaElTrabajo(th[k]));
}

bool suHogarEsCasaODepartamento(individuo &i, eph_h &th) {
    int k = indiceDeHogar(i, th);
    return esCasaODepartamento(th[k]);
}

bool individuoEnHogarValido(individuo &i, eph_h &th) {
    return (esDeCiudadGrande(i, th) && suHogarEsCasaODepartamento(i, th));
}

bool trabajaEnSuVivienda(individuo &i, eph_h &th) {
    return (realizaSusTareasEnEsteHogar(i) && suHogarTieneEspaciosReservadosParaElTrabajo(i, th));
}

// j no puede llegar a estar fuera de rango porque la encuesta es válida.

int indiceDeHogar(individuo &i, eph_h &th) {
    int j = 0;
    while (not esSuHogar(th[j], i)) {
        j++;
    }
    return j;
}

bool trabaja(individuo &i) {
    return (i[ESTADO] == 1);
}

bool esCasaODepartamento(hogar &h) {
    return (h[IV1] == 1 || h[IV1] == 2);
}

bool realizaSusTareasEnEsteHogar(individuo &i) {
    return (i[PP04G] == 6);
}

bool tieneEspaciosReservadosParaElTrabajo(hogar &h) {
    return (h[II3] == 1);
}




//Auxiliares para ordenarRegionYCodusu




bool vivenJuntos(individuo &i1, individuo &i2) {
    return (i1[INDCODUSU] == i2[INDCODUSU]);
}

bool hogarEstaAntes(hogar &h1, hogar &h2, eph_h &th) {
    bool anterior = false;
    for (int i = 0; i < th.size() - 1; ++i) {
        for (int j = i + 1; j < th.size(); ++j) {
            if (th[i] == h1 && th[j] == h2) {
                anterior = true;
            }
        }
    }
    return anterior;
}

bool suHogarEstaAntes(individuo &i1, individuo &i2, eph_h &th) {
    hogar h1 = {};
    hogar h2 = {};
    for (int i = 0; i < th.size(); ++i) {
        if (i1[INDCODUSU] == th[i][HOGCODUSU]) {
            h1 = th[i];
        }
        if (i2[INDCODUSU] == th[i][HOGCODUSU]) {
            h2 = th[i];
        }
    }
    return (hogarEstaAntes(h1, h2, th));
}

bool estanOrdenadosPorCodusuDeHogarYComponente(eph_i &ti, eph_h &th) {
    bool ordenados = true;
    for (int i = 0; i < ti.size() - 1; ++i) {
        for (int j = i + 1; j < ti.size(); ++j) {
            if (!suHogarEstaAntes(ti[i], ti[j], th) ||
                  (vivenJuntos(ti[i], ti[j]) && ti[i][COMPONENTE] > ti[j][COMPONENTE])) {
                ordenados = false;
            }
        }
    }
    return ordenados;
}

bool estanOrdenadosPorRegionYCodusu(eph_h &th) {
    bool ordenados = true;
    for (int i = 0; i < th.size() - 1; ++i) {
        for (int j = i + 1; j < th.size(); ++j) {
            if ((th[i][REGION] > th[j][REGION]) ||
                (th[i][REGION] == th[j][REGION] && th[i][HOGCODUSU] > th[j][HOGCODUSU])) {
                ordenados = false;
            }
        }
    }
    return ordenados;
}

void ordenarHogPorReg(eph_h &th) {
    for (int j = 0; j < th.size() - 1; ++j) {
        int menorReg = j;
        for (int i = j + 1; i < th.size(); ++i) {
            if (th[i][REGION] < th[menorReg][REGION]) {
                menorReg = i;
            }
        }
        swap(th[menorReg], th[j]);

    }
}

//Ya están ordenados por region los hogares.

void ordenarHogPorCod(eph_h &th) {
    for (int j = 0; j < th.size() - 1; ++j) {
        int menorCod = j;
        for (int i = j + 1; i < th.size(); ++i) {
            if (th[i][REGION] == th[menorCod][REGION] && th[i][HOGCODUSU] < th[menorCod][HOGCODUSU]) {
                menorCod = i;
            }
        }
        swap(th[menorCod], th[j]);
    }
}

//La lista de hogares ya está ordenada.

void ordenarIndPorCodDeHog(eph_i &ti, eph_h &th) {
    int proxHabitante = 0;
    for (int i = 0; i < th.size() - 1; ++i) {
        for (int j = proxHabitante; j < ti.size(); ++j) {
            if (th[i][HOGCODUSU] == ti[j][INDCODUSU]) {
                swap(ti[j], ti[proxHabitante]);
                proxHabitante++;
            }
        }
    }
}

// La lista de individuos ya está ordenada por Cod de Hogar.

void ordenarIndPorComp(eph_i &ti) {
    int i = 0;
    int j = 1;
    while (i < ti.size()) {
        while (j < ti.size() && ti[j][INDCODUSU] == ti[i][INDCODUSU]) {
            j++;
        }
        selSortPorComponente(ti, i, j); //Ordeno por componente.
        i = j;
        //j = i;
    }
}

void selSortPorComponente(eph_i &ti, int &inicio, int &final) {
    for (int i = inicio; i < final; ++i) {
        int min = i;
        for (int j = i + 1; j < final; ++j) {
            if (ti[j][COMPONENTE] < ti[min][COMPONENTE]) {
                min = j;
            }
        }
        swap(ti[i], ti[min]);
    }
}

//Auxiliares para muestraHomogenea

// Fija dos índices; luego declara otro, l, y con k, variable de control, recorre.
// Si la diferencia de ingresos de los primeros dos componentes de ingresos es la misma para el k-ésimo y el l-ésimo en algún momento,
// significa que podemos agregar el k-ésimo a nuestra tira, ahora seguir comparando contra el último de la tira.
// k aumenta y eso está bien pues al estar ordenada por ingresos el vector, los únicos candidatos a poder ser metidos en la tira se encuentran más adelante.

vector<int> solMaximalMuestraHomogenea(vector<vector<int> > &ingresos) {
    vector<int> res = {};
    for (int i = 0; i < ingresos.size(); ++i) {
        for (int j = i + 1; j < ingresos.size() && ingresos[j][1] - ingresos[i][1] != 0; ++j) {
            vector<int> aux{i, j};
            int l = j;
            for (int k = j + 1; k < ingresos.size(); ++k) {
                if (ingresos[k][1] - ingresos[l][1] == ingresos[j][1] - ingresos[i][1]) {
                    aux.push_back(k);
                    l = k;

                }
            }
            if (aux.size() > res.size()) {
                res = aux;
            }
        }
    }
    return res;
}


void selectionSortEspecial(vector<vector<int> > &ingresos) {
    for (int i = 0; i < ingresos.size() - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < ingresos.size(); ++j) {
            if (ingresos[j][1] < ingresos[min][1]) {
                min = j;
            }
        }
        swapMH(ingresos, i, min);
    }
}


void swapMH(vector<vector<int> > &vec, int &a, int &b) {
    vector<int> aux = vec[a];
    vec[a] = vec[b];
    vec[b] = aux;
}

vector<vector<int> > listarIngresosDeHogares(eph_h &th, eph_i &ti) {
    vector<vector<int> > ingres;
    for (int i = 0; i < th.size(); ++i) {
        ingres.push_back({i, (int) ingresos(th[i], ti)});
    }
    return ingres;
}


//Auxiliares para corregirRegion




void soloModificaRegionGBAaPampeana(eph_h &th) {
    for (int i = 0; i < th.size(); ++i) {
        if (th[i][REGION] == 1) {
            th[i][REGION] = 5;
        }
    }
}




//Auxiliares para indiceGini




float cantHab(hogar &h, eph_i &ti) {
    int contador = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (h[HOGCODUSU] == ti[i][INDCODUSU]) {
            contador++;
        }
    }
    return contador;
}

float ingresos(hogar &h, eph_i &ti) {
    int contador = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (h[HOGCODUSU] == ti[i][INDCODUSU] && ti[i][p47T] != -1) {
            contador += ti[i][p47T];
        }
    }
    return contador;
}

float ingresosPerCapitaEnHogar(hogar &h, eph_i &ti) {
    return (ingresos(h, ti) / cantHab(h, ti));
}

float ingresosHasta(int n, eph_h &th, eph_i &ti) {
    float contador = 0;
    for (int i = 0; i < n; ++i) {
        contador += ingresosPerCapitaEnHogar(th[i], ti);
    }
    return contador;
}

float integralDeIngresosObservados(eph_h &th, eph_i &ti) {
    float contador = 0;
    for (int i = 0; i < th.size(); ++i) {
        contador += ((ingresosHasta(i, th, ti) / ingresosHasta(th.size(), th, ti)) +
                     (ingresosPerCapitaEnHogar(th[i], ti) / ingresosHasta(th.size(), th, ti)) / 2);
    }
    return contador / th.size();
}

float areaObservada(eph_h &th, eph_i &ti) {
    float areaIgualdadTotal = 0.5;
    return areaIgualdadTotal - integralDeIngresosObservados(th, ti);
}

bool tablaHogaresOrdenadaPorIngresosPerCapita(eph_h &th, eph_i &ti) {
    bool ordenada = true;
    for (int i = 0; i < th.size() - 1; ++i) {
        if (ingresosPerCapitaEnHogar(th[i], ti) > ingresosPerCapitaEnHogar(th[i + 1], ti)) {
            ordenada = false;
        }
    }
    return ordenada;
}