#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

typedef struct Patient{
char name[50];
int age;
int room;
float temperature;
} Patient;


void addPatient(Patient patients[],int *numPatients){
	
	if(*numPatients == max){
		printf("no se puede agregar mas pacientes");
	}
	else{
		printf("-------- Paciente %d --------\n",*numPatients+1);
		printf("indique el nombre:");
		scanf("%s",&patients[*numPatients].name);
		printf("indique la edad:");
		scanf("%d",&patients[*numPatients].age);
		printf("indique la habitacion:");
		scanf("%d",&patients[*numPatients].room);
		printf("indique la temperatura:");
		scanf("%f",&patients[*numPatients].temperature);
		
		(*numPatients)++;
	}
	
	
	
}


void print(Patient patients[], int numPatients){
	printf("-----------------------------\n");
	printf("Cantidad de pacientes: %d\n", numPatients);
	printf("-----------------------------\n\n");
	int i;
	for(i=0; i < numPatients; i++){
		printf("%d.nombre: %s\n", i+1, patients[i].name);
		printf("%d.edad: %d\n", i+1, patients[i].age);
		printf("%d.habitacion: %d\n", i+1, patients[i].room);
		printf("%d.temperatura: %.2f\n\n", i+1, patients[i].temperature);
		
	}
	printf("-----------------------------\n");
}



int main(){
	
	Patient patients[max];
	
	int numPatients;
	int i, op = 3;
	
	printf("indique el numero de pacientes:");
	scanf("%d",&numPatients);
	
	
	if(numPatients <= 0){	//en caso de se una cifra menor o igual a 0 se establece como minimo 1
		numPatients = 1;
	}
	if(numPatients > max){	//en caso de se una cifra mayor a el maximo se establece como maximo 100
		numPatients = max;
	}
	
	for(i=0; i<numPatients; i++){
		
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
	
	
	int j=0;
	
	while(j == 0){
		printf("\n[1] gregar paciente\n");
		printf("[2] mostrar pacientes\n");
		printf("[3] salir");
		printf("\nopciones\n");
		
		scanf("%d",&op);
	
	
		
		if(op==1){
			addPatient(patients, &numPatients);
		}
		
		
		if(op == 2){
			print(patients, numPatients);	
		}
		if(op==3){
			j = 1;
		}	
	}
		
	return 0;
}
