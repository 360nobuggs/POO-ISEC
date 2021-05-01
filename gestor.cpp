/*  crazy_driver.cpp

    ->Vasco Oliveira 2019119011
    ->Alexandre Costa 21280755
    Created on 22 Nov. 2019.
*/
using namespace std;
#include "gestor.h"
Gestor* Gestor::getInstance() {
    static Gestor* instance = 0;
    if (instance == 0) {
        instance = new Gestor();
    };
    return instance;
}
void Gestor::start() {
    cout << " Fase de setup: todos os comandos disponiveis para preparar o campeonato. \n";
    DGV.leitura();
    campeonato= DGV.getrace();// vai buscar o campeonato

    pista = campeonato[0].getpista();// carrega a pista
    //visualizacao();
    int n_auto=-1;
    dgv backup;
    string s;
    string vencedor = "";
    string ultimate_vencedor = "";
    int n;
    int wait;
    string tipo;
    //bloco de teste
    bool go = false;

/*
    Piloto papa1("papa", "papa1");
    Piloto papa2("papa", "papa2");
    Piloto papa3("papa", "papa3");
    Piloto rap("rapido", "fast");
    Piloto cray("crazy", "crazy");
    Piloto normal("normal", "normal");


    Carro a('a', "ferro", 100, 100, 300, "hey");
    Carro b('b', "ferro", 50, 100, 300, "hey");
    Carro c('c', "ferro", 25, 100, 300, "hey");
    Carro e('c', "ferro", 75, 100, 300, "hey");
    Carro f('c', "ferro", 100, 100, 300, "hey");
    Carro g('c', "ferro", 25, 100, 300, "hey");
    a.setpiloto(&rap);
    b.setpiloto(&cray);
    c.setpiloto(&papa1);
    e.setpiloto(&papa2);
    f.setpiloto(&papa3);
    g.setpiloto(&normal);
    Autodromo au("vroom", 10, 1000);
    Autodromo aus("vroom", 10, 1000);
    Autodromo au2("vroom", 10, 1000);
    Autodromo aus3("vroom", 10, 1000);
    Autodromo au4("vroom", 10, 1000);
    Autodromo au5("vroom", 10, 1000);
    campeonato.push_back(au);
    campeonato.push_back(aus);
    campeonato.push_back(au2);
    campeonato.push_back(aus3);
    campeonato.push_back(au4);
    campeonato.push_back(au5);
    pista.push_back(a);
    pista.push_back(b);
    pista.push_back(c);
    pista.push_back(e);
    pista.push_back(f);
    pista.push_back(g);
    Carro ultimo(103, "ferro", 25, 100, 300, "hey");
    ultimo.setdistancia(50);
    //bloco de teste
    */
    cout << "settup feito \n";

    while (ultimate_vencedor == "") {
        if(!go)
        {
            if(ultimate_vencedor!="")
            {
                break;
            }
            cout<<"Para comecar a corrida escreva: corrida \n";
            getline(cin, s); //aguarda input do user
            if ((s.find("corrida")) != string::npos) {
                n_auto++; //seleciona o autodromo
                if(n_auto!=0)
                {

                    cout<<"Corrida "<<n_auto+1<<"!\n";
                    auto iter=pista.begin();
                    for (; iter != pista.end(); iter++) { //fix them
                        (*iter).setenergia((*iter).get_energia_total());
                        (*iter).setspeed(0);
                        (*iter).fix();
                        (*iter).setdistancia(0);
                        vencedor="";
                    }
                }



                go=true;
                cout << " Fase de corrida: comando passatempo disponivel! \n";
            }
        }

        while (vencedor == "" &&(go)) {
            getline(cin, s); //aguarda input do user
            if ((s.find("savedgv")) != string::npos) {
                backup = DGV.estedgv(); //faz backup do dgv
                cout << "dvg guardado \n";
            }
            if ((s.find("loaddgv")) != string::npos) {
                DGV = backup;
                cout << "dvg carregado \n";
            }
            if ((s.find("delddgv")) != string::npos) {
                backup.~dgv();//apaga backup
                cout << "dvg de backup eliminado \n";
            }

            if ((s.find("passatempo")) != string::npos) {
                size_t last = s.find_last_of(" ");
                int segundos = stoi(s.substr(last + 1, s.length()));
                //int segundos =30;
                for (int i = 0; i < segundos; i++) {
                    cout << "start:" << segundos << "\n";
                    auto iter = pista.begin();

                    vector<int> distancias;
                    int j = 0;
                    for (; iter != pista.end(); iter++) {
                        distancias.push_back((*iter).getdistancia());
                    }
                    iter = pista.begin();
                    sort(distancias.begin(), distancias.end(), greater<int>());//ordena valores
                    for (; iter != pista.end(); iter++) {
                        for (int k = 0; k < distancias.size(); k++) {
                            if (distancias.at(k) == (*iter).getdistancia()) {
                                (*iter).set_pos(k + 1);
                            } //coloca posiçoes
                        }
                        if ((*iter).get_pos() == distancias.size()) {
                            //(*iter).set_pos(10);
                        }
                    }
                    iter = pista.begin();
                    for (; iter != pista.end(); iter++) {
                        (*iter).movimento();//gasta energia

                        (*iter).setdistancia(
                                ((*iter).getdistancia() + (*iter).getvelocidade()));//ganha por exemplo 6 m por segundo
                        if ((*iter).getdistancia() >= campeonato[n_auto].getComprimento()) {
                            go= false;
                            vencedor = (*iter).getpil().getnome() + " Ganhou a corrida no carro " + (*iter).getid()+"\n";
                            (*iter).setvitorias((*iter).getvitorias()+1);

                            if((*iter).getvitorias()>=abs(campeonato.size())||(*iter).getvitorias()>=3)//se tiver mais de metade do numero de autodromos, ganha automaticamente
                            {
                                ultimate_vencedor=(*iter).getpil().getnome() + " Ganhou o campeonato no carro " + (*iter).getid()+"\n";
                                cout<< ultimate_vencedor;
                            }
                            break;
                        }
                    }
                    iter = pista.begin();
                    for (; iter != pista.end(); iter++) {
                        cout << "lugar: " << (*iter).get_pos() << " metros: " << (*iter).getdistancia() << " nome: "
                             << (*iter).getpil().getnome() << " energia: " << (*iter).getenergia() << " velocidade: "
                             << (*iter).getvelocidade();
                        if ((*iter).getdano()) {
                            cout << " DESTRUIDO ";
                        }
                        cout << "\n";
                    }

                    iter = pista.begin();
                    for (; iter != pista.end(); iter++) {
                        tipo = (*iter).getpil().gettipo();
                        if ((tipo == "papa") && !(*iter).getdano()) {
                            papa_reformas papa((*iter).getpil().getnome(),
                                               (*iter).getpil().gettipo()); //cria um piloto identico auxiliar
                            if (papa.behavior()) {
                                (*iter).speedown();//reduz
                            } else { (*iter).speedup(); }//acelera
                            if ((*iter).get_pos() == distancias.size()) { //se em ultimo lugar
                                if (papa.blue_shell(10)) {
                                    cout << "PUMM O CARRO DO PILOTO " << pista.at((1)).getpil().getnome()
                                         << " EXPLODIU \n";
                                    pista.at(1).crash();//destroi o primeiro carro
                                    pista.at(1).getpil().die(); //mata o piloto
                                }
                            }
                            if (papa.banana((*iter).get_pos())) {
                                pista.at((*iter).get_pos() - 1).setspeed(
                                        pista.at((*iter).get_pos() - 1).getvelocidade() -
                                        2);//reduz velocidade ao que vai atras
                            }
                            if (papa.nitro()) {
                                (*iter).speedup();
                                (*iter).speedup();
                                (*iter).speedup();
                            }

                        } else if ((tipo == "crazy" && !(*iter).getdano())) {
                            Crazy_Driver crazy((*iter).getpil().getnome(), (*iter).getpil().gettipo());

                            if ((*iter).getdistancia() == 0) {
                                wait = crazy.delay();
                                //AVANÇA 1
                                (*iter).setdistancia(1);
                            }
                            wait--;
                            if (wait <= 0) {
                                if (crazy.behavior((*iter).get_pos()) == 1) { (*iter).speedup(); } //acelera
                                else if (crazy.behavior((*iter).get_pos()) == -1) { (*iter).speedown(); }

                                if (crazy.behavior_loser((*iter).get_pos(), (*iter).getenergia()) == 3) {
                                    (*iter).emergencia(); //Se algum carro ligar o sinal de emergência, será removido da corrida e movido para a garagem.
                                    //A garagem é um local que permite armazenar carros. Quando um carro é colocado na
                                    //garagem, é indicado ao piloto para deixar o veículo, porque, para ele, a corrida acabou.



                                } else if (crazy.behavior_loser((*iter).get_pos(), (*iter).getenergia()) == 2) {
                                    (*iter).speedup();
                                    (*iter).speedup();
                                }
                                if (crazy.destroitudo()) {
                                    cout << "PUMM O CARRO DO PILOTO " << (*iter).getpil().getnome() << " EXPLODIU \n";
                                    (*iter).crash();
                                    pista.at((*iter).get_pos() - 1).crash();//destroi o carro antes
                                    cout << "PUMM O CARRO DO PILOTO "
                                         << pista.at((*iter).get_pos() - 1).getpil().getnome() << " EXPLODIU \n";
                                }

                            }
                            cout << "velocidade: " << (*iter).getvelocidade() << " \n";

                        } else if (tipo == "rapido" && !(*iter).getdano()) {
                            piloto_rapido rapido((*iter).getpil().getnome(), (*iter).getpil().gettipo());
                            if (rapido.behavior((*iter).getenergia(), (*iter).get_energia_total())) {
                                if (n == 3) //ao terceiro segundo gooooooooooooooooooo!
                                {
                                    n = 0;
                                    (*iter).speedup();
                                } else { n++; }
                            } else { (*iter).speedup(); }
                            if (rapido.panic(i)) { (*iter).emergencia();; } //EMERGENCIA


                        } else {//normal
                            (*iter).speedup();

                        }
                    }
                    if (vencedor != "") {
                        cout << vencedor;
                        break;
                    }
                    cout << "\n";
                }
            }
            if ((s.find("listacarros")) != string::npos) {
                auto iter_c = pista.begin();
                cout << endl << "Lista de Carros" << endl;
                for (; iter_c != pista.end(); iter_c++) {
                    cout << "\nID: " << (*iter_c).getid();
                    cout << "\n\tMarca: " << (*iter_c).getmarca();
                    cout << "\n\tModelo: " << (*iter_c).getmodelo();
                    cout << "\n\tEnergia: " << (*iter_c).getenergia();
                    cout << "\n\tEnergia Max: " << (*iter_c).get_energia_total();
                    cout << "\n\tVelocidade Max: " << (*iter_c).getvelmax();
                    cout << "\n\tPiloto: " << (*iter_c).getpiloto();
                    cout << "\n\tDano: " << (*iter_c).getdano();
                    cout << "\n\tSinal Emergencia: " << (*iter_c).getsinalemer() << endl;
                }
            }

            if ((s.find("carregabat")) != string::npos) {
                size_t last = s.find_first_of(" ");
                char id = s[last + 1];
                last = s.find_last_of(" ");
                int energ = stoi(s.substr(last + 1, s.length()));

                auto iter = pista.begin();
                for (; iter != pista.end(); iter++) {
                    if ((*iter).getid() == id) {
                        (*iter).addenergia(energ);
                        cout << "Bateria do carro " << id << " carregada\n";
                    }
                }
            }

            if ((s.find("carregatudo")) != string::npos) {
                break;
                auto iter = pista.begin();
                for (; iter != pista.end(); iter++) {
                    (*iter).addenergia((*iter).get_energia_total());
                    cout << "Bateria do carro " << (*iter).getid() << " carregada\n";
                }
            }

            if ((s.find("acidente")) != string::npos) {
                size_t last = s.find_last_of(" ");
                char id = s[last + 1];

                auto iter = pista.begin();
                for (; iter != pista.end(); iter++) {
                    if ((*iter).getid() == id) {
                        (*iter).crash();
                    }
                }
            }

            if ((s.find("stop")) != string::npos) {
                size_t last = s.find_last_of(" ");
                string nome = s.substr(last + 1, s.length());

                auto iter = pista.begin();
                for (; iter != pista.end(); iter++) {
                    if ((*iter).getpiloto() == nome) {
                        (*iter).setenergia(0);
                    }
                }

            }
        }

    }
}
/*
void Gestor::visualizacao(){
    Consola::clrscr();
    Consola::setScreenSize(campeonato[0].getComprimento(), 40);
    Consola::setTextSize(10, 10);
    Consola::setTextColor(Consola::VERDE);
    Consola::setBackgroundColor(Consola::PRETO);
    Consola::gotoxy(10, 10);


    auto iter = pista.begin();
    int j=0;
    for (; iter != pista.end(); iter++) {
        Consola::gotoxy(campeonato[0].getComprimento(), 5+j);
        cout<< "META";
        Consola::gotoxy(0, 5+j);
        cout<< (*iter).getid();
        j++;
    }
    Consola::gotoxy(0, 0);
};
void Gestor::carromov()
{
    Consola::clrscr(); //apaga posição antiga
    int j=0;
    auto iter = pista.begin();
    for (; iter != pista.end(); iter++) {
        Consola::gotoxy(campeonato[0].getComprimento(), 5+j);//meta no final tirei um 1Nurburgring
        cout<< "|";
        Consola::gotoxy((*iter).getdistancia(), 5+j);
        cout<< (*iter).getid(); //imprime na posição o nosso carro
        j++;
    }
}*/

