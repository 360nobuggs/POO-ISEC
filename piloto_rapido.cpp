//
// Created by VascoOliveira on 02-Jan-20.
//
//É extremamente ansioso e começa a correr no primeiro segundo da corrida.
#include "piloto_rapido.h"
piloto_rapido::piloto_rapido(string tipo, string nome): Piloto( tipo, nome) {

}

bool piloto_rapido::behavior(int energia, int energia_total) {


    if(energia <= (energia_total/2))
    {
    return true;
    }
    else return false;
}
bool piloto_rapido::panic(int tempo) {
if(tempo%10==0)
{
    int k=(rand() % 10 )+ 1;
    if(k==2)
    {
        return true; //ativa o botão de emergencia
    }
    else
    return false;
}
    return false;
}
/*
Devido à sua ansiedade, a cada 10 segundos tem uma probabilidade 10% de sofrer um ataque
de pânico, e, caso se verifique esta situação, ativa o botão de emergência.*/