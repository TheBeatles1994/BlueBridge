#include <iostream>
#include "ctsingleton.h"

CTSingleton &CTSingleton::getInstance()
{
    //此处是线程安全的
    //C++11文档：
    /*If control enters the declaration concurrently
      while the variable is being initialized, the concurrent
      execution shall wait for completion of the initialization.*/
	 static CTSingleton instance;

    return instance;
}
