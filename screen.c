#include <stdio.h>
#include "screen.h"

void startingBarChart(int index[]){
	int i, j;
	setColors(CYAN, bg(BLACK));
	for (i = 0; i < COL; i++){
		for (j = 0; j < index[i]/2; j++){
			printf("\033[%d;%dH", 40 - j, i + 1);
#ifdef UNICODE		// conditional compilation
			printf("%s", BAR);
#else
			printf("%c", '*');
#endif
		}
		printf("\033[%d;%dH", 40 - j, i + 1);	// move to the top of the bar
		if (index[i] != 0) printf("%d", index[i]);	// display index
		printf("\033[%d;%dH", 41, i + 1);		// move to the feet of the bar
		printf("%c", i + 65);				// display letter
	}
}

void appearBarChart(int index[]){
	int i, j;
	setColors(GREEN, bg(BLACK));
	for (i = 0; i < COL; i++){
		for (j = 0; j < index[i]/5; j++){
			printf("\033[%d;%dH", 40 - j, i + 1 + 30);
#ifdef UNICODE		// conditional compilation
			printf("%s", BAR);
#else
			printf("%c", '*');
#endif
		}
		printf("\033[%d;%dH", 40 - j, i + 1 + 30);	// move to the top of the bar
		if (index[i] != 0) printf("%d", index[i]);	// display index
		printf("\033[%d;%dH", 41, i + 1 + 30);		// move to the feet of the bar
		printf("%c", i + 65);			// display letter
	}
	puts("");
}

void displayDataStatistics(char data[]){
	int starting[COL], appear[COL], i;

	for (i = 0; i < COL; i++){
		starting[i] = 0; appear[i] = 0;		// initialize the bar charts
	}

	starting[data[0] - 65]++; appear[data[0] - 65]++;	// mark for the first letter

	for (i = 1; i < strlen(data); i++)
		if (data[i] >= 'A' && data[i] <= 'Z'){
			appear[data[i] - 65]++;
			if (data[i - 1] == ' ') starting[data[i] - 65]++;
		}

	startingBarChart(starting);
	appearBarChart(appear);
}

void clearScreen(void){
	printf("\033[2J");
	fflush(stdout);	// for remote terminal (such as PUTTY)
}

void setColors(short bg, short fg){
	printf("\033[%d;%d;1m", bg, fg);
	fflush(stdout);
}

void resetColors(void){
	printf("\033[0m");
	fflush(stdout);
}
