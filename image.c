// Omar Rojas And Eden
// CS 135
// Team Project 9

#include <stdio.h>
#define IMAGE_SIZE 512
#define NAME_SIZE 50

int displayMenu(); // done
int displayEdits(); // done
void loadImage(int row, int col, char fileName[]);
void convertPixel();
void displayImage();
void cropImage();
void dimPic();
void brightenPic();
void saveImage();
void saveImage();

int main(){
	int userin;
	int useredit;
	// to make sure they loaded an image first befo anything
	int isloaded = 0;
	do{
		userin = displayMenu();
		switch(userin){
		case 0:
			return 0;
		break;
		case 1:
			// Load image call goes here
			printf("image loader is boken T^T, just pretend i did for now \n\n");
			isloaded = 1;
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

void loadImage(int rows,int col, char fileName[]){
	//I TRIED AND I GIVE UP FOR NOW I CANT GET FGETS TO WORK ALL IT DOES IT GETS '\n\0'
	//FILE* fptr;
	//printf("What is the name of the image file? ");
	//fgets(Name, 50, stdin);
	//printf("%s",Name);
	//fptr = fopen(fileName,"w");
	//if(fptr == NULL){
	//	printf("Could not find an image with that filename.");
	//}
}

void convertPixel(int col, int image[][col], char displayImage[][col]){
	
}


