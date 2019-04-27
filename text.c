#include <stdio.h>
#include <string.h>
#include "text.h"
#include "screen.h"

void displayDataInformation(char data[]){
	int wordCount = 0;
	char *p;
	p = strchr(data, ' ');
	while (p != NULL){
		wordCount++;		// if there is a space then a word is counted
		p = strchr(p + 1, ' ');
	}
	printf("\033[1;1H");
	setColors(BLACK, bg(RED));
	printf("Words: %d\n", wordCount);
	printf("\033[1;21H");
	setColors(BLACK, bg(YELLOW));
	printf("Letters: %d\n", (int)(strlen(data) - wordCount));	// not include spaces
}

void findDuplicates(char data[]){
	printf("\033[2;1H");
	setColors(BLACK, bg(MAGENTA));
	printf("Duplicates: ");

	char str[1500];
	int i, j, k;
	strcat(str, data);

	for (i = 0; i < strlen(str); i++){
		if (str[i] == ' '){
			// extract the specified word
			char word[10] = " ";
			j = i; k = 0;
			do {
				k++; j++;
				word[k] = str[j];
			} while (str[j] != ' ');

			// check if that word is duplicated
			char *pos;
			pos = strstr(str, word);
			if (pos < &str[i]) 
				printf("%s", word);
		}
	}
	printf("\033[43;1H");
}