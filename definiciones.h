//
// Created by Pablo on 03/10/2017.
//

#ifndef UTILES_DEFINICIONES_H
#define UTILES_DEFINICIONES_H

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// CONSTANTES

enum ItemHogar {
  HOGCODUSU,    // CODUSU
  HOGANIO,      // Año
  HOGTRIMESTRE, // Trimestre
  II7,          // Régimen de tenencia (Propietario, Inquilino, Ocupante)
  REGION,       // Región
  MAS_500,      // Aglomerados de más de 500.000 habitantes
  IV1,          // Tipo de hogar (Casa, Depto, etc.)
  IV2,          // Cantidad de habitaciones
  II2,          // ¿Cuántas se usan para dormir?
  II3           // ¿Alguna se usa para trabajar?
};

#define FILAS_HOGAR 10

enum ItemInd {
  INDCODUSU,    // CODUSU
  COMPONENTE,   // Componente (id de persona dentro de un mismo CODUSU)
  INDANIO,      // Año
  INDTRIMESTRE, // Trimestre
  NIVEL_ED,     // Estudios Universitarios completos
  CH4,          // Género
  CH6,          // Edad
  ESTADO,       // Condición de actividad (Desocupado, Ocupado, No informado)
  CAT_OCUP,     // Categoría ocupacional (Patrón, Empleado, etc.)
  p47T,         // Ingreso
  PP04G         // Ubicación laboral (Oficina, Calle, Hogar, etc.)
};

#define FILAS_INDIVIDUO 11

#define GBA 1
#define PAMPEANA 5
#define CANTIDAD_DE_REGIONES 6

#define CASA 1

#define OCUPADO 1
#define EN_ESTE_HOGAR 6

// DEFINICIONES DE TIPO

typedef int                   dato;
typedef vector < dato >       individuo;
typedef vector < dato >       hogar;
typedef vector < individuo >  eph_i;
typedef vector < hogar >      eph_h;


#endif //UTILES_DEFINICIONES_H
