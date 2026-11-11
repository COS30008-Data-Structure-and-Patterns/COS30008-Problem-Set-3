# COS30008 Problem Set 3

[English](README.md) | [简体中文](README.zh-CN.md)

## 项目简介

本仓库是为 COS30008 Problem Set 3 开发的 C++ 控制台文字地牢游戏。项目通过以下内容展示数据结构和设计模式的应用：

- 使用通用四叉树表示地牢及其房间；
- 使用自定义双向链表存储房间物品和玩家背包；
- 使用访问者模式实现攻击怪物、拾取物品和查看对象信息。

玩家可以通过文字命令探索示例地牢、与怪物战斗、收集物品，并查看每个房间中的内容。

## 克隆仓库

```powershell
git clone https://github.com/COS30008-Data-Structure-and-Patterns/COS30008-Problem-Set-3.git
cd COS30008-Problem-Set-3
```

## 项目结构

```text
COS30008-Problem-Set-3/
├── include/                         # 类和模板的头文件
│   ├── Tree.h                       # 通用 N 叉树
│   ├── List.h and Node.h            # 自定义双向链表
│   ├── Visitor.h                    # 访问者接口
│   └── ...                          # 游戏实体和访问者声明
├── src/                             # C++ 源文件
│   ├── main.cpp                     # 程序入口和游戏循环
│   ├── Dungeon.cpp                  # 示例地牢的构建逻辑
│   └── ...                          # 游戏实体和访问者实现
├── COS30008 Problem Set 3.sln       # Visual Studio 解决方案
└── COS30008 Problem Set 3.vcxproj   # Visual C++ 项目配置
```

## 构建与运行

### Visual Studio

环境要求：

- Windows
- 安装了 **使用 C++ 的桌面开发** 工作负载和 **v145** 平台工具集的 Visual Studio

运行步骤：

1. 使用 Visual Studio 打开 `COS30008 Problem Set 3.sln`。
2. 选择配置，例如 `Debug | x64`。
3. 点击 **生成 > 生成解决方案**。
4. 按 `Ctrl+F5`，在不调试的情况下运行控制台程序。

### Developer Command Prompt

在 Visual Studio Developer Command Prompt 中进入仓库根目录，然后运行：

```powershell
msbuild "COS30008 Problem Set 3.sln" /p:Configuration=Debug /p:Platform=x64
& ".\x64\Debug\COS30008 Problem Set 3.exe"
```

## 游戏命令

```text
move <door>           移动到指定门编号对应的房间
attack <index>        攻击指定编号的怪物
pickup <index>        拾取指定编号的物品
inspect m <index>     查看怪物信息
inspect i <index>     查看物品信息
inv                   显示玩家背包
help                  显示命令列表
quit                  退出游戏
```
