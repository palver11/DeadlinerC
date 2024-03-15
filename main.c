/* notes:
probably there is a way to get the date in numerical format, so i wouldn't have to convert "mar" to 3
but i think i'll keep it this way. for the additional practice(to write more code) or just because i'm lazy, idk.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


void setdeadline(int deadlines[][6]);
char convertmonth(char month[]);

int main() {
   time_t t; 
   int elements = 15;

// year | month | day | hours | minutes
   int deadlines[elements][6]; 

   time(&t); 
   // struct tm tm = *localtime(&t);
   
   setdeadline(deadlines);


   getchar();

}


void setdeadline(int deadlines[][6]) {
   printf(
      "input the row and date: \n"
      "date e.g. 2024, mar, 9, 15, 0 \n"
   );

   char monthStr[4];
   int row;
   int convertedToIntData[5];

// get data from a user
   printf("row: \n");
   scanf("%d", &row);

   printf("year: \n");
   scanf("%d", &convertedToIntData[0]);

   printf("month: \n");
   scanf("%s", monthStr);

   printf("day: \n");
   scanf("%d", &convertedToIntData[2]);

   printf("hrs: \n");
   scanf("%d", &convertedToIntData[3]);

   printf("min: \n");
   scanf("%d", &convertedToIntData[4]);

// conver month to int
   convertedToIntData[1] = convertmonth(monthStr);

   for ( int i = 0; i < 6; i++) {
      deadlines[row][i] = convertedToIntData[i];
      // printf("row: %d\n", deadlines[row][i]);
      printf("length: %zu\n", 6);
   }
}

char convertmonth(char month[]) {
   int monthNum = -1;

   if      (!strcmp(month, "jan")) { monthNum = 1; }
   else if (!strcmp(month, "feb")) { monthNum = 2; }
   else if (!strcmp(month, "mar")) { monthNum = 3; }
   else if (!strcmp(month, "apr")) { monthNum = 4; }
   else if (!strcmp(month, "may")) { monthNum = 5; }
   else if (!strcmp(month, "jun")) { monthNum = 6; }
   else if (!strcmp(month, "jul")) { monthNum = 7; }
   else if (!strcmp(month, "aug")) { monthNum = 8; }
   else if (!strcmp(month, "sep")) { monthNum = 9; }
   else if (!strcmp(month, "oct")) { monthNum = 10; }
   else if (!strcmp(month, "nov")) { monthNum = 11; }
   else if (!strcmp(month, "dec")) { monthNum = 12; }

   printf("Month Num: %d\n", monthNum);
   return monthNum;
}



/* code reference
//sat mar  9 09:00:24 2024

fopen("e:\\cprogram\\newprogram.txt","w");
fopen("e:\\cprogram\\oldprogram.bin","r");
fclose(fptr);

int main()
{
   int num;
   file *fptr;

   fptr = fopen("c:\\program.txt","w");

   if(fptr == null)
   {
      printf("error!");   
      exit(1);             
   }

   printf("enter num: ");
   scanf("%d",&num);

   fprintf(fptr,"%d",num);
   fclose(fptr);
}

*/