#include <AFMotor.h> 
AF_DCMotor motor1(1, MOTOR12_64KHZ); // Motoru tanımlıyoruz.
AF_DCMotor motor2(2, MOTOR12_64KHZ); // Motoru tanımlıyoruz.
AF_DCMotor motor3(3, MOTOR34_64KHZ); // Motoru tanımlıyoruz.
AF_DCMotor motor4(4, MOTOR34_64KHZ); // Motoru tanımlıyoruz.
int gelenVeri;

float pwm = -0.0;// Lütfen - değer vererek fan hızını düşürün. Örnek -0,01 . Varsayılan 0.00
int motorcs1 = 44; //1. Motorun çalışma sıcaklığı
int motorcs2 = 60; //2. Motorun çalışma sıcaklığı
int motorcs3 = 53; //3. Motorun çalışma sıcaklığı
int motorcs4 = 57; //4. Motorun çalışma sıcaklığı
  
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
    //Burada sıcaklık değerini belirleyip, 1. Fanıma hız tanımlıyoruz
    if(gelenVeri=='w'){//80 ve üzeri
      hiz = 1+pwm;
      sicaklik = 80;
    }
    else if(gelenVeri=='e'){
      hiz = 1+pwm;
      sicaklik = 79;
      
    }
    else if(gelenVeri=='r'){
      hiz = 1+pwm;
      sicaklik = 78;
    }
    else if(gelenVeri=='t'){
      hiz = 1+pwm;
      sicaklik = 77;
    }
    else if(gelenVeri=='y'){
      hiz = 1+pwm;
      sicaklik = 76;
    }
    else if(gelenVeri=='u'){
      hiz = 1+pwm;//75
      sicaklik = 75;
    }
    else if(gelenVeri=='o'){
      hiz = 1+pwm;
      sicaklik = 74;
    }
    else if(gelenVeri=='p'){
      hiz = 1+pwm;
      sicaklik = 73;
    }
    else if(gelenVeri=='a'){
      hiz = 1+pwm;
      sicaklik = 72;
    }
    else if(gelenVeri=='s'){
      hiz = 1+pwm;
      sicaklik = 71;
    }
    else if(gelenVeri=='d'){
      hiz = 1+pwm;
      sicaklik = 70;
    }
    //70 Dereceden sonra etkin soğutma için 1 kullandık
    
    else if(gelenVeri=='f'){
      hiz = 0.80+pwm;
      sicaklik = 69;
    }
    else if(gelenVeri=='g'){
      hiz = 0.78+pwm;
      sicaklik = 68;
    }
    else if(gelenVeri=='h'){
      hiz = 0.77+pwm;
      sicaklik = 67;
    }
    else if(gelenVeri=='j'){
      hiz = 0.76+pwm;
      sicaklik = 66;
    }
    else if(gelenVeri=='k'){
      hiz = 0.75+pwm;
      sicaklik = 65;
    }
    else if(gelenVeri=='l'){
      hiz = 0.74+pwm;
      sicaklik = 64;
    }
    else if(gelenVeri=='i'){
      hiz = 0.73+pwm;
      sicaklik = 63;
    }
    else if(gelenVeri=='z'){
      hiz = 0.72+pwm;
      sicaklik = 62;
    }
    else if(gelenVeri=='x'){
      hiz = 0.71+pwm;
      sicaklik = 61;
    }
    else if(gelenVeri=='c'){
      hiz = 0.70+pwm;
      sicaklik = 60;
    }
    else if(gelenVeri=='v'){
      hiz = 0.67+pwm;
      sicaklik = 59;
    }
    else if(gelenVeri=='b'){
      hiz = 0.66+pwm;
      sicaklik = 58;
    }
    else if(gelenVeri=='n'){
      hiz = 0.65+pwm;
      sicaklik = 57;
    }
    else if(gelenVeri=='m'){
      hiz = 0.60+pwm;
      sicaklik = 56;
    }
    else if(gelenVeri=='0'){
      hiz = 0.60+pwm;
      sicaklik = 55;
    }
    else if(gelenVeri=='1'){
      hiz = 0.60+pwm;
      sicaklik = 54;
    }
    else if(gelenVeri=='2'){
      hiz = 0.60+pwm;
      sicaklik = 53;
    }
    else if(gelenVeri=='3'){
      hiz = 0.60+pwm;
      sicaklik = 52;
    }
    else if(gelenVeri=='4'){
      hiz = 0.60+pwm;
      sicaklik = 51;
    }
    else if(gelenVeri=='5'){
      hiz = 0.50+pwm;
      sicaklik = 49;
    }
    else if(gelenVeri=='6'){
      hiz = 0.50+pwm;
      sicaklik = 47;
    }
    else if(gelenVeri=='7'){
      hiz = 0.50+pwm;
      sicaklik = 45;
    }
    else if(gelenVeri=='8'){
      hiz = 0.50+pwm;
      sicaklik = 43;
    }
    else if(gelenVeri=='9'){//40 ve altı
      hiz = 0.50+pwm;
      sicaklik = 40;
    }

    //Sıcalık ve hız değerimizi aldıktan sonra Fan motorlarımızı çalıştıralım
    
    if(gelenVeri!='q'){//Seri porttan q değeri geldiğinde çalışmayı durdurur.
     //Motor 1 Çalışma
     if(sicaklik > motorcs1){
    motor1.setSpeed(130+(125*hiz));
    motor1.run(FORWARD);
     }
     else{
    motor1.setSpeed(0);
    motor1.run(RELEASE);
     }
    //Motor 2 Çalışma
    if(sicaklik > motorcs2){
      motor2.setSpeed(210+(45*hiz));
      motor2.run(FORWARD);
    }
    else{
      motor2.setSpeed(0);
      motor2.run(RELEASE);
    }
    //Motor 3 Çalışma
     if(sicaklik > motorcs3){
      motor3.setSpeed(210+(45*hiz));
      motor3.run(FORWARD);
     }
     else{
      motor3.setSpeed(0);
      motor3.run(RELEASE);
     }
    //Motor 4 Çalışma
     if(sicaklik > motorcs4){
      motor4.setSpeed(210+(45*hiz));
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
