/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 1
   PROGRAMMER: Damler, Lucas
   LOGON ID:   z1761739
   DUE DATE:   2/2/2017
 
   FUNCTION:   This program tests functions for manipulating C 
               strings.
*********************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

// Add your function prototypes here
char* copy(char* destination, const char* source, size_t num);
char* reverseCopy(char* destination, const char* source, size_t num);
char* caseChangeCopy(char* destination, const char* source, size_t num);
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num);
void read(char* destination, int n);

int main()
   {
   const int WORDSIZE = 15;
   char words[][WORDSIZE] = {"cattywampus", "collywobbles", "Lickety Split", "Kerfuffle", "Lollygag", ""};
   char word[WORDSIZE];

   // Test the copy function
   cout << "Copy \"cattywampus\", should see \"cattywampus\".\n";
   copy(word, words[0], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the copy function
   cout << "Copy \"Supercalifragilisticexpialidocious\", should see \"Super\".\n";
   copy(word, "Supercalifragilisticexpialidocious", 5);
   cout << word << endl << endl;

   // Test the replaceCopy function
   cout << "Replace 'l' in \"collywobbles\" with 'b', should see \"cobbywobbbes\".\n";
   replaceCopy(word, words[1], 'l', 'b', sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the replaceCopy function
   cout << "Replace 's' in \"Supercalifragilistic\" with 'd', should see \"duper\".\n";
   replaceCopy(word, "Supercalifragilistic", 'S', 'd', 5);
   cout << word << endl << endl;

   // Test the caseChangeCopy function
   cout << "Case change \"Lickety Split\", should see \"lICKETY sPLIT\".\n";
   caseChangeCopy(word, words[2], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the caseChangeCopy function
   cout << "Case change \"Supercalifragilistic\", should see \"sUPER\".\n";
   caseChangeCopy(word, "Supercalifragilistic", 5);
   cout << word << endl << endl;  
   
   // Test the reverseCopy function
   cout << "Reverse \"Kerfuffle\", should see \"elffufreK\".\n";
   reverseCopy(word, words[3], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the reverseCopy function
   cout << "Reverse \"triskaidekaphobia\", should see \"ohpakediaksirt\".\n";
   reverseCopy(word, "triskaidekaphobia", sizeof(word) - 1);;
   cout << word << endl << endl;

   cout << "Reverse \"Lollygag\", change case, and replace 'G' with 'Z', should see \"ZAZYLLOl\".\n";
   replaceCopy(caseChangeCopy(reverseCopy(word, words[4], sizeof(word) - 1), word, sizeof(word) - 1), word, 'G', 'Z', sizeof(word) - 1);
   cout << word << endl << endl;  

   cout << "Enter your entire name: ";
   read(words[5], sizeof(words[5]));
   cout << words[5] << endl << endl;  
   
   cout << "Reverse your name and change case.\n";
   cout << caseChangeCopy(reverseCopy(word, words[5], sizeof(word) - 1), word, sizeof(word) - 1) << endl;

   return 0;
   }

// Add your function definitions here

char* copy(char* destination, const char* source, size_t num){
	int lastNdx;
	int i;
	if(num <= strlen(source)){					//following if/else statement decides the allowed size of destination based on if num is smaller than source.
        lastNdx = num - 1;						//array length is stored into last index (lastNdx).
        }
        else{
                lastNdx = strlen(source) - 1;
        }

        for(i = 0; i <= lastNdx; i++){					//copies chars from source to destination within limits of last index as defined above.
                destination[i] = source[i];
        }
        destination[i] = '\0';						//includes null termiantor at end of character array
        return destination;						//returns destination string containing chars copied from source string

}

char* reverseCopy(char* destination, const char* source, size_t num){
        int lastNdx;
        int i = 0;
        if(num < strlen(source)){					//does same as char* copy if/else
                lastNdx = num - 1;
        }
        else{
                lastNdx = strlen(source) - 1;
        }
        while(lastNdx >= 0){
        	destination[i] = source[lastNdx];
        	i++; lastNdx--;
	}
	destination[i] = '\0';
        return destination;						//returns destination string containing chars copied from source string
}

char* caseChangeCopy(char* destination, const char* source, size_t num){
		int lastNdx;
		int i;
        if(num < strlen(source)){					//does same as char* copy if/else
                lastNdx = num - 1;
        }
        else{
                lastNdx = strlen(source) - 1;
        }

        for(i = 0; i <= lastNdx; i++){					//loop checks each char case and change lower to upper and upper to lower and is stored in destination array
                if(islower(source[i])){destination[i] = toupper(source[i]);}
                else{destination[i] = tolower(source[i]);}
        }
        destination[i] = '\0';
        return destination;						//returns destination string containing chars copied from source string
}

char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num){
		int lastNdx;
		int i;
        if(num < strlen(source)){					//does same as char* copy if/else
                lastNdx = num - 1;
        }
        else{
                lastNdx = strlen(source) - 1;
        }
        for(i = 0; i <= lastNdx; i++){					//copares target char to char in source
        	if(source[i] == target){				//if chars are equal source char is repalced with replace char
        		destination[i] = replace;			//replace char is stored in destination
		}
		else{
			destination[i] = source[i];			//if char in question does not equal target char it is stored as is in destination array
		}
	}
		destination[i] = '\0';
		return destination;					//returns destination string containing chars copied from source string
}

void read(char* destination, int n){
	cin.getline(destination, 256); 					//takes character input from user and stores into a c string
}

