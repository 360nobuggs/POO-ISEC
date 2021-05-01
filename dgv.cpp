/*  crazy_driver.cpp

    ->Vasco Oliveira 2019119011
    ->Alexandre Costa 21280755
    Created on 07 Nov. 2019.
*/
#include "dgv.h"
#include <bits/stdc++.h>
using namespace std;
dgv::dgv()
{
}

void dgv::leitura() {
    string s;
    do {

        //CARREGA PILOTOS A PARTIR DE UM FICHEIRO
        getline(cin, s);
        if ((s.find("carregaP")) != string::npos) //retorna posição onde encontra a palavra
        {
            size_t last = s.find_last_of(" ");
            s = s.substr(last + 1);//valor do ultimo espaço +1 para não envolver o espaço
            //se o ultimo espaço for no fim dá erro ;assert maybe ?
            cout << "Found:" << s << '\n';
            string line;
            string words[2];
            fstream file;
            string word;
            file.open(s.c_str());
            if (!file.is_open())
                cout << "ficheiro nao enccontrado";
            while (getline(file, line)) {

                size_t last = line.find_last_of(" ");
                words[0] = line.substr(0, last);//tipo de piloto
                words[1] = line.substr(last + 1, line.length());//nome
                if (words[0] == "papa") {
                    papa_reformas papa(words[0], words[1]);
                    pilotos.push_back(papa);

                } else if (words[0] == "crazy") {
                    Crazy_Driver crazy(words[0], words[1]);
                    pilotos.push_back(crazy);

                } else if (words[0] == "rapido") {
                    piloto_rapido rapido(words[0], words[1]);
                    pilotos.push_back(rapido);
                } else {
                    word= words[1];
                    auto ip = find_if(pilotos.begin(), pilotos.end(),
                                      [&word](Piloto &piloto) { return piloto.getnome().compare(word); });
                    if (ip != pilotos.end()) { //encontrou um piloto com o mesmo nome
                        char randy = 'a' + rand() % 26;
                        Piloto piloto("normal", word + randy); //piloto de nome alterado
                        pilotos.push_back(piloto);
                    } else {
                        Piloto piloto("normal", word); //piloto de nome normal
                        pilotos.push_back(piloto);
                    }
                }
                cout << " " << words[1]; //le todos os nomesca
                cout<<"\n";
            }

        }

        //CARREGA CARROS A PARTIR DE UM FICHEIRO
        if ((s.find("carregaC")) != string::npos) //retorna posição onde encontra a palavra
        {
            size_t last = s.find_last_of(" ");
            s = s.substr(last + 1);//valor do ultimo espaço +1 para não envolver o espaço
            //se o ultimo espaço for no fim dá erro ;assert maybe ?
            cout << "Found:" << s << '\n';

            size_t pos = 0;
            string token;
            string delimiter = " ";
            fstream file;
            string line;
            string words[4]; //regista todos os campos para criar um carro
            char id[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k','l','n','o','p','q','r','s','t','u','v','x','w','y','z','!'};
            int nid = 0;
            file.open(s.c_str());
            if (!file.is_open())
                cout << "ficheiro nao encontrado";
            while (getline(file, line)) {
                //cout<< line;
                int k = 0;
                while ((pos = line.find(" ")) != string::npos) {
                    token = line.substr(0, pos);
                    //cout << token;
                    words[k] = token;// k++ nao estava a funcionar ?? dai ter feito outra forma LOL
                    line.erase(0, pos + delimiter.length());//vai apagando conforme vai lendo
                    k = k + 1;
                }
                words[3] = line; //carrega o fim da lista, ou seja o ultimo parametro
                //cout<< line;
                /*
                * words[0] : energia atual
                * words[1] : marca
                * words[2] : modelo
                * words[3] : top speed
                */
                //cout<< '\n' << words[1] << " ***** " << stoi(words[4]);
                if(id[nid]!='!') //se ja nao tiver modelos
                {//começa com energia total
                    Carro carro(id[nid++], words[1], stoi(words[0]),stoi(words[0]), stoi(words[3]),words[2]);
                    carros.push_back(carro);

                    line.push_back('\n');
                } else{
                    Carro carro('?', words[1], stoi(words[0]),stoi(words[0]), stoi(words[3]),words[2]);
                    carros.push_back(carro);

                    line.push_back('\n');
                }

                //cout << carro.getenergia();

            }
        }

        //CARREGAR AUTÓDROMOS A PARTIR DUM FICHEIRO
        if ((s.find("carregaA")) != string::npos) {
            size_t last = s.find_last_of(" ");
            s = s.substr(last + 1);//valor do ultimo espaço +1 para não envolver o espaço
            //se o ultimo espaço for no fim dá erro ;assert maybe ?
            cout << "Found:" << s << '\n';

            size_t pos = 0;
            string token;
            string delimiter = " ";
            fstream file;
            string line;
            string words[3]; //regista todos os campos para criar um autodromo
            int id = -1;
            file.open(s.c_str());
            if (!file.is_open())
                cout << "ficheiro nao encontrado";

            while (getline(file, line)) {
                //cout<< line;
                int k = -1;
                while ((pos = line.find(" ")) != string::npos) {
                    token = line.substr(0, pos);
                    k = k + 1;
                    words[k] = token;// k++ nao estava a funcionar ?? dai ter feito outra forma LOL
                    line.erase(0, pos + delimiter.length());//vai apagando conforme vai lendo
                }
                words[2] = line; //carrega o fim da lista, ou seja o ultimo parametro
                /* words[0] : numero
                * words[1] : distancia
                * words[2] : nome*/
                Autodromo autodromo(words[2], stoi(words[0]), stoi(words[1]));
                autodromos.push_back(autodromo);
            }
        }

        //ENTRA NO CARRO
        if ((s.find("entranocarro")) != string::npos) {
            size_t first = s.find_first_of(" ");
            size_t last = s.find_last_of(" ");
            string arg1 = s.substr(first + 1, last - first - 1);// primeiro argumento
            string arg2 = s.substr(last + 1);//segundo argumento
            //bloco de pesquisa do vector
            //carro
            auto index = 0;

            auto it = find_if(carros.begin(), carros.end(),
                              [&arg1](Carro &carro) { return carro.getid() == arg1[0]; });
            if (it != carros.end()) {
                // found element. it is an iterator to the first matching element.
                // if you really need the index, you can also get it:
                index = distance(carros.begin(), it);
                //cout << index;
            }

            //Carro carroauxiliar = carros[index];
            auto index1 = index;
            //piloto
            auto iq = find_if(pilotos.begin(), pilotos.end(),
                              [&arg2](Piloto &piloto) { return piloto.getnome() == arg2; });
            if (iq != pilotos.end()) {
                // found element. it is an iterator to the first matching element.
                // if you really need the index, you can also get it:
                index = distance(pilotos.begin(), iq);
                //cout << index;

            }
            if (pilotos[index].driving()) {
                cout << "O piloto ja esta num carro. \n ";
            } else {
                if(carros[index1].getdano()!=true) { //se o carro nao está destruido


                    carros[index1].setpiloto(&pilotos[index]);
                    carros[index1].setid(); //coloca upper case
                    pilotos[index].inout(); //o piloto está num carro
                    cout << " O piloto " << arg2 << " esta no carro " << arg1 << "\n";
                }
            }


        }

        //SAI DO CARRO
        if ((s.find("saidocarro")) != string::npos) {
            size_t last = s.find_last_of(" ");
            s = s.substr(last + 1);//valor do ultimo espaço +1 para não envolver o espaço
            auto index = 0;

            auto it = find_if(carros.begin(), carros.end(),
                              [&s](Carro &carro) { return carro.getid() == s[0]; });
            if (it != carros.end()) {
                index = distance(carros.begin(), it);
                cout << index;
            }
            carros[index].getpiloto();
            carros[index].empty();

        }

        //LISTA
        if ((s.find("lista")) != string::npos) {
            auto iter_p = pilotos.begin();
            auto iter_c = carros.begin();
            auto iter_a = autodromos.begin();
            cout<<endl<<"Lista de Pilotos"<<endl;
            for( ; iter_p != pilotos.end(); iter_p++){
                cout<<"\nNome: "<<(*iter_p).getnome();
                cout<<"\n\tTipo: "<<(*iter_p).gettipo()<<endl;
            }
            cout<<endl<<"Lista de Carros"<<endl;
            for( ; iter_c != carros.end(); iter_c++){
                cout<<"\nID: "<<(*iter_c).getid();
                cout<<"\n\tMarca: "<<(*iter_c).getmarca();
                cout<<"\n\tModelo: "<<(*iter_c).getmodelo();
                cout<<"\n\tEnergia: "<<(*iter_c).getenergia();
                cout<<"\n\tVelocidade Max: "<<(*iter_c).getvelmax();
                cout<<"\n\tPiloto: "<<(*iter_c).getpiloto();
                cout<<"\n\tDano: "<<(*iter_c).getdano();
                cout<<"\n\tSinal Emergencia: "<<(*iter_c).getsinalemer()<<endl;
            }
            cout<<endl<<"Lista de Autodromos"<<endl;
            for( ; iter_a != autodromos.end(); iter_a++){
                cout<<"\nNome: "<<(*iter_a).getNome();
                cout<<"\n\tN. Carros: "<<(*iter_a).getN_Carros();
                cout<<"\n\tComprimento: "<<(*iter_a).getComprimento();
                cout<<"\n\tDestruido: "<<(*iter_a).getDestruido()<<endl;
            }
        }

        //CAMPEONATO
        if ((s.find("campeonato")) != string::npos) {
            size_t pos = 0;
            int k=0;
            string delimiter=" ";
            string aux;
            string autodro[10];
            while ((pos = s.find(" ")) != string::npos) {
                aux = s.substr(0, pos);
                autodro[k] = aux;// k++ nao estava a funcionar ?? dai ter feito outra forma LOL
                s.erase(0, pos + delimiter.length());//vai apagando conforme vai lendo
                k = k + 1;
            }

            //programado só para um por enquanto
            auto index = 0;

        for(int i=1;i<k;i++)
        {
            auto iter=autodromos.begin();
            for (; iter != autodromos.end(); iter++) { //fix them
               if(autodro[i]==(*iter).getNome())
               {
                   campeonato.push_back((*iter));
                   //cout<<(*iter).getNome();
               }
            }
        }
            auto iter=autodromos.begin();
            for (; iter != autodromos.end(); iter++) { //fix them
                if(s==(*iter).getNome())
                {
                    campeonato.push_back((*iter));
                    cout<<(*iter).getNome();
                }
            }

    }

//CRIA PILOTO/CARRO/AUTODROMO A PARTIR DE UMA LINHA DE COMANDO
    if (s.find("cria") != string::npos) {
        string delimiter = " ";
        size_t pos = 0;
        string pil[2]; //argumentos a guardar no Piloto
        string car[5]; //argumentos a guardar no Carro
        string aut[3]; //argumentos a guardar no Autodromo
        string aux; //onde os tokens do substr são guardados
        int k = 0; //iteradod dos arrays

        //Procura o primeiro whitespace e retira o conteúdo à sua esquerda. Isto vai eliminar o "cria".
        pos = s.find(" ");
        s.erase(0, pos + 1);

        //Apaga todos os whitespaces antes do <tipo>
        //ex: "           p <nome>" passa a "p <nome>"
        //front() returns reference to first member of vector aka conteúdo do primeiro char
        //begin() returns an iterator aka [0]
        while (s.front() == ' ') {
            s.erase(s.begin());
        }

        //Identifica o <tipo> a criar (Piloto, autodromo ou Carro)
        if (s.find("p") == 0) {

            //Tira o "p" do comando, deixando só os argumentos para a sua adição.
            pos = s.find(" ");
            s.erase(0, pos + 1);

            //Tira o <tipo> do piloto para pil[0]
            pos = s.find(" ");
            pil[0] = s.substr(0, pos);
            s.erase(0, pos + 1);

            //Adiciona o restante da string (será o nome do piloto) a pil[1]
            pil[1] = s;
            auto ip = find_if(pilotos.begin(), pilotos.end(), [&s](Piloto &piloto) { return piloto.getnome().compare(s);});
            if (ip != pilotos.end()) { //encontrou um piloto com o mesmo nome
               cout<< "esse piloto ja esta na corrida \n";
            }
            else{
                Piloto piloto(pil[0], pil[1]); //piloto de nome normal
                pilotos.push_back(piloto);
                cout << "Found piloto:" << s << '\n';
            }
        } else if (s.find("c") == 0) {

            //Tira o "c" do comando, deixando só os argumentos para a sua adição.
            pos = s.find(" ");
            s.erase(0, pos + 1);

            while ((pos = s.find(" ")) != string::npos) {
                aux = s.substr(0, pos);
                car[k] = aux;// k++ nao estava a funcionar ?? dai ter feito outra forma LOL
                s.erase(0, pos + delimiter.length());//vai apagando conforme vai lendo
                k = k + 1;
            }
            /*
            car[0] : id
            car[1] : marca
            car[2] : energia
            car[3] : velocidade_max
            car[4] : modelo -> no código utilizamos o valor de s
            */

                //Couts de debug
                /*
                cout<<"Id: "<<car[0][0]<<endl;
                cout<<"Marca: "<<car[1]<<endl;
                cout<<"Energia: "<<car[2]<<endl;
                cout<<"VelocidadeMax: "<<car[3]<<endl;
                cout<<"Modelo: "<<car[4]<<endl;
                */

                Carro carro(car[0][0], car[1],stoi(car[2]),stoi(car[2]), stoi(car[3]), car[4]);
                carros.push_back(carro);

                cout << "Found carro:" << s << '\n';
            } else if (s.find("a") == 0) {

                //Tira o "a" do comando, deixando só os argumentos para a sua adição.
                pos = s.find(" ");
                s.erase(0, pos + 1);

                while ((pos = s.find(" ")) != string::npos) {
                    aux = s.substr(0, pos);
                    aut[k] = aux;// k++ nao estava a funcionar ?? dai ter feito outra forma LOL
                    s.erase(0, pos + delimiter.length());//vai apagando conforme vai lendo
                    k = k + 1;
                }
                /*
                aut[0] : nome
                aut[1] : n_carros
                aut[2] : comprimento
                */

                //Couts de debug
                /*
                cout<<"Nome: "<<aut[0]<<endl;
                cout<<"N Carros: "<<aut[1]<<endl;
                cout<<"Comprimento: "<<s<<endl;
                */


                Autodromo autodromo(aut[0], stoi(aut[1]), stoi(s));
                autodromos.push_back(autodromo);
                cout << "Found autodromo:" << s << '\n';
            } else
                cout << "Comando 'cria' invalido.\n";
        }
        //APAGA PILOTO/CARRO/AUTODROMO
        if(s.find("apaga") != string::npos){
            string delimiter = " ";
            size_t pos = 0;
            auto index = 0;

            //Procura o primeiro whitespace e retira o conteúdo à sua esquerda. Isto vai eliminar o "apaga".
            pos = s.find(" ");
            s.erase(0, pos + 1);

            //Apagar piloto
            if(s.find("p") == 0){
                //Tira o "p" do comando, deixando só o identificador
                pos = s.find(" ");
                s.erase(0, pos + 1);

                auto it = find_if(pilotos.begin(), pilotos.end(), [&s](Piloto &piloto) {
                    return piloto.getnome() == s;
                });
                if (it != pilotos.end()) {
                    // found element. it is an iterator to the first matching element.
                    // if you really need the index, you can also get it:
                    index = distance(pilotos.begin(), it);
                    pilotos.erase(pilotos.begin()+index);
                    //cout << index;
                }
            }

            //Apagar carro
            if(s.find("c") == 0){
                //Tira o "c" do comando, deixando só o identificador
                pos = s.find(" ");
                s.erase(0, pos + 1);

                auto it = find_if(carros.begin(), carros.end(), [&s](Carro &carro) {
                    return carro.getid() == s[0];
                });
                if (it != carros.end()) {
                    // found element. it is an iterator to the first matching element.
                    // if you really need the index, you can also get it:
                    index = distance(carros.begin(), it);
                    carros.erase(carros.begin()+index);
                    //cout << index;
                }
            }
            //Apagar autodromo
            if(s.find("a") == 0){
                //Tira o "a" do comando, deixando só o identificador
                pos = s.find(" ");
                s.erase(0, pos + 1);

                auto it = find_if(autodromos.begin(), autodromos.end(), [&s](Autodromo &autodromo) {
                    return autodromo.getNome() == s; 
                });
                if (it != autodromos.end()) {
                    // found element. it is an iterator to the first matching element.
                    // if you really need the index, you can also get it:
                    index = distance(autodromos.begin(), it);
                    autodromos.erase(autodromos.begin()+index);
                    //cout << index;
                }
            }
        }
    } while (s.find("end") == string::npos);

    //iterador de campeonato
    auto iter = carros.begin();
    for ( ; iter !=  carros.end(); iter++) {
        if (isupper((*iter).getid())!=0) {
            if (!campeonato[0].pistacheia()) { // se a pista estiver cheia vai para a garagem
            campeonato[0].carregapista((*iter));
            }
        } else
        {
            campeonato[0].carregagaragem(*iter);
        }
        //carros.erase(iter);
    }
        // se sobraram carros devem ser enviados para um outro autodromo
        cout << "\n"<<"Fase de setup terminada. \n";

}
vector<Autodromo> dgv::getrace() {
    return campeonato;
}
dgv dgv::estedgv() {
    return dgv();
}
dgv::~dgv() {

}