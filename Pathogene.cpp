#include <iostream>
#include "Pathogene.hpp"

using namespace std;

Pathogene::Pathogene(const string type,const string nom):
_type(type), _nom(nom)
{
}
    
Pathogene::~Pathogene()
{
}

const string Pathogene::getName(){
    return this->_nom;
}

const string Pathogene::getType(){
    return this->_type;
}

//Rajoute au vecteur un pointeur vers une personne infectée par le pathogene
void Pathogene::appendInfected(Personne *personne){
    _infected.push_back(personne);
}

//imprime toutes les personnes infectées
void Pathogene::printInfected(){
    if(_infected.size() != 0){
        cout << "Liste de personnes infectées par le " << _nom <<":"<<endl;
    for (auto personneInfected : _infected) 
        cout << personneInfected->getName() <<" "<< personneInfected->getFamName() << endl; 
    }else{
        cout << "Personne n'est infecté par le " << _nom << endl << endl;
    }
}

//Supprime du vecteur le pointeur vers une personne guérie du pathogene 
void Pathogene::deleteInfected(Personne *personne){
	for(long unsigned int i=0;i<_infected.size(); i++){
        if(personne == _infected[i])
        { 
            _infected.erase(_infected.begin()+i);//WARNING car addition entre long unsigned int et long int
            break;
        }
    }
}