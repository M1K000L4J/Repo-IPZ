#include <Wire.h>

#define AS5600 0x36 // Adres enkodera AS5600 do i2c
//Pinouty pinów zasilających poszczególne enkodery

void setup() {
  Wire.begin(); // Inicjalizacja interfejsu I2C
  Serial.begin(9600); // Inicjalizacja komunikacji szeregowej
}

double read(int enkoder_power_pin){
  Wire.beginTransmission(AS5600); // Rozpoczęcie transmisji do enkodera
  Wire.write(0x0E); // Adres rejestru odczytu kąta
  Wire.endTransmission(); // Zakończenie transmisji

  Wire.requestFrom(AS5600_ADDR, 2); // Odczytaj 2 bajty danych z enkodera
  if (Wire.available() >= 2) {
    int angle_LSB = Wire.read(); // Odczytaj mniej znaczący bajt
    int angle_MSB = Wire.read(); // Odczytaj bardziej znaczący bajt

    int angle = (angle_MSB << 8) | angle_LSB; // Oblicz wartość kąta
    return(angle);
}


void loop() {
  //zmienne mierzonych kątów
  double angle_1;
  double angle_2;
  double angle_3;
  double angle_4;
  //odczyt położenia wszystkich enkoderów
  angle_1 = read(enkoder_1_power);
  angle_2 = read(enkoder_2_power);
  angle_3 = read(enkoder_3_power);
  angle_4 = read(enkoder_4_power);
  //ewentualna transformacja na wartośći bardziej użyteczne
  
  //transmisja do bazy danych
  
  delay(100); // Poczekaj przed kolejnym odczytem
}

