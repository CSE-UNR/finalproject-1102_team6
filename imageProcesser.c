#include <stdio.h>

void dimImage();
void brightImage();
void cropImage();
void loadImage();
void displayImage();
void saveImage();

int main(){


  
  
  
  
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
