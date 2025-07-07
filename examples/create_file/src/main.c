#include <stdio.h>
#include <stdlib.h>

/*
 * TODO: read a csv file, put them in struct entries
 * ways to read a file (cross platform stdlib)
 *  fgetc | character by character | simple
 *  fgets | line by line | safer handling of buffers
 *  fscanf | read formatted text | parsing structured input
 *  fread | raw binary or block reads | fast for big data
 *  mmap | memory mapping | efficient for huge files
 *  fseek/ftell + fread | full file loading | entire file into memory
 */

void create_csv_file()
{
    FILE* file1 = fopen("sample.csv", "w");
    if (file1 == NULL)
    {
        perror("File failed to open");
        return;
    }
    
    fprintf(file1, "id,name,message\n1,Gian Cedrick,I like milfs");
    fprintf(file1, "Gian Cedrick,I like milfs");
    if (fclose(file1)) // returns 0 on success
    {
        perror("Failed to close csv file.");
    }
}

void using_fgets()
{
    FILE *file = fopen("sample.csv","r");
    if (file == NULL)
    {
        perror("failed to open csv file.");
        return;
    }
    
    char buffer[1024]; 
    while(fgets(buffer, sizeof(buffer), file))
    {
        printf("%s", buffer);
    }

    if (fclose(file))
    {
        perror("Failed to close csv file.");
        return;
    }
}

int main(){
    create_csv_file();
    return EXIT_SUCCESS;
}
