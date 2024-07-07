#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct university {
    int code;
    char name[100];
    int seats;
} univ[100],univ_dup[100];

struct preference {
    char username[100];
    int pref1;
    int pref2;
    int pref3;
    int pref4;
    int pref5;
    int changed;
} pref[1000];

struct ranks {
    int rank;
    char username[100];
    int mark;
} ranks1[1000], ranks2[1000];

struct verify2 {
    char username[100];
    char name[100];
    int age;
    int jee_main;
    int jee_advanced, rank_main, rank_adv;
    char pref_options[100];
    char pref_list[100];
    char allotted_seat[100];
    char choose_wait_skip[100];
} ver2[1000];

void allot_main(int univ_count,int pref_count,int student_count) {
    FILE *fp1 = fopen("Jee_main.txt", "r");
    FILE *fp2 = fopen("preferences.txt", "r");
    FILE *fp3 = fopen("Student.txt", "r+");
    FILE *fp5 = fopen("allot_nit.txt","r+");
    
    for (int i = 0; i < student_count; i++) {
        fscanf(fp1, "[%d,%[^,],%d]\n", &ranks1[i].rank, ranks1[i].username, &ranks1[i].mark);
        //printf("rank %d username %s\n", ranks1[i].rank, ranks1[i].username);
    }

    for (int j = 0; j < pref_count; j++) {
        fscanf(fp2, "%s %d %d %d %d %d %d\n", pref[j].username, &pref[j].pref1, &pref[j].pref2, &pref[j].pref3,&pref[j].pref4,&pref[j].pref5,&pref[j].changed);
        //printf("username %s pref1 %d pref2 %d pref3 %d pref4 %d pref5 %d\n", pref[j].username, pref[j].pref1, pref[j].pref2, pref[j].pref3,pref[j].pref4,pref[j].pref5);
        pref[j].changed=0;
    }
    for (int z = 0; z < student_count; z++) {
                            fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);
    }

    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < pref_count; j++) {
            if (strcmp(ranks1[i].username, pref[j].username) == 0) {
                if(ranks1[i].rank!=0){
                //printf("Username: %s\n", ranks1[i].username);
                for (int k = 0; k < univ_count; k++) {
                    //printf("k is %d code is %d pref1 is %d\n", k, univ[k].code, pref[j].pref1);
                    
                    if ((univ[k].code == pref[j].pref1) && (univ[k].seats > 0)&&(pref[j].pref1<200)&&(pref[j].changed==0)) {
                        //printf("k is %d code: %d seats: %d pref1 is %d\n", k, univ[k].code, univ[k].seats, pref[j].pref1);
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                //printf("%s\n",ver2[z].username);
                                if((strcmp(ver2[z].allotted_seat,"no_seat")==0)||(strcmp(ver2[z].allotted_seat,"NITT")==0)||(strcmp(ver2[z].allotted_seat,"NITC")==0)||(strcmp(ver2[z].allotted_seat,"NITS")==0)||(strcmp(ver2[z].allotted_seat,"[]")==0)||(strcmp(ver2[z].allotted_seat,"IITM")==0)||(strcmp(ver2[z].allotted_seat,"IITB")==0)||(strcmp(ver2[z].allotted_seat,"IITK")==0)){
                                for(int x=0;x<univ_count;x++){
                                    if(strcmp(univ[x].name,ver2[z].allotted_seat)==0){
                                        univ[x].seats+=1;
                                    }
                                }
                                strcpy(ver2[z].allotted_seat, univ[k].name);
                                fprintf(fp5,"%s %d\n",ver2[z].username,pref[j].pref1);
                                //printf("%s %s\n",ver2[z].username,ver2[z].allotted_seat);///////////////////
                                 univ[k].seats -= 1;
                                 //printf("%s %d\n",univ[k].name,univ[k].seats);
                                 pref[j].changed=1;
                                 
                        //printf("%d\n",univ[k].seats);
                        }
                            }
                        }
                       
                    }}
                    for (int k = 0; k < univ_count; k++) {
                    //printf("k is %d code is %d pref2 is %d\n", k, univ[k].code, pref[j].pref2);
                    if ((univ[k].code == pref[j].pref2) && (univ[k].seats > 0)&&(pref[j].pref2<200)&&(pref[j].changed==0)) {
                        //printf("k is %d code: %d seats: %d pref2 is %d\n", k, univ[k].code, univ[k].seats, pref[j].pref2);
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                if((strcmp(ver2[z].allotted_seat,"no_seat")==0)||(strcmp(ver2[z].allotted_seat,"NITT")==0)||(strcmp(ver2[z].allotted_seat,"NITC")==0)||(strcmp(ver2[z].allotted_seat,"NITS")==0)||(strcmp(ver2[z].allotted_seat,"[]")==0)||(strcmp(ver2[z].allotted_seat,"IITM")==0)||(strcmp(ver2[z].allotted_seat,"IITB")==0)||(strcmp(ver2[z].allotted_seat,"IITK")==0)){
                                for(int x=0;x<univ_count;x++){
                                    if(strcmp(univ[x].name,ver2[z].allotted_seat)==0){
                                        univ[x].seats+=1;
                                    }
                                }
                                strcpy(ver2[z].allotted_seat, univ[k].name);
                                fprintf(fp5,"%s %d\n",ver2[z].username,pref[j].pref2);
                                //printf("%s %s\n",ver2[z].username,ver2[z].allotted_seat);/////////////
                                 univ[k].seats -= 1;
                                 //printf("%s %d\n",univ[k].name,univ[k].seats);
                                 pref[j].changed=1;
                                 
                        //printf("%d\n",univ[k].seats);
                        }
                            }
                        }
                       
                    }}
                    for (int k = 0; k < univ_count; k++) {
                    //printf("k is %d code is %d pref3 is %d\n", k, univ[k].code, pref[j].pref3);
                    if ((univ[k].code == pref[j].pref3) && (univ[k].seats > 0)&&(pref[j].pref3<200)&&(pref[j].changed==0)) {
                        //printf("k is %d code: %d seats: %d pref3 is %d\n", k, univ[k].code, univ[k].seats, pref[j].pref3);
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                if((strcmp(ver2[z].allotted_seat,"no_seat")==0)||(strcmp(ver2[z].allotted_seat,"NITT")==0)||(strcmp(ver2[z].allotted_seat,"NITC")==0)||(strcmp(ver2[z].allotted_seat,"NITS")==0)||(strcmp(ver2[z].allotted_seat,"[]")==0)||(strcmp(ver2[z].allotted_seat,"IITM")==0)||(strcmp(ver2[z].allotted_seat,"IITB")==0)||(strcmp(ver2[z].allotted_seat,"IITK")==0)){
                                for(int x=0;x<univ_count;x++){
                                    if(strcmp(univ[x].name,ver2[z].allotted_seat)==0){
                                        univ[x].seats+=1;
                                    }
                                }
                                strcpy(ver2[z].allotted_seat, univ[k].name);
                                fprintf(fp5,"%s %d\n",ver2[z].username,pref[j].pref3);
                                //printf("%s %s\n",ver2[z].username,ver2[z].allotted_seat);///////////
                                univ[k].seats -= 1;
                                //printf("%s %d\n",univ[k].name,univ[k].seats);
                                pref[j].changed=1;
                                
                        //printf("%d\n",univ[k].seats);
                        }
                            }
                        }
                        
                    }} for (int k = 0; k < univ_count; k++) {
                    //printf("k is %d code is %d pref1 is %d\n", k, univ[k].code, pref[j].pref1);
                    
                    if ((univ[k].code == pref[j].pref4) && (univ[k].seats > 0)&&(pref[j].pref4<200)&&(pref[j].changed==0)) {
                        //printf("k is %d code: %d seats: %d pref4 is %d\n", k, univ[k].code, univ[k].seats, pref[j].pref4);
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                if((strcmp(ver2[z].allotted_seat,"no_seat")==0)||(strcmp(ver2[z].allotted_seat,"NITT")==0)||(strcmp(ver2[z].allotted_seat,"NITC")==0)||(strcmp(ver2[z].allotted_seat,"NITS")==0)||(strcmp(ver2[z].allotted_seat,"[]")==0)||(strcmp(ver2[z].allotted_seat,"IITM")==0)||(strcmp(ver2[z].allotted_seat,"IITB")==0)||(strcmp(ver2[z].allotted_seat,"IITK")==0)){
                                for(int x=0;x<univ_count;x++){
                                    if(strcmp(univ[x].name,ver2[z].allotted_seat)==0){
                                        univ[x].seats+=1;
                                    }
                                }
                                strcpy(ver2[z].allotted_seat, univ[k].name);
                                fprintf(fp5,"%s %d\n",ver2[z].username,pref[j].pref4);
                                //printf("%s %s\n",ver2[z].username,ver2[z].allotted_seat);///////////////////
                                 univ[k].seats -= 1;
                                 //printf("%s %d\n",univ[k].name,univ[k].seats);
                                 pref[j].changed=1;
                                 
                        //printf("%d\n",univ[k].seats);
                        }
                            }
                        }
                       
                    }}for (int k = 0; k < univ_count; k++) {
                    //printf("k is %d code is %d pref1 is %d\n", k, univ[k].code, pref[j].pref1);
                    
                    if ((univ[k].code == pref[j].pref5) && (univ[k].seats > 0)&&(pref[j].pref5<200)&&(pref[j].changed==0)) {
                        //printf("k is %d code: %d seats: %d pref5 is %d\n", k, univ[k].code, univ[k].seats, pref[j].pref5);
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                if((strcmp(ver2[z].allotted_seat,"no_seat")==0)||(strcmp(ver2[z].allotted_seat,"NITT")==0)||(strcmp(ver2[z].allotted_seat,"NITC")==0)||(strcmp(ver2[z].allotted_seat,"NITS")==0)||(strcmp(ver2[z].allotted_seat,"[]")==0)||(strcmp(ver2[z].allotted_seat,"IITM")==0)||(strcmp(ver2[z].allotted_seat,"IITB")==0)||(strcmp(ver2[z].allotted_seat,"IITK")==0)){
                                for(int x=0;x<univ_count;x++){
                                    if(strcmp(univ[x].name,ver2[z].allotted_seat)==0){
                                        univ[x].seats+=1;
                                    }
                                }
                                strcpy(ver2[z].allotted_seat, univ[k].name);
                                fprintf(fp5,"%s %d\n",ver2[z].username,pref[j].pref5);
                                //printf("%s %s\n",ver2[z].username,ver2[z].allotted_seat);///////////////////
                                 univ[k].seats -= 1;
                                 //printf("%s %d\n",univ[k].name,univ[k].seats);
                                 pref[j].changed=1;
                                 
                        //printf("%d\n",univ[k].seats);
                        }
                            }}
                       
                    }}
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                if(strcmp(ver2[z].allotted_seat,"[]")==0){
                                strcpy(ver2[z].allotted_seat, "no_seat");
                                
                            }
                        }
                        
                        }
                        
                    
                
            }}
        }
    }
    fclose(fp5);
    fclose(fp3);
    FILE *fp4 = fopen("Student.txt", "w+");
    
        for (int i = 0; i < student_count; i++) {
            fprintf(fp4, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[i].name, ver2[i].username, ver2[i].age, ver2[i].jee_main, ver2[i].jee_advanced, ver2[i].rank_main, ver2[i].rank_adv, ver2[i].pref_options, ver2[i].pref_list, ver2[i].allotted_seat,ver2[i].choose_wait_skip);
        }
        fclose(fp4);
    

    fclose(fp2);
    fclose(fp1);
}

