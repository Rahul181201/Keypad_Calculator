void init(void);
void delay1(long num);
void digit1(char op);
void digit2(char op);
void digit3(char op);
void digit4(char op);
void add(char num1, char num2, char num3, char num4, char num5, char num6, char num7, char num8, unsigned char digit[]);
void sub(char num1, char num2, char num3, char num4, char num5, char num6, char num7, char num8, unsigned char digit[]);
void mul(char num1, char num2, char num3, char num4, char num5, char num6, char num7, char num8, unsigned char digit[]);
void div(char num1, char num2, char num3, char num4, char num5, char num6, char num7, char num8, unsigned char digit[]);
void init(){
  volatile char *dirf, *dirk, *dira, *dirc;
  dirf = 0x30; dirk = 0x107; dira = 0x21; dirc = 0x27;
  *dirf = 0xFF; *dirk = 0x00; *dira = 0xFF; *dirc = 0x0F;
}

void delay1(long num){
  volatile long m;
  for(m=0;m<num*10000;m++);
}
void digit1(char op){
  volatile char *outc, *outa;
  outc = 0x28;
  outa = 0x22;
  *outc = 0xff;
  *outa = op;
  *outc = 0xfe;
  
}
void digit2(char op){
  volatile char *outc, *outa;
  outc = 0x28;
  outa = 0x22;
  *outc = 0xff;
  *outa = op;
  *outc = 0xfd;
  
}
void digit3(char op){
  volatile char *outc, *outa;
  outc = 0x28;
  outa = 0x22;
  *outc = 0xff;
  *outa = op;
  *outc = 0xfb;
  
}
void digit4(char op){
  volatile char *outc, *outa;
  outc = 0x28;
  outa = 0x22;
  *outc = 0xff;
  *outa = op;
  *outc = 0xf7;
  
}

void add(char num1, char num2, char num3, char num4, char num5, char num6, char num7, char num8, unsigned char digit[]){
  int finalnum1,finalnum2,sum;
  char dig1, dig2, dig3, dig4;
  if(num1!=10 && num2==10 && num3==10 && num4==10){
    finalnum1 = (int)num1;
  }
  else if(num1!=10 && num2!=10 && num3==10 && num4==10 ){
    finalnum1 = (int)(num1*10 + num2);
  }
  else if(num1!=10 && num2!=10 && num3!=10 && num4==10){
    finalnum1 = (int)(num1*100 + num2*10 + num3);
  }else{
    finalnum1 = (int)(num1*1000 + num2*100 + num3*10 + num4);
  }
  if(num5!=10 && num6==10 && num7==10 && num8==10){
    finalnum2 = (int)num5;
  }
  else if(num5!=10 && num6!=10 && num7==10 && num8==10 ){
    finalnum2 = (int)num5*10 + num6;
  }
  else if(num5!=10 && num6!=10 && num7!=10 && num8==10){
    finalnum2 = (int)num5*100 + num6*10 + num7;
  }else{
    finalnum2 = (int)num5*1000 + num6*100 + num7*10 + num8;
  }
  sum = finalnum1 + finalnum2;
  if(sum>=0 && sum<10){
    dig1 = (char) sum;
    digit4(digit[dig1]);
  }
  else if(sum>=10 && sum<100){
    dig1 = (char)(sum/10);
    dig2 = (char)(sum%10);
    while(1){
      digit3(digit[dig1]);
      delay1(0.5);
      digit4(digit[dig2]);
      delay1(0.5);
    }
  }
  else if(sum>=100 && sum<1000){
    dig1 = (char)(sum/100);
    dig2 = (char)((sum/10)%10);
    dig3 = (char)(sum%10);
    while(1){
      digit2(digit[dig1]);
      delay1(0.5);
      digit3(digit[dig2]);
      delay1(0.5);
      digit4(digit[dig3]);
      delay1(0.5);
    }
  }else if(sum>=1000 && sum<10000){
    dig1 = (char)(sum/1000);
    dig2 = (char)((sum/100)%10);
    dig3 = (char)((sum/10)%10);
    dig4 = (char)(sum%10);
    while(1){
      digit1(digit[dig1]);
      delay1(0.5);
      digit2(digit[dig2]);
      delay1(0.5);
      digit3(digit[dig3]);
      delay1(0.5);
      digit4(digit[dig4]);
      delay1(0.5);
    }
  }else{
    while(1){
        digit1(digit[12]);
        delay1(0.5);
        digit2(digit[12]);
        delay1(0.5);
        digit3(digit[12]);
        delay1(0.5);
        digit4(digit[12]);
        delay1(0.5);
      }
  }
}

