
#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>

template <typename Type> class BinarySearchTree;

template <typename TYPE> class treeNode {
    friend class BinarySearchTree<TYPE>;

public:

    explicit treeNode(const TYPE &a) {
        data = a;
        left = right = 0;
        isThreaded = false;
    }

    TYPE getData() { return data; }

protected:
    treeNode *left;
    treeNode *right;
    treeNode *parent;
    TYPE data;
    bool isThreaded{};
};


template <typename Type>
class BinarySearchTree {
private:

    treeNode<Type> *root;
    size_t size;

public:

    BinarySearchTree();
    explicit BinarySearchTree(treeNode<Type> *);
    void insert(const Type &);
    treeNode<Type>* deleteNode(treeNode<Type> *);

    [[maybe_unused]] treeNode<Type>* findMax(treeNode<Type>*);
    treeNode<Type>* findMin(treeNode<Type>*);
    treeNode<Type>* findNode(treeNode<Type>*, const Type &);
    treeNode<Type>* findNext(const Type &);
    treeNode<Type>* getRoot();
    int getSize();
    bool search(const Type &);
    bool isEquals(treeNode<Type> *, treeNode<Type> *);
    int getHeight(treeNode<Type>*);

    BinarySearchTree<Type> map(Type(*func)(Type));
    BinarySearchTree<Type> where(bool(*predicate)(Type));
    Type reduce(Type(*reducer)(Type, Type), Type const &value);

    void balance();
    BinarySearchTree<Type> getSubTree(treeNode<Type>*);
    bool findSubTree(BinarySearchTree<Type> );
    treeNode<Type> *convert2Threaded(treeNode<Type>*);

    void printInorder(treeNode<Type>*, size_t);
    void print2D(treeNode<Type>*);
    void threadInOrder(treeNode<Type> *);
    std::vector<Type> get2D();
    std::string getString();

protected:
    void mapper(Type(*func)(Type), treeNode<Type> *n);
    void wPath(bool(*predicate)(Type), treeNode<Type>*, BinarySearchTree<Type>*);
    Type reducePath(Type(*reducer)(Type, Type), treeNode<Type>*, const Type&);
    void storeNodes(treeNode<Type>*, std::vector<treeNode<Type>*> &);
    treeNode<Type>* allocationNodes(std::vector<treeNode<Type>*> &, int, int);
    bool inOrderCompare( treeNode<Type>*, treeNode<Type>*);
    treeNode<Type> *leftM(treeNode<Type> *);

};

template<typename Type>
BinarySearchTree<Type>::BinarySearchTree()
{
    root = nullptr;
    size = 0;

}

template<typename Type>
BinarySearchTree<Type>::BinarySearchTree(treeNode<Type>* newRoot)
{
    root = newRoot;
    size = 0;
}

