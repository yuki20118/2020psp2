#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int n);
extern double var_online(double val,double ave,double square_ave,int n);

int main(void)
{
    double val,ave,square_ave,u2,ave_n,var_n,ave_n1,square_ave_n1,gap,st_e;
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

    ave_n1 =0;
    square_ave_n1=0;
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        
        ave_n=ave_online(val,ave_n1,n);
        square_ave=ave_online(pow(val,2),square_ave_n1,n);
        var_n=var_online(val,ave_n1,square_ave_n1,n);
        
        ave_n1 = ave_n;
        square_ave_n1=square_ave;

        u2 = n*var_n/(n-1);
        gap = sqrt(u2/n) ;

        n++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }




printf("ave = %.2lf\n",ave_n);
printf("var = %.2lf\n",var_n);
printf("ave_all = %.2lf+-%.2lf\n",ave_n,gap);
printf("var_all = %.2lf\n",u2);

    return 0;


}



double ave_online(double val,double ave,int n)
{
    double ave_n;
   ave_n = ((n-1)*ave)/n + (val/n);
   
   return ave_n;
}


double var_online(double val,double ave,double square_ave,int n)
{
    double var_n;
    var_n=((n-1)*square_ave/n + pow(val,2)/n) - pow(((n-1)*ave/n)+(val/n),2);

    return var_n;
}