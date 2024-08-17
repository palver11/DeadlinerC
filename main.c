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
#define MAX_LEN_NAME 10

// PROTOTYPES
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
  for (int i = 0; i < TASKS_SIZE; i++) {
    strcpy(task_names[i], "-----");
  }

  bool exit_program = false;
  while (!exit_program) {

    switch (show_menu()) {
      case 1:
        set_task();
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