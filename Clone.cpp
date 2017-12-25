/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
        //复制链表结点并将副本插入在原结点之后
    void CloneInsert(RandomListNode* pHead){
        RandomListNode* tempnode = pHead;
        RandomListNode* temp;
        while(tempnode){
            RandomListNode* newnode = new RandomListNode(tempnode->label);
        	temp = tempnode->next;
            tempnode->next = newnode;
            newnode->next = temp;
            tempnode = newnode->next;
        } 
    }
    //同理将结点的random复制和插入到相应的位置
    void RandomInsert(RandomListNode* pHead) {
        RandomListNode* tempnode = pHead;
        while(tempnode){
            if(tempnode->random)
                tempnode->next->random = tempnode->random->next;
            tempnode = tempnode->next->next;//得跳过一个结点
        }
        /*RandomListNode *pNode = pHead;
     
        while (pNode != NULL)
        {
            RandomListNode *pClone = pNode->next;
            if (pNode->random)
            {
                pClone->random = pNode->random->next;
            }
            pNode = pClone->next;
        }*/
    }
    //将副本结点拆开并组成一个新的链表
    RandomListNode* NewRandomList(RandomListNode* pHead){
        RandomListNode* tempnode = pHead;
        RandomListNode* cloneHead = pHead->next;
        while(tempnode->next){
            RandomListNode* pclone = tempnode->next;
            tempnode->next = pclone->next;
            tempnode = pclone;
            pclone->next = tempnode->next;
        }
        return cloneHead;
    }
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        CloneInsert(pHead);
        RandomInsert(pHead);
        RandomListNode* newHead = NewRandomList(pHead);
        return newHead;
    }
};
