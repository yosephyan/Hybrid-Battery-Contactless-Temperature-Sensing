//This files contains definitions for the various
//#define's that are sprinkled and used through out the code 

//Defines the address of each sensor
#define SENSOR1 0xBE30
#define SENSOR2 0xBE33
#define SENSOR3 0xBE33

//Defines size of battery pack sampling 
#define BATTERY_PACK 20
//#define BATTERY_PACK 40


//Defines data output rate
//1 = 1 millisecond
#define DATA_OUTPUT_RATE 1000

//Defines refresh rate
//Choices:
 //MLX90640_0_5_HZ
 //MLX90640_1_HZ
 //MLX90640_2_HZ
 //MLX90640_4_HZ
 //MLX90640_8_HZ
 //MLX90640_16_HZ
 //MLX90640_32_HZ
 //MLX90640_64_HZ
//#define REFRESH_RATE MLX90640_0_5_HZ

//Defines sensor resolution
//Choices:
//MLX90640_ADC_16BIT
//MLX90640_ADC_17BIT
//MLX90640_ADC_18BIT
//MLX90640_ADC_19BIT

//define SENSOR_RESOLUTION MLX90640_ADC_18BIT


//Sensor pixel Diagram
//            R R R
//            o o o
//            w w w ........      1 1 1 1 1 1 1 1 1 1 2 2 2 2 
//            0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3
//  Column  0|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column  1|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column  2|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column  3|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column  4|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column  5|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column  6|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column  7|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column  8|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column  9|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 10|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 11|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 12|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 13|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 14|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 15|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 16|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 17|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 18|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 19|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 20|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 21|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 22|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 23|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 24|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 25|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 26|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 27|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 28|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 29|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 30|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
//  Column 31|_|_|_|x|_|_|x|_|_|_|_|_|x|_|_|_|_|x|_|x|_|_|_|_|
 
