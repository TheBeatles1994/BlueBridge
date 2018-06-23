#ifndef CTOBSERVER_H
#define CTOBSERVER_H

#include <list>

class CTSubject;

class CTObserver
{
public:
    virtual ~CTObserver(){}
    virtual void update() = 0;
    CTSubject *getSubject(){return subject;}
protected:
    CTObserver(CTSubject *subject);
private:
    CTSubject *subject;
};

class CTSubject
{
public:
    virtual ~CTSubject(){}
    virtual void notify();
    virtual void attach(CTObserver *observer);
    virtual void detach(CTObserver *observer);
protected:
    CTSubject(){}
private:
    std::list<CTObserver *> observers;
};

#endif // CTOBSERVER_H
