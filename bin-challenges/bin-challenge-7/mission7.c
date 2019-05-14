#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* XMALLOC(size_t size) {
    void* ptr = malloc(size);
    fprintf(stderr, "[DEBUG] Allocated %d@%x\n", size, ptr);
    return ptr;
}

#ifdef DEBUG
    #define malloc XMALLOC
#endif

char* g_fmt  = NULL;
char* g_tz   = NULL;
int   g_time = 0;

void set_format() {
    char tmp[896];
    char whitelist[51];
    memcpy(whitelist, "%aAbBcCdDeFgGhHIjklmMnNpPrRsStTuUVwWxXyYzZ:-_/0^# \0", 51);

    fprintf(stdout, "Time format: ");
    fgets(tmp, 896, stdin);
    tmp[strcspn(tmp, "\n")] = '\0';

    if( g_fmt != NULL ) {
       free(g_fmt);
    }

    if (strspn(tmp, whitelist) == strlen(tmp)) {
      g_fmt = malloc(strlen(tmp) + 1);
      if( g_fmt != NULL ) {
        strcpy(g_fmt, tmp);
      }
    }

}

void set_time() {
    int time;
    char buf[128];
    fprintf(stdout, "Enter a Unix time : ");
    fgets(buf, 16, stdin);
    time = atoi(buf);
    if (time <= 0) {
      fprintf(stderr, "Time must be positive\n");
    } else {
      g_time = time;
    }  
}

void set_time_zone() {
    char tmp[896];
    fprintf(stdout, "Time zone: ");
    fgets(tmp, 896, stdin);
    tmp[strcspn(tmp, "\n")] = 0;
    if ( g_tz != NULL ) {
        free(g_tz);
    }

    g_tz = malloc(strlen(tmp) + 1);
    if (g_tz != NULL) {
        strcpy(g_tz, tmp);
    }
}

void print_time() {
   char command[2048];
   if(g_tz == NULL || g_time == 0 || g_fmt == NULL) {
      free(g_tz);
      free(g_fmt);
      g_tz = g_fmt = NULL;
      g_time = 0;
   } else {
      snprintf(command, 2048, "/bin/date -d @%d +'%s'", g_time, g_fmt);
      setenv("TZ", g_tz, 1);
      printf("\nHere's your time:");
      system(command);
      printf("\n");
   }
}

int main(int argc, char** argv) {

    int option = 0;
    char buf[16];

    setbuf(stdin, 0);
    setbuf(stdout, 0);
    setbuf(stderr, 0);

    fprintf(stdout, "Welcome to NECSTime! Ever wondered how to easily format a time?\n");

    for(;;) {
        fprintf(stdout, "1) Set a time format\n");
        fprintf(stdout, "2) Set time\n");
        fprintf(stdout, "3) Set time zone\n");
        fprintf(stdout, "4) Print your time\n");
        fprintf(stdout, "5) Exit\n");
        
        fgets(buf, 16, stdin);
        option = atoi(buf);

        switch(option) {
            case 1:
                set_format();
                break;
            case 2:
                set_time();
                break;
            case 3:
                set_time_zone();
                break;
            case 4:
                print_time();
                break;
            default:
                exit(0);
        }
    }

    return 0;

}