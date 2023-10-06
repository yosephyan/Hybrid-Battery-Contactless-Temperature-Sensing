#include <Adafruit_MLX90640.h>
#include "one_row.h"
#include "Sensors.h"
#include "definitions.h"

Adafruit_MLX90640 mlx1;
Adafruit_MLX90640 mlx2;
//Adafruit_MLX90640 mlx3;


float frame[32*24]; // buffer for full frame of temperatures
float mlxarray[6*40];



//determines how many rows sensor is picking up
int row = 0;

  
// uncomment *one* of the below
#define PRINT_TEMPERATURES
//#define PRINT_ASCIIART

void setup() {
  while (!Serial) delay(10);
  Serial.begin(115200);
  delay(100);


 /*for (int h=0; h<24; h++) {
        for (int w = 0; w < 32; w++) {
            frame[h * 32 + w] = w;
        }
    }
*/


  //address data
  uint16_t readData = 0;
  
  Serial.println("Adafruit MLX90640 Simple Test");
  if (! mlx1.begin(0xBE30, &Wire)) {
    Serial.println("MLX90640 not found!");
    while (1) delay(10);
  }
  Serial.println("Found Adafruit MLX90640");

  
  //mlx1.setMode(MLX90640_INTERLEAVED);
  mlx1.setMode(MLX90640_CHESS);
  

  mlx1.setResolution(MLX90640_ADC_18BIT);
  mlx90640_resolution_t res = mlx1.getResolution();
  
  mlx1.setRefreshRate(MLX90640_2_HZ);
  mlx90640_refreshrate_t rate = mlx1.getRefreshRate();
  
  switch (rate) {
    case MLX90640_0_5_HZ: Serial.println("0.5 Hz"); break;
    case MLX90640_1_HZ: Serial.println("1 Hz"); break; 
    case MLX90640_2_HZ: Serial.println("2 Hz"); break;
    case MLX90640_4_HZ: Serial.println("4 Hz"); break;
    case MLX90640_8_HZ: Serial.println("8 Hz"); break;
    case MLX90640_16_HZ: Serial.println("16 Hz"); break;
    case MLX90640_32_HZ: Serial.println("32 Hz"); break;
    case MLX90640_64_HZ: Serial.println("64 Hz"); break;
  }
  

Serial.println("Adafruit MLX90640 Simple Test");
  if (! mlx2.begin(SENSOR2, &Wire)) {
    Serial.println("MLX90640 not found!");
    while (1) delay(10);
  }
   MLX90640_I2CRead(SENSOR2, 0x240F, 2, &readData);
            Serial.print("Found I2C 0x");  
  Serial.println(readData, HEX);

  //sensor 2
mlx2.setMode(MLX90640_CHESS);
  

  //Sensor 2
 mlx2.setResolution(MLX90640_ADC_18BIT);
   res = mlx2.getResolution();
  

  mlx2.setRefreshRate(MLX90640_2_HZ);
  Serial.print("Current frame rate: ");
   rate = mlx2.getRefreshRate();
  switch (rate) {
    case MLX90640_0_5_HZ: Serial.println("0.5 Hz"); break;
    case MLX90640_1_HZ: Serial.println("1 Hz"); break; 
    case MLX90640_2_HZ: Serial.println("2 Hz"); break;
    case MLX90640_4_HZ: Serial.println("4 Hz"); break;
    case MLX90640_8_HZ: Serial.println("8 Hz"); break;
    case MLX90640_16_HZ: Serial.println("16 Hz"); break;
    case MLX90640_32_HZ: Serial.println("32 Hz"); break;
    case MLX90640_64_HZ: Serial.println("64 Hz"); break;
  }
}

void loop() {
 int index = 0;          //index = index of array

 
   // Activate Sensor 1
  delay(500);
  if (mlx1.getFrame(frame) != 0) {
    Serial.println("Failed");
    return;
  }
  //Serial.println();


//Sensor 1
index = calibrate_sensor_type1(mlxarray, frame, index);


   // Activate Sensor 2
  delay(500);
  if (mlx2.getFrame(frame) != 0) {
    Serial.println("Failed");
    return;
  }
  //Serial.println();


//Sensor 2
index = calibrate_sensor_type2(mlxarray, frame, index);

/*
   // Activate Sensor 3
  delay(500);
  if (mlx3.getFrame(frame) != 0) {
    Serial.println("Failed");
    return;
  }
  Serial.println();
*/
//Sensor 3
//index = calibrate_sensor_type1(mlxarray, frame, index);
//Serial.println();
Serial.println();

  //prints final output array into serial monitor
  for(int q = 0; q<6*BATTERY_PACK; q++) {
    float t = mlxarray[q];

  #ifdef PRINT_TEMPERATURES
      Serial.print(t, 2);
      Serial.print(",");
  #endif
  
  #ifdef PRINT_ASCIIART
      char c = '&';
      if (t < 20) c = ' ';
      else if (t < 23) c = '.';
      else if (t < 25) c = '-';
      else if (t < 27) c = '*';
      else if (t < 29) c = '+';
      else if (t < 31) c = 'x';
      else if (t < 33) c = '%';
      else if (t < 35) c = '#';
      else if (t < 37) c = 'X';
      Serial.print(c);
      Serial.print("     ");
  #endif
   
   //if (q % 6 == 5 || q == 5) {
    //Serial.println();
     //}
    }
   



  delay (DATA_OUTPUT_RATE); //milliseconds delay
}
  
