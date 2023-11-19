#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//Function for error-handling
void handleError(char *message) {
    perror(message); //Message after handling error
    exit(EXIT_FAILURE);
}
//Function for creating a file
void createFile(char *filename) {
    int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0666); //Using open() command to open the file 
    if(fd==-1) {
        handleError("Error! File could not be created.");
    }
    printf("File \"%s\" has been created successfully.\n",filename);

    close(fd); //Using close() command to close the file
}
//Function for reading a file
void readFile(char *filename) {
    int fd = open(filename, O_RDONLY);
    if(fd==-1){
        handleError("Error! File could not be accessed for reading");
    }
    char buffer[1024]; 
    ssize_t bytesRead;

    printf("Contents of \"%s\": \n",filename);
    while ((bytesRead = read(fd, buffer, sizeof(buffer)))>0) //Using read() command to read the content from the file
    {
        write(STDOUT_FILENO, buffer, bytesRead);
    }
    
    if(bytesRead==-1){
        handleError("File could not be read");
    }

    close(fd);
}
//Function to write to a file
void writeFile(char *filename, char *content){
    int fd = open(filename, O_WRONLY | O_TRUNC);
    if(fd==-1){
        handleError("Error! Could not open file for writing.");
    }
    ssize_t bytesWritten = write(fd, content, strlen(content)); //Using write() command to write to the file
    if(bytesWritten==-1){
        handleError("Could not write to file");
    }
    printf("Content has been written to \"%s\" successfully. \n",filename);
    close(fd);
}
//Function for appending to a file
void appendFile(char *filename, char *content){
    int fd = open(filename, O_WRONLY | O_APPEND);
    if(fd==-1){
        handleError("Error! File could not be opened for appending");
    }
    ssize_t bytesAppended = write(fd, content, strlen(content));
    if(bytesAppended==-1){
        handleError("Could not append to file");
    }
    printf("Content has been appended to \"%s\" successfully. \n",filename);
    close(fd);
}
//Function for deleting a file
void deleteFile(char *filename){
    if(unlink(filename)==-1){ //Using unlink() command to delete the file
        handleError("Could not delete file");
    }
    printf("File \"%s\" deleted successfully. \n",filename);
}
int main() {
    char filename[256];
    char content[1024];
    char appendContent[1024];

    printf("Enter the name of the file: ");
    scanf("%255s",filename); 

    printf("Enter the content: ");
    scanf(" %[^\n]",content);

    printf("Enter additional content to append: ");
    scanf(" %[^\n]",appendContent);

    createFile(filename);
    writeFile(filename, content);
    appendFile(filename, appendContent);
    readFile(filename);
    deleteFile(filename);

    return 0;
}

