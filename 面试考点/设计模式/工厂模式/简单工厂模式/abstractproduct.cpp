#include "AbstractProduct.h"

AbstractProduct::AbstractProduct(){
}


AbstractProduct::~AbstractProduct(){
}


ProductA::ProductA(){
}


ProductA::~ProductA(){
}


void ProductA::operation(){
    fprintf(stderr,"productA operation!\n");
}


ProductB::ProductB(){
}


ProductB::~ProductB(){
}


void ProductB::operation(){
    fprintf(stderr,"productB operation!\n");
}