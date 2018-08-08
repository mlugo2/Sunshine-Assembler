#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
void usage();

int main(int argc, const char *argv[]) {

	printf("Hello, world!\n");

	FILE *fp;		// file pointer
	char *source;
	long last;

	// Make sure source is passed in.
	if (argc < 2) 
		usage();

	fp = fopen(argv[1], "r");

	// Check for file authenticity
	if (fp == NULL) {
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0L, SEEK_END);	/* go to end of file */
	last = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	source = (char*) malloc(last * sizeof(char));

	fread(source, sizeof(char), last, fp);

	printf("\n%s", source);

	fclose(fp);

	return 0;
}

void usage() {

	printf("Error! Needs source file.\n");
	exit(EXIT_FAILURE);
}
