#include "header.h"
void setup() {
  init();
  volatile char *outf, *ink, *outa, *outc, x,y,row,num;
  volatile char num1=10,num2=10,num3=10,num4=10,num5=10,num6=10,num7=10,num8=10;
  outf = 0x31; ink = 0x106; outa = 0x22; outc = 0x28;
  unsigned char digit[] = {0x3F,0x06,0x5B,0x4f,0x66,0x6d,0x7d,0x07,0x7F,0x6F,0x00,0x40,0x79};
  char count = 0, flag = 0, numround = 0;
  while(1){ 
    for(row=0;row<4;row++){
      *outf = (1<<row);
      x = *ink;
      if(x!=0){
        delay1(5);
        while(*ink !=0){}
        if(row==3){
          if(x == (1<<1)) num = 0;
          else{
            num  = 10;
          }
        }
        else{
          for(char col=0;col<3;col++){
            if(x == (1<<col)) num = col + 1 + 3*row;
            if(x == (1<<3)) num = 10;
          }
        }
        if(count == 0){
          if((row==0) && (x==(1<<3))){  // check for +
            count = -1;
            numround = 1;
            flag = 1;
          }
          else if((row==1) && (x==(1<<3))){  //check for -
            count = -1;
            numround = 1;
            flag = 2;
          }
          else if((row==2) && (x==(1<<3))){  //check for *
            count = -1;
            numround = 1;
            flag = 3;
          }
          else if((row==3) && (x==(1<<3))){  //check for /
            count = -1;
            numround = 1;
            flag = 4;
          }
          else if((row==3) && (x==(1<<2))){  // check for =
            if(flag==1){
              add(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else if(flag==2){
              sub(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else if(flag==3){
              mul(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else{
              div(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }
          }
          else{
            if(numround == 0){
              num1 = num;
            }else{
              num5 = num;
            }
          }
        }
        else if(count == 1){
          if((row==0) && (x==(1<<3))){  // check for +
            count = -1;
            numround = 1;
            flag = 1;
          }
          else if((row==1) && (x==(1<<3))){  //check for -
            count = -1;
            numround = 1;
            flag = 2;
          }
          else if((row==2) && (x==(1<<3))){  //check for *
            count = -1;
            numround = 1;
            flag = 3;
          }
          else if((row==3) && (x==(1<<3))){  //check for /
            count = -1;
            numround = 1;
            flag = 4;
          }
          else if((row==3) && (x==(1<<2))){  // check for =
            if(flag==1){
              add(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else if(flag==2){
              sub(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else if(flag==3){
              mul(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else{
              div(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }
          }
          else{
            if(numround == 0){
              num2 = num;
            }else{
              num6 = num;
            }
          }
        }
        else if(count == 2){
          if((row==0) && (x==(1<<3))){  // check for +
            count = -1;
            numround = 1;
            flag = 1;
          }
          else if((row==1) && (x==(1<<3))){  //check for -
            count = -1;
            numround = 1;
            flag = 2;
          }
          else if((row==2) && (x==(1<<3))){  //check for *
            count = -1;
            numround = 1;
            flag = 3;
          }
          else if((row==3) && (x==(1<<3))){  //check for /
            count = -1;
            numround = 1;
            flag = 4;
          }
          else if((row==3) && (x==(1<<2))){  // check for =
            if(flag==1){
              add(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else if(flag==2){
              sub(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else if(flag==3){
              mul(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else{
              div(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }
          }
          else{
            if(numround == 0){
              num3 = num;
            }else{
              num7 = num;
            }
          }
        }
        else if(count == 3){
          if((row==0) && (x==(1<<3))){  // check for +
            count = -1;
            numround = 1;
            flag = 1;
          }
          else if((row==1) && (x==(1<<3))){  //check for -
            count = -1;
            numround = 1;
            flag = 2;
          }
          else if((row==2) && (x==(1<<3))){  //check for *
            count = -1;
            numround = 1;
            flag = 3;
          }
          else if((row==3) && (x==(1<<3))){  //check for /
            count = -1;
            numround = 1;
            flag = 4;
          }
          else if((row==3) && (x==(1<<2))){  // check for =
            if(flag==1){
              add(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else if(flag==2){
              sub(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else if(flag==3){
              mul(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }else{
              div(num1, num2, num3, num4, num5, num6, num7, num8, digit);
            }
          }
          else{
            if(numround == 0){
              num4 = num;
              count = -1;
              numround = 1;
            }else{
              num8 = num;
              count = -1;
              numround = 1;
            }
          }

        }
        count++;
      }
    }
  }
}





