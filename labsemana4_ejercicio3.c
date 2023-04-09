#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

typedef struct Patient{
char name[50];
int age;
int room;
float temperature[max];
int temp; //contador de temperaturas
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
		scanf("%f",&patients[*numPatients].temperature[0]);
		
		(*numPatients)++;
		patients[*numPatients].temp = 1;
	}	
}

void recordTemperature(Patient patients[], int numPatients){
	int i;
	int paciente;
	
	for(i=0; i < numPatients; i++){
		printf("%d.nombre: %s\n", i+1, patients[i].name);
	}
	printf("indique el numero del paciente al cual desea registrar una nueva temperatura:");
	scanf("%d",&paciente);
	printf("indique la temperatura a registrar para el paciente %s:",patients[paciente-1].name);
	scanf("%f",&patients[paciente-1].temperature[patients[paciente-1].temp]);
	patients[paciente-1].temp++;
}

void print(Patient patients[], int numPatients){
	int k=0;
	printf("-----------------------------\n");
	printf("Cantidad de pacientes: %d\n", numPatients);
	printf("-----------------------------\n\n");
	int i;
	for(i=0; i < numPatients; i++){
		printf("%d.nombre: %s\n", i+1, patients[i].name);
		printf("edad: %d\n",patients[i].age);
		printf("habitacion: %d\n",patients[i].room);
		
		for(k=0; k<patients[i].temp; k++){ //imprime las temperaturas dependiendo de el contador para imprimir todas las temperaturas ingresadas
			printf("temperatura %d: %.1f\n",k+1, patients[i].temperature[k]);
		}
		printf("\n");
	}
	printf("-----------------------------\n");
}



int main(){
	
	Patient patients[max];
	
	int numPatients;
	int i, op = 3;
	
	printf("indique el numero de pacientes:");
	scanf("%d",&numPatients);
	
	
	if(numPatients <= 0){
		numPatients = 1;
	}
	if(numPatients >= max){
		numPatients = max;
	}
	
	for(i=0; i < numPatients; i++){ //se inicializa el contador de temperaturas en 1 ya que al ingresarse ya se ingreso una temperatura
		patients[i].temp = 1;	
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
		scanf("%f",&patients[i].temperature[0]);
		
	}
	
	
	int j=0;
	
	while(j == 0){
		printf("\n[1] gregar paciente\n");
		printf("[2] mostrar pacientes\n");
		printf("[3] agregar temperatura\n");
		printf("[4] salir");
		printf("\nopciones\n");
		
		scanf("%d",&op);
	
	
		
		if(op==1){
			addPatient(patients, &numPatients);
		}
		
		
		if(op == 2){
			print(patients, numPatients);	
		}
		if(op == 3){
			recordTemperature(patients,numPatients);
		}
		if(op == 4){
			j = 1;
		}	
	}
		
	return 0;
}
