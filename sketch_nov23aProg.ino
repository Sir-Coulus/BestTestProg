#include <DallasTemperature.h>
#include <OneWire.h>

int detectTemperature();
int temperature = 0; // Глобальная переменная для хранения значение температуры с датчика DS18B20

OneWire oneWire(15);                                       // вход датчиков 18b20, аналоговый А1, он же 15 цифровой 
DallasTemperature ds(&oneWire);    

void setup() {
  Serial.begin(9600);
  ds.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  Serial.println(temperature);

  digitalWrite(LED_BUILTIN, HIGH); 
  delay (1000);
  digitalWrite(LED_BUILTIN, LOW); 
  delay (1000);
  ds.requestTemperatures();                               // считываем температуру с датчиков, на это требуется 750мс
  
  Serial.print("Sensor 0: ");
  Serial.print(ds.getTempCByIndex(0));                    // отправляем температуру
  Serial.println("C"); 
}  
