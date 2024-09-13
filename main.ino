void init_port(void);
void out_data(char);
void out_control(char);
void delay1(char);
void init_lcd(void);
void lcd_control_write(void);
void write_string(char);
void write_data(char);
void setup() {
  init_port();
  init_lcd();
  write_string("Embedded System");
  out_data(0xc0);
  lcd_control_write();
  write_string("Programming");
}
void init_port(void ){
  volatile char *dirf = (volatile char *)0x30;
  volatile char *dirk = (volatile char *)0x107;
  *dirf = 0xFF;
  *dirk = 0x03;
}
void out_data(char data){
  volatile char *outf = (volatile char *)0x31;
  *outf = data;
}
void out_control(char data){
  volatile char *outk = (volatile char *)0x108;
  *outk = data;
}
void delay1(char time){
  volatile long i;
  for(i=0;i<time*10000;i++);
}
void init_lcd(void){
  out_data(0x38);
  lcd_control_write();
  out_data(0x0F);
  lcd_control_write();
  out_data(0x01);
  lcd_control_write();
  out_data(0x06);
  lcd_control_write();
  
}
void lcd_control_write(void){
  out_control(0x00);
  delay1(1);
  out_control(0x01);
  delay1(1);
  out_control(0x00);
  delay1(1);
}
void write_string(char *ptr){
  while(*ptr!=0){
    write_data(*ptr);
    ptr++;
  }
}
void write_data(char writedata){
  out_data(writedata);
  out_control(0x02);
  delay1(1);
  out_control(0x03);
  delay1(1);
  out_control(0x02);
  delay1(1);
}

void loop() {

}
