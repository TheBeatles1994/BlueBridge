#ifndef _SIMPLEFACTORY_H_
#define _SIMPLEFACTROY_H_

#include <stdio.h>
#include "AbstractProduct.h"


class AbstractFactory{

public:
    AbstractFactory();
    virtual ~AbstractFactory();
    
public:
    virtual AbstractProduct* createProduct(int type) = 0;    
};


class SimpleFactory:public AbstractFactory{

public:
    SimpleFactory();
    ~SimpleFactory();
    
public:
    AbstractProduct* createProduct(int type);
};

#endif