#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5

typedef struct Patient{
char name[50];
int age;
int room;
float temperature;
} Patient;


void addPatient(Patient patients[]){
	int i;
	for(i=0; i<max; i++){
		
		printf("-------- Paciente %d --------\n",i+1);
		printf("indique el nombre:");
		scanf("%s",&patients[i].name);
		printf("indique la edad:");
		scanf("%d",&patients[i].age);
		printf("indique la habitacion:");
		scanf("%d",&patients[i].room);
		printf("indique la temperatura:");
		scanf("%f",&patients[i].temperature);
		
	}
	
}

void print(Patient patients[]){
	int i;
	for(i=0; i<max; i++){
		printf("%d.nombe:%s\n",i+1,patients[i].name);
		printf("%d.edad:%d\n",i+1,patients[i].age);
		printf("%d.habitacion:%d\n",i+1,patients[i].room);
		printf("%d.habitacion:%.2f\n",i+1,patients[i].temperature);
		
	}
	
}

int main(){
	
	Patient patients[max];
	
	addPatient(patients);
	print(patients);
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	
	
	
	return 0;
}
