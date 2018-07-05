#ifndef _SIMPLEFACTORY_H_
#define _SIMPLEFACTROY_H_

#include <stdio.h>
#include "AbstractProductA.h"
#include "AbstractProductB.h"


class AbstractFactory{

public:
    AbstractFactory();
    virtual ~AbstractFactory();
    
public:
    virtual AbstractProductA* createProductA() = 0;    
    virtual AbstractProductB* createProductB() = 0;    
};


class Factory1:public AbstractFactory{

public:
    Factory1();
    ~Factory1();
    
public:
    AbstractProductA* createProductA();
    AbstractProductB* createProductB();
};


class Factory2:public AbstractFactory{

public:
    Factory2();
    ~Factory2();
    
public:
    AbstractProductA* createProductA();
    AbstractProductB* createProductB();
};
#endif
