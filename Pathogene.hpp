#ifndef DEF_PATHOGENE
#define DEF_PATHOGENE

#include <string>
#include "Personne.hpp"
#include <vector>

using namespace std;

class Personne;
class Pathogene
{
private:
    const string _type;
    const string _nom;
    vector <Personne*> _infected;

public:
    Pathogene(string type, string nom);
    ~Pathogene(); 
    const string getName();
    const string getType();
    void appendInfected(Personne *personne);
    void printInfected();
    void deleteInfected(Personne *personne);
};
#endif


