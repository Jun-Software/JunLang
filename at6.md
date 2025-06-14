# 开发者文档
> ## Developer Docs

## 功能添加教程
> ### Functions addition

添加功能仅需修改4个地方：
> Addition functions only change 4 files:

1. `src/init.hpp`
```cpp
const string identifiers[] {
    "output",
    ...,
    "<Function-Name>"
};
```

2. `src/interpreter.hpp`
```cpp
        if (!unknow) {
            // identifier: output
            add_function(it, file, 0, output);
            ...
            // identifier: <Function-Name>
            add_function(it, file, <Number>, <Function-Name>);
        }
```

3. `src/identifiers/identifiers.hpp`
```cpp
// Output
#include "output.hpp"
...
// <Function-Name>
#include "<Function-Name>.hpp"
```

4. `src/identifiers/<Function-Name>.hpp`

```cpp
/**
 * <Function-Name> function
 * By <Author>
**/
void <Function-Name>(vector<string>::iterator it, ifstream &file) {
    <Function>;
}
```

## 编译教程
> ### Recompile
编译（必须安装`cmake`和`make`）：
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