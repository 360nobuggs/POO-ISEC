//
// Created by VascoOliveira on 02-Jan-20.
//

#ifndef OMEGA_PAPA_REFORMAS_H
#define OMEGA_PAPA_REFORMAS_H


class papa_reformas:public Piloto {
private:
    string tipo;
    bool incar= false;
    string nome ; //Quero fazer John + nome aleatoriamente gerado por uma library eg: jonh sullivan john macarroni john redneck
public:
    bool behavior();
    bool blue_shell(int posicao);
    bool banana(int posicao);
    bool nitro();
    papa_reformas(string tipo , string nome);

};


#endif //OMEGA_PAPA_REFORMAS_H
