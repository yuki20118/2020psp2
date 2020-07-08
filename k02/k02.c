#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define USE_MATH_DEFINDS

extern double p_stdnorm(double z);

int main(void)
{
    double val,n=1,muA=170.8,sigmaA=5.43,zA,L_A,La_n,La_n1=1;
    double muB=169.7,sigmaB=5.5,zB,L_B,Lb_n,Lb_n1=1;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;

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

        zA=(val - muA)/sigmaA;
        zB=(val - muB)/sigmaB;
        
        La_n = p_stdnorm(zA);
        Lb_n = p_stdnorm(zB);
        
        L_A = La_n * La_n1;
        L_B = Lb_n * Lb_n1;
        
        La_n1 = L_A;
        Lb_n1 = L_B;

        n++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("Likelihood for A: %f\n",L_A);
    printf("Likelihood for B: %f\n",L_B);

    return 0;
}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}
    
