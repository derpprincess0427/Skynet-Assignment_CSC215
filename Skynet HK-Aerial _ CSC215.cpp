/*
Alexus Dooley
07/22/2021
Skynet HK-Aerial Phase 1
Create a Grid search program that uses loops to locate an enemy
*/

//necessary libraries for assignment 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

//declare the namespace as standard 
using namespace std; 

//declare the string as standard
using std::string;

//main

int main()
{
	//declare variable for the string 
	string answer;

	//declare variables for the different algorithms and generators being used

	//establish the lowest number possible
	int searchGridLowNumber = 1;
	//establish the highest number possible
	int searchGridHighNumber = 64;
	//'seed' random number generator
	srand(static_cast<unsigned int>(time(0)));
	//set a range 
	int secretNumber = rand() % 64 + 1;
	//search algorithm looks at the possible guesses that are between the set range of numbers
	int targetLocationPrediction =
		((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

	//set variable to keep track of number of guesses
	int tries = 0;

	//start tests
	cout << "Let's place an enemy somewhere, sha'll we? \n";
	cout << "Our area of suspicion has been condensed down to an 8x8 mile area,\n";
	cout << "which we have turned into a grid and numbered each square mile from 1-64. \n";
	cout << "\n Still following? \n";
	cin >> answer;
	cout << "Okay good, let's get started! \n";
	cout << "\n Generating random enemy location on grid...\n";
	cout << "The enemy is located at Sector " << secretNumber << " on the grid!\n";
	cout << "Now we will test Skynet HK-Aerial Software to see how many tries it \n";
	cout << "will take to find the enemy we have just generated.\n";

	//Do-while loop running the algorithm and game text
	do
	{
		//increment tries here to get the first Ping
		++tries;
		cout << "...\n";
		cout << "HK-Aerial Radar attempt #" << tries << "\n";

		//start the search algorithm for this cycle
		targetLocationPrediction =
			((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

		//start conditional to see if the guess is less or greater than the random number

		//if guess is greater than the number...
		if (targetLocationPrediction > secretNumber)
		{
			cout << "The software guessed the enemy was located in Sector " << targetLocationPrediction << " \n";
			cout << "which is higher than the Sector number that the enemy is residing in. \n";
			cout << "As a result, the software will now use this number as its maximum, as guessing anything above it would be pointless. \n";
			cout << "Got it?\n";
				cin >> answer;
			cout << "Okay, now let's continue. \n";

			//assign this guess as the high number
			searchGridHighNumber = targetLocationPrediction;
			//tell the user
			cout << "The new maximum number possible is " << searchGridHighNumber << "\n";
		}
		//If the guess is lower than the number...
		else if (targetLocationPrediction < secretNumber)
		{
			cout << "The software guessed the enemy was located in Sector " << targetLocationPrediction << " \n";
			cout << "which is lower than the Sector number that the enemy is residing in. \n";
			cout << "As a result, the software will now use this number as its minimum, as guessing anything below it would be pointless. \n";
			cout << "Got it?\n";
				cin >> answer;
				cout << "Okay, now let's continue. \n";

			//assign this guess as the new low number
			searchGridLowNumber = targetLocationPrediction;
			//tell the user
			cout << "The new minimum number possible is " << searchGridLowNumber << "\n";
		}
		//Correct guess condition
		else if (targetLocationPrediction == secretNumber)
		{
			cout << "The software has successfully found the enemy hiding in Sector " << secretNumber << "\n";
			cout << "The target was found in Sector " << targetLocationPrediction << "\n";
			cout << "The Skynet HK-Aerial Software took " << tries << "guesses to find the enemy location!\n";
		}
	}
	//set the loop condition
	while (targetLocationPrediction != secretNumber);

	//main() return statement
	return 0;
}


