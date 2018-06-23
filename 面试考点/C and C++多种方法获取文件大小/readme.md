# C/C++多种方法获取文件大小

## 方法一：调用系统函数
```
FILE* file = fopen(filepath, "rb");
if (file)
{
    int size = filelength(fileno(file));
    cout<<size<<endl;
    fclose(file);
}
```
### FILE * fopen ( const char * filename, const char * mode );
1. filename指文件名，mode指未来能对文件执行操作的权限。
2. 返回值是一个指向该文件的指针，否则返回NULL表明打开失败
3. 返回的指针可能会失效，当调用fclose或freopen
4. mode参数：r表示读；w表示写，若存在同名文件则原文件内容丢弃，写上新的内容；a表示附加（append），若文件不存在则创建文件，若文件存在则在文件内容后面添加内容；r+表示可读可写，前提是文件必须存在；w+表示可读可写，文件不存在的话创建文件，存在的话先把内容清空；a+可读可写，写的话写在文件已有内容的后面；加上b表示以二进制文件打开的方式打开此文件，默认是以文本文件打开（此处自己没有深究）
5. 
### int fclose ( FILE * stream );
1. 关闭文件
2. 如果关闭成功返回0， 否则返回EOF（End-of-File）
### int fileno(FILE *stream);
1. 获取与流关联的文件描述符。
2. 返回-1是失败
### long filelength(int fd); 
1. 得到文件的大小，fd位文件描述符

## 方法二：移动指针来获得文件长度
```
fseek(fp, 0L, SEEK_END);
sz = ftell(fp);
//You can then seek back, e.g.:
fseek(fp, 0L, SEEK_SET);
//or (if seeking to go to the beginning)
rewind(fp);
```
### int fseek ( FILE * stream, long int offset, int origin );
1. 重新定位流指针
2. 第三个参数origin，需要特别留意一下：SEEK_SET表示文件起始位置，SEEK_CUR表示文件指针当前位置，SEEK_END表示文件结尾。
3. 调用成功返回0，否则返回非零值
### long int ftell ( FILE * stream );
1. 获得当前文件流指针的位置
2. 对于二进制方式打开的文件，这个返回的是从文件开始到当前位置的字节数；对于文本文件，则数字可能没有什么实际意义
### void rewind ( FILE * stream );
1. 将文件指针移动到文件起始位置

## 文本流和二进制流的区别
```
char *file_name;
/* Initialize file_name */
FILE *file = fopen(file_name, "w"); //文本流
/* Check for errors */
fputs("\n", file);
```
1. 输入的字符可能会发生变化，这个变化随环境（操作系统）变化而变化，比如上面的这几行代码，在Windows上在那个文件上写了两个字符（a carriage return and then a newline），而在linux下面就只写一个（newline）
```
char *file_name;
/* Initialize file_name */
FILE *file = fopen(file_name, "w"); //二进制流
/* Check for errors */
fputs("\n", file);
```
1. 流中的内容将会完全还原或写入到文件中。
