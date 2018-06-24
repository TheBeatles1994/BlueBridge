#include <string>
#include <iostream>
using namespace std;

class ChineseName
{
public:
    virtual string getname()
    {
        return string("Chinese");
    }
};

class EnglishName
{
public:
    virtual string getname()
    {
        return string("English");
    }
};

class ICName : public ChineseName
{
public:
    virtual string getname()
    {
        return getChineseName();
    }

private:
    virtual string getChineseName() = 0;
};

class IEName : public EnglishName
{
public:
    virtual string getname()
    {
        return getEnglishName();
    }

private:
    virtual string getEnglishName() = 0;
};

class Name : public ICName, public IEName
{
private:
    virtual string getChineseName()
    {
        return string("Chinese");
    }

    virtual string getEnglishName()
    {
        return string("English");
    }
};

int main()
{
    Name n;
    ChineseName & c = n;
    EnglishName & e = n;

    //cout << n.getname() << endl;  //会产生二义
    cout << c.getname() << endl;
    cout << e.getname() << endl;

    return 0;
}
