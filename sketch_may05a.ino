#include <AFMotor.h> 
AF_DCMotor motor1(1, MOTOR12_64KHZ); // Motoru tanımlıyoruz.
AF_DCMotor motor2(2, MOTOR12_64KHZ); // Motoru tanımlıyoruz.
AF_DCMotor motor3(3, MOTOR34_64KHZ); // Motoru tanımlıyoruz.
AF_DCMotor motor4(4, MOTOR34_64KHZ); // Motoru tanımlıyoruz.
int gelenVeri;

//Motor çalışma sıcaklığı, Verilen değerde motor otomatik çalışmaya başlar
int motorcs1 = 44;
int motorcs2 = 60;
int motorcs3 = 53;
int motorcs4 = 57;

//Motor başlangıç çalışma frekansı, Max 255
float motorpwm1 = 190;
float motorpwm2 = 185;
float motorpwm3 = 185;
float motorpwm4 = 185;

int fanSpeed(float fanHizi, float pwm){
  //Başlangıç fan hızını referans alarak pwm ile bir fan hızı verir.
  //Otomatik fan hızı belirlemek için kullanacağız
  float hiz = 255 - fanHizi;
  hiz = hiz * pwm;
  return fanHizi + hiz;
}  

void setup() {
  Serial.begin(9600);
      motor1.setSpeed(190);
      motor1.run(FORWARD);
      motor2.setSpeed(0);
      motor2.run(RELEASE);
      motor3.setSpeed(0);
      motor3.run(RELEASE);
      motor4.setSpeed(0);
      motor4.run(RELEASE);
      
}

void loop() {
  float hiz = 1;
  int sicaklik = 0;
  if(Serial.available()){
    if(gelenVeri=Serial.read());
    if(gelenVeri=='w'){//80 ve üzeri
      hiz = 1;
      sicaklik = 80;
    }
    else if(gelenVeri=='e'){
      hiz = 0.97;
      sicaklik = 79;
      
    }
    else if(gelenVeri=='r'){
      hiz = 0.94;
      sicaklik = 78;
    }
    else if(gelenVeri=='t'){
      hiz = 0.91;
      sicaklik = 77;
    }
    else if(gelenVeri=='y'){
      hiz = 0.88;
      sicaklik = 76;
    }
    else if(gelenVeri=='u'){
      hiz = 0.85;//75
      sicaklik = 75;
    }
    else if(gelenVeri=='o'){
      hiz = 0.82;
      sicaklik = 74;
    }
    else if(gelenVeri=='p'){
      hiz = 0.79;
      sicaklik = 73;
    }
    else if(gelenVeri=='a'){
      hiz = 0.76;
      sicaklik = 72;
    }
    else if(gelenVeri=='s'){
      hiz = 0.73;
      sicaklik = 71;
    }
    else if(gelenVeri=='d'){
      hiz = 0.70;
      sicaklik = 70;
    }
    
    else if(gelenVeri=='f'){
      hiz = 0.67;
      sicaklik = 69;
    }
    else if(gelenVeri=='g'){
      hiz = 0.64;
      sicaklik = 68;
    }
    else if(gelenVeri=='h'){
      hiz = 0.61;
      sicaklik = 67;
    }
    else if(gelenVeri=='j'){
      hiz = 0.58;
      sicaklik = 66;
    }
    else if(gelenVeri=='k'){
      hiz = 0.55;
      sicaklik = 65;
    }
    else if(gelenVeri=='l'){
      hiz = 0.52;
      sicaklik = 64;
    }
    else if(gelenVeri=='i'){
      hiz = 0.48;
      sicaklik = 63;
    }
    else if(gelenVeri=='z'){
      hiz = 0.45;
      sicaklik = 62;
    }
    else if(gelenVeri=='x'){
      hiz = 0.42;
      sicaklik = 61;
    }
    else if(gelenVeri=='c'){
      hiz = 0.39;
      sicaklik = 60;
    }
    else if(gelenVeri=='v'){
      hiz = 0.36;
      sicaklik = 59;
    }
    else if(gelenVeri=='b'){
      hiz = 0.33;
      sicaklik = 58;
    }
    else if(gelenVeri=='n'){
      hiz = 0.30;
      sicaklik = 57;
    }
    else if(gelenVeri=='m'){
      hiz = 0.27;
      sicaklik = 56;
    }
    else if(gelenVeri=='0'){
      hiz = 0.24;
      sicaklik = 55;
    }
    else if(gelenVeri=='1'){
      hiz = 0.21;
      sicaklik = 54;
    }
    else if(gelenVeri=='2'){
      hiz = 0.18;
      sicaklik = 53;
    }
    else if(gelenVeri=='3'){
      hiz = 0.15;
      sicaklik = 52;
    }
    else if(gelenVeri=='4'){
      hiz = 0.12;
      sicaklik = 51;
    }
    else if(gelenVeri=='5'){
      hiz = 0.09;
      sicaklik = 49;
    }
    else if(gelenVeri=='6'){
      hiz = 0.06;
      sicaklik = 47;
    }
    else if(gelenVeri=='7'){
      hiz = 0.03;
      sicaklik = 45;
    }
    else if(gelenVeri=='8'){
      hiz = 0.02;
      sicaklik = 43;
    }
    else if(gelenVeri=='9'){//40 ve altı
      hiz = 0.01;
      sicaklik = 40;
    }

    //Sıcalık ve hız değerimizi aldıktan sonra Fan motorlarımızı çalıştıralım
    
    if(gelenVeri!='q'){//Seri porttan q değeri geldiğinde çalışmayı durdurur.
     //Motor 1 Çalışma
     if(sicaklik > motorcs1){
    motor1.setSpeed(fanSpeed(motorpwm1, hiz));
    motor1.run(FORWARD);
     }
     else{
    motor1.setSpeed(0);
    motor1.run(RELEASE);
     }
    //Motor 2 Çalışma
    if(sicaklik > motorcs2){
      motor2.setSpeed(fanSpeed(motorpwm2, hiz));
      motor2.run(FORWARD);
    }
    else{
      motor2.setSpeed(0);
      motor2.run(RELEASE);
    }
    //Motor 3 Çalışma
     if(sicaklik > motorcs3){
      motor3.setSpeed(fanSpeed(motorpwm3, hiz));
      motor3.run(FORWARD);
     }
     else{
      motor3.setSpeed(0);
      motor3.run(RELEASE);
     }
    //Motor 4 Çalışma
     if(sicaklik > motorcs4){
      motor4.setSpeed(fanSpeed(motorpwm4, hiz));
      motor4.run(FORWARD);
     }
     else{
      motor4.setSpeed(0);
      motor4.run(RELEASE);
     }    
   }
   
   else{
    hiz = 0;
    motor1.setSpeed(0);   // Motor hızını ayarlıyoruz. (Maks 255)
    motor1.run(RELEASE);   // ileri yönde dön
    motor2.setSpeed(0);
    motor2.run(RELEASE);
    motor3.setSpeed(0);
    motor3.run(RELEASE);
    motor4.setSpeed(0);
    motor4.run(RELEASE);
   }

  }
}
