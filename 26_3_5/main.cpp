#include <iostream>

using namespace std;
int m=-100;
int b[10]={0,0,0,0,0,0,0,0,0,0};
//----------����ջ�Ķ���--------------------
template <class T>
class ArrayStack
{
private:
	int Maxsize;        //ջ�����ֵ
	int top;            //ջ�� ��������������λ�þ����Ԫ�ص�λ�ã�
	T *st;              //���ջ������

public:
	//�в�
	ArrayStack(int s)
	{
		Maxsize = s;
		top = -1;
		st = new T[Maxsize];
	}

	ArrayStack() { top = -1; }     //�޲�
	~ArrayStack() { delete[]st; } //����


	//���ܺ���
	void Clear();                    //���ջ
	bool Push(const T ele);          //Ԫ����ջ
	bool Pop(T &ele);                //Ԫ�س�ջ ��ɾ�����Ԫ��
	bool Top(T &ele);               //Ԫ�س�ջ ���ǲ�ɾ����
	bool IsEmpty();                  //�ж�ջ�Ƿ�Ϊ��
    void Print();                    //��ӡջ

};

//���ջ
template <class T>
void ArrayStack<T>::Clear()
{
	top = -1;
}

//Ԫ����ջ
template <class T>
bool ArrayStack<T>::Push(const T ele)
{
	if (top == Maxsize - 1)
	{
		cout << "ջ�������޷�����Ԫ����ջ������" << endl;
		return false;
	}
	//
	top++;
	st[top] = ele;
	return true;
}



//Ԫ�س�ջ ��ɾ�����Ԫ��
template <class T>
bool ArrayStack<T>::Pop(T &ele)
{
	if (top == -1)
	{
		cout << "��ջΪ��ջ���޷�����Ԫ�س�ջ����" << endl;
		return false;
	}
	ele = st[top];
	top--;

	return true;
}


//Ԫ�س�ջ ���ǲ�ɾ����
template <class T>
bool ArrayStack<T>::Top(T &ele)
{
	if (top == -1)
	{
		cout << "��ջΪ��ջ���޷�����Ԫ�س�ջ����" << endl;
		return false;
	}
	ele = st[top];
	return true;
}


//�ж�ջ�Ƿ�Ϊ��
template <class T>
bool ArrayStack<T>::IsEmpty()
{
	if (top == -1)
	{
	//	cout << "��ջ" << endl;
		return true;
	}
	return false;
}


template <class T>
void ArrayStack<T>::Print()
{
	if (top == -1)
	{
		cout << "��ջ" << endl;
		return;
	}
	for (int i = 0; i <= top; i++)
	{
		cout << st[i] << "  ";
	}
	cout << endl;
	cout << "ջ��Ԫ���ǣ�" << st[top] << endl;
}
//--------------------------------------------------------
//--------------------------------------------------------
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

//������������������ д��صݹ��㷨



template <class T>
class BinaryTree
{
private:
    TreeNode<T> *root;

public:
    BinaryTree();
    ~BinaryTree();
    bool IsEmpty();                                 //�ж϶������Ƿ��ǿ���
    void Destroy(TreeNode<T>* p);                   //����һ�Ŷ�����
    TreeNode<T>*  getRoot(){return root;}           //���ظ��ڵ�
    TreeNode<T>*  create();                         //����һ���ض��Ķ�����
    void PreOrder(TreeNode<T>* root);                //ǰ�����

    //��Ϊ0 1 2
    int NumofNochild(TreeNode<T> * cur);
    int NumofOnechild(TreeNode<T> * cur);
    int NumofTwochild(TreeNode<T> * cur);
    //ͳ�ƶ������ĸ߶�
    int Height(TreeNode<T> * cur);

    //ͳ�ƶ������Ŀ��
   int  Width(TreeNode<T> * cur,int s);

    //ͳ�ƶ������ĸ�����������Ԫ�ص�ֵ
    T Max(TreeNode<T> * cur);

    //����ÿ���ڵ�����Ӻ��Һ���
    void Swapchild(TreeNode<T> * cur);

    //ɾȥ���е�Ҷ�ӽ��
    TreeNode<T>*  DeleteLeaf(TreeNode<T> * cur);

};

//���캯��
template <class T>
BinaryTree<T>::BinaryTree()
{
    root=new TreeNode<T>(0);
    //�ض���̬ �̶�����
    root=this->create();
}
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
	if (p)			//�ø��ڵ�ǿ�
	{
	//	cout << p->data << endl;
		TreeNode<T>* Left_Tree= p->lchild;
		TreeNode<T>* Right_Tree= p->rchild;
		delete p;
		if (Left_Tree)			//�������ǿ����ͷ�
			Destroy(Left_Tree);
		if (Right_Tree)			//��
			Destroy(Right_Tree);
	}
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

//�������Ľ�������ǰ������ķ�ʽ��������������ȻҲ��������������ķ�ʽ����������

template <class T>
TreeNode<T>* BinaryTree<T>::create()               //����һ���ض��Ķ�����
 {
      root->data='A';
      root->lchild=new TreeNode<T>('B');
      root->rchild=new TreeNode<T>('C');
      root->lchild->rchild=new TreeNode<T>('D');
      root->rchild->rchild=new TreeNode<T>('E');
      root->lchild->rchild->lchild=new TreeNode<T>('F');
      root->lchild->rchild->rchild=new TreeNode<T>('G');
    //root->rchild->rchild->lchild=new TreeNode<T>('W');
      root->rchild->rchild->rchild=new TreeNode<T>('H');
      return root;
 }

 //ǰ���������
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