void filter_adv(int univ_count,int pref_count,int student_count){
    //FILE *fp1=fopen("Jee_main.txt","r+");
    FILE *fp2=fopen("Jee_adv.txt","r+");
    FILE *fp3=fopen("allot_nit.txt","r+");
    FILE *fp4=fopen("preferences.txt","r+");
    FILE *fp5=fopen("Student.txt","r+");
    for (int z = 0; z < student_count; z++) {
    fscanf(fp5, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);
}
for (int i = 0; i < student_count; i++) {
        fscanf(fp2, "[%d,%[^,],%d]\n", &ranks1[i].rank, ranks1[i].username, &ranks1[i].mark);
       //printf("rank %d username %s\n", ranks1[i].rank, ranks1[i].username);
    }

    for (int j = 0; j < pref_count; j++) {
        fscanf(fp4, "%s %d %d %d %d\n", pref[j].username, &pref[j].pref1, &pref[j].pref2, &pref[j].pref3,&pref[j].changed);
        //printf("username %s pref1 %d pref2 %d pref3 %d\n", pref[j].username, pref[j].pref1, pref[j].pref2, pref[j].pref3);
    }
    for(int i=0;i<100;i++){
        char username[100];
        int alloted_nit_seat;
        fscanf(fp3,"%s %d\n",username,&alloted_nit_seat);
        //printf("%s %d\n",username,alloted_iit_seat);
        for(int j=0;j<student_count;j++){
            if(strcmp(ranks1[j].username,username)==0){
                    //printf("found %s\n",ranks1[j].username);
                    for(int k=0;k<pref_count;k++){
                        //printf("%s\n",pref[k].username);
                            if(strcmp(pref[k].username,username)==0){
                                if(alloted_nit_seat==pref[k].pref1){
                                    //printf("found at 1 %d\n",pref[k].pref1);
                                    ranks1[j].rank=0;
                                }
                                else if(alloted_nit_seat==pref[k].pref3){
                                    //printf("found at 3, prev pref are %d %d\n",pref[k].pref1,pref[k].pref2);
                                    if((pref[k].pref1<200)&&(pref[k].pref2<200)){
                                        ranks1[j].rank=0;
                                    }
                                }else if(alloted_nit_seat==pref[k].pref2){
                                    //printf("found at 2, prev pref is %d\n",pref[k].pref1);
                                    if(pref[k].pref1<200){
                                        ranks1[j].rank=0;
                                    }
                                }else if(alloted_nit_seat==pref[k].pref4){
                                    //printf("found at 3, prev pref are %d %d\n",pref[k].pref1,pref[k].pref2);
                                    if((pref[k].pref1<200)&&(pref[k].pref2<200)&&(pref[k].pref3<200)){
                                        ranks1[j].rank=0;
                                    }
                                }else if(alloted_nit_seat==pref[k].pref5){
                                    //printf("found at 3, prev pref are %d %d\n",pref[k].pref1,pref[k].pref2);
                                    if((pref[k].pref1<200)&&(pref[k].pref2<200)&&(pref[k].pref3<200)&&(pref[k].pref4<200)){
                                        ranks1[j].rank=0;
                                    }
                                }
                            }
                    }
            }
        }
    }
    fclose(fp2);
    fp2=fopen("Jee_adv.txt","w");
    for(int i=0;i<student_count;i++){
        fprintf(fp2,"[%d,%s,%d]\n",ranks1[i].rank,ranks1[i].username,ranks1[i].mark);
    }
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);

}

