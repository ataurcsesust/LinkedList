#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
     int data;
     Node* next;

 public:
     Node(int data1, Node* next1){
         data=data1;
         next= next1;
     }
 public:
     Node(int data2)
      {
          data = data2;
           next=nullptr;
      }
};

Node* ArrayTOLinkedList(vector<int>&v){
     Node* head = new Node(v[0]);
     Node* move = head;
     for(int i=1;i<v.size();i++){
          Node* temp = new Node(v[i]);      
          move->next= temp;
          move=move->next;
     }
     return head;
}

Node* Reverse(Node * head){

      if(head==nullptr) return head;
      Node *cur=head,*prev=nullptr;

      while(cur!=nullptr){
          Node* temp = cur->next;
          cur->next=prev;
          prev=cur;
          cur=temp;
      }
      return prev;
}


void print(Node *head){
       Node  *move = head;
        while(move!=nullptr){
          cout<<move->data<<' ';
          move = move->next;
      }
     
     cout<<endl;
}


int main(){

         vector<int> v={1,2,3,4,5,6,20};
         Node* head= ArrayTOLinkedList(v);
         print(head);

         Node *head1 = Reverse(head);
         print(head1);


    return 0;
}