#include<iostream>
#include <ctime>
using namespace std;

typedef struct Element Element;
struct Element {
    int val;
    Element* suivant;
};

Element* liste = NULL;

void Ajouter(int occur)
{
    int i = 0;
    srand(time(nullptr));
    while (i<occur){
        int nombre = rand()% 10000;
        Element* element= new Element;
        element->val = nombre;
        element->suivant = liste;
        liste = element;
        i++;
    }
}

void Permut (Element* VAR1, Element* VAR2)
{
    int tampon;
    tampon=VAR1->val;
    VAR1->val=VAR2->val;
    VAR2->val=tampon;
}

void Tri_Bulles()
{
    Element* element = liste;
    bool isPermut = true;
    while (isPermut){
        element = liste;
        isPermut=false;
       
        while(element->suivant!=NULL){
        if (element->suivant->val>element->val) {
            int tampon;
            tampon=element->val;
            element->val= element->suivant->val;
            element->suivant->val=tampon;
            isPermut = true;
        }
        element = element->suivant;

    }
    }
    
}

void Afficher()
{

    Element* element = liste;
    while(element != NULL)
    {

        cout << element->val << "\t";
        element = element->suivant;

    }
    cout << endl;

}

int main()
{   
    int nombre_entiers;
    cout << "Combien d'entiers souhaitez-vous trier ?";
    cin >> nombre_entiers;
    Ajouter(nombre_entiers);
    Afficher();
    Tri_Bulles();
    Afficher();
    return 0;
}