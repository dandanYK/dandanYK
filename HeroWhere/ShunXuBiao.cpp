#include <iostream>
using namespace std;

#define eleType double

//创建结构体用来对顺序表管理和操作
struct SequentialList {
    eleType* elements; //创建指针，指向的是自己创建的数组。
    int size;//数组内现有的元素个数
    int capacity;//数组的容量
};

//初始化，定义数组的大小
void initializeList(SequentialList* list, int capacity) {
    list->elements = new eleType[capacity]();//直接让指针指向新定义的数组
    list->size = 0;
    list->capacity = capacity;
}

//删除数组在堆内的空间
void destroyList(SequentialList* list) {
    delete[] list->elements;
}

//判断顺序表是否为空，如果为空则返回真
bool isEmpty(SequentialList* list) {
    return list->size == 0;
}

//获得数组现有的元素个数
int size(SequentialList* list) {
    return list->size;
}

//插入元素，整个结构里最复杂的操作
void insert(SequentialList* list, int index, eleType element) {
    //三个参数分别是要操作的列表结构体，插入的位置和插入的数据
    if (index < 0 || index > list->size) { //判断插入的位置是否合法
        throw std::invalid_argument("Invalid index");//如果不合法则抛出异常
    }

    if (list->size == list->capacity) { //如果顺序表满了
        int newCapacity = list->capacity * 2; 
        eleType* newElements = new eleType[newCapacity]();
        for (int i = 0; i < list->size; i++) {
            newElements[i] = list->elements[i];
        }
        delete[] list->elements; //在数据移动后将原来的数组给销毁
        list->elements = newElements; //将结构体内的指针指向变化一下
        list->capacity = newCapacity;//将结构体内的顺序表容量更改一下
    }
    list->size++;//放在哪里其实都是可以的下面也是可以的
    if (list->size <= list->capacity) { 
        //进行插入操作的第一步就是将那些在插入位置后的数据向后移一位
        for (int i = list->size - 1; i > index; i--) {
            list->elements[i] = list->elements[i - 1];
        }
        list->elements[index] = element;//上面的一大段都是为了执行这一句操作
    }
}

void deleteElement(SequentialList* list, int index) {
    if (index < 0 || index >= list->size) {
        //索引等于size的话也是属于越界操作了
        throw std::invalid_argument("Invalid index");
    }

    for (int i = index; i < list->size - 1; i++) {
        //直接将要删除的位置后的数据都往前移一下，直接将数据给覆盖掉
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
}

int findElement(SequentialList* list, eleType element) {
    for (int i = 0; i < list->size; i++) {
        if (list->elements[i] == element) {
            return i;
        }
    }
    return -1;
}

eleType getElement(SequentialList* list, int index) {
    if (index < 0 || index >= list->size) {
        throw std::invalid_argument("Invalid index");
    }
    return list->elements[index];
}

void updateElement(SequentialList* list, int index, eleType value) {
    if (index < 0 || index >= list->size) {
        throw std::invalid_argument("Invalid index");
    }

    list->elements[index] = value;
}

int main() {
    SequentialList myList;
    initializeList(&myList, 10);

    for (int i = 0; i < 10; i++) {
        insert(&myList, i, i * 10);
    }

    cout << "Size: " << size(&myList) << endl;
    cout << "Is empty: " << isEmpty(&myList) << endl;

    for (int i = 0; i < size(&myList); i++) {
        cout << getElement(&myList, i) << " ";
    }
    cout << endl;

    deleteElement(&myList, 5);
    updateElement(&myList, 1, 1314);

    int idx = findElement(&myList, 20);
    updateElement(&myList, idx, 520);

    cout << "Size: " << size(&myList) << endl;
    cout << "Is empty: " << isEmpty(&myList) << endl;

    for (int i = 0; i < size(&myList); i++) {
        cout << getElement(&myList, i) << " ";
    }
    cout << endl;

    destroyList(&myList);

    return 0;
}