# 开发者文档
> ## Developer Docs

首先，Fork仓库(不要选择`Only fork the master branch`选项)，切换至`development`分支
> At first, fork the repository(Never `Only fork the master branch`), switch to the `development` branch.

## 功能添加
> ### Functions addition

添加功能仅需修改这3处：
> Addition functions only change these 3 files:

1. `src/identifiers/<Function-Name>.hpp`

```cpp
/**
 * <Function-Name> function
 * By <Author>
**/
void <Replaceable-Function-Name>(vector<string>::iterator it, ifstream &file) {
    <Function>;
}
```

2. `src/identifiers/identifiers.hpp`

```cpp
// Output
#include "output.hpp"
...
// <Function-Name>
#include "<Function-Name>.hpp"
```

3. `src/main.hpp`

```cpp
const string identifiers[] {
    identifiers["output"] = output;
    ...
    identifiers["<Function-Name>"] = <Replaceable-Function-Name>;
};
```


## 编译教程
> ### Recompile
编译（须`cmake`和`make`）：
> Compile (Requires `cmake` and `make`):
```bash
cmake .
make
```

## 发布到主分支教程
> ### Publish to master repository
这非常的简单，
> This is very easy.

使用`Pull requests`将你的仓库分支合并至`JunLang-dev/JunLang:development`
> Use `Pull requests` for let your repository compare to `JunLang-dev/JunLang:development`.