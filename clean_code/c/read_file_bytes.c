

FILE *fileptr;
char *buffer;
long filelen;

fileptr = fopen("myfile.txt", "rb");  // Open the file in binary mode
fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
filelen = ftell(fileptr);             // Get the current byte offset in the file
rewind(fileptr);                      // Jump back to the beginning of the file

buffer = (char *)malloc(filelen * sizeof(char)); // Enough memory for the file
fread(buffer, filelen, 1, fileptr); // Read in the entire file
fclose(fileptr); // Close the file
