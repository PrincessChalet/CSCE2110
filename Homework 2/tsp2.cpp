/*
Author: Chalet Shelton
Date: April 21, 2017
Instructor: Fahmida
Description: This program attempts to solve the travelling salesman problem, but it does not 
	produce the output that we were give. It also has repeating cities. Please be merciful! 
*/
#include <iostream>
using namespace std;

void initilizeArray(int **r, int size);
void swap(int *r,int x, int y); 
void permute(int *c, int **w, int x, int y, int* path); //pass in cities & weights array, orgin, and destination, and count

int smallest_cost = 10000000;
int find_cost(int** w, int* r, int size, int* path);
	
int main()
{
	char c;
	int orgin=0, destination=0, weight=0;
	int count=0; //keep track of how many cities there are 
	
	cin >> c >> orgin; //prime the input
	count++;
	while(c != 'a') //reading to get count for cities
	{
		count++;
		cin >> c >> orgin;	
	}
	count--;


	int final_path[count+1];

	int* cities = new int [count];
	for(int i = 0; i < count; i++)
	{
		cities[i] = i;
	}

	int **weights = new int *[count]; //create 2D array for weights
	for(int i=0; i < count; i++) // create the columns for the 2D dynamic array
	{
		weights[i] = new int[count];
	}
	
	initilizeArray(weights,count);
	
	cin.clear();
	cin  >> destination >> weight; //prime the input

	while(cin.get(c)) // read in all of the connections 
	{
		weights[orgin-1][destination-1] = weight; // set the weight equal to the corridents 
		weights[destination-1][orgin-1] = weight; // copy the value in the inverse index
		cin >> c >> orgin >> destination >>weight;
	}
	weights[orgin-1][destination-1] = weight; // set the weight equal to the corridents 
	weights[destination-1][orgin-1] = weight; // copy the value in the inverse index

	permute(cities, weights, 0, count, final_path);
	
	cout << "The shortest path is: ";
	for(int i = 0; i < count+1; i++)
	{
		cout << final_path[i] << " ";
	}
	cout << "and the weight is: " << smallest_cost << endl;

	for(int i =0; i <count; i++)
	{
		delete [] weights[i];
	}
	delete weights;
	delete cities;
}
void initilizeArray(int **r, int size)
{
	for(int i=0; i< size; i++)
	{
		for(int j =0; j <size; j++)
		{
			r[i][j] = 0;
		}
	}
}
void swap(int *r, int x, int y)
{
	int temp = r[x];
	r[x] = r[y];
	r[y] = temp;
}
int find_cost(int** w, int* r, int size, int* path) //passing in weights, cities, count, path
{
	int sum = 0;
	for(int i = 0; i < size; i++)
	{
		path[i] = r[i] + 1; //example: path 1 = city 1 + 1
		if(i + 1 == size); //if orgin is equal to count do nothing
		else
		{
			sum = sum + w[r[i]][r[i+1]]; // sum = sum + weights[cities[orgin]][cities[destination +1]]
		}
	}
	sum = sum+ w[size-1][0]; // sum = sum + weights[orgin -1][destination 1]

	if(sum < smallest_cost) //if sum is less than smallest cost
	{
		smallest_cost = sum; //smallest cost = sum
		path[size] = r[0] + 1; //path[count] = cities + 1
	}

	return 0;
}
void permute(int *c, int **w, int x, int y, int* path)
{
	int i;
	if(x == y)
	{
	/*
		EXAMPLE ARRAY: [1][2][3][4]
		For instance, say we're in cell 2, if our orgin = destination the sum is weight of cell 2 + weight of cell 1
		*/
		find_cost(w,c,y, path);	
	}
	else
	{
		for(i=x; i <= y; i++)
		{
		//in citi[i] swap the weight + the orgin, weight + orgin???
			swap(c,x,i); // swap the weights in the cities array
			permute(c, w, x+1, y, path);
			swap(c,x,i); // swap the weights in the cities array
		}
	}
}
