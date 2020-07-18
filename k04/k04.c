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

//extern char gender_data(int gender,int i); この行は不要です。

int main(void)
{
    FILE*fp;
    char fname[FILENAME_MAX];
    char buf[256],gender_mf;/* gender_mfは使いません。*/
    int ID,gender,i=1;/* i=0（1番目）から始めます*/
    double height;

    struct student_data detal;/* main外でstudent_dataと定義した構造体をmain内ではdetalとして扱います。
    また、配列として扱うのでdetal[14]として人数分用意してください。*/

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    /* fgets(buf, sizeof(buf),fp);  ←を追加してください。height.csvの１行目は項目名なので空読みします*/

    while(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%d,%lf",&gender,&height);
        //gender_mf = gender_data(gender,i); /*genderは数値のまま扱いprintfする際に文字にします。この行は不要です。*/
        /* genderとheightを構造体に入れていきます。
        detal[i].gender = gender; という風に書きます。
        heightも同様に追加します。
        i++;
        */
    }

    printf("input the filename of sample ID:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    printf("---\n");
    /* このままだとi=14から始まるので0で初期化してください。*/

    while(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%d",&ID);
        /* ここはまだ構造体を創る途中です。以下print文は不要です。
        if(student_data[i].ID==ID){
            printf("ID : %d\n",ID);
            printf("gender : %c\n",gender_mf);
            printf("height : %lf\n",height);
        }
        else{
            printf("No data \n");
        }*/

        /* gender,heightと同様に構造体にIDを追加してください。*/

        i++;
    }

    /* ここから検索パートです*/
    printf("Which ID's data do you want? :");
    /* 手入力した値を探すので以下ファイル読み込みは不要です。
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("No data\n",stderr);
        exit(EXIT_FAILURE);
    }
    else{
        sscanf(buf,"%d",&ID);
    }*/
    /* 手入力したIDをscanfで受け取ってください*/

    /* IDを構造体から探します。
    このままだとi=14から始まるので0で初期化してください。
    while文で　標本の数(14周)する
        if文で　もし構造体のi番目のIDが受け取ったIDなら
            if文で　もし構造体のi番目のgenderが1なら
                print  (ID),'Male',(height)
            else文で　もし構造体のi番目のgenderが2なら
                print  (ID),'Female',(height)
            return 0;
        i++;
    printf('No data');　//14周しても見つからない場合
    return 0;
    */
}


/* 不要です。
char gender_data(gender,i)
{
    if(detal[i].gender==1){
        return "male";
    }
    else if(detal[i].gender==2){
        return "female";
    }
}*/