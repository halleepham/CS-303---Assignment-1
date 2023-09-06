#include <iostream>
#include <fstream>
using namespace std;

//DESCRIPTION: A function to check if a certain integer exists in the array if the number is present return the index where the number is present
int findInt(int target, int arr[], int arraySize);

//DESCRIPTION: A function that can modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user
void changeInt(int index, int newInt, int arr[]);

//DESCRIPTION: A function that adds a new integer to the end of the array
void addInt(int num, int arr[], int arraySize);

//DESCRIPTION: A function which intakes an index of an array and removes the integer altogether
void delInt(int index, int arr[], int arraySize);

//DESCRIPTION: fills an array with integers from a text file
void readFile(int arr[]);

//DESCRIPTION: prints the array
void printArray(int arr[], int arraySize);