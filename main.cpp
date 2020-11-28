/*
 * Akman Fatih - BA1-INFO  
 * main.cpp
 */

#include "Personne.hpp"
#include "Pathogene.hpp"
#include "Groupe.hpp"
#include <iostream> //std::cout, std::endl;

int main()
{

//Initialisation des personnes, groupes et pathogènes différents

//Pathogènes
Pathogene Cholera("Bactérie", "Choléra");
Pathogene Sida("Virus", "Sida");
//Groupes
Groupe Pauvre;
Groupe ClasseMoyenne;
//Personnes
Personne George("George","Abitbol",83);
Personne Eric("Eric","Dupont", 32);


//Impressions des tests de méthodes des différentes classes implémentés + cas limites
std::cout << "---------------------------------------" << std::endl;
std::cout << "Test des méthodes de la classe Personne" << std::endl;
std::cout << "---------------------------------------" << std::endl;

std::cout << std::endl;
std::cout << "Impression d'une personne <<Eric>> non infectée :"<< std::endl;
std::cout << "-------------------------------------------------" << std::endl;

 
Eric.afficher();

std::cout << "Impression de la même personne <<Eric>> inféctée par un pathogène :" << std::endl;
std::cout << "-------------------------------------------------------------------" << std::endl;
Eric.infection(&Cholera);
Eric.afficher();

std::cout << "Impression d'une personne non infectée <<George>> se faisant infecter par <<Eric>> :" << std::endl;
std::cout << "-----------------------------------------------------------------------------------" << std::endl;

std::cout << "Avant contamination :" << std::endl;
George.afficher();
std::cout << "Après contamination :" << std::endl;
Eric.infecter(&George);
George.afficher();
std::cout << "Impression d'une personne infectée avant et après guérison :" << std::endl;
std::cout << "------------------------------------------------------------" << std::endl;
George.afficher();
George.recuperer();
George.afficher();
std::cout << "Un nom-contaminé <<George>> qui essaie de guérir" << std::endl;
std::cout << "-------------------------------------------------" << std::endl;
George.recuperer();
std::cout << std::endl;
std::cout << "Un nom-contaminé <<George>> qui essaie de contaminer une autre personne :" << std::endl;
std::cout << "------------------------------------------------------------------------" << std::endl;
George.infecter(&Eric);
std::cout << std::endl << std::endl << std::endl;


std::cout << "----------------------------------------" << std::endl;
std::cout << "Test des méthodes de la classe Pathogene" << std::endl;
std::cout << "----------------------------------------" << std::endl;
std::cout << std::endl;

std::cout << "Impression de tous les membres infectés par un pathogène <<Sida>> ayant aucun infecté :" << std::endl;
std::cout << "---------------------------------------------------------------------------------------" << std::endl;

Sida.printInfected();
std::cout << "Impression de tous les membres infectés par un pathogène <<Sida>> ayant un infecté :" << std::endl;
std::cout << "------------------------------------------------------------------------------------" << std::endl;

Eric.infection(&Sida);
Sida.printInfected();
std::cout << std::endl << std::endl << std::endl;

std::cout << "-------------------------------------" << std::endl;
std::cout << "Test des méthodes de la classe Groupe" << std::endl;
std::cout << "-------------------------------------" << std::endl;
std::cout << std::endl;

std::cout << "Impression d'un groupe <<Pauvre>> sans personne :" << std::endl;
std::cout << "-------------------------------------------------" << std::endl;
Pauvre.printMember();
std::cout << "Impression d'un groupe <<Pauvre>> après l'ajoute d'une personne <<Eric>> :" << std::endl;
std::cout << "--------------------------------------------------------------------------" << std::endl;

Pauvre.addMember(&Eric);
Pauvre.printMember();

std::cout << "Impression d'un groupe <<Pauvre>> après la suppression d'une personne <<Eric>> :" << std::endl;
std::cout << "--------------------------------------------------------------------------------" << std::endl;

Pauvre.removeMember(&Eric);
Pauvre.printMember();

std::cout << "Impression d'un groupe <<Pauvre>> après la suppression d'une personne <<Eric>> qui ne s'y trouve pas :" << std::endl;
std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
Pauvre.removeMember(&Eric);

return EXIT_SUCCESS;
}