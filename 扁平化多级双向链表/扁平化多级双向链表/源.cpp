/*
您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，可能指向单独的双向链表。这些子列表可能有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。

*****！！！！单级链表的child也要指向NULL
 

 示例:

 输入:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

 输出:
 1-2-3-7-8-11-12-9-10-4-5-6-NULL

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
using namespace std;
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
	Node() {
		prev = NULL;
		next = NULL;
		child = NULL;
		val = 0;
	}
};
//递归查找，每一级最多只有一个节点有child
class Solution {
public:
	Node* flatten(Node* head) {
		if (head==NULL)
		{
			return head;
		}
		//头节点也为新生成链表的头节点
		arrayline(head);
		return head;
	}
	Node* arrayline(Node* &head)
	{
		if (head->child!=NULL)
		{
			//步骤一
			Node *p = head->next;//保存当前节点的下一节点，因为当前节点之后会指向下一级，会找不到该节点
			head->next = head->child;//下一节点指向子节点
			head->child->prev = head;//子节点的前节点此时是指向空的，让其指向父节点
			Node *endnode=arrayline(head->child);
			head->child = NULL;
			//步骤四
			//执行下面的步骤时，节点指向例子中8或者3，此时链表为1-2-3-7-8-11-12
			if (p==NULL)//刚好尾节点是父节点
			{
				return endnode;
			}
			else
			{
				endnode->next = p;
				p->prev = endnode;
				if (p->next==NULL)//父节点的下一节点是尾节点，那么链接完后直接返回父节点的下一节点，这里递归代码的顺序写的不好
					//应该将节点本身是否是NULL放在if中而不是放在else中，且要将该If语句放在最前面，这样可以防止访问空指针
				{
					return p;
				}
				//否则
				return arrayline(p->next);//找到与当前父节点同级的尾节点，并借由其前面的节点逐步返回给上一父节点
			}
		}
		//步骤二
		else if(head->next!=NULL)//head->next!=NULL && head->child==NULL
		{
			//递归调用下一节点，每一级的末尾开始回退到有父节点的子节点的位置，类似例子中的11或者8
			/*
			这样写可能比较清晰
			Node *endnode=arrayline(head->next,rightnode);
			return endnode;
			*/
			return arrayline(head->next);
		}
		//步骤三
		else//head->next==NULL,说明到达了该级的尾节点，返回该点
		{
			return head;
		}
	}
};
int main()
{
	Node* head = new Node();
	head->next = new Node();
	head->next->prev = head;
	head->child = new Node();
	head->val = 1;
	head->next->val = 2;
	head->child->val = 3;
	Solution a;
	a.flatten(head);
	cin.get();
}