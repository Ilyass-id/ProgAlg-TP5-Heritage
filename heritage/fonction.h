#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <map>
using namespace std;

typedef float (*FnPtr)(float);


class Fonction {
public:
    virtual ~Fonction();                                //done
    virtual Fonction* derivee() const = 0;              //done
    virtual float operator()(float x) const = 0;        //done
    float inverse(float y) const ;                      //done
    virtual Fonction* clone() const = 0;                //done
};

class Polynome : public Fonction
{
private:
    vector<float> coefficients;
public:
    virtual ~Polynome();                                //done
    Polynome(const vector<float>& V);                   //done
    virtual float operator()(float x) const;            //done
    Polynome(){};                                       //done
    virtual Fonction* derivee() const;                  //done
    virtual Fonction* clone() const;                    //done
};


class Affine : public Polynome
{
private:
    float a;
    float b;
public:
    virtual ~Affine();                                  //done
    Affine(const float a1,const float b1);              //done
    virtual float operator()(const float x) const;      //done
    virtual Fonction* derivee() const;                  //done
    virtual Fonction* clone() const;                    //done
};

class Trigo: public Fonction
{
private:
    string trig;
public:
    virtual ~Trigo();                                   //done
    Trigo(string a);                                    //done
    virtual float operator()(float x) const;            //done
    virtual Fonction* clone() const;                    //done
    virtual Fonction* derivee() const;                  //done
};

class Derivee: public Fonction
{
private:
    Fonction* integrale;
public:
    virtual ~Derivee();                                     //done
    Derivee(const Fonction* f);                             //done
    virtual float operator()(const float x) const;          //done
    virtual Fonction* clone() const;                        //done
    virtual Fonction* derivee() const;                      //done
};
