/*username | name | age | jee_main | jee_advanced | rank_main | rank_adv | preference_order_choice | prefernce_list | allotted seat | choose_wait_skip*/
#include<stdio.h>
#include<string.h>
struct verify1{
    char user_name[20];
    char pswd[20];
}ver,ver1[1000];

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

struct verify2{
    char username[20];
    char name[20];
    int age;
    int jee_main;
    int jee_advanced,rank_main,rank_adv;
    char pref_options[100];
    char pref_list[100];
    char allotted_seat[100];
    char choose_wait_skip[100];
}ver2[1000];

void preference_input(char username[],int student_count){
    FILE *fp4;
    fp4=fopen("Student.txt","r+");
    for(int i=0;i<student_count;i++){
        fscanf(fp4,"%s %s %d %d %d %d %d %s %s %s %s\n",ver2[i].name,ver2[i].username,&ver2[i].age,&ver2[i].jee_main,&ver2[i].jee_advanced,&ver2[i].rank_main,&ver2[i].rank_adv,&ver2[i].pref_options,&ver2[i].pref_list,&ver2[i].allotted_seat,&ver2[i].choose_wait_skip);
		if(strcmp(username,ver2[i].username)==0){
			printf("your mains rank is %d\n",ver2[i].rank_main);
			printf("your advanced rank is %d\n",ver2[i].rank_adv);
            printf("%s\n",ver2[i].pref_options);
			strcpy(pref[i].username,ver2[i].username);
        if(strcmp(ver2[i].pref_options,"[sorry_you_are_not_eligible]")!=0){
			FILE *fp5;
			fp5=fopen("preferences.txt","a+");
		printf("Choose 5 options from the given choices: \n");
		int pref1,pref2,pref3,pref4,pref5;
		printf("pref1: ");
		scanf("%d",&pref1);
		printf("pref2: ");
		scanf("%d",&pref2);
		printf("pref3: ");
		scanf("%d",&pref3);
		printf("pref4: ");
		scanf("%d",&pref4);
		printf("pref5: ");
		scanf("%d",&pref5);
		fprintf(fp5,"%s %d %d %d %d %d 0\n",username,pref1,pref2,pref3,pref4,pref5);
		fclose(fp5);

		}else{
			printf("sorry you are not eligible for prefernce selection\n");
		}
			strcpy(ver2[i].pref_list,"[preferences_filled]");}}
        fclose(fp4);
		
	
	fp4=fopen("Student.txt","w+");
	for(int i=0;i<student_count;i++){
		fprintf(fp4,"%s %s %d %d %d %d %d %s %s [] []\n",ver2[i].name,ver2[i].username,ver2[i].age,ver2[i].jee_main,ver2[i].jee_advanced,ver2[i].rank_main,ver2[i].rank_adv,ver2[i].pref_options,ver2[i].pref_list);
	}
	fclose(fp4);
}

void signup(){
	FILE *fp1;
	fp1=fopen("login.txt","a+");
	char username[20];
	printf("username: ");
	scanf("%s",username);
	while(!feof(fp1)){
		
    fscanf(fp1,"%s",ver.user_name);
    if(strcmp(username,ver.user_name)==0){
        printf("Username taken\n");
		
        return;
    }}
	
	char password[20];
	printf("password: ");
	scanf("%s",password);
	
	
	
	fprintf(fp1,"%s %s\n",username,password);
	fclose(fp1);
	printf("Signed up\n");
	return;

}





