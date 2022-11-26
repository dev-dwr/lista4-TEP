
#include <vector>

class CNodeDynamic {
public:
    CNodeDynamic();

    CNodeDynamic(const CNodeDynamic &node);

    ~CNodeDynamic();

    void vSetValue(int iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    void vSetNewChild(CNodeDynamic *node);

    CNodeDynamic *pcGetChild(int iChildOffset);

    void vPrint();

    void vPrintUp();

    void vPrintAllBelow();

    void v_tree_test1();

    void v_tree_test2();

    void deleteChild(CNodeDynamic *node);

    CNodeDynamic *getParent();

    int getValue();

private:
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;
};
