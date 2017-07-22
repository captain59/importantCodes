#include <iostream>
#include <stdlib.h>
using namespace std;


//Node declaration
struct node
{
	int data;
	struct node *next;
};
struct node *start;
//Class Declaration
class Linked_List
{
public:
	
	Linked_List();
	node* create_node(int);
	node* traverse(int);
	int length();
	void insert_begin();
	void insert_pos();
	void insert_last();
	void delete_pos();
	void sorting();
	void search();
	void update();
	void reverse();
	void display();
	~Linked_List();
};
Linked_List::Linked_List()
{
	start=NULL;
}
Linked_List::~Linked_List()
{
	struct node *ptr=start;
	while(start!=NULL)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
}
int main(int argc, char const *argv[])
{
	int choice,nodes,element,position,i;
	Linked_List s1;
	start = NULL;
	while(true)
	{
	    cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;

        cout<<"1.Insert Node at beginning"<<endl;

        cout<<"2.Insert node at last"<<endl;

        cout<<"3.Insert node at position"<<endl;

        cout<<"4.sorting Link List"<<endl;

        cout<<"5.Delete a Particular Node"<<endl;

        cout<<"6.Update Node Value"<<endl;

        cout<<"7.Search Element"<<endl;

        cout<<"8.Display Linked List"<<endl;

        cout<<"9.Reverse Linked List "<<endl;

        cout<<"10.Exit "<<endl;

        cout<<"Enter your choice : ";

        cin>>choice;
        switch(choice)
        {
        	case 1:
        	cout<<"Inserting Node at Beginning: "<<endl;
        	s1.insert_begin();
        	cout<<endl;
        	break;
        	case 2:
        	cout<<"Inserting node at the last: "<<endl;
        	s1.insert_last();
        	cout<<endl;
        	break;
        	case 3:
        	cout<<"Inserting node at a give position: "<<endl;
        	s1.insert_pos();
        	cout<<endl;
        	break;
        	case 4:
        	cout<<"sorting Link List "<<endl;
        	s1.sorting();
        	cout<<endl;
        	break;
        	case 5:
        	cout<<"Delete a particular node: "<<endl;
        	s1.delete_pos();
        	cout<<endl;
        	break;
        	case 6:
        	cout<<" Update Node Value "<<endl;
        	s1.update();
        	cout<<endl;
        	break;
        	case 7:
        	cout<<"Search an element in the Link List "<<endl;
        	s1.search();
        	cout<<endl;
        	break;
        	case 8:
        	cout<<"Display element in link list "<<endl;
        	s1.display();
        	cout<<endl;
        	break;
        	case 9:
        	cout<<"Reverse element of link list "<<endl;
        	s1.reverse();
        	cout<<endl;
        	break;
        	case 10:
        	cout<<"Exiting "<<endl;
        	cout<<endl;
        	exit(0);
        	break;
        	default:
        	cout<<"Wrong Choice"<<endl;
        }
	}
	return 0;
}
//Creating a node
node *Linked_List::create_node(int value)
{
	struct node *temp,*s;
	temp = new(struct node);
	if(temp==NULL)
	{
		cout<<"Memory not allocated"<<endl;
		return 0;
	}
	temp->data = value;
	temp->next = NULL;
	return temp;
}
//Inserting node in the beginning
void Linked_List::insert_begin()
{
	int value;
	cout<<"Enter the value to be inserted: ";
	cin>>value;
	struct node *temp,*p;
	temp= create_node(value);
	if(start==NULL)
	{
		start=temp;
		start->next = NULL;
	}
	else
	{
		p =start;
		start = temp;
		start->next = p;
	}
	cout<<"Element inserted at the beginning"<<endl;
}
node *Linked_List::traverse(int pos)
{
	int count=1;
	struct node *nptr=start;
	while(nptr->next!=NULL)
	{
		if(count==pos)
			break;
		count++;
	}
	return nptr;
}
// insert node at the last
void Linked_List::insert_last()
{
	int value;
	cout<<"Enter the value to be inserted: ";
	cin>>value;
	struct node *temp,*s;
	temp=create_node(value);
	s=start;
	while(s->next!=NULL)
		s=s->next;
	temp->next=NULL;
	s->next=temp;
	cout<<"Element inserted at last\n";
}
int Linked_List::length()
{
	struct node *p=start;
	int count=0;
	while(p->next!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
void Linked_List::insert_pos()
{
	int value,pos,counter=0,i;
	cout<<"Enter the value to be inserted: ";
	cin>>value;
	struct node *temp,*ptr,*s;
	temp = create_node(value);
	cout<<"Enter the position at which node to be inserted: ";
	cin>>pos;
	s=start;
	while(s!=NULL)
	{
		s=s->next;
		counter++;
	}
	if(pos==1)
	{
		if(start==NULL)
		{
			start=temp;
			start->next=NULL;
		}
		else
		{
			ptr=start;
			start=temp;
			start->next=ptr;
		}
	}
	else if(pos>1 && pos<=counter)
	{
		s=start;
		for(i=1;i<pos;i++)
		{
			ptr=s;
			s=s->next;
		}
		ptr->next=temp;
		temp->next=s;
	}
	else
	{
		cout<<"Position out of range\n";
	}
}
//delete an element at a given postion
void Linked_List::delete_pos()
{
	int pos,i,counter=0;
	if(start==NULL)
	{
		cout<<"List is empty\n";
		return;
	}
	cout<<"Enter the position of the value to be deleted: ";
	cin>>pos;
	struct node *s,*ptr;
	s=start;
	if(pos==1)
		start=s->next;
	else
	{
		while(s!=NULL)
		{
			s=s->next;
			counter++;
		}
		if(pos>0 && pos<=counter)
		{
			s= start;
			for(i=1;i<pos;i++)
			{
				ptr=s;
				s=s->next;
			}
			ptr->next=s->next;
		}
		else
			cout<<"Position out of range"<<endl;
		free(s);
		cout<<"Element Deleted"<<endl;
	}
}
void Linked_List::update()
{
	int value,pos,i;
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	cout<<"Enter the node position to be updated";
	cin>>pos;
	cout<<"Enter the ne value: ";
	cin>>value;
	struct node *s,*ptr;
	s=start;
	if(pos==1)
		start->data = value;
	else
	{
		for(i=0;i<pos-1;i++)
		{
			if(s==NULL)
			{
				cout<<"There are less than "<<pos<<" elements";
				return;
			}
			s=s->next;
		}
		s->data=value;
	}
	cout<<"Node Updated"<<endl;
}
// Searching an element
void Linked_List::search()
{
	int value,pos=0;
	bool flag=false;
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	cout<<"Enter the value to be searched: ";
	cin>>value;
	struct node *s;
	while(s->next!=NULL)
	{
		pos++;
		if(s->data==value)
		{
			flag=true;
			cout<<"Element "<<value<<" is at position "<<pos<<endl;
		}
		s=s->next;
	}
	if(!flag)
		cout<<"Element "<<value<<" not found in the list "<<endl;
}
//reverse linked list
void Linked_List::reverse()
{
	struct node *ptr1,*ptr2,*ptr3;
	if(start==NULL)
	{
		cout<<"Empty List\n";
		return;
	}
	if(start->next==NULL)
		return;
	ptr1=start;
	ptr2=ptr1->next;
	ptr3=ptr2->next;
	ptr1->next=NULL;
	ptr2->next=ptr1;
	while(ptr3!=NULL)
	{
		ptr1=ptr2;
		ptr2=ptr3;
		ptr3=ptr3->next;
		ptr2->next=ptr1;
	}
	start=ptr2;
}
//Display elements
void Linked_List::display()
{
	struct node *temp;
	if(start==NULL)
	{
		cout<<"Empty List\n";
		return;
	}
	temp=start;
	cout<<"The Elements are: "<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL\n";
}
void Linked_List::sorting()
{
	struct node *ptr,*s;
	int value;
	if(start==NULL)
	{
		cout<<"Empty List\n";
		return;
	}
	ptr=start;
	while(ptr!=NULL)
	{
		for(s=ptr->next;s!=NULL;s=s->next)
		{
			if(ptr->data>s->data)
			{
				value=ptr->data;
				ptr->data=s->data;
				s->data=value;
			}
		}
		ptr=ptr->next;
	}
}