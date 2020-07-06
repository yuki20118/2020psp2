#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

int main(void)
{
    double val,muA=170.8,muB=169.7,sigmaA=5.43,sigmaB=5.5,n=1,zA,zB,L_A,L_a_n,L_a_n1,L_B,L_b_n,L_b_n1;
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
        
        L_a_n = p_stdnorm(zA);
        L_b_n = p_stdnorm(zB);
        
        L_A = L_a_n * L_a_n1;
        L_B = L_b_n * L_b_n1;
        
        L_a_n1 = L_A;
        L_b_n1 = L_B;

        n++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",L_A);
    printf("L_B: %f\n",L_B);

    return 0;
}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}
    
