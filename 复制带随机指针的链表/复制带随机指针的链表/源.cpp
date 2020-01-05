/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深拷贝。
*/
#include<iostream>
#include<unordered_map>
using namespace std;
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
class Solution {
	public:
		Node* copyRandomList(Node* head) {
			if (head==NULL)
			{
				return NULL;
			}
			else
			{
				typedef Node* oldrandomptr;//所给链表中存储的random
				typedef Node* newrandomptr;//新链表中存储的random
				typedef Node* oldnode;//旧节点
				typedef Node* newnode;//新节点
				/*
				看完题解后回来看这份代码觉得冗余代码太多了
				下面这两个MAP只用一个便足够了
				即每当生成新节点便将其加入map
				*/
				unordered_map<oldrandomptr,newrandomptr> randomnodemap;//存放random   
				unordered_map<oldnode, newnode> oldnewmap; //存放node
				Node* deepcopyhead = new Node(head->val);//新链表的头节点
				if (head->random!=NULL)
				{
					if (head->random==head)//第一个非空也可能是指向本身
					{
						deepcopyhead->random = deepcopyhead;
						randomnodemap[head->random] = deepcopyhead->random;
						oldnewmap[head] = deepcopyhead;
					}
					else
					{
						deepcopyhead->random = new Node(head->random->val);
						randomnodemap[head->random] = deepcopyhead->random;//将新旧random节点映射并放入图中
						oldnewmap[head] = deepcopyhead;
					}
				}
				else
				{
					oldnewmap[head] = deepcopyhead;
				}
				Node* oldnownode = head;
				Node* newnownode = deepcopyhead;
				oldnownode=oldnownode->next;
				while (oldnownode!=NULL)
				{
					if (randomnodemap.count(oldnownode))//如果当前节点是已经构建过的（因为random可能指向后续的节点），这里只需要找randomnode里面的节点，因为oldnewmap里面的节点都一定在当前节点前面
					{
						//那么只需要通过map找到新链表中对应的节点即可
						newnownode->next = randomnodemap[oldnownode];
						if (oldnownode->random!=NULL)//虽然新节点已经构建了，但可能它的random没有正确分配（因为若该节点是后续的节点得等到找到对应的旧节点才知道其random的指向哪里，在此之前random是指向NULL的）
						{
							if (randomnodemap.count(oldnownode->random))
							{
								newnownode->next->random = randomnodemap[oldnownode->random];
							}
							else if (oldnewmap.count(oldnownode->random))
							{
								newnownode->next->random = oldnewmap[oldnownode->random];
							}
							else//该random节点还是指向新节点
							{
								Node *p = new Node(oldnownode->random->val);
								newnownode->next->random = p;
								randomnodemap[oldnownode->random] = p;
							}
						}
						else//该节点的random本来就指向NULL，那就什么都不做
						{
							//
						}
						oldnownode = oldnownode->next;
						newnownode = newnownode->next;
					}
					else//oldnownode->random是一个全新的节点
					{
						Node *p = new Node(oldnownode->val);
						oldnewmap[oldnownode] = p;//加入新映射
						if (oldnownode->random==NULL)
						{
							//什么都不做
						}
						else if (randomnodemap.count(oldnownode->random))//如果random节点是之前已经构建过的
						{
							//那么只需要通过map找到新链表中对应节点即可
							p->random = randomnodemap[oldnownode->random];
						}
						else if (oldnewmap.count(oldnownode->random))//如果指向的是之前构造的节点
						{
							p->random = oldnewmap[oldnownode->random];
						}
						else//否则生成新的random节点
						{
							p->random = new Node(oldnownode->random->val);
							randomnodemap[oldnownode->random] = p->random;
						}
						newnownode->next=p;//链接上新节点

						oldnownode = oldnownode->next;
						newnownode = newnownode->next;
					}
				}
				return deepcopyhead;
			}
		}
	};
int main()
{
	Node* p1 = new Node(7);
	p1->random = p1;
	//Node* p2 = new Node(13);
	//Node* p3 = new Node(11);
	//Node* p4 = new Node(10);
	//Node* p5 = new Node(1);
	//p2->random = p1;
	//p1->next = p2;
	//p2->next = p3;
	//p3->next = p4;
	//p4->next = p5;
	//p3 ->random = p5;
	//p4->random = p3;
	//p5->random = p1;
	Solution a;
	Node*newp1=a.copyRandomList(p1);
	cin.get();
}