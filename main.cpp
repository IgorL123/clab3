#include <iostream>
#include <complex>
#include "BST.hpp"
#include "Set.hpp"
#include "person.hpp"
using namespace std;



template <typename T>
void inputTree(int size, BinarySearchTree<T> &tree){
    T x = 0;
    for (int i = 0; i < size; i ++) {
        cin >> x;
        tree.insert(x);
    }
}

template <typename T>
void inputSet(int size, set<T> &st){
    T x;
    for (int i = 0; i < size; i ++) {
        cin >> x;
        st.add(x);
    }
}

template <typename T>
void populateTree(int size, BinarySearchTree<T> &tree){

    for (int i = 0; i < size; i++){
        T value = rand() % 1000 + 1;
        tree.insert(value);
    }
}


template <typename Type>
int menuBST(){
    int oper = 1;
    while (oper){

        int size;
        cout << "Operations:\n";
        cout << "1. Balance tree\n2. Find sub tree\n3. Print\n4. Populate\n5. Populate & balance\n6. Threaded & print\n7. Quit" << endl;
        cin >> oper;
        if (oper == 7){
            return 0;
        }
        cout << "Enter size:\n";
        cin >>  size;
        BinarySearchTree<Type> a;
        BinarySearchTree<Type> b;
        bool res;
        if ( oper != 4 && oper != 5 ){
            cout << "Enter first tree:\n";
            inputTree(size, a);

        }
        switch(oper){
            case 1:
                cout << "Your tree: \n";
                a.printInorder(a.getRoot(), 10);
                a.balance();
                cout << "\nBalanced tree:\n";
                a.printInorder(a.getRoot(), 10);
                cout << "------------------------" << endl;
                break;
            case 2:
                cout << "Enter your subtree size:\n";
                cin >> size;
                cout << "Enter your subtree:\n";
                inputTree(size, b);
                cout << "Your subtree:\n";
                b.printInorder(b.getRoot(), 10);
                res = a.findSubTree(b);
                if (res){
                    cout << "Tree contains your subtree\n";
                } else {
                    cout << "Tree doesnt contain your subtree\n";
                }
                break;
            case 4:
                populateTree(size, a);
                cout << "------------------------" << endl;
                a.printInorder(a.getRoot(), 10);
                cout << "------------------------" << endl;
                break;
            case 3:
                cout << "------------------------" << endl;
                a.printInorder(a.getRoot(), 10);
                cout << "------------------------" << endl;
                break;
            case 5:
                populateTree(size, a);
                cout << "------------------------" << endl;
                a.printInorder(a.getRoot(), 10);
                cout << "------------------------" << endl;
                a.balance();
                cout << "------------------------" << endl;
                a.printInorder(a.getRoot(), 10);
                cout << "------------------------" << endl;
                break;
            case 6:
                cout << "------------------------" << endl;
                a.convert2Threaded(a.getRoot());
                a.threadInOrder(a.getRoot());
                cout << "\n------------------------" << endl;
                break;
            default:
                cout << "Wrong operation number";
                break;
        }


    }
}

template <typename Type>
int menuSet(int oo){
    int oper = 1;
    while (oper){
        int size;
        cout << "Operations:\n";
        cout << "1. Union\n2. Intersection\n3. Difference\n4. Print \n5. Quit" << endl;
        cin >> oper;
        if (oper == 5){
            return 0;
        }
        cout << "Enter size:\n";
        cin >>  size;
        set<Type> a;
        set<Type> b;
        cout << "Enter your first set:\n";
        if (oo){
            cout << "Id | First name | Middle name | Last name | Birth date\n";
        }
        inputSet(size, a);
        switch(oper){
            case 1:
                cout << "Enter your second set:\n";
                inputSet(size, b);
                cout << "Your sets: \n";
                cout << "First: ";
                a.print();
                cout << "\nSecond: ";
                b.print();
                a.unionSet(b);
                cout << "\nResult of union: \n";
                a.print();
                cout << "\n------------------------" << endl;
                break;
            case 2:
                cout << "Enter your second set:\n";
                inputSet(size, b);
                cout << "Your sets: \n";
                cout << "First: ";
                a.print();
                cout << "\nSecond: ";
                b.print();
                a.intersection(b);
                cout << "\nResult of intersection: \n";
                a.print();
                cout << "\n------------------------" << endl;
                break;
            case 3:
                cout << "Enter your second set:\n";
                inputSet(size, b);
                cout << "Your sets: \n";
                cout << "First: ";
                a.print();
                cout << "\nSecond: ";
                b.print();
                a.difference(b);
                cout << "\nResult of difference: \n";
                a.print();
                cout << "\n------------------------" << endl;
            case 4:
                cout << "------------------------" << endl;
                a.print();
                cout << "\n------------------------" << endl;
                break;
            case 5:
                break;
            default:
                cout << "Wrong operation number";
                break;
        }


    }
}


int main() {
    unsigned type = 1;
    unsigned struc = 1;
    while(type) {

        cout << "Tree or set; Enter 1 if tree and 2 if another:\n";
        cin >> struc;

        switch(struc){
            case 1:
                cout << "Choose type:\n";
                cout << "1. Integer\n2. Float\n" << endl;
                cin >> type;
                switch (type) {
                    case 1:
                        menuBST<int>();
                        break;
                    case 2:
                        menuBST<float>();
                        break;

                    default:
                        cout << "Wrong type number." << endl;
                        type = -1;
                        break;
                }
                break;
            case 2:
                cout << "Choose type:\n";
                cout << "1. Integer\n2. Float\n3. Complex\n4. Persons\n" << endl;
                cin >> type;
                switch (type) {
                    case 1:
                        menuSet<int>(0);
                        break;
                    case 2:
                        menuSet<float>(0);
                        break;
                    case 3:
                        //menuSet<complex<float>>(0);
                        break;
                    case 4:
                        menuSet<person>(1);
                        break;
                    default:
                        cout << "Wrong type number." << endl;
                        type = -1;
                        break;
                }
                break;
            default:
                cout << "Wrong type number." << endl;
                break;
        }
    }

    return 0;
}
