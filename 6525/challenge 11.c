#include <stdio.h>

int main()
{
    FILE *file;
    char text[200];

    // Writing to a file
    file = fopen("data.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return 1;
    }
    printf("Enter text to write to file: ");
    scanf(" %[^\n]", text); // Read a line including spaces
    fprintf(file, "%s\n", text);
    fclose(file);

    // Reading from the file
    file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return 1;
    }
    printf("\nContents of file:\n");
    while (fscanf(file, " %[^\n]", text) != EOF)
    {
        printf("%s\n", text);
    }
    fclose(file);

    // Appending new text
    file = fopen("data.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file for appending.\n");
        return 1;
    }
    printf("\nEnter text to append: ");
    scanf(" %[^\n]", text);
    fprintf(file, "%s\n", text);
    fclose(file);

    printf("\nUpdated file content:\n");
    file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return 1;
    }
    while (fscanf(file, " %[^\n]", text) != EOF)
    {
        printf("%s\n", text);
    }
    fclose(file);

    return 0;
}
