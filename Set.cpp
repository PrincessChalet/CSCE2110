/*
Author: Chalet Shelton
Date: Fubrurary 3, 2017
Instructor: Fahmida
Description: This is the function definitions file. It includes the Set.h file. 
*/
#include "Set.h"

Set::Set()
{
	head = tail = NULL;
	count = 0;
}
/*Set::~Set() {
	Node* current = head;
	while( current != 0 )
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = 0;
}*/
void Set::addToSet(int i)
{
	if(head == NULL) // if head is empty
	{
		Node *temp = new Node; //create new node
		temp->data = i; // set date in new node to i
		count++; // increase the count
		temp->next = NULL; // set next to null
		head = tail = temp; // set head and tail to temp

	}
	else //if head is not empty
	{
		Node *temp = new Node; //create new node
		temp->data = i; //set data in new node to i
		count++; // increase the count
		tail->next = temp; // set next to temp
		tail = tail->next; //set tail to next

	}
}
void Set::printSet()
{
	Node* current = head; // create iterator current

	if(!head) // if we are not at the head node
	{
		return; //return the node
	}
	while(current != NULL) // while current is not null
	{
		cout<< current->data <<endl; //print data in that node
		current = current->next; //go to next node
	}
}
void Set::clear()
{
	head = tail = NULL; // head and tail are empty
	count = 0; // initilize count
}
void Set::operator=(const Set& s) //POTENTIAL PROBLEM, WHY DOES THIS WORK? 
{
	//head = s.head;
	Node *temp = s.head, *temp2; //create new nodes
	head = NULL; // head is empty

	while(temp != NULL) //while temp is not null
	{
		temp2 = new Node; //create new node temp2
		temp2->data =temp->data; //set data in set B to data in set A
		temp2->next = head; //set the next node to head
		head = temp2; // head is in set B
		temp = temp->next; // pretty intutive
	}
}
Set Set::operator&(const Set& s) //intersection
{
	Set result; //creating new object set
	Node* temp = head; //create temp node sets equal to head
	if(head == NULL || s.head == NULL) // if the head in set A is empty or the head in set B is empty
	{
		return result; //return result
	}
	else
	{
		while(temp != NULL) // while set/temp is not empty
		{
			if(s.find(temp->data)) //if element on the left set is in the second set
			{
				result.addToSet(temp->data); //add to result set
			}
			temp = temp->next; //point temp to next
		}
	}
	return result;
}
bool Set::find(int i) const
{
	Node *temp = head;

	while(temp != NULL)
	{
		if(temp->data == i)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}
Set Set::operator|(const Set& s) //union
{
	Set result;
	Node* temp = head;

	if(count == 0 && s.count == 0) // if both sets are empty return empty set
	{
		return result;
	}
	else
	{
		while( temp != NULL) // whiel temp set is not NULL
		{
			result.addToSet(temp->data); // add the first set
			temp = temp->next; //set temp to next
		}

		temp = s.head; // now temp is pointing to 2nd set

		while(temp != NULL)
		{
			if(result.find(temp->data)) // if data is in prev set
			{
				break; //break. IDK why this works but itdoes
			}
			else
			{
				result.addToSet(temp->data);// else add num to set
				temp = temp->next; //set pointer to next
			}
		}
		return result;
	}
}
int Set::cardinality() //pretty intutive, no need for comments
{
	Node *temp = head;
	int ones = 0;
	while(temp != NULL)
	{
		ones++;
		temp = temp->next;
	}
/*	for(int i = 0; i < NUM_WORDS; i++)
	{
		if(find(temp->data))
		{
			ones++;
		}
		temp = temp->next;
	}*/
	return ones;
}
Set Set::operator-(const Set& s)
{
	Set result;
	Node* temp = head;

	while(temp != NULL) // in A
	{
		if(s.find(temp->data)); // if we find head in set B, do nothing
		else
		{
			result.addToSet(temp->data);
		}
		temp = temp->next;
	}
	return result;

}
void Set::removeFromSet(int i)
{
	if(find(i) == true)
	{
		Node *temp = head;
		Node *prev = head;

		while(temp != NULL)
		{
			//if(temp == head)
			//{
			//	head = head->next;
			//}
			if(temp->data == i)
			{
				prev->next = temp->next;
				temp = temp->next;
			}
			else
			{
				prev = temp;
				temp = temp->next;
			}
		}
	}
}
Set Set::operator^(const Set& s) //exclusive OR
{
	Set result;
	Node *temp = head;

	/*result.addToSet(temp->data);
	head.removeFromSet;*/
	while(temp != NULL)
	{
		if(s.find(temp->data));
		else
		{
			result.addToSet(temp->data);
		}
		temp = temp->next;
	}
	return result;
	/*temp = s.head;
	while( temp != NULL)
	{
		if(find(temp->data));
		else
		{
			result.addToSet(temp->data);
		}
		temp = temp->next;
	}*/
}
