#include <iostream>
#include <vector>
using namespace std;


// 烤肉师傅
class RoastCook
{
public:
    void MakeMutton() { cout << "MakeMutton" << endl; }
    void MakeChickenWing() { cout << "MakeChickenWing" << endl; }
};


// 抽象命令类
class Command
{
public:
    Command(RoastCook* temp) { receiver = temp; }
    virtual void ExecuteCmd() = 0;

protected:
    RoastCook* receiver;
};

// 烤羊肉命令
class MakeMuttonCmd : public Command
{
public:
    MakeMuttonCmd(RoastCook* temp) : Command(temp) {}
    virtual void ExecuteCmd() { receiver->MakeMutton(); }
};

// 烤鸡翅膀命令

class MakeChickenWingCmd : public Command
{
public:
    MakeChickenWingCmd(RoastCook* temp) : Command(temp) {}
    virtual void ExecuteCmd() { receiver->MakeChickenWing(); }
};

// 服务员类
class Waiter
{
public:
    void SetCmd(Command* temp);

    // 通知执行
    void Notify();
protected:
    vector<Command*> m_commandList;
};

void Waiter::SetCmd(Command* temp)
{
    m_commandList.push_back(temp);
    cout << "Add Command" << endl;
}

void Waiter::Notify()
{
    vector<Command*>::iterator it;
    for (it=m_commandList.begin(); it!=m_commandList.end(); ++it)
    {
        (*it)->ExecuteCmd();
    }
}

int main()
{
    // 店里添加烤肉师傅、菜单、服务员等顾客
    RoastCook* cook = new RoastCook();
    Command* cmd1 = new MakeMuttonCmd(cook);
    Command* cmd2 = new MakeChickenWingCmd(cook);
    Waiter* girl = new Waiter();

    // 点菜
    girl->SetCmd(cmd1);
    girl->SetCmd(cmd2);

    // 服务员通知
    girl->Notify();
    return 0;
}
