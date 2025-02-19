#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1024
void usage(){
    printf("Usage:\t./a.out filename word \n");
}
void main(int argc, char *argv[]){
    FILE *fp;
    char fline[max];
    char *newline;
    int c=0;
    int occr=0;
    if(argc!=3){
        usage();
        exit(1);
    }
    if(!(fp=fopen(argv[1],"r"))){
        printf("grep: couldnot open file : %s \n",argv[1]);
        exit(1);
    }
    while(fgets(fline,max,fp)!=NULL){
        c++;
        if((newline=strchr(fline,'\n'))!=NULL)
        *newline='\0';
        if(strstr(fline,argv[2])!=NULL){
            printf("%s: %d %s\n",argv[1],c,fline);
            occr++;
        }
    }
    if (occr==0)
        printf("No occurrences of the word '%s' found.\n", argv[2]);
    fclose(fp);
}