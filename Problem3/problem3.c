#include<stdio.h>

#include<string.h>

#include<stdlib.h>

int myGrep(char *str, char *find);

void Usage(char *filename);

 

 

int main(int argc, char *argv[]) {

    int result, errno;

 

    if(argc < 3 ) {

        Usage(argv[0]);

        exit(1);

    }

 

     

    system("clear");

 

    result = myGrep(argv[1], argv[2]);

    if(result == -1) {

        perror("Error");
        printf("Error number = %d\n", errno);

        exit(1);

    }

    return(0);

}

 

void Usage(char *filename) {

    printf("Usage Error\n");

     

}

 

int myGrep(char *fname, char *str) {

    FILE *fp;

    int lno = 1;

    int result = 0;

    char temp[512];

     

     

    if((fp = fopen(fname, "r")) == NULL) {

        return(-1);

    }

 

     

 

    while(fgets(temp, 512, fp) != NULL) {

        if((strstr(temp, str)) != NULL) {

            printf("A match found on line: %d\n", lno);

            printf("\n%s\n", temp);

            result++;

        }

        lno++;

    }

 

    if(result == 0) {

        printf("\nSorry, couldn't find a match.\n");}



else

printf("\n%d\n", result);



     

     

    if (fp) {

        fclose(fp);

    }

}

