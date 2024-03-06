/*基本思路:使用三个指针：prev、current和nextNode。这三个指针分别指向当前节点的前一个节点、当前节点和当前节点的下一个节点
    初始化三个指针：prev为nullptr，current为链表的头节点，nextNode为nullptr。
                 使用循环遍历链表，每次迭代执行以下步骤：
                 将nextNode指向current的下一个节点，以保存下一个节点的引用。
                 将current的next指针指向prev，实现反转。
                 更新prev为当前节点current。
                 更新current为下一个节点nextNode。
                 继续循环直到遍历完整个链表。
                 最后，将反转后的链表的头节点指定为prev。
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){
    }
};

Node* reverseLinkedList(Node* head){
    Node *prev=nullptr;
    Node *current=head;
    Node *nextNode=nullptr;
    
    while(current!=nullptr){
        nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }
    head=prev;
    return head;
}

void printLinkedList(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    cout<<"反转前：";
    printLinkedList(head);

    head=reverseLinkedList(head);
    cout<<"反转后：";
    printLinkedList(head);
    return 0;
}