void allot_adv(int univ_count,int pref_count,int student_count) {
    FILE *fp1 = fopen("Jee_adv.txt", "r");
    FILE *fp2 = fopen("preferences.txt", "r");
    FILE *fp3 = fopen("Student.txt", "r+");
    FILE *fp5 = fopen("allot_iit.txt","r+");
    
    for (int i = 0; i < student_count; i++) {
        fscanf(fp1, "[%d,%[^,],%d]\n", &ranks1[i].rank, ranks1[i].username, &ranks1[i].mark);
        //printf("rank %d username %s\n", ranks1[i].rank, ranks1[i].username);
    }

    for (int j = 0; j < pref_count; j++) {
        fscanf(fp2, "%s %d %d %d %d %d %d\n", pref[j].username, &pref[j].pref1, &pref[j].pref2, &pref[j].pref3,&pref[j].pref4,&pref[j].pref5,&pref[j].changed);
        //printf("username %s pref1 %d pref2 %d pref3 %d pref4 %d pref5 %d\n", pref[j].username, pref[j].pref1, pref[j].pref2, pref[j].pref3,pref[j].pref4,pref[j].pref5);
        pref[j].changed=0;
    }
    for (int z = 0; z < student_count; z++) {
                            fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);
    }

    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < pref_count; j++) {
            if (strcmp(ranks1[i].username, pref[j].username) == 0) {
                if(ranks1[i].rank!=0){
                //printf("Username: %s\n", ranks1[i].username);
                for (int k = 0; k < univ_count; k++) {
                    //printf("k is %d code is %d pref1 is %d\n", k, univ[k].code, pref[j].pref1);
                    
                    if ((univ[k].code == pref[j].pref1) && (univ[k].seats > 0)&&(pref[j].pref1>200)&&(pref[j].changed==0)) {
                        //printf("k is %d code: %d seats: %d pref1 is %d\n", k, univ[k].code, univ[k].seats, pref[j].pref1);
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                //printf("%s\n",ver2[z].username);
                                if((strcmp(ver2[z].allotted_seat,"no_seat")==0)||(strcmp(ver2[z].allotted_seat,"NITT")==0)||(strcmp(ver2[z].allotted_seat,"NITC")==0)||(strcmp(ver2[z].allotted_seat,"NITS")==0)||(strcmp(ver2[z].allotted_seat,"[]")==0)||(strcmp(ver2[z].allotted_seat,"IITM")==0)||(strcmp(ver2[z].allotted_seat,"IITB")==0)||(strcmp(ver2[z].allotted_seat,"IITK")==0)){
                                for(int x=0;x<univ_count;x++){
                                    if(strcmp(univ[x].name,ver2[z].allotted_seat)==0){
                                        univ[x].seats+=1;
                                    }
                                }
                                strcpy(ver2[z].allotted_seat, univ[k].name);
                                fprintf(fp5,"%s %d\n",ver2[z].username,pref[j].pref1);
                                //printf("%s %s\n",ver2[z].username,ver2[z].allotted_seat);///////////////////
                                 univ[k].seats -= 1;
                                 //printf("%s %d\n",univ[k].name,univ[k].seats);
                                 pref[j].changed=1;
                                 
                        //printf("%d\n",univ[k].seats);
                        }
                            }
                        }
                       
                    }}
                    for (int k = 0; k < univ_count; k++) {
                    //printf("k is %d code is %d pref2 is %d\n", k, univ[k].code, pref[j].pref2);
                    if ((univ[k].code == pref[j].pref2) && (univ[k].seats > 0)&&(pref[j].pref2>200)&&(pref[j].changed==0)) {
                        //printf("k is %d code: %d seats: %d pref2 is %d\n", k, univ[k].code, univ[k].seats, pref[j].pref2);
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                if((strcmp(ver2[z].allotted_seat,"no_seat")==0)||(strcmp(ver2[z].allotted_seat,"NITT")==0)||(strcmp(ver2[z].allotted_seat,"NITC")==0)||(strcmp(ver2[z].allotted_seat,"NITS")==0)||(strcmp(ver2[z].allotted_seat,"[]")==0)||(strcmp(ver2[z].allotted_seat,"IITM")==0)||(strcmp(ver2[z].allotted_seat,"IITB")==0)||(strcmp(ver2[z].allotted_seat,"IITK")==0)){
                                for(int x=0;x<univ_count;x++){
                                    if(strcmp(univ[x].name,ver2[z].allotted_seat)==0){
                                        univ[x].seats+=1;
                                    }
                                }
                                strcpy(ver2[z].allotted_seat, univ[k].name);
                                fprintf(fp5,"%s %d\n",ver2[z].username,pref[j].pref2);
                                //printf("%s %s\n",ver2[z].username,ver2[z].allotted_seat);/////////////
                                 univ[k].seats -= 1;
                                 //printf("%s %d\n",univ[k].name,univ[k].seats);
                                 pref[j].changed=1;
                                 
                        //printf("%d\n",univ[k].seats);
                        }
                            }
                        }
                       
                    }}
                    for (int k = 0; k < univ_count; k++) {
                    //printf("k is %d code is %d pref3 is %d\n", k, univ[k].code, pref[j].pref3);
                    if ((univ[k].code == pref[j].pref3) && (univ[k].seats > 0)&&(pref[j].pref3>200)&&(pref[j].changed==0)) {
                        //printf("k is %d code: %d seats: %d pref3 is %d\n", k, univ[k].code, univ[k].seats, pref[j].pref3);
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                if((strcmp(ver2[z].allotted_seat,"no_seat")==0)||(strcmp(ver2[z].allotted_seat,"NITT")==0)||(strcmp(ver2[z].allotted_seat,"NITC")==0)||(strcmp(ver2[z].allotted_seat,"NITS")==0)||(strcmp(ver2[z].allotted_seat,"[]")==0)||(strcmp(ver2[z].allotted_seat,"IITM")==0)||(strcmp(ver2[z].allotted_seat,"IITB")==0)||(strcmp(ver2[z].allotted_seat,"IITK")==0)){
                                for(int x=0;x<univ_count;x++){
                                    if(strcmp(univ[x].name,ver2[z].allotted_seat)==0){
                                        univ[x].seats+=1;
                                    }
                                }
                                strcpy(ver2[z].allotted_seat, univ[k].name);
                                fprintf(fp5,"%s %d\n",ver2[z].username,pref[j].pref3);
                                //printf("%s %s\n",ver2[z].username,ver2[z].allotted_seat);///////////
                                univ[k].seats -= 1;
                                //printf("%s %d\n",univ[k].name,univ[k].seats);
                                pref[j].changed=1;
                                
                        //printf("%d\n",univ[k].seats);
                        }
                            }
                        }
                        
                    }} for (int k = 0; k < univ_count; k++) {
                    //printf("k is %d code is %d pref1 is %d\n", k, univ[k].code, pref[j].pref1);
                    
                    if ((univ[k].code == pref[j].pref4) && (univ[k].seats > 0)&&(pref[j].pref4<200)&&(pref[j].changed==0)) {
                        //printf("k is %d code: %d seats: %d pref4 is %d\n", k, univ[k].code, univ[k].seats, pref[j].pref4);
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                if((strcmp(ver2[z].allotted_seat,"no_seat")==0)||(strcmp(ver2[z].allotted_seat,"NITT")==0)||(strcmp(ver2[z].allotted_seat,"NITC")==0)||(strcmp(ver2[z].allotted_seat,"NITS")==0)||(strcmp(ver2[z].allotted_seat,"[]")==0)||(strcmp(ver2[z].allotted_seat,"IITM")==0)||(strcmp(ver2[z].allotted_seat,"IITB")==0)||(strcmp(ver2[z].allotted_seat,"IITK")==0)){
                                for(int x=0;x<univ_count;x++){
                                    if(strcmp(univ[x].name,ver2[z].allotted_seat)==0){
                                        univ[x].seats+=1;
                                    }
                                }
                                strcpy(ver2[z].allotted_seat, univ[k].name);
                                fprintf(fp5,"%s %d\n",ver2[z].username,pref[j].pref4);
                                //printf("%s %s\n",ver2[z].username,ver2[z].allotted_seat);///////////////////
                                 univ[k].seats -= 1;
                                 //printf("%s %d\n",univ[k].name,univ[k].seats);
                                 pref[j].changed=1;
                                 
                        //printf("%d\n",univ[k].seats);
                        }
                            }
                        }
                       
                    }}for (int k = 0; k < univ_count; k++) {
                    //printf("k is %d code is %d pref1 is %d\n", k, univ[k].code, pref[j].pref1);
                    
                    if ((univ[k].code == pref[j].pref5) && (univ[k].seats > 0)&&(pref[j].pref5>200)&&(pref[j].changed==0)) {
                        //printf("k is %d code: %d seats: %d pref5 is %d\n", k, univ[k].code, univ[k].seats, pref[j].pref5);
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                if((strcmp(ver2[z].allotted_seat,"no_seat")==0)||(strcmp(ver2[z].allotted_seat,"NITT")==0)||(strcmp(ver2[z].allotted_seat,"NITC")==0)||(strcmp(ver2[z].allotted_seat,"NITS")==0)||(strcmp(ver2[z].allotted_seat,"[]")==0)||(strcmp(ver2[z].allotted_seat,"IITM")==0)||(strcmp(ver2[z].allotted_seat,"IITB")==0)||(strcmp(ver2[z].allotted_seat,"IITK")==0)){
                                for(int x=0;x<univ_count;x++){
                                    if(strcmp(univ[x].name,ver2[z].allotted_seat)==0){
                                        univ[x].seats+=1;
                                    }
                                }
                                strcpy(ver2[z].allotted_seat, univ[k].name);
                                fprintf(fp5,"%s %d\n",ver2[z].username,pref[j].pref5);
                                //printf("%s %s\n",ver2[z].username,ver2[z].allotted_seat);///////////////////
                                 univ[k].seats -= 1;
                                 //printf("%s %d\n",univ[k].name,univ[k].seats);
                                 pref[j].changed=1;
                                 
                        //printf("%d\n",univ[k].seats);
                        }
                            }}}}
                        for (int z = 0; z < student_count; z++) {
                            //fscanf(fp3, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);

                            if (strcmp(ver2[z].username, ranks1[i].username) == 0) {
                                if(strcmp(ver2[z].allotted_seat,"[]")==0){
                                strcpy(ver2[z].allotted_seat, "no_seat");
                                
                            }
                        }
                        
                        }
                        
                       
                    
                    
                
            }}
        }
    }
    fclose(fp5);
    fclose(fp3);
    FILE *fp4 = fopen("Student.txt", "w+");
    
        for (int i = 0; i < student_count; i++) {
            fprintf(fp4, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[i].name, ver2[i].username, ver2[i].age, ver2[i].jee_main, ver2[i].jee_advanced, ver2[i].rank_main, ver2[i].rank_adv, ver2[i].pref_options, ver2[i].pref_list, ver2[i].allotted_seat,ver2[i].choose_wait_skip);
        }
        fclose(fp4);
    

    fclose(fp2);
    fclose(fp1);
}

