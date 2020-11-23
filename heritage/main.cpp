#include "fonction.h"

using namespace std;

int main()
{
    ///////////////////////
    // TESTS operateur ()
    ///////////////////////
    //Affine
    Affine f1(1,1);
    //cout<<f1(2)<<endl;

    //Polynome
    vector<float> V{0,0,0,1};
    Polynome f2(V);
    //cout<<f2(3)<<endl;

    //Trigonometriques
    Trigo f3("cos");
    //cout<<f3(M_PI/2)<<endl;                   //cos(0) = 1 et cos (pi/2) = 0


    ///////////////////////
    // TESTS Derivee
    ///////////////////////

    //Test derivee de la fonction affine f1(x) = x + 1
    Fonction* f4;
    f4 = f1.derivee();
    //cout<<(*f2)(1)<<endl;                     //f'(x)=1 pour tout x

    ///////////////////////
    // TESTS Inverse
    ///////////////////////
    //Polynomiale
    float y = 27;
    float lambda = f2.inverse(y);
    //cout<<lambda<<endl;                       //Retourne bien 3

    ///////////////////////
    // TESTS Derivee trigonometrique
    ///////////////////////
    Fonction* f5 = f3.derivee();
    cout<<(*f5)(M_PI/2)<<endl;                  // Affiche bien -1 car : cos'(x) = -sin(x)

    Trigo f6("tan");
    cout<<(*f6.derivee()->derivee())(M_PI/4)<<endl;  //La dérivée seconde fonctionne elle aussi très bien.
    return 0;
}
