#include<iostream>
using namespace std;

class MyLinkedList {
private:
	struct Node{
		Node *pre, *next;//ǰһ�ڵ�ͺ�һ�ڵ�
		int val;
		Node(int x):val(x),pre(NULL),next(NULL){}
	};
	Node *head, *tail;//ͷ�ڵ㣬β�ڵ�
	int length;//������
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = NULL;
		tail = NULL;
		length = -1;//
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index<0|| index>length) //�ж�index�Ƿ�Ϸ�
		{
			return -1;
		}
		int x = 0;
		Node *righthead = head;
		while (x!=index) //�ҵ���Ӧ�ڵ�
		{
			righthead = righthead->next;
			x++;
		}
		return righthead->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		if (head == NULL)//�������Ϊ��
		{
			head = new Node(val);
			length = 0; //��һ���ڵ�Ϊ0�ڵ㣬�˴���Ϊ����Ϊ0
			tail = head;
		}
		else//�����½ڵ㲢���뵽��ͷ
		{
			Node* newnode = new Node(val);
			head->pre = newnode;
			newnode->next = head;
			head = newnode;
			length++;
		}
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if (head==NULL)//����ǿ�������ô��ͬ����ӱ�ͷ
		{
			addAtHead(val);
		}
		else
		{
			Node* newnode = new Node(val);
			tail->next = newnode;
			newnode ->pre = tail;
			tail = newnode;
			length++;
		}
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index<=0)
		{
			addAtHead(val);
		}
		else if(index==length+1)
		{
			addAtTail(val);
		}
		else if(index>length+1)
		{
			return;
		}
		else//�ڱ��в���ڵ�
		{
			length++;
			int x = 0;
			Node *Nownode = head;
			while (x!=index)
			{
				Nownode = Nownode->next;
				x++;
			}
			Node *newnode = new Node(val);
			Node *lastnode = Nownode->pre;  //��Ҫ����ڵ��ǰһ�ڵ�
			lastnode->next = newnode;
			newnode->pre = lastnode;
			newnode->next = Nownode;
			Nownode->pre = newnode;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index<0 || index>length)
		{
			return;
		}
		else
		{
			length--;//ɾ���ڵ㳤�ȱؽ���һ
			Node *deletenode = head;
			int x = 0;
			while (x!=index)
			{
				deletenode = deletenode->next;
				x++;
			}
			if (deletenode==head)//���ɾ������ͷ�ڵ�
			{
				head = head->next;//��һ�ڵ��Ϊͷ�ڵ�
				if (head==NULL) //����½ڵ�Ϊ�գ�˵��ԭ��ֻ��һ���ڵ�
				{
					tail = NULL;//��ôɾȥһ���ڵ�֮��β�ڵ�Ҳ�������ˣ�Ӧ��ָ���
				}
				delete deletenode; //�ͷ��ڴ�ռ�
				return;
			}
			else if(deletenode==tail) //����ǰ���ж����Ƿ���ͷ�ڵ㣬���Ե�deletenode==tailʱ��ʱ�����������ڵ㣬tail�����ܵ���head;
			{
				tail = tail->pre;
				tail->next = NULL;
				delete deletenode;
			}
			else
			{
				Node* lastnode = deletenode->pre;
				Node* nextnode = deletenode->next;
				lastnode->next = nextnode;
				nextnode->pre = lastnode;
				delete deletenode;
			}
		}
	}


};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList* obj = new MyLinkedList();
* int param_1 = obj->get(index);
* obj->addAtHead(val);
* obj->addAtTail(val);
* obj->addAtIndex(index,val);
* obj->deleteAtIndex(index);
*/	