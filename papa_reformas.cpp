#include "papa_reformas.h"

//
// Created by VascoOliveira on 02-Jan-20.
//
papa_reformas::papa_reformas(string tipo, string nome): Piloto( tipo, nome) {
}

bool papa_reformas::behavior() {

        int k=(rand() % 70) + 1;
        if(k==1)
        {
            return true; //vai desacelarar
        }
        else
            return false;
//blue shell
}
bool papa_reformas::blue_shell(int posicao) {
    if (posicao == 10) { //ultima posição
    int k = (rand() % 80) + 1;
    if (k == 7) {
        return true; //vai lançar blue shell para destruir o primeiro piloto
    } else
        return false;
}
}
bool papa_reformas::banana(int posicao) {
    if(posicao==1) {
        int k = (rand() % 50) + 1;
        if (k == 1) {
            return true; //vai largar uma banana e fazer o piloto antes deste reduzir 20 m/s
        } else
            return false;
    }
}
bool papa_reformas::nitro() {
    int k = (rand() % 4) + 1;
    if (k == 3) {
        return true; //vai largar uma banana e fazer o piloto antes deste reduzir 20 m/s
    } else
        return false;
}