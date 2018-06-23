# 解决中文路径问题

1. 使用QString的toLocal8Bit获得本机8比特编码的QByteArray，然后再用data()提取其char *，e.g:qstr.toLocal8Bit().data()