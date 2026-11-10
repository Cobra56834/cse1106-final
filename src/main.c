#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#define PIN 17
#define THRESHOLD 80
int x,y;
int main(int argc, char **argv)
{
    gpioInitialise();
    gpioSetMode(PIN,PI_OUTPUT);
    FILE *fptr;
    const char *filename = "status.txt";
    char *text;
    printf("Enter System Memory Usage: ");
    scanf("%d", &x);
    printf("Enter System Storage Usage: ");
    scanf("%d", &y);
    if(x > THRESHOLD || y > THRESHOLD){
        gpioWrite(PIN,1);
        text="Warning";
    }
    else {
    gpioWrite(PIN,0);
        text="Normal";
    }
    fptr = fopen(filename, "w");
    fprintf(fptr, "%s", text);
    fclose(fptr);
    gpioTerminate();
    return 0;
}
