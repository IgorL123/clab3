
#include "../BST.hpp"
#include <gtest/gtest.h>


TEST(bst_int, InitDefault) {
    BinarySearchTree<int> bst;
    ASSERT_EQ(nullptr, bst.getRoot());
}

TEST(bst_int, insert) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(1);
    ASSERT_EQ(1, bst.search(10));
    ASSERT_EQ(1, bst.search(1));
    ASSERT_EQ(0, bst.search(20));
}

TEST(bst_int, deleteNode) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(1);
    bst.insert(413134);
    auto *nd = bst.findNode(bst.getRoot(), 413134);
    bst.deleteNode(nd);

    ASSERT_EQ(1, bst.search(10));
    ASSERT_EQ(1, bst.search(1));
    ASSERT_EQ(0, bst.search(413134));
}

TEST(bst_int, getsubtree) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(1);
    bst.insert(15);
    bst.insert(14);
    bst.insert(13);

    auto *nd = bst.findNode(bst.getRoot(), 15);
    auto nt = bst.getSubTree(nd);
    ASSERT_EQ(0, nt.search(10));
    ASSERT_EQ(0, nt.search(1));
    ASSERT_EQ(1, nt.search(15));
    ASSERT_EQ(1, nt.search(14));
    ASSERT_EQ(1, nt.search(13));

}

TEST(bst_int, findsubtree) {
    BinarySearchTree<int> bst;
    BinarySearchTree<int> st1;
    BinarySearchTree<int> st2;
    bst.insert(10);
    bst.insert(1);
    bst.insert(15);
    bst.insert(14);
    bst.insert(13);

    st1.insert(15);
    st1.insert(14);
    st1.insert(13);

    st2.insert(15);
    st2.insert(14);

    ASSERT_EQ(1, bst.findSubTree(st1));
    ASSERT_EQ(0, bst.findSubTree(st2));


}

TEST(bst_int, balance) {
    BinarySearchTree<int> bst;
    BinarySearchTree<int> bd;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);
    bd.insert(3);
    bd.insert(1);
    bd.insert(2);
    bd.insert(4);
    bd.insert(5);
    bst.balance();
    ASSERT_EQ(1, bst.isEquals(bst.getRoot(), bd.getRoot()));
}


int func1(int elem){
    return elem * elem;
}
TEST(bst_int, map) {

    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);
    bst.map(func1);
    ASSERT_EQ(1, bst.search(1));
    ASSERT_EQ(1, bst.search(4));
    ASSERT_EQ(1, bst.search(9));
    ASSERT_EQ(1, bst.search(16));
    ASSERT_EQ(0, bst.search(5));
}

int func2(int elem1, int elem2){
    return elem1 * elem2;
}
TEST(bst_int, reduce) {

    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);
    auto res = bst.reduce(func2, 1);
    ASSERT_EQ(120, res);
}

bool func3(int elem1){
    return elem1 > 3;
}
TEST(bst_int, where) {
    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);

    bst = bst.where(func3);

    ASSERT_EQ(0, bst.search(1));
    ASSERT_EQ(0, bst.search(2));
    ASSERT_EQ(0, bst.search(3));
    ASSERT_EQ(1, bst.search(4));
    ASSERT_EQ(1, bst.search(5));

}

TEST(bst_int, string) {
    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);

    auto res = bst.getString();
    ASSERT_EQ(" 1 2 3 ", res);


}