//Authors: Noah Jacobsen and Diego Lopez
//Name: Image Processor
//Purpose: Allows user to insert image that they could edit

#include <stdio.h>

void dimImage(int row, int col, int arr[][100]);
void brightImage(int row, int col, int arr[][100]);
void cropImage(int row, int col, int arr[][100]);
void loadImage(int col, int row, int arr[][100], int *newRow, int *newCol);
void displayImage(int row, int col, int arr[][100]);
void saveImage(int row, int col, int arr[][100]);

int main(){
  
char cmd, cmd2;
 
 int rows;
 int cols;
 int img[100][100];
 
 printf("\n");
 
do{	
	printf("**ERINSTAGRAM**\n");
 	printf("1: Load image\n");
 	printf("2: Display image\n");
 	printf("3: Edit image\n");
 	printf("0: Exit\n\n");
 	printf("Choose from one of the options above: ");
 	scanf(" %c", &cmd);
 
 
 
 switch (cmd){
  case '1':
	loadImage(100, 100, img, &rows, &cols);
  break;
  
  case '2':
   	displayImage(rows, cols, img);
  break;
  
  case '3':
  	if(img[0][0]=='\0'){
  		printf("Sorry, no image to edit\n");
  	}else{
  		printf("\n\n**EDITING**\n");
  		printf("1: Crop image\n");
		printf("2: Dim image\n");
		printf("3: Brighten image\n");
		printf("0: Return to main menu\n\n");
		printf("Choose from one of the options above: ");
		scanf(" %c", &cmd2);
		
		switch (cmd2){
		  case '1':
		  	cropImage(rows, cols, img);
		  break;
		  
		  case '2':
		  	brightImage(rows, cols, img);
		  break;
		  
		  case '3':
		  	dimImage(rows, cols, img);
		  break;
		  
		  default:
		  break;
		}
		
  		break;
  
  case 0:
  printf("\n");
  break;
  
  default:
	printf("Invalid option, please try again.\n");
  break;
    
 }
 
 }
 
 
 }while(cmd != '0');
 
 printf("Goodbye!");
 
  return 0 ;
}



//-----------------------------------------------------------

