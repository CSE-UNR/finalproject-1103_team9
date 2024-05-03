// Omar Rojas And Eden
// CS 135
// Team Project 9

#include <stdio.h>
#define IMAGESIZE 512
#define NAMESIZE 50

int displayMenu(); // done
int displayEdits(); // done
void loadImage(char fileName[], FILE* ptr);
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
	
	int userImage[IMAGESIZE];
	char imageName[50];
	
	FILE *userfileptr;
	do{
		userin = displayMenu();
		switch(userin){
		case 0:
			return 0;
		break;
		case 1:
			// Load image call goes here
			loadImage(imageName,userfileptr);
			//printf("image loader is boken T^T, just pretend i did for now \n\n");
			isloaded = 1;
			fclose(userfileptr);
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

void loadImage(char fileName[], FILE* ptr){
	char Name[50];
	
	printf("give me the name of the file with .txt to load:\n");
	//fgets(Name,50,stdin);

	scanf("%s", Name);

	
	ptr = fopen(Name,"r");
	if(ptr == NULL){
		printf("Cant open file");
	}
	
	
}

void convertPixel(int col, int image[][col], char displayImage[][col]){
	
}


