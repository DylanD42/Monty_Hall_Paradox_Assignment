
#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time()

using namespace std;

bool monty_hall(int userSelectedDoor);
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
      cout << endl << endl <<outcome << endl;
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
  int shownDoor;
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
    }
    else if((userSelectedDoor + carDoor) == 4){
      shownDoor = 2;
    }
    else if((userSelectedDoor + carDoor) == 3){
      shownDoor = 3;
    }
  }
  cout << "You chose door: " << userSelectedDoor << endl
       << "Dealer opened door: " << shownDoor << endl
       << "The car is behind door: " << carDoor;
  return true;
};
/*
void simulate(int num_iterations){
  for(int i = 0; i < num_iterations; i++){
    monty_hall();
  }
};

  */
