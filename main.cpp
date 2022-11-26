#include <iostream>
#include "CNodeDynamic.h"
#include "CTreeDynamic.h"

int main() {
    std::cout <<"\nCNodeDynamic for int"<<std::endl;
    CNodeDynamic<int> tree_int;
    tree_int.v_tree_test1();
    tree_int.vPrintAllBelow();
    std::cout << std::endl;

    std::cout <<"\nCNodeDynamic for dobule"<<std::endl;
    CNodeDynamic<double> tree_double;
    tree_double.v_tree_test2();
    tree_double.vPrintAllBelow();

    std::cout <<"\nCTreeDynamic 1 przed polaczeniem"<<std::endl;
    CTreeDynamic<int> tree1;
    tree1.pcGetRoot()->vAddNewChild();
    tree1.pcGetRoot()->vAddNewChild();
    tree1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    tree1.pcGetRoot()->pcGetChild(1)->vSetValue(2);

    tree1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    tree1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

    tree1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    tree1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    tree1.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    tree1.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    tree1.vPrintTree();

    std::cout <<"\nCTreeDynamic 2 przed polaczeniem"<<std::endl;
    CTreeDynamic<int> tree2;
    tree2.pcGetRoot()->vAddNewChild();
    tree2.pcGetRoot()->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->vSetValue(8);
    tree2.pcGetRoot()->pcGetChild(1)->vSetValue(18);

    tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(9);
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(10);

    tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(20);

    tree2.vPrintTree();


    tree1.bMoveSubtree(tree1.pcGetRoot(), tree2.pcGetRoot()->pcGetChild(0));
    std::cout <<"\nCTreeDynamic 1 po polaczeniu"<<std::endl;
    tree1.vPrintTree();
    std::cout <<"\nCTreeDynamic 2 po polaczeniu"<<std::endl;
    tree2.vPrintTree();
    std::cout <<"\n"<<std::endl;
}
