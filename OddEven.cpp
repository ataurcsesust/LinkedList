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

//My approach
Node* OddEven1(Node *head){
      if(head==nullptr || head->next==nullptr){
         return head;
      }

      int cnt = 0;
      Node *cur=head;
      while(cur!=nullptr){
          cnt++;
          cur=cur->next;
      }
      
      Node *ansHead = new Node(head->data);
      Node *last=ansHead;
      Node *temp=head;
      int cnt2=(cnt+1)/2;
      cnt2--; 
      for(int i=0;i<cnt2;i++){
          temp=temp->next->next;
          last->next=new Node(temp->data);
          last=last->next;
      }
      
      cnt2=(cnt)/2;
      if(head->next!=nullptr){
           temp=head->next;
      }

    for(int i=0;i<cnt2;i++){
          last->next=new Node(temp->data);
          if(temp->next!=nullptr && temp->next->next!=nullptr){
              temp=temp->next->next;
              last=last->next;
          }
         
      }

      return ansHead;

}

// Node* OddEven2(Node *head){

//          if(head==nullptr || head->next ==nullptr) return head;
//          Node *newHead = new Node(-1);
//          Node *odd= head;
//          Node *even=head->next;
//          Node *temp=head;
//          int cnt=0;
//          while(temp!=nullptr){
//               cnt++;
//               if(cnt%2){
//                  temp->next=new Node()
//               }
//          }
// }



void print(Node *head){
       Node  *move = head;
        while(move!=nullptr){
          cout<<move->data<<' ';
          move = move->next;
      }
     
     cout<<endl;
}


int main(){

       // vector<int> v={1,2,3,4,5,6,20};
        vector<int> v = {1, 2, 3, 4};
        Node* head= ArrayTOLinkedList(v);
        print(head);

       Node  *head1=OddEven1(head);
        print(head1);
        
      //Node  *head2 = OddEven2(head);
    

    return 0;
}