void displayImage(int row, int col, int arr[][100] ){

printf("\n");
 
 for(int c = 0; c < col; c++){
  for(int r = 0; r < row; r++){
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
void loadImage(int col, int row, int arr[][100], int *newRow, int *newCol){
char buffer;
 char name[50];
  *newRow = 0;
  *newCol = 0;
  
  scanf("%c", &buffer);
 
 printf("What is the name of the image file? ");
 fgets(name, 49, stdin);
 
 for(int nameIndex=0; name[nameIndex]!='\0' ; nameIndex++){
 		if(name[nameIndex]=='\n'){
 			name[nameIndex]='\0';
 
 FILE* file = fopen(name, "r");
 
 if(file == NULL){
  	printf("file does not exist ");
 }else{ 
 	
 	char tempC;
 	while(fscanf(file, "%c",&tempC ) == 1){//finds col
 	 if(tempC != '\n'){
 	  *newCol++;
 	 }	  
 	}
 	
 	fclose(file);
 	file = fopen(name, "r");//resets file to start 
 	
 	char temp;
 	while(fscanf(file, "%c", &tempC) == 1){//get rows       
 	 if(temp != '\n' || temp != ' '){
 	  *newRow++;
 	 }
 	 
 	}
 	
        fclose(file);
        file = fopen(name, "r");//resets file to start 
 	
 	
 	char x;// 
 	  for(int c = 0; c < col; c++){
  	    for(int r = 0; r < row; r++){
             fscanf(file, "%d",  &arr[r][c]);
            }
    	     fscanf(file, "%c", &x );//go to next line by scanning '\n' 
          }
          fclose(file);
    }
 	
	}
     
 }

 printf("\nImage successfully loaded!\n\n");

 }
 
//---------------------------------------------------------- 
 void dimImage(int row, int col, int arr[][100]){
 
 int dim[100][100];
 
 for(int c = 0; c < col; c++){
   for(int r = 0; r < row; r++){
     dim[r][c]=arr[r][c];
    }
  }
 

  for(int c = 0; c < col; c++){
   for(int r = 0; r < row; r++){
    if(dim[r][c] > 0){
     dim[r][c]--;
    	}   
   }
 }
 
 displayImage(row,col,dim);
	
 saveImage(row,col,dim);
 
 }
 //---------------------------------------------------------
 
 void brightImage(int row, int col, int arr[][100]){
 
 int bright[100][100];
 
 for(int c = 0; c < col; c++){
   for(int r = 0; r < row; r++){
     bright[r][c]=arr[r][c];
    }
  }
 
   for(int c = 0; c < col; c++){
    for(int r = 0; r < row ; r++){
     if(bright[r][c] < 4){
      bright[r][c]++;      
     }
  
      }
    }
 displayImage(row,col,bright);
	
 saveImage(row,col,bright);
 
 }
 
//---------------------------------------------------------

void cropImage(int col, int row, int arr[][100]){

	int newLeft, newRight, newTop, newBottom, rowSize, colSize;
	
	printf("   1");
	for(int r = 0 ; r < row-2 ; r++){
		printf(" ");
	}
	printf("%d\n", row);
	
	for(int c = 0; c < col; c++){
	if(c==0 || c==col-1){
		printf("%3d", c+1);
	}else{
		printf("   ");
	}
  		for(int r = 0; r < row; r++){
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
	
	printf("\nThe image you want to crop is %d x %d.", row, col);
	printf("\nThe row and column values start in the upper lefthand corner.\n");
	
	printf("Which column do you want to be the new left side? ");
	scanf("%d", &newLeft);
	while(newLeft < 1 || newLeft >= row){
		printf("Invalid column value. Choose a value between 1 and %d ", col-1);
		scanf("%d", &newLeft);
	}

	printf("\nWhich column do you want to be the new right side? ");
	scanf("%d", &newRight);
	while(newRight <= newLeft || newRight > row){
		printf("Invalid column value. Choose a value between %d and %d ",newLeft+1, row);
		scanf("%d", &newRight);
	}
	
	printf("\nWhich row do you want to be the new top? ");
	scanf("%d", &newTop);
	while(newTop<1 || newTop>=col){
		printf("Invalid row value. Choose a value between 1 and %d ", col-1);
		scanf("%d", &newTop);
	}

	printf("\nWhich row do you want to be the new bottom? ");
	scanf("%d", &newBottom);
	while(newBottom<=newTop || newBottom>col){
		printf("Invalid row value. Choose a value between %d and %d ",newTop+1, col);
		scanf("%d", &newBottom);
	}
	
	rowSize=newRight-newLeft+1;
	
	colSize=newBottom-newTop+1;
	
	int cropImg[100][100];
	
	
	
	for(int c = 0; c < colSize ; c++ ){
		for(int r=0;r<rowSize;r++){
			cropImg[r][c]= arr[newLeft-1+r][newTop-1+c];//
		}
	}
	
	displayImage(rowSize,colSize,cropImg);
	
	saveImage(rowSize,colSize,cropImg);
	

}

//---------------------------------------------------------
 
void saveImage(int col, int row, int arr[][100]){
 
 	char option, buffer;
 	char nameSave[50];
 	
 	printf("Would you like to save? (y/n) ");
 	scanf(" %c", &option);
 	
 	scanf("%c", &buffer); //consumes the \n from last scan
 	
 	if(option=='y'){
 	
 		printf("\nWhat do you want to name the image file? (include the extension) ");
 		fgets(nameSave, 49, stdin);
 		
 		for(int nameIndex=0; nameSave[nameIndex]!='\0' ; nameIndex++){
 			if(nameSave[nameIndex]=='\n'){
 				nameSave[nameIndex]='\0';
 			}
 		}
 			
 		FILE* file = fopen(nameSave, "w");
 		
 		for(int c=0; c<col ; c++){
 			if(c!=0){
 				fprintf(file,"\n");
 			}
 			for(int r=0; r<row ; r++){
 				fprintf(file,"%d", arr[r][c]);
 				if(r<row-1){
 					fprintf(file, " ");
 				}
 			}
 		}
 		fclose(file);
 		printf("\nImage successfully saved!\n");		
 	}
 
 }
 
 
 
 
 
 
 
 
 
 
 
