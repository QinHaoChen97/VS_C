// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
#include<iostream>
#include<unordered_map>
using namespace std;
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head; //双链表的伪头部
    DLinkedNode* tail; //双链表的伪尾部
    int size; //当前大小
    int capacity; //总容量

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
       head=new DLinkedNode();
       tail=new DLinkedNode();
       head->next=tail;
       tail->prev=head;
    }
    
    int get(int key) {
       if (!cache.count(key))
       {
           return -1;
       }
       else
       {
           //使用过的数据移到链表头
           DLinkedNode* node=cache[key];
           moveToHead(node);
           return node->value;
       }
    }
    
    void put(int key, int value) {
       if (!cache.count(key))
       {
           if (size==capacity) //容量满了，需要先删除节点
           {
               DLinkedNode* deletenode=removeTail();
               cache.erase(deletenode->key);
               delete deletenode; //防止内存泄漏
               size--;
           }
           size++;
           DLinkedNode* add_node=new DLinkedNode(key,value);
           addToHead(add_node);
           cache[key]=add_node;
       }
       else //关键字存在，变更数据值
       {
           DLinkedNode* node=cache[key];
           node->value=value;
           moveToHead(node);
       }
       
       
    }

    void addToHead(DLinkedNode* node) {
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
        
    }
    
    void removeNode(DLinkedNode* node) {
        node->next->prev=node->prev;
        node->prev->next=node->next;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }
    //返回被删除的尾节点的地址，做内存处理
    DLinkedNode* removeTail() {
        DLinkedNode* deletenode=tail->prev;
        removeNode(deletenode);
        return deletenode;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