void sub(char num1, char num2, char num3, char num4, char num5, char num6, char num7, char num8, unsigned char digit[]){
  int finalnum1,finalnum2,dif;
  char dig1, dig2, dig3, dig4;
  if(num1!=10 && num2==10 && num3==10 && num4==10){
    finalnum1 = (int)num1;
  }
  else if(num1!=10 && num2!=10 && num3==10 && num4==10 ){
    finalnum1 = (int)(num1*10 + num2);
  }
  else if(num1!=10 && num2!=10 && num3!=10 && num4==10){
    finalnum1 = (int)(num1*100 + num2*10 + num3);
  }else{
    finalnum1 = (int)(num1*1000 + num2*100 + num3*10 + num4);
  }
  if(num5!=10 && num6==10 && num7==10 && num8==10){
    finalnum2 = (int)num5;
  }
  else if(num5!=10 && num6!=10 && num7==10 && num8==10 ){
    finalnum2 = (int)num5*10 + num6;
  }
  else if(num5!=10 && num6!=10 && num7!=10 && num8==10){
    finalnum2 = (int)num5*100 + num6*10 + num7;
  }else{
    finalnum2 = (int)num5*1000 + num6*100 + num7*10 + num8;
  }
  dif = finalnum1 - finalnum2;
  if(dif>=0 && dif<10){
    dig1 = (char) dif;
    digit4(digit[dig1]);
  }
  else if(dif<0){
    dif = dif - 2*dif;
    if(dif>=0 && dif<10){
      dig1 = (char) dif;
      while(1){
        digit3(digit[11]);
        delay1(0.5);
        digit4(digit[dig1]);
        delay1(0.5);
      }
    }
    else if(dif>=10 && dif<100){
      dig1 = (char)(dif/10);
      dig2 = (char)(dif%10);
      while(1){
        digit2(digit[11]);
        delay1(0.5);
        digit3(digit[dig1]);
        delay1(0.5);
        digit4(digit[dig2]);
        delay1(0.5);
      }
    }
    else if(dif>=100 && dif<1000){
      dig1 = (char)(dif/100);
      dig2 = (char)((dif/10)%10);
      dig3 = (char)(dif%10);
      while(1){
        digit1(digit[11]);
        delay1(0.5);
        digit2(digit[dig1]);
        delay1(0.5);
        digit3(digit[dig2]);
        delay1(0.5);
        digit4(digit[dig3]);
        delay1(0.5);
      }
    }
    else if(dif>=10 && dif<100){
      dig1 = (char)(dif/10);
      dig2 = (char)(dif%10);
      while(1){
        digit3(digit[dig1]);
        delay1(0.5);
        digit4(digit[dig2]);
        delay1(0.5);
      }
    }
    else{
      while(1){
        digit1(digit[12]);
        delay1(0.5);
        digit2(digit[12]);
        delay1(0.5);
        digit3(digit[12]);
        delay1(0.5);
        digit4(digit[12]);
        delay1(0.5);
      }
    }
  }
  else if(dif>=100 && dif<1000){
    dig1 = (char)(dif/100);
    dig2 = (char)((dif/10)%10);
    dig3 = (char)(dif%10);
    while(1){
      digit2(digit[dig1]);
      delay1(0.5);
      digit3(digit[dig2]);
      delay1(0.5);
      digit4(digit[dig3]);
      delay1(0.5);
    }
  }else{
    dig1 = (char)(dif/1000);
    dig2 = (char)((dif/100)%10);
    dig3 = (char)((dif/10)%10);
    dig4 = (char)(dif%10);
    while(1){
      digit1(digit[dig1]);
      delay1(0.5);
      digit2(digit[dig2]);
      delay1(0.5);
      digit3(digit[dig3]);
      delay1(0.5);
      digit4(digit[dig4]);
      delay1(0.5);
    }
  }
}

