/*

Craftperson:- Sameer Somkuwar

College: Pune Institute of Computer Technology

Problem statement:- 

As a scientist at ISRO controlling the latest lunar spacecraft Chandrayaan 3, your task is to develop a program that 
translates commands sent from Earth into instructions understood by the spacecraft. The spacecraft navigates through 
the galaxy using galactic coordinates, represented by x, y, z coordinates (x for east or west location, y for north or
south location, and z for distance above or below the galactic plane).

Requirements:-

You will be given the initial starting point (x, y, z) of the spacecraft and the direction it is facing (N, S, E, W, Up, Down). 
The spacecraft receives a character array of commands, and you are required to implement the following functionalities:

Move the spacecraft forward/backward (f, b): The spacecraft moves one step forward or backward based on its current direction.
Turn the spacecraft left/right (l, r): The spacecraft rotates 90 degrees to the left or right, changing its facing direction.
Turn the spacecraft up/down (u, d): The spacecraft changes its angle, rotating upwards or downwards.

Note:-

1. The spacecraft’s initial direction (N, S, E, W, Up, Down) represents the reference frame for movement and rotation.
2. The spacecraft cannot move or rotate diagonally; it can only move in the direction it is currently facing.
3. Assume that the spacecraft’s movement and rotations are rigid, and it cannot move beyond the galactic boundaries.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	// We can take test case from user as well.
	/*
	
	int numberOfCommands;
	cout << "Enter the numbers of commands: ";
	cin >> numberOfCommands;
	cout << endl;

	char command[numberOfCommands];

	cout << "Enter the commands(f,b,l,r,u,b): ";
	for(int i = 0 ; i < numberOfCommands ; i++)
	{
		cin >> command[i];
	}
	cout << endl;

	int x, y, z;
	cout << "Enter the starting coordinated(x, y, x) : ";
	cin >> x >> y >> z;
	cout << endl;

	char currentFacingDirection,previousFacingDirection;
	cout << "Enter the initial facing direction of rover(N, S, E, W, U, D) : ";
	cin >> currentFacingDirection ;
	cout << endl;

	previousFacingDirection = currentFacingDirection;
	
	*/

	// Sample test case is taken.
	
	char command[] = {'f','r','u','b','l'};
	
	int numberOfCommands = 5;
	
	int x = 0, y = 0, z = 0;
	
	char currentFacingDirection = 'N', previousFacingDirection = 'N';
	
	cout << "Number of commands: " << numberOfCommands << endl;
	
	cout << "Commands send to rover: " ;
	for(int i = 0 ; i < numberOfCommands ; i++)
	{
		cout << command[i] <<" ";
	}cout << endl;
	
	cout << "Initial position of rover(x, y, z): " << x << " " << y << " " << z << endl;
	
	cout << "Initial facing direction: " << currentFacingDirection << endl;
	
	for(int i = 0 ; i < numberOfCommands ; i++)
	{
		
		if(currentFacingDirection == 'N' && command[i] == 'f') y++;
		else if(currentFacingDirection == 'N' && command[i] == 'b') y--;
		else if(currentFacingDirection == 'N' && command[i] == 'r') {currentFacingDirection = 'E'; previousFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'N' && command[i] == 'l') {currentFacingDirection = 'W'; previousFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'N' && command[i] == 'u') {currentFacingDirection = 'U'; previousFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'N' && command[i] == 'd') {currentFacingDirection = 'D'; previousFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'E' && command[i] == 'f') x++;
		else if(currentFacingDirection == 'E' && command[i] == 'b') x--;
		else if(currentFacingDirection == 'E' && command[i] == 'r') {currentFacingDirection = 'S'; previousFacingDirection = 'E';
		}
		else if(currentFacingDirection == 'E' && command[i] == 'l') {currentFacingDirection = 'N'; previousFacingDirection = 'E';
		}
		else if(currentFacingDirection == 'E' && command[i] == 'u') {currentFacingDirection = 'U'; previousFacingDirection = 'E';
		}
		else if(currentFacingDirection == 'E' && command[i] == 'd') {currentFacingDirection = 'D'; previousFacingDirection = 'E';
		}
		else if(currentFacingDirection == 'S' && command[i] == 'f') y--;
		else if(currentFacingDirection == 'S' && command[i] == 'b') y++;
		else if(currentFacingDirection == 'S' && command[i] == 'r') {currentFacingDirection = 'W'; previousFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'S' && command[i] == 'l') {currentFacingDirection = 'E'; previousFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'S' && command[i] == 'u') {currentFacingDirection = 'U'; previousFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'S' && command[i] == 'd') {currentFacingDirection = 'D'; previousFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'W' && command[i] == 'f') x--;
		else if(currentFacingDirection == 'W' && command[i] == 'b') x++;
		else if(currentFacingDirection == 'W' && command[i] == 'r') {currentFacingDirection = 'N'; previousFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'W' && command[i] == 'l') {currentFacingDirection = 'S'; previousFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'W' && command[i] == 'u') {currentFacingDirection = 'U'; previousFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'W' && command[i] == 'd') {currentFacingDirection = 'D'; previousFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'U' && command[i] == 'f') z++;
		else if(currentFacingDirection == 'U' && command[i] == 'b') z--;
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'N' && command[i] == 'r') {currentFacingDirection = 'E';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'N' && command[i] == 'l') {currentFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'N' && command[i] == 'u') {currentFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'N' && command[i] == 'd') {currentFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'E' && command[i] == 'r') {currentFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'E' && command[i] == 'l') {currentFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'E' && command[i] == 'u') {currentFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'E' && command[i] == 'd') {currentFacingDirection = 'E';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'S' && command[i] == 'r') {currentFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'S' && command[i] == 'l') {currentFacingDirection = 'E';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'S' && command[i] == 'u') {currentFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'S' && command[i] == 'd') {currentFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'W' && command[i] == 'r') {currentFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'W' && command[i] == 'l') {currentFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'W' && command[i] == 'u') {currentFacingDirection = 'E';
		}
		else if(currentFacingDirection == 'U' && previousFacingDirection == 'W' && command[i] == 'd') {currentFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'D' && command[i] == 'f') z--;
		else if(currentFacingDirection == 'D' && command[i] == 'b') z++;
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'N' && command[i] == 'r') {currentFacingDirection = 'E';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'N' && command[i] == 'l') {currentFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'N' && command[i] == 'u') {currentFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'N' && command[i] == 'd') {currentFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'E' && command[i] == 'r') {currentFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'E' && command[i] == 'l') {currentFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'E' && command[i] == 'u') {currentFacingDirection = 'E';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'E' && command[i] == 'd') {currentFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'S' && command[i] == 'r') {currentFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'S' && command[i] == 'l') {currentFacingDirection = 'E';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'S' && command[i] == 'u') {currentFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'S' && command[i] == 'd') {currentFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'W' && command[i] == 'r') {currentFacingDirection = 'N';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'W' && command[i] == 'l') {currentFacingDirection = 'S';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'W' && command[i] == 'u') {currentFacingDirection = 'W';
		}
		else if(currentFacingDirection == 'D' && previousFacingDirection == 'W' && command[i] == 'd') {currentFacingDirection = 'E';
		}	
		
	}
	
	cout << "Final position of rover will be: (" << x << ", " << y << ", " << z << ")" <<endl;
	
	cout << "Final direction of the rover will be: " << currentFacingDirection <<endl;
	
	return 0;
}

