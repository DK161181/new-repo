/*Develop a Hospital Emergency Room Management System using a Priority Queue.
The system should allow users to register patients along with their priority level
(e.g., Critical, Serious, Normal), display the waiting queue, and serve patients based
on priority basis.*/

#include<iostream>
using namespace std;

class Patient{
public:
string name;
int ID;
int priority;
};

class PriQueue{
Patient p[10];
int front;
int rare;
public:
void EQ();
void DQ();
void display();
bool isFull();
bool isEmpty();
PriQueue(){
    front=-1;
    rare=-1;
}
};

bool PriQueue:: isFull(){
        if(front==0 && rare==9){
            return true;
        }
        return false;
}

bool PriQueue:: isEmpty(){
    if(front==-1 && rare==-1){
                return true;
        }
        return false;
}

void PriQueue:: EQ(){
    for(int i=0; i<4; i++){
        cout<<"Enter name: ";
        cin>>p[i].name;
        cout<<"Enter ID: ";
        cin>>p[i].ID;
        cout<<"Enter Priority: ";
        cin>>p[i].priority;
        if(front==-1 && rare==-1){
            front =i;
            rare= i;
        }
        else{
            rare=i;
        }
    }
}

void PriQueue:: DQ(){
    cout<<"1.Normal 2.Serious 3.Critical"<<endl;
    int maxi=p[front].priority;
    int i=front+1;
    int idx=front;
    while(i<=rare){
        if(p[i].priority > maxi){
            maxi=p[i].priority;
            idx=i;
        }
        i++;
    }
    for(int i=0; i<=rare;i++){
            if(p[i].priority==maxi){
                    idx=i;
                    break;
            }
    }
    int j=idx;
    while(j<rare){
            p[j]=p[j+1];
            j++;
    }
    rare--;
    if(rare==-1){
        front=-1;
    }
}
void PriQueue::display()
{
    if(isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }


    for(int i = front; i <= rare; i++)
    {
        cout << "Name: " << p[i].name<<" "<< "ID: " << p[i].ID<<" "<< "Priority: " << p[i].priority;
             cout<< endl;
    }
}

int main(){
    PriQueue p;
    p.EQ();
    p.DQ();
    p.display();
    return 0;
}