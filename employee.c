//Steve Cha Assignment 02
#include "employee.h"
EMPLOYEE* list_of_employees=NULL;

void printEmployee(EMPLOYEE e){
    // Your code here
	//print name and id
	printf("Name: ");
	printf("%s",e.name);
	printf(", ID: ");
	printf("%d",e.id);
	printf("\n-----------------\n");
	PAYMENT* ep = e.payments;
	//if there are no payments, display no payments. if there are payments, go through each payment and display the details.
	if(ep == NULL){
		printf("%s", "No Payments...");
	}
	else{
		int hasNext = 1;
		printf("Date\t\tAmount\n");
		while(hasNext == 1){
			printf("%s", ep -> date);
			printf("\t");
			printf("%f", ep->amount);
			printf("\n");
			if(ep -> next == NULL){
			hasNext = 0;
			}
			ep = ep -> next;
		}
	}
}



void addEmployee(int e_id, char* e_name){
    // Your code here
	EMPLOYEE* emp = (EMPLOYEE*) malloc(sizeof(EMPLOYEE));
	emp -> id = e_id;
	emp -> name = e_name;
	emp -> payments = NULL;
	emp -> next = list_of_employees;
	list_of_employees = emp;
}




void printEmployees(){
    // Your code here
	EMPLOYEE* emp = list_of_employees;
	int empHasNext = 0;
	if(emp -> id == 0){
		printf("The list is empty...");
	}
	else{
		empHasNext = 1;
	}
	while(empHasNext == 1){
		if(emp -> id != 0){
			printf("Name: ");
			printf("%s",emp -> name);
			printf(", ID: ");
			printf("%d",emp -> id);
			printf("\n-----------------\n");
			PAYMENT* ep = emp -> payments;
			if(ep == NULL){
				printf("%s", "No Payments...\n");
				printf("=================\n");
			}
			else{
				int hasNext = 1;
				printf("Date\t\tAmount\n");
				printf("----\t\t------\n");
				while(hasNext == 1){
					printf("%s", ep -> date);
					printf("\t");
					printf("%f", ep->amount);
					printf("\n");
					if(ep -> next == NULL){
						hasNext = 0;
					}
					ep = ep -> next;
				}
				printf("==========================\n");
			}
	
			if(emp -> next == NULL){
				empHasNext = 0;
			}
			emp = emp -> next;
		}
		if(emp -> id == 0){
			empHasNext = 0;
		}	
	}
}



int addPayment(int e_id, char* p_date, float p_amount){
    // Your code here
	//go through list and find the employee you're looking for
	int atEmp = 0;
	EMPLOYEE* emp = list_of_employees;

	while(atEmp == 0){
		if(emp -> id == e_id){
			//code to add payments
			PAYMENT* pay = (PAYMENT*) malloc(sizeof(PAYMENT));
			pay -> date = p_date;
			pay -> amount = p_amount;
			pay -> next = emp -> payments;
			emp -> payments = pay;
			//stop the while loop
			atEmp = 1;
		}
		emp = emp -> next;
	}
}



int deleteEmployee(int e_id, char* e_name){
    // Your code here
	//find employee you're looking for
	int atEmp = 0;
	int nextChain = 0;
	EMPLOYEE* emp = list_of_employees;

	while(atEmp == 0){
		if(emp -> id == e_id){
			//code to delete employee
			while(nextChain == 0){
				if(emp -> next == NULL){
					emp -> id = 0;
					emp -> name = NULL;
					emp -> payments = NULL;
					nextChain = 1;
				}
				else{
					emp -> id = emp -> next -> id;
					emp -> name = emp -> next -> name;
					emp -> payments = emp -> next -> payments;
					emp -> next = emp -> next -> next;
					emp = emp -> next;
				}
			}
			atEmp = 1;
		}
		emp = emp -> next;
	}
}
