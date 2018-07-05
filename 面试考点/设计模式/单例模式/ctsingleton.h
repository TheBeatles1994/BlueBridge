#ifndef CTSINGLETON
#define CTSINGLETON

/*
 * 注意事项：
 * 1. 构造函数必须要声明成私有函数，否则依然会被用户实例化
 * 2. 单例对象要能够释放
 * 3. 要注意线程安全
 */
#include <mutex>
#include <iostream>

class CTSingleton
{
public:
    static CTSingleton &getInstance();
private:
    CTSingleton(){std::cout<<"CTSingleton constructor"<<std::endl;}
public:
    virtual ~CTSingleton(){std::cout<<"CTSingleton destructor"<<std::endl;}
    CTSingleton(const CTSingleton &) = delete;
    CTSingleton &operator=(const CTSingleton &) = delete;
    void doSth(int num){std::cout<<"do sth: "<<num<<std::endl;}
};



#endif // CTSINGLETON
