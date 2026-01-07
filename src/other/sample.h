//
// Created by redredmaple on 2025/8/7.
//

#ifndef MAIEV_SAMPLE_H
#define MAIEV_SAMPLE_H
template <typename elemType>
class arrayListType{
public:
    arrayListType<elemType>& operator=(const arrayListType<elemType> &);
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    void print() const;
    bool isItemAtEqual(int location, const elemType& item) const;
    void insertAt(int location, const elemType& insertItem);
    void insertEnd(const elemType& insertItem);
    void removeAt(int location);
    void retrieveAt(int location, elemType& retItem)const;
    void clearList();
    int seqSearch(const elemType& item) const;
    void insert(const elemType& item);
    void remove(const elemType& item);
    arrayListType(int size=100);
    arrayListType(const arrayListType<elemType> & other);
    ~arrayListType();
protected:
    elemType* list;
    int length;
    int maxSize;
};

template <typename elemType>
bool arrayListType<elemType>::isEmpty() const {
    return length == 0;
}

template <typename elemType>
bool arrayListType<elemType>::isFull() const {
    return length == maxSize;
}

template <typename elemType>
int arrayListType<elemType>::listSize() const {
    return length;
}

template <typename elemType>
int arrayListType<elemType>::maxListSize() const {
    return maxSize;
}

template<typename elemType>
void arrayListType<elemType>::print() const {
   for(int i = 0; i < length; i++){
       std::cout << list[i] << std::endl;
   }
}

template<typename elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType &item) const {
    return list[location] == item;
}

template<typename elemType>
void arrayListType<elemType>::insertAt(int location, const elemType &insertItem) {
    assert(location > 0 || location < maxSize);
    for(int i=length;i>location;i--){
        list[i] = list[i-1];
    }

    list[location] = insertItem;
    length++;
}

template<typename elemType>
void arrayListType<elemType>::insertEnd(const elemType &insertItem) {
    list[length++] = insertItem;
}

template<typename elemType>
void arrayListType<elemType>::removeAt(int location) {
    assert(location > 0 && location <length);
    for(int i = location; i< length;i ++){
        list[i] = list[i + 1];
    }
    length--;
}

template<typename elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType &retItem) const {
    assert(location > 0 && location <length);
    retItem = list[location];
}

template<typename elemType>
void arrayListType<elemType>::clearList() {
    length = 0;
}

template<typename elemType>
arrayListType<elemType>::arrayListType(int size) {
    assert(size>0);
    maxSize = size;
    length = 0;
    list = new elemType[maxSize];
}

template<typename elemType>
arrayListType<elemType>::~arrayListType(){
    maxSize = 0;
    length = 0;
    delete[] list;
};

template<typename elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType> &other) {
    maxSize = other.maxSize;
    length = other.length;
    list = new elemType[maxSize];

    for(int i = 0; i < length; i ++){
//        elemType item;
//        other.retrieveAt(i, item);
        list[i] = other.list[i];
    }
}

template<typename elemType>
arrayListType<elemType> &arrayListType<elemType>::operator=(const arrayListType<elemType> &other) {
    delete[] list;
    maxSize = other.maxSize;
    length = other.length;
    list = new elemType[maxSize];
    for(int i = 0; i < length; i ++){
        list[i] = other.list[i];
    }

    return *this;
}

template<typename elemType>
int arrayListType<elemType>::seqSearch(const elemType &item) const {
    int loc;
    bool found = false;
    for(loc = 0; loc<length;loc++){
        if (list[loc] == item){
            found = true;
            break;
        }
    }

    if (found){
        return loc;
    }else{
        return -1;
    }
}

template<typename elemType>
void arrayListType<elemType>::insert(const elemType &item) {
    int loc;
    if (length == 0){
        list[length++] = item;
    }else if (length == maxSize){
        std::cerr << "is full" << std::endl;
    }else{
        loc = seqSearch(item);

        if (loc == -1){
            list[length++] = item;
        }
    }
}

template<typename elemType>
void arrayListType<elemType>::remove(const elemType &item) {
    int loc;
    if (length ==0){
        std::cerr<< "can'n delete from an empty list!" << std::endl;
    }else{
        loc = seqSearch(item);
        if (loc == -1){
            std::cerr << "the item is'not in list!!";
        }else{
            removeAt(loc);
        }
    }
}

#endif //MAIEV_SAMPLE_H
