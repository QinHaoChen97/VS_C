#include<iostream>
using namespace std;

/*
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
*/
class MyLinkedList {
private:
	struct Node {
		int val;
		Node *next;
		Node(int x) : val(x), next(nullptr) {}
	};
	int len;  //用于记录链表的长度,0为第一个节点，所以len要初始化为-1
 	Node *head, *tail;//head指向头结点，tail指向尾节点
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		len = -1;
		head = NULL;
		tail = NULL;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index<0 || index>len)  //判断index是否合规
		{
			return -1;
		}
		else
		{
			int i = -1;
			Node* ind_node=head;
			while (++i != index)  //找到对应节点的位置
			{
				ind_node = ind_node->next;
			}
			return ind_node->val;
		}
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		Node* last_head = head;  //保存原先的头节点
		Node* p = new Node(val);
		head = p;  //修改头节点
		p->next = last_head;  //将原先的链表接入
		len++;
		if (len==0)  //如果此时长度为一，那么头节点也为尾节点
		{
			tail = head;
		}
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		Node* p = new Node(val);
		tail->next = p; //将新的尾部节点链入
		tail = p;  //将尾节点更改为新链入的尾部节点
		len++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	//题目里还要求index<=0时插入在节点头
	void addAtIndex(int index, int val) {
		if (index>len+1)
		{
			cout << "index is greater than the length" << endl;
			return;
		}
		else if (index <= 0)
		{
			addAtHead(val);
		}
		else if(index==len+1)  //若index==0时链表又为空，此时在链表尾部进行操作导致出现错误，所以应当先把Index<=的判断放在前面
		{
			addAtTail(val);
		}
		else
		{
			index--; //得到index前一位置
			Node* ind_node = head;
			int i = -1;
			while (++i != index)  //找到对应节点的位置
			{
				ind_node = ind_node->next;
			}
			Node* p = new Node(val);
			//将新节点插入
			Node* last_next = ind_node->next; 
			ind_node->next = p;
			p->next = last_next;
			len++;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	//要考虑删除的是头节点或者是尾节点，此时需要对head或tail进行更新
	void deleteAtIndex(int index) {
		if (index>len || index<0)
		{
			return;
		}
		else
		{
			if (index==0)  //删除头节点
			{
				Node* p = head;
				head = head->next;  //新的头节点
				delete p;
				p = nullptr;
			}
			else
			{
				index--;//得到要删除节点的前一节点
				Node* ind_node = head;
				int i = -1;
				while (++i != index)  //找到对应节点的位置
				{
					ind_node = ind_node->next;
				}
				if (index==len-1) //是否删除的是尾节点，是的话要修改尾指针
				{
					tail = ind_node;
				}
				Node* p = ind_node->next;//此时p指向要被删除的节点
				ind_node->next = p->next;
				delete p;
				p = nullptr;
			}
		}
		len--;
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
int main()
{
	MyLinkedList* obj = new MyLinkedList();
	
	obj->addAtHead(7);
	obj->addAtHead(2);
	obj->addAtHead(1);
	obj->addAtIndex(3, 0);
	int a=obj->get(3);
	cin.get();
}