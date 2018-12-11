#include <iostream>

using namespace std;
template <class T>
class ArrayQueue
{
public:
    int maxSize;    //存放队列数组的大小
    int qfront;     //表示队头所在的位置下标
    int rear;       //表示队尾所在的位置下标
    T * arrqueue ;   //存放类型为T的队列元素的数组

public:
    //构造与析构
    ArrayQueue(int qsize)
    {
        maxSize=qsize+1;            //多出一个空间用来区别队列的空和满
        arrqueue =new T[maxSize];   //为指针划分数组空间
        qfront=rear=0;              //起始设定
    }
    ~ArrayQueue()
    {
        delete [] arrqueue;
    }

    //基础功能函数
    void Clear();                  //清空队列
    bool EnQueue(const T item);    //入队操作 插入队尾
    bool DeQueue(T & ele);         //出队操作 从队头离开
    bool GetFront(T & ele);        //获得队头元素 但是不从队中拿走
    bool IsEmpty();                //判断队列是否为空
    bool IsFull();                 //判断队列是否为满
    int  NumberOfEle();            //返回元素结点个数
    void PrintQueue();             //打印队列

};

//清空队列
template <class T>
void ArrayQueue<T>::Clear()
{
    qfront=rear;
}

//入队操作 插入队尾
template <class T>
bool ArrayQueue<T>::EnQueue(const T item)
{
    if((rear+1)%maxSize==qfront)
    {
        cout<<"队列已满，不允许继续插入元素了"<<endl;
        return false;
    }
    arrqueue[rear]=item;   //如果没满 直接插入队尾
    rear=(rear+1)%maxSize; //队尾位置后移
    return true;
}

//出队操作 从队头离开
template <class T>
bool ArrayQueue<T>::DeQueue(T & ele)
{
    if(qfront==rear)
    {
        cout<<"队列为空！"<<endl;
        return false;
    }
    ele=arrqueue[qfront];
    qfront=(qfront+1)%maxSize;
   // cout<<"出队列元素为"<<ele;
    return true;
}

//获得队头元素 但是不从队中拿走
template <class T>
bool ArrayQueue<T>:: GetFront(T & ele)
{
    if(qfront==rear)
    {
        cout<<"队列为空！"<<endl;
        return false;
    }
    ele=arrqueue[qfront];
    return true;

}

//判断队列是否为空
template <class T>
bool ArrayQueue<T>::IsEmpty()
{
    if(qfront==rear)
    {
    //cout<<"队列为空！"<<endl;
        return true;
    }
    else
        return false;
}

//判断队列是否为满
template <class T>
bool ArrayQueue<T>::IsFull()
{
    if((rear+1)%maxSize==qfront)
    {
        cout<<"队列已满"<<endl;
        return true;
    }
    else
        return false;
}
 //返回元素结点个数
template <class T>
int ArrayQueue<T>::NumberOfEle()
{
    return (rear - qfront + maxSize ) % maxSize;
}

 //打印队列
template <class T>
void ArrayQueue<T>::PrintQueue()             //打印队列
{
    cout<<"队列元素："<<endl;
    for(int i=qfront%maxSize;i<rear%maxSize;i++)
    {
        cout<<arrqueue[i]<<" ";
    }
    cout<<endl;
}

//--------------------------------------------------------------
//--------------------------------------------------------------

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

    //判断树是不是完全二叉树
    /*完全二叉树定义：除了最后一层以外其他所有层结点数都达到了最大值 而最后一层的结点分布在左侧*/
    bool IsComplete();

};

//构造函数
template <class T>
BinaryTree<T>::BinaryTree()
{
    root=new TreeNode<T>(0);
    //特定形态 固定构造
    root=this->create();
}
//二叉树的建立

template <class T>
TreeNode<T>* BinaryTree<T>::create()               //创建一个特定的二叉树
 {

     /*  root->data='A';
      root->lchild=new TreeNode<T>('B');
      root->rchild=new TreeNode<T>('C');
      root->lchild->rchild=new TreeNode<T>('D');
      root->rchild->rchild=new TreeNode<T>('E');
      root->lchild->rchild->lchild=new TreeNode<T>('F');
      root->lchild->rchild->rchild=new TreeNode<T>('G');
      root->rchild->rchild->rchild=new TreeNode<T>('H');*/
      root->data='A';
      root->lchild=new TreeNode<T>('B');
      root->rchild=new TreeNode<T>('C');
      root->lchild->lchild=new TreeNode<T>('D');
      root->lchild->rchild=new TreeNode<T>('E');

      return root;
 }

