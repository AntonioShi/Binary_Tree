//
// Created by antonio on 17-11-3.
//

#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H
/*
 * 二叉树
 * 采用链式顺序存储
 * 表示法：未知
 * 性质：课本5条
 *
 */
#include <malloc.h>
#include <jmorecfg.h>
#include <spandsp.h>

typedef char DataType ;
typedef struct Node{
    DataType data ;
    struct Node *leftChild ;
    struct Node *rightChild ;
}BiTreeNode;//结点的结构体定义



void Destroy(struct Node **root);

//初始化
void Initiate(BiTreeNode **root){
    *root = (BiTreeNode *)malloc(sizeof(BiTreeNode)) ;
    (*root)->data = 0 ;
    (*root)->leftChild = NULL ;
    (*root)->rightChild = NULL ;
}

//左插入结点：强行插入到别人的家族中去，成为当前要插入位置任务的继父母
BiTreeNode* InsertLeftNode(BiTreeNode *curr, DataType x){
    BiTreeNode *s, *t ;
    if (curr == NULL)
        return NULL ;
    t = curr->leftChild ;
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode)) ;
    s->data = x ;
    s->leftChild = t ;
    s->rightChild = NULL ;
    curr->leftChild = s ;

    return curr->leftChild ;
}

//右插入结点：同理
BiTreeNode* InsertRightNode(BiTreeNode *curr, DataType x){
    BiTreeNode *s, *t ;
    if (curr == NULL)
        return NULL ;
    t = curr->rightChild ;
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode)) ;
    s->data = x ;
    s->rightChild = t ;
    s->leftChild = NULL ;
    curr->rightChild = s ;

    return curr->rightChild ;
}

//判断结点是否为空
boolean Empty(BiTreeNode *curr){
    if(curr != NULL)
        return true ;
    else
        return false ;
}

//左删除
BiTreeNode* DeleteLeftTree(BiTreeNode *curr){
    if(curr == NULL || curr->leftChild == NULL)
        return NULL ;
    Destroy(&curr->leftChild) ;
    curr->leftChild = NULL ;
    return curr ;
}

//撤销
void Destroy(struct Node **root) {
    if((*root) != NULL && (*root)->leftChild != NULL)
        Destroy(&(*root)->leftChild) ;

    if((*root) != NULL && (*root)->rightChild != NULL)
        Destroy(&(*root)->rightChild) ;

    free(*root) ;
}

//右删除
BiTreeNode* DeleteRightTree(BiTreeNode *curr){
    if(curr == NULL || curr->rightChild == NULL)
        return NULL ;
    Destroy(&curr->rightChild) ;
    curr->rightChild = NULL ;
    return curr ;
}

//遍历二叉树:DLR前序遍历
void PreOrder(BiTreeNode *root, void visit(DataType item)){
    if(root != NULL){
        visit(root->data) ;
        PreOrder(root->leftChild, visit) ;
        PreOrder(root->rightChild, visit) ;
    }
}

//中序LDR
void InOrder(BiTreeNode *root, void visit(DataType item)) {
    if(root != NULL){
        InOrder(root->leftChild, visit) ;
        visit(root->data) ;
        InOrder(root->rightChild, visit) ;
    }
}

//后序LRD
void PostOrder(BiTreeNode *root, void visit(DataType item)) {
    if(root != NULL){
        PostOrder(root->leftChild, visit) ;
        PostOrder(root->rightChild, visit) ;
        visit(root->data) ;
    }
}

//打印二叉树:
void PrintBitree(BiTreeNode *root, int n){
    //n为缩进层数
    if(root == NULL) return;
    PrintBitree(root->rightChild, n+1) ;
    //访问根节点
    for (int i = 0; i < n-1; ++i) {
        printf("    ") ;
    }
    if(n > 0){
        printf("----") ;
        printf("%c\n", root->data) ;
    }
    PrintBitree(root->leftChild, n+1) ;
    return;
}
//撤销二叉树

//查找数据元素
BiTreeNode* Search(BiTreeNode *root, DataType x){
    BiTreeNode *find = NULL ;
    if(root != NULL){
        if(root->data == x){
            find = root ;
        }
        else{
            find = Search(root->leftChild, x) ;
            if(find == NULL)
                find = Search(root->rightChild, x) ;
        }
    }
    return find ;
}

//显示函数
void Visit(DataType item){
    printf("%c  ", item) ;
}
#endif //BINARY_TREE_BINARYTREE_H
