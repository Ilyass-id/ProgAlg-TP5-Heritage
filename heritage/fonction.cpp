#include "fonction.h"



/////////////////////////////////////
//FONCTION
/////////////////////////////////////
//Destructeur
Fonction::~Fonction(){
    cout<<"~Fonction"<<endl;
}

//Inverse
float Fonction::inverse(float y) const{ //xi+1 --> xb and xi --> xa
    float xb ;
    float xa =1;
    float eps = 1;
    int i=0;
    Fonction* A = (this)->derivee();
    while(eps>0.00001 && i<100){
        xb = xa + (y - (*this)(xa))/(A->operator()(xa));
        eps = abs(xb-xa);
        xa=xb;
        i++;
    }
    return xb;
}

/////////////////////////////////////
//POLYNOME (FONCTION-> POLYNOME )
/////////////////////////////////////
//Destructeur
Polynome::~Polynome(){
    cout<<"~Polynome"<<endl;
}

//Constructeur
Polynome::Polynome(const vector<float>& V){
    vector<float>::const_iterator it=V.begin();
    for (; it!=V.end(); ++it)
        coefficients.push_back(*it);
}


//Operateur ()
float Polynome::operator()(const float x) const{
    float res=0;
    int i=0;
    vector<float>::const_iterator it=coefficients.begin();
    for (; it!=coefficients.end(); ++it){
        res+= (*it) * pow(x, i);
        i++;
    }
    return res;
};
//Derivee
Fonction* Polynome::derivee() const{
    vector<float> coefficientsDerivee;                                 // coefficients du polynome derivee
    vector<float> coefficientsCopie = coefficients;                    //copie des coefficients du polynome
    int i=0;
    coefficientsCopie.erase(coefficientsCopie.begin());
    vector<float>::const_iterator it=coefficientsCopie.begin();
    for (; it!=coefficientsCopie.end(); ++it){
        coefficientsDerivee.push_back((*it) * (i+1));
        i++;
    }
    return new Polynome(coefficientsDerivee);
}

//Clone

Fonction* Polynome::clone()const {
    return new Polynome(*this);
}

/////////////////////////////////////
//AFFINE (Heritage : FONCTION-> POLYNOME -> AFFINE)
/////////////////////////////////////

//Destructeur
Affine::~Affine(){
    cout<<"~Affine"<<endl;
}

//Constructeur
Affine::Affine(float a1, float b1): Polynome(){ a=a1; b=b1;};


//operateur ()
float Affine::operator()(const float x) const{ return(a*x+b); };

//derivee
Fonction* Affine::derivee() const{
    return new Affine(0,a);
}

//clone
Fonction* Affine::clone()const {
    return new Affine(*this);
}
/////////////////////////////////////
//TRIGO (FONCTION-> TRIGO )
/////////////////////////////////////
//Destructeur

Trigo::~Trigo() {
    cout<<"~Trigo"<<endl;
}

//Constructeur

Trigo::Trigo(string a){
    trig=a;
};

//Operateur()

float Trigo::operator()(const float x) const{
    map<string, FnPtr> MyMap;
    MyMap["sin"] = sin;
    MyMap["cos"] = cos;
    MyMap["tan"] = tan;
    float res;
    res = MyMap.at(trig)(x);
    MyMap.clear();
    return(res);
};


//Clone

Fonction* Trigo::clone()const {
    return new Trigo(*this);
}

//Derivee

Fonction* Trigo::derivee() const{
    return new Derivee(this);
};

/////////////////////////////////////
//DERIVEE (FONCTION-> DERIVEE )
/////////////////////////////////////
//Destructeur

Derivee::~Derivee() {
    cout<<"~Derivee"<<endl;
}

//Constructeur

Derivee::Derivee(const Fonction* f){
    integrale=f->clone();
};

//operateur()
float Derivee::operator()(const float x) const{
    const float eps = 0.01;
    float yprime= ((*integrale)(x+eps)-(*integrale)(x-eps))/(2*eps);
    return yprime;
}

//clone

Fonction* Derivee::clone()const {
    return new Derivee(*this);
}

//Derivee

Fonction* Derivee::derivee() const{
    return new Derivee(this);
};
