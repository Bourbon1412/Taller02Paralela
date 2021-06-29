#include "funciones.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <math.h>

void participantes()
{
    std::cout << "---> INTEGRANTES <---" << std::endl;

    std::cout << std::endl
              << "Cristobal Valenzuela";
    std::cout << std::endl
              << "Miguel Martinez";
    std::cout << std::endl
              << "Andres Mella" << std::endl;
}

void replace(std::string &subject, const std::string &search, const std::string &replace)
{

    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos)
    {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
}

std::vector<std::string> split(std::string s, std::string lim)
{
    size_t inicio = 0, final, largo = lim.length();
    std::string token;
    std::vector<std::string> res;

    while ((final = s.find(lim, inicio)) != std::string::npos)
    {
        token = s.substr(inicio, final - inicio);
        inicio = final + largo;
        res.push_back(token);
    }

    res.push_back(s.substr(inicio));
    return res;
}

/*primer modelo suavizamiento exponencial
            formula F = (alfa * ventas dia anterior) + ((1-alfa)* ventas pronosticadas anterior)
            alfa = factor de suavizacion entre 0 y 1 (ventas regulares de 0- 0.5, ventas irregulares 0.6-1)
            recorrer fecha para que tome solo la fecha y no la hora,
             si la fecha es igual, se suma el producto.
*/
void archivo(char *valor1)
{
    int cantidad = 0, valor = 0, product = 0, count = 0, x = 0, auxd = 0, auxm = 0, auxa = 0, s = 0;
    long num=0,suma1=0,suma2=0;
    float pendiente,q=0,F = 0; 
    float PROMv;
    float PROMt;
    float interseccion;
    std::vector<std::string> fecha;
    std::string fecha1;
    int sumproducto = 0;
    int i;
    std::vector<int> cantidadMes;
    std::vector<int> mes;
    int matrizdia[384630][4];
    int matrizre[200][4];
    std::string linea;
    std::vector<std::string> identificador;

    std::ifstream archivo(valor1);
    if (archivo.is_open())
    {
        identificador.clear();
        while (getline(archivo, linea))
        {
            replace(linea, "\"", "");
            identificador.push_back(linea);
        }
        archivo.close();

        for (int x = 1; x < identificador.size(); x++)
        {
            std::string csv = "";
            std::vector<std::string> lugar = split(identificador[x], ";");
            std::vector<std::string> lugar1 = split(identificador[x], " ");
            cantidad = std::stoi(lugar[2]);
            valor = std::stoi(lugar[3]);
            product = cantidad * valor;
            matrizdia[x][3] = product;
            fecha.push_back(lugar1[0]);
        }

        for (i = 0; i < fecha.size(); i++)
        {
            
            std::vector<std::string> lugar2 = split(fecha[i], "-");

            matrizdia[i][0] = std::stoi(lugar2[0]); //año
            matrizdia[i][1] = std::stoi(lugar2[1]); //mes
            matrizdia[i][2] = std::stoi(lugar2[2]); //dia
        }
        
       
       

              matrizre[0][0]=matrizdia[1][0];
              matrizre[0][1]=matrizdia[1][1];
              matrizre[0][2]=matrizdia[1][2];

        for (int j = 0; j <= 384630; j++)
        {
            if (matrizdia[j][0]==matrizdia[j+1][0] && matrizdia[j][1]==matrizdia[j+1][1] && matrizdia[j][2]==(matrizdia[j+1][2]))
            {
                num=num+matrizdia[j][3];
                
            }
             else
             {
              
              num=num+matrizdia[j][3];
              matrizre[s][3]=num;
              num=0;
              s=s+1;
              matrizre[s][0]=matrizdia[j+1][0];
              matrizre[s][1]=matrizdia[j+1][1];
              matrizre[s][2]=matrizdia[j+1][2];
             }

        
            
        }
        pendiente=(matrizre[0][3]-(matrizre[1][3]))/(matrizre[0][2])-(matrizre[1][2]);
        PROMv=(matrizre[0][3]+matrizre[1][3])/2;
        PROMt=(matrizre[0][2]+matrizre[1][2])/2;
        interseccion=PROMv-(pendiente*PROMt);

        std::cout <<"Modelo de regresion lineal"<<std::endl;  
        std::cout <<"Venta="<<interseccion<<" + "<<pendiente<<"(fecha)"<<std::endl;  
        //ventas=fecha*pendienete+-intercepto
        q=0,7;
        
        F =   (1 - q) * matrizre[0][3];
        std::cout <<"Modelo de suavizamiento exponencial"<< "( (q) varia de 0 a 1, en este caso ocupamos 0,7)"<<std::endl;  
        //std::cout <<"Venta ="<< F << "(fecha)" <<std::endl;
        std::cout << "Venta = "<< "q * fecha (dia anterior)" << " + " << F << std::endl;
         for (int o = 0; o <= 384630; o++)
        {
            
           suma1=suma1+matrizdia[o][3];
           suma2=suma2+(matrizdia[o][3]*matrizdia[o][3]);  
         } 
          std::cout <<"Modelo de Regresion polinomica"<<std::endl;  
          std::cout <<"Venta= "<<"384630"<< " + "<< suma1<< "(fecha)" <<" + "<< suma2 << "(fecha)x^2" <<std::endl; 
    } 
        
       
      //y=ax+b ---> a=y°-(b*x°) --°=promedio de los datos correspondientes
    // {

    //}
    // pendiente=(product-product)/product2-product1

    else
    {
        std::cout << "No se pudo abrir el archivo";
    }
}
