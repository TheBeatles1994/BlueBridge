#include "AbstractFactory.h"


AbstractFactory::AbstractFactory(){
}


AbstractFactory::~AbstractFactory(){
}


Factory1::Factory1(){
}


Factory1::~Factory1(){
}


AbstractProductA* Factory1::createProductA(){
    AbstractProductA* temp = NULL;
    temp = new ProductA_1();
    return temp;
}


AbstractProductB* Factory1::createProductB(){
    AbstractProductB* temp = NULL;
    temp = new ProductB_1();
    return temp;
}


Factory2::Factory2(){
}


Factory2::~Factory2(){
}


AbstractProductA* Factory2::createProductA(){
    AbstractProductA* temp = NULL;
    temp = new ProductA_2();
    return temp;
}


AbstractProductB* Factory2::createProductB(){
    AbstractProductB* temp = NULL;
    temp = new ProductB_2();
    return temp;
}
