#include "ctobserver.h"
/*
 * @函数功能:观察者构造函数
 * @输入参数:无
 * @输出参数:无
 * @注意事项:
 *      1. 设置subject对象
 *      2. 绑定链接
 */
void CTObserver::setSubject(CTSubject *subject)
{
    /* 若subject变量为空则进行操作 */
    if(!this->subject)
    {
        this->subject = subject;
        subject->attach(this);
    }
}

CTObserver::CTObserver(CTSubject *subject)
{
    /* 非空则赋值 */
    if(subject)
        setSubject(subject);
}
/*
 * @函数功能:通知
 * @输入参数:无
 * @输出参数:无
 * @注意事项:
 *      1. 在Subject的子类中一定要记得调用此函数
 */
void CTSubject::notify()
{
    for(auto i:observers)
        i->update(this);
}
/*
 * @函数功能:绑定
 * @输入参数:无
 * @输出参数:无
 * @注意事项:无
 */
void CTSubject::attach(CTObserver *observer)
{
    observers.push_back(observer);
}
/*
 * @函数功能:解绑
 * @输入参数:无
 * @输出参数:无
 * @注意事项:无
 */
void CTSubject::detach(CTObserver *observer)
{
    observers.remove(observer);
}
