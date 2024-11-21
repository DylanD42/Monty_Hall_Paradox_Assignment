
#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time()

using namespace std;

bool monty_hall(int userSelectedDoor);
//void gameshowPrint(int userDoor, int openedDoor);
//void simulate(int num_iterations);

int main() {
  
  srand(time(0));
  int userChoice;
  cout << "Welcome to the Monty Hall Paradox!" << endl
       << endl << "To start out, what would you like to do?" << endl;
  do{
    cout << endl << "1: Run the game show yourself" << endl
	 << "2: Simulate the game multiple times" << endl
	 << "3: Exit the program" << endl << endl
	 << ": ";
    cin >> userChoice;
    cout << endl;

    switch (userChoice){
    case 1: {
      int userDoor;
      cout << " You chose 1 ";
      
      cout << "What door do you want to select? 1, 2 or 3?" << endl << ": ";
      cin >> userDoor;
      bool outcome = monty_hall(userDoor);
      cout << endl << endl << outcome << endl;
      break;
    }
    case 2:{
      cout << " You chose 2 ";
      break;
    }
    case 3:{
      cout << " You chose 3 ";
      break;
    }
    default:{
      cout << " You chose none ";
      break;
    } 
    }} while (userChoice != 3);
  
  return 0;
}
  
bool monty_hall(int userSelectedDoor){
  int carDoor = 1 + (rand()%3);
  int shownDoor, unopenedDoor;
  if (userSelectedDoor == carDoor){
    if (userSelectedDoor == 3){
      shownDoor = (rand()%2)+1;
    }
    else{
      shownDoor = userSelectedDoor + 1;
    }
  }
  if (userSelectedDoor != carDoor){
    if((userSelectedDoor + carDoor) == 5){
      shownDoor = 1;
      if(userSelectedDoor == 2){
	unopenedDoor = 3;
      }
      else if(userSelectedDoor == 3){
	unopenedDoor = 2;
      }
    }
    else if((userSelectedDoor + carDoor) == 4){
      shownDoor = 2;
      if(userSelectedDoor == 1){
	unopenedDoor = 3;
      }
      else if(userSelectedDoor == 3){
	unopenedDoor = 1;
      }
    }
    else if((userSelectedDoor + carDoor) == 3){
      shownDoor = 3;
      if (userSelectedDoor == 1){
	unopenedDoor = 2;
      }
      else if (userSelectedDoor == 2){
	unopenedDoor = 1;
      }
    }
  }
  cout << "You chose door: " << userSelectedDoor << endl
       << "Dealer opened door: " << shownDoor << endl << endl;
    //<< "The car is behind door: " << carDoor;
  int userSecondChoice;
  cout << "What would you like to do? " << endl <<"1: Stay with your original door" << endl << "2: Switch to the unopened door?" << endl << endl << ": ";
  cin >> userSecondChoice;
  switch (userSecondChoice){
  case 1:{
    cout << "You decided to stay." << endl;
    break;
      
  }
  case 2:{
    cout << "You decided to switch." << endl;
    userSelectedDoor = unopenedDoor;
    break;
  }
  default:{
    cout << "That isn't a option." << endl;
    unopenedDoor = 5;
    break;
  }}
  cout << "Users Door: " << userSelectedDoor << endl;
  cout << "Unopened Door: " << unopenedDoor << endl;
  cout << "Opened Door: " << shownDoor << endl;
  cout << "Car Door: " << carDoor << endl;
  
  if(userSelectedDoor == unopenedDoor){
    cout << "WIN!" << endl;
    return true;
  }
  else{
    cout << "LOSE!" << endl;
    return false;
  }
  
  
}
/*
void simulate(int num_iterations){
  for(int i = 0; i < num_iterations; i++){
    monty_hall();
  }
};

  */
