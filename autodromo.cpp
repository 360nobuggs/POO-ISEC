/*  autodromo.cpp

    ->Vasco Oliveira 2019119011
    ->Alexandre Costa 2018015537
    Created on 07 Nov. 2019.
*/

#include "autodromo.h"
//Construtor
Autodromo::Autodromo(string nome, int n_carros, int comprimento){
    this->nome = nome;
    this->n_carros = n_carros;
    this->comprimento = comprimento;
}

//Getters
string Autodromo::getNome(){
    return nome;
}

int Autodromo::getN_Carros(){
    return n_carros;
}

int Autodromo::getComprimento(){
    return comprimento;
}

bool Autodromo::getDestruido(){
    return destruido;
}

//Setters
void Autodromo::setNome(string nome){
    this->nome = nome;
}

void Autodromo::setN_Carros(int n_carros){
    this->n_carros = n_carros;
}

void Autodromo::setDestruido(bool destruido){
    this->destruido = destruido;
}

//Pista Vazia
bool Autodromo::pistaVazia(){ 
    if(pista.empty()){
        return true;
    }
}

//Garagem Vazia
bool Autodromo::garagemVazia(){
    if(garagem.empty()){
        return true;
    }else{
        return false;
    }
}
void Autodromo::carregagaragem(Carro carroaux)
{
    cout<< " garagem ";
    garagem.push_back(carroaux);
}
void Autodromo::carregapista(Carro carroaux)
{
    cout<< " pista ";
    pista.push_back(carroaux);
}
bool Autodromo::pistacheia()
{
    if (pista.size()== getN_Carros())
    {
        return 1;
    }
}
vector<Carro> Autodromo::getpista() {
    return pista;
}