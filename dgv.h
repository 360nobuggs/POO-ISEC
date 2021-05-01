/*  crazy_driver.cpp

    ->Vasco Oliveira 2019119011
    ->Alexandre Costa 21280755
    Created on 07 Nov. 2019.
*/
#ifndef DGV_H
#define DGV_H
#include <iostream>
#include <string>
typedef std::basic_string<char> string;
using namespace std;
#include "autodromo.cpp"
#include <vector>

class dgv {

private:
    vector<Piloto> pilotos; //vetor de pilotos vazio
    vector<Carro> carros;
    vector<Autodromo> autodromos;
    vector<Autodromo> campeonato;

public:
    dgv();
     void leitura();
     vector<Autodromo> getrace();
     dgv estedgv();
      ~dgv();
};


#endif //DGV_H