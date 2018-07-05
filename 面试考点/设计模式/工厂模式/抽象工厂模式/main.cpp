#include "AbstractFactory.h"

int main(){

    AbstractFactory* factory = new Factory1();
    AbstractProductA* productA = factory->createProductA();
    AbstractProductB* productB = factory->createProductB();
    productA->operationA();
    productB->operationB();
    
    delete factory;
    factory = NULL;
    delete productA;
    productA = NULL;
    delete productB;
    productB = NULL;
    
    factory = new Factory2();
    productA = factory->createProductA();
    productB = factory->createProductB();
    productA->operationA();
    productB->operationB();
    
    delete factory;
    factory = NULL;
    delete productA;
    productA = NULL;
    delete productB;
    productB = NULL;
    return 0;
}

client.cpp