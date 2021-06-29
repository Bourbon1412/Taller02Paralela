#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <string>

/**
 * Función que muestra los participantes del grupo
 */
void participantes();



void replace(std::string& , const std::string& ,const std::string& );

//funcion que divide una cadena de caracteres
std::vector<std::string> split (std::string , std::string );

/**
 * Función que toma la ruta del csv y muestra los resultados
 */
void archivo(char*);

#endif /* FUNCIONES_H */