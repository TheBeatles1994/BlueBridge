#ifndef CTOBSERVER_H
#define CTOBSERVER_H

#include <list>

class CTSubject;
/* 观察者基类 */
class CTObserver
{
public:
    virtual ~CTObserver(){}
    virtual void update(CTSubject *) = 0;   //子类只需要重写此虚函数即可
    CTSubject *getSubject(){return subject;}
    void setSubject(CTSubject *subject);    //对于在构造函数中没有设置subject的子类，初始化后必须调用此函数
protected:
    CTObserver(CTSubject *subject = nullptr);
private:
    CTSubject *subject = nullptr;
};
/* 对象基类 */
class CTSubject
{
public:
    virtual ~CTSubject(){}
    virtual void notify();      //一定要记得调用此函数
    virtual void attach(CTObserver *observer);
    virtual void detach(CTObserver *observer);
protected:
    CTSubject(){}
private:
    std::list<CTObserver *> observers;
};

#endif // CTOBSERVER_H
