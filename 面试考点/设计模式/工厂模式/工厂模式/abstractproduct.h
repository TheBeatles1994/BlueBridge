#ifndef _ABSTRACTPRODUCT_H_
#define _ABSTRACTPRODUCT_H_


#include <stdio.h>


class AbstractProduct{

public:
    AbstractProduct();
    virtual ~AbstractProduct();
    
public:
    virtual void operation() = 0;
};

class ProductA:public AbstractProduct{

public:
    ProductA();
    virtual ~ProductA();
    
public:
    void operation();
};

class ProductB:public AbstractProduct{

public:
    ProductB();
    ~ProductB();
    
public:
    void operation();
};

#endif
