#include <iostream>
#include "ATM.h"
#include "ATMQueue.h"
#include "Node.h"
#include "Customer.h"

using namespace std;

int getSimParameters(int &simLen, int &numATM, int &numCustomers, int *&atime_list, int *&ttime_list);
void displaySimResults(int wait, int numCustomers);

int main () 
{
  // TO DO:: Rename these
  int simLen,numATM,numCustomers;
  int *atime_list, *ttime_list;

  // Total wait time for all customers in the simulation.
  int total_wait_time = 0;

  // Input code to read simulation parameters
  int param_err = getSimParameters(simLen, numATM, numCustomers, atime_list, ttime_list);
  if (param_err) 
  {
    cerr << "Error in simulation parameters." << endl;
    return -1;
  }

  cout << "numATM = " << numATM << endl;
  cout << "numCustomers = " << numCustomers << endl;
  // TO DO:: Your simulation code goes here.
 
  ATM atmArray[numATM]; // Creating an array of ATMs
 
  // Filling ATMs
  for (int k = 0; k < numATM; k++)
  {
    atmArray[k] = ATM();
  }

// Printing the contents of the ATMs
  for (int i = 0; i < numATM; ++i)
  {
    cout << atmArray[i];
  }

  int minute = 0;
  int customersDone = 0;

  while (minute < simLen || customersDone < numCustomers)
  {
        // Process new customers
        while (customersDone < numCustomers && atime_list[customersDone] == minute)
        {
          cout << "New Customer has arrived!" << endl;
          Customer* newCustomer = new Customer(atime_list[customersDone], ttime_list[customersDone]);
          Node* newNode = new Node(newCustomer);
        
          int min_i = 0; // Index of smallest length ATM Queue
          int min = atmArray[0].getLength(); // Minimum ATM Queue
      
          // Finding smallest Length ATM Queue
          for (int j = 0; j < numATM; j++)
          {
              if (atmArray[j].getLength() < min)
              {
                min = atmArray[j].getLength();
                min_i = j;
              }
          }
          cout << "Smallest ATM queue is ATM " << min_i << endl;
          atmArray[min_i].insertCustomer(newNode);
          customersDone++;
          cout << "Customers done: " << customersDone << endl; 

        }

        // Process ATMs
        for (int l = 0; l < numATM; l++)
        {
          atmArray[l].processCustomer(minute);
          cout << "ATM contents: " << atmArray[l] << endl;
        }
        minute ++; 
  }

  //compute and output statistics
  for (int i = 0; i < numATM; i++)
  {
    total_wait_time += atmArray[i].getWaitTime();
  }
  // Display statistics on the simulation.
  displaySimResults(total_wait_time, numCustomers);
  // Return total_wait_time, will be used by test script.
  return total_wait_time;
}



// Read the simulation parameters from standard input (cin).
// Parameters:
// simLen: minutes to run simulation
// numATM: number of ATMs
// numCustomers: number of customers
// atime_list: array of customer arrival times
// ttime_list: array of customer transaction times
//    customer i arrives at time atime_list[i] and performs a transaction that takes ttime_list[i] minutes
//
// All parameters are pass-by-reference (note & character).  This means assignments in this function will affect value from calling function
// 
// Return value:
// returns 0 if successful read of input
// non-zero values used to denote failure
//   1: simulation time < 1
//   2: number of ATMs < 1
//   3: number of customers < 1
//   4: a customer's transaction time < 1
//   5: customer list is not sorted by arrival time
//   6: customer arrival time later than simulation end time
int getSimParameters(int &simLen, int &numATM, int &numCustomers, int *&atime_list, int *&ttime_list) {
  // Code to read simulation parameters.
  cout << "Run an ATM simulation" << endl;

  cout << "Enter the number of minutes" << endl;
  cin >> simLen;
  // Check input validity.
  if (simLen < 1) 
  {
    cerr << "Simulation for invalid length of time." << endl;
    return 1;
  }

  
  cout << "Enter the number of ATMs" << endl;
  cin >> numATM;
  // Check input validity.
  if (numATM < 1) 
  {
    cerr << "Simulation for invalid number of ATMs." << endl;
    return 2;
  }


  // Read customer list
  cout << "Enter the number of customers" << endl;
  cin >> numCustomers;
  if (numCustomers < 1) 
  {
    cerr << "Simulation for invalid number of customers." << endl;
    return 3;
  }
  // Allocate memory for customer list.
  atime_list = new int [numCustomers];
  ttime_list = new int [numCustomers];

  // Read numCustomers customers
  int atime = -1;
  int prevatime = -1;
  int ttime = 0;
  for (int i=0; i<numCustomers; i++) 
  {
    cout << "Enter customer arrival and transaction time." << endl;
    cin >> atime;
    cin >> ttime;

    // Check input validity.
    if (ttime < 1) 
    {
      cerr << "Invalid transaction time." << endl;
      return 4;
    }
    if (atime < prevatime) 
    {
      cerr << "Arrival times not sorted." << endl;
      return 5;
    }
    if (atime >= simLen) 
    {
      cerr << "Arrival time later than simulation end time." << endl;
      return 6;
    }
    prevatime = atime;

    atime_list[i] = atime;
    ttime_list[i] = ttime;
  }

  // All went well, return 0.
  return 0;
}


// Display statistics on the simulation.
// wait: Total wait time of all customers in simulation.
// numCustomers: total number of customers in simulation.
void displaySimResults(int wait, int numCustomers) 
{
  cout << "Simulation results" << endl;
  cout << "Number of customers: " << numCustomers << endl;
  cout << "Total wait time: " << wait << endl;
  cout << "Average wait time: " << ((double) wait)/((double) numCustomers) << endl;
}
