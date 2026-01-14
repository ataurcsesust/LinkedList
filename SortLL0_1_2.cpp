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

Node* SortEasy(Node *head){

      if(head==nullptr) return head;
       int one=0,zero=0,two=0;
       Node *temp=head;
       while(temp!=nullptr){
            if(temp->data==0) zero++;
            else if(temp->data==1) one++;
            else two++;
            temp=temp->next;
       }
       temp=head;

       while(temp!=nullptr){
            if(zero){
                temp->data=0;
                zero--;
            }
            else if(one){
                temp->data=1;
                one--;
            }
            else {
                temp->data=2;
                two--;
            }
            temp=temp->next;
       }
       return head;
}

Node* SortOptimal(Node *head){
      Node *zero = new Node(-1); 
      Node *one = new Node(-1); 
      Node *two = new Node(-1); 
      Node *last0=zero,*last1=one, *last2=two;
      Node *temp= head;
      while(temp!=nullptr){
           if(temp->data==0){
               last0->next=temp;
               last0=last0->next;
           }
           else if(temp->data==1){
               last1->next=temp;
               last1=last1->next;
           }
           else {
               last2->next=temp;
               last2=last2->next;
           }
          temp = temp->next;
      }
     
      last0->next=one->next?one->next:two->next;
      last1->next=two->next;
      last2->next=nullptr;

        Node* newHead = zero->next; 
        delete zero;
        delete one;
        delete two;
        return newHead;
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

        vector<int> v={1,0,1,2,0,2,1};
        Node* head= ArrayTOLinkedList(v);
        print(head);

       Node  *head1= SortEasy(head);
        print(head1);

        Node *head2 = SortOptimal(head);
        print(head2);


    return 0;
}