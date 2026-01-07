//
// Created by redredmaple on 2025/8/25.
//

#ifndef MAIEV_LINKLIST_H
#define MAIEV_LINKLIST_H

template<class Type>
struct nodeType{
    Type info;
    nodeType<Type>* link;
};

template<class Type>
class linkedListType{
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>&);
    void initializeList();
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destroyList();
    Type front() const;
    Type back() const;
    virtual bool search(const Type& searchItem) const = 0;
    virtual void insertFirst(const Type& newItem) = 0;
    virtual void insertLast(const Type& newItem) = 0;
    virtual void deleteNodes(const Type& deleteItem) = 0;
    linkedListType<Type> begin();
    linkedListType<Type> end();
    linkedListType();
    linkedListType(const linkedListType<Type>& otherList){
        first = nullptr;
        copyList(otherList);
    }
    ~linkedListType();
protected:
    int count;
    nodeType<Type>* first;
    nodeType<Type>* last;
private:
    void copyList(const linkedListType<Type>& otherList);
};

template<typename Type>
class unorderedLinkedList: public linkedListType<Type>{
public:
    bool search(const Type& searchItem) const;
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    void deleteNode(const Type& deleteItem);
};

template<typename Type>
bool unorderedLinkedList<Type>::search(const Type &searchItem) const {
    nodeType<Type>* current;
    bool found = false;

    current = this->first; //@TODO ????????????

    while(current != nullptr && !found){
        if (current->info == searchItem){
            found = true;
        }else{
            current = current->link;
        }
    }

    return found;
}

template<typename Type>
void linkedListType<Type>::copyList(const linkedListType<Type> &otherList) {
    nodeType<Type>* newNode;
    nodeType<Type>* current;

    if (first != nullptr){
        destroyList();
    }

    if (otherList.first == nullptr){
        first = nullptr;
        last = nullptr;
        count = 0;
    }else{
        current = otherList.first;
        count = otherList.count;

        first = new nodeType<Type>;
        first->info = otherList.first->info;
        first->link = nullptr;
        last = first;
        current = current->link;

        while(current != nullptr){
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;

            last->link = newNode;
            last = newNode;

            current = current->link;
        }
    }
}

template<typename Type>
bool linkedListType<Type>::isEmptyList() const {
    return first == nullptr;
}

template<typename Type>
linkedListType<Type>::~linkedListType<Type>() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

template<typename Type>
void linkedListType<Type>::destroyList() {
    nodeType<Type>* temp;
    //delete nodes!!!
    while(first != nullptr){
        temp = first;
        first = first->link;
        delete temp;
    }

    last = nullptr;
    count = 0;
}

template<typename Type>
void linkedListType<Type>::initializeList() {
    destroyList();
}

#include <iostream>
using std::cout;
using std::endl;
template<typename Type>
void linkedListType<Type>::print() const {
    nodeType<Type> * current;
    current = first;
    while(current != nullptr){
        cout << "info:" << current->info << endl;
        current = current->link;
    }
}

template<typename Type>
int linkedListType<Type>::length() const {
    return count;
}

template<typename Type>
Type linkedListType<Type>::front() const {
    assert(first != nullptr);
    return first->info;
}

template<typename Type>
Type linkedListType<Type>::back() const {
    assert(last != nullptr);
    return last->info;
}

template<typename Type>
linkedListType<Type> linkedListType<Type>::begin() {
    linkedListType<Type> temp(first);

    return temp;
}

template<typename Type>
linkedListType<Type> linkedListType<Type>::end() {
    linkedListType<Type> temp(last);

    return temp;
}

template<typename Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList){
    if (this != otherList){
        copyList(otherList);
    }

    return *this;
}




template <class Type>
class LinkListIterator{
public:
    LinkListIterator();
    LinkListIterator(nodeType<Type> *ptr);
    Type operator*();
    LinkListIterator<Type> operator++();
    LinkListIterator<Type> operator++(int i);
    bool operator==(const LinkListIterator<Type>& right) const;
    bool operator!=(const LinkListIterator<Type>& right) const;
private:
    nodeType<Type>* current;
};

template <class Type>
LinkListIterator<Type>::LinkListIterator() {
    current = nullptr;
}

template<class Type>
LinkListIterator<Type>::LinkListIterator(nodeType<Type> *ptr) {
    current = ptr;
}

template<class Type>
Type LinkListIterator<Type>::operator*() {
    return *current->info;
}

template<class Type>
LinkListIterator<Type> LinkListIterator<Type>::operator++() {
    current = current->link;
    return *this;
}

template<class Type>
LinkListIterator<Type> LinkListIterator<Type>::operator++(int i) {
    current = current->link;
    return *this;
}

template<class Type>
bool LinkListIterator<Type>::operator==(const LinkListIterator<Type> &right) const {
    return current == right.current;
}

template<class Type>
bool LinkListIterator<Type>::operator!=(const LinkListIterator<Type> &right) const {
    return !operator==(right);
}

#endif //MAIEV_LINKLIST_H
