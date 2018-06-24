# 两个基类有同名的虚函数
1. A、B两类各有一个虚函数且同名，C继承A、B，则此时C若override此函数，将同时覆盖A和B的虚函数。
2. 最好的方式是能有个中间层：[代码](main.cpp)，zC类继承中间层的类，然后重写两个虚函数即可。
3. 项目中的CTPaintLabel继承了CTObserver，但QLabel和CTObserver同时有update函数，不过此处QLabel的update函数时槽函数，而CTObserver的update是虚函数，当重写update虚函数后发现QLabel的槽函数用起来很麻烦。为了解决此问题，发现有Observer连接多个subject的设定，故将update虚函数设置成了有参数的。