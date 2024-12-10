#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
    public:
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList
{
    private:
        ListNode* head;

    public:
        LinkedList() : head(nullptr) {}

        ~LinkedList()
        {
            ListNode* p = head;
            while (p != nullptr)
            {
                ListNode* next = p->next;
                delete p;
                p = next;
            }
        }

        //在链表的头部插入节点
        void insertAtHead(int val)
        {
            ListNode* newNode = new ListNode(val);
            newNode->next = head;
            head = newNode;
        }

        //将数组转化为链表
        void createLinkedList(const vector<int>& nums)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                insertAtTail(nums[i]);
            }
        }

        //在链表的指定位置插入节点
        void insertAtPosition(int val, int position)
        {
            ListNode* newNode = new ListNode(val);
            if(position <= 0)
            {
                insertAtHead(val);
                return;
            }

            ListNode* cur = head;
            ListNode* prev = nullptr;

            for (int n = 0; n < position; n++)
            {
                prev = cur;
                cur = cur->next;
            }

            prev->next = newNode;
            newNode->next = cur;
        }

        //将元素添加到链表尾部
        void insertAtTail(int val)
        {
            ListNode* newNode = new ListNode(val);

            ListNode* cur = head;
            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                while (cur->next != nullptr)
                {
                    cur = cur->next;
                }

                cur->next = newNode;
            }
        }

        //删除链表中值为val的节点
        void deleteNode(int val)
        {
            ListNode* cur = head;
            ListNode* prev = nullptr;

            while (cur != nullptr && cur->val != val)
            {
                prev = cur;
                cur = cur->next;
            }

            if (cur == nullptr)
            {
                cout << "没有找到要删除的节点" << val <<endl;
                return;
            }

            if (prev == nullptr)
            {
                head = head->next;
            }
            else
            {
                prev->next = cur->next;
            }

            delete cur;
        }


        //遍历输出链表
        void printLinkedList()
        {
            ListNode* cur = head;
            while (cur != nullptr)
            {
                cout << cur->val << "->";
                cur = cur->next;
            }

            cout << "遍历完了" << endl;
        }

};

int main()
{
    LinkedList list;

    vector<int> nums = {1, 2, 3, 5, 6};
    list.createLinkedList(nums);
    list.printLinkedList();

    list.insertAtHead(0);
    list.printLinkedList();

    list.insertAtTail(7);
    list.printLinkedList();

    list.insertAtPosition(4, 4);
    list.printLinkedList();

    list.deleteNode(1);
    list.printLinkedList();

    list.deleteNode(4);
    list.printLinkedList();


    return 0;
}