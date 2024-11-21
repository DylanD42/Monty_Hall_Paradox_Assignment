
#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time()
#include <iomanip> // for set precision
using namespace std;

bool monty_hall(int userSelectedDoor);
//void gameshowPrint(int userDoor, int openedDoor);
void simulate(int num_iterations);

int main() {
  
  srand(time(0));
  int userChoice, simulationSize;
  
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
      cout << " You chose 2 " << endl
	   << "How many times do you want to simulate? "
	   << endl << ": ";
      cin >> simulationSize;
      simulate(simulationSize);
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
void simulate(int num_iterations){
  int wins, losses, total, switch_or_stay, userDoor, carDoor, openedDoor, otherDoor;
  wins = losses = total = 0;
  userDoor = 1; // users door will be 1 for every case;
  
  cout << "What would you like to do for all cases? " << endl <<"1: Stay with the original door" << endl << "2: Switch to the unopened door?" << endl << endl << ": ";
  cin >> switch_or_stay;
  switch (switch_or_stay){
  case 1:{
    cout << "You decided to stay." << endl;
    break;
      
  }
  case 2:{
    cout << "You decided to switch." << endl;
    
    break;
  }
  default:{
    cout << "That isn't a option." << endl;
    break;
  }}
  //int wins, losses, total, switch_or_stay, userDoor, carDoor, openedDoor, otherDoor;
  for(int i = 0; i < num_iterations; i++){
    total++;
    carDoor = 1 + (rand()%3);

    if (userDoor == carDoor){
      if (userDoor == 3){
	otherDoor = (rand()%2)+1;
      }
      else{
	otherDoor = userDoor + 1;
      }
    }
    if (userDoor != carDoor){
      if((userDoor + carDoor) == 5){
	openedDoor = 1;
	if(userDoor == 2){
	  otherDoor = 3;
	}
	else if(userDoor == 3){
	  otherDoor = 2;
	}
      }
      else if((userDoor + carDoor) == 4){
	openedDoor = 2;
	if(userDoor == 1){
	  otherDoor = 3;
	}
	else if(userDoor == 3){
	  otherDoor = 1;
	}
      }
      else if((userDoor + carDoor) == 3){
	openedDoor = 3;
	if (userDoor == 1){
	  otherDoor = 2;
	}
	else if (userDoor == 2){
	  otherDoor = 1;
	}
      }
    }
    
    
    if (switch_or_stay == 1){
      if(userDoor == carDoor){
	//cout << "WIN!" << endl;
	wins++;
      }
      else{
	//cout << "LOSE!" << endl;
	losses++;
      }
    }
    
    else if(switch_or_stay == 2){
      userDoor = otherDoor;
      if(userDoor == carDoor){
	//cout << "WIN!" << endl;
	wins++;
      }
      else{
	//cout << "LOSE!" << endl;
	losses++;
      }
    }
    
  }
  double winPercent  = wins*100.000000/total;
  double lossPercent = losses*100.00000/total;
  
  cout << "Wins: " << wins << endl
       << "Losses: " << losses << endl
       << "Total: " << total << endl;
  cout << fixed << setprecision(6);
  cout << "Win %: " << winPercent << '%' <<endl
       << "Loss %: " << lossPercent << '%' << endl << endl;
  cout << fixed << setprecision(2);

  
  
}

 
