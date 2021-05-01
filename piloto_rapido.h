//
// Created by VascoOliveira on 02-Jan-20.
//

#ifndef OMEGA_PILOTO_RAPIDO_H
#define OMEGA_PILOTO_RAPIDO_H


class piloto_rapido :public Piloto {
private:
    string tipo;
    bool incar= false;
    string nome ; //Quero fazer John + nome aleatoriamente gerado por uma library eg: jonh sullivan john macarroni john redneck
    /*O nome de cada piloto é único. Este aspeto é verificado automaticamente pela classe que, se
    detetar repetição, modificará o nome dado automaticamente de forma a ser único*/
public:
    bool behavior(int energia, int energia_total);
bool panic(int tempo);
piloto_rapido(string tipo, string nome);
};


#endif //OMEGA_PILOTO_RAPIDO_H
