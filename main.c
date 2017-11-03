#include <stdio.h>
#include "binaryTree.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    BiTreeNode *root, *p, *find ;
    char x = 'E' ;
    Initiate(&root) ;
    p = InsertLeftNode(root, 'A') ;
    p = InsertLeftNode(p, 'B') ;
    p = InsertLeftNode(p, 'D') ;
    p = InsertRightNode(p, 'G') ;
    p = InsertRightNode(root->leftChild, 'C') ;
    InsertLeftNode(p, 'E') ;
    InsertRightNode(p, 'F') ;

    PrintBitree(root, 0) ;

    printf("前序遍历\n") ;
    PreOrder(root->leftChild, Visit) ;
    printf("\n中序遍历") ;
    InOrder(root->leftChild, Visit) ;
    printf("\n后序遍历") ;
    PostOrder(root->leftChild, Visit) ;

    find = Search(root, x) ;
    if(find != NULL)
        printf("\n在") ;
    else
        printf("\n不在") ;

    Destroy(&root) ;
    return 0;
}
