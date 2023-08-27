// const int leds[] = {
//   1,
//   2,
//   3,
//   4
// };

// #define LEN sizeof(leds) / sizeof(leds[0])

// void setup()
// {
//   for (int i = 0; i < 5; i++)
//   {
//     pinMode(leds[i], OUTPUT);
//   }
// }

// void turn_off_all_leds()
// {
//   for (int i = 0; i < LEN; i++)
//   {
//     digitalWrite(leds[i], LOW);
//   }
// }

// void first_mode()
// {
//   turn_off_all_leds();
//   for (int i = 0; i < LEN; i++) {
//     digitalWrite(leds[i], HIGH);
//     delay(200);
//   }
// }

// void second_mode()
// {
//   turn_off_all_leds();
//   for (int i = LEN - 1; i >= 0; i--) {
//     digitalWrite(leds[i], HIGH);
//     delay(200);
//   }
// }

// void third_mode()
// {
//   turn_off_all_leds();
//   first_mode();
//   second_mode();
//   first_mode();
//   second_mode();
// }

// void loop()
// {
//   first_mode();
//   delay(1000);
//   second_mode();
//   delay(1000);
//   third_mode();
// }


#define PWM_PIN 3

void setup()
{
  pinMode(PWM_PIN, OUTPUT);
}

void loop()
{
  //for (int i = 0; i < 256; i += 5) {
    digitalWrite(PWM_PIN, 1);
    //delay(200);
 // }
}