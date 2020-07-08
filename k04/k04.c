#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
    FILE*fp;
    char fname[FILENAME_MAX];
    char buf[256];
    int ID,gender;
    double height;

    printif("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    printf("the filename of sample: %s\n",fname);
    
    printif("input the filename of sample ID:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    printf("the filename of sample ID: %s\n",fname);
    
    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printif("Which ID's data do you want? :");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    printf("Which ID's data do you want? : %s\n",fname);
    
    printf("---");

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("No data\n",stderr);
        exit(EXIT_FAILURE);
    }


    if(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%d",&ID);

        
    }

    






}