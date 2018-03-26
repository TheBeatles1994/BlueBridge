#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cstring>

using namespace std;

bool Find(int target, vector<vector<int> > array) {
    int rows=array.size()-1;
    int cols=0;

    while(rows>=0 && cols<array[0].size())
    {
        if(target>array[rows][cols])
        {
            cols++;
        }
        else if(target<array[rows][cols])
        {
            rows--;
        }
        else
            return true;

    }
    return false;
}

int main(int argc, char *argv[])
{
    int rows,cols;
    int target;
    vector<vector<int> >vvdata;
    vector<int> vdata;
    char line[256];

    ifstream ifile("data.txt");
    if(ifile.good())
    {
        ifile.getline(line,256);
        istringstream iss(line);
        iss >> rows >> cols;
    }
    else
    {
        return 1;
    }

    for(int i=0;i<rows;i++)
    {
        ifile.getline(line,256);
        istringstream iss(line);
        for(int j=0;j<cols;j++)
        {
            iss >> target;
            vdata.push_back(target);
        }
        vvdata.push_back(vdata);
        vector<int>().swap(vdata);
    }

    ifile.getline(line,256);
    istringstream iss(line);
    iss >>target;

    if(Find(target,vvdata))
        cout << "1"<<endl;
    else
        cout << "0"<<endl;

    return 0;
}
