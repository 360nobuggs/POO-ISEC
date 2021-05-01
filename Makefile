all: run

run: main.cpp autodromo.cpp carro.cpp consola.cpp crazy_driver.cpp dgv.cpp gestor.cpp papa_reformas.cpp piloto_rapido.cpp piloto.cpp
	x86_64-w64-mingw32-g++ main.cpp -static -static-libgcc -static-libstdc++ -o main.exe -lws2_32 -gstabs
