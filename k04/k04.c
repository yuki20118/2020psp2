#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
    FILE*fp;
    char fname[FILENAME_MAX];
    char buf[256],gender_mf,male,female;
    int ID,gender;
    double height;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';


    fp = fopen(fname,"r");

    if(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%lf",&height);
    }
    
    else{
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    printf("input the filename of sample ID:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    
    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    else{
        sscanf(buf,"%d",&gender);
        if(gender==1){
            gender_mf = male ;
        }
        else{
            gender_mf = female ;
        }
    }

    printf("Which ID's data do you want? :");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';

    printf("---\n");

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("No data\n",stderr);
        exit(EXIT_FAILURE);
    }

    else{
        sscanf(buf,"%d",&ID);
    }
    

    printf("ID : %d\n",ID);

    printf("gender : %c",gender_mf);

    printf("heights : %lf",height);


}