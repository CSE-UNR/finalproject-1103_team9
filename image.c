// Omar Rojas And Eden
// CS 135
// Team Project 9

#include <stdio.h>
#define IMAGESIZE 500
#define NAMESIZE 50

int displayMenu(); // done
int displayEdits(); // done
int loadImage(int size, char fileName[], int image[][size], int* xrow, int* ycol);
char convertPixel(int pixel);
void displayImage(int size, int image[][size], int* xrow, int* ycol);
void cropImage();
void dimPic();
void brightenPic();
void saveImage();


int main(){
	int userin;
	int useredit;
	int isloaded;
	int xrow, ycol;
	
	int userImage[IMAGESIZE][IMAGESIZE];
	char imageName[50];
	
	do{
		userin = displayMenu();
		switch(userin){
		case 0:
			return 0;
		break;
		case 1:
			isloaded = loadImage(IMAGESIZE, imageName, userImage, &xrow, &ycol);
		break;
		case 2:
			if(isloaded == 1){
			// display image call goes here
			displayImage(IMAGESIZE, userImage, &xrow, &ycol);
			}else{
				printf("Sorry, no image to display\n\n");
			}
		break;
		case 3:
			if(isloaded == 1){
			useredit = displayEdits();
				switch(useredit){
				case 1:
					// Crop call goes here
					printf("image crop is boken T^T \n\n");
				break;
				case 2:
					//Dim call goes here
					printf("image dim is boken T^T \n\n");
				break;
				case 3:
					//Brighten call goes here
					printf("image brighten is boken T^T \n\n");
				case 0:
					printf("\n\n");
				break;
				default:
					printf("Invalid option, please try again\n\n");
				} 
			
			}else{
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
	printf("1: Crop image\n2: Dim image\n3: Brighten image\n0: Return to main menu\n\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &input);
	return input;
}

int loadImage(int size, char fileName[], int image[][size], int* xrow, int* ycol){
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
// Gets the size of array (col for some reason is off by one)
	char getsize[size][size];
 	char temp[size][size];
	colInd=0;
	for(rowInd = 0; rowInd < size && fscanf(ptr, "%c", &getsize[rowInd][colInd]) == 1; rowInd++){
		printf("\nrow ");
		colInd = 0;
		while(fscanf(ptr, "%c", &getsize[rowInd][colInd]) == 1 && getsize[rowInd][colInd] != '\n' && colInd < size){
			printf("col ");
			colInd++;
		}
	}
// resets the scans
	fclose(ptr);
	ptr = fopen(Name, "r");
// asigns the size of array
	int numCol = colInd + 1;
	int numRow = rowInd;
	*xrow = numRow;
	*ycol = numCol;
	printf("\ncolums: %d \nrows: %d \n", numCol, numRow);
// gets the array in char using the sizes 
	for(int i = 0; i <= numRow; i++){
		for(int j = 0; j <= numCol; j++){
			fscanf(ptr,"%c", &temp[i][j]);
			if(temp[i][j] == '\n'){
				fscanf(ptr, "\n");
			}
		}
	}

// test print of char
	for(int i = 0; i <= numRow; i++){
		for(int j = 0; j <= numCol; j++){
			printf("%c", temp[i][j]);
		}
	}
// converts char array into ints
	for (int i = 0; i < numRow; i++) {
	        for (int j = 0; j < numCol; j++) {
	            image[i][j] = temp[i][j] - '0';
	        }
	    }
	    
// test print of int array
	for(int i = 0; i < numRow; i++){
		printf("\n");
		for(int j = 0; j < numCol; j++){
			printf("%d", image[i][j]);
		}
	}
 	
	
	printf("\n\nImage successfullay loaded\n\n");
	fclose(ptr);
	int check = 1;
	
	return check;
	
	
}
void displayImage(int size, int image[][size], int* xrow, int* ycol){
	// to see the size passes
	printf("\ncolums: %d \nrows: %d \n", *ycol, *xrow);
	//to print
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




