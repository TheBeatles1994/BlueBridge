#include <iostream>
#include <vector>

using namespace std;

// 烤肉师傅
class RoastCook
{
public:
    void Make1() { cout << "Make1" << endl; }
    void Make2() { cout << "Make2" << endl; }
    void Make3() { cout << "Make3" << endl; }
    void Make4() { cout << "Make4" << endl; }
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

// 命令1
class Make1Cmd : public Command
{
public:
    Make1Cmd(RoastCook* temp) : Command(temp) {}
    virtual void ExecuteCmd() { receiver->Make1(); }
};

// 命令2
class Make2Cmd : public Command
{
public:
    Make2Cmd(RoastCook* temp) : Command(temp) {}
    virtual void ExecuteCmd() { receiver->Make2(); }
};

// 命令3
class Make3Cmd : public Command
{
public:
    Make3Cmd(RoastCook* temp) : Command(temp) {}
    virtual void ExecuteCmd() { receiver->Make3(); }
};

// 命令2
class Make4Cmd : public Command
{
public:
    Make4Cmd(RoastCook* temp) : Command(temp) {}
    virtual void ExecuteCmd() { receiver->Make4(); }
};

// 服务员类
class Waiter
{
public:
    void setCmd(Command* temp);
    // 通知执行
    void notify();
    void redo();
    void undo();
    ~Waiter();
protected:
    vector<Command*> commandList;
    vector<Command*> redoCommandList;
};

void Waiter::setCmd(Command* temp)
{
    commandList.push_back(temp);
    if(!redoCommandList.empty())
    {
        for(int i=0;i<redoCommandList.size();i++)
            delete redoCommandList[i];
        redoCommandList.clear();
    }
}

void Waiter::notify()
{
    vector<Command*>::iterator it;
    for (it=commandList.begin(); it!=commandList.end(); ++it)
    {
        (*it)->ExecuteCmd();
    }
}

void Waiter::redo()
{
    if(redoCommandList.empty())
        return;
    else
    {
        commandList.push_back(redoCommandList[redoCommandList.size()-1]);
        redoCommandList.pop_back();
    }
}

void Waiter::undo()
{
    if(commandList.empty())
        return;
    else
    {
        redoCommandList.push_back(commandList[commandList.size()-1]);
        commandList.pop_back();
    }
}

Waiter::~Waiter()
{
    if(!commandList.empty())
    {
        for(int i=0;i<commandList.size();i++)
            delete commandList[i];
        commandList.clear();
    }
    if(!redoCommandList.empty())
    {
        for(int i=0;i<redoCommandList.size();i++)
            delete redoCommandList[i];
        redoCommandList.clear();
    }
}

int main()
{
    // 店里添加烤肉师傅、菜单、服务员等顾客
    RoastCook* cook = new RoastCook();
    Command* cmd1 = new Make1Cmd(cook);
    Command* cmd2 = new Make2Cmd(cook);
    Command* cmd3 = new Make3Cmd(cook);
    Command* cmd4 = new Make4Cmd(cook);
    Waiter* girl = new Waiter();
    // 点菜
    girl->setCmd(cmd1);
    girl->setCmd(cmd2);
    girl->setCmd(cmd3);
    girl->setCmd(cmd4);
    girl->undo();
    girl->undo();
    girl->undo();
    girl->undo();
    girl->redo();
    girl->redo();
    girl->undo();
    // 服务员通知
    girl->notify();
    return 0;
}
