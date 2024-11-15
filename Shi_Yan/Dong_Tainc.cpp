//
// Created by 黄展博 on 2024/11/15.
//
#include <iostream>

int main() {
    int* ptr = new int;  // 分配内存
    *ptr = 10;           // 使用内存
    std::cout << "Value: " << *ptr << std::endl;
    delete ptr;          // 释放内存
    return 0;
}
