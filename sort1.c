#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void bots(int *arr,int len){
   int temp;
  for(int i = 0 ; i < len ; i++){
    for(int j = 0 ; j < len-1-i ; j++){
      if(arr[j] > arr[j+1]){
         temp = arr[j];
         arr[j]= arr[j+1];
         arr[j+1] = temp;
       }      }     }   }

void sort(int *arr,int len){
  int temp;
  for(int i = 0;i < len;i++){
    for(int j = 0;j < len-1-i;j++){
      if(arr[j] < arr[j+1]){
         temp = arr[j];
         arr[j] = arr[j+1];
         arr[j+1]=temp;
       }      }     }   }

  int main(){
   char buff[255];
   int r[5];
   int z,x,i = 0;

   FILE *fp,*fg;
     fp = fopen("number.txt","r");
     fg = fopen("out.txt","w");
     printf("How many number in the case = %d\n" , sizeof(r)/4);
    memset(r,0,sizeof(r));
    while(fgets(buff,255,fp) !=NULL){
      x=atoi(buff);
      r[i] = x;
      i++;
     printf("%d\n",x);
    }
     scanf("%d",&z);
    if(z==1){
      bots(r, 5);
      for(int i = 0;i < 5;i++)
        printf("%d\n" , r[i]);
     }
    if(z==2){
      sort(r, 5);
      for(int i = 0;i < 5;i++)
        fprintf(fg,"%d\n",r[i]);
        printf("%d\n" , r[i]);
       }
   fclose(fg);
   fclose(fp);
  }

