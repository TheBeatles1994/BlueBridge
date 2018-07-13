# RAII

>> RAII：Resource Acquisition Is Initialization（资源获取就是初始化）

- RAII的本质内容是**用对象代表资源**，把管理资源的任务转化为管理**对象**的任务，**将资源的获取和释放与对象的构造和析构对应起来**，从而确保在对象的生存期内资源始终有效，对象销毁时资源必被释放。
## 举例
### 文件操作
```
//问题场景
void Func()  
{  
  FILE *fp;  
  char* filename = "test.txt";  
  if((fp=fopen(filename,"r"))==NULL)  
  {  
      printf("not open");  
      exit(0);  
  }  
  ... // 如果 在使用fp指针时产生异常 并退出  
       // 那么 fp文件就没有正常关闭  
 
  fclose(fp);  
}  
//解决思路
    class FileRAII{  
    public:  
        FileRAII(FILE* aFile):file_(aFile){}  
        ~FileRAII() { fclose(file_); }//在析构函数中进行文件关闭  
        FILE* get() {return file_;}  
    private:  
        FILE* file_;  
    };  
void Func()  
{  
    FILE *fp;  
    char* filename = "test.txt";  
    if((fp=fopen(filename,"r"))==NULL)  
    {  
        printf("not open");  
        exit(0);  
    }  
    FileRAII fileRAII(fp);  
    ... // 如果 在使用fp指针时产生异常 并退出  
        // 那么 fileRAII在栈展开过程中会被自动释放，析构函数也就会自动地将fp关闭  
    
    // 即使所有代码是都正确执行了，也无需手动释放fp，fileRAII它的生命期在此结束时，**它的析构函数会自动执行！**
}  
```