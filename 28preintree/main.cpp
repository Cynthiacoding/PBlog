#include <iostream>

using namespace std;
template <class T>
class BinaryTree;
template <class T>
class TreeNode
{
friend class BinaryTree<T>;
public:
    T data;
    TreeNode<T>* lchild;
    TreeNode<T>* rchild;

    TreeNode(T da, TreeNode<T>* l=NULL,TreeNode<T>* r=NULL)
    {
        data=da;
        lchild=l;
        rchild=r;
    }
    bool Isleaf()const;
    void visit(){cout<<"访问："<<this->data<<endl;}

};

//判断是否为叶子结点
template <class T>
 bool TreeNode<T>::Isleaf()const
{
    if(lchild==NULL&&rchild==NULL)
    {
        return true;
    }
    else
        return false;
}

template <class T>
class BinaryTree
{
public:
    TreeNode<T> *root=NULL;

public:
    ~BinaryTree();
    bool IsEmpty();                                 //判断二叉树是否是空树
    void Destroy(TreeNode<T>* p);                   //销毁一颗二叉树
    TreeNode<T>*  getRoot(){return root;}           //返回根节点
    TreeNode<T>*  PostIncreate(T *a,int s1,int e1,T* b,int s2,int e2);     //中序后序创建二叉树
    //递归遍历
    void  PreOrder(TreeNode<T>* root);              //前
    void  PostOrder(TreeNode<T>* root);      //后
     void  PostOrderWithoutRecusion();   //后

};

//析构函数
template <class T>
BinaryTree<T>::~BinaryTree()
{
   Destroy(root);
}
//递归销毁二叉树
template <class T>
void BinaryTree<T>:: Destroy(TreeNode<T>* p)//销毁一颗二叉树
{
    //1.树为空，直接返回，无结点销毁
        if (p==NULL)
        {
            return;
        }
    //2.树只有一个结点，则销毁该节点
        if (p->lchild==NULL&&p->rchild==NULL)
        {
            delete p;
          //  root=NULL;
            return;
        }
    //3.树的结点大于一个，则先销毁左子树，后销毁右子树 递归直到找到叶子结点
        Destroy(p->lchild);
        Destroy(p->rchild);
        delete p;
        //root=NULL;
}

//判断二叉树是否是空树
template <class T>
bool BinaryTree<T>:: IsEmpty()
{
    if(root==NULL)
        return true;
    else
        return false;
}

 //递归遍历
 //左和右是固定好的 根的位置对应提前设定的前中后
template <class T>
void BinaryTree<T>::PreOrder(TreeNode<T>* root)       //前
{

    if(root!=NULL)
    {
        root->visit();
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

template <class T>
void BinaryTree<T>::PostOrder(TreeNode<T>* root)      //后
{
      if(root!=NULL)
    {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        root->visit();
    }
}

//先序中序创建二叉树
template <class T>
TreeNode<T>* PreIncreate(T *a,int s1,int e1,T* b,int s2,int e2)
{
  T rootdata;
  if(s1>e1)
    return NULL;
  else
    rootdata=a[s1];
  //cout<<"rootdata"<<rootdata<<endl;
  TreeNode<T>* r=new TreeNode<T>(rootdata);
  int i=0,leftlen,rightlen;
  for(i=s2;i<=e2;i++)
  {
      if(b[i]==rootdata)
          break;
  }
  leftlen=i-s2;      //左子树：b[S1]`````b[i]
  rightlen=e2-i;     //右子树：b[i+1]`````b[e2]
 // cout<<"i"<<i<<rootdata<<"为根"<<"左子树长度"<<leftlen<<"right子树长度"<<rightlen<<endl;
  if(leftlen>0)
      r->lchild=PreIncreate(a,s1+1,s1+leftlen,b,s2,i-1);
  if(rightlen>0)
     r->rchild=PreIncreate(a,s1+1+leftlen,e1,b,i+1,e2);

    return r;
}


//中序后序创建二叉树
template <class T>
TreeNode<T>* BinaryTree<T>:: PostIncreate(T *c,int s1,int e1,T* b,int s2,int e2)
{
   cout<<"中序后序创建二叉树" <<endl;
   //后序c[s1]~~~c[e1]
   //中序b[s2]~~~b[e2]
  T rootdata;
  if(s1>e1)
    return NULL;
  else
    rootdata=c[e1]; //树段最后一个数值为这棵树根

  TreeNode<T>* r=new TreeNode<T>(rootdata);
  int i=0,leftlen,rightlen;
  //在中序树中找根 将数组分段
  for(i=s2;i<=e2;i++)
  {
      if(b[i]==rootdata)
          break;
  }

  leftlen=i-s2;      //左子树：b[S1]`````b[i]
  rightlen=e2-i;     //右子树：b[i+1]`````b[e2]
 // cout<<"i"<<i<<rootdata<<"为根"<<"左子树长度"<<leftlen<<"right子树长度"<<rightlen<<endl;
  if(leftlen>0)
      r->lchild=PostIncreate(c,s1,s1+leftlen-1,b,s2,i-1);
  if(rightlen>0)
     r->rchild=PostIncreate(c,s1+leftlen,e1-1,b,i+1,e2);

    return r;
}




 int main()
{
   char a[7]={'A','B','C','D','E','F','G'};
   char b[7]={'C','B','D','A','F','G','E'};
   char c[7]={'C','D','B','G','F','E','A'};
/* BinaryTree<char> ctree1;
   ctree1.root=PreIncreate(a,0,6,b,0,6);
   cout<<"后序遍历结果："<<endl;
   ctree1.PostOrder(ctree1.getRoot());*/

   BinaryTree<char> ctree2;
   ctree2.root=ctree2.PostIncreate(c,0,6,b,0,6);
   cout<<"前序遍历结果："<<endl;
   ctree2.PreOrder(ctree2.getRoot());




   return 0;
}

