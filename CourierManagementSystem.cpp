#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 100

//Structure for storing Courier details
typedef struct{
	char name[50];
	int id;
	char address[50];
}Record;

//function prototypes
void create_record();
void search_record();
void modify_record();
void delete_record();
void display_record();

//global variable
Record records[MAX_RECORDS];
int num_records=0;

int main(){
	int choice;
	
	//display the menu and process user input
	do{
		printf("-------------- COURIER MANAGEMENT SYSTEM --------------\n");
		printf("\n");
		printf("1. Create Record\n");
		printf("2. Search Record\n");
		printf("3. Modify Record\n");
		printf("4. Delete Record\n");
		printf("5. Display Record\n");
		printf("0. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				create_record();
				break;
			case 2:
				search_record();
				break;
			case 3:
				modify_record();
				break;
			case 4:
				delete_record();
				break;
			case 5:
				display_record();
				break;
			case 0:
				printf("Exiting program...\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
				break;
		}
	}while(choice!=0);
	return 0;
}

//function to create new record
void create_record(){
	Record record;
	printf("\nEnter Name: ");
	scanf("%s",&record.name);
	printf("\nEnter ID: ");
	scanf("%d",&record.id);
	printf("\nEnter Adress: ");
	scanf("%s",&record.address);
	
	//add record to global array
	records[num_records]=record;
	num_records++;
	
	//write code in file
	FILE *fp=fopen("records.txt","a");
	if(fp==NULL){
		printf("Error opening file.\n");
		return;
	}
	fprintf(fp,"%s %d %s\n",record.name,record.id,record.address);
	fclose(fp);
	printf("Record created Successfully....\n");
}

//function to search for a record
void search_record(){
	int id,found=0,i;
	printf("\nEnter ID to search for: ");
	scanf("%d",&id);
	for(i=0;i<num_records;i++){
		if(records[i].id==id){
			printf("\nRecord Found\n");
			printf("Name: %s\n",records[i].name);
			printf("ID: %d\n",records[i].id);
			printf("ADDRESS: %s\n",records[i].address);
			found=1;
			break;
		}
	}
	if(!found){
		printf("\nRecord not found.\n");
	}
}

//Function to modify a function
void modify_record(){
	int id,found=0,i,j;
	printf("Enter ID to modify: ");
	scanf("%d",&id);
	for(i=0;i<num_records;i++){
		if(records[i].id==id){
			printf("\nEnter new details\n");
			printf("Name: ");
			scanf("%s",&records[i].name);
			printf("ID: ");
			scanf("%d",&records[i].id);
			printf("Address: ");
			scanf("%s",&records[i].address);
		
			//update record in file
			FILE *fp=fopen("records.txt","w");
			if(fp==NULL){
				printf("Error opening file.\n");
				return;
			}
			for(j=0;j<num_records;j++){
				fprintf(fp,"%s %d %s\n",records[j].name,records[j].id,records[j].address);
			}
			fclose(fp);
			printf("Record modified successfully.\n");
			found=1;
			break;
		}
	}
	if(!found){
		printf("\nRecord not found.\n");
	}
}

//function to delete a record
void delete_record(){
	int id,found=0,i,j;
	printf("\nEnter ID to delete: \n");
	scanf("%d",&id);
	for(i=0;i<num_records;i++){
		if(records[i].id==id){
			//shift remaining records up by one
			for(j-i;j<num_records-1;j++){
				records[j]=records[j+1];
			}
			num_records--;
			
			//write updated record to file
			FILE *fp=fopen("records.txt","w");
			if(fp==NULL){
				printf("Error opening file.\n");
				return;
			}
			for(j=0;j<num_records;j++){
				fprintf(fp,"%s %d %s\n",records[j].name,records[j].id,records[j].address);
			}
			fclose(fp);
			printf("Record deleted successfully.\n");
			found=1;
			break;
		}
	}
	if(!found){
		printf("\nRecord not found\n");
	}
}

//function to display all records
void display_record(){
	FILE *fp=fopen("records.txt","r");
	if(fp==NULL){
		printf("Error opening file\n");
		return;
	}
	printf("\n----------All Records----------\n");
	while(!feof(fp)){
		char name[50];
		int id;
		char address[50];
		if(fscanf(fp,"%s %d %s\n",&name,&id,&address)==3){
			printf("Name: %s\n",name);
			printf("ID: %d\n",id);
			printf("Address: %s\n",address);
			printf("\n");
		}
	}
	fclose(fp);
}
