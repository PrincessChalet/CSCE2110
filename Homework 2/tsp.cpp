#include <iostream>
using namespace std;

void initilizeArray(int **r, int size);
void swap(int *r,int x, int y); 
void permute(int *c, int **w, int x, int y, int size); //pass in cities & weights array, orgin, and destination, and count

	
int main()
{
	char c;
	int orgin=0, destination=0, weight=0;
	int count=0; //keep track of how many cities there are 
	
	int cities[count];
	cin >> c >> orgin; //prime the input
	count++;
	while(c != 'a') //reading to get count for cities
	{
		cout << c <<orgin<<endl;
		cin >> c >> orgin;	
		count++;
	}
	
	int **path = new int*[count]; //creat 2D array for paths
	int **weights = new int *[count]; //create 2D array for weights
	for(int i=0; i < count; i++) // create the columns for the 2D dynamic array
	{
		path[i] = new int[count];
		weights[i] = new int[count];
	}
	
	initilizeArray(path, count);
	initilizeArray(weights,count);
	
	cin.clear();
	cin  >> destination >> weight; //prime the input

	while(cin.get(c)) // read in all of the connections 
	{
		cout <<c << orgin <<destination <<weight<<endl;
		cin >> c >> orgin >> destination >>weight;
		path[orgin-1][destination-1] = weight; // set the weight equal to the corridents 
	}

	permute(cities, weights, orgin, destination, count);
	
	//cout << sum;
	for(int i =0; i <count; i++)
	{
		delete [] path[i];
		delete [] weights[i];
	}
	//delete path;
	//delete weights;
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
	int temp = x;
	r[x-1]=r[y-1];
	r[y-1] = temp;
}
void permute(int *c, int **w, int x, int y, int size)
{
	int sum =0;
	//cout <<"test 1"<<endl;
	if(x == y)
	{
		/*
		EXAMPLE ARRAY: [1][2][3][4]
		For instance, say we're in cell 2, if our orgin = destination the sum is weight of cell 2 + weight of cell 1
		*/
		sum = w[x-1][y-1] + w[x-1][0];
	}
	else
	{
		//cout<<"test 2" <<endl;
		for(int i=x; i <y; i++)
		{
		//in citi[i] swap the weight + the orgin, weight + orgin???
			cout << "test 3"<<endl;
			swap((c[x-1]),(c[y-1])); // swap the weights in the cities array
			cout <<"test 4"<<endl;
			permute(c, w, x+1, y, size);
			cout <<"Test 5"<<endl;
			swap((c[x-1]), (c[y-1])); // backtrack
			sum = w[x-1][y-1] + w[x-1][0];
		}
	}
	cout << sum <<endl;
}