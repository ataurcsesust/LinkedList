#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
     int data;
     Node* next;
     Node* back;

   public:
     Node(int data1, Node* next1,Node *back1){
         data=data1;
         next= next1;
         back=back1;
     }
   public:
     Node(int data2)
      {
          data = data2;
          next=nullptr;
          back=nullptr;
      }
};

Node* ArrayToDLL(vector<int>&arr){
       Node *head= new Node(arr[0]);
       Node *prev = head;

       for(int i=1;i<arr.size();i++){
            Node *temp = new Node(arr[i],nullptr,prev);
            prev->next = temp;
            prev=temp;
       }

       return head;
}

Node* InsertAtHead(Node *head,int val){

    if(head == nullptr){
         return new Node(val, nullptr, nullptr);
    }
     Node *newHead= new Node(val,head,nullptr);
     head->back=newHead;
     return newHead;
}

Node* InsertAtTail(Node *head, int val){
      if(head==nullptr){
         return new Node(val,nullptr,nullptr);
      }
      Node *temp = head;
      while(temp->next!=nullptr){
            temp=temp->next;
      }

      Node *newNode = new Node(val,nullptr,temp);
       temp->next=newNode;

       return head;
}

Node* InsertBeforeTail(Node *head, int val){
      if(head==nullptr){
         return new Node(val,nullptr,nullptr);
      }

      if(head->next==nullptr){
           Node *newNode = new Node(val,head,nullptr);
           head->back=newNode;
           return newNode;
      }


      Node *temp = head;
      while(temp->next!=nullptr){
            temp=temp->next;
      }

      Node *prev =temp->back;
      Node *newNode = new Node(val,temp,prev);
       temp->back= newNode;
       prev->next=newNode;

       return head;
}



Node* InsertBeforeKthElement(Node *head, int pos,int val){
      if(head==nullptr){
          if(pos==1) return new Node(val,nullptr,nullptr);
          else return head;
          
      }

      if(head->next==nullptr){
           if(pos==1){
             Node *newNode = new Node(val,head,nullptr);
             head->back=newNode;
             return newNode;
           }
           else return head;
      }

           if(pos==1){
             Node *newNode = new Node(val,head,nullptr);
             head->back=newNode;
             return newNode;
           }

      int cnt =0;
      Node *temp = head;
      while(temp!=nullptr){
            cnt++;
            if(cnt==pos){
                  Node *prev=temp->back;
                  Node *newNode=new Node(val,temp,prev);
                  prev->next=newNode;
                  temp->back=newNode;
                  break;
            }
            temp=temp->next;
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

int main(){
       vector<int> v={1,2,3,20};
        //  vector<int> v={1};
        Node* head= ArrayToDLL(v);
        print(head);


        head=InsertAtHead(head,99);
        print(head);

        head=InsertAtTail(head,33);
        print(head);

        head = InsertBeforeTail(head,67);
        print(head);

        head=InsertBeforeKthElement(head,5,683);
        print(head);


    return 0;
}