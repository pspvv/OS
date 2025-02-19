#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(int argc, char *argv[]){
    char buff[100];
    DIR *dirp;
    struct dirent *dptr;
    printf("\nENTER DIRECTORY NAME : ");
    scanf("%s",buff);
    if((dirp=opendir(buff))==NULL){
        printf("The given directory does not exist");
        exit(1);
    }
    printf("Contents of directory %s:\n", buff);
    while(dptr=readdir(dirp)){
        printf("%s\n",dptr->d_name);
    }
    closedir(dirp);
}