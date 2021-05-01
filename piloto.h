/*  piloto.h

    ->Vasco Oliveira 2019119011
    ->Alexandre Costa 21280755
    Created on 06 Nov. 2019.
*/

#ifndef PILOTO_H
#define PILOTO_H


class Piloto {
protected:
    string tipo;
    bool incar= false;
    string nome ; //Quero fazer John + nome aleatoriamente gerado por uma library eg: jonh sullivan john macarroni john redneck
    /*O nome de cada piloto é único. Este aspeto é verificado automaticamente pela classe que, se
    detetar repetição, modificará o nome dado automaticamente de forma a ser único*/
    bool vivo= true;
    int vitorias=0;
public:
    //Construtor
    Piloto(string tipo, string nome);
    void die();
    Piloto();
    int getvitorias();
    void setvitorias(int vit);
    //Getters
    string getnome();
    string gettipo();
    
    void inout();
    bool driving();
};
#endif //PILOTO_H