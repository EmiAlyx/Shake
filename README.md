## 项目概述
本项目是一个简单的控制台贪吃蛇游戏，使用 C++ 语言编写，基于 Windows 控制台进行开发。游戏支持玩家输入控制蛇的移动方向，吃到食物后蛇身会变长，同时得分增加，速度加快。此外，还提供了查看游戏排行榜的功能。

## 功能特性
1. **游戏玩法**：玩家可以使用 `W`、`A`、`S`、`D` 键控制蛇的移动方向，吃到食物后蛇身变长，得分增加。
2. **排行榜**：记录玩家的得分，并按照得分从高到低进行排序，玩家可以随时查看排行榜。
3. **速度控制**：随着蛇吃到的食物增多，游戏速度会逐渐加快。

## 代码结构
### 头文件 `shake.h`
- 定义了游戏所需的常量，如游戏窗口的宽度 `WID` 和高度 `HIG`，以及排行榜文件的路径 `GOALS`。
- 定义了 `body` 结构体，用于表示蛇的每个身体部分的坐标。
- 定义了 `snake` 类和 `food` 类，分别表示蛇和食物。

### 源文件 `shake.cpp`
- 实现了 `snake` 类和 `food` 类的成员函数，包括蛇的初始化、重置、变长、碰撞检测，以及食物的初始化、重置等功能。

### 源文件 `main.cpp`
- 实现了游戏的主逻辑，包括游戏界面的初始化、游戏循环、玩家输入处理、排行榜的读取和排序等功能。

### 排行榜文件 `goals.txt`
- 用于记录玩家的得分信息，每行包含玩家的昵称和得分，用空格分隔。

## 使用方法
1. 编译并运行 `main.cpp` 文件。
2. 在控制台输入 `z` 开始游戏，输入玩家昵称后开始游戏。
3. 使用 `W`、`A`、`S`、`D` 键控制蛇的移动方向。
4. 吃到食物后蛇身变长，得分增加。
5. 游戏结束后，输入的玩家昵称和得分会被记录到排行榜中。
6. 在主菜单输入 `x` 可以查看排行榜。
7. 在主菜单输入 `p` 可以退出游戏。

## 注意事项
- 本项目基于 Windows 控制台开发，部分函数（如 `SetConsoleCursorPosition`、`SetConsoleCursorInfo` 等）为 Windows 特定函数，在其他操作系统上可能无法正常运行。
- 排行榜文件 `goals.txt` 会在程序运行过程中自动创建和更新，请确保程序有足够的权限进行文件操作。
