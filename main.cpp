#include <iostream>
#include <fstream>
#include <vector>
#include "funciones.h"
#include <string>

using std::cin;
using std::endl;
using std::vector;
using std::ifstream;
using std::ofstream;

int main(int argc, char* argv[]) {

  
  int nelements, i, j, existe;
  string line, prefix;

  vector<string> registro, resultado;

  
  ifstream archivo1(argv[1]); 
  ofstream archivo2(argv[2]);

  
  archivo1 >> nelements >> prefix;

  do{
     getline(archivo1, line);

    if(archivo1.good()){
      existe = SearchPrefix(line, prefix);

      if(existe >= 0){
        registro.push_back(line);
      }
    }
    i++;
  } while (i < nelements);

  resultado = sortRegister(registro);

  for (j = 0; j < resultado.size(); j++){
    archivo2 << resultado[j] << endl;
  }

  archivo1.close();
  archivo2.close();

  return 0;

}