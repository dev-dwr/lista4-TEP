#ifndef CNODEDYNAMIC_H
#define CNODEDYNAMIC_H

#include <iostream>
#include <vector>

using namespace std;


template<typename T>
class CNodeDynamic {
public:
    CNodeDynamic();

    CNodeDynamic(const CNodeDynamic<T> &node);

    ~CNodeDynamic();

    void vSetValue(T iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    void vSetNewChild(CNodeDynamic<T> *node);

    CNodeDynamic<T> *pcGetChild(int iChildOffset);

    void vPrint();

    void vPrintUp();

    void vPrintAllBelow();

    void v_tree_test1();

    void v_tree_test2();


    void deleteChild(CNodeDynamic<T> *node);

    CNodeDynamic<T> *getParent();

    T getValue();


private:
    std::vector<CNodeDynamic<T> *> v_children;
    CNodeDynamic<T> *pc_parent_node;
    T i_val;
};

#endif /* !CNODEDYNAMIC_H*/

template<typename T>
CNodeDynamic<T>::CNodeDynamic() {
    i_val = 0;
    pc_parent_node = NULL;
}

template<typename T>
CNodeDynamic<T>::CNodeDynamic(const CNodeDynamic &node) {
    i_val = node.i_val;
    pc_parent_node = node.pc_parent_node;
    v_children = node.v_children;
}

template<typename T>
CNodeDynamic<T>::~CNodeDynamic() {
    std::cout << "Usuwam dynamiczny wezel: " << i_val << std::endl;
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        delete v_children[i];
    }


}

template<typename T>
void CNodeDynamic<T>::vSetValue(T iNewVal) {
    i_val = iNewVal;
}


template<typename T>
int CNodeDynamic<T>::iGetChildrenNumber() {
    return v_children.size();
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild() {
    CNodeDynamic *node;
    node = new CNodeDynamic();
    node->pc_parent_node = this;
    v_children.push_back(node);
}

template<typename T>
void CNodeDynamic<T>::vSetNewChild(CNodeDynamic *node) {
    node->pc_parent_node = this;
    v_children.push_back(node);
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
    if (iChildOffset >= 0 && iGetChildrenNumber() > iChildOffset) return v_children[iChildOffset];
    else return NULL;
}

template<typename T>
void CNodeDynamic<T>::vPrint() {
    std::cout << " " << i_val;
}

template<typename T>
void CNodeDynamic<T>::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL)
        pc_parent_node->vPrintUp();
}

template<typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++)
        v_children[i]->vPrintAllBelow();

}

template<typename T>
void CNodeDynamic<T>::deleteChild(CNodeDynamic *node) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if (v_children[i] == node)
            v_children.erase(v_children.begin() + i);
    }

}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::getParent() {
    return pc_parent_node;
}

template<typename T>
T CNodeDynamic<T>::getValue() {
    return i_val;
}

template<typename T>
void CNodeDynamic<T>::v_tree_test1() {
    vAddNewChild();
    vAddNewChild();
    pcGetChild(0)->vSetValue(1);
    pcGetChild(1)->vSetValue(2);
    pcGetChild(0)->vAddNewChild();
    pcGetChild(0)->vAddNewChild();
    pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    pcGetChild(1)->vAddNewChild();
    pcGetChild(1)->vAddNewChild();
    pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    pcGetChild(1)->pcGetChild(1)->vSetValue(22);
}


template<typename T>
void CNodeDynamic<T>::v_tree_test2() {
    vAddNewChild();
    vAddNewChild();
    pcGetChild(0)->vSetValue(1.5);
    pcGetChild(1)->vSetValue(2.2);
    pcGetChild(0)->vAddNewChild();
    pcGetChild(0)->vAddNewChild();
    pcGetChild(0)->pcGetChild(0)->vSetValue(3.7);
    pcGetChild(0)->pcGetChild(1)->vSetValue(4.4);
    pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(5.0);
}


