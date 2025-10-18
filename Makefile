PROG = bin/concessionaria
CC = g++
CPPFLAGS = -O -g -Wall -ansi -pedantic -Iinclude -std=c++11
OBJS = main.o Sistema.o Concessionaria.o Automovel.o Moto.o Caminhao.o Veiculo.o listarFrotaConcessionaria.o saveConcessionaria.o
VALGRIND = valgrind

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o: src/main.cpp 
	$(CC) $(CPPFLAGS) -c src/main.cpp

Sistema.o: src/Sistema.cpp include/Sistema.h
	$(CC) $(CPPFLAGS) -c src/Sistema.cpp

Concessionaria.o: src/Concessionaria.cpp include/Concessionaria.h
	$(CC) $(CPPFLAGS) -c src/Concessionaria.cpp
Automovel.o: src/Automovel.cpp include/Automovel.h
	$(CC) $(CPPFLAGS) -c src/Automovel.cpp
Moto.o: src/Moto.cpp include/Moto.h
	$(CC) $(CPPFLAGS) -c src/Moto.cpp
Caminhao.o: src/Caminhao.cpp include/Caminhao.h
	$(CC) $(CPPFLAGS) -c src/Caminhao.cpp
Veiculo.o: src/Veiculo.cpp include/Veiculo.h
	$(CC) $(CPPFLAGS) -c src/Veiculo.cpp
listarFrotaConcessionaria.o: src/listarFrotaConcessionaria.cpp include/listarFrotaConcessionaria.h
	$(CC) $(CPPFLAGS) -c src/listarFrotaConcessionaria.cpp
saveConcessionaria.o: src/saveConcessionaria.cpp include/saveConcessionaria.h
	$(CC) $(CPPFLAGS) -c src/saveConcessionaria.cpp
clean:
	rm -f core $(PROG) $(OBJS)
test: $(OBJS)
	$(VALGRIND) --leak-check=yes ./$(PROG)
	./$(PROG) < teste.txt
