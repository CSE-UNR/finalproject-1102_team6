#include <stdio.h>

void dimImage();
void brightImage();
void cropImage();
void loadImage();
void displayImage();
void saveImage();

int main(){
  
 char cmd;
 
 //int rows;
 //int cols;
 //int img[rows][cols];
 /*
 printf("**ERINSTAGRAM**\n");
 printf("1: Load image\n");
 printf("2: Display image\n");
 printf("3: Edit image\n");
 printf("0: Exit\n");
 scanf("%c", cmd);
 
 switch (cmd){
  case 1:
  
  break;
  
  case 2:
   displayImage(cols, rows, img[][cols] );
  break;
  
  case 3:
  
  break;
  
  case 0:
   
  break;
    
 }
  */
//  displayImage(cols, rows, img[][cols] );
  return 0 ;
}


void displayImage(int col, int row, int arr[][col] ){
 
 for(int r = 0; r < row; r++){
  for(int c = 0; c < col; c++){
   switch(arr[r][c]){
    case 0:
     printf(" ");
     break;  
    case 1:
     printf(".");
     break;
    case 2:
     printf("o");
     break;
    case 3: 
     printf("O");
     break;
    case 4:
    printf("0"); 
 
    }

   }
   printf("\n");
  }
}

//-----------------------------------------------------------------
void loadImage(/*pass in array rows cols and img[][] to change */){
 char name[50];
 int rows;
 int cols;
 
 printf("What is the name of the image file?");
 fgets(name, 30, stdin);
 FILE* file = fopen(name, "r");
 
 if(file == NULL){
  printf("file does not exist ");
 }else{
  //find way to get #of rows and #of cols 
  // loop through file values and assign to array

  
 }

 }
 
//---------------------------------------------------------- 
 void dimImage(int col, int row, int arr[][col]){

  for(int r = 0; r < row; r++){
   for(int c = 0; c < col; c++){
    if(arr[r][c] > 0){
     arr[r][c]--;
    }
    
    
     }
    }
 }
 //---------------------------------------------------------
 
 void brightImage(int col, int row, int arr[][col]){
   for(int r = 0; r < row; r++){
    for(int c = 0; c < col; c++){
     if(arr[r][c] < 4){
      arr[r][c]++;      
     }
  
      }
    }
 
 
 }
 
//---------------------------------------------------------

void cropImage(int col, int row, int arr[][col]){

	int newLeft, newRight, newTop, newBottom;
	
	printf("The image you want to crop is %d x %d.", col, row);
	printf("\nThe row and column values start in the upper lefthand corner.\n");
	
	printf("Which column do you want to be the new left side? ");
	scanf("%d", &newLeft);
	while(newLeft<1 && newleft>col){
		printf("Invalid column value. Choose a value between 1 and %d ", col);
		scanf("%d", &newLeft);
	}

	printf("\nWhich column do you want to be the new right side? ");
	scanf("%d", &newRight);
	while(newRight<=newLeft && newRight>col){
		printf("Invalid column value. Choose a value between %d and %d ",newLeft, col);
		scanf("%d", &newLeft);
	}
	
	printf("\nWhich row do you want to be the new top? ");
	scanf("%d", &newTop);
	while(newTop<1 && newTop>row){
		printf("Invalid row value. Choose a value between 1 and %d", row);
		scanf("%d", &newTop);
	}

	printf("\nWhich row do you want to be the new bottom? ");
	scanf("%d", &newBottom);
	while(newBottom<=newTop && newBottom>row){
		printf("Invalid row value. Choose a value between %d and %d ",newTop, row);
		scanf("%d", &newBottom);
	}
	
	int crpImg[newRight][newBottom]
	
	for(int r=0;r<newBottom;r++){
		for(int c=0;c<newRight;c++){
			newImage[r][c]= arr[newLeft-1][newTop-1];
		}
	}
	
	displayImage(newRight,newBottom,cropImg[][newBottom];
	return 0;
}

//---------------------------------------------------------
 
 void saveImage(int col, int row, int arr[][col]){
 
 	char option;
 	char nameSave[30]
 	
 	printf("Would you like to save? (y/n) ");
 	scanf(" &c", &option);
 	
 	if(option='y'){
 		printf("\nWhat do you want to name the image file? (include the extension) "
 		fgets(nameSave, 30, stdin);
 		FILE* file = fopen(nameSave, "w");
 		
 	}
 
 }
 
 
 
 
 
 
 
 
 
 
 
