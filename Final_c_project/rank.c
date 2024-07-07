#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct university {
    int code;
    char name[20];
    int seats;
} univ[20], univ_dup[20];

struct verify2 {
    char username[20];
    char name[20];
    int age;
    int jee_main;
    int jee_advanced, rank_main, rank_adv;
    char pref_options[100];
    char pref_list[100];
    char allotted_seat[100];
    char choose_wait_skip[100];
} ver2[1000], det,ver3[1000];

struct ranks {
    int rank;
    char username[20];
    int mark;
} ranks1[1000], ranks2[1000];

void jee_main_sorter(int student_count) {
    int i, j;
    FILE* fp;
	FILE *fp2;
    fp = fopen("Student.txt", "r");
	fp2 = fopen("Student.txt", "r");
    for (int i = 0; i < student_count; i++) {
        fscanf(fp,"%s %s %d %d %d %d %d %s %s %s %s\n",ver2[i].name,ver2[i].username,&ver2[i].age,&ver2[i].jee_main,&ver2[i].jee_advanced,&ver2[i].rank_main,&ver2[i].rank_adv,ver2[i].pref_options,ver2[i].pref_list,ver2[i].allotted_seat,ver2[i].choose_wait_skip);
		fscanf(fp2, "%s %s %d %d %d %d %d %s %s %s %s\n", ver3[i].name, ver3[i].username, &ver3[i].age, &ver3[i].jee_main, &ver3[i].jee_advanced, &ver3[i].rank_main, &ver3[i].rank_adv, ver3[i].pref_options, ver3[i].pref_list, ver3[i].allotted_seat, ver3[i].choose_wait_skip);
    }
    for (i = 0; i < student_count; i++){
        for (j = 0; j < student_count - i; j++) {
            if (ver3[j].jee_main < ver3[j + 1].jee_main) {
                det = ver3[j];
                ver3[j] = ver3[j + 1];
                ver3[j + 1] = det;
            }
        }
	}
    fclose(fp);
    FILE* fp1;
    fp1 = fopen("Jee_main.txt", "w");
    for (i = 0; i < student_count; i++) {
        fprintf(fp1, "[%d,%s,%d]\n", i + 1, ver3[i].username, ver3[i].jee_main);
		for(int j=0;j<student_count;j++){
			if(strcmp(ver2[j].username,ver3[i].username)==0){
				ver2[j].rank_main=i+1;
			}
		}
    }
    FILE *fp4 = fopen("Student.txt", "w+");
    
        for (int i = 0; i < student_count; i++) {
            fprintf(fp4, "%s %s %d %d %d %d %d %s %s %s []\n", ver2[i].name, ver2[i].username, ver2[i].age, ver2[i].jee_main, ver2[i].jee_advanced, ver2[i].rank_main, ver2[i].rank_adv, ver2[i].pref_options, ver2[i].pref_list, ver2[i].allotted_seat);
        }
        fclose(fp4);
}

void jee_adv_sorter(int student_count) {
    int i, j;
    FILE* fp;
	FILE* fp2;
    fp = fopen("Student.txt", "r");
	fp2 = fopen("Student.txt", "r");
    for (int i = 0; i < student_count; i++) {
        fscanf(fp,"%s %s %d %d %d %d %d %s %s %s %s\n",ver2[i].name,ver2[i].username,&ver2[i].age,&ver2[i].jee_main,&ver2[i].jee_advanced,&ver2[i].rank_main,&ver2[i].rank_adv,ver2[i].pref_options,ver2[i].pref_list,ver2[i].allotted_seat,ver2[i].choose_wait_skip);
		fscanf(fp2, "%s %s %d %d %d %d %d %s %s %s %s\n", ver3[i].name, ver3[i].username, &ver3[i].age, &ver3[i].jee_main, &ver3[i].jee_advanced, &ver3[i].rank_main, &ver3[i].rank_adv, ver3[i].pref_options, ver3[i].pref_list, ver3[i].allotted_seat, ver3[i].choose_wait_skip);
    }
    for (i = 0; i < student_count; i++){
        for (j = 0; j < student_count - i; j++) {
            if (ver3[j].jee_advanced < ver3[j + 1].jee_advanced) {
                det = ver3[j];
                ver3[j] = ver3[j + 1];
                ver3[j + 1] = det;
            }
        }
	}
    fclose(fp);
	fclose(fp2);
    FILE* fp1;
    fp1 = fopen("Jee_adv.txt", "w");
    for (i = 0; i < student_count; i++) {
        fprintf(fp1, "[%d,%s,%d]\n", i + 1, ver3[i].username, ver3[i].jee_advanced);
		for(int j=0;j<student_count;j++){
			if(strcmp(ver2[j].username,ver3[i].username)==0){
				ver2[j].rank_adv=i+1;
			}
		}
    }
    FILE *fp4 = fopen("Student.txt", "w+");
    
        for (int i = 0; i < student_count; i++) {
            fprintf(fp4, "%s %s %d %d %d %d %d %s %s %s []\n", ver2[i].name, ver2[i].username, ver2[i].age, ver2[i].jee_main, ver2[i].jee_advanced, ver2[i].rank_main, ver2[i].rank_adv, ver2[i].pref_options, ver2[i].pref_list, ver2[i].allotted_seat);
        }
        fclose(fp4);
		}

int main() {
    FILE *file = fopen("Student.txt", "r");
    
    int student_count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            student_count++;
        }
    }
    

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

    file = fopen("Structures.txt", "r");
    
    int univ_count = 0;
    //char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            univ_count++;
        }
    }

    fclose(file);
    int a;
    printf("Shall we generate rank list? 1 for yes: ");
    scanf("%d", &a);
    if (a == 1) {
        jee_main_sorter(student_count);
        jee_adv_sorter(student_count);

        
        printf("Rank list successfully generated\n");
    }

    int rank_main, rank_adv;
    printf("Cutoff mark for jee mains: ");
    scanf("%d", &rank_main);
    printf("Cutoff mark for jee advanced: ");
    scanf("%d", &rank_adv);

    FILE* fp = fopen("Student.txt", "r+");
    for (int i = 0; i < student_count; i++) {
        fscanf(fp, "%s %s %d %d %d %d %d [] [] [] []\n", ver2[i].name, ver2[i].username, &ver2[i].age, &ver2[i].jee_main, &ver2[i].jee_advanced, &ver2[i].rank_main,&ver2[i].rank_adv, ver2[i].pref_options);
        if (ver2[i].jee_main < rank_main) {
            strcpy(ver2[i].pref_options, "[sorry_you_are_not_eligible]");
        } else if (ver2[i].jee_advanced < rank_adv) {
            strcpy(ver2[i].pref_options, "[111:NITT,112:NITC,113:NITS,114:NITK,115:NITW]");
        } else {
            strcpy(ver2[i].pref_options, "[111:NITT,112:NITC,113:NITS,114:NITK,115:NITW,211:IITM,212:IITB,213:IITK,214:IITR,215:IITH]");
        }
    }
    fclose(fp);

    fp = fopen("Student.txt", "w");
    for (int i = 0; i < student_count; i++) {
        fprintf(fp, "%s %s %d %d %d %d %d %s [] [] []\n", ver2[i].name, ver2[i].username, ver2[i].age, ver2[i].jee_main, ver2[i].jee_advanced, ver2[i].rank_main, ver2[i].rank_adv, ver2[i].pref_options);
    }
    fclose(fp);

    return 0;
}