void mul(char num1, char num2, char num3, char num4, char num5, char num6, char num7, char num8, unsigned char digit[]){
  int finalnum1,finalnum2,prod;
  char dig1, dig2, dig3, dig4;
  if(num1!=10 && num2==10 && num3==10 && num4==10){
    finalnum1 = (int)num1;
  }
  else if(num1!=10 && num2!=10 && num3==10 && num4==10 ){
    finalnum1 = (int)(num1*10 + num2);
  }
  else if(num1!=10 && num2!=10 && num3!=10 && num4==10){
    finalnum1 = (int)(num1*100 + num2*10 + num3);
  }else{
    finalnum1 = (int)(num1*1000 + num2*100 + num3*10 + num4);
  }
  if(num5!=10 && num6==10 && num7==10 && num8==10){
    finalnum2 = (int)num5;
  }
  else if(num5!=10 && num6!=10 && num7==10 && num8==10 ){
    finalnum2 = (int)num5*10 + num6;
  }
  else if(num5!=10 && num6!=10 && num7!=10 && num8==10){
    finalnum2 = (int)num5*100 + num6*10 + num7;
  }else{
    finalnum2 = (int)num5*1000 + num6*100 + num7*10 + num8;
  }
  prod = finalnum1 * finalnum2;
  if(prod>=0 && prod<10){
    dig1 = (char) prod;
    digit4(digit[dig1]);
  }
  else if(prod>=10 && prod<100){
    dig1 = (char)(prod/10);
    dig2 = (char)(prod%10);
    while(1){
      digit3(digit[dig1]);
      delay1(0.5);
      digit4(digit[dig2]);
      delay1(0.5);
    }
  }
  else if(prod>=100 && prod<1000){
    dig1 = (char)(prod/100);
    dig2 = (char)((prod/10)%10);
    dig3 = (char)(prod%10);
    while(1){
      digit2(digit[dig1]);
      delay1(0.5);
      digit3(digit[dig2]);
      delay1(0.5);
      digit4(digit[dig3]);
      delay1(0.5);
    }
  }else if(prod>=1000 && prod<10000){
    dig1 = (char)(prod/1000);
    dig2 = (char)((prod/100)%10);
    dig3 = (char)((prod/10)%10);
    dig4 = (char)(prod%10);
    while(1){
      digit1(digit[dig1]);
      delay1(0.5);
      digit2(digit[dig2]);
      delay1(0.5);
      digit3(digit[dig3]);
      delay1(0.5);
      digit4(digit[dig4]);
      delay1(0.5);
    }
  }else{
    while(1){
        digit1(digit[12]);
        delay1(0.5);
        digit2(digit[12]);
        delay1(0.5);
        digit3(digit[12]);
        delay1(0.5);
        digit4(digit[12]);
        delay1(0.5);
      }
  }
}

void div(char num1, char num2, char num3, char num4, char num5, char num6, char num7, char num8, unsigned char digit[]){
  int finalnum1,finalnum2,quo;
  char dig1, dig2, dig3, dig4;
  if(num1!=10 && num2==10 && num3==10 && num4==10){
    finalnum1 = (int)num1;
  }
  else if(num1!=10 && num2!=10 && num3==10 && num4==10 ){
    finalnum1 = (int)(num1*10 + num2);
  }
  else if(num1!=10 && num2!=10 && num3!=10 && num4==10){
    finalnum1 = (int)(num1*100 + num2*10 + num3);
  }else{
    finalnum1 = (int)(num1*1000 + num2*100 + num3*10 + num4);
  }
  if(num5!=10 && num6==10 && num7==10 && num8==10){
    finalnum2 = (int)num5;
  }
  else if(num5!=10 && num6!=10 && num7==10 && num8==10 ){
    finalnum2 = (int)num5*10 + num6;
  }
  else if(num5!=10 && num6!=10 && num7!=10 && num8==10){
    finalnum2 = (int)num5*100 + num6*10 + num7;
  }else{
    finalnum2 = (int)num5*1000 + num6*100 + num7*10 + num8;
  }
  quo = finalnum1/finalnum2;
  if(quo>=0 && quo<10){
    dig1 = (char) quo;
    digit4(digit[dig1]);
  }
  else if(quo>=10 && quo<100){
    dig1 = (char)(quo/10);
    dig2 = (char)(quo%10);
    while(1){
      digit3(digit[dig1]);
      delay1(0.5);
      digit4(digit[dig2]);
      delay1(0.5);
    }
  }
  else if(quo>=100 && quo<1000){
    dig1 = (char)(quo/100);
    dig2 = (char)((quo/10)%10);
    dig3 = (char)(quo%10);
    while(1){
      digit2(digit[dig1]);
      delay1(0.5);
      digit3(digit[dig2]);
      delay1(0.5);
      digit4(digit[dig3]);
      delay1(0.5);
    }
  }else{
    dig1 = (char)(quo/1000);
    dig2 = (char)((quo/100)%10);
    dig3 = (char)((quo/10)%10);
    dig4 = (char)(quo%10);
    while(1){
      digit1(digit[dig1]);
      delay1(0.5);
      digit2(digit[dig2]);
      delay1(0.5);
      digit3(digit[dig3]);
      delay1(0.5);
      digit4(digit[dig4]);
      delay1(0.5);
    }
  }
}

