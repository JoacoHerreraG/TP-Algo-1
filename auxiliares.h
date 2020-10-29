//
// Created by leticia on 07/05/19.
//

#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool vacia(vector<vector<int> > &encuesta);
bool esMatriz(vector<vector<int> > encuesta);
bool cantidadCorrectaDeColumnasI(eph_i &ti);
bool cantidadCorrectaDeColumnasH(eph_h &th);
bool hayHogarConCodigo(eph_h &th, int c);
bool hayIndividuosSinHogares(eph_i &ti, eph_h &th);
bool hayIndividuoConCodigo(eph_i &ti, int c);
bool hayHogaresSinIndividuos(eph_i &ti, eph_h &th);
bool mismoCodusuYComponente(individuo a, individuo b);
bool hayRepetidosI(eph_i &ti);
bool hayRepetidosH(eph_h &th);
bool mismoAnioYTrimestre (eph_i &ti, eph_h &th);
int cantidadHabitantes(hogar &h, eph_i &ti);
bool menosDe21MiembrosPorHogar(eph_h &th, eph_i &ti);
bool cantidadValidaDormitorios(eph_h &th);
bool valoresEnRangoI(eph_i &ti);
bool individuoValido(individuo &i);
bool valoresEnRangoH(eph_h &th);
bool hogarValido(hogar &h);
bool esValida(eph_h &th, eph_i &ti);
int maxCantDeAmbientes(eph_h &th, int region);
bool esCasa(hogar &h);
bool esHogarValido(hogar &h, int region);
int cantHogaresValidos(eph_h &th, eph_i &ti, int region);
bool esHogarHC(hogar &h, eph_i &ti);
int cantHogaresValidosConHC(eph_h &th, eph_i &ti, int region);
bool trabaja(individuo &i);
bool esCasaODepartamento(hogar &h);
bool realizaSusTareasEnEsteHogar(individuo &i);
bool tieneEspaciosReservadosParaElTrabajo(hogar &h);
bool esSuHogar(hogar &h, individuo &i);
int indiceDeHogar(individuo &i, eph_h &th);
bool esDeCiudadGrande(individuo &i, eph_h &th);
bool suHogarTieneEspaciosReservadosParaElTrabajo(individuo &i, eph_h &th);
bool suHogarEsCasaODepartamento(individuo &i, eph_h &th);
bool individuoEnHogarValido(individuo &i, eph_h &th);
bool trabajaEnSuVivienda(individuo &i, eph_h &th);
int cantIndividuosQueTrabajan(eph_h &th, eph_i &ti);
int cantIndividuosTrabajandoEnSuVivienda(eph_h &th, eph_i &ti);
float proporcionTeleworking(eph_h &th, eph_i &ti);
bool vivenJuntos(individuo &i1, individuo &i2);
bool hogarEstaAntes(hogar &h1, hogar &h2, eph_h &th);
bool suHogarEstaAntes(individuo &i1, individuo &i2, eph_h &th);
bool estanOrdenadosPorCodusuDeHogarYComponente(eph_i &ti, eph_h &th);
bool estanOrdenadosPorRegionYCodusu(eph_h &th);

void ordenarHogPorReg(eph_h &th);
void ordenarHogPorCod(eph_h &th);
void ordenarIndPorCodDeHog(eph_i &ti, eph_h &th);
void ordenarIndPorComp(eph_i &ti);
void selSortPorComponente(eph_i &ti, int &inicio, int &final);

vector<int> solMaximalMuestraHomogenea(vector<vector<int> > &ingresos);
void selectionSortEspecial(vector<vector<int> > &ingresos);
void swapMH(vector<vector<int> > &vec, int &a, int &b);
vector<vector<int> > listarIngresosDeHogares(eph_h &th, eph_i &ti);


void soloModificaRegionGBAaPampeana(eph_h &th);

float cantHab(hogar &h, eph_i &ti);
float ingresos(hogar &h, eph_i &ti);
float ingresosPerCapitaEnHogar(hogar &h, eph_i &ti);
float ingresosHasta(int n, eph_h &th, eph_i &ti);
float integralDeIngresosObservados(eph_h &th, eph_i &ti);
float areaObservada (eph_h &th, eph_i &ti);
bool tablaHogaresOrdenadaPorIngresosPerCapita(eph_h &th, eph_i &ti);

#endif //SOLUCION_AUXILIARES_H
