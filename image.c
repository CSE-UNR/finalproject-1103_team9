// Omar Rojas And Eden
// CS 135
// Team Project 9

#include <stdio.h>
#define IMAGESIZE 500
#define NAMESIZE 50

int displayMenu(); // done
int displayEdits(); // done
int loadImage(int size, int image[][size], int* xrow, int* ycol); //done
char convertPixel(int pixel); //done
void displayImage(int size, int image[][size], int* xrow, int* ycol); //done
void cropImage();
void dimBrightenPic(int choice, int size, int *xrow, int *ycol, int image[][size]); //started
int saveImage(int size, int *xrow, int *ycol, int image[][size]); //started


int main(){
	int userin;
	int useredit;
	int isloaded;
	int xrow, ycol;
	
	int userImage[IMAGESIZE][IMAGESIZE];
	/* char imageName[50]; */
	
	do{
		userin = displayMenu();
		switch(userin){
		case 0:
			return 0;
		break;
		case 1:
			isloaded = loadImage(IMAGESIZE, userImage, &xrow, &ycol);
		break;
		case 2:
			if(isloaded == 1){
			// display image call goes here
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
					// Crop call goes here
					printf("image crop is boken T^T \n\n");
				break;
				case 2:
					dimBrightenPic(useredit, IMAGESIZE, &xrow, &ycol, userImage);
					//printf("image dim is ben T^T \n\n");
				break;
				case 3:
					dimBrightenPic(useredit, IMAGESIZE, &xrow, &ycol, userImage);
					printf("image brighten is boken T^T \n\n");
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
	printf("1: Crop image\n2: Dim image\n3: Brighten image\n0: Return to main menu\n\n");
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
// test print of char
	/* for(int i = 0; i <= rowInd; i++){
		for(int j = 0; j <= colInd; j++){
			printf("%c", temp[i][j]);
		}
	} */
// converting char to int	
	for (int i = 0; i < rowInd; i++) {
	        for (int j = 0; j < colInd; j++) {
	            image[i][j] = temp[i][j] - '0';
	        }
	}
	    
// test print of int array
	/* for(int i = 0; i < rowInd; i++){
		printf("\n");
		for(int j = 0; j < colInd; j++){
			printf("%d", image[i][j]);
		}
	} */
 	
	
	printf("\n\nImage successfully loaded\n\n");
	int check = 1;
	
	return check;
}
void displayImage(int size, int image[][size], int* xrow, int* ycol){
	// to see the size passes
	printf("\ncolumns: %d \nrows: %d \n", *ycol, *xrow);
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

void dimBrightenPic(int choice, int size, int *xrow, int *ycol, int image[][size]){
	int rowInd, colInd;
	int edit[size][size];
	displayImage(IMAGESIZE, image, xrow, ycol);
	if(choice == 2){
		for(rowInd = 0; rowInd < *xrow; rowInd++){
			colInd = 0;
			for(colInd = 0; colInd < *ycol; colInd++){
				if(image[rowInd][colInd] != 0){
					edit[rowInd][colInd] = image[rowInd][colInd] -1 ;
				}
			}
			
			printf("%d ", edit[rowInd][colInd]);
			printf("\n");
		}
	}
	else if(choice == 3){
		for(rowInd = 0; rowInd < *xrow; rowInd++){
			for(colInd = 0; colInd < *ycol; colInd++){
				if(image[rowInd][colInd] != 4){
					edit[rowInd][colInd] = image[rowInd][colInd] + 1;
				}
			}
			colInd = 0;
		}
	}
	displayImage(IMAGESIZE, edit, xrow, ycol);
	saveImage(IMAGESIZE, xrow, ycol, edit);
}

int saveImage(int size, int *xrow, int *ycol, int image[][size]){
	int rowInd, colInd;
	char choice;
	char Name[50];
	FILE* ptr;
	
	printf("Would you like to save your edited image to a file? [Y]es or [N]o: ");
	scanf(" %c", &choice);
	if(choice == 'N' || choice == 'n'){
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
		printf("\nImage Saved Successfully\n\n");
	}
	else{
		printf("Invalid choice\n");
	}
	return 0;	
}
