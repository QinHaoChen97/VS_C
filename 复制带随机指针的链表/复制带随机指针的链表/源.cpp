/*
����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣

Ҫ�󷵻��������������
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
				typedef Node* oldrandomptr;//���������д洢��random
				typedef Node* newrandomptr;//�������д洢��random
				typedef Node* oldnode;//�ɽڵ�
				typedef Node* newnode;//�½ڵ�
				/*
				���������������ݴ�������������̫����
				����������MAPֻ��һ�����㹻��
				��ÿ�������½ڵ�㽫�����map
				*/
				unordered_map<oldrandomptr,newrandomptr> randomnodemap;//���random   
				unordered_map<oldnode, newnode> oldnewmap; //���node
				Node* deepcopyhead = new Node(head->val);//�������ͷ�ڵ�
				if (head->random!=NULL)
				{
					if (head->random==head)//��һ���ǿ�Ҳ������ָ����
					{
						deepcopyhead->random = deepcopyhead;
						randomnodemap[head->random] = deepcopyhead->random;
						oldnewmap[head] = deepcopyhead;
					}
					else
					{
						deepcopyhead->random = new Node(head->random->val);
						randomnodemap[head->random] = deepcopyhead->random;//���¾�random�ڵ�ӳ�䲢����ͼ��
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
					if (randomnodemap.count(oldnownode))//�����ǰ�ڵ����Ѿ��������ģ���Ϊrandom����ָ������Ľڵ㣩������ֻ��Ҫ��randomnode����Ľڵ㣬��Ϊoldnewmap����Ľڵ㶼һ���ڵ�ǰ�ڵ�ǰ��
					{
						//��ôֻ��Ҫͨ��map�ҵ��������ж�Ӧ�Ľڵ㼴��
						newnownode->next = randomnodemap[oldnownode];
						if (oldnownode->random!=NULL)//��Ȼ�½ڵ��Ѿ������ˣ�����������randomû����ȷ���䣨��Ϊ���ýڵ��Ǻ����Ľڵ�õȵ��ҵ���Ӧ�ľɽڵ��֪����random��ָ������ڴ�֮ǰrandom��ָ��NULL�ģ�
						{
							if (randomnodemap.count(oldnownode->random))
							{
								newnownode->next->random = randomnodemap[oldnownode->random];
							}
							else if (oldnewmap.count(oldnownode->random))
							{
								newnownode->next->random = oldnewmap[oldnownode->random];
							}
							else//��random�ڵ㻹��ָ���½ڵ�
							{
								Node *p = new Node(oldnownode->random->val);
								newnownode->next->random = p;
								randomnodemap[oldnownode->random] = p;
							}
						}
						else//�ýڵ��random������ָ��NULL���Ǿ�ʲô������
						{
							//
						}
						oldnownode = oldnownode->next;
						newnownode = newnownode->next;
					}
					else//oldnownode->random��һ��ȫ�µĽڵ�
					{
						Node *p = new Node(oldnownode->val);
						oldnewmap[oldnownode] = p;//������ӳ��
						if (oldnownode->random==NULL)
						{
							//ʲô������
						}
						else if (randomnodemap.count(oldnownode->random))//���random�ڵ���֮ǰ�Ѿ���������
						{
							//��ôֻ��Ҫͨ��map�ҵ��������ж�Ӧ�ڵ㼴��
							p->random = randomnodemap[oldnownode->random];
						}
						else if (oldnewmap.count(oldnownode->random))//���ָ�����֮ǰ����Ľڵ�
						{
							p->random = oldnewmap[oldnownode->random];
						}
						else//���������µ�random�ڵ�
						{
							p->random = new Node(oldnownode->random->val);
							randomnodemap[oldnownode->random] = p->random;
						}
						newnownode->next=p;//�������½ڵ�

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