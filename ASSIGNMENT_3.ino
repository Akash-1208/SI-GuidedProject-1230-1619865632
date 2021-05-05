// (1):get the temperature ,humidity from the dth sensor

#include "DHT.h"

#define DHTPIN 4     
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  
}



//(2):get the light intensity form the LDR

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   int a=analogRead(15);
   Serial.println("the ldr value is");
   Serial.println(a);
delay(1000);
    
}




//(3):display the light intensity,temperature and humidity in oled display




#include "DHT.h"

#define DHTPIN 4     // Digital pin connected to the DHT sensor
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
 dht.begin();
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }

}
void loop() {
delay(6000);
int ldrval=analogRead(15);
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");

  }
  else
  {
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("%  Temperature: ");
  Serial.println(t);
  Serial.print("°C ");
  Serial.println(f);
  Serial.print("the LDR intensity is:");
  Serial.println(ldrval);
  display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.println(" ");
    display.print("the ldr intensity is ");
    display.println(ldrval);
    display.print("Humidity: ");
    display.print(h);
    display.println("%");
    display.print("Temparature: ");
    display.print(t);
    display.println("°C ");
    display.print(f);
    
    display.display();
}
}


//(4):control the lights based on light intensity (control the led's as an indication of light)


int LED_BUILTIN=16;
int freq =5000;
int ledChannel=0;
int resolution=8;
void setup()
{
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel);
  Serial.begin(9600);
}
void loop() {
    int a=analogRead(15);
   Serial.println("the ldr value is");
   Serial.println(a);

   if(a>=100&&a<1000)
   {
  
    {
        ledcWrite(ledChannel, 0);
    }
   }
   
   else if(a>=1001&&a<2000)
   {
  
    {
        ledcWrite(ledChannel, 100);
    }
   }
      else if(a>=2001&&a<=3000)
   {
   
    {
        ledcWrite(ledChannel, 175);
    }
   }
       else if(a>=3001)
   {
   
    {
        ledcWrite(ledChannel, 255);
    }
   }
   delay(1000);
}

//(5):control the fans based on the temperature and humidity parameters (control led's as an indication of fan)






int LED_BUILTIN=16;
int freq =5000;
int ledChannel=0;
int resolution=8;





#include "DHT.h"

#define DHTPIN 4     


#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
   ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel);

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);


  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  if((t>=0&&t<=20)||(h>=0&&h<=20))
  {
     
        ledcWrite(ledChannel, 50);
    
  }
  else if((t>=21&&t<=30)||(h>=21&&h<=40))
  {
     
    {
        ledcWrite(ledChannel, 100);
    }
  }
    else if((t>=31&&t<=40)||(h>=41&&h<=60))
  {
     
    {
        ledcWrite(ledChannel, 200);
    }
  }
     else if(t>=41||h>61)
  {
     
    {
        ledcWrite(ledChannel, 255);
    }
  }
}
