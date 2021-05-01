/*  autodromo.h

    ->Vasco Oliveira 2019119011
    ->Alexandre Costa 2018015537
    Created on 07 Nov. 2019.
*/

#ifndef AUTODROMO_H
#define AUTODROMO_H
#include <string>
#include <vector>
#include "carro.cpp"
using namespace std;

class Autodromo {
private:
    string nome; //O nome de cada autódromo é único, sendo isto validado e corrigido automaticamente pela classe em questão
    int n_carros; //Nº de carros que a pista suporta
    int comprimento;//Tamanho (em metros) da pista
    bool destruido = false; //Estado da pista
    
    vector<Carro> pista; //Uma pista guarda um vetor com os carros
    vector<Carro> garagem; //Uma garagem guarda um vetor com os carros

public:
    //Construtor
    Autodromo(string nome, int n_carros, int comprimento);
    
    //Getters
    vector<Carro> getpista();
    string getNome();
    int getN_Carros();
    int getComprimento();
    bool getDestruido();
    
    //Setters
    void setNome(string nome);
    void setN_Carros(int n_carros);
    void setDestruido(bool destruido);
    
    void carregagaragem(Carro carroaux);
    void carregapista(Carro carroaux);
    bool pistacheia();
    //Funções para ver se a pista/garagem está vazia
    bool pistaVazia();
    bool garagemVazia();

    //Inicia a corrida [WIP]
    //void iniciarCorrida();
    //Adiciona os carros do DGV para a garagem [WIP]
    //g_addCarro();
    //Adiciona os carros da garagem para a pista [WIP]
    //p_addCarro();
    //Acaba a corrida [WIP]
    //terminarCorrida();
};
#endif //AUTODROMO_H

