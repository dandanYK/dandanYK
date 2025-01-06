/*
在2025年的1月6日完成这个操作，通过手敲一遍发现自己在一些细节方面还是比较欠缺，
就像在就结构体定义后加不加；还有其他的一下小细节，总的来说还是不错的。
*/
#include <iostream>
using namespace std;
#define eleType int

struct SequentiaList {
    eleType* elements;
    int size;
    int capacity;
};

void initializeList(SequentiaList* list, int capacity) {
    list->elements = new eleType[capacity]();
    list->size = 0;
    list->capacity = capacity;
}

void destroyList(SequentiaList* list) {
    delete list->elements;
}

bool isEmpty(SequentiaList* list) {
    return list->size == 0;
}

int size(SequentiaList* list) {
    return list->size;
}

void insert(SequentiaList* list, int index, eleType element) {
    if (index < 0 || index > list->capacity) {
        throw std::invalid_argument("Invalid index");
    }

    if (list->size == list->capacity) {
        int newcapacity = list->capacity * 2;
        eleType* newelements = new eleType[newcapacity];
        for(int i = 0; i < list->size; i++) {
            newelements[i] = list->elements[i];
        }
        delete[] list->elements;
        list->elements = newelements;
        list->capacity = newcapacity;
    }

    if(index <= list->capacity) {
        for(int a = list->size - 1; a > index; a--) {
            list->elements[a + 1] = list->elements[a];
        }
        list->elements[index] = element;
        list->size++;
    }
}

void deleteElement(SequentiaList* list, int index) {
    if (index < 0 || index >= list->capacity) {
        throw std::invalid_argument("Invalid index");
    }

    for(int i = index; i < list->size - 1; i++) {
        list->elements[index] = list->elements[index + 1];
    }
    list->size--;
}

int findElement(SequentiaList* list, eleType element) {
    for(int i = 0; i < list->size - 1; i++) {
        if(list->elements[i] == element) {
            return i;
        }
    }
    return -1;
}

eleType getElement(SequentiaList* list, int index) {
    if (index < 0 || index >= list->capacity) {
        throw std::invalid_argument("Invalid index");
    }
    return list->elements[index];
}

void updateElement(SequentiaList* list, int index, eleType value) {
    if (index < 0 || index >= list->capacity) {
        throw std::invalid_argument("Invalid index");
    }
    list->elements[index] = value;
}

int main() {
    SequentiaList myList;
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