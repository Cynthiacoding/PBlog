#include <iostream>

using namespace std;

//������������������ֲ�ͬ��������ȱ���
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
    //�ݹ����
    void  PreOrder(TreeNode<T>* root);       //ǰ
    void  InOrder(TreeNode<T>* root);        //��
    void  PostOrder(TreeNode<T>* root);      //��
    //�ǵݹ����
    void  PreOrderWithoutRecusion();    //ǰ
    void  InOrderWithoutRecusion();     //��
    void  PostOrderWithoutRecusion();   //��


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
   // Destroy(root);
   // root=NULL;
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

//�������Ľ�������ǰ������ķ�ʽ��������������ȻҲ��������������ķ�ʽ����������

template <class T>
TreeNode<T>* BinaryTree<T>::create()               //����һ���ض��Ķ�����
 {
   /* TreeNode<T>* cur;
    T ch;
    cin>>ch;
    if(ch == 0)     //�������Ҷ�ӽڵ㣬�����������������ֱ�ֵΪ0
    {
        cur = NULL;
    }
    else
    {
        cur = new TreeNode<T>(ch);
        cur->lchild = create();  //�ݹ鴴��������
        cur->rchild = create();  //�ݹ鴴��������
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
void BinaryTree<T>::InOrder(TreeNode<T>* root)        //��
{
    cout<<"������������"<<endl;
        if(root!=NULL)
    {
        PreOrder(root->lchild);
        root->visit();
        PreOrder(root->rchild);
    }
}

template <class T>
void BinaryTree<T>::PostOrder(TreeNode<T>* root)      //��
{
    cout<<"������������"<<endl;
        if(root!=NULL)
    {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        root->visit();
    }
}



//�ǵݹ����
template <class T>
void BinaryTree<T>:: PreOrderWithoutRecusion()    //ǰ ������
{
     cout<<"ǰ����������"<<endl;
     ArrayStack<TreeNode<T>*> st(20);
     TreeNode <T>*pointer=root;
     while(!st.IsEmpty()||pointer)
     {
       if(pointer)
      {
         pointer->visit();      //���ʽڵ�
         //ֻ���Һ����ж�����ʱ�� ������ڵ���Һ��Ӳ�ֵ�ñ���������
         if(pointer->rchild!=NULL)
         {
            st.Push(pointer->rchild);      //�Ѹ��ڵ���ҽ��ѹ��ջ��
         }
         pointer=pointer->lchild;  //ת���о�������
      }
     //��ʱ�������ͷ������� ��ԭ��ѹ�õ�����ı�ѹ����������� ����ջ �ٶ����С�����з���
       else
      {
          st.Pop(pointer);
      }
     }
}




/*
ÿ����һ�����Ͱ���ѹջ��Ȼ��ȥ������������

�������������󣬴�ջ���г������㣨����������֮

��֮������ ���Һ�����һ�� ��ȥ�����ý���������

*/
//�� �� ��
template <class T>
void BinaryTree<T>:: InOrderWithoutRecusion()     //��
{
     cout<<"������������"<<endl;
     ArrayStack<TreeNode<T>*> st(20);
     TreeNode <T>*pointer=root;
     while(!st.IsEmpty()||pointer)
     {
         if(pointer)
         {
             //��������ѹ��ջ
             st.Push(pointer);
             //����������
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
ÿ����һ����㣬�Ȱ�������ջ�У�ȥ��������������

������������������Ӧ���������ý���������

������������֮�󣬲Ŵ�ջ���г��ý�㲢������

*/




template <class T>
void BinaryTree<T>:: PostOrderWithoutRecusion()   //��
{
    cout<<"������������"<<endl;
     ArrayStack<TreeNode<T>*> st(20);
     TreeNode <T>*pointer;
     TreeNode <T>*pre;
     pre=pointer=root;

     while(pointer)
     {
         //��һ������߳������� ������к��ӵĸ���ѹ��ջ��
          while(pointer->lchild!=NULL)
        {
      //      cout<<"!!!!!!!!!!!!!!!1"<<endl;
                st.Push(pointer);
                pointer=pointer->lchild;
        }
        //��ʱ�������ӵ������Ѿ�����ջ��


        //�����û���Һ��� �����ұߵĺ��ӱ����ʹ��˵Ļ�
        //�Ը��ķ��� �Լ���һ����������˵�ټ�
            while(pointer!=NULL&&(pointer->rchild==NULL||pointer->rchild==pre))
        {
         //  cout<<"22222222222222222"<<endl;
            pointer->visit();   //���Է�������
            pre=pointer;        //��ס�ոձ�����Ԫ�ص�λ��
            if(st.IsEmpty())    //���ʱ��ջΪ�� ��֤�� ��һ����� ������·��
                return;
            st.Pop(pointer);    //���ʶ��������� Ҫ�µ�Ԫ�� ����ջ�� ��ȡ�µ�Ԫ��
        }

        //��� ���Ҳ����
       //  cout<<"333333333333333333333"<<endl;
            st.Push(pointer);
            pointer=pointer->rchild; //ת��������
     }


}

 int main()
 {
   BinaryTree<char> btree;
   cout<<"ǰ����������"<<endl;   btree.PreOrderWithoutRecusion();
   btree.InOrderWithoutRecusion();
   btree.PostOrderWithoutRecusion();



   return 0;
 }

