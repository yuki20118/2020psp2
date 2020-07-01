#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int n);
extern double var_online(double val,double ave,double square_ave,int n);

int main(void)
{
    double val,ave,square_ave,u2,ave_all,var_all,ave_n,var_n;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int n=1;

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
        ave_n=ave_online(val,ave,n);
        var_n=var_online(val,ave,square_ave,n);
        n++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

u2 = n*val/(n-1);
ave_all = ave_n + sqrt(u2/n) ;
var_all = u2 ;

printf("ave = %lf/n ",ave_n);
printf("var = %lf/n",var_n);
printf("ave_all = %lf/n",ave_all);
printf("var_all = %lf/n",var_all);

    return 0;


}



double ave_online(val,ave,n)
{
   ave_n = ((n-1)*ave)/n + (val/n);
   
   return ave_n;
}


double var_online(val,ave,square_ave,n)
{
    var_n = (((n-1)*sqrt(ave))/n + sqrt(val)/n) - (sqrt((n-1)*ave/n + val/n));
    
    return var_n;
}