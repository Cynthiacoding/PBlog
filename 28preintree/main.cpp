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
    void visit(){cout<<"���ʣ�"<<this->data<<endl;}

};

//�ж��Ƿ�ΪҶ�ӽ��
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
    bool IsEmpty();                                 //�ж϶������Ƿ��ǿ���
    void Destroy(TreeNode<T>* p);                   //����һ�Ŷ�����
    TreeNode<T>*  getRoot(){return root;}           //���ظ��ڵ�
    TreeNode<T>*  PostIncreate(T *a,int s1,int e1,T* b,int s2,int e2);     //������򴴽�������
    //�ݹ����
    void  PreOrder(TreeNode<T>* root);              //ǰ
    void  PostOrder(TreeNode<T>* root);      //��
     void  PostOrderWithoutRecusion();   //��

};

//��������
template <class T>
BinaryTree<T>::~BinaryTree()
{
   Destroy(root);
}
//�ݹ����ٶ�����
template <class T>
void BinaryTree<T>:: Destroy(TreeNode<T>* p)//����һ�Ŷ�����
{
    //1.��Ϊ�գ�ֱ�ӷ��أ��޽������
        if (p==NULL)
        {
            return;
        }
    //2.��ֻ��һ����㣬�����ٸýڵ�
        if (p->lchild==NULL&&p->rchild==NULL)
        {
            delete p;
          //  root=NULL;
            return;
        }
    //3.���Ľ�����һ�������������������������������� �ݹ�ֱ���ҵ�Ҷ�ӽ��
        Destroy(p->lchild);
        Destroy(p->rchild);
        delete p;
        //root=NULL;
}

//�ж϶������Ƿ��ǿ���
template <class T>
bool BinaryTree<T>:: IsEmpty()
{
    if(root==NULL)
        return true;
    else
        return false;
}

 //�ݹ����
 //������ǹ̶��õ� ����λ�ö�Ӧ��ǰ�趨��ǰ�к�
template <class T>
void BinaryTree<T>::PreOrder(TreeNode<T>* root)       //ǰ
{

    if(root!=NULL)
    {
        root->visit();
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

template <class T>
void BinaryTree<T>::PostOrder(TreeNode<T>* root)      //��
{
      if(root!=NULL)
    {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        root->visit();
    }
}

//�������򴴽�������
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
  leftlen=i-s2;      //��������b[S1]`````b[i]
  rightlen=e2-i;     //��������b[i+1]`````b[e2]
 // cout<<"i"<<i<<rootdata<<"Ϊ��"<<"����������"<<leftlen<<"right��������"<<rightlen<<endl;
  if(leftlen>0)
      r->lchild=PreIncreate(a,s1+1,s1+leftlen,b,s2,i-1);
  if(rightlen>0)
     r->rchild=PreIncreate(a,s1+1+leftlen,e1,b,i+1,e2);

    return r;
}


//������򴴽�������
template <class T>
TreeNode<T>* BinaryTree<T>:: PostIncreate(T *c,int s1,int e1,T* b,int s2,int e2)
{
   cout<<"������򴴽�������" <<endl;
   //����c[s1]~~~c[e1]
   //����b[s2]~~~b[e2]
  T rootdata;
  if(s1>e1)
    return NULL;
  else
    rootdata=c[e1]; //�������һ����ֵΪ�������

  TreeNode<T>* r=new TreeNode<T>(rootdata);
  int i=0,leftlen,rightlen;
  //�����������Ҹ� ������ֶ�
  for(i=s2;i<=e2;i++)
  {
      if(b[i]==rootdata)
          break;
  }

  leftlen=i-s2;      //��������b[S1]`````b[i]
  rightlen=e2-i;     //��������b[i+1]`````b[e2]
 // cout<<"i"<<i<<rootdata<<"Ϊ��"<<"����������"<<leftlen<<"right��������"<<rightlen<<endl;
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
   cout<<"������������"<<endl;
   ctree1.PostOrder(ctree1.getRoot());*/

   BinaryTree<char> ctree2;
   ctree2.root=ctree2.PostIncreate(c,0,6,b,0,6);
   cout<<"ǰ����������"<<endl;
   ctree2.PreOrder(ctree2.getRoot());




   return 0;
}

