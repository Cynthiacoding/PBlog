#include <iostream>

using namespace std;
int m=-100;
int b[10]={0,0,0,0,0,0,0,0,0,0};
//----------利用栈的定义--------------------
template <class T>
class ArrayStack
{
private:
	int Maxsize;        //栈的最大值
	int top;            //栈顶 （这里设置它的位置就是最顶元素的位置）
	T *st;              //存放栈的数组

public:
	//有参
	ArrayStack(int s)
	{
		Maxsize = s;
		top = -1;
		st = new T[Maxsize];
	}

	ArrayStack() { top = -1; }     //无参
	~ArrayStack() { delete[]st; } //析构


	//功能函数
	void Clear();                    //清空栈
	bool Push(const T ele);          //元素入栈
	bool Pop(T &ele);                //元素出栈 并删除这个元素
	bool Top(T &ele);               //元素出栈 但是不删除它
	bool IsEmpty();                  //判断栈是否为空
    void Print();                    //打印栈

};

//清空栈
template <class T>
void ArrayStack<T>::Clear()
{
	top = -1;
}

//元素入栈
template <class T>
bool ArrayStack<T>::Push(const T ele)
{
	if (top == Maxsize - 1)
	{
		cout << "栈已满！无法进行元素入栈操作！" << endl;
		return false;
	}
	//
	top++;
	st[top] = ele;
	return true;
}



//元素出栈 并删除这个元素
template <class T>
bool ArrayStack<T>::Pop(T &ele)
{
	if (top == -1)
	{
		cout << "此栈为空栈，无法进行元素出栈操作" << endl;
		return false;
	}
	ele = st[top];
	top--;

	return true;
}


//元素出栈 但是不删除它
template <class T>
bool ArrayStack<T>::Top(T &ele)
{
	if (top == -1)
	{
		cout << "此栈为空栈，无法进行元素出栈操作" << endl;
		return false;
	}
	ele = st[top];
	return true;
}


//判断栈是否为空
template <class T>
bool ArrayStack<T>::IsEmpty()
{
	if (top == -1)
	{
	//	cout << "空栈" << endl;
		return true;
	}
	return false;
}


template <class T>
void ArrayStack<T>::Print()
{
	if (top == -1)
	{
		cout << "空栈" << endl;
		return;
	}
	for (int i = 0; i <= top; i++)
	{
		cout << st[i] << "  ";
	}
	cout << endl;
	cout << "栈顶元素是：" << st[top] << endl;
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

//二叉树——二叉链表 写相关递归算法



template <class T>
class BinaryTree
{
private:
    TreeNode<T> *root;

public:
    BinaryTree();
    ~BinaryTree();
    bool IsEmpty();                                 //判断二叉树是否是空树
    void Destroy(TreeNode<T>* p);                   //销毁一颗二叉树
    TreeNode<T>*  getRoot(){return root;}           //返回根节点
    TreeNode<T>*  create();                         //创建一个特定的二叉树
    void PreOrder(TreeNode<T>* root);                //前序遍历

    //度为0 1 2
    int NumofNochild(TreeNode<T> * cur);
    int NumofOnechild(TreeNode<T> * cur);
    int NumofTwochild(TreeNode<T> * cur);
    //统计二叉树的高度
    int Height(TreeNode<T> * cur);

    //统计二叉树的宽度
   int  Width(TreeNode<T> * cur,int s);

    //统计二叉树的各个结点中最大元素的值
    T Max(TreeNode<T> * cur);

    //交换每个节点的左孩子和右孩子
    void Swapchild(TreeNode<T> * cur);

    //删去所有的叶子结点
    TreeNode<T>*  DeleteLeaf(TreeNode<T> * cur);

};

//构造函数
template <class T>
BinaryTree<T>::BinaryTree()
{
    root=new TreeNode<T>(0);
    //特定形态 固定构造
    root=this->create();
}
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
	if (p)			//该根节点非空
	{
	//	cout << p->data << endl;
		TreeNode<T>* Left_Tree= p->lchild;
		TreeNode<T>* Right_Tree= p->rchild;
		delete p;
		if (Left_Tree)			//左子树非空则释放
			Destroy(Left_Tree);
		if (Right_Tree)			//右
			Destroy(Right_Tree);
	}
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

//二叉树的建立，按前序遍历的方式建立二叉树，当然也可以以中序或后序的方式建立二叉树

template <class T>
TreeNode<T>* BinaryTree<T>::create()               //创建一个特定的二叉树
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

 //前序遍历函数
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

//返回叶子结点个数
template <class T>
int BinaryTree<T>:: NumofNochild(TreeNode<T> * cur)
{
    if(cur==NULL)
        return 0;
    if(cur->lchild==NULL&&cur->rchild==NULL)
        return 1;
    return NumofNochild(cur->lchild)+NumofNochild(cur->rchild);
}

//返回度为1结点个数
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

     //方法2
    /* int num=(cur->lchild==NULL&&cur->rchild!=NULL)||(cur->lchild!=NULL&&cur->rchild==NULL);
     return NumofOnechild(cur->lchild)+NumofOnechild(cur->rchild)+num;*/
}
//返回度为2结点个数
template <class T>
int BinaryTree<T>:: NumofTwochild(TreeNode<T> * cur)
{
     if(cur==NULL)
        return 0;
      //用1表示结果成立
     int num=cur->rchild!=NULL&&cur->lchild!=NULL;
     return NumofTwochild(cur->lchild)+NumofTwochild(cur->rchild)+num;
}