void filter_main(int univ_count,int pref_count,int student_count){
    //FILE *fp1=fopen("Jee_main.txt","r+");
    FILE *fp2=fopen("Jee_main.txt","r+");
    FILE *fp3=fopen("allot_iit.txt","r+");
    FILE *fp4=fopen("preferences.txt","r+");
    FILE *fp5=fopen("Student.txt","r+");
    for (int z = 0; z < student_count; z++) {
    fscanf(fp5, "%s %s %d %d %d %d %d %s %s %s %s\n", ver2[z].name, ver2[z].username, &ver2[z].age, &ver2[z].jee_main, &ver2[z].jee_advanced, &ver2[z].rank_main, &ver2[z].rank_adv, ver2[z].pref_options, ver2[z].pref_list, ver2[z].allotted_seat, ver2[z].choose_wait_skip);
}
for (int i = 0; i < student_count; i++) {
        fscanf(fp2, "[%d,%[^,],%d]\n", &ranks1[i].rank, ranks1[i].username, &ranks1[i].mark);
       //printf("rank %d username %s\n", ranks1[i].rank, ranks1[i].username);
    }

    for (int j = 0; j < pref_count; j++) {
        fscanf(fp4, "%s %d %d %d %d\n", pref[j].username, &pref[j].pref1, &pref[j].pref2, &pref[j].pref3,&pref[j].changed);
        //printf("username %s pref1 %d pref2 %d pref3 %d\n", pref[j].username, pref[j].pref1, pref[j].pref2, pref[j].pref3);
    }
    for(int i=0;i<100;i++){
        char username[100];
        int alloted_nit_seat;
        fscanf(fp3,"%s %d\n",username,&alloted_nit_seat);
        //printf("%s %d\n",username,alloted_iit_seat);
        for(int j=0;j<student_count;j++){
            if(strcmp(ranks1[j].username,username)==0){
                    //printf("found %s\n",ranks1[j].username);
                    for(int k=0;k<pref_count;k++){
                        //printf("%s\n",pref[k].username);
                            if(strcmp(pref[k].username,username)==0){
                                if(alloted_nit_seat==pref[k].pref1){
                                    //printf("found at 1 %d\n",pref[k].pref1);
                                    ranks1[j].rank=0;
                                }
                                else if(alloted_nit_seat==pref[k].pref3){
                                    //printf("found at 3, prev pref are %d %d\n",pref[k].pref1,pref[k].pref2);
                                    if((pref[k].pref1>200)&&(pref[k].pref2>200)){
                                        ranks1[j].rank=0;
                                    }
                                }else if(alloted_nit_seat==pref[k].pref2){
                                    //printf("found at 2, prev pref is %d\n",pref[k].pref1);
                                    if(pref[k].pref1>200){
                                        ranks1[j].rank=0;
                                    }
                                }else if(alloted_nit_seat==pref[k].pref4){
                                    //printf("found at 3, prev pref are %d %d\n",pref[k].pref1,pref[k].pref2);
                                    if((pref[k].pref1>200)&&(pref[k].pref2>200)&&(pref[k].pref3>200)){
                                        ranks1[j].rank=0;
                                    }
                                }else if(alloted_nit_seat==pref[k].pref5){
                                    //printf("found at 3, prev pref are %d %d\n",pref[k].pref1,pref[k].pref2);
                                    if((pref[k].pref1>200)&&(pref[k].pref2>200)&&(pref[k].pref3>200)&&(pref[k].pref4>200)){
                                        ranks1[j].rank=0;
                                    }
                                }
                            }
                    }
            }
        }
    }
    fclose(fp2);
    fp2=fopen("Jee_main.txt","w");
    for(int i=0;i<student_count;i++){
        fprintf(fp2,"[%d,%s,%d]\n",ranks1[i].rank,ranks1[i].username,ranks1[i].mark);
    }
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);

}


int main() {
    FILE *fp;
    fp=fopen("Structures.txt","r");
    while(!feof(fp)){
        for(int i=0;i<10;i++){
        fscanf(fp,"%d %s %d\n",&univ[i].code,univ[i].name,&univ[i].seats);
        //printf("%s %d %d\n",univ[i].name,univ[i].code,univ[i].seats);
    }}
    FILE *file = fopen("Student.txt", "r");
    
    int student_count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            student_count++;
        }
    }
    //printf("student count %d\n",student_count);

    fclose(file);
    file = fopen("preferences.txt", "r");
    
    int pref_count = 0;
    //char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            pref_count++;
        }
    }

    fclose(file);
    //printf("preference count %d\n",pref_count);
    file = fopen("Structures.txt", "r");
    
    int univ_count = 0;
    //char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            univ_count++;
        }
    }

    fclose(file);
    //printf("univ count %d\n",univ_count);
    
    for(int i=0;i<3;i++){
        allot_main(univ_count,pref_count,student_count);
        filter_adv(univ_count,pref_count,student_count);
        allot_adv(univ_count,pref_count,student_count);
        filter_main(univ_count,pref_count,student_count);}
        

    
}