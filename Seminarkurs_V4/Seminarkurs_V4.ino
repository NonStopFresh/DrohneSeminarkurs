#include <RCSwitch.h>
#include "Wire.h" 
#define MPU          0x68 // Alternatively set AD0 to HIGH  --> Address = 0x69
#define MPU6050_GYRO_CONFIG       0x1B
#define MPU6050_ACCEL_CONFIG      0x1C // Accelerometer Configuration Register
#define MPU6050_PWR_MGT_1         0x6B // Power Management 1 Register
#define MPU6050_INT_PIN_CFG       0x37 // Interrupt Pin / Bypass Enable Configuration Register
#define MPU6050_INT_ENABLE        0x38 // Interrupt Enable Register
#define MPU6050_LATCH_INT_EN      0x05 // Latch Enable Bit for Interrupt 
#define MPU6050_ACTL              0x07 // Active-Low Enable Bit
#define MPU6050_WOM_EN            0x06 // Wake on Motion Enable bit
#define MPU6050_WOM_THR           0x1F // Wake on Motion Threshold Register
#define MPU6050_MOT_DUR           0x20 // Motion Detection Duration Register
#define MPU6050_ACCEL_INTEL_CTRL  0x69 // Accelaration Interrupt Control Register
#define MPU6050_SIGNAL_PATH_RESET 0x68 // Signal Path Reset Register

unsigned long startTime;
unsigned long endTime;
unsigned long elapsedTime;

int loopcontrol1=1;
double volatile AccX,AccY,AccZ,Temp, ProcessAccX, ProcessAccY, ProcessAccZ,ProcessGyroX, ProcessGyroY, ProcessGyroZ,GyroX,GyroY,GyroZ;
//int ProcessGyroX, ProcessGyroY, ProcessGyroZ,GyroX,GyroY,GyroZ;
float FertigGyroX,FertigGyroX2;
float TestA,TestB,TestC, GyroreadingsinGradX, GyroreadingsinGradY, GyroreadingsinGradZ ;
float GyroreadingsinGradX1, GyroreadingsinGradY1, GyroreadingsinGradZ1 ;
float OffsetGyroX, OffsetGyroY, OffsetGyroZ,  OffsetGyroX1, OffsetGyroY1, OffsetGyroZ1;
float OffsetGyroXinsg,OffsetGyroYinsg,OffsetGyroZinsg;
int gyroZaehler=0;
int ACCData,C,GYROData;
int accregisterconf;

int LIM=100;
volatile bool accEvent = false;
float GyroXOfset, GyroYOfset,  GyroZOfset;
#include <Servo.h>

float GyroreadingsinGradX2=0;
bool Done;


#define ledRot 12
#define ledBlau 11 

#define MotorX1 3
#define MotorX2 4
#define MotorY1 5
#define MotorY2 6
int pot;
short potKalUsr;
//#define pot A3//A8       Extrerne Inputs
//#define potKalUsr A2//A9

#define inputBut 9
RCSwitch mySwitch = RCSwitch();
void setup() {
  
  pinMode(MotorX1, OUTPUT);
  pinMode(MotorX2, OUTPUT);
  pinMode(MotorY1, OUTPUT);
  pinMode(MotorY2, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(potKalUsr, INPUT);
  pinMode(inputBut,INPUT);
  pinMode(ledRot, OUTPUT);
  pinMode(ledBlau, OUTPUT);
  
  
  mySwitch.enableReceive(0); //daten transmit pin 0

  ACCData = 16384;
  GYROData = 256;

  Serial.begin(115200);
  accConfG();
  gyroConfig();
  Wire.begin();
  //pinmodes
  }


void loop(){
  delay(100);
  receive();
  startTime = millis();
  if(Done){
  accReadings();
  Userkalibrierung();
  }
  gyroReadings();

  //interruptloop();
  endTime = millis();
}

void accConfG(){
  
  Wire.begin();
  
  Serial.println("Starte Accelerometer konfiguration");
  Wire.beginTransmission(MPU);
  Wire.write(MPU6050_PWR_MGT_1);
  Wire.write(0);
  Serial.println("powermanagement RESET");
  delay(1000);
  Wire.endTransmission(true);
  Wire.beginTransmission(MPU);
  Wire.write(MPU6050_ACCEL_CONFIG);
  Wire.write(0b00000000);//Accelerometer auf +-2g einstellen(Bit 4 und 5)
  Wire.endTransmission(true);
  delay(1000);
  Serial.println("Accelerometer eingestellt");
  Wire.endTransmission(true);
  
}
void gyroConfig(){
  Wire.begin();
  Serial.println("Starte Gyroskop konfiguration");
  Wire.beginTransmission(MPU);
  Wire.write(MPU6050_GYRO_CONFIG);
  Wire.write(0b00000000);//gyro auf +- 250 gard pro sekunde )
  Serial.println("Gyroskop eingestellt");
  Wire.endTransmission(true);
  delay(1000);

}



