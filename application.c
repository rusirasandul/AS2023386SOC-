/* Simple in-memory CRUD example in C. */
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_SIZE 50

typedef struct {
	int id;
	char name[NAME_SIZE];
	int age;
} Record;

static Record records[MAX_RECORDS];
static int record_count = 0;

void create_record(void) {
	if (record_count >= MAX_RECORDS) {
		printf("Storage is full.\n");
		return;
	}

	Record *record = &records[record_count];
	record->id = record_count + 1;
	printf("Enter name: ");
	scanf(" %49[^\n]", record->name);
	printf("Enter age: ");
	scanf("%d", &record->age);
	record_count++;
	printf("Record created with ID %d.\n", record->id);
}

void read_records(void) {
	if (record_count == 0) {
		printf("No records found.\n");
		return;
	}

	printf("\n%-5s %-30s %-5s\n", "ID", "Name", "Age");
	for (int i = 0; i < record_count; i++) {
		printf("%-5d %-30s %-5d\n", records[i].id, records[i].name,
			   records[i].age);
	}
}

void update_record(void) {
	int id;
	printf("Enter ID to update: ");
	scanf("%d", &id);

	for (int i = 0; i < record_count; i++) {
		if (records[i].id == id) {
			printf("Enter new name: ");
			scanf(" %49[^\n]", records[i].name);
			printf("Enter new age: ");
			scanf("%d", &records[i].age);
			printf("Record updated.\n");
			return;
		}
	}
	printf("Record not found.\n");
}

void delete_record(void) {
	int id;
	printf("Enter ID to delete: ");
	scanf("%d", &id);

	for (int i = 0; i < record_count; i++) {
		if (records[i].id == id) {
			for (int j = i; j < record_count - 1; j++) {
				records[j] = records[j + 1];
			}
			record_count--;
			printf("Record deleted.\n");
			return;
		}
	}
	printf("Record not found.\n");
}

int main(void) {
	int choice;

	do {
		printf("\n--- Simple CRUD Menu ---\n");
		printf("1. Create\n2. Read\n3. Update\n4. Delete\n5. Exit\n");
		printf("Choose an option: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1: create_record(); break;
			case 2: read_records(); break;
			case 3: update_record(); break;
			case 4: delete_record(); break;
			case 5: printf("Goodbye.\n"); break;
			default: printf("Invalid option.\n");
		}
	} while (choice != 5);

	return 0;
}
