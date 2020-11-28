#ifndef DEF_GROUPE
#define DEF_GROUPE

#include <vector>
#include <string>
#include "Personne.hpp"
#include "Groupe.hpp"

using namespace std;

class Personne;

class Groupe
{
private:
    vector <Personne*> _groupe;

public:
    Groupe();
    ~Groupe();
    void addMember(Personne *personne);
    void removeMember(Personne *personne);
    void printMember();
    

};
#endif