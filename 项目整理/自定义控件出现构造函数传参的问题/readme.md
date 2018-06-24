# 自定义控件出现构造函数传参的问题
- 首先Qt Designer若是使用此提升的控件，将出错，因为构造函数需要传参。
- 解决方案：
- - Make a default value for your parameters
- - Make two constructors: with standard Qt's parameter QWidget * parent, and with your own parameters, and call the second if you're creating you class from code
- - Add function(s) to your class, that will set parameters (as Qt likes to do, for example: QFile( QString filename ) and QFile::setFileName( QString filename )