template<typename Type>
void BinarySearchTree<Type>::insert(const Type &x)
{
    auto* n = new treeNode<Type>(x);
    treeNode<Type>* ptr;
    treeNode<Type>* ptr1 = nullptr;

    n->parent = n->left = n->right = 0;
    ptr = root;
    while(ptr != 0)
    {
        ptr1 = ptr;
        if(x < ptr->data )
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    n->parent = ptr1;
    if(ptr1 == 0)
        root = n;
    else
    {
        if(x < ptr1->data )
            ptr1->left = n;
        else
            ptr1->right = n;
    }
    size++;
}

template<typename Type>
treeNode<Type>* BinarySearchTree<Type>::deleteNode(treeNode<Type> *z)
{
    treeNode<Type>* y;
    treeNode<Type>* x;
    if(z->left == 0 || z->right == 0)
        y = z;
    else
        y = findNext(z->getData());
    if(y->left!=0)
        x = y->left;
    else
        x = y->right;
    if(x!=0)
        x->parent = y->parent;
    if(y->parent == 0)
        root = x;
    else
    {
        if (y == (y->parent)->left)
            (y->parent)->left = x;
        else
            (y->parent)->right = x;
    }
    if(y != z)
        z->data = y->getData();
    size--;
    return y;
}

template<typename Type>
[[maybe_unused]] treeNode<Type>* BinarySearchTree<Type>::findMax(treeNode<Type>* x)
{
    while(x->right != 0)
        x = x->right;
    return x;
}

template<typename Type>
treeNode<Type>* BinarySearchTree<Type>::findMin(treeNode<Type>* x)
{
    while(x->left != 0)
        x = x->left;
    return x;
}

template<typename Type>
treeNode<Type>* BinarySearchTree<Type>::findNext(const Type & val)
{
    treeNode<Type>* x = findNode(root, val);
    treeNode<Type>* y;
    if(x == 0)
        return 0;
    if(x->right != 0)
        return findMin(x->right);
    y = x->parent;
    while(y != 0 && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

template<typename Type>
treeNode<Type>* BinarySearchTree<Type>::findNode(treeNode<Type>* n, const Type &value)
{
    if(n == nullptr || value == n->getData())
        return n;
    if(value > n->getData() )
        return findNode(n->right, value);
    else
        return findNode(n->left, value);
}

template<typename Type>
void BinarySearchTree<Type>::printInorder(treeNode<Type>* n, size_t space)
{
    if(n != 0)
    {
        space += 10;
        printInorder(n->right, space);


        std::cout << std::endl;
        for (size_t i = 10; i < space + 1; i++){
            std::cout<<" ";
        }
        std::cout << n->getData() << std::endl;

        printInorder(n->left, space);

    }
}

template<typename Type>
void BinarySearchTree<Type>::print2D(treeNode<Type>* n)
{
    if(n != 0)
    {
        print2D(n->left);
        std::cout << n->getData() << " ";
        print2D(n->right);
    }
}

template<typename Type>
std::vector<Type> BinarySearchTree<Type>::get2D()
{
    std::vector<treeNode<Type>*> nodes;
    std::vector<Type> res;
    storeNodes(root, nodes);
    for (size_t i = 0; i < nodes.size(); i++){
        res.push_back(nodes[i]->getData());
    }
    return res;
}

template<typename Type>
treeNode<Type>* BinarySearchTree<Type>::getRoot()
{
    return root;
}


template<typename Type>
void BinarySearchTree<Type>::storeNodes(treeNode<Type> *r, std::vector<treeNode<Type> *> &nodes) {
    if (r == nullptr)
        return;
    storeNodes(r->left, nodes);
    nodes.push_back(r);
    storeNodes(r->right, nodes);
}


template<typename Type>
treeNode<Type>* BinarySearchTree<Type>::allocationNodes(std::vector<treeNode<Type>*> &nodes, int start, int end)
{

    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    auto *r = nodes[mid];
    r->left  = allocationNodes(nodes, start, mid - 1);
    r->right = allocationNodes(nodes, mid + 1, end);

    return r;
}


template<typename Type>
void BinarySearchTree<Type>::balance() {
    auto *rt = root;

    std::vector<treeNode<Type>*> nodes;
    storeNodes(rt, nodes);
    auto n = nodes.size();
    rt = allocationNodes(nodes, 0, n - 1);

    root = rt;
}

template<typename Type>
bool BinarySearchTree<Type>::search(const Type &value) {

    auto *current = getRoot();
    while (current){

        if (value > current->getData()){
            current = current->right;
        } else if ( value < current->getData() ) {
            current = current->left;
        } else if ( value == current->getData()){
            return true;
        }

    }

    return false;
}

template<typename Type>
BinarySearchTree<Type> BinarySearchTree<Type>::getSubTree(treeNode<Type> * rootNode) {


    auto *current = getRoot();
    while (current){

        if (rootNode->getData() > current->getData()){
            current = current->right;
        } else if ( rootNode->getData() < current->getData() ) {
            current = current->left;
        } else if ( rootNode->getData() == current->getData()){

            BinarySearchTree<Type> res(current);
            return res;
        }
    }
    return  *this;
}


template<typename Type>
bool BinarySearchTree<Type>::inOrderCompare(treeNode<Type> *rt1, treeNode<Type> *rt2 ) {


    return isEquals(rt1, rt2)
    || (rt1->left != nullptr && inOrderCompare(rt1->left, rt2))
    || (rt1->right != nullptr && inOrderCompare(rt1->right, rt2));
}

template<typename Type>
bool BinarySearchTree<Type>::findSubTree(BinarySearchTree<Type> tree) {

    return inOrderCompare(root, tree.getRoot());
}

template<typename Type>
bool BinarySearchTree<Type>::isEquals(treeNode<Type> *tree1, treeNode<Type> *tree2 ) {

    if (tree1 == nullptr && tree2 == nullptr ){
        return true;
    }
    if (tree1 == nullptr || tree2 == nullptr){
        return false;
    }

    if (tree1->getData() != tree2->getData()){
        return false;
    }

    return isEquals(tree1->left, tree2->left) && isEquals(tree1->right, tree2->right);
}


template<typename Type>
void BinarySearchTree<Type>::mapper(Type (*func)(Type), treeNode<Type> *n) {
    n->data = func(n->getData());
    if (n->left) {
        mapper(func, n->left);
    }
    if ( n->right) {
        mapper(func, n->right);
    }
}

template<typename Type>
void BinarySearchTree<Type>::wPath(bool (*predicate)(Type), treeNode<Type> * n , BinarySearchTree<Type> *tree) {
    if (predicate(n->getData())){
        tree->insert(n->getData());
    }
    if(n->left){
        wPath(predicate, n->left, tree);
    }
    if (n->right){
        wPath(predicate, n->right, tree);
    }
}

template<typename Type>
BinarySearchTree<Type> BinarySearchTree<Type>::map(Type (*func)(Type)) {
    if (func == nullptr){
        return *this;
    }
    BinarySearchTree<Type> res(getRoot());
    mapper(func, res.getRoot());
    return res;
}

template<typename Type>
BinarySearchTree<Type> BinarySearchTree<Type>::where(bool (*predicate)(Type)) {
    if (predicate == nullptr){
        return *this;
    }
    BinarySearchTree<Type> res;
    wPath(predicate, getRoot(), &res);
    return res;
}

template<typename Type>
Type BinarySearchTree<Type>::reduce(Type (*reducer)(Type, Type), const Type &value) {
    if (reducer == nullptr){
        return 0;
    }
    Type res = reducePath(reducer, getRoot(), value);
    return res;
}

template<typename Type>
Type BinarySearchTree<Type>::reducePath(Type (*reducer)(Type, Type), treeNode<Type> *n, const Type &value) {
    if (n) {
        Type res = reducer(n->data, value);
        res = reducePath(reducer, n->left, res);
        res = reducePath(reducer, n->right, res);
        return res;
    }

    return value;
}

template<typename Type>
int BinarySearchTree<Type>::getSize() {
    return size;
}

template <class Type>
int BinarySearchTree<Type>::getHeight( treeNode<Type> *workingPtr)
{
    int leftH, rightH;

    if( workingPtr == NULL )
    {
        return 0;
    }

    leftH = getHeight( workingPtr->left );
    rightH = getHeight( workingPtr->right );

    if( rightH > leftH )
    {
        return rightH + 1;
    }

    else
    {
        return leftH + 1;
    }
}


template<typename Type>
treeNode<Type> *BinarySearchTree<Type>::convert2Threaded(treeNode<Type> *rt) {


    if (rt == nullptr)
        return rt;
    if (rt->left == nullptr &&
        rt->right == nullptr)
        return rt;

    if (rt->left != nullptr)
    {

        treeNode<Type> *l = convert2Threaded(rt->left);

        l->right = rt;
        l->isThreaded = true;
    }


    if (rt->right == nullptr)
        return rt;

    return convert2Threaded(rt->right);
}

template<typename Type>
std::string BinarySearchTree<Type>::getString() {
    auto vec = get2D();

    std::string res = " ";
    for (int i = 0; i < vec.size(); i++){
        res += std::to_string(vec[i]) + " ";
    }
    return res;
}

template<typename Type>
treeNode<Type> *BinarySearchTree<Type>::leftM(treeNode<Type> *rt) {
    while (rt != nullptr && rt->left != nullptr)
        rt = rt->left;
    return rt;
}

template<typename Type>
void BinarySearchTree<Type>::threadInOrder(treeNode<Type> *rt) {
    if (root == nullptr) return;

    treeNode<Type> *cur = leftM(rt);

    while (cur != nullptr)
    {
        std::cout << cur->data << " ";

        if (cur->isThreaded)
            cur = cur->right;

        else
            cur = leftM(cur->right);
    }
}


#endif //BST_HPP