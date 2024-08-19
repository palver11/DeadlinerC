// TODO
// add error check for a wrong input with non-numbers in set_task()
// make save and load data from the data file.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define TASKS_SIZE 5
#define MAX_LEN_NAME 30

// PROTOTYPES
void save_data();
void load_data();
void show_tasks();
void set_task();
void conv_secs(int secs);
int show_menu();

// VARIABLES
const int SEC_DAY = 86400;
const int SEC_HR = 3600;
const int SEC_MIN = 60;

char task_names[TASKS_SIZE][MAX_LEN_NAME];
int tasks[TASKS_SIZE];


int main(int argc, char* argv[]) {
  // Assing default task names
  for (int i = 0; i < TASKS_SIZE; i++) {
    strcpy(task_names[i], "-----");
  }

  load_data();

  // Program processing
  bool exit_program = false;
  while (!exit_program) {

    switch (show_menu()) {
      case 1:
        set_task();
        save_data();
        break;
      case 2:
        show_menu();
        break;
      case 3:
        exit_program = true;
        break;
    }
  }
  
  return 0;
}

// WRITE TO A FILE
// fprintf, fputs, puts
// READ FROM A FILE
// fscanf, fgets, gets

void save_data() {
  FILE *p_file = fopen("data.txt", "w");
  int size = (TASKS_SIZE * MAX_LEN_NAME) + (30 * TASKS_SIZE); // dynamically define size for the array
  char data_to_save[size];

  data_to_save[0] = '\0';

  for (int i = 0; i < TASKS_SIZE; i++) {
    char str_secs[30];

    sprintf(str_secs, "%d", tasks[i]); // cast int to str
    strcat(data_to_save, task_names[i]);
    strcat(data_to_save, ",");
    strcat(data_to_save, str_secs);
    strcat(data_to_save, ".");
  }

  fprintf(p_file, data_to_save);

  fclose(p_file);
}

void load_data() {
  FILE *p_file;
  int size = (TASKS_SIZE * MAX_LEN_NAME) + (30 * TASKS_SIZE); // dynamically define size for the array
  char loaded_data[size];

  if ((p_file = fopen("data.txt", "r")) == NULL) {
    printf("Error: unable to load a file. New file was created.");
    // exit(EXIT_FAILURE);
    // save_data(); // Does fopen with "r" create the abscent file automatically?
  }

  fgets(loaded_data, size, p_file);

  // Parsing and assignment of the loaded data
  int y = 0;
  // if (loaded_data[y] == NULL) {
  //   printf("Loading met the end of the file earlier than expected. Data may be corrupted!");
  //   getchar();
  //   break;
  // }

  for (int i = 0; i < TASKS_SIZE; i++) {
    // parsing
    char loaded_name[MAX_LEN_NAME];    
    char loaded_secs[30];


      // name
    for (int ii = 0; loaded_data[ii] != ','; ii++, y++) {
      loaded_name[ii] = loaded_data[y];
      loaded_name[ii + 1] = '\0';
    }
    y++;

      // secs
    for (int ii = 0; loaded_data[ii] != ','; ii++, y++) {
      loaded_secs[ii] = loaded_data[y];
      loaded_secs[ii + 1] = '\0';
    }
    y++;

      // assignment
    strcpy(task_names[i], loaded_name);
    task_names[i][strlen(task_names[i])] = '\0';
    tasks[i] = atoi(loaded_secs);
  }

  fclose(p_file);
}

int show_menu() {
  int choice;
  bool valid_choice;

  system("cls");

  show_tasks();

  printf("\n\n= MENU =\n----------");
  printf("\n1.Edit a task");
  printf("\n2.Refresh");
  printf("\n3.Exit");
  printf("\n\nEnter option number: ");

  do {
    // Get the option number
    int input_err_check = scanf(" %d", &choice);
    if (input_err_check != 1) {
      printf("\nInvalid symbol! Exiting the program...\n");
      exit(EXIT_FAILURE);
      // I tried to make a repetition if a user enetered a character,
      // but for some reason the program just falls into some
      // infinite loop. Couldn't find the solution, so for now
      // the program crashes when a character is entered.
    }
    
    // Check if right number has been entered
    switch (choice) {
      case 1:
      case 2:
      case 3:
        valid_choice = true;
        break;
      default:
        printf("\nInvalid input! Try again:");
        valid_choice = false;
    }
  } while (!valid_choice);

  return choice;
}

void show_tasks() {
  // Get the current time
  time_t now = time(NULL);

  printf("= TASKS =\n----------");
  for (int i = 0; i < TASKS_SIZE; i++) {
    printf("\n%d.%s:  ", (i + 1), task_names[i]);
    conv_secs(difftime(tasks[i], now));
  }
}

void set_task() {
  int index;
  int year;
  int mon;
  int day;
  int hour;
  int mins;
  // int secs;

  // User Input

  // Task
  do {
    printf("\nTask to change (number): ");
    scanf("%d", &index);
  } while (index > (TASKS_SIZE - 1) || index < 0);
  index--;

  // Task name
  printf("\nName the task: ");
  getchar();
  fgets(task_names[index], MAX_LEN_NAME, stdin);
  for (int i = 0; i < MAX_LEN_NAME; i++) { // remove \n from the string which fgets has added
    if (task_names[index][i] == '\n') { task_names[index][i] = '\0'; break; }
  }

  // Year
  printf("Enter end time of your deadline (nums).\nYear: ");
  scanf("%d", &year);

  // Month
  do {
    printf("Month: ");
    scanf("%d", &mon);
  } while (mon > 12 || mon < 1);

  // Day
  printf("Day: ");
  scanf("%d", &day);

  // Hours
  do {
  printf("Hour (24): ");
  scanf("%d", &hour);
  } while (hour > 24 || hour < 0);

  // Minutes
  printf("Minutes: ");
  scanf("%d", &mins);

  // Define a struct tm for a future date (e.g., January 1, 2030)
  struct tm future_date = {0};
  future_date.tm_year = year - 1900;  // Year since 1900
  future_date.tm_mon = mon - 1;             // January (0-based)
  future_date.tm_mday = day;           // 1st
  future_date.tm_hour = hour;
  future_date.tm_min = mins;
  future_date.tm_sec = 0;

  // Convert the future date to a time_t value
  time_t future_time = mktime(&future_date);
    // Error check
  if (future_time == -1) {
    printf("Failed to convert future date.\n");
    exit(EXIT_FAILURE);
    // return;
  }

  tasks[index] = future_time;
}

void conv_secs(int secs) {
  
  if (secs < 1) {
    // printf("0|0:0:0");
    printf("---");
    return;
  }

  int days = 0;
  int hrs  = 0;
  int mins = 0;

  // Convert seconds to days
  if (secs >= SEC_DAY) {
    days = secs / SEC_DAY;
    secs -= days * SEC_DAY;
  }
  
  if (secs >= SEC_HR) {
    hrs = secs / SEC_HR;
    secs -= hrs * SEC_HR;
  }
  
  if (secs >= SEC_MIN) {
    mins = secs / SEC_MIN;
    secs -= mins * SEC_MIN;
  }

  // format time string, add 0 to 1 digit nums
  char z[5] = {""};
  if (days < 10) z[0] = '0';
  if (hrs  < 10) z[1] = '0';
  if (mins < 10) z[2] = '0';
  if (secs < 10) z[3] = '0';

  printf("%c%dd | [%c%d:%c%d:%c%d]", z[0], days, z[1], hrs, z[2], mins, z[3], secs);

}