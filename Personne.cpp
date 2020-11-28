#include <iostream>
#include "Personne.hpp"
#include <vector>

using namespace std;

Personne::Personne(const string prenom, const string nomdeFam,const unsigned int age):_prenom(prenom),
 _nomdeFamille(nomdeFam),_age(age)
{

}

Personne::~Personne()
{
    
}

//Imprimer les informations sur la personne
void Personne::afficher(){
    cout <<"Prénom : " << _prenom << endl;
    cout <<"Nom de Famille : " << _nomdeFamille << endl;
    cout <<"Age : " << _age << endl;
    cout <<"Pathogene : " << endl;
    //Si infecté ou non
    if(_pathogene == nullptr)
    {
        cout << "Pas infecté" << endl;
    }
    else
    {
        cout <<"Nom : "<< _pathogene->getName() << endl;
        cout <<"Type : "<< _pathogene->getType() << endl;
    }
    cout << endl;
    
}

//infection
void Personne::infection(Pathogene *path){
    this->setPathogene(path);
}

Pathogene* Personne::getPathogene(){
    return this->_pathogene;
}

//Setter for Pathogene + Append to vector une personne infectées
void Personne::setPathogene(Pathogene* pathogene){
    _pathogene = pathogene;
    pathogene->appendInfected(this);
} 

//infecter une personne 
void Personne::infecter(Personne *personne){
    if(_pathogene != nullptr){
    personne->setPathogene(this->getPathogene());
    }
    else{
        cout <<"Impossible : "<< _prenom << " n'est infecté par aucun virus" << endl;
    }
}

//Guérit une personne
void Personne::recuperer(){
    if (_pathogene != nullptr){
        _pathogene->deleteInfected(this);
        _pathogene = nullptr;
    }else{
        cout <<"Impossible : " << _prenom <<" n'a pas de pathogene à guérir" << endl;
    }

}

const string Personne::getName(){
    return _prenom;
}

const string Personne::getFamName(){
    return _nomdeFamille;
}

//Rajoute le groupe aux groupes auxquels appartient la personne
void Personne::setGroupe(Groupe *groupe){
    _groupes.push_back(groupe);
}

//Supprime le groupe des groupes auxquels appartient la personne
void Personne::deleteGroupe(Groupe *groupe){
    for(unsigned int i=0;i<_groupes.size(); i++){
        if(groupe == _groupes[i])
        {
            _groupes.erase(_groupes.begin()+i);
            break;
        }
    }
}

