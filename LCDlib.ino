//#define LOW 0
//#define HIGH 1

int LCDRegisterSelctPin =  4; //D2  rs low for command and high for data
int LCDENablePin =  0;  //D3

int Pin4 = 2;  //D4
int Pin5 =  14; //D5
int Pin6 = 12;  //D6
int Pin7 = 13;  //D7



#define LCDClear() LCDWriteCommand(0x01)    /* Clear display LCD */
#define LCDRow1()  LCDWriteCommand(0x80)    /* Begin at Line 1 */
#define LCDRow2()  LCDWriteCommand(0xC0)   /* Begin at Line 2 */

//USERDEFINE DATA TYPES
//typedef unsigned char unsigned char;

//DEFINE PROTOTYPES
inline void  LCDEnable(void);
void LCDWriteCommand(unsigned char command);
void LCDWriteData(unsigned char ascii);
void LCDWriteString(const char *lcd_string);
void LCDWriteString1(volatile char *lcd_string);
void LCDWriteStringWithLength (volatile unsigned char * str, unsigned char length);
void LCDWriteByte(unsigned char  LCDData);
void LCDInitialize(void);
void LCDDisplayInitializing(void);
void LCDDisplayByte(unsigned char LCDAdress, unsigned char Value);
//void LCDReset(void);

//#endif
void setup()// put your setup code here, to run once:
{
    pinMode(LCDRegisterSelctPin, OUTPUT); 
    pinMode(LCDENablePin, OUTPUT); 
    pinMode(Pin4, OUTPUT); 
    pinMode(Pin5, OUTPUT); 
    pinMode(Pin6, OUTPUT); 
    pinMode(Pin7, OUTPUT); 
    LCDEnable();
    LCDInitialise();
    delay(10);
    LCDWriteString("Meera ka pic");
}
void loop() {
  // put your main code here, to run repeatedly:

}

inline void LCDEnable(void)
{
     digitalWrite(LCDENablePin, HIGH);
     delay(10);
     digitalWrite(LCDENablePin, LOW);
}
void LCDWriteCommand(unsigned char LCDData)
{
     digitalWrite(LCDRegisterSelctPin, LOW);
     LCDWriteByte(LCDData);
}
void LCDWriteData(unsigned char LCDData)
{
      digitalWrite(LCDRegisterSelctPin, HIGH);
      LCDWriteByte(LCDData);
}
void LCDWriteString(const char *lcd_string)
{
      while(*lcd_string)
      {
        LCDWriteData(*lcd_string++);
      }
}
void LCDWriteString1(volatile char *lcd_string)
{
   while(*lcd_string)
   {
      LCDWriteData(*lcd_string++);
   }
}
void LCDWriteStringWithLength(volatile unsigned char *str, unsigned char length)
{
      while((length--) && (*str!= '\r'))
      LCDWriteData(*str++);
}
void LCDInitialise(void)
{
//    digitalWrite(Pin7, LOW);
//    digitalWrite(Pin6, LOW);
//    digitalWrite(Pin5, LOW);
//    digitalWrite(Pin4, LOW);
//    digitalWrite(LCDRegisterSelctPin, HIGH);
//    digitalWrite(LCDENablePin,HIGH);
    
//    LCDReset();
    LCDWriteCommand(0x28);
    LCDWriteCommand(0x0E);
    LCDWriteCommand(0x06);
    LCDWriteCommand(0x01);
}

//void LCDReset(void)
//{
//   LCDWriteCommand(0x33);
//   LCDWriteCommand(0x33);
//   LCDWriteCommand(0x32);
//}
//*/
void LCDWriteByte(unsigned char LCDData)
{
   digitalWrite(Pin7, LOW);
   digitalWrite(Pin6, LOW);
  digitalWrite(Pin5, LOW);
  digitalWrite(Pin4, LOW);

   digitalWrite(Pin7, LCDData & 0x80);
   digitalWrite(Pin6, LCDData & 0x40);
   digitalWrite(Pin5, LCDData & 0x20);
   digitalWrite(Pin4, LCDData & 0x10);
   LCDEnable();
   digitalWrite(Pin7, LCDData & 0x08);
   digitalWrite(Pin6, LCDData & 0x04);
   digitalWrite(Pin5, LCDData & 0x02);
   digitalWrite(Pin4, LCDData & 0x01);
    LCDEnable();
    delay(5);

}
 
