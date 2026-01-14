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


// Node* Reverse(Node *head){

//       Node *temp=head; 
//       stack<int>st;
//       while(temp!=nullptr){
//            st.push(temp->data);
//            temp=temp->next;
//       }

//       temp=head;
//       while(temp!=nullptr){
//            temp->data=st.top(); 
//            st.pop();
//            temp=temp->next;
//       }

//       return head;
// }

Node* Reverse(Node *head){
      if(head==nullptr || head->next==nullptr) return head;
     
      Node *last=nullptr;
      Node *cur=head;
      while(cur!=nullptr){
            last=cur->back;
            cur->back=cur->next;
            cur->next=last;
            cur=cur->back;
      }

      return last->back;
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

        head =Reverse(head);
        print(head);


    return 0;
}