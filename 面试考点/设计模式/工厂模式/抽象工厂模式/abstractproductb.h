#ifndef _ABSTRACTPRODUCTB_H_
#define _ABSTRACTPRODUCTB_H_


#include <stdio.h>


class AbstractProductB{

public:
    AbstractProductB();
    virtual ~AbstractProductB();
    
public:
    virtual void operationB() = 0;
};

class ProductB_1:public AbstractProductB{

public:
    ProductB_1();
    virtual ~ProductB_1();
    
public:
    void operationB();
};

class ProductB_2:public AbstractProductB{

public:
    ProductB_2();
    ~ProductB_2();
    
public:
    void operationB();
};

#endif
