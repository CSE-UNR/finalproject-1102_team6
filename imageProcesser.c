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
 
 
 
 
 
 
 
 
 
 
 
 
 
