#include <iostream>
#include "funciones.h"

using namespace std;


int main( int argc, char** argv){
    
    if (argc == 2){
            archivo(argv[1]);
            
        }
        else
        {
            participantes();

        }
    
    return 0;
}