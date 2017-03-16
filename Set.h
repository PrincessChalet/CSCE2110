/*
Author: Chalet Shelton
Date: Februrary 3, 2017 
Instructor: Fahmida
Description: This is the .h file that is included in main.cpp. This file includes the class Set
	the function prototypes and all of the libraries.
*/

#include <iostream>
//#include "Set.cpp"
//#include <stdio.h>

using namespace std;

const int NUM_OF_SETS = 5;
const int NUM_WORDS = 5;

class Set
{
	private:
		struct Node
		{
			int data;
			Node *next;
		};
		Node *head;
		Node *tail;

		int count;
	public :
		Set();
		//Set(const Set& s);	// copy constructor
		//~Set();
		void clear();
		void addToSet(int i);
		void removeFromSet(int i);
		int cardinality();
		int is_member(int i);
		bool find(int i) const;
		bool check(int i); //check for rep. value
		void operator=(const Set& s); // copy a set
		Set operator&(const Set& s);//, const Set& d);	// intersection
		Set operator|(const Set& s);	// union
		Set operator^(const Set& s);	// exclusive OR
		Set operator-(const Set& s);	// set difference
		void printSet();
//		void debug();
//		int array[100];
};
