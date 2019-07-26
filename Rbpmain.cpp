/*
 * Written By: Sean M. .J.
 * Date Written: 7/22/19
 * Code Workins: To translate text -> morse Code -> Blinking LED's
 * 				 	that correspond to the that was letter given.
 */
#include <iostream>
using std::cout;	using std::endl;
#include <string>
using std::string;
#include "rbp.h"

int main()
{
	string s("Thunder");	
	//Translate a string to morse code
	string t = translate(s);
	//Print morse code to follow along with the LED blinking
	cout << t << endl;
	//Run the lights as morse code
	for(;;)
		morse_light(t);
	//Turn off the lights, stars the end of the program
	kill_code();
	return 0;
}

