#ifndef LISTA4_CTREEDYNAMIC_H
#define LISTA4_CTREEDYNAMIC_H

#include <iostream>


template<typename T>
class CTreeDynamic {
public:
    CTreeDynamic();

    ~CTreeDynamic();

    CNodeDynamic<T> *pcGetRoot();

    void vPrintTree();

    bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);



private:
    CNodeDynamic<T> *pc_root;
};

#endif //LISTA4_CTREEDYNAMIC_H

template<typename T>
CTreeDynamic<T>::CTreeDynamic() {
    pc_root = new CNodeDynamic<T>();
}


template<typename T>
CTreeDynamic<T>::~CTreeDynamic() {
    std::cout << "Usuwam drzewo dynamiczne" << std::endl;
    delete pc_root;
}


template<typename T>
CNodeDynamic<T> *CTreeDynamic<T>::pcGetRoot() {
    return pc_root;
}

template<typename T>
void CTreeDynamic<T>::vPrintTree() {
    pc_root->vPrintAllBelow();
}


template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode) {
    if (pcParentNode != NULL && pcNewChildNode != NULL) {
        pcNewChildNode->getParent()->deleteChild(pcNewChildNode);
        pcParentNode->vSetNewChild(pcNewChildNode);
        return true;
    } else return false;
}



