
#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <vector>
#include "BST.hpp"


template <typename Type>
class set         // хыуеъ
{

private:
    BinarySearchTree<Type> item;

public:

    set() { item = BinarySearchTree<Type>(); }
    void add(Type value) {
        if (!search(value)){
            item.insert(value);
        }
    }
    void remove(Type value) {item.deleteNode(item.findNode(item.getRoot(), value)); }
    bool search(Type value) { return item.search(value); }
    size_t size() { return item.getSize(); }
    void clear() { item = BinarySearchTree<Type>(); }
    bool isContain(set<Type> &set) { return item.findSubTree(set.item); }


    void unionSet(set<Type> &list) {
        std::vector<Type> a = list.item.get2D();

        for (int i = 0 ;i < a.size(); i++){
            if (!search(a[i])){
                add(a[i]);
            }
        }
    }

    void intersection(set<Type> &list) {
        std::vector<Type> a = list.item.get2D();
        std::vector<Type> b;

        for (int i = 0; i < a.size(); i++) {
            if (search(a[i]))
                b.push_back(a[i]);
        }
        clear();
        for (int i = 0; i < b.size(); i++){
            add(b[i]);
        }
    }

    void difference(set<Type> &list) {
        std::vector<Type> a = list.item.get2D();
        for (int i = 0; i < a.size(); i++){
            if (search(a[i])){
                remove(a[i]);
            }
        }
    }


    void map(Type (*func)(Type)) {
        if (func == nullptr){
            throw std::invalid_argument{"Wrong function"};
        }
        item.map(func);
    }

    Type reduceSet(Type (*func)(Type, Type), const Type &value) {
        if (func == nullptr){
            throw std::invalid_argument{"Wrong function"};
        }
        Type res = item.reduce(func, value);
        return res;
    }

    void where( bool(*func)(Type) ) {
        if (func == nullptr){
            throw std::invalid_argument{"Wrong function"};
        }
        item = item.where(func);
    }


    bool operator==(set<Type> &list) {
        return item.isEquals(item.getRoot(), list.item.getRoot());
    }


    set<Type> operator+(set<Type> &list) {
        return unionSet(list);
    }

    set<Type> operator*(set<Type> &list) {
        return intersection(list);
    }

    set<Type> operator-(set<Type> &list) {
        return difference(list);
    }

    void print(){
        std::vector<Type> a = item.get2D();

        for(int i = 0; i < size(); i++){
            std::cout << a[i] << ' ';
        }
    }

};


#endif //SET_HPP
