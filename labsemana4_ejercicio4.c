#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Patient{
char name[50];
int age;
int room;
float temperature[5];
int conttemp; //contador de temperaturas
struct Patient *next;
} Patient;

void addPatient(Patient **head){
	//se crea un nuevo nodo
	Patient *newPatient = (Patient *)malloc(sizeof(struct Patient));
	printf("-------- Paciente --------\n");
	printf("indique el nombre:");
	scanf("%s",newPatient->name);
	printf("indique la edad:");
	scanf("%d",&newPatient->age);
	printf("indique la habitacion:");
	scanf("%d",&newPatient->room);
	printf("indique la temperatura:");
	scanf("%f",&newPatient->temperature[0]);
	newPatient-> conttemp = 1;
	
	newPatient->next = NULL;
	//se verifica si la lista esta vacia
	if(*head == NULL){
	    *head = newPatient;
	}
	else{
	    //se recorre la lista hasta el ultimo nodo y se agrega el nuevo paciente
	    Patient *current = *head;
	    
	    while(current->next != NULL){
	        current = current->next;
	    }
	    current->next = newPatient;
	}
}



void recordTemperature(Patient *head){
	int i = 1;
	int paciente;
	//se crea una copia de la lista original
	Patient *current = head;
	//se muestra la lista de pacientes
	printf("Pacientes:\n");
	while(current != NULL){
		printf("%d. %s\n",i, current->name);
		current = current->next;
		i++;
	}
	printf("indique el numero del paciente al cual desea registrar una nueva temperatura:");
	scanf("%d",&paciente);
	//se recorre la copia de la lista hasta el nodo correspondiente y se agrega la nueva temperatura
	i = 1;
	current = head; //se vuelve a apuntar al inicio de la lista
	while(current != NULL){
	    if(i == paciente){
	        float t;
	        printf("indique la temperatura a registrar para el paciente: %s\n",current->name);
	        scanf("%f",&t);
	        current->temperature[current->conttemp] = t;
	        current->conttemp++;
	        break;
	    }
	    current = current->next;
	    i++;
	}
}

void dischargePatient(Patient **head){
    int i = 1;
    int paciente;
    //se crea una copia de la lista original
    Patient *current = *head;
    //se muestra la lista de pacientes
    printf("Pacientes:\n");
    while(current != NULL){
        printf("%d. %s\n",i, current->name);
        current = current->next;
        i++;
    }
    printf("indique el numero del paciente que desea eliminar:");
    scanf("%d",&paciente);
    //se verifica si se quiere eliminar el primer paciente de la lista
    if(paciente == 1){
        Patient *temporal = *head;
        *head = (*head)->next;
        free(temporal);
    }
    else{
        i = 1;
        current = *head; //se vuelve a apuntar al inicio de la lista
        Patient *previous = NULL;
        while(current != NULL){
            if(i == paciente){
                //se elimina el nodo correspondiente al paciente
                previous->next = current->next;
                free(current);
                break;
            }
            previous = current;
            current = current->next;
            i++;
        }
    }
}

void print(Patient *head){
	printf("-----------------------------\n");
	int i = 1;
	int j = 0;
	while(head != NULL){
	printf("%d. nombre: %s\n",i,head->name);
	printf("   edad: %d\n",head->age);
	printf("   habitacion: %d\n",head->room);
	for(j=0;j<head->conttemp;j++){
		printf("   temperatura %d: %.1f\n",j+1,head->temperature[j]);
	}
	head = head->next;
	i++;
	}
	printf("-----------------------------\n");
	
	
}

void freePatients(Patient *head) {
	Patient *current = head;
	while (current != NULL) {
		Patient *next = current->next;
		free(current);
		current = next;
	}
}

int main(){
	Patient *head = NULL;
	int op = 3;
	while(op != 5){
		printf("\n[1] agregar paciente\n");
		printf("[2] mostrar pacientes\n");
		printf("[3] agregar temperatura\n");
		printf("[4] dar de alta al paciente\n");
		printf("[5] salir\n");
		printf("opciones:");
		scanf("%d",&op);
	
		if(op == 1){
			addPatient(&head);
		}
		if(op == 2){
			print(head);
		}
		if(op == 3){
			recordTemperature(head);
		}
		if(op == 4){
			dischargePatient(&head);
		}
		if(op == 5){
			printf("Saliendo...\n");
		}
	}

	//se libera la memoria de todos los nodos
	freePatients(head);
	
return 0;
}
