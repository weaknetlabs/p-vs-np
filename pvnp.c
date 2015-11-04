/*
	Copyright (C) Douglas Berdeaux - 07.06.2015    	

	This program is free software: you can redistribute it and/or modify
    	it under the terms of the GNU General Public License as published by
    	the Free Software Foundation, either version 3 of the License, or
    	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

    	You should have received a copy of the GNU General Public License
	    along with this program.  If not, see <http://www.gnu.org/licenses/>

        Finding two simple factors to prove the section
        about factors in this article:
         "(p vs. np) - http://carlcheo.com/compsci"
        can be done.

        I accidentally found a prime that Euler found: 2,147,483,647
        while using this program. // lel
        
        Compile with "gcc -lm -o pvnp pvnp.c"
        
*/
#include<stdio.h> // printf()
#include<stdlib.h> // for exit()
#include<string.h> // for strlen()
#include<math.h> // for floor()
void checkType(char *ct); // check the type of number
void processEasy(int ict,int even); // for handling even numbers
void processHard(int ict); // for odd numbers
void processInsane(int ict); // for the odds that aren't below 10
int main(int argc,char * argv[]){ // entry point of execution
        if(argc<2){ // didn't pass an argument
                printf("please pass an number argument.\n");
                return 1; // mov EBX, 1
        }else{ // check what type of number we are dealing with
                checkType(argv[1]);
        }
        return 0; // done
}
void checkType(char *ct){ // least significant place gives the most clues!
        int ict = atoi(ct); // get last digit
        int ictm = ict%10; // modulo to get least significant value, e.g. 133_7_
        if(ictm == 5 || ictm == 0){ // special case
                processEasy(ict,0); // pass entire integer to this
                return;
        }else if(ictm==2||ictm==4||ictm==6||ictm==8){
                processEasy(ict,1);
        }else{ // flow through, we have an odd
                processHard(ict);
        }
        return; // done
}
void processEasy(int ict,int even){ // for even numbers
        printf("That's easy, you have ");
        even ? printf("2 and %d\n",(ict/2)) : printf("5 and %d\n",(ict/5));
        return; // done
}
void processHard(int ict){ // for odd numbers
        printf("that one was tricky, ");
        if(ict%3==0){
                printf("3 and %d\n",(ict/3));
        }else if(ict%7==0){
                printf("7 and %d\n",(ict/7));
        }else if(ict%9==0){
                printf("9 and %d\n",(ict/9));
        }else{
                processInsane(ict); // GoW throwback, yo
        }
        return;
}
void processInsane(int ict){ // it wasn't divisible by < 9
        // we will loop and increment by 10 for these
        int i=9; // mov ECX, 0x9 ; lel
        double flr = ict/2;
        while(i<floor(flr)){ // floor() used to reduce redundancy
                if(ict%(i+=4)==0){ // PEMDAS?
                        printf("%d and %d\n",i,(ict/i));
                        return;
                }else if(ict%(i+=4)==0){
                        printf("%d and %d\n",i,(ict/i));
                        return;
                }else if(ict%(i+=2)==0){
                        printf("%d and %d\n",i,(ict/i));
                        return;
                }
        }
        printf("I actually couldn't caculate it. %d may be a prime number.\n",ict);
        return;
}
