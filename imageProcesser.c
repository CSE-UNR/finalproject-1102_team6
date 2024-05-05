#include <stdio.h>

void dimImage(int col, int row, int arr[][col]);
void brightImage(int col, int row, int arr[][col]);
void cropImage(int col, int row, int arr[][col]);
void loadImage(int col, int row, int arr[][col], int *newRow, int *newColumn);
void displayImage(int col, int row, int arr[][col]);
void saveImage(int col, int row, int arr[][col]);

int main(){
  
 char cmd, cmd2;
 
 //int rows;
 //int cols;
 //int img[100][100];
 /*
do{	
	printf("**ERINSTAGRAM**\n");
 	printf("1: Load image\n");
 	printf("2: Display image\n");
 	printf("3: Edit image\n");
 	printf("0: Exit\n");
 	scanf(" %c", cmd);
 
 
 
 switch (cmd){
  case 1: '1'
	loadImage(100, 100, img[][100], &rows, &cols);
  break;
  
  case 2: '2'
   	displayImage(cols, rows, img[][cols]);
  break;
  
  case 3: '3'
  	if(img[0][0]=='\0'){
  		printf("Sorry, no image to edit\n");
  	}else{
  		printf("\n\n**EDITING**\n");
  		printf("1: Crop image\n");
		printf("2: Dim image\n");
		printf("3: Brighten image\n");
		printf("0: Return to main menu"\n\n");
		printf("Choose from one of the options above: ");
		scanf(" %c", cmd2);
		
		switch (cmd2){
		  case 1: '1'
		  	cropImage(cols, rows, img[][cols]);
		  break;
		  
		  case 2: '2'
		  	brightImage(cols, rows, img[][cols]);
		  break;
		  
		  case 3
		  	dimImage(cols, rows, img[][cols]);
		  break;
		  
		  default:
		  break;
	}
		
  break;
  
  case 0:
   
  break;
  
  default:
	printf("Invalid option, please try again.\n");
  break;
    
 }
 
 
 }while(cmd != '0');
 
 printf("\nGoodbye!");
 
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


*/

//-----------------------------------------------------------------
void loadImage(int col, int row, int arr[][col], int *newRow, int *newCol){
 char name[50];
 *newRows=0;
 *newCol=0;
 
 printf("What is the name of the image file?");
 fgets(name, 49, stdin);
 
 for(int nameIndex=0; name[nameIndex]!='\0' ; nameIndex++){
 		if(name[nameIndex]=='\n'){
 			name[nameIndex]='\0';
 
 FILE* file = fopen(name, "r");
 
 if(file == NULL){
  	printf("file does not exist ");
 }else{ 
 	while(fscanf(file, "%d", &img[newRow][newCol])==1){
 		newRow++;
  	//find way to get #of rows and #of cols 
  	// loop through file values and assign to array
	}
  fclose(name);
 }

 printf("\nImage successfully loaded!\n\n");

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
	while(newLeft<1 && newleft>=col){
		printf("Invalid column value. Choose a value between 1 and %d ", col-1);
		scanf("%d", &newLeft);
	}

	printf("\nWhich column do you want to be the new right side? ");
	scanf("%d", &newRight);
	while(newRight<=newLeft && newRight>=col){
		printf("Invalid column value. Choose a value between %d and %d ",newLeft, col-1);
		scanf("%d", &newLeft);
	}
	
	printf("\nWhich row do you want to be the new top? ");
	scanf("%d", &newTop);
	while(newTop<1 && newTop>=row){
		printf("Invalid row value. Choose a value between 1 and %d", row-1);
		scanf("%d", &newTop);
	}

	printf("\nWhich row do you want to be the new bottom? ");
	scanf("%d", &newBottom);
	while(newBottom<=newTop && newBottom>=row){
		printf("Invalid row value. Choose a value between %d and %d ",newTop, row-1);
		scanf("%d", &newBottom);
	}
	
	int crpImg[newRight][newBottom]
	
	for(int r=0;r<newBottom;r++){
		for(int c=0;c<newRight;c++){
			newImage[r][c]= arr[newLeft-1][newTop-1];
		}
	}
	
	displayImage(newRight,newBottom,cropImg[][newBottom]);
	
	saveImage(newRight,newBottom,cropImg[][newBottom]);
	
	return 0;
}

//---------------------------------------------------------
 
 void saveImage(int col, int row, int arr[][col]){
 
 	char option;
 	char nameSave[50]
 	
 	printf("Would you like to save? (y/n) ");
 	scanf(" &c", &option);
 	
 	if(option='y'){
 		printf("\nWhat do you want to name the image file? (include the extension) "
 		fgets(nameSave, 49, stdin);
 		
 		for(int nameIndex=0; name[nameIndex]!='\0' ; nameIndex++){
 			if(name[nameIndex]=='\n'){
 				name[nameIndex]='\0';
 			}
 		}
 			
 		FILE* file = fopen(nameSave, "w");
 		
 		for(int c=0; c<col ; c++){
 			for(int r=0; r<row ; r++){
 				fprintf(name,"%d", arr[r][c]);
 				if(r<row-1){
 					fprintf(name, " ");
 				}
 			}
 		}
 		fclose(name);
 		printf("\nImage successfully saved!\n");		
 	}
 
 }
 
 
 
 
 
 
 
 
 
 
 
