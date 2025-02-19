/*simulating unix command cp*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
void main(int argc, char *argv[]){
    FILE *fp;
    char ch;
    int sc=0;
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return;
    }
    fp=fopen(argv[1],"r");
    if(fp==NULL){
        printf("Unable to open file %s",argv[1]);
    }
    else{
        while(!feof(fp)){
            ch=fgetc(fp);
            if(ch==' '){
                sc++;
            }
        }
        printf("No of spaces %d\n",sc);
        fclose(fp);
    }
}