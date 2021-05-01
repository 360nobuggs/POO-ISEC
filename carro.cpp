/*  carro.cpp

    ->Vasco Oliveira 2019119011
    ->Alexandre Costa 21280755
    Created on 06 Nov. 2019.
*/

#include "carro.h"
#include <iostream>

//Construtor
Carro::Carro(char id, string marca, int energia,int energia_total, int velocidade_max, string modelo){
    this->id = id;
    this->marca = marca;
    this->modelo = modelo;
    this -> energia_total=energia_total;
    this->velocidade_max = velocidade_max;
    this->energia=energia;
    this->energia_total=energia_total;


}
Piloto Carro::getpil() {
    Piloto pil= *piloto;

    return pil;
}
//Getters
int Carro::getenergia() {
    return this->energia;

}
string Carro::getpiloto() {
    if(isupper(this->id) != 0){
        return piloto->getnome();
    }
    return "N/A";
}
int Carro::getvelocidade()  {
    return this->velocidade;
}
char Carro::getid(){
    return id;
}
string Carro::getmarca(){
    return this->marca;
}
int Carro::getvelmax(){
    return this->velocidade_max;
}
string Carro::getmodelo(){
    return this->modelo;
}
bool Carro::getdano(){
    return this->dano;
}
bool Carro::getsinalemer(){
    return this->sinal_emer;
}
void Carro::fix(){
    if(getdano())
    {
        dano=false;
    }
}
//Setters
void Carro::setid(){
    id = toupper(id);
}
void Carro::setpiloto(Piloto *pilotoaux) {
    piloto= pilotoaux;
}
void Carro::addenergia(int energia){
    this->energia += energia;
    if(this->energia > this->energia_total)
        this->energia = this->energia_total;
}
void Carro::setenergia(int energia){
    this->energia = energia;
}

/*
void Carro::crash(){
    this->dano = true;
    Piloto *p = &piloto;
    p = NULL; //colocar objeto piloto como nulo
    this->velocidade = 0;};
*/
void Carro::speedup(){ //só aumenta velocidade assim
    if(getenergia()>0 && getvelocidade() <= velocidade_max) {

            this->velocidade++;

    }
}
void Carro::speedown( ) {


        this->velocidade--;


}
void Carro::setdistancia(int dist) {
    distancia= dist;
}
void Carro ::movimento( ) {
    if (getenergia() > 0) {
       energia = energia-(getvelocidade() * 0.1); //perde 0.1 mhamp por ms
    } else {
        if (velocidade > 0) {
        velocidade--; //perde por segundo velocidade até chegar a 0
    }
    } // Se além disso o condutor travar, o seu efeito é somado ao efeito de perda de velocidade por falta de energia.
}
void Carro::emergencia()
    {
        if (sinal_emer = 0){
            sinal_emer = true;

        }
        else{
            sinal_emer = false;
        }

}
int Carro::getdistancia()
{
    return distancia;
}
int Carro::move(int distanciaaux) {
    distancia= distancia+ distanciaaux;
}
int Carro::get_energia_total()
{
    return energia_total;
}
void Carro::empty()
{
    piloto->inout();//rip objeto ?
    piloto= nullptr;
}

void Carro::charging() {
    if(velocidade==0) {
        energia=energia_total;
    }
    }

int Carro::get_pos()  {
    return posicao;
}
void Carro::set_pos(int pos) {
    posicao=pos;
}
void Carro::crash() {
    velocidade=0;
    dano=true;
    energia=0;
}

void Carro:: setspeed(int vel)
{
    velocidade=abs(vel);
}
int Carro::getvitorias() {
    return vitorias;
}
void Carro::setvitorias(int vit) {
    vitorias=vit;
}