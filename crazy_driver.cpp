/*  crazy_driver.cpp

    ->Vasco Oliveira
    ->Alexandre Costa 21280755
    Created on 06 Nov. 2019.
*/

#include "crazy_driver.h"
Crazy_Driver::Crazy_Driver(string tipo, string nome): Piloto( tipo, nome) {
}

int Crazy_Driver::delay() {
    return rand() % 5 + 1; //delay entre 1 e 5 segundos
}
int Crazy_Driver::behavior(int posicao) {
if(posicao==1)
{
    return 0; //mantem a velocidade
}
else if (posicao==10) //mudar para ultima posiçao dependendo da pista
{
    return -1; //desiste e trava
} else{
    return 1;// acelera
}

}
int Crazy_Driver::behavior_loser(int posicao,int energia) {
    if (energia == 0) {
        return 3; //ativa sinal de emergencia
    } else {
    if (posicao < pos_ant) {
        pos_ant=posicao;
        return 2; //acelera 2x por segundo ??
    }
    else{pos_ant=posicao; return 0;}

}
}
bool Crazy_Driver:: destroitudo()
{
    int k=(rand() % 20) + 1;
    if(k==5)
    {
        return true;
    }
    else return false;
}