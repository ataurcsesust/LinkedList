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


void print(Node *head){
       Node  *move = head;
        while(move!=nullptr){
          cout<<move->data<<' ';
          move = move->next;
      }
     
     cout<<endl;
}

Node* RemoveKthNodeFromLast(Node *head,int k){
         Node *temp=head;
         int cnt=0;
         while(temp!=nullptr){
              cnt++;
              temp=temp->next;
         }

         if(cnt<k){
            return head;
         }

         if(cnt==k){
             Node *del=head;
             head=head->next;
             delete del;
         }
         
         int ind=cnt-k;
         temp=head;

          while(ind){
               ind--;
               if(ind==0){
                  Node *del= temp->next;
                  temp->next = del->next;
                  delete del;
               }
              temp=temp->next;
         }

         return head;

}

Node* RemoveKthNodeFromLastOptimal(Node *head,int k){
       Node *fast=head,*slow=head;
       for(int i=0;i<k;i++) fast=fast->next;
       if(fast==nullptr) return head->next;
       while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
       }

       Node *del = slow->next;
       slow->next= del->next;
       delete del;
       return head;

}




int main(){

        vector<int> v={1,2,3,4,5,6,20};
        Node* head= ArrayTOLinkedList(v);
        print(head);

        Node *head1= RemoveKthNodeFromLast(head,3);
        print(head1);


        Node *head2 = RemoveKthNodeFromLastOptimal(head,3);
        print(head2);


    return 0;
}