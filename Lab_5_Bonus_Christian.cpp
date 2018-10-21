// Author:				Jacob Christian
// Assignment Number:   Lab 5
// File Name:			Lab_5_Bonus_Chrisitan.cpp 
// Course/Section:      COSC 1337 Section 014
// Date:                November 11th, 2018
// Instructor:          Dr. Bernard Ku

#include <iostream>
#include <string>
#include <algorithm> // for stlSort()
#include <cstdlib> //for random_shuffle() function
#include <ctime> //To set seed to current time to randomly shuffe

using namespace std;

//Function Prototypes
void displayArray(string[], int);
void selectionSort(string[], int);
void stlSort(string[], int);
bool binarySearch(string[], int, string);


int main()
{
	const int SIZE = 20; //constant size of array used
	
	srand (time(0)); // use current time as seed for random generator
	
	bool binarySearchFound; //for true/false if binary search was found

	
	string name[SIZE] =
	    { "Collins, Bill",  "Smith, Bart",  "Michalski, Joe", "Griffin, Jim",
	      "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
	      "Allison, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
	      "Moretti, Bella", "Wu, Hong",     "Patel, Renee",   "Harrison, Rose",
	      "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth" };
		
	//Display original contents of the array:
	cout << "The original array is: " << endl;
	displayArray(name, SIZE);
	
	//Passing through selectionSort() and redisplaying
	cout << endl << "The original array through selection sort: " << endl;
	selectionSort(name, SIZE);
	displayArray(name, SIZE);
	
	//Shuffling the array so STL sort() can be used and shown as working
	cout << endl << "The array will now randomly be shuffled and redisplayed: " << endl;
	random_shuffle(name, name + SIZE);
	displayArray(name, SIZE);
	
	//sort() called to sort array
	cout << endl << "The shuffled array will now be sorted with STL sort() and redisplayed: " << endl;
	stlSort(name, SIZE);
	displayArray(name, SIZE);
	
	//Binary search section, using conditional ternary to display whether or not search value was found.
	cout << endl << "The array will now try for two different binary searches: " << endl;
	cout << "\tNow searching for Juan Moreno..." << endl;
	binarySearchFound = binarySearch(name, SIZE, "Moreno, Juan");
	(binarySearchFound) ? cout <<  "\tJuan Moreno was found in the array!" : cout << "\tJuan Moreno was not found in array.\n";

	cout << "\n\tNow searching for Jacob Christian..." << endl;
	binarySearchFound = binarySearch(name, SIZE, "Christian, Jacob");
	(binarySearchFound) ? cout << "\tJacob Christian was found in the array!" : cout << "\tJacob Christian was not found in array.";

	return 0;
}

					//FUNCTIONS AND THEIR DESCRIPTIONS//
					
/*****************************************************************************
** stlSort() uses sort() from the STL <algorithm> library. It uses an       **
** unknown sorting algorithm. This is to showcase powerful tools that C++   **
** has to offer, and that developers don't always have to rely on raw power **
** to complete the task.                                                    **
*****************************************************************************/
void stlSort(string nameArray[], int arraySize)
	{ sort(nameArray, nameArray + arraySize); }

//Simply displays the contents of the array. Called multiple times
void displayArray(string nameArray[], int arraySize)
	{ for (int index = 0; index < arraySize; index++)
		cout << nameArray[index] << endl; }

/******************************************************************************
** binarySearch() is a powerful searching algorithm that takes a sorted list **
** and searches, starting at the middle. If the array is not found, it will  **
** determine whether or not the value searching for is larger or smaller,    **
** then check 1/2 of that portion of the array. This is repeated until the   **
** searched item is found, else it will return false if not found.           **
******************************************************************************/
bool binarySearch(string nameArray[], int arraySize, string searchTerm)
{	
    int first = 0,
        middle,
        last = arraySize - 1;
    bool found = false;
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        
        if (nameArray[middle] == searchTerm)
        	{ found = true; }
        else if (nameArray[middle] > searchTerm)
            { last = middle - 1; }
        else
            { first = middle + 1; }
    }
    return found;
}
/********************************************************************************
** selectionSort() is a simple algorithm that sorts data pretty quickly. It    **
** will find the lowest value in an array and swap it with the first value in  **
** the array. Once the lowest value has been set, it moves on to the next      **
** index in the array and repeats the process until completely sorted.         **
********************************************************************************/
void selectionSort(string nameArray[], int arraySize)
{
	int minIndex;
	string minValue;

	for (int startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = nameArray[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (nameArray[index] < minValue)
			{
				minValue = nameArray[index];
				minIndex = index;
			}
		}
		nameArray[minIndex] = nameArray[startScan];
		nameArray[startScan] = minValue;
	
	}
}

/*
The original array is:
Collins, Bill
Smith, Bart
Michalski, Joe
Griffin, Jim
Sanchez, Manny
Rubin, Sarah
Taylor, Tyrone
Johnson, Jill
Allison, Jeff
Moreno, Juan
Wolfe, Bill
Whitman, Jean
Moretti, Bella
Wu, Hong
Patel, Renee
Harrison, Rose
Smith, Cathy
Conroy, Pat
Kelly, Sean
Holland, Beth

The original array through selection sort:
Allison, Jeff
Collins, Bill
Conroy, Pat
Griffin, Jim
Harrison, Rose
Holland, Beth
Johnson, Jill
Kelly, Sean
Michalski, Joe
Moreno, Juan
Moretti, Bella
Patel, Renee
Rubin, Sarah
Sanchez, Manny
Smith, Bart
Smith, Cathy
Taylor, Tyrone
Whitman, Jean
Wolfe, Bill
Wu, Hong

The array will now randomly be shuffled and redisplayed:
Smith, Cathy
Sanchez, Manny
Whitman, Jean
Rubin, Sarah
Griffin, Jim
Moretti, Bella
Johnson, Jill
Conroy, Pat
Moreno, Juan
Patel, Renee
Allison, Jeff
Kelly, Sean
Wu, Hong
Holland, Beth
Collins, Bill
Taylor, Tyrone
Wolfe, Bill
Smith, Bart
Michalski, Joe
Harrison, Rose

The shuffled array will now be sorted with STL sort() and redisplayed:
Allison, Jeff
Collins, Bill
Conroy, Pat
Griffin, Jim
Harrison, Rose
Holland, Beth
Johnson, Jill
Kelly, Sean
Michalski, Joe
Moreno, Juan
Moretti, Bella
Patel, Renee
Rubin, Sarah
Sanchez, Manny
Smith, Bart
Smith, Cathy
Taylor, Tyrone
Whitman, Jean
Wolfe, Bill
Wu, Hong

The array will now try for two different binary searches:
        Now searching for Juan Moreno...
        Juan Moreno was found in the array!

        Now searching for Jacob Christian...
        Jacob Christian was not found in array.
*/
