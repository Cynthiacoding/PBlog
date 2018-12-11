#include <iostream>

using namespace std;
template <class T>
class ArrayQueue
{
public:
    int maxSize;    //��Ŷ�������Ĵ�С
    int qfront;     //��ʾ��ͷ���ڵ�λ���±�
    int rear;       //��ʾ��β���ڵ�λ���±�
    T * arrqueue ;   //�������ΪT�Ķ���Ԫ�ص�����

public:
    //����������
    ArrayQueue(int qsize)
    {
        maxSize=qsize+1;            //���һ���ռ�����������еĿպ���
        arrqueue =new T[maxSize];   //Ϊָ�뻮������ռ�
        qfront=rear=0;              //��ʼ�趨
    }
    ~ArrayQueue()
    {
        delete [] arrqueue;
    }

    //�������ܺ���
    void Clear();                  //��ն���
    bool EnQueue(const T item);    //��Ӳ��� �����β
    bool DeQueue(T & ele);         //���Ӳ��� �Ӷ�ͷ�뿪
    bool GetFront(T & ele);        //��ö�ͷԪ�� ���ǲ��Ӷ�������
    bool IsEmpty();                //�ж϶����Ƿ�Ϊ��
    bool IsFull();                 //�ж϶����Ƿ�Ϊ��
    int  NumberOfEle();            //����Ԫ�ؽ�����
    void PrintQueue();             //��ӡ����

};

//��ն���
template <class T>
void ArrayQueue<T>::Clear()
{
    qfront=rear;
}

//��Ӳ��� �����β
template <class T>
bool ArrayQueue<T>::EnQueue(const T item)
{
    if((rear+1)%maxSize==qfront)
    {
        cout<<"�����������������������Ԫ����"<<endl;
        return false;
    }
    arrqueue[rear]=item;   //���û�� ֱ�Ӳ����β
    rear=(rear+1)%maxSize; //��βλ�ú���
    return true;
}

//���Ӳ��� �Ӷ�ͷ�뿪
template <class T>
bool ArrayQueue<T>::DeQueue(T & ele)
{
    if(qfront==rear)
    {
        cout<<"����Ϊ�գ�"<<endl;
        return false;
    }
    ele=arrqueue[qfront];
    qfront=(qfront+1)%maxSize;
   // cout<<"������Ԫ��Ϊ"<<ele;
    return true;
}

//��ö�ͷԪ�� ���ǲ��Ӷ�������
template <class T>
bool ArrayQueue<T>:: GetFront(T & ele)
{
    if(qfront==rear)
    {
        cout<<"����Ϊ�գ�"<<endl;
        return false;
    }
    ele=arrqueue[qfront];
    return true;

}

//�ж϶����Ƿ�Ϊ��
template <class T>
bool ArrayQueue<T>::IsEmpty()
{
    if(qfront==rear)
    {
    //cout<<"����Ϊ�գ�"<<endl;
        return true;
    }
    else
        return false;
}

//�ж϶����Ƿ�Ϊ��
template <class T>
bool ArrayQueue<T>::IsFull()
{
    if((rear+1)%maxSize==qfront)
    {
        cout<<"��������"<<endl;
        return true;
    }
    else
        return false;
}
 //����Ԫ�ؽ�����
template <class T>
int ArrayQueue<T>::NumberOfEle()
{
    return (rear - qfront + maxSize ) % maxSize;
}

 //��ӡ����
template <class T>
void ArrayQueue<T>::PrintQueue()             //��ӡ����
{
    cout<<"����Ԫ�أ�"<<endl;
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
private:
    TreeNode<T> *root;

public:
    BinaryTree();
    ~BinaryTree();
    bool IsEmpty();                                 //�ж϶������Ƿ��ǿ���
    void Destroy(TreeNode<T>* p);                   //����һ�Ŷ�����
    TreeNode<T>*  getRoot(){return root;}       //���ظ��ڵ�
    TreeNode<T>*  create();                         //����һ���ض��Ķ�����

    //�ж����ǲ�����ȫ������
    /*��ȫ���������壺�������һ�������������в��������ﵽ�����ֵ �����һ��Ľ��ֲ������*/
    bool IsComplete();

};

//���캯��
template <class T>
BinaryTree<T>::BinaryTree()
{
    root=new TreeNode<T>(0);
    //�ض���̬ �̶�����
    root=this->create();
}
//�������Ľ���

template <class T>
TreeNode<T>* BinaryTree<T>::create()               //����һ���ض��Ķ�����
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

//��������
template <class T>
BinaryTree<T>::~BinaryTree()
{
    Destroy(root);
}
//�ݹ����ٶ�����
template <class T>
void BinaryTree<T>:: Destroy(TreeNode<T>* cur)//����һ�Ŷ�����
{
	if (cur)			//�ø��ڵ�ǿ�
	{
	//	cout << p->data << endl;
		TreeNode<T>* Left_Tree= cur->lchild;
		TreeNode<T>* Right_Tree= cur->rchild;
		delete cur;
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

//�ж϶������Ƿ�����ȫ������
//��Ϊ1�Ľ��Ķ��Ӿ͸ý����� �ҵ���Ϊ1�ĵ�� ������Ӧ����Ҷ�ӽ��
/*
template <class T>
bool BinaryTree<T>:: IsComplete()
{
    ArrayQueue<TreeNode<T>*> NodeQueue(10);  //�ö�������Ž���ָ��
    TreeNode<T>* pointer;
    pointer=root;
     if(pointer)
        NodeQueue.EnQueue(pointer);
    //��ʼ�������
     while(!NodeQueue.IsEmpty())
    {
        NodeQueue.DeQueue(pointer);          //�÷��ʹ��ĸ�����
        cout<<pointer->data<<endl;
        //ֻ���Һ���û�����ӿ϶�����
     if((pointer->lchild==NULL&&pointer->rchild!=NULL))
     {
         return false;
     }
      if(pointer->lchild)
        NodeQueue.EnQueue(pointer->lchild);
      if(pointer->rchild)
        NodeQueue.EnQueue(pointer->rchild);
      //���poiter��ֻ�����ӵĵ���߸ɴ����Ҷ�ӽ��
      //��ô����֮��ĵ㣨��ʱ�����д洢��Ԫ�أ���Ӧ����Ҷ�ӽ��
       if((pointer->lchild!=NULL&&pointer->rchild==NULL)||(pointer->lchild==NULL&&pointer->rchild==NULL))
        {
             break;
        }
    }
    //���ջ��ʣ�µ�Ԫ���ǲ��Ƕ���Ҷ�ӽ��
    while(!NodeQueue.IsEmpty())
    {
        NodeQueue.GetFront(pointer);
      //�������Ҷ�ӽ��
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
    cout<<"����ȫ������"<<endl;
   else
    cout<<"������ȫ������"<<endl;
   return 0;
 }

