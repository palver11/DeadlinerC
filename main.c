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

   char acquireddatatxt[6][6];
   int convertedtointdata[6][6];

// get data from a user
   printf("row: \n");
   scanf("%s", acquireddatatxt[0]);

   printf("year: \n");
   scanf("%d", convertedtointdata[1]);

   printf("month: \n");
   scanf("%d", convertedtointdata[2]);

   printf("day: \n");
   scanf("%d", convertedtointdata[3]);

   printf("hrs: \n");
   scanf("%d", convertedtointdata[4]);

   printf("min: \n");
   scanf("%d", convertedtointdata[5]);

// conver acquired data to int
   convertedtointdata[0][0] = convertmonth(acquireddatatxt[0]);
}

char convertmonth(char month[]) {
   int monthnum;

   if      (strcmp(month, "jan")) { monthnum = 1; }
   else if (strcmp(month, "feb")) { monthnum = 2; }
   else if (strcmp(month, "mar")) { monthnum = 3; }
   else if (strcmp(month, "apr")) { monthnum = 4; }
   else if (strcmp(month, "may")) { monthnum = 5; }
   else if (strcmp(month, "jun")) { monthnum = 6; }
   else if (strcmp(month, "jul")) { monthnum = 7; }
   else if (strcmp(month, "aug")) { monthnum = 8; }
   else if (strcmp(month, "sep")) { monthnum = 9; }
   else if (strcmp(month, "oct")) { monthnum = 10; }
   else if (strcmp(month, "nov")) { monthnum = 11; }
   else if (strcmp(month, "dec")) { monthnum = 12; }

   printf("%d\n", strcmp(monthnum, "jul"));
   return monthnum;
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