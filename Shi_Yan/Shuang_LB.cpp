#include <iostream>
#include <vector>

using namespace std;

class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;

    DoublyListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    DoublyListNode* head;
    DoublyListNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // 析构函数
    ~DoublyLinkedList() {
        DoublyListNode* cur = head;
        while (cur != nullptr) {
            DoublyListNode* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    // 创建双向链表
    void createDoublyLinkedList(vector<int>& arr) {
        if (arr.empty()) {
            return;
        }

        head = new DoublyListNode(arr[0]);
        tail = head;

        // for 循环迭代创建双链表
        for (int i = 1; i < arr.size(); i++) {
            DoublyListNode* newNode = new DoublyListNode(arr[i]);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // 插入节点到链表头部
    void insertAtHead(int val) {
        DoublyListNode* newNode = new DoublyListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // 插入节点到链表尾部
    void insertAtTail(int val) {
        DoublyListNode* newNode = new DoublyListNode(val);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    //在链表的指定位置插入元素
    void insertAtPosition(int val, int position)
    {
        if (position <= 0)
        {
            insertAtHead(val);
            return;
        }

        DoublyListNode* newNode = new DoublyListNode(val);
        DoublyListNode* cur = head;
        int curPosition = 0;

        while (cur != nullptr && curPosition < position -1)
        {
            cur = cur->next;
            curPosition++;
        }

        if (cur == nullptr)
        {
            insertAtTail(val);
        }
        else
        {
            newNode->next = cur->next;
            newNode->prev = cur;
            if (cur->next != nullptr)
            {
                cur->next->prev = newNode;
            }
            else
            {
                tail = newNode;
            }
            cur->next = newNode;
        }
    }

    // 删除链表中值为val的节点
    void deleteNode(int val) {
        DoublyListNode* cur = head;

        while (cur != nullptr && cur->val != val) {
            cur = cur->next;
        }

        if (cur == nullptr) {
            cout << "Node with value " << val << " not found." << endl;
            return;
        }

        if (cur->prev != nullptr) {
            cur->prev->next = cur->next;
        } else {
            head = cur->next;
        }

        if (cur->next != nullptr) {
            cur->next->prev = cur->prev;
        } else {
            tail = cur->prev;
        }

        delete cur;
    }

    // 打印双向链表
    void printDoublyLinkedList() {
        DoublyListNode* cur = head;
        while (cur != nullptr) {
            cout << cur->val << " <-> ";
            cur = cur->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    DoublyLinkedList list;

    // 创建双向链表
    list.createDoublyLinkedList(arr);

    // 打印双向链表
    list.printDoublyLinkedList();

    // 插入节点到链表头部
    list.insertAtHead(0);
    list.printDoublyLinkedList();

    // 插入节点到链表尾部
    list.insertAtTail(6);
    list.printDoublyLinkedList();

    //插入节点到指定位置
    list.insertAtPosition(5, 3);
    list.printDoublyLinkedList();

    // 删除节点
    list.deleteNode(3);
    list.printDoublyLinkedList();

    return 0;
}