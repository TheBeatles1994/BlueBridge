# C/C++多种方法获取文件大小

```
FILE* file = fopen(filepath, "rb");
if (file)
{
    int size = filelength(fileno(file));
    cout<<size<<endl;
    fclose(file);
}
```