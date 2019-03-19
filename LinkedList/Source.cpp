#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct node1
{
	int data;
	struct node1 *next;
};
class linkedlist
{
public:
	struct node1 *start; //start node or head node

	linkedlist()
	{
		start = NULL;
	}
	void insertfirst(int);
	void deleteele(int);
	void traverse_forward();
	void traverse_backward();
	friend void print(struct node1 *);
	void reverse();
	void insert_pos();
	~linkedlist();
};
void linkedlist::insertfirst(int ele)
{ //this member function inserts an element at the begionning of the list
	struct node1 *temp; 
	temp = new node1;
	temp->data = ele;
	temp->next = start;
	start = temp; //making the start node or head node aas temp
}


void linkedlist::insert_pos() //this function inserts the element at a particular position
{
	int value, pos, counter = 0;
	cout << "Enter the value to be inserted: ";
	cin >> value;
	struct node1 *temp=NULL, *s, *ptr=NULL;
	temp = new node1;
	temp->data = value;
	cout << "Enter the postion at which node to be inserted: ";
	cin >> pos;
	int i;
	s = start;
	//using the counter variable in knowing the bounds of the positions where we can insert the element
	while (s != NULL)
	{
		s = s->next;
		counter++;
	}
	if (pos == 1) 
	{
		if (start == NULL)
		{
			start = temp;
			start->next = NULL;
		}
		else
		{
			ptr = start;
			start = temp;
			start->next = ptr;
		}
	}
	else if (pos > 1 && pos <= counter) //if position is within the bounds
	{
		s = start;
		for (i = 1; i < pos; i++)
		{
			ptr = s;
			s = s->next;
		}
		ptr->next = temp;
		temp->next = s;
	}
	else
	{
		cout << "Positon out of range" << endl;
	}
}



void linkedlist::deleteele(int ele)
{
	struct node1 *temp, *curr;
	if (start != NULL)
	{
		if (start->data == ele)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else
		{
			curr = start;
			while (curr->next != NULL && curr->next->data != ele)
			{
				curr = curr->next;
			}
			if (curr->next != NULL)
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "element not found";
		}
	}
	else
		cout << "list is empty";
}
void linkedlist::traverse_forward()
{
	struct node1 *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data<<" ";
		curr = curr->next;
	}
}
void print(struct node1 *curr)
{
	if (curr != NULL)
	{
		print(curr->next);
		cout << curr->data << " ";
	}
}
void linkedlist::traverse_backward()
{
	if (start != NULL)
		print(start);
}
//void print(struct node1 *curr)
//{
//	if (curr != NULL)
//	{
//		print(curr->next);
//		cout << curr->data;
//	}
//}
void linkedlist::reverse()
{
	struct node1 *rev, *temp;
	rev = NULL;
	if (start != NULL || start->next != NULL)
	{
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			temp->next = rev;
			rev = temp;
		}
		start = rev;
	}
}
linkedlist::~linkedlist()
{
	struct node1 *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}
int main()
{
	linkedlist a;
	cout << "enter 1.insert at beg\n 2. insert at n \n 3. reverse list \n4. forward printing\n 5.backward printing\n 6.delete particular ele \n ";
	int ch;
	int ele, e1;
	cin >> ch;
	while (ch <= 10)
	{
		switch (ch)
		{
		case 1:cout << "\nEnter an element";
			cin >> ele;
			a.insertfirst(ele);
			break;
		
		case 2: 
			a.insert_pos();
			break;
		case 3: cout << "After reversing\n";
			a.reverse();
			a.traverse_forward();
			break;
		case 4: a.traverse_forward();
			break;
		case 5: a.traverse_backward();
			break;
		case 6:
			cout << endl << "enter some ele to delete";
			int el;
			cin >> el;a.deleteele(el);
			break;
		 default:
			break;
		}

		cout << "\nEnter an operation to perform:";
		cin >> ch;
	}
	return 0;

}