//����Ҷ�ӽ�����
template <class T>
int BinaryTree<T>:: NumofNochild(TreeNode<T> * cur)
{
    if(cur==NULL)
        return 0;
    if(cur->lchild==NULL&&cur->rchild==NULL)
        return 1;
    return NumofNochild(cur->lchild)+NumofNochild(cur->rchild);
}

//���ض�Ϊ1������
template <class T>
int BinaryTree<T>:: NumofOnechild(TreeNode<T> * cur)
{
    if(cur==NULL)
    return 0;
    if((cur->lchild==NULL&&cur->rchild!=NULL)||(cur->lchild!=NULL&&cur->rchild==NULL))
    {
        return NumofOnechild(cur->lchild)+NumofOnechild(cur->rchild)+1;
    }
     return NumofOnechild(cur->lchild)+NumofOnechild(cur->rchild);

     //����2
    /* int num=(cur->lchild==NULL&&cur->rchild!=NULL)||(cur->lchild!=NULL&&cur->rchild==NULL);
     return NumofOnechild(cur->lchild)+NumofOnechild(cur->rchild)+num;*/
}
//���ض�Ϊ2������
template <class T>
int BinaryTree<T>:: NumofTwochild(TreeNode<T> * cur)
{
     if(cur==NULL)
        return 0;
      //��1��ʾ�������
     int num=cur->rchild!=NULL&&cur->lchild!=NULL;
     return NumofTwochild(cur->lchild)+NumofTwochild(cur->rchild)+num;
}


//ͳ�ƶ������ĸ߶�
//�ݹ�˼·��⣺
/*
Height��ptr���������������ptrΪ���ڵ�������ĸ߶�
�Ӹ��ڵ㿪ʼ����ô��ʾ������ĸ߶ȣ����ڵ�һ�㣬����������˭�����࣬��Ȼ����˭����
���� return 1 + max(height(llink),height(rlink))��
���ʲôʱ�򷵻أ���Ȼ�ǽڵ�Ϊ�յ�ʱ��������Ϊһ��Ҷ�ӽڵ��Ѿ������һ�㣬�������ҽڵ�
���ǿյ�
*/
template <class T>
int BinaryTree<T>::Height(TreeNode<T> * cur)
{
    if(cur==NULL)
        return 0;
    return (Height(cur->lchild)>Height(cur->rchild)?Height(cur->lchild):Height(cur->rchild))+1;
}


//ͳ�ƶ������Ŀ��
template <class T>
int BinaryTree<T>::Width(TreeNode<T> * cur,int s)
{
    if(cur==NULL)return 0;
    //s��ʾ����
	b[s]++;
	Width(cur->lchild,s+1);
	Width(cur->rchild,s+1);
    int width=0;
    for(int i=0;i<=Height(root);i++)
    {
	  width=width>b[i]?width:b[i];
    }
    return width;
}

//ͳ�ƶ������ĸ�����������Ԫ�ص�ֵ
template <class T>
T BinaryTree<T>::Max(TreeNode<T> * cur)
{
    if(!cur)
      return 0;
    if(cur->data>m)
      m=cur->data;
    Max(cur->lchild);
    Max(cur->rchild);
    return m;
}

//����ÿ���ڵ�����Ӻ��Һ���
template <class T>
void BinaryTree<T>::Swapchild(TreeNode<T> * cur)
{
    TreeNode <T>* temp;
    if(cur)
    {
        temp=cur->lchild;
        cur->lchild=cur->rchild;
        cur->rchild=temp;
    }
    else
    {
        return;
    }
    Swapchild(cur->lchild);
    Swapchild(cur->rchild);
}

//ɾ��Ҷ�ӽ��
template <class T>
TreeNode<T>* BinaryTree<T>::DeleteLeaf(TreeNode<T> * cur)
{

  /*   if(cur->lchild!=NULL)
       DeleteLeaf(cur->lchild);
   if(cur->rchild!=NULL)
       DeleteLeaf(cur->rchild);
   if(cur==NULL)
       return cur;
   if(cur->lchild==NULL&&cur->rchild==NULL)
   {
       cout<<"!!"<<endl;
       cur=NULL;
   }*/

    //��ԭ������ָ��Ҷ�ӽڵ��ָ��ָ��NULL
    if (cur == NULL || ( cur->lchild == NULL && cur->rchild == NULL ))
        return NULL;
    cur->lchild = DeleteLeaf(cur->lchild);
    cur->rchild = DeleteLeaf(cur->rchild);
    return cur;

}

 int main()
 {
   BinaryTree<char> btree;
   cout<<"��Ϊ0��������"<<btree.NumofNochild(btree.getRoot())<<endl;
   cout<<"��Ϊ1��������"<<btree.NumofOnechild(btree.getRoot())<<endl;
   cout<<"��Ϊ2��������"<<btree.NumofTwochild(btree.getRoot())<<endl;
   cout<<"�������ĸ߶ȣ�"<<btree.Height(btree.getRoot())<<endl;
   cout<<"�������Ŀ�ȣ�"<<btree.Width(btree.getRoot(),0)<<endl;
   cout<<"�����������ֵ��"<<btree.Max(btree.getRoot())<<endl;


   cout<<"ԭ��ǰ����������"<<endl;
   btree.PreOrder(btree.getRoot());
 /*  btree.Swapchild(btree.getRoot());
   cout<<"����������ǰ����������"<<endl;
   btree.PreOrder(btree.getRoot());
   */

   btree.DeleteLeaf(btree.getRoot());
   cout<<"ɾ��Ҷ�ӽ�㣬ǰ����������"<<endl;
   btree.PreOrder(btree.getRoot());

   return 0;
 }