//统计二叉树的高度
//递归思路理解：
/*
Height（ptr）函数可以求出以ptr为根节点的子树的高度
从根节点开始，怎么表示这棵树的高度？根节点一层，左右子树，谁层数多，当然加上谁的啦
所以 return 1 + max(height(llink),height(rlink))；
最后什么时候返回？当然是节点为空的时候啦，因为一个叶子节点已经是最后一层，它的左右节点
都是空的
*/
template <class T>
int BinaryTree<T>::Height(TreeNode<T> * cur)
{
    if(cur==NULL)
        return 0;
    return (Height(cur->lchild)>Height(cur->rchild)?Height(cur->lchild):Height(cur->rchild))+1;
}


//统计二叉树的宽度
template <class T>
int BinaryTree<T>::Width(TreeNode<T> * cur,int s)
{
    if(cur==NULL)return 0;
    //s表示层数
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

//统计二叉树的各个结点中最大元素的值
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

//交换每个节点的左孩子和右孩子
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

//删除叶子结点
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

    //让原来本来指向叶子节点的指针指向NULL
    if (cur == NULL || ( cur->lchild == NULL && cur->rchild == NULL ))
        return NULL;
    cur->lchild = DeleteLeaf(cur->lchild);
    cur->rchild = DeleteLeaf(cur->rchild);
    return cur;

}

 int main()
 {
   BinaryTree<char> btree;
   cout<<"度为0结点个数："<<btree.NumofNochild(btree.getRoot())<<endl;
   cout<<"度为1结点个数："<<btree.NumofOnechild(btree.getRoot())<<endl;
   cout<<"度为2结点个数："<<btree.NumofTwochild(btree.getRoot())<<endl;
   cout<<"二叉树的高度："<<btree.Height(btree.getRoot())<<endl;
   cout<<"二叉树的宽度："<<btree.Width(btree.getRoot(),0)<<endl;
   cout<<"二叉树的最大值："<<btree.Max(btree.getRoot())<<endl;


   cout<<"原来前序遍历结果："<<endl;
   btree.PreOrder(btree.getRoot());
 /*  btree.Swapchild(btree.getRoot());
   cout<<"经过交换，前序遍历结果："<<endl;
   btree.PreOrder(btree.getRoot());
   */

   btree.DeleteLeaf(btree.getRoot());
   cout<<"删除叶子结点，前序遍历结果："<<endl;
   btree.PreOrder(btree.getRoot());

   return 0;
 }

