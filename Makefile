FLAGS =-std=c++17  -fconcepts -mlong-double-128 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wsign-conversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override -lquadmath

CC = g++
executable = main

all : $(executable)

$(executable): main.cpp Personne.o Pathogene.o Groupe.o
	$(CC) $(FLAGS) main.cpp Personne.o Pathogene.o Groupe.o -o $(executable)

Personne.o: Personne.cpp
	$(CC) $(FLAGS) -c Personne.cpp -o Personne.o

Pathogene.o: Pathogene.cpp
	$(CC) $(FLAGS) -c Pathogene.cpp -o Pathogene.o

Groupe.o: Groupe.cpp
	$(CC) $(FLAGS) -c Groupe.cpp -o Groupe.o

.PHONY : clean

clean: 
	rm $(executable) *.o
	



