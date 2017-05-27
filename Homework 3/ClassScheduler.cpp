/*
Author: Chalet Shelton
Date: May 5, 2017
Instructor: Famadia
Description:
*/
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Classes
{
	string course_id;
	int numStu;
	int countclasses;
};
struct Rooms
{
	string room_id;
	int countroom;
};

int main()
{
	string _50min[10] = {"8:00am-8:50am", "9:00am-9:50am", "10:00am-10:50am", "11:00am-11:50am", "12:00pm-12:50pm", "1:00pm-1:50pm", "2:00pm-2:50pm", "3:00pm-3:50pm", "4:00pm-4:50pm", "5:00pm-5:50pm"}; // array for 50 minute classes
	string _90min[10] = {"8:00am-9:20am", "9:30am-10:50am", "11:00am-12:20pm", "12:30pm-1:50pm", "2:00pm-3:20pm", "3:30pm-4:50pm"};//array for 90 min classes
	string input;
	struct Classes arrayC[100]; //array for the classes
	int numClasses =0; //keeps track of # of classes
	int numRooms =0; // keeps track of the # of rooms
	struct Rooms arrayR[100]; // array for rooms
	
	cin >> input;
	cin >> input;

	while(input.compare("Rooms") != 0) // reading in class information
	{
		arrayC[numClasses].countclasses =0;
		arrayC[numClasses].course_id = input; //takes classname
		cout << input << " ";
		cin  >> input;
		arrayC[numClasses].numStu = atoi(input.c_str());
		arrayC[numClasses].countclasses++;
		cout << input <<endl;
		cin  >> input;
		numClasses++;
	}
	while(!cin.eof()) //room information
	{
		cin >> input;
		arrayR[numRooms].room_id = input;
		cout << input << " ";
		cin  >> input;
		arrayR[numRooms].countroom = atoi(input.c_str());
		cout << input << endl;
		numRooms++;
	}
	
	numRooms--;
	
	cout << "Day of Week      Room#     Class     Number of Students    Total           Time" << endl;  //Header:  daysofweek , roomnumbers,  classes, numofstudents
	
	int roomNum =0, MWFcount =0, TRcount =0; //counter for room number were on, time count for both MWF and TR

	//int total=0;
	for(int i =0; i < numClasses; i++) //loop through all of classes
	{
		int total =0; // total number of students in class so far
		while(total < arrayC[i].numStu)
		{
			total = total + arrayR[roomNum].countroom;
			cout << "MWF              " << arrayR[roomNum].room_id << "       " << arrayC[i].course_id << "      " << arrayR[roomNum].countroom << "                    " << total << "         " << _50min[MWFcount] << endl;
			MWFcount++;
			total = total + arrayR[roomNum].countroom;
			
			if(total < arrayC[i].numStu)
			{
				cout << "TUTHR            " << arrayR[roomNum].room_id <<"       " << arrayC[i].course_id <<"      " << arrayR[roomNum].countroom << "                    " << total << "         " << _90min[TRcount] << endl;
				TRcount++;
			}
			roomNum = roomNum +1; 
			if(roomNum >= numRooms)
			{
				roomNum =0;
			}
		}
	}
	
	cout << "Number of Classes: " << numClasses << endl;
	cout << "Number of Rooms: " << numRooms << endl;
	
	return 0;
}