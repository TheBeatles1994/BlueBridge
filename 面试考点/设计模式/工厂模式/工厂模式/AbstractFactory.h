#ifndef _SIMPLEFACTORY_H_
#define _SIMPLEFACTROY_H_

#include <stdio.h>
#include "AbstractProduct.h"


class AbstractFactory{

public:
    AbstractFactory();
    virtual ~AbstractFactory();
    
public:
    virtual AbstractProduct* createProduct() = 0;    
};


class FactoryA:public AbstractFactory{

public:
    FactoryA();
    ~FactoryA();
    
public:
    AbstractProduct* createProduct();
};


class FactoryB:public AbstractFactory{

public:
    FactoryB();
    ~FactoryB();
    
public:
    AbstractProduct* createProduct();
};
#endif
