# COS30008 Problem Set 3

[English](README.md) | [简体中文](README.zh-CN.md)

## Introduction

This repository contains a C++ console-based text dungeon game developed for COS30008 Problem Set 3. The project demonstrates data structures and design patterns through:

- a generic four-way tree for the dungeon and its rooms;
- a custom doubly linked list for room items and the player's inventory;
- the Visitor pattern for attacking monsters, picking up items, and inspecting objects.

The player explores a sample dungeon, fights monsters, collects items, and inspects the contents of each room through text commands.

## Clone the Repository

```powershell
git clone https://github.com/COS30008-Data-Structure-and-Patterns/COS30008-Problem-Set-3.git
cd COS30008-Problem-Set-3
```

## Project Structure

```text
COS30008-Problem-Set-3/
├── include/                         # Class and template header files
│   ├── Tree.h                       # Generic N-ary tree
│   ├── List.h and Node.h            # Custom doubly linked list
│   ├── Visitor.h                    # Visitor interface
│   └── ...                          # Game entity and visitor declarations
├── src/                             # C++ source files
│   ├── main.cpp                     # Program entry point and game loop
│   ├── Dungeon.cpp                  # Sample dungeon construction
│   └── ...                          # Game entity and visitor implementations
├── COS30008 Problem Set 3.sln       # Visual Studio solution
└── COS30008 Problem Set 3.vcxproj   # Visual C++ project configuration
```

## Build and Run

### Visual Studio

Requirements:

- Windows
- Visual Studio with the **Desktop development with C++** workload and the **v145** platform toolset

Steps:

1. Open `COS30008 Problem Set 3.sln` in Visual Studio.
2. Select a configuration such as `Debug | x64`.
3. Choose **Build > Build Solution**.
4. Press `Ctrl+F5` to run the console application without debugging.

### Developer Command Prompt

Run the following commands in a Visual Studio Developer Command Prompt from the repository root:

```powershell
msbuild "COS30008 Problem Set 3.sln" /p:Configuration=Debug /p:Platform=x64
& ".\x64\Debug\COS30008 Problem Set 3.exe"
```

## Game Commands

```text
move <door>           Move through the specified door index
attack <index>        Attack a monster
pickup <index>        Pick up an item
inspect m <index>     Inspect a monster
inspect i <index>     Inspect an item
inv                   Display the player's inventory
help                  Display the command list
quit                  Exit the game
```
