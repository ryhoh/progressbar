/*
 *		sample.c
 *		
 *		progressbar.cの呼び出し方
 *
 */
 
#include <stdio.h>
#include "progressbar.h"
 
int main(void){
	int pos, full;
	
	printf("pos:");
	scanf("%d", &pos);
	printf("full:");
	scanf("%d", &full);
	
	printProgress(pos, full);
	
	return 0;
}