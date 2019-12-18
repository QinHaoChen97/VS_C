#include<iostream>
using namespace std;

/*
��������ʵ�֡�������ѡ��ʹ�õ������˫�����������еĽڵ�Ӧ�þ����������ԣ�val �� next��val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ��/���á����Ҫʹ��˫����������Ҫһ������ prev ��ָʾ�����е���һ���ڵ㡣���������е����нڵ㶼�� 0-index �ġ�

����������ʵ����Щ���ܣ�

get(index)����ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1��
addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
addAtTail(val)����ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
addAtIndex(index,val)���������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣��� index ��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣���indexС��0������ͷ������ڵ㡣
deleteAtIndex(index)��������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣
*/
class MyLinkedList {
private:
	struct Node {
		int val;
		Node *next;
		Node(int x) : val(x), next(nullptr) {}
	};
	int len;  //���ڼ�¼����ĳ���,0Ϊ��һ���ڵ㣬����lenҪ��ʼ��Ϊ-1
 	Node *head, *tail;//headָ��ͷ��㣬tailָ��β�ڵ�
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		len = -1;
		head = NULL;
		tail = NULL;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index<0 || index>len)  //�ж�index�Ƿ�Ϲ�
		{
			return -1;
		}
		else
		{
			int i = -1;
			Node* ind_node=head;
			while (++i != index)  //�ҵ���Ӧ�ڵ��λ��
			{
				ind_node = ind_node->next;
			}
			return ind_node->val;
		}
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		Node* last_head = head;  //����ԭ�ȵ�ͷ�ڵ�
		Node* p = new Node(val);
		head = p;  //�޸�ͷ�ڵ�
		p->next = last_head;  //��ԭ�ȵ��������
		len++;
		if (len==0)  //�����ʱ����Ϊһ����ôͷ�ڵ�ҲΪβ�ڵ�
		{
			tail = head;
		}
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		Node* p = new Node(val);
		tail->next = p; //���µ�β���ڵ�����
		tail = p;  //��β�ڵ����Ϊ�������β���ڵ�
		len++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	//��Ŀ�ﻹҪ��index<=0ʱ�����ڽڵ�ͷ
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
		else if(index==len+1)  //��index==0ʱ������Ϊ�գ���ʱ������β�����в������³��ִ�������Ӧ���Ȱ�Index<=���жϷ���ǰ��
		{
			addAtTail(val);
		}
		else
		{
			index--; //�õ�indexǰһλ��
			Node* ind_node = head;
			int i = -1;
			while (++i != index)  //�ҵ���Ӧ�ڵ��λ��
			{
				ind_node = ind_node->next;
			}
			Node* p = new Node(val);
			//���½ڵ����
			Node* last_next = ind_node->next; 
			ind_node->next = p;
			p->next = last_next;
			len++;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	//Ҫ����ɾ������ͷ�ڵ������β�ڵ㣬��ʱ��Ҫ��head��tail���и���
	void deleteAtIndex(int index) {
		if (index>len || index<0)
		{
			return;
		}
		else
		{
			if (index==0)  //ɾ��ͷ�ڵ�
			{
				Node* p = head;
				head = head->next;  //�µ�ͷ�ڵ�
				delete p;
				p = nullptr;
			}
			else
			{
				index--;//�õ�Ҫɾ���ڵ��ǰһ�ڵ�
				Node* ind_node = head;
				int i = -1;
				while (++i != index)  //�ҵ���Ӧ�ڵ��λ��
				{
					ind_node = ind_node->next;
				}
				if (index==len-1) //�Ƿ�ɾ������β�ڵ㣬�ǵĻ�Ҫ�޸�βָ��
				{
					tail = ind_node;
				}
				Node* p = ind_node->next;//��ʱpָ��Ҫ��ɾ���Ľڵ�
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