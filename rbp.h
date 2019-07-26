
#include <wiringPi.h>

#include <string>
using std::string;
//..
char change_case(char& chr){
	if(isupper(chr))
		return tolower(chr);
	else
		return chr;
}

string translate(string& trans_str)
{
		string hld = " ";
		for(char i = 0; i != trans_str.size(); ++i)
		{
			trans_str[i] = change_case(trans_str[i]); //for uniform user input - make all inputed values to lowercase -
			//rule #2 7 units after the end of a word
			switch(trans_str[i]){
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
				case('q'): hld += "--.- ";
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
		}
		return hld;

}

int morse_light(std::string morse_message){
	
		const int GPIO_LED_Red = 24;
		const int GPIO_LED_Blue = 3;
		
		wiringPiSetup();
		pinMode(0, OUTPUT);
		short tmp = 0;
		for(auto& i : morse_message)
		{
			if(i == '.'){
				delay(250);
				digitalWrite(GPIO_LED_Red, HIGH);
				digitalWrite(GPIO_LED_Blue, LOW);
				++tmp;
				
				if(tmp >= 1){
					delay(250);
					digitalWrite(GPIO_LED_Red, LOW);
					digitalWrite(GPIO_LED_Red, LOW);
				}
			}
			else if(i == '-'){
				delay(500);
				digitalWrite(GPIO_LED_Blue, HIGH);
				digitalWrite(GPIO_LED_Red, LOW);
				++tmp;
				
				if(tmp >= 1){
					delay(500);
					digitalWrite(GPIO_LED_Blue, LOW);
					digitalWrite(GPIO_LED_Blue, LOW);
				}
			}else if(isspace(i)){
					digitalWrite(GPIO_LED_Red, LOW);
					digitalWrite(GPIO_LED_Blue, LOW);
					delay(1500);
			}
			tmp = 0;		
	}
	return 0;
}

void kill_code(){
	const int GPIO_LED_Red = 24;
	const int GPIO_LED_Blue = 3;
		
	//wiringPiSetup();
	//pinMode(0, OUTPUT);
	
	digitalWrite(GPIO_LED_Red, HIGH);
	digitalWrite(GPIO_LED_Blue, HIGH);
}

