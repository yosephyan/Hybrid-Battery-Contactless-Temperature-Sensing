#include "definitions.h"
#include <Adafruit_MLX90640.h>

//-------------------------------------------------------------
//Function "MLX90640_I2CRead" reads the value that is located 
//at a given address  
//-------------------------------------------------------------


//Read a number of words from startAddress. Store into Data array.
//Returns 0 if successful, -1 if error
int MLX90640_I2CRead(uint8_t _deviceAddress, unsigned int startAddress, unsigned int nWordsRead, uint16_t *data)
{

  //Caller passes number of 'unsigned ints to read', increase this to 'bytes to read'
  uint16_t bytesRemaining = nWordsRead * 2;

  //It doesn't look like sequential read works. Do we need to re-issue the address command each time?

  uint16_t dataSpot = 0; //Start at beginning of array

  //Setup a series of chunked I2C_BUFFER_LENGTH byte reads
  while (bytesRemaining > 0)
  {
    Wire.beginTransmission(_deviceAddress);
    Wire.write(startAddress >> 8); //MSB
    Wire.write(startAddress & 0xFF); //LSB
    if (Wire.endTransmission(false) != 0) //Do not release bus
    {
      //Serial.println("No ack read");
      return (0); //Sensor did not ACK
    }

    uint16_t numberOfBytesToRead = bytesRemaining;
    if (numberOfBytesToRead > I2C_BUFFER_LENGTH) numberOfBytesToRead = I2C_BUFFER_LENGTH;

    Wire.requestFrom((uint8_t)_deviceAddress, numberOfBytesToRead);
    if (Wire.available())
    {
      for (uint16_t x = 0 ; x < numberOfBytesToRead / 2; x++)
      {
        //Store data into array
        data[dataSpot] = Wire.read() << 8; //MSB
        data[dataSpot] |= Wire.read(); //LSB

        dataSpot++;
      }
    }

    bytesRemaining -= numberOfBytesToRead;

    startAddress += numberOfBytesToRead / 2;
  }

  return (0); //Success
}



//Adafruit_MLX90640 mlx1;
//Adafruit_MLX90640 mlx2;
//Adafruit_MLX90640 mlx3;

/*
//-------------------------------------------------------------
//Function "Sensor1_setup" Sets up sensor 1 and ensures
//its working and functioning
//-------------------------------------------------------------

void Sensor1_setup (){
 //address data
  uint16_t readData = 0;
  
  Serial.println("Adafruit MLX90640 Simple Test");
  if (! mlx1.begin(0xBE30, &Wire)) {
    Serial.println("MLX90640 not found!");
    while (1) delay(10);
  }
  Serial.println("Found Adafruit MLX90640");

  Serial.print("Serial number: ");
  Serial.print(mlx1.serialNumber[0], HEX);
  Serial.print(mlx1.serialNumber[1], HEX);
  Serial.println(mlx1.serialNumber[2], HEX);
  
  //mlx1.setMode(MLX90640_INTERLEAVED);
  mlx1.setMode(MLX90640_CHESS);
  Serial.print("Current mode: ");
  if (mlx1.getMode() == MLX90640_CHESS) {
    Serial.println("Chess");
  } else {
    Serial.println("Interleave");    
  }

  mlx1.setResolution(MLX90640_ADC_18BIT);
  Serial.print("Current resolution: ");
  mlx90640_resolution_t res = mlx1.getResolution();
  switch (res) {
    case MLX90640_ADC_16BIT: Serial.println("16 bit"); break;
    case MLX90640_ADC_17BIT: Serial.println("17 bit"); break;
    case MLX90640_ADC_18BIT: Serial.println("18 bit"); break;
    case MLX90640_ADC_19BIT: Serial.println("19 bit"); break;
  }

  mlx1.setRefreshRate(MLX90640_2_HZ);
  Serial.print("Current frame rate: ");
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
  
}
*/

/*
//-------------------------------------------------------------
//Function "Sensor2_setup" Sets up sensor 2 and ensures
//its working and functioning
//-------------------------------------------------------------

void Sensor2_setup (){
  //address data
  uint16_t readData = 0;
  
  Serial.println("Adafruit MLX90640 Simple Test");
  if (! mlx2.begin(SENSOR2, &Wire)) {
    Serial.println("MLX90640 not found!");
    while (1) delay(10);
  }


//check if address have been changed 
  MLX90640_I2CRead(SENSOR2, 0x240F, 2, &readData);
            Serial.print("Found I2C 0x");  
  Serial.println(readData, HEX);


//Select Chess or Interleaved Mode
  //mlx2.setMode(MLX90640_INTERLEAVED);
  mlx2.setMode(MLX90640_CHESS);
  Serial.print("Current mode: ");
  if (mlx2.getMode() == MLX90640_CHESS) {
    Serial.println("Chess");
  } else {
    Serial.println("Interleave");    
  }


  mlx2.setResolution(MLX90640_ADC_18BIT);
  Serial.print("Current resolution: ");
  mlx90640_resolution_t res = mlx2.getResolution();
  switch (res) {
    case MLX90640_ADC_16BIT: Serial.println("16 bit"); break;
    case MLX90640_ADC_17BIT: Serial.println("17 bit"); break;
    case MLX90640_ADC_18BIT: Serial.println("18 bit"); break;
    case MLX90640_ADC_19BIT: Serial.println("19 bit"); break;
  }

  mlx2.setRefreshRate(MLX90640_2_HZ);
  Serial.print("Current frame rate: ");
  mlx90640_refreshrate_t rate = mlx2.getRefreshRate();
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

//-------------------------------------------------------------
//Function "Sensor3_setup" Sets up sensor 3 and ensures
//its working and functioning
//-------------------------------------------------------------

void Sensor3_setup (){
  //address data
  uint16_t readData = 0;
  
  Serial.println("Adafruit MLX90640 Simple Test");
  if (! mlx3.begin(SENSOR3, &Wire)) {
    Serial.println("MLX90640 not found!");
    while (1) delay(10);
  }


//check if address have been changed 
  MLX90640_I2CRead(SENSOR3, 0x240F, 2, &readData);
            Serial.print("Found I2C 0x");  
  Serial.println(readData, HEX);


//Select Chess or Interleaved Mode
  //mlx3.setMode(MLX90640_INTERLEAVED);
  mlx3.setMode(MLX90640_CHESS);
  Serial.print("Current mode: ");
  if (mlx3.getMode() == MLX90640_CHESS) {
    Serial.println("Chess");
  } else {
    Serial.println("Interleave");    
  }


  mlx3.setResolution(MLX90640_ADC_18BIT);
  Serial.print("Current resolution: ");
  mlx90640_resolution_t res = mlx3.getResolution();
  switch (res) {
    case MLX90640_ADC_16BIT: Serial.println("16 bit"); break;
    case MLX90640_ADC_17BIT: Serial.println("17 bit"); break;
    case MLX90640_ADC_18BIT: Serial.println("18 bit"); break;
    case MLX90640_ADC_19BIT: Serial.println("19 bit"); break;
  }

  mlx3.setRefreshRate(MLX90640_2_HZ);
  Serial.print("Current frame rate: ");
  mlx90640_refreshrate_t rate = mlx3.getRefreshRate();
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

*/
