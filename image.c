// Omar Rojas And Eden
// CS 135
// Team Project 9

#include <stdio.h>
#define IMAGESIZE 512
#define NAMESIZE 50

int displayMenu(); // done
int displayEdits(); // done
int loadImage(int size, char fileName[], int temp[][size]);
void convertPixel();
void displayImage();
void cropImage();
void dimPic();
void brightenPic();
void saveImage();


int main(){
	int userin;
	int useredit;
	int isloaded;
	
	int userImage[IMAGESIZE][IMAGESIZE];
	char imageName[50];
	
	do{
		userin = displayMenu();
		switch(userin){
		case 0:
			return 0;
		break;
		case 1:
			isloaded = loadImage(IMAGESIZE, imageName, userImage);
		break;
		case 2:
			if(isloaded == 1){
			// display image call goes here
			printf("image display is boken T^T \n\n");
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

int loadImage(int size, char fileName[], int image[][size]){
	char Name[50];
	char temp[size][size];
	int rowInd, colInd;
	FILE* ptr;
	
	printf("Enter the file name [.txt format, no spaces]:\n");
	scanf("%s", Name);

	
	ptr = fopen(Name,"r");
	if(ptr == NULL){
		printf("Cant open file");
		return 0;
	}
	for(rowInd = 0; rowInd < size; rowInd++){
		for(colInd = 0; temp[rowInd][colInd] != '\n'; colInd++){
			while(fscanf(ptr, "%c", &temp[rowInd][colInd]) == 1){}
		}
	}
	printf("%c\n", temp[5][5]);
	
	fclose(ptr);
	int check = 1;
	
	return check;
	
	
}

void convertPixel(int col, int image[][col], char displayImage[][col]){
	
}


