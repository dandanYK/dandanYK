// Created by 黄展博 on 2024/12/6.
#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    // 释放链表内存
    ~LinkedList() {
        ListNode* p = head;
        while (p != nullptr) {
            ListNode* next = p->next;
            delete p;
            p = next;
        }
    }

    // 将元素插入到链表头部
    void insertAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    // 将数组转换为链表
    void createLinkedList(const vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            insertAtTail(nums[i]);
        }
    }

    // 将元素插入到链表尾部
    void insertAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // 删除链表中值为val的节点
    void deleteNode(int val) {
        ListNode* current = head;
        ListNode* prev = nullptr;

        // 找到要删除的节点，前面的判定链表是否为空，后面的判定是否找到了要删除的节点
        while (current != nullptr && current->val != val) {
            prev = current;
            current = current->next;
        }

        // 如果链表为空或者没有找到要删除的节点，则返回。因为尾节点的next指针也为nullptr
        if (current == nullptr) {
            cout << "没有找到要删除的节点 " << val << endl;
            return;
        }

        // 如果要删除的节点是头节点
        if (prev == nullptr) {
            // 因为current->next已经指向了要删除的节点的下一个节点，所以直接将head指向current->next即可
            head = current->next;
        } else {
            // 如果要删除的节点不是头节点，则将prev->next指向current->next即可
            prev->next = current->next;
        }

        // 释放要删除的节点内存
        delete current;
    }

    // 打印链表
    void printLinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->val << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

#include <vector>
// 其他必要的includes

int main() {
    LinkedList list;
    std::vector<int>  nums = {1, 2, 3, 4, 5}; // 创建一个vector
    list.createLinkedList(nums); // 通过vector传递参数

    list.printLinkedList();

    list.insertAtHead(0);
    list.printLinkedList();

    list.insertAtTail(6);
    list.printLinkedList();

    list.deleteNode(3);
}