//析构函数
template <class T>
BinaryTree<T>::~BinaryTree()
{
    Destroy(root);
}
//递归销毁二叉树
template <class T>
void BinaryTree<T>:: Destroy(TreeNode<T>* cur)//销毁一颗二叉树
{
	if (cur)			//该根节点非空
	{
	//	cout << p->data << endl;
		TreeNode<T>* Left_Tree= cur->lchild;
		TreeNode<T>* Right_Tree= cur->rchild;
		delete cur;
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

//判断二叉树是否是完全二叉树
//度为1的结点的儿子就该结束了 找到度为1的点后 后续都应该是叶子结点
/*
template <class T>
bool BinaryTree<T>:: IsComplete()
{
    ArrayQueue<TreeNode<T>*> NodeQueue(10);  //用队列来存放结点的指针
    TreeNode<T>* pointer;
    pointer=root;
     if(pointer)
        NodeQueue.EnQueue(pointer);
    //开始处理队列
     while(!NodeQueue.IsEmpty())
    {
        NodeQueue.DeQueue(pointer);          //让访问过的根出队
        cout<<pointer->data<<endl;
        //只有右孩子没有左孩子肯定不对
     if((pointer->lchild==NULL&&pointer->rchild!=NULL))
     {
         return false;
     }
      if(pointer->lchild)
        NodeQueue.EnQueue(pointer->lchild);
      if(pointer->rchild)
        NodeQueue.EnQueue(pointer->rchild);
      //如果poiter是只有左孩子的点或者干脆就是叶子结点
      //那么在她之后的点（此时队列中存储的元素）都应该是叶子结点
       if((pointer->lchild!=NULL&&pointer->rchild==NULL)||(pointer->lchild==NULL&&pointer->rchild==NULL))
        {
             break;
        }
    }
    //检测栈中剩下的元素是不是都是叶子结点
    while(!NodeQueue.IsEmpty())
    {
        NodeQueue.GetFront(pointer);
      //如果不是叶子结点
        if(pointer->lchild!=NULL||pointer->rchild!=NULL)
            return false;
        else
        NodeQueue.DeQueue(pointer);
    }
    if(NodeQueue.IsEmpty())
        return true;
    return false;
}
*/

template <class T>
bool BinaryTree<T>:: IsComplete()
{
    ArrayQueue<TreeNode<T>*> aque(10);
    int temp,width;
    temp=0;
    width=0;
    TreeNode<T>* pointer;
    pointer=root;
    if(pointer)
    {
        aque.EnQueue(pointer);
        temp++;
        aque.EnQueue(NULL);
    }
    while(!aque.IsEmpty())
    {
        aque.DeQueue(pointer);
        if(pointer==NULL)
        {
            width=temp;
            temp=0;
            aque.EnQueue(pointer);
            continue;
        }
        if(pointer->lchild==NULL&&pointer->rchild!=NULL)
            return false;
        if(pointer->lchild)
        {
             aque.EnQueue(pointer->lchild);
             temp++;
        }
        if(pointer->rchild)
        {
            aque.EnQueue(pointer->rchild);
            temp++;
        }
        if((pointer->lchild!=NULL&&pointer->rchild==NULL)||pointer->Isleaf())
            {
                break;
            }
    }
     while(!aque.IsEmpty())
     {
          aque.DeQueue(pointer);
         // cout<<pointer->data<<endl;
         if(pointer==NULL)
            continue;
          if(!pointer->Isleaf())
            break;
     }
     if(aque.IsEmpty())
     {
         cout<<width<<endl;
         return true;
     }
     cout<<width<<endl;
     return false;
}




















 int main()
 {
   BinaryTree<char> btree;
   if(btree.IsComplete())
    cout<<"是完全二叉树"<<endl;
   else
    cout<<"不是完全二叉树"<<endl;
   return 0;
 }

