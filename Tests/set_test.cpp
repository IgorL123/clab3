#include "../Set.hpp"
#include <gtest/gtest.h>


TEST(set_int, InitDefault) {
    set<int> st;
    ASSERT_EQ(0, st.size());
}

TEST(set_int, add) {
    set<int> st;
    st.add(10);
    st.add(1);
    ASSERT_EQ(0, st.search(650));
    ASSERT_EQ(1, st.search(1));
    ASSERT_EQ(1, st.search(10));
}

TEST(set_int, remove) {
    set<int> st;
    st.add(10);
    st.add(1);
    st.add(9785);
    st.remove(1);

    ASSERT_EQ(1, st.search(9785));
    ASSERT_EQ(0, st.search(650));
    ASSERT_EQ(0, st.search(1));
    ASSERT_EQ(1, st.search(10));
}

TEST(set_int, isContain) {
    set<int> st;
    set<int> st2;
    set<int> st3;
    st.add(10);
    st.add(1);
    st.add(5);
    st.add(6);
    st.add(7);
    st.add(15);

    st2.add(5);
    st2.add(6);
    st2.add(7);

    st3.add(5);
    st3.add(8);
    st3.add(7);

    ASSERT_EQ(1, st.isContain(st2));
    ASSERT_EQ(0, st.isContain(st3));

}

TEST(set_int, unionSet) {
    set<int> st;
    set<int> st2;

    st.add(10);
    st.add(1);
    st.add(5);
    st.add(6);
    st.add(7);
    st.add(15);

    st2.add(5);
    st2.add(6);
    st2.add(8);

    st.unionSet(st2);

    ASSERT_EQ(1, st.search(8));
    ASSERT_EQ(1, st.search(7));
    ASSERT_EQ(1, st.search(5));
    ASSERT_EQ(1, st.search(10));
    ASSERT_EQ(1, st.search(1));
}

TEST(set_int, intersection) {
    set<int> st;
    set<int> st2;

    st.add(10);
    st.add(1);
    st.add(5);
    st.add(6);
    st.add(7);
    st.add(15);

    st2.add(5);
    st2.add(6);
    st2.add(8);

    st.intersection(st2);

    ASSERT_EQ(0, st.search(8));
    ASSERT_EQ(0, st.search(7));
    ASSERT_EQ(1, st.search(5));
    ASSERT_EQ(0, st.search(10));
    ASSERT_EQ(0, st.search(1));
}

TEST(set_int, differense) {
    set<int> st;
    set<int> st2;

    st.add(10);
    st.add(1);
    st.add(5);
    st.add(6);
    st.add(7);
    st.add(15);

    st2.add(5);
    st2.add(6);
    st2.add(8);

    st.difference(st2);

    ASSERT_EQ(0, st.search(8));
    ASSERT_EQ(1, st.search(7));
    ASSERT_EQ(0, st.search(5));
    ASSERT_EQ(1, st.search(10));
    ASSERT_EQ(1, st.search(1));
}
int func(int a){
    return a % 2;
}

TEST(set_int, map) {
    set<int> st;

    st.add(10);
    st.add(1);
    st.add(5);

    st.map(func);
    st.print();
    /*
    ASSERT_EQ(1, st.search(2));
    ASSERT_EQ(1, st.search(6));
    ASSERT_EQ(1, st.search(11));
    ASSERT_EQ(0, st.search(10));
    ASSERT_EQ(0, st.search(1));
     */
    ASSERT_EQ(2, st.size());
}

int funcion(int a, int b){
    return a +  b + 1;
}

TEST(set_int, reduce) {
        set<int> st;

        st.add(10);
        st.add(1);
        st.add(5);

        auto res = st.reduceSet(funcion, 1);

    ASSERT_EQ(20, res);

}

bool is(int a){
    return a % 5 == 0;
}

TEST(set_int, where) {
    set<int> st;

    st.add(10);
    st.add(1);
    st.add(5);

    st.where(is);

    ASSERT_EQ(1, st.search(10));
    ASSERT_EQ(1, st.search(5));
    ASSERT_EQ(0, st.search(1));

}