#include "functions.h"


//PRE: takes in the integer that is being searched, an array, and the array size
//POST: if the integer exists in the array, returns the index of the integer, if intger does not exist, then return -1
int findInt(int target, int arr[], int arraySize){
  for (int i = 0; i < arraySize; i++){
    if(arr[i] == target){
      cout << "The number " << target << " is at position " << i << endl;
      return i;
    }
  }
  cout << "The number " << target << " is not in the array" << endl;
  return -1;
}

//PRE: takes in the index of the integer to be changed in the array, the new value of the integer, and the array
//POST: changes the integer value to the new value and outputs the old value and the new value
void changeInt(int index, int newInt, int arr[]){
  int oldInt = arr[index];
  arr[index] = newInt;
  cout << "Old Value: " << oldInt << endl;
  cout << "New Value: " << newInt << endl << endl;
}

//PRE: takes in the new integer to be added, the array, and size of the array
//POST: adds the new integer to the end of the array
void addInt(int num, int arr[], int arraySize){
  for(int i = 0; i < arraySize; i++){
    if(arr[i] == 0){
      arr[i] = num;
      arr[i + 1] = 0;
      return;
    }
  }
}

//PRE: takes in an inetger representing the index of the array, an array, and the array size
//POST: removes the integer at the position given, shifting all following numbers back
void delInt(int index, int arr[], int arraySize){
  int endOfArray = 0;
  for(int i = 0; i < arraySize; i++){
    if(arr[i] == 0){
      endOfArray = i;
      break;
    }
  }
  for(int i = index; i < endOfArray; i++){
    arr[i] = arr[i + 1];
  }
}


//PRE: takes in an empty array
//POST: fills the array with integers from an input file
//NOTE: the end of array is shown by the integer 0
void readFile(int arr[]){
  try{
    ifstream inputFile;
    int integer;
    inputFile.open("array.txt");

    if(inputFile.is_open()){
      int index = 0;
      while(!inputFile.eof()){
        inputFile >> integer;
        arr[index] = integer;
        index++;
      }
      arr[index] = 0;
    }
    else {
		  throw runtime_error("Unable to Read file.");
	  }
  }
  catch(runtime_error err) {
		cout << err.what();
  }
}

//PRE: takes in an array and its size
//POST: prints the array
void printArray(int arr[], int arraySize){
  int count = 0;
  int endOfArray = 0;
  //checks for the integer 0, which indicates the end of the array
  for(int i = 0; i < arraySize; i++){
    if(arr[i] == 0){
      endOfArray = i;
      break;
    }
  }
  cout << "Printing Array: " << endl;
  for(int j = 0; j < endOfArray; j++){
    cout << arr[j] << " ";
    count++;
    if(count == 10){
      cout << endl;
      count = 0;
    }
  }
  cout << endl << endl;
}