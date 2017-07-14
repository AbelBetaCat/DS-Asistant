#include <structure.h>
#include <iostream>

void array::set()
{
    csize=0;
}

void array::ins(int x)
{   if (csize==MSIZE) {cout<<"Illegal insertion!The array is full!"<<endl;return ;}
    int i,l=0,r=csize,mid;
    while (l<=r)
    {
        mid=(r-l)/2+l;
        if (a[mid]>x) r=mid-1;
        else if (a[mid]<x) l=mid+1;
        else { for (i=csize;i>mid;i--) a[i+1]=a[i];
            a[mid+1]=x;
            csize++;
            return ;
        }

    }
    if (x>=a[mid]) mid++;
    for (i=csize;i>=mid;i--) a[i+1]=a[i];
    a[mid]=x;
    csize++;
    return ;
}

void array::del(int x)
{
    int i,l=0,r=csize,mid;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (a[mid]>x) r=mid-1;
        else if (a[mid]<x) l=mid+1;
        else { for (i=mid+1;i<=csize;i++) a[i-1]=a[i];
            csize--;
            return ;
        }
    }
    cout<<"Illegal deletion!Cannot find "<<x<<"!"<<endl;return ;
}
void hash0::set()
{   int i;
    csize=11;
    for (i=0;i<=MSIZE;i++) h[i]=0;
}
void hash0::ins(int x)
{  int i=x%csize,k=0;
    while ((i<=MSIZE)&&(h[i]!=0)) i++;
    if (i>csize) { cout<<"Illegal insertion!The hash table is full!"<<endl;
        return ;
    }
    h[i]=1;a[i]=x;

}
void hash0::del(int x)
{  int i=x%csize,k=0;
    while ((i<=MSIZE)&&(h[i]!=0)) i++;
    if (i>csize) { cout<<"Illegal deletion!Cannot find "<<x<<"!"<<endl;
        return ;
    }
    h[i]=0;

}

void BST::set()
{
    T=NULL;
}

Tree BST::ins( ElementType X , Tree T)
{
    if ( T == NULL ) { /* Create and return a one-node tree */
        {   T = new TreeNode;
            T->key = X;
            T->l = T->r = NULL; }
    }  /* End creating a one-node tree */
    else  /* If there is a tree */
        if ( X < T->key )
            T->l = ins( X, T->l );
        else
            if ( X > T->key )
                T->r = ins( X, T->r );
    /* Else X is in the tree already; we'll do nothing */
    return  T;   /* Do not forget this line!! */
}

Pos  BST::FindMin( Tree T )
{
    if ( T == NULL )
        return  NULL; /* not found in an empty tree */
    else
        if ( T->l == NULL )   return  T;  /* found left most */
        else   return  FindMin( T->l );   /* keep moving to left */
}


Tree BST::del( ElementType X ,Tree T)
{    Pos  TmpCell;
     if ( T == NULL )  { cout<<"Illegal deletion!Cannot find "<<X<<"!"<<endl;
         return 0;
     }
     else  if ( X < T->key )  /* Go left */
         T->l = del( X, T->l );
     else  if ( X > T->key )  /* Go right */
         T->r = del( X, T->r );
     else  /* Found element to be deleted */
         if ( T->l && T->r ) {  /* Two children */
             /* Replace with smallest in right subtree */
             TmpCell = FindMin( T->r );
             T->key = TmpCell->key;
             T->r = del( T->key, T->r );  } /* End if */
         else {  /* One or zero child */
             TmpCell = T;
             if ( T->l == NULL ) /* Also handles 0 child */
                 T = T->r;
             else  if ( T->r == NULL )  T = T->l;
             delete TmpCell;  }  /* End else 1 or 0 child */
      return  T;
}

void AVL::set()
{
    T=NULL;
}

int AVL::QueryH(Pos p)
{
    if(p==NULL) return -1;
    return p->height;
}
Pos AVL::singleL(Pos k2)
{
    Pos k1;
    k1=k2->l;
    k2->l=k1->r;
    k1->r=k2;
    if (QueryH(k2->l)>QueryH(k2->r))	k2->height=QueryH(k2->l)+1;
    else k2->height=QueryH(k2->r)+1;
    if (QueryH(k1->l)>k2->height)	k1->height=QueryH(k1->l)+1;
    else k1->height=k2->height+1;
    return k1;
}
Pos AVL::singleR(Pos k1)
{
    Pos k2;
    k2=k1->r;
    k1->r=k2->l;
    k2->l=k1;
    if (QueryH(k1->l)>QueryH(k1->r))	k1->height=QueryH(k1->l)+1;
    else k1->height=QueryH(k1->r)+1;
    if (QueryH(k2->r)>k1->height)	k2->height=QueryH(k2->r)+1;
    else k2->height=k1->height+1;
    return k2;
}
Pos AVL::doubleL(Pos k3)
{
    k3->l=singleR(k3->l);
    return singleL(k3);
}
Pos AVL::doubleR(Pos k3)
{
    k3->r=singleL(k3->r);
    return singleR(k3);
}
Tree AVL::Insert(int k, Tree T)
{
    if (T==NULL)
    {  T= new TreeNode;
        T->key=k;T->height=0;
        T->l=T->r=NULL;
    }
    else
        if (k<T->key)
        {
            T->l=Insert(k,T->l);
            if (QueryH(T->l)-QueryH(T->r)==2)

                if (k<T->l->key) T=singleL(T);
                else             T=doubleL(T);
        }
        else
            if (k>T->key)
            {
                T->r=Insert(k,T->r);
                if (QueryH(T->r)-QueryH(T->l)==2)
                    if (k>T->r->key) T=singleR(T);
                    else             T=doubleR(T);
            }
    if (QueryH(T->l)>QueryH(T->r)) T->height=QueryH(T->l)+1;
    else T->height=QueryH(T->r)+1;
    return T;
}


void Heap::set()
{
    csize=0;
    return ;
}
void Heap::ins(int num)
{
    int i, j, n;
    n =csize;
    a[n] = num;//num插入堆尾
    i = n;
    j = (n - 1) / 2;//j指向i的父结点

    //注意不要漏掉i!=0的条件。因为必须保证i有父结点j。j>=0并不能保证i!=0。
    //如果没有此条件，当i=0时，j=0,若heap[0]>num,程序就会陷入死循环。
    while (j >= 0 && i != 0)
    {
        if (a[j] <= num)
            break;
        a[i] = a[j];
        i = j;
        j = (i - 1) / 2;
    }
    a[i] = num;
    csize++;
    return ;
}

void Heap::deltop()
{   int n;
    //使用堆尾元素直接覆盖堆顶元素。
    n= csize;
    a[0] = a[n - 1];
    //从堆顶到堆尾(此时堆中只有n-1个元素)进行堆调整。
    adjust( 0, n - 1);
    csize--;
    return ;
}

/*
 * 堆调整算法。(小顶堆)
 * 已知heap[top]结点的左右子树均为堆，调整堆中元素，使以heap[top]为根结点的树为堆。
 * n为堆中元素总数。
 */
void Heap::adjust(int top, int n)
{
    int j = 2 * top + 1;    //左孩子结点
    int temp = a[top];

    while (j < n)
    {
        if (j + 1 < n&&a[j + 1] < a[j])
            j++;    //使j指向左右孩子中较小的结点。
        if (a[j] >= temp)
            break;
        a[top] = a[j];
        top = j;
        j = 2 * top + 1;
    }
    a[top] = temp;
    return ;
}



