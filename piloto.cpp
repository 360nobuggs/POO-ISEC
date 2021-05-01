/*  piloto.cpp

    ->Vasco Oliveira 2019119011
    ->Alexandre Costa 21280755
    Created on 06 Nov. 2019.
*/

#include "piloto.h"
#include <iostream>
#include "crazy_driver.cpp"
#include "piloto_rapido.cpp"
#include "papa_reformas.cpp"
//Construtor
Piloto::Piloto(string tipo, string nome){
    this->tipo = tipo;
    this->nome =nome;
}

string Piloto::gettipo(){
    return tipo;
}
string Piloto::getnome(){
    return nome;
}

void Piloto::inout() {
    incar= !incar;
}
bool Piloto::driving( )
{
    return incar;
}

void Piloto::die()
{
    vivo=false;
}
int Piloto::getvitorias() {
    return vitorias;
}
void Piloto::setvitorias(int vit) {
    vitorias=vit;
}