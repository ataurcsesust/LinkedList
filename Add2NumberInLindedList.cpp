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

Node* addTwoNumber(Node *head1, Node *head2){
       Node *cur1=head1, *cur2=head2;
       Node *ran = new Node(-1);
       Node *last=ran;
       int carry=0;
       while(cur1!=nullptr || cur2!=nullptr || carry){
            int sum=carry;
            if(cur1!=nullptr){
                sum+= cur1->data;
                cur1=cur1->next;
            }
            
            if(cur2!=nullptr){
                sum+= cur2->data;
                cur2=cur2->next;
            }

            last->next= new Node(sum%10);
            carry = sum/10;
            last=last->next;

       }

       return ran->next;

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

        vector<int> v1={4,5,6};
        vector<int> v2={7,3,5};
        Node* head1= ArrayTOLinkedList(v1);
        Node* head2= ArrayTOLinkedList(v2);
        print(head1);
        print(head2);

        Node *head= addTwoNumber(head1,head2);
        print(head);

    return 0;
}