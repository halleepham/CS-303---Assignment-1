#include "functions.h"
using namespace std;

//ASSUMPTIONS: the array can only include positive integers (not 0)
//When validating user inputs, if input is not valid, program ends

int main() {
  //initializes an integer array with the size of 150
  int nums[150];
  int arraySize = 150;
  
  //uses the readFile function to fill the array with numbers from the text file
  readFile(nums);
  int userChoice;

  //Prints the original array
  cout << "Original Array" << endl;
  printArray(nums, arraySize);
  
  //FOR THE GRADER: this is how you choose which function you want to test
  cout << "Choose a function to test:" << endl;
  cout << "\t1 - check if a certain integer exists" << endl;
  cout << "\t2 - modify the value of an integer" << endl;
  cout << "\t3 - add an integer to the end of the array" << endl;
  cout << "\t4 - delete an integer from the array" << endl;
  cout << "\t0 - quit the program" << endl;
  cout << "--> ";
  cin >> userChoice;
  cout << endl << endl;
  
  while(userChoice != 0){
    //FOR THE GRADER: This is what tests function #1
    if(userChoice == 1){
      int numToFind;
      cout << "What number would you like to look for in the array? --> ";
      cin >> numToFind;
      cout << endl;
      findInt(numToFind, nums, arraySize);
      cout << endl << endl;
    }

    //FOR THE GRADER: This is what tests function #2
    else if(userChoice == 2){
      int posToChange, newNum;
        //FOR THE GRADER: this is where part two of the assignment is (adding the try and catch block to validate user inputs)
        try{
          cout << "What position would you like to change? --> ";
          cin >> posToChange;
          if(!cin.good()){
            throw runtime_error("Please input a number.\n");
          }
          if(posToChange < 0){
            throw runtime_error("Please input a number greater or equal to 0\n");
          }
          cout << endl << "What integer would you like to change it to? --> ";
          cin >> newNum;
          if(newNum < 1){
            throw runtime_error("Please input a number greater than 0 (starting function over)\n");
          }
          changeInt(posToChange, newNum, nums);
          printArray(nums, arraySize);
        }
        catch(runtime_error err){
          cout << err.what();
          break;
        }
        catch(...){
          cout << "Please enter a positive integer\n";
          break;
        }
    }

    //FOR THE GRADER: This is what tests function #3
    else if(userChoice == 3){
      int numToAdd;
      //FOR THE GRADER: this is where part two of the assignment is (adding the try and catch block to validate user inputs)
      try{
        cout << "What integer would you like to add to the end of the array? --> ";
        cin >> numToAdd;
        cout << endl;
        if(numToAdd < 1){
          throw runtime_error("Please enter an integer greater than 0\n");
        }
        addInt(numToAdd, nums, arraySize);
        printArray(nums, arraySize);
      }
      catch(runtime_error err){
        cout << err.what();
        break;
      }
      catch(...){
        cout << "Please enter an integer\n";
        break;
      }
    }

    //FOR THE GRADER: This is what tests function #4
    else if(userChoice == 4){
      int numToDel;
      cout << "What position would you like to delete the integer at? --> ";
      cin >> numToDel;
      cout << endl;
      delInt(numToDel, nums, arraySize);
      printArray(nums, arraySize);
    }
    else if(userChoice == 0){
      break;
    }
    cout << "Choose a function to test:" << endl;
    cout << "\t1 - check if a certain integer exists" << endl;
    cout << "\t2 - modify the value of an integer" << endl;
    cout << "\t3 - add an integer to the end of the array" << endl;
    cout << "\t4 - delete an integer from the array" << endl;
    cout << "\t0 - quit the program" << endl;
    cout << "--> ";
    cin >> userChoice;
    cout << endl << endl;
  }
}