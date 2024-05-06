// Omar Rojas And Eden
// CS 135
// Team Project 11

#include <stdio.h>
#define IMAGESIZE 500
#define NAMESIZE 50

int displayMenu(); // done
int displayEdits(); // done
int loadImage(int size, int image[][size], int* xrow, int* ycol); //done
char convertPixel(int pixel); //done
void displayImage(int size, int image[][size], int* xrow, int* ycol); //done
void cropImage(int size, int image[][size], int* xrow, int* ycol); //done
void dimBrightenPic(int choice, int size, int* xrow, int* ycol, int image[][size]); //done
void rotateImage(int size, int image[][size], int* xrow, int* ycol);
int saveImage(int size, int* xrow, int* ycol, int image[][size]); //done


int main(){
	int userin;
	int useredit;
	int isloaded;
	int xrow, ycol;
	int userImage[IMAGESIZE][IMAGESIZE];
	
	do{
		userin = displayMenu();
		switch(userin){
		case 0:
			printf("Goodbye!\n");
		break;
		case 1:
			isloaded = loadImage(IMAGESIZE, userImage, &xrow, &ycol);
		break;
		case 2:
			if(isloaded == 1){
			displayImage(IMAGESIZE, userImage, &xrow, &ycol);
			}
			else{
				printf("Sorry, no image to display\n\n");
			}
		break;
		case 3:
			if(isloaded == 1){
			useredit = displayEdits();
				switch(useredit){
				case 1:
					cropImage(IMAGESIZE, userImage, &xrow, &ycol);
				break;
				case 2:
					dimBrightenPic(useredit, IMAGESIZE, &xrow, &ycol, userImage);
				break;
				case 3:
					dimBrightenPic(useredit, IMAGESIZE, &xrow, &ycol, userImage);
				break;
				case 4:
					rotateImage(IMAGESIZE, userImage, &xrow, &ycol);
				break;
				case 0:
					printf("\n\n");
				break;
				default:
					printf("Invalid option, please try again\n\n");
				} 
			
			}
			else{
				printf("Sorry, no image to edit\n\n");
			}
		break;
		default:
			printf("Invalid option, please try again\n\n");
		}
	}while(userin != 0);
	return 0;
}

int displayMenu(){
	int input;
	printf("---PHOTOSHOP---\n");
	printf("1: Load image\n2: Display image\n3: Edit image\n0: Exit\n\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &input);
	return input;
	
}

int displayEdits(){
	int input;
	printf("\n\n---EDITING---\n");
	printf("1: Crop image\n2: Dim image\n3: Brighten image\n4: Rotate image\n0: Return to main menu\n\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &input);
	return input;
}

int loadImage(int size, int image[][size], int* xrow, int* ycol){
	char Name[50];
	int rowInd = 0, colInd = 0;
	FILE* ptr;
	
	printf("Enter the file name [.txt format, no spaces]:\n");
	scanf("%s", Name);

	
	ptr = fopen(Name,"r");
	if(ptr == NULL){
		printf("Cant open file");
		return 0;
	}
	
 	char temp[size][size];
 	
	
	for(rowInd = 0; rowInd < size && fscanf(ptr, "%c", &temp[rowInd][colInd]) == 1; rowInd++){
		colInd = 1;
		while(fscanf(ptr, "%c", &temp[rowInd][colInd]) == 1 && temp[rowInd][colInd] != '\n' && colInd < size){
			colInd++;
		}
		colInd = 0;
	}
	while(temp[0][colInd] < size && temp[0][colInd] != '\n'){
		colInd++;
	}

	*xrow = rowInd;
	*ycol = colInd;
	
	for (int i = 0; i < rowInd; i++) {
	        for (int j = 0; j < colInd; j++) {
	            image[i][j] = temp[i][j] - '0';
	        }
	}
	
	printf("\n---Image Loaded Successfully---\n\n");
	int check = 1;
	
	return check;
}
void displayImage(int size, int image[][size], int* xrow, int* ycol){
	for(int i = 0; i < *xrow; i++){
		printf("\n");
		for(int j = 0; j < *ycol; j++){
			printf("%c", convertPixel(image[i][j]));
		}
	}
	printf("\n\n");
	
}

char convertPixel(int pixel){
	switch(pixel){
		case 0:
			return ' ';
			break;
		case 1:
			return '.';
			break;
		case 2:
			return 'o';
			break;
		case 3:
			return 'O';
			break;
		case 4:
			return '0';
			break;
		}
}

void cropImage(int size, int image[][size], int* xrow, int* ycol){
	int rowInd, colInd;
	int edit[size][size];
	int row1, col1, row2, col2;
	
	printf("      1");
	for(colInd = 1; colInd <= *ycol; colInd++){
		if(colInd != *ycol){
			printf(" ");
		}
		else{
			printf("%d", colInd);
		}
	}
	for(rowInd = 0; rowInd < *xrow; rowInd++){
		printf("\n");
		printf("%4.1d  ", rowInd + 1);
		for(colInd = 0; colInd < *ycol; colInd++){
			printf("%c", convertPixel(image[rowInd][colInd]));
		}
	}
	
	printf("\nEnter the corners of the edited image\n");
	printf("Upper left corner [row]: ");
	scanf("%d", &row1);
	printf("Upper left corner [column]: ");
	scanf("%d", &col1);
	printf("\nLower right corner [row]: ");
	scanf("%d", &row2);
	printf("Lower right corner [column]: ");
	scanf("%d", &col2);
	
	int cropRows = *xrow - row1 - (*xrow - row2) + 1;
	int cropCols = *ycol - col1 - (*ycol - col2) + 1;
	
	for(rowInd = 0; rowInd < cropRows; rowInd++){
		for(colInd = 0; colInd < cropCols; colInd++){
			edit[rowInd][colInd] = image[rowInd + row1 - 1][colInd + col1 - 1];
		}
	}
	displayImage(size, edit, &cropRows, &cropCols);
	saveImage(size, &cropRows, &cropCols, edit);
	
}

void dimBrightenPic(int choice, int size, int* xrow, int* ycol, int image[][size]){
	int rowInd, colInd;
	int edit[size][size];
	if(choice == 2){
		for(rowInd = 0; rowInd < *xrow; rowInd++){
			for(colInd = 0; colInd < *ycol; colInd++){
				if(image[rowInd][colInd] != 0){
					edit[rowInd][colInd] = image[rowInd][colInd] - 1;
				}
				else if(image[rowInd][colInd] == 0){
					edit[rowInd][colInd] = image[rowInd][colInd];
				}
			}
		}
	}
	else if(choice == 3){
		for(rowInd = 0; rowInd < *xrow; rowInd++){
			for(colInd = 0; colInd < *ycol; colInd++){
				if(image[rowInd][colInd] != 4){
					edit[rowInd][colInd] = image[rowInd][colInd] + 1;
				}
				else if(image[rowInd][colInd] == 4){
					edit[rowInd][colInd] = image[rowInd][colInd];
				}
			}
		}
	}
	displayImage(size, edit, xrow, ycol);
	saveImage(size, xrow, ycol, edit);
}

void rotateImage(int size, int image[][size], int* xrow, int* ycol){
	int rowInd, colInd;
	int choice;
	int edit[size][size];
	int rotateRows = *ycol;
	int rotateCols = *xrow;
	
	printf("\n1: Rotate right\n2: Rotate left\n\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &choice);
	
	if(choice == 1){
		for(rowInd = 0; rowInd <= rotateRows; rowInd++){
			for(colInd = 0; colInd <= rotateCols; colInd++){
				edit[rowInd][colInd - 1] = image[rotateCols - colInd][rowInd];
			}
		}
		displayImage(size, edit, &rotateRows, &rotateCols);
		printf("Image rotated 90 degrees to the right.\n\n");
	}
	else if(choice == 2){
		for(rowInd = 0; rowInd <= rotateRows; rowInd++){
			for(colInd = 0; colInd <= rotateCols; colInd++){
				edit[rowInd -1][colInd] = image[colInd][rotateRows - rowInd];
			}
		}
		displayImage(size, edit, &rotateRows, &rotateCols);
		printf("Image rotated 90 degrees to the left.\n\n");
	}
	saveImage(size, &rotateRows, &rotateCols, edit);

}

int saveImage(int size, int* xrow, int* ycol, int image[][size]){
	int rowInd, colInd;
	char choice;
	char Name[50];
	FILE* ptr;
	
	printf("Would you like to save your edited image to a file? [Y]es or [N]o: ");
	scanf(" %c", &choice);
	if(choice == 'N' || choice == 'n'){
		printf("\n\n");
		return 0;
	}
	else if(choice == 'Y' || choice == 'y'){
		printf("Enter the file name [.txt format, no spaces]:\n");
		scanf("%s", Name);
		ptr = fopen(Name,"w");
		if(ptr == NULL){
			printf("Cant open file");
			return 0;
		}
		for(rowInd = 0; rowInd < *xrow; rowInd++){
			for(colInd = 0; colInd < *ycol; colInd++){
				fprintf(ptr, "%d", image[rowInd][colInd]);
			}
			fprintf(ptr, "\n");
		}
		printf("\n---Image Saved Successfully---\nExit program to use edited image or edit original image again.\n\n");
	}
	else{
		printf("Invalid choice\n");
	}
	return 0;	
}
