#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h> /* puts, printf */
#include <time.h>  /* time_t, struct tm, time, localtime */
int main(int argc, char *argv[])
{

   
    FILE *fp;
    printf("het adres van de file is: %s\n", argv[1]); //dit is om te controleren dat de eerste parameter wel degelijk de file is
    int tijd = atoi(argv[2]); // de ingegeven parameter omvormen van een char naar een int n stoppen in de var int.
    printf("het aantal seconden wachten is: %d\n", tijd); // de gevraagde tijd die we willen wachten weergeven
    fp = fopen(argv[1], "w");

    while (1)
    {
        time_t rawtime;
        struct tm *timeinfo;

        time(&rawtime);
        timeinfo = localtime(&rawtime);
        printf("Current local time and date: %s", asctime(timeinfo));
        
        fprintf(fp, "%s", asctime(timeinfo));
        fputs(asctime(timeinfo), fp);
        sleep(tijd);
    }

    return 0;
}