#include <iostream>
#include <string>
#include <chrono>
typedef std::basic_string<char> string;
#include "dgv.cpp"
#include <vector>
#include "gestor.cpp"
int main() {
    //vector<Carro> *carro, std::vector<Piloto> *piloto
    auto start = std::chrono::steady_clock::now(); //variaveis temporais implementação possivel mais tarde
    auto end = std::chrono::steady_clock::now();

    //gestor
    Gestor::getInstance()->start();
    return 0;
}