void details_entry(char username[]){
	
	FILE *fp3;
	fp3=fopen("Student.txt","r+");
	FILE *file = fopen("Student.txt", "r");
    
    int student_count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
		
        if (c == '\n') {
            student_count++;
        }
    }
	for(int i=0;i<student_count;i++){
        fscanf(fp3,"%s %s %d %d %d %d %d %s %s %s %s\n",ver2[i].name,ver2[i].username,&ver2[i].age,&ver2[i].jee_main,&ver2[i].jee_advanced,&ver2[i].rank_main,&ver2[i].rank_adv,ver2[i].pref_options,ver2[i].pref_list,ver2[i].allotted_seat,ver2[i].choose_wait_skip);
        //printf("%s %d\n",ver2[i].username,ver2[i].rank_main);
	}
		for(int i=0;i<student_count;i++){
			if((strcmp(username,ver2[i].username)==0&&ver2[i].rank_main==0&&strcmp(ver2[i].choose_wait_skip,"skip")==0)){
			printf("You are out of the admission process\n");
			return;
		}
		if((strcmp(username,ver2[i].username)==0&&ver2[i].rank_main==0&&strcmp(ver2[i].choose_wait_skip,"chose")!=0)||(strcmp(username,ver2[i].username)==0&&strcmp(ver2[i].pref_list,"[preferences_filled]")==0)&&(strcmp(ver2[i].allotted_seat,"[]")==0)||(strcmp(username,ver2[i].username)==0&&ver2[i].rank_main!=0&&strcmp(ver2[i].allotted_seat,"[]")==0&&strcmp(ver2[i].choose_wait_skip,"wait")==0)){
			fclose(fp3);
            printf("kindly wait for updates\n");
            return;
        }else if((strcmp(username,ver2[i].username)==0&&ver2[i].rank_main==0&&strcmp(ver2[i].choose_wait_skip,"chose")==0)){
			printf("congrats, you got seat in %s\n",ver2[i].allotted_seat);
			return;
		}
		else if(strcmp(username,ver2[i].username)==0&&ver2[i].rank_main!=0&&strcmp(ver2[i].allotted_seat,"[]")==0&&strcmp(ver2[i].choose_wait_skip,"wait")!=0){
			//printf("%s\n",ver2[i].username);
			fclose(fp3);
			FILE *file = fopen("Student.txt", "r");
    
    int student_count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            student_count++;
        }
    }
			preference_input(username,student_count);
			return;
		}else if(strcmp(username,ver2[i].username)==0&&strcmp(ver2[i].allotted_seat,"[]")!=0){
			FILE *file = fopen("Structures.txt", "r");
    
    int univ_count = 0;
    //char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            univ_count++;
        }
    }
	fclose(file);
			FILE *fp;
    fp=fopen("Structures.txt","r");
    while(!feof(fp)){
        for(int i=0;i<univ_count;i++){
        fscanf(fp,"%d %s %d\n",&univ[i].code,univ[i].name,&univ[i].seats);
        //printf("%s %d %d\n",univ[i].name,univ[i].code,univ[i].seats);
    }}
	fclose(fp);
			printf("%s\n",ver2[i].allotted_seat);
			int choose_wait;
			printf("1 to choose, 2 to wait, 3 to skip: ");
			scanf("%d",&choose_wait);
			if(choose_wait==1){
					
					FILE *fp4=fopen("Structures.txt","r+");
					for(int x=0;x<univ_count;x++){
						
						if(strcmp(univ[x].name,ver2[i].allotted_seat)==0){
						univ[x].seats-=1;
						ver2[i].rank_main=0;
						ver2[i].rank_adv=0;
						strcpy(ver2[i].choose_wait_skip,"chose");
						}}
						fclose(fp4);
						fclose(fp3);
						fp4=fopen("Student.txt","w+");
						for(int z=0;z<student_count;z++){
							fprintf(fp4,"%s %s %d %d %d %d %d %s %s %s %s\n",ver2[z].name,ver2[z].username,ver2[z].age,ver2[z].jee_main,ver2[z].jee_advanced,ver2[z].rank_main,ver2[z].rank_adv,ver2[z].pref_options,ver2[z].pref_list,ver2[z].allotted_seat,ver2[z].choose_wait_skip);
						}
						fclose(fp4);
						fp4=fopen("Structures.txt","w+");
						for(int z=0;z<univ_count;z++){
							fprintf(fp4,"%d %s %d\n",univ[z].code,univ[z].name,univ[z].seats);
						}
						fclose(fp4);
					
			}else if(choose_wait==2){
					strcpy(ver2[i].allotted_seat,"[]");
					strcpy(ver2[i].choose_wait_skip,"wait");
					fclose(fp3);
					FILE *fp4=fopen("Student.txt","w+");
						for(int z=0;z<student_count;z++){
							fprintf(fp4,"%s %s %d %d %d %d %d %s %s %s %s\n",ver2[z].name,ver2[z].username,ver2[z].age,ver2[z].jee_main,ver2[z].jee_advanced,ver2[z].rank_main,ver2[z].rank_adv,ver2[z].pref_options,ver2[z].pref_list,ver2[z].allotted_seat,ver2[z].choose_wait_skip);
						}
						fclose(fp4);

			}else if(choose_wait==3){
				FILE *fp4=fopen("Structures.txt","r+");
					for(int x=0;x<univ_count;x++){
						
						if(strcmp(univ[x].name,ver2[i].allotted_seat)==0){
						
						ver2[i].rank_main=0;
						ver2[i].rank_adv=0;
						strcpy(ver2[i].choose_wait_skip,"skip");
						}}
						fclose(fp4);
						fclose(fp3);
						fp4=fopen("Student.txt","w+");
						for(int z=0;z<student_count;z++){
							fprintf(fp4,"%s %s %d %d %d %d %d %s %s %s %s\n",ver2[z].name,ver2[z].username,ver2[z].age,ver2[z].jee_main,ver2[z].jee_advanced,ver2[z].rank_main,ver2[z].rank_adv,ver2[z].pref_options,ver2[z].pref_list,ver2[z].allotted_seat,ver2[z].choose_wait_skip);
						}
						fclose(fp4);
						fp4=fopen("Structures.txt","w+");
						for(int z=0;z<univ_count;z++){
							fprintf(fp4,"%d %s %d\n",univ[z].code,univ[z].name,univ[z].seats);
						}
						fclose(fp4);
			}
			
			return;
		}
    }
	char name[20];
    printf("name: ");
    scanf("%s",name);
	int age;
	printf("age: ");
	scanf("%d",&age);
	printf("jee main mark: ");
	int jee_main;
	scanf("%d",&jee_main);
	printf("jee adv mark: ");
	int jee_advanced;
	scanf("%d",&jee_advanced);
	
		fprintf(fp3,"%s %s %d %d %d 0 0 [] [] [] []\n",name,username,age,jee_main,jee_advanced);
		fclose(fp3);
		
}

void login(){
	char username[20];
	printf("username: ");
	scanf("%s",username);
	char password[20];
	printf("password: ");
	scanf("%s",password);
	FILE *fp2;
	fp2=fopen("login.txt","r");
	
	while(!feof(fp2)){
		for(int i=0;i<1000;i++){
		fscanf(fp2,"%s %s\n",ver1[i].user_name,ver1[i].pswd);
		if(strcmp(username,ver1[i].user_name)==0){
			if(strcmp(password,ver1[i].pswd)==0){
				printf("logged in\n");
				fclose(fp2);
				details_entry(username);
                return;
			}
		else{printf("invalid username or password\n");fclose(fp2);return;}}}

	}printf("invalid username or password\n");

}


int main(){
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
	int z=0;
	while(z!=3){
		printf("1 to login, 2 to signup, 3 to exit: ");
		scanf("%d",&z);
		if(z==1){login();}else if(z==2){signup();}
	}
}