//
// Created by 黄展博 on 2024/11/19.
//
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// 定义链表节点类
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 基于链表实现的队列
class LinkedListQueue {
private:
    ListNode *front, *rear; // 头节点 front ，尾节点 rear
    int queSize;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        queSize = 0;
    }

    ~LinkedListQueue() {
        // 遍历链表删除节点，释放内存
        freeMemoryLinkedList(front);
    }

    /* 获取队列的长度 */
    int size() {
        return queSize;
    }

    /* 判断队列是否为空 */
    bool isEmpty() {
        return queSize == 0;
    }

    /* 入队 */
    void push(int num) {
        // 在尾节点后添加 num
        ListNode *node = new ListNode(num);
        // 如果队列为空，则令头、尾节点都指向该节点
        if (front == nullptr) {
            front = node;
            rear = node;
        }
            // 如果队列不为空，则将该节点添加到尾节点后
        else {
            rear->next = node;
            rear = node;
        }
        queSize++;
    }

    /* 出队 */
    int pop() {
        if (isEmpty()) {
            throw out_of_range("队列为空");
        }
        int num = peek();
        // 删除头节点
        ListNode *tmp = front;
        front = front->next;
        // 释放内存
        delete tmp;
        queSize--;
        return num;
    }

    /* 访问队首元素 */
    int peek() {
        if (isEmpty()) {
            throw out_of_range("队列为空");
        }
        return front->val;
    }

    /* 将链表转化为 Vector 并返回 */
    vector<int> toVector() {
        ListNode *node = front;
        vector<int> res(size());
        for (int i = 0; i < res.size(); i++) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }

private:
    /* 释放链表内存 */
    void freeMemoryLinkedList(ListNode *node) {
        while (node != nullptr) {
            ListNode *tmp = node;
            node = node->next;
            delete tmp;
        }
    }
};

int main() {
    LinkedListQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << "Queue size: " << queue.size() << endl;
    cout << "Front element: " << queue.peek() << endl;

    while (!queue.isEmpty()) {
        cout << "Popped: " << queue.pop() << endl;
    }

    return 0;
}
