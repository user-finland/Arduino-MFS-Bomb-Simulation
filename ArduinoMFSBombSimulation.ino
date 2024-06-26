//delays defined
#define DELAY1 500
#define DELAY2 250
#define DELAY3 125
#define DELAY4 90
#define DELAY5 2000
//includes repository
#include <MultiFunctionShield.h>
//function run at start
void setup (){
  //starts MFS and other setup
  MultiFunctionShield MFS;
  MFS.begin();
  MFS.Display(100);
  pinMode(LED_1_PIN, OUTPUT);
}
 
void loop() {
  uint8_t i;

  if (digitalRead(BUTTON_1_PIN) == LOW) { //detects button press
      //MFS started
      MultiFunctionShield MFS;
      MFS.begin();
      
      int counter = 100; //variable for the counter
      for (i = 0; i < 8; i++) { //buzzer and led flicker for loop (8 times)
        counter = counter - 5;
        MFS.Display(counter);
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_1_PIN, HIGH);
        delay (DELAY1);
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(LED_1_PIN, LOW);
        delay (DELAY1);
      }
      for (i = 0; i < 8; i++) { //buzzer and led flicker for loop (8 times)
        counter = counter - 5;
        MFS.Display(counter);
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_1_PIN, HIGH);
        delay (DELAY2);
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(LED_1_PIN, LOW);
        delay (DELAY2);
      }
      for (i = 0; i < 8; i++) {  //buzzer and led flicker for loop (8 times)
        counter = counter - 1;
        MFS.Display(counter); 
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_1_PIN, HIGH);
        delay (DELAY3);
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(LED_1_PIN, LOW);
        delay (DELAY3);
      }
      for (i = 0; i < 8; i++) { //buzzer and led flicker for loop (8 times)
        counter = counter - 1;
        MFS.Display(counter);
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_1_PIN, HIGH);
        delay (DELAY4);
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(LED_1_PIN, LOW);
        delay (DELAY4);
      }

      unsigned long startTime = millis(); //final buzzer and led flicker
      while (millis() - startTime < DELAY5) {
        MFS.Display(0000);
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_1_PIN, HIGH);
        delay(20); //delay for the desired frequency
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(LED_1_PIN, LOW);
        delay(20); //delay for the desired frequency
      }
      setup(); //re-runs setup function
  }
}
