/* notes:
probably there is a way to get the date in numerical format, so i wouldn't have to convert "mar" to 3
but i think i'll keep it this way. for the additional practice(to write more code) or just because i'm lazy, idk.






*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>



int setdeadline(int deadlines[][5]);
char convertmonth(char month[]);

int main() {
   time_t t; 
   int elements = 15;

// row | year | month | day | hours | minutes
   int deadlines[elements][5]; 

   time(&t); 
   // struct tm tm = *localtime(&t);
   
   setdeadline(deadlines);
   // for (int i = 0; i < elements; i++) {
   //    printf("%d", ctime(&t));

   // }


   getchar();

}


int setdeadline(int deadlines[][5]) {
   printf(
      "input the row and date: \n"
      "date e.g. 2024, mar, 9, 15, 0 \n"
   );

   char monthStr[6];
   int convertedToIntData[6];

// get data from a user
   printf("row: \n");
   scanf("%d", convertedToIntData[0]);

   printf("year: \n");
   scanf("%d", convertedToIntData[1]);

   printf("month: \n");
   // scanf("%s", &monthStr);

   printf("day: \n");
   scanf("%d", convertedToIntData[2]);

   printf("hrs: \n");
   scanf("%d", convertedToIntData[3]);

   printf("min: \n");
   scanf("%d", convertedToIntData[4]);

// conver acquired data to int
   printf("%s\n", monthStr);
   // convertedToIntData[2] = convertmonth(monthStr);
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

   printf("%s\n", month);
   printf("%d\n", strcmp(month, "jul"));
   printf("Month Num: %d", monthNum);
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