#include "ctobserver.h"

CTObserver::CTObserver(CTSubject *subject)
{
    this->subject = subject;
    subject->attach(this);
}


void CTSubject::notify()
{
    for(auto i:observers)
        i->update();
}

void CTSubject::attach(CTObserver *observer)
{
    observers.push_back(observer);
}

void CTSubject::detach(CTObserver *observer)
{
    observers.remove(observer);
}
