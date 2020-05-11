#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int n);
extern double var_online(double val,double ave,double square_ave,int n);

int main(void)
{
    double val,ave,square_ave;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int n=0;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        n++;
        ave_online(val,ave,n);
        var_online(val,ave,square_ave,n);
    
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

printf("ave = %lf/n ",ave);
printf("square_ave = %lf/n",square_ave);

    return 0;


}



double ave_online(double val,double ave,int n)
{
    ave=(((n-1)*ave)/n + (val/n));

    return ave;
}


#include <math.h>

double var_online(double val,double ave,double square_ave,int n)
{
    square_ave = (((n-1)*sqrt(ave))/n + sqrt(val)/n) - sqrt((n-1)*ave/n + val/n);

    return square_ave;
}