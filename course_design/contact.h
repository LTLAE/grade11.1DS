#include <iostream>
#include <fstream>
#define UntilBreak true

using namespace std;

struct person{
    person *next = NULL;
    string firstName;
    string lastName;
    string tel;
    string qq;
    string wechat;
    string email;
};

struct index{
    index *next = NULL;
    char firstLetter;   //first letter of last name
    person *firstPerson = NULL;  //point to first person starting with firstLetter
};

void Init (struct index *&Head);

void NewPerson(struct index *&Head);

bool PersonExist(struct index *Head, string firstName, string lastName, bool output);

void Edit(struct index *&Head, string firstName, string lastName);

void Delete(struct index *&Head, string firstName, string lastName);

void Output(struct index *Head);

void LoadExampleData(struct index *&Head);

// special thanks
// Demitail stabilizing condition
// Daxie White helped in Destiny 2 and stabilizing condition
// Qiluo Nin and Cengqing Tang took me hanging around
// George Sun improved me in Rainbow 6 Siege
// DJ brought me lots of fun and being a reliable siege teammate
// Du Guwei introduced me a good restaurant
// Anti Air gave me some tactical support
// Bang Bang is a reliable siege and finals teammate
// Liang Chen provided me a residence and tactical support
// Intelligent RiceCooker had lots of fun with me
// Romantic MG taught me using (char) in switch statement
// Elosia gave me tips in cpp and java courses
// Dana Iclucia aka tempest helped me to study data structure
// Ann9iVOR helped me to study data structure
// Mr Coconut introduced me lots of fun and help me pick outfits