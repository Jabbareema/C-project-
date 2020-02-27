#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
*
 *
*
 *
Name:Rema Abdulrhman Alabduljabbar
ID: 437202646
 
Name: Raghad Saleh Alowini
ID:437202723
*
 *
*
 *
*/

 
//Functions' prototypes:
void add();
void search();
void viewAll();
void edit();
void deleteR();

typedef struct { //rename 
char name[25],email[25],phoneNum[10];}
Record;

int main() {

time_t t = time(NULL);
struct tm tm = *localtime(&t);

int pass;
int x = 1;
int Pass[5]={1111,1234,9999,5555,1122};
while(x){
printf("the current date & time: [%d-%d-%d] **** [%d:%d:%d]\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

printf("\t\tEnter your Password: ");
   scanf("%d",&pass);
   for(int i = 0 ; i<5 ; i++){
   if(pass == Pass[i])
   x=0;
   
   }
   }
   

   int n;
   x=1;
   while(x){
   printf("\n\n\n  the current date & time:\n[%d-%d-%d] **** [%d:%d:%d]", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
printf("\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Added Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

printf("Enter your choice: ");
   scanf("%d",&n);
   switch(n){
   case 0:
      printf("\n\n\t\tSee you next time .... ");
      x=0;
      break;
   
   case 1:
     add();
     break;
      
      case 2:
      viewAll();
      break;

       case 3:
       search();
       break;
       
       case 4:
       edit();
       break;
       
       case 5:
       deleteR();
       
       default:
       printf("\n  ======== Enter correct Number :)! ========\n");
       break;
return 0;}
}

}//main


void add(){
int num;
Record r,list[25];
 printf("How many Contacts do you want to enter?\n");
     scanf("%d",&num);
FILE * file;
file = fopen("record.txt", "a+");

  if(file == NULL){
      perror("File could not be opened.");
      return;}
      
  else{
  
  for(int i=0;i<num;i++) {

printf(" Name: ");
    scanf("%s",r.name);

printf(" Email: ");
   scanf("%s",r.email);

printf(" Phone Number: ");
  scanf("%s",r.phoneNum);



fwrite(&r,1,sizeof(Record),file);}
fclose(file);

        
}//else
}//method Add


void viewAll(){
     FILE* fr;
fr=fopen("record.txt","r");
Record r;
while(fread(&r,sizeof(r),1,fr)){
printf("Name: %s\t || Email: %s\t || Phone Number: %s \n",r.name,r.email,r.phoneNum);}
fclose(fr);}


void search(){
Record r;
    int flag = 1;
     FILE* fr;
    while(flag){
fr=fopen("record.txt","r");    
char na[10];
 printf(" Enter the name:... ");
    scanf("%s",na);
    
while(fread(&r,sizeof(r),1,fr)){
if(strstr(na,r.name)) {// strstr or strcmp
printf(" A match has been found ... ");
printf("%s %s %s \n",r.name,r.email,r.phoneNum);}
//else printf(" Not found ");
}

printf("\n press 1 to search for another contact, 0 other ways ... ");
        scanf("%d",&flag);
        fclose(fr);}
        }
        
void deleteR(){
      
FILE* fr; 
fr=fopen("record.txt","r"); //open first file
FILE * fileptr2 = fopen("temp.txt", "w"); //open 2nd file 
Record r;
 
char name[10];
 printf(" Enter the name:... ");
   scanf("%s",name); 
   while(fread(&r,sizeof(r),1,fr)){
   if(strstr(name,r.name))
   printf( "Record Deleted Successfully \n");
   else{
   fwrite(&r,1,sizeof(r),fileptr2);}
   }
    fclose(fr);
    fclose(fileptr2);
    remove("record.txt");
rename("temp.txt", "record.txt");
} 
  
  
void edit(){
FILE* fr; 
fr=fopen("record.txt","r"); //open first file
FILE * fileptr2 = fopen("temp.txt", "w"); //open 2nd file 
Record r;
 
char name[10];
 printf(" Enter the name:... ");
   scanf("%s",name); 
   while(fread(&r,sizeof(r),1,fr)){
   if(strstr(name,r.name)){
   printf(" Enter the new info. ... \n"); 
printf(" Name: ");
    scanf("%s",r.name);

printf(" Email: ");
   scanf("%s",r.email);

printf(" Phone Number: ");
  scanf("%s",r.phoneNum);
     fwrite(&r,1,sizeof(r),fileptr2);
     printf( "Record Updated Successfully \n");}
   else{
   fwrite(&r,1,sizeof(r),fileptr2);}
   }
    fclose(fr);
    fclose(fileptr2);
    remove("record.txt");
rename("temp.txt", "record.txt");
}




    