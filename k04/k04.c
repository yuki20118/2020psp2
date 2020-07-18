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


int main(void)
{
    FILE*fp;
    char fname[FILENAME_MAX];
    char buf[256];/* gender_mfは使いません。*/
    int ID,ID_data,gender,i=0;/* i=0（1番目）から始めます*/
    double height;

    struct student_data detail[14];/* main外でstudent_dataと定義した構造体をmain内ではdetailとして扱います。
    また、配列として扱うのでdetail[14]として人数分用意してください。*/

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    
    fname[strlen(fname)-1] = '\0';
    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    /* fgets(buf, sizeof(buf),fp);  ←を追加してください。height.csvの１行目は項目名なので空読みします*/
    fgets(buf, sizeof(buf),fp);

    while(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%d,%lf",&gender,&height);
        
        detail[i].gender = gender;
        detail[i].height = height;

        i++;

        /*genderは数値のまま扱いprintfする際に文字にします。この行は不要です。*/
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
    
    

    /* このままだとi=14から始まるので0で初期化してください。*/
    i=0;

    while(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%d",&ID);
        /* ここはまだ構造体を創る途中です。以下print文は不要です。*/
        /* gender,heightと同様に構造体にIDを追加してください。*/

        detail[i].ID = ID;

        i++;
    }

    /* ここから検索パートです*/
    printf("Which ID's data do you want? : ");
    
    /* 手入力したIDをscanfで受け取ってください*/
    scanf("%d",&ID_data);
    
    printf("---\n");

    i=0;
    while(i<=14){
        if(detail[i].ID == ID_data){
            if(detail[i].gender == 1){
                printf("ID : %d\n",detail[i].ID);
                printf("gender : Male\n");
                printf("height : %lf\n",detail[i].height);
            }
            else if(detail[i].gender == 2){
                printf("ID : %d\n",detail[i].ID);
                printf("gender : Female\n");
                printf("height : %.1lf\n",detail[i].height);
            }
            return 0;
        }
        
        i++;

    }
    
    printf("No data");
    return 0;
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
