//Dario Molina, Regie
//11/6/15
// Description:  Write a camel game, that implements the desired inputs.
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

void drink( int& water, int& thirsty);
void moderateSpeed( int& userDistance, int& thirsty, int& sleepy, int& themDistance);
void fullSpeed( int& userDistance, int& thirsty, int& sleepy, int& themDistance);
void information(int& thirsty, int& sleepy, int& userDistance, int& themDistance, int& water, bool& finish);
 


int main()
{
 int thirst = 0, random;
 int tiredness = 0;
 int milesTraveled = 0;
 int nativeDistance = -20;
 int canteen = 10;
 bool done = false;
 char userInput;
 
 srand(time(0));
 
 cout << "Welcome to Camel!" << endl;
 cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
 cout << "The natives want their camel back and are chasing you down! Sruvive your desert trek and outrun the narives." << endl << endl;
 
 while( done == false)
 {
   cout << "A. Drink from your canteen.\n"
           "B. Ahead moderate speed.\n"
           "C. Ahead full speed.\n"
           "D. Stop and rest.\n"
           "E. Status check.\n"
           "Q. Quit.\n\n";
           
   cin >> userInput;
   userInput = toupper( userInput);
   
   cout << " Your choice? " << userInput << endl;
   
   switch( userInput)
   {
     case 'A':
     {
       drink( canteen, thirst);
      break;
     }
     case 'B':
     {
       moderateSpeed( milesTraveled, thirst, tiredness, nativeDistance);
       information( thirst, tiredness, milesTraveled, nativeDistance, canteen, done);
      break;
     }
     case 'C':
     {
      fullSpeed( milesTraveled, thirst, tiredness, nativeDistance);
      information( thirst, tiredness, milesTraveled, nativeDistance, canteen, done);
      break;
     }
     case 'D':
      {
        information( thirst, tiredness, milesTraveled, nativeDistance, canteen, done);
        break;
      }
     case 'E':
     {
     
     information( thirst, tiredness, milesTraveled, nativeDistance, canteen, done);
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
      cout << " Your are no longer thirsty.\n ";
    }
    
   else
    {
      cout << "You ran out of water in your canteen.\n";
    }
}

void moderateSpeed( int& userDistance, int& thirsty, int& sleepy, int& themDistance)
{
  int random1, random2;
  
  random1 = rand() % 8 + 5;
  random2 = rand() % 8 + 7;

  userDistance += random1;
  themDistance += random2;
  thirsty++;
  sleepy++;
  
  cout << "You traveled: " << random1 << " miles.\n";

}

void fullSpeed( int& userDistance, int& thirsty, int& sleepy, int& themDistance)
{
  int random1, random2, random3;
  
  random1 = rand() % 9 + 10;
  random2 = rand() % 8 + 7;
  random3 = rand() % 3 + 1;
  
  userDistance += random1;
  sleepy += random3;
  themDistance += random2;
  
  cout << " You traveled " << random1 << " miles\n";
}


void information(int& thirsty, int& sleepy, int& userDistance, int& themDistance, int& water, bool& finish)
{
    int random;
    
    random = rand() % 20 + 1;

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
     cout << " Your camel is getting tired.\n";
   }
   
   else if( sleepy > 8)
   {
     cout << " Your camel died.\n";
     finish = true;
   }
   
   if( userDistance <= themDistance )
    {
      cout << " Natives caught up, you lose!\n";
      finish = true;
    }
   
  else if ( userDistance - themDistance <= 15)
   {
     cout << "Natives are getting close.\n";
   }
  else if ( userDistance >= 200)
   {
     cout <<" Congratulations, you won!\n";
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
