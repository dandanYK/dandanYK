// Created by 黄展博 on 2024/11/18.

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/* 基于链表实现的栈 */
class LinkedListStack {
private:
    ListNode *stackTop; // 将头节点作为栈顶
    int stkSize;        // 栈的长度

public:
    LinkedListStack() {
        stackTop = nullptr;
        stkSize = 0;
    }

    ~LinkedListStack() {
        // 遍历链表删除节点，释放内存
        freeMemoryLinkedList(stackTop);
    }

    /* 释放链表内存 */
    void freeMemoryLinkedList(ListNode *node) {
        while (node != nullptr) {
            ListNode *tmp = node;
            node = node->next;
            delete tmp;
        }
    }

    /* 获取栈的长度 */
    int size() {
        return stkSize;
    }

    /* 判断栈是否为空 */
    bool isEmpty() {
        return size() == 0;
    }

    /* 入栈 */
    void push(int num) {
        ListNode *node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stkSize++;
    }

    /* 出栈 */
    int pop() {
        if (isEmpty()) {
            throw out_of_range("栈为空");
        }
        int num = top();
        ListNode *tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
        stkSize--;
        return num;
    }

    /* 访问栈顶元素 */
    int top() {
        if (isEmpty()) {
            throw out_of_range("栈为空");
        }
        return stackTop->val;
    }

    /* 将 List 转化为 Array 并返回 */
    vector<int> toVector() {
        ListNode *node = stackTop;
        vector<int> res(size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};

int main() {
    LinkedListStack stack;

    // 入栈
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // 出栈
    cout << "Pop: " << stack.pop() << endl;

    // 访问栈顶元素
    cout << "Top: " << stack.top() << endl;

    // 获取栈的长度
    cout << "Size: " << stack.size() << endl;

    // 判断栈是否为空
    cout << "Is Empty: " << (stack.isEmpty() ? "true" : "false") << endl;

    // 将栈转换为数组
    vector<int> vec = stack.toVector();
    cout << "Stack to Vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
