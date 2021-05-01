/*  crazy_driver.h

    ->Vasco Oliveira
    ->Alexandre Costa 21280755
    Created on 06 Nov. 2019.
*/

#ifndef CRAZY_DRIVER_H
#define CRAZY_DRIVER_H


class Crazy_Driver: public Piloto { //vai herdar piloto
private:
    string tipo;
    bool incar= false;
    string nome ;
    int pos_ant=20;
public:
int delay();
int behavior(int posicao);
int behavior_loser(int posicao,int energia);
bool destroitudo();
Crazy_Driver(string tipo, string nome);
};


#endif //CRAZY_DRIVER_H
