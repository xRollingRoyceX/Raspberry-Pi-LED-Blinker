#include <wiringPi.h>
#include <string>
using std::string;

/*
 * almost all examples of this code online are using a layer of complexity that is unnessassary,
 * and python, ruby, and java always look like its hard to understand unless your the one who wrote it (IMHO)
 * anyways this code is simple to follow and rather well formatted 
 * (even my dad could read it... and he does not understand code)
 
 LED's must be changed here: void kill_code();
 and here: 					 int morse_light(string morse_message);

 ---
 ---
 * https://www.youtube.com/watch?v=fX2W3nNjJIo 1:00:05 ("dont be clever") section (amoungst other sections)
*/

//if you want to use a global vars:

//const short GPIO_LED_Red = [GPIO #]
//const short GPIO_LED_Blue = [GPIO #]

char change_case(char& chr)
{
	if(isupper(chr))
		return tolower(chr);
	else
		return chr;
}

//assumes a string w/o numbers and special characteres.
//TODO: if-else regarding errors and inputs
string translate(string& trans_str)
{
	string hld = " ";
	for(char i = 0; i != trans_str.size(); ++i)
	{
		trans_str[i] = change_case(trans_str[i]); //for uniform user input - make all inputed values to lowercase -
		//rule #1 3 units after the end of a char
		//rule #2 7 units after the end of a word			
		switch(trans_str[i])
		{
			case('a') : hld += ".- ";
			break;
			case('b') : hld += "-... ";
			break;
			case('c') : hld +=  "-.-. ";
			break;
			case('d') : hld +=  "-.. ";
			break;
			case('e') : hld +=  ". ";
			break;
			case('f') : hld +=  "..-. ";
			break;
			case('g') : hld +=  "--. ";
			break;
			case('h') : hld +=  ".... ";
			break;
			case('i') : hld +=  ".. ";
			break;
			case('j') : hld +=  ".--- ";
			break;
			case('k') : hld +=  "-.- ";
			break;
			case('l') : hld +=  ".-.. ";
			break;
			case('m') : hld +=  "-- ";
			break;
			case('n') : hld +=  "-. ";
			break;
			case('o') : hld +=  "--- ";
			break;
			case('p') : hld +=  ".--. ";
			break;
			case('q') : hld += "--.- ";
			break;
			case('r') : hld +=  ".-. ";
			break;
			case('s') : hld +=  "... ";
			break;
			case('t') : hld +=  "- ";
			break;
			case('u') : hld +=  "..- ";
			break;
			case('v') : hld +=  "...- ";
			break;
			case('w') : hld += ".-- ";
			break;
			case('x') : hld += "-..- ";
			break;
			case('y') : hld += "-.-- ";
			break;
			case('z') : hld += "--.. ";
			break;
			default:
			break;
		}
			//I left out the numbers for others to do if they want to extend the code and get some practice with switch
			//... this is the first time i've used switch.
	}
	return hld;
}
int morse_light(string morse_message){
		// i realize that this should prob.  be a global var. but i dont like global vars. 
		// as i dont understand how the system uses them yet in ASM and everyone says not to use them or to use them,
		// as they say with goto, break, or continue. in this case i should use it, 
		// as its being used in two places as the same thing, in the same way... idk but i should trust my gut
	
	const short GPIO_LED_Red = 24;
	const short GPIO_LED_Blue = 3;
		
	wiringPiSetup();
	pinMode(0, OUTPUT);
	short tmp = 0;
	for(auto& i : morse_message)
	{
		if(i == '.')
		{
			delay(250);
			digitalWrite(GPIO_LED_Red, HIGH);
			digitalWrite(GPIO_LED_Blue, LOW);
			++tmp;
				
			if(tmp >= 1)
			{
				delay(250);
				digitalWrite(GPIO_LED_Red, LOW);
				digitalWrite(GPIO_LED_Red, LOW);
			}
		}
		else if(i == '-')
		{
			delay(500);
			digitalWrite(GPIO_LED_Blue, HIGH);
			digitalWrite(GPIO_LED_Red, LOW);
			++tmp;
			
			if(tmp >= 1)
			{
				delay(500);
				digitalWrite(GPIO_LED_Blue, LOW);
				digitalWrite(GPIO_LED_Blue, LOW);
			}
		}
		else if(isspace(i))
		{
				digitalWrite(GPIO_LED_Red, LOW);
				digitalWrite(GPIO_LED_Blue, LOW);
				delay(1500);
		}
		tmp = 0;		
	}
	
	return 0;
}
//if not being run as an infinate loop, call this code to turn off the lights at the end of the program.
void kill_code(){
    const short GPIO_LED_Red = 24;
	const short GPIO_LED_Blue = 3;
		
	//wiringPiSetup();
	//pinMode(0, OUTPUT);
	
	digitalWrite(GPIO_LED_Red, HIGH);
	digitalWrite(GPIO_LED_Blue, HIGH);
}

