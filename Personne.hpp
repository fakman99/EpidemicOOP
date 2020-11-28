#ifndef DEF_PERSONNE
#define DEF_PERSONNE

#include <string>
#include "Pathogene.hpp"
#include "Groupe.hpp"

using namespace std;

class Pathogene;
class Groupe;

class Personne
{
   
private:
    Personne(const Personne&);
    Personne operator=(const Personne&);
    const string _prenom;
    const string _nomdeFamille;
    const unsigned int _age;  // L'age ne sera jamais négatif, donc unsigned
    Pathogene *_pathogene = nullptr; 
    vector <Groupe*> _groupes = {};
public:
    Personne(const string prenom, const string nomdeFamille, const unsigned int age);
    ~Personne(); 
    
    void afficher();
    void infection(Pathogene *pathogene);
    Pathogene* getPathogene(); 
    void setPathogene(Pathogene *_pathogene);
    void infecter(Personne *personne);
    void recuperer();
    const string getName();
    const string getFamName();
    void setGroupe(Groupe *groupe);
    void deleteGroupe(Groupe *groupe);
    
};
#endif