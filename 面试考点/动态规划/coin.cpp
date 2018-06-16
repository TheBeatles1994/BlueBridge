#include <iostream>

using namespace std;

#define MIN(x, y) x<y?x:y
#define MAXNUM 65535
#define COINNUM 3

typedef struct
{
	int nCoin;			//需要的硬币数
	int lastCoin;		//最后一个硬币面值
}State;
//硬币种类
int coin[COINNUM]={1, 3, 5};

int main()
{
	int sum;
	State *myState;

	cin >> sum;

	myState = (State *)malloc(sizeof(State)*(sum+1));

	for (int i=1;i<=sum;i++)
	{
		myState[i].nCoin = MAXNUM;
	}
	myState[0].nCoin = 0;

	for (int i=1;i<=sum;i++)
	{
		for (int j=0;j<COINNUM;j++)
		{
			if((i-coin[j]>=0) && (myState[i-coin[j]].nCoin+1 < myState[i].nCoin))
			{
				myState[i].nCoin = myState[i-coin[j]].nCoin+1;
				myState[i].lastCoin = coin[j];
			}
		}
	}

	cout << myState[sum].nCoin <<endl;
	do 
	{
		cout << myState[sum].lastCoin;
		sum -= myState[sum].lastCoin;
		if (sum == 0)
		{
			cout << endl;
		}
		else
		{
			cout << " ";
		}
	} while (sum != 0);
	free(myState);

	system("pause");
	return 0;
}