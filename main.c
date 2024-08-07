// TODO
// move constants from the function into the global scope
// add 0s in singular values when printing time
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void show_tasks(int* tasks);
void set_task(int* tasks);
void conv_secs(int secs);

int tasks[2];

int main(int argc, char* argv[]) {

   set_task(tasks);
   printf("\nEXECUTED"); // DEBUG
   show_tasks(tasks);
   


   return 0;
}

void show_tasks(int* tasks) {
   // Get the current time
   time_t now = time(NULL);

   for (int i = 0; tasks[i] != 0; i++) {
      printf("\nTask %d: ", i+1);
      // Calculate the difference in seconds between the current time and the future time
      conv_secs(difftime(tasks[i], now));
   }
}

void set_task(int* tasks) {
   int index;
   int year;
   int mon;
   int day;
   int hour;
   int mins;
   // int secs;
   // User Input
   printf("\nChoose task to change by index: ");
   scanf("%d", index);
   printf("\nEnter end time of your deadline (nums).\nYear: ");
   scanf("%d", year);
   printf("\nMonth: ");
   scanf("%d", mon);
   printf("\nDay: ");
   scanf("%d", day);
   printf("\nHour: ");
   scanf("%d", hour);
   printf("\nMinutes: ");
   scanf("%d", mins);

   // DEBUG
   printf("\n%d", index);
   printf("\n%d", year);
   printf("\n%d", mon);
   printf("\n%d", day);
   printf("\n%d", hour);
   printf("\n%d", mins);

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
   if (future_time == -1) {
      printf("Failed to convert future date.\n");
      return;
   }

   tasks[index] = future_time;
}

void conv_secs(int secs) {
   
   if (secs < 1) {
      printf("\nTime left: 0|0:0:0");
      return;
   }

   // Convert seconds to days
   const int SEC_DAY = 86400;
   const int SEC_HR = 3600;
   const int SEC_MIN = 60;

   int days;
   int hrs;
   int mins;

   printf("%d", secs);

   if (secs >= SEC_DAY)
      days = secs / SEC_DAY;
      secs -= days * SEC_DAY;
   
   if (secs >= SEC_HR)
      hrs = secs / SEC_HR;
      secs -= hrs * SEC_HR;
   
   if (secs >= SEC_MIN)
      mins = secs / SEC_MIN;
      secs -= mins * SEC_MIN;

   printf("\nTime left: %d|%d:%d:%d", days, hrs, mins, secs);

}