#include <iostream>
#include "Groupe.hpp"

using namespace std;

Groupe::Groupe()
{
}
    
Groupe::~Groupe()
{
}

//Ajoute une personne à un groupe
void Groupe::addMember(Personne *personne){
    _groupe.push_back(personne);
    personne->setGroupe(this);

    
}

//Supprime une personne du groupe
void Groupe::removeMember(Personne *personne){
    bool find = false;
    for(int i=0;i<_groupe.size(); i++){
        if(personne == _groupe[i])
        {
            find = true;
            _groupe.erase(_groupe.begin()+i);
            personne->deleteGroupe(this);
            break;
        }
    }
    if (find == false){
            cout <<"Impossible : "<<personne->getName() << " n'est pas dans ce groupe" << endl;
    }
}


//Imprime toutes les personnes du groupe
void Groupe::printMember(){
    if(_groupe.size() != 0){
        cout << "Liste des membres du groupe: "<< endl;
        for (auto personne : _groupe) 
            cout << personne->getName() <<" "<< personne->getFamName() << endl << endl;
    }else{
        cout << "Personne n'est dans ce groupe social" << endl << endl;
    }
}