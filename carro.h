/*  carro.h

    ->Vasco Oliveira 2019119011
    ->Alexandre Costa 21280755
    Created on 06 Nov. 2019.
*/

#ifndef CARRO_H
#define CARRO_H
#include <string>
#include "piloto.cpp"
using namespace std;
class Carro {
private:
    char id; /*automaticamente atribuída na criação do carro. Se houver mais carros que letras, os excedentes ficam com a letra ‘?’.
                A atribuição da letra é automática (sem intervenção do resto do programa), sento o primeiro ‘a’.*/
    string marca;
    string modelo; //mas se nada for dito, terá o modelo "modelo base".
    int energia;
    int energia_total;
    /*Pode ser carregado, mas para isso deve estar parado. O processo de carregamento envolve uma manivela que fornece nmAh, sendo n 
    maior que zero. O carro não permitirá ultrapassar a capacidade máxima da sua bateria. A capacidade máxima e a capacidade inicial
    são características especificadas quando um carro é fabricado. O valor n é indicado quando a operação é feita. */
    int velocidade = 0;
    int velocidade_max;
    Piloto *piloto = nullptr;
    bool dano = false;
    bool sinal_emer = false;
    int distancia=0;
    int posicao=0;
    int vitorias=0;

public:
    //Construtor
    Carro(char id, string marca, int energia,int energia_total, int velocidade_max, string modelo = "Modelo base");
    Piloto getpil();
    //Setters
    void setid();
    void setpiloto(Piloto *pilotoaux);
    void addenergia(int energia);
    void setenergia(int energia);

    //Getters
    char getid();
    string getmarca();
    int getvelocidade();
    int getenergia();
    int getvelmax();
    string getpiloto();
    string getmodelo();
    bool getdano();
    bool getsinalemer();
    int get_energia_total();
    void speedup();
    int  move(int distanciaux);
    int getdistancia();
    void setdistancia(int dist);
    void empty();
    void speedown();
    void movimento();
    void emergencia();
    void charging();
    int get_pos();
    void fix();
    void setspeed(int vel);
    void set_pos(int pos);
    void crash();//dano no carro<
    int getvitorias();
    void setvitorias(int vit);
    //virtual ~Carro() override;
    //An object of a class cannot be set to NULL; however, you can set a pointer (which contains a memory address of an object) to NULL.
};
#endif //CARRO_H

