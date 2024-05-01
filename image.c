// Omar Rojas And Eden
// CS 135
// Team Project 9

#include <stdio.h>
#define IMAGE_SIZE 512

int displayMenu(int userinput);
void loadImage(int col, char fileName[], int image[][col]);
void convertPixel();
void displayImage();
void cropImage();
void dimPic();
void brightenPic();
void saveImage()

int main(){
	
	

}

int displayMenu(userinput){
	int input;
	printf("---PHOTOSHOP---\n")
	printf("1 - Load Image\n2 - Display Image\n3 - Edit Image")
	scanf("%d", &input);
	if(input == 3){
		printf("4 - Crop Image\n5 - Dim Image\n6 - Brighten Image");
		scanf("%d", &input);
	}
	return input;
	
}

void loadImage(int col, char fileName[], int image[][col]){
	
}

void convertPixel(int col, int image[][col], char displayImage[][col]){
	
}


