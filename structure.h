#ifndef STRUCTURE_H
#define STRUCTURE_H

struct TreeNode;
typedef struct TreeNode *Pos;
typedef struct TreeNode *Tree;
typedef int ElementType;
struct TreeNode
{
    ElementType key;
    Tree l;
    Tree r;
    int height;
};


#include <iostream>

#define MSIZE 100000
using namespace std;

class array{
public:   void set();
          void ins(int);
          void del(int);
private: int a[MSIZE];
         int csize;
};


class hash0{
public:   void set();
          void ins(int);
          void del(int);
private: int a[MSIZE];
         int h[MSIZE];
         int csize;
};


class BST{
public:   void set();
          ~BST() {delete[] T;}
          Pos FindMin( Tree );
          Tree ins(int,Tree);
          Tree del(int,Tree);
          Tree T;
};

class AVL{
public: void set();
        ~AVL() {delete[] T;}
        int QueryH(Pos);
        Pos singleL(Pos);
        Pos singleR(Pos);
        Pos doubleL(Pos);
        Pos doubleR(Pos);
        Tree Insert(int,Tree);
        Tree T;
};

class Heap{
public: void set();
        void adjust(int,int);
        void ins(int);
        void deltop();
        //void sort();
private: int a[MSIZE];
         int csize;

};




#endif // STRUCTURE_H
