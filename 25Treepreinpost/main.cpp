#include <iostream>

using namespace std;

//对于任意二叉树的三种不同的深度优先遍历
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
    TreeNode<T>*  getRoot(){return root;}       //返回根节点
    TreeNode<T>*  create();                         //创建一个特定的二叉树
    //递归遍历
    void  PreOrder(TreeNode<T>* root);       //前
    void  InOrder(TreeNode<T>* root);        //中
    void  PostOrder(TreeNode<T>* root);      //后
    //非递归遍历
    void  PreOrderWithoutRecusion();    //前
    void  InOrderWithoutRecusion();     //中
    void  PostOrderWithoutRecusion();   //后


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
   // Destroy(root);
   // root=NULL;
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

//二叉树的建立，按前序遍历的方式建立二叉树，当然也可以以中序或后序的方式建立二叉树

template <class T>
TreeNode<T>* BinaryTree<T>::create()               //创建一个特定的二叉树
 {
   /* TreeNode<T>* cur;
    T ch;
    cin>>ch;
    if(ch == 0)     //如果到了叶子节点，接下来的左、右子树分别赋值为0
    {
        cur = NULL;
    }
    else
    {
        cur = new TreeNode<T>(ch);
        cur->lchild = create();  //递归创建左子树
        cur->rchild = create();  //递归创建右子树
    }
    return cur;*/
      root->data='A';
      root->lchild=new TreeNode<T>('B');
      root->rchild=new TreeNode<T>('C');
      root->lchild->rchild=new TreeNode<T>('D');
      root->rchild->rchild=new TreeNode<T>('E');
      root->lchild->rchild->lchild=new TreeNode<T>('F');
      root->lchild->rchild->rchild=new TreeNode<T>('G');
      root->rchild->rchild->rchild=new TreeNode<T>('H');
      return root;

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
void BinaryTree<T>::InOrder(TreeNode<T>* root)        //中
{
    cout<<"中序遍历结果："<<endl;
        if(root!=NULL)
    {
        PreOrder(root->lchild);
        root->visit();
        PreOrder(root->rchild);
    }
}

template <class T>
void BinaryTree<T>::PostOrder(TreeNode<T>* root)      //后
{
    cout<<"后序遍历结果："<<endl;
        if(root!=NULL)
    {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        root->visit();
    }
}



//非递归遍历
template <class T>
void BinaryTree<T>:: PreOrderWithoutRecusion()    //前 根左右
{
     cout<<"前序遍历结果："<<endl;
     ArrayStack<TreeNode<T>*> st(20);
     TreeNode <T>*pointer=root;
     while(!st.IsEmpty()||pointer)
     {
       if(pointer)
      {
         pointer->visit();      //访问节点
         //只有右孩子有东西的时候 这个根节点的右孩子才值得被保留下来
         if(pointer->rchild!=NULL)
         {
            st.Push(pointer->rchild);      //把根节点的右结点压入栈中
         }
         pointer=pointer->lchild;  //转而研究左子树
      }
     //此时左子树就访问完了 将原来压好的最近的被压入的右子树根 弹出栈 再对这个小树进行分析
       else
      {
          st.Pop(pointer);
      }
     }
}




/*
每遇到一个结点就把它压栈，然后去遍历其左子树

遍历完左子树后，从栈顶托出这个结点（根）并访问之

根之后是右 往右孩子走一步 再去遍历该结点的右子树

*/
//左 中 右
template <class T>
void BinaryTree<T>:: InOrderWithoutRecusion()     //中
{
     cout<<"中序遍历结果："<<endl;
     ArrayStack<TreeNode<T>*> st(20);
     TreeNode <T>*pointer=root;
     while(!st.IsEmpty()||pointer)
     {
         if(pointer)
         {
             //将树根先压入栈
             st.Push(pointer);
             //访问左子树
             pointer=pointer->lchild;
         }
         else
            {
                 st.Top(pointer);
                 pointer->visit();
                 st.Pop(pointer);
                 pointer=pointer->rchild;
            }
     }
}
/*
每遇到一个结点，先把它推入栈中，去遍历它的左子树

遍历完它的左子树后，应继续遍历该结点的右子树

遍历完右子树之后，才从栈顶托出该结点并访问它

*/




template <class T>
void BinaryTree<T>:: PostOrderWithoutRecusion()   //后
{
    cout<<"后序遍历结果："<<endl;
     ArrayStack<TreeNode<T>*> st(20);
     TreeNode <T>*pointer;
     TreeNode <T>*pre;
     pre=pointer=root;

     while(pointer)
     {
         //第一步向左边持续搜索 将左边有孩子的根都压入栈中
          while(pointer->lchild!=NULL)
        {
      //      cout<<"!!!!!!!!!!!!!!!1"<<endl;
                st.Push(pointer);
                pointer=pointer->lchild;
        }
        //此时存在左孩子的树根已经存入栈了


        //当结点没有右孩子 或者右边的孩子被访问过了的话
        //对根的访问 以及和一个子树彻底说再见
            while(pointer!=NULL&&(pointer->rchild==NULL||pointer->rchild==pre))
        {
         //  cout<<"22222222222222222"<<endl;
            pointer->visit();   //可以访问它了
            pre=pointer;        //记住刚刚被访问元素的位置
            if(st.IsEmpty())    //这个时候栈为空 就证明 就一个结点 可以跑路了
                return;
            st.Pop(pointer);    //访问都访问完了 要新的元素 拿走栈顶 获取新的元素
        }

        //存根 向右侧访问
       //  cout<<"333333333333333333333"<<endl;
            st.Push(pointer);
            pointer=pointer->rchild; //转向右子树
     }


}

 int main()
 {
   BinaryTree<char> btree;
   cout<<"前序遍历结果："<<endl;   btree.PreOrderWithoutRecusion();
   btree.InOrderWithoutRecusion();
   btree.PostOrderWithoutRecusion();



   return 0;
 }

