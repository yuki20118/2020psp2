#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct student_data
{
    int gender;
    double height;
    int ID;
};

extern char gender_data(int gender,int i);

int main(void)
{
    FILE*fp;
    char fname[FILENAME_MAX];
    char buf[256],gender_mf;
    int ID,gender,i=1;
    double height;

    struct student_data detal;


    printf("input the filename of sample:");
    while(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%d,%lf",&gender,&height);
        gender_mf = gender_data(gender,i);
    }

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }


    printf("input the filename of sample ID:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';

    printf("---\n");

    while(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%d",&ID);
        if(student_data[i].ID==ID){
            printf("ID : %d\n",ID);
            printf("gender : %c\n",gender_mf);
            printf("height : %lf\n",height);
        }
        else{
            printf("No data \n");
        }

        i++;
    }
    
    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
   


    printf("Which ID's data do you want? :");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';


    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("No data\n",stderr);
        exit(EXIT_FAILURE);
    }

    else{
        sscanf(buf,"%d",&ID);
    }

}



char gender_data(gender,i)
{
    if(student_data[i].gender==1){
        return "male";
    }
    else if(student_data[i].gender==2){
        return "female";
    }
}