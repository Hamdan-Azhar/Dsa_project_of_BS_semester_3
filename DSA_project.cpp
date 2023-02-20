
//A simple C++ program that does the work of a bank management system and provides some functionalities for customer and manager.
// It does linked list, stack and dequeue implementation. The program uses double linked list.
#include <iostream>
using namespace std;
struct node                                                         
{
    string name;
    int accNo;
    int money;
    node *next;
    node *prev;
};

class linked                                                        
{
	private:
    node *curr,*front,*top;                                         //we create top node for stack implementation and front node for 
    int noOfRegisteredAccs;                                         //dequeue implementation of queue
    public:
    linked()
    {
    	noOfRegisteredAccs=0;
    	curr=front=top=NULL;
	}
    void insert(string name,int accNo, int money)                  // inserts all the necessary user credentials  
    {
    	curr=front;
    	while(curr!=NULL)
    	{
    		if(curr->name==name && curr->accNo)                    //if account with entered name and account no is already present, then we
    		{                                                      //simply add money to that account
    			curr->money+=money;
    		    cout<<"Money added to account "<<accNo<<" successfully\n";	
    			return;
			}
			curr=curr->next;
		}
    	node *newnode = new node;                                 //if we do not find an exising account with given name and account number, then 
        newnode->name = name;                                      //we create a new account with that number and account number
        newnode->accNo = accNo;
        newnode->money = money;
        newnode->next = newnode->prev = NULL;
        
    	if(top==NULL)
            front = top = newnode;
		else
		{
            top->next=newnode;
			newnode->prev = top;
			newnode->next = NULL;
			top=newnode;
		}
        noOfRegisteredAccs++;
        cout<<"New account with accountNo: "<<accNo<<" and name: "<<name<<" created successfully and money added to that account\n";
        dequeue_func_for_queue_implementation();                  //we call this function to check whether the total capacity of bank has been exceeded or
                                                                  //not
    }
    void displayDetails()                                         //displays the users and their information 
    {
        curr= front;
        while(curr!= NULL)
        {
            cout << "Name = " << curr->name <<endl;
            cout << "Account Number = " << curr->accNo <<endl;
            cout << "Money = " << curr->money <<endl;
            curr = curr->next;
        }
    }
    void display_details_through_StackImplementation()            //displays the users and their information through stack 
    {
        curr=top;
        while(curr!=NULL)
        {
        	cout << "Name = " << curr->name <<endl;
            cout << "Account Number = " << curr->accNo <<endl;
            cout << "Money = " << curr->money <<endl;
            curr = curr->prev;
		}
    }
    
    void registeredAccs()                                         // displays the number of registered accounts      
    {
        cout << "Number of registered accounts = " << noOfRegisteredAccs<<endl;
    }
    void Addmoney(string name,int accNo, int money)               // adds money to existing account  
    {
        curr=front;
        while(curr!=NULL)
        {
        	if(curr->name==name && curr->accNo==accNo)
        	{
        		curr->money+=money;
        		cout<<"Money added to account "<<accNo<<" successfully\n";
        		return;
			}
			curr=curr->next;
		}
		cout<<"There does not exist any account with entered name,ID or accNo\n";
    }
    void dequeue_func_for_queue_implementation()                  //dequeue implementation function
    {                                                             //if the linked list has more than 10 nodes in total,then this function removes the node
    	if(noOfRegisteredAccs>10)                                 //at front. This is dequeue function of a queue 
    	{
    		node*delete_node=front;
     	    front=front->next;
     	    front->prev=NULL;
    	    cout<<"The maximum capacity of the bank has been exceeded.Therefore the account with account no:"<<delete_node->accNo<<" is removed from bank\n";
    	    noOfRegisteredAccs--;
    	    delete delete_node;
		}
    	
	}
	void deleteAccount()                                           //function to delete account(node) 
    {
       string name;
       int accNo;
       cout<<"Enter account name and account No of the account you want to delete: ";
       cin>>name>>accNo;
       
       curr = front;
       node* PrevNode = NULL;
     
       if (curr!= NULL && curr->name==name && curr->accNo==accNo)
       {
           front= front->next;
		   front->prev=NULL; 
           delete curr;   
		   cout<<"Account deleted\n"; 
		   noOfRegisteredAccs--;        
           return;
       }
       else
       {
           while (curr!= NULL && curr->name!= name && curr->accNo!=accNo)
          {
            PrevNode = curr;
            curr = curr->next;
          }
 
       if(curr==NULL)
       {
       	   cout<<"No account with given name and account found\n";
       	   return;
	   }
       
       PrevNode->next = curr->next;
       curr->next->prev=PrevNode;
       delete curr;
       cout<<"Account deleted\n";
       noOfRegisteredAccs--; 
       }
    }
 
};
int main()                                                         
{
	linked Account;
	
	cout << "\t\t\t\t\t*******************************************\n";
    cout << "\t\t\t\t\tWELCOME TO THE BANK MANAGEMENT SYSTEM\n";
    cout << "\t\t\t\t\t*******************************************\n";
    
    int choice,subchoice;
    string name;
    int accNo,money;
    do
    {
    	cout << "Enter your choice:\n1->Are you a MANAGER?\n2->Are you a CUSTOMER?\nAny other number->EXIT\n";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			 cout <<"Enter your choice\n1->View Account's Details\n2->View Number Of Registered Accounts\n3->View created accounts in descending order\n";
				 cout<<"4.delete account\n";
    			 cin>>subchoice;
				 if(subchoice==1)
				       Account.displayDetails();
    			 else if(subchoice==2)
    			       Account.registeredAccs();
    			 else if(subchoice==3)
    				   Account.display_details_through_StackImplementation();
    			 else if(subchoice==4)
    			       Account.deleteAccount();
    			 else
    			      cout<<"Invalid choice\n";
    	         break;
    		case 2:
    			 cout<< "Enter your choice\n1->Create new account\n2->Add money to existing account\n";
    			 cin>>subchoice;
    			
    			 if(subchoice==1)
    			 {
    			 	cout << "Enter user's name, account number, and money = ";
                    cin >> name >> accNo >> money;
                    Account.insert(name,accNo,money);
				 }
                 else if(subchoice==2)
                 {
                 	cout << "Enter user's name, account number, and money = ";
                    cin >> name >> accNo >> money;
                    Account.Addmoney(name,accNo,money);
				 }  
                 else 
                      cout<<"Invalid choice\n";
                 break;
	    }
   }while(choice==1 || choice==2);

   return 0;
}




