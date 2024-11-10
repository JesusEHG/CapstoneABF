int BUTTON_1 = D0;
int BUTTON_2 = D1;
int BUTTON_3 = D2;
int confirm_counter=0;
int i; 
char string_phonenumber[12] = {'+','1',0,0,0,0,0,0,0,0,0,0};
int phoneNumber[10] = {0,0,0,0,0,0,0,0,0,0};
int state = 0;
int value;
int value_2;
int value_3;
int number = 0;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,  16, 2);

void setup() {
  // put your setup code here, to run once:

  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();

 pinMode(BUTTON_1, INPUT);
 pinMode(BUTTON_2, INPUT);
 pinMode(BUTTON_3, INPUT);

 //Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0, 0);
lcd.print("Enter Number:");
printPhoneNumber();


  value = digitalRead(BUTTON_1);//left button//
  if(value == LOW)
  {
    state=(state-1);
    if(state<0)
    {
      state = 0;
    }
    
    delay(250);
    phoneNumber[number] = state; 
    printPhoneNumber();
  
  } 
  
  value_2 = digitalRead(BUTTON_2);//right button//
if(value_2==LOW)
{
  state = (state+1);
  if(state>9)
    {
      state = 9;
    }
  delay(250);
  phoneNumber[number] = state; 
     printPhoneNumber();

}

  value_3 = digitalRead(BUTTON_3);//set button//
  if (value_3 == LOW)
  {
number = number + 1;
confirm_counter++;
if(number>10)
    {
      number = 0;
    } 
 if(confirm_counter>15)
 {
  confirm_counter = 15;
 }
state = 0;
delay (250);
  }




  
while(confirm_counter == 15)
{
      
      lcd.setCursor(0,0);
      lcd.print("Confirm Number:  ");
      lcd.setCursor(0,1);
      lcd.print("Yes       No     ");

    value = digitalRead(BUTTON_1); // Re-read BUTTON_1
    value_2 = digitalRead(BUTTON_2); // Re-read BUTTON_2
      
      if(value == LOW)
      {
        for (i = 0; i < 10; i++) {
            string_phonenumber[i+2] = phoneNumber[i] + '0'; // Convert int to char
        }
        string_phonenumber[12] = '\0'; // Null-terminate the string
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Number saved    ");
        lcd.setCursor(0,1);
        lcd.print(string_phonenumber);
        delay(2000);
        lcd.clear();
        confirm_counter = 0; // Exit the confirmation loop
        number=0;
       // Serial.println("Phone Number as String: ");
       // Serial.println(string_phonenumber);

      }
     else if(value_2 == LOW)
      {
        lcd.clear();
        confirm_counter = 0;
        number = 0;
        
      }
delay(250);


}


}
      




void printPhoneNumber()
{
  
  lcd.setCursor(number, 1);
  for (i = number; i<10; i++)
{
  
  lcd.print(phoneNumber[i]);
}
}
