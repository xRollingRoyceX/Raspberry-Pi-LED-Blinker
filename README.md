# Raspberry-Pi-LED-Blinker

#Raspberry Pi LED Morse Code Blinker

#written for people who like C++, and for those, like me, learning to Code.

Change the LED pins your using, make sure you are using root, make sure you convert the pins
correctly - and please be safe :)
noticed their was no C++ code for this, it was mostly in Python and Java - 
I thought them both to look a bit sloppy and hard to follow 
(KISS, because just because you can make something complex does not mean you should)
I also tried to keep the the spirit of C++11 as much as possible. 
and... ive come quite a way in coding :)
to make running this code easier - use this as a batch file below:




#/bin/bash

#by: sean

#written july 26t.

cd /home/<Dir_n>/<Dir_n>/   #(basically  place the dir where the file is here instead)

sudo [ProgramName]

#end of Program


# chmod +x [filename]



rewrite this above, fit it with your needs - after save and in the directory that contains the batch file,
use the terminal and use command chmod +x <filename>
press ls and it will turn green.
filename references the name of the batch file, not the C++ files
run this with sudo

----------------------------------------
#if i can help let me know :) 
-----------------------------------------

To Compile (using your favorite compiler:

clang++ -std=c++11 -02 -lwiringPi <Input_Filename>.cpp -o <Output_File_Name>  #clang is the best hands down (because the way it sounds)
---------------------
g++     -std=c++11 -02 -lwiringPi <Input_Filename>.cpp -o <Output_File_Name>
---------------------
gcc     -std=c++11 -02 -lwiringPi <Input_Filename>.cpp -o <Output_File_Name>
---------------------



To make into Smaller .out file 
--------------------
strip -s <filename> 
  12/14kb ~> 9.6kb after the strip
(its not nessassary but I like doing it to random code to look more "cool" in the folder)

this code should use < 0% of the CPU
