#include <stdio.h>
#include <stdlib.h>		// for system() function
#include "text.h"
#include "screen.h"

int main(){
	system(RCMD);	// get data from the server

	FILE *f;
	f = fopen("wlist.txt", "r");
	if (f == NULL){
		printf("Cannot open the file\n");
		return 1;
	}
	clearScreen();

	char data[DATALEN] = "";
	fread(data, sizeof(data), 1, f);
	displayDataInformation(data);
	displayDataStatistics(data);
	findDuplicates(data);
	resetColors();
}
