// Team: Regie Daquioag, Dario Molina
// Date: November 10, 2015
// Project: Camel/Appa Game

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

void drink(int& water, int& thirsty);
/*[
Precondition:  Takes in parameters by reference
Postcondition: Lets user drink water and keeps count of how many drinks are left
Summary:  Necessary to keep player alive during the game
*/
void moderateSpeed(int& userDistance, int& thirsty, int& sleepy, int& themDistance); 
/*[
Precondition:  Takes in arguments by reference
Postcondition:  It speeds up and advances certain miles
Summary: As a result, people chasing you get closer, and you and your ride get tired.
]*/
void fullSpeed(int& userDistance, int& thirsty,int& sleepy, int& themDistance);
/*[
Precondition:  Takes in arguments by reference
Postcondition:  It speeds up and advances user further miles than the moderate speed option.
Summary:  People chasing you get farther behind and you can keep going forward.

]*/
void stop(int& sleepy, int& themDistance); 
/*[
Precondition: Takes in arguments by reference
Postcondition:  It lets user rest as well as for their camel/ or appa.
Summary: Necessary to keep playing
]*/
void status(int userDistance, int water, int themDistance); 
/*[
Precondition: Takes in arguments by reference
Postcondition:  It lets user know the status of their game
Summary:  Necessary to make strategic decisions.
]*/
void information(int& thirsty, int& sleepy, int& userDistance, int& themDistance, int& water, bool& finish);
/*{
Preconditions: Takes in arguments by reference
Postconditon:  It informs the user of vital information that is happening during the game
Summary:  Samething as postcondition
}*/

int main()
{
 int thirst = 0;// declaration of all variables used
 int tiredness = 0;
 int milesTraveled = 0;
 int nativeDistance = -20;
 int canteen = 10;
 bool done = false;
 char userInput;
 
 srand(time(0));// random number generator
 
 cout << "Welcome to Free the Flying Bison!" << endl;// welcoming user to the game, and what they need to do
 cout << "You have taken your flying bison called Appa back from the Fire Nation, however you were seen spotted." << endl;
 cout << "The Fire Nation is trying to capture you and your bsion becuase you are the Avavtar, the last air bender." << endl;
 cout << "Try to survive the strom and make it back to your freinds in the Northern Water Tribe." << endl;
 cout << "Be warned, if you get stuck in the storm mulitple times you will get hit by lighting.\n" << endl;
 
 while( done == false)// keeps going until game is over
 {
   cout << "\nA. Drink from your canteen.\n";
   cout << "B. Ahead moderate speed.\n";
   cout << "C. Ahead full speed.\n";
   cout << "D. Stop and rest.\n";
   cout << "E. Status check.\n";
   cout << "Q. Quit.\n";
           
   cin >> userInput;
   userInput = toupper( userInput);
   
   cout << " Your choice? " << userInput << endl;
 
   
   switch( userInput)// switch dedicated to each input entered by the user
   {
     case 'A':
     {
        drink(canteen, thirst);
        information(thirst, tiredness, milesTraveled, nativeDistance, canteen, done);
        break;
     }
     case 'B':
     {
        moderateSpeed(milesTraveled, thirst, tiredness,nativeDistance);
        information(thirst, tiredness, milesTraveled, nativeDistance, canteen, done);
        break;
     }
     case 'C':
     {
        fullSpeed(milesTraveled, thirst ,tiredness, nativeDistance);
        information(thirst, tiredness, milesTraveled, nativeDistance, canteen, done);
        break;
     }
     case 'D':
      {
        stop(tiredness, nativeDistance);
        information(thirst, tiredness, milesTraveled, nativeDistance, canteen, done);
        break;
      }
     case 'E':
     {
        status(milesTraveled, canteen, nativeDistance);
        information(thirst, tiredness, milesTraveled, nativeDistance, canteen, done);
        break;
     }
     case 'Q':
      {
        done = true;
        break;
      }
   }
 
 }// While loop ends
return 0;
}

void drink( int& water, int& thirsty)
{
   if ( water > 0)
    {
      water--;
      thirsty = 0;
      
      cout << " Drinks left in canteen: " << water << endl;
      cout << " Your are no longer thirsty.\n";
    }
    
   else
    {
      cout << " You ran out of water in your canteen.\n";
    }
}

void moderateSpeed( int& userDistance, int& thirsty, int& sleepy, int& themDistance)
{
  int random1, random2;// random numbers used that make the game more interesting
  
  random1 = rand() % 8 + 5;
  random2 = rand() % 8 + 7;

  userDistance += random1;
  themDistance += random2;
  thirsty++;
  sleepy++;
  
  cout << " You traveled: " << random1 << " miles.\n";
  
}

void stop( int& sleepy, int& themDistance)
{
    int random;
    sleepy = 0; 
    
    random = rand() % 8 + 7;
    
    themDistance += random;
    cout << " Appa is no longer tired." << endl;
    
}

void status( int userDistance, int water, int themDistance)
{
    int awayMiles = userDistance - themDistance;
    
    cout << " You have traveled " << userDistance << "  miles.\n"
         << " You have " << water << " drinks left in your canteen.\n "
         << " The fire nation is " << awayMiles << " behind you." << endl; 

}

void fullSpeed( int& userDistance, int& thirsty, int& sleepy, int& themDistance)
{
    int random1, random2;
    int storm = 0;
    random1 = rand() % 11 +10;
    random2 = rand() % 8 + 7;
    
    userDistance += random1;
    cout << " You have traveled " << random1 << " miles.\n";
    thirsty++;
    sleepy++;
    themDistance += random2;
}

void information(int& thirsty, int& sleepy, int& userDistance, int& themDistance, int& water, bool& finish)
{
    int random;
    int random1;
    int storm = 0;
    
    random = rand() % 20 + 1;
    random1 = rand() % 6 + 1;

   if( thirsty > 4 && thirsty <= 6)
    {
      cout << " You are thirsty." << endl;
    } 
    
   else if( thirsty > 6)
   {
     cout << "You're dead, you didn't drink water.\n";
     finish = true;
   }
   
   if( sleepy > 5 && sleepy <= 8 )
   {
     cout << " Appa is getting tired.\n";
   }
   
   else if( sleepy > 8)
   {
     cout << " Appa has died.\n";
     finish = true;
   }
   
   if( userDistance <= themDistance )
    {
      cout << " Fire Nation caught up, you lose!\n";
      finish = true;
    }
   
   else if (random1 == 6)
    {
        cout << " Oh, no!! You are stuck in a storm and it brought you back 9 miles" << endl;
        
        userDistance = userDistance- 9;
        
        storm++;
    
    }
    
    else if (storm == 7)
    {
        cout << " I am sorry, but you have been hit by thunder.\n"
             << " You and Appa did not make it to your freinds\n";
        
        finish = true;
        
        
    }
  if ( userDistance - themDistance <= 15)
   {
     cout << " The Fire Nation is getting close.\n";
   }
  else if ( userDistance >= 200)
   {
     cout <<" Congratulations, you have made it back to your friends!\n";
     finish = true;
   }
   
   if ( random == 20)
    {
      cout << " Wow!! You found an Oasis!!\n"
           << " Your thirst will be fully replenished\n"
           << " Your canteen fully refilled\n"
           << " And you camel will be fully rested.\n";
      
      thirsty = 0;
      water = 10;
      sleepy = 0;
    
    }
    
 return;
}







