#include "LiquidCrystal.h"

#include "max6675.h"

// CONFIGURACION DE LOS PINES UTILIZADOS PARA LA COMUNICACIÓN CON EL MAX6675

#define CONFIG_TCGND_PIN      8   // ALIMENTACION GND

#define CONFIG_TCVCC_PIN      9   // ALIMENTACION VCC

#define CONFIG_TCSCK_PIN      10  // SPI SCK

#define CONFIG_TCCS_PIN       11  // SPI CS

#define CONFIG_TCDO_PIN       12  // SPI MISO

// CONSTRUCTOR PARA LA PANTALLA LCD 16X2

// AQUI SE CONFIGURAN LOS PINES PARA LA COMUNICACION CON LA PANTALLA

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// OBJETO UTILIZADO PARA LA COMUNICACION CON EL MAX6675

MAX6675 thermocouple(CONFIG_TCSCK_PIN, CONFIG_TCCS_PIN, CONFIG_TCDO_PIN);

void setup() {

  // PREPARAR LA INTERFAZ SERIAL

  Serial.begin(9600);

  // IMPRIMR MENSAJE INICIAL A LA TERMINAL

  Serial.println(F("—————————————————-"));

  Serial.println(F("      TUTORIAL TERMOPAR CON ARDUINO Y MAX6675       "));

  Serial.println(F("            http://www.geekfactory.mx               "));

  Serial.println(F("—————————————————-"));

  // USAR PINES DE ARDUINO PARA ALIMENTAR EL MODULO MAX6675

  pinMode(CONFIG_TCVCC_PIN, OUTPUT); digitalWrite(CONFIG_TCVCC_PIN, HIGH);

  pinMode(CONFIG_TCGND_PIN, OUTPUT); digitalWrite(CONFIG_TCGND_PIN, LOW);

  // INDICAMOS QUE TENEMOS CONECTADA UNA PANTALLA DE 16X2

  // IMPRIMIR MENSAJE INICIAL EN PANTALLA

  lcd.begin(16, 2);

  lcd.clear();

  lcd.print(F("TERMOPAR ARDUINO"));

  lcd.setCursor( 0, 1 );

  lcd.print(F("  CON MAX6675   "));

  // ESPERAR UN SEGUNDO

  delay(1000);

}

void loop() {

  // LEER EL TERMOPAR Y ALMACENAR EL VALOR EN UNA VARIABLE

  double t = thermocouple.readCelsius();

  // PRIMERO LIMPIAMOS LA PANTALLA Y LUEGO IMPRIMIMOS LA TEMPERATURA

  lcd.clear();

  lcd.print(F("->TEMPERATURA<-"));

  lcd.setCursor( 3, 1 );

  lcd.print(t);

  // IMPRIMIR LA TEMPERATURA EN LA TERMINAL SERIAL

  Serial.print("C = ");

  Serial.println(t);

  // ESPERAR UN SEGUNDO ENTRE LAS LECTURAS

  delay(1000);

}


