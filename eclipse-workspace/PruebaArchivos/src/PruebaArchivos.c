/*
 ============================================================================
 Name        : PruebaArchivos.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



	/******************************************************************************

	Welcome to GDB Online.
	GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
	C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
	Code, Compile, Run and Debug online from anywhere in world.

	*******************************************************************************/
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	#define size 1

	int autoload();

	int autosave();

	int dataInt();

	typedef struct{
	    int a;
	    int b;
	    int c;
	}sTest;

	int main()
	{
		setbuf(stdout, NULL);
	    sTest test[1];
	    int i = 0, j=0;

	    if(autoload(test)==-1){
	        printf("\nCreating save file...\n");
	        autosave(test);
	        printf("\n\n~ Restarting ~\n");
	        printf("\n-------------------------------\n\n");
	    }
	    else{
	        printf("\nThe numbers are:\n\n");
	        printf("\n%d",test[0].a);
	        printf("\n%d",test[0].b);
	        printf("\n%d",test[0].c);
	    }

	    printf("\n\nTest ran successfully. Thanks for participating <3");

	    return 0;
	}

	////////////////////////////////////////////////////// FUNCTIONS.

	/////////// AUTOLOAD

	int autoload(sTest *test){

	    FILE *fp;

	    fp=fopen("test.txt","r"); //Opens a file, name 'text.txt', more R for read only.
	                            //If cannot find such a file, it will return NULL.

	    if(fp==NULL){// If it returns NULL...
	        printf("\nERROR. No previous file.");
	        return -1;//Exits the function.
	    }

	    printf("\nFile loaded."); //... Else, it loads the file data into the given array.
	    fread(test,sizeof(sTest),size,fp);

	    fclose(fp);//We close the file.
	    return 0;
	}

	/////////// AUTOSAVE

	int autosave(sTest *test){

	    FILE *fp;
	    int i;

	    fp=fopen("test.txt","w"); //Opens 'test.txt' in W mode. W opens the file for writing, and
	                            // if such file doesn't exist, it creates it. Otherwise WIPES the file.
	                            //If the file cannot be created, returns NULL.

	    if(fp==NULL){//If NULL...
	        printf("\nERROR. Cannot create file.");
	        return -1;//Exits the function.
	    }

	    printf("\nEnter a: ");
	    test[0].a=dataInt(1,5,"");
	    printf("\nEnter b: ");
	    test[0].b=dataInt(1,5,"");
	    printf("\nEnter c: ");
	    test[0].c=dataInt(1,5,"");

	    fwrite(test,sizeof(sTest),size,fp);// This stores the data for the numbers in 'test.txt'.
	    printf("\nData saved successfully.");

	    fclose(fp);//We close the file.
	    return 0;
	}

	////////////////////////////////////////////////////////////////////////// DATA Int.

	int dataInt(int base, int top,char msg[]){

		int i;
		int j=0;
	    int errorFlag=0;
	    char numS[1022];
	    char numS2[1022];
	    int num;
	    char digit[] = "-0123456789";

	    do{

	        for(i=0;i<1022;i++){
	            numS[i]=0;
	            numS2[i]=0;
	        }

	    	if(errorFlag==1){
	    		printf("\n[ Error. \nOnly numbers within the range ]\n");
	            	errorFlag=0;
	                num=0;
	                j=0;
	    	}
	    	printf("\n%s\n",msg);
	    	printf("Value between: [ %d ] to [ %d ] :\n\n ", base, top);

	    	///////

	    	fgets(numS,1022,stdin);
	    	numS[strlen(numS)-1]='\0';

	    	//////

	    	if (strlen(numS) != strspn(numS, digit)){
	    		errorFlag=1;
	    	}

	    	//////

	    	for(i=0;i<strlen(numS);i++){
	    		if(i==0 && numS[0]=='-'){
	    			numS2[j]=numS[i];
	    			j++;
	    		}
	    		else if(numS[i]<='9' && numS[i]>='0'){
	    			numS2[j]=numS[i];
	    			j++;
	    		}
	    	}

	    	//////

	    	num=atoi(numS2);
	    	if(num>top || num<base){
	    		errorFlag=1;
	    	}

	    }while(errorFlag==1);

	   	return num;
	}




	return EXIT_SUCCESS;
}
