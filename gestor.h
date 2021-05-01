/*  crazy_driver.cpp

    ->Vasco Oliveira 2019119011
    ->Alexandre Costa 21280755
    Created on 22 Nov. 2019.
*/

#ifndef GESTOR_H
#define GESTOR_H
#include "consola.cpp"

class Gestor {
private:
    dgv DGV;
    vector<Autodromo> campeonato;
    vector<Carro> pista;
public:
    static Gestor * getInstance();
    void start();
    void visualizacao();
    void carromov();
};


#endif //GESTOR_H