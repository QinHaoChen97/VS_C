#include<iostream>
using namespace std;

class MyLinkedList {
private:
	struct Node{
		Node *pre, *next;//前一节点和后一节点
		int val;
		Node(int x):val(x),pre(NULL),next(NULL){}
	};
	Node *head, *tail;//头节点，尾节点
	int length;//链表长度
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = NULL;
		tail = NULL;
		length = -1;//
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index<0|| index>length) //判断index是否合法
		{
			return -1;
		}
		int x = 0;
		Node *righthead = head;
		while (x!=index) //找到对应节点
		{
			righthead = righthead->next;
			x++;
		}
		return righthead->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		if (head == NULL)//如果链表为空
		{
			head = new Node(val);
			length = 0; //第一个节点为0节点，此处认为长度为0
			tail = head;
		}
		else//生成新节点并插入到表头
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
		if (head==NULL)//如果是空链表那么等同于添加表头
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
		else//在表中插入节点
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
			Node *lastnode = Nownode->pre;  //将要插入节点的前一节点
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
			length--;//删除节点长度必将减一
			Node *deletenode = head;
			int x = 0;
			while (x!=index)
			{
				deletenode = deletenode->next;
				x++;
			}
			if (deletenode==head)//如果删除的是头节点
			{
				head = head->next;//下一节点变为头节点
				if (head==NULL) //如果新节点为空，说明原来只有一个节点
				{
					tail = NULL;//那么删去一个节点之后尾节点也不存在了，应当指向空
				}
				delete deletenode; //释放内存空间
				return;
			}
			else if(deletenode==tail) //由于前面判断了是否是头节点，所以当deletenode==tail时此时至少有两个节点，tail不可能等于head;
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