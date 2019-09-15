# C++
procticing

## Introduction
problems from leetcode and nowcode

## c++文件编译时可能出现的问题及解决

**报错1**：```error: in C++98 ‘iv’ must be initialized by constructor, not by ‘{...}’```
**解决**：编译时加参数 -std=c++11

**报错2**：```error: 'NULL' was not declared in this scope```
**解决**：加头文件#include<stdlib.h>

示例：
``` shell
g++ nextLargerNodes.cpp LinkList.cpp -o linklist.exe -std=c++11
```


## 头文件编写经验

```c++
#ifndef XXX
#define XXX 100
#endif

#if defined XXX
#undef XXX
#define XXX 100
#endif
```