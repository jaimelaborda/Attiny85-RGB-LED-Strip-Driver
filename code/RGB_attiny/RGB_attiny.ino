int blue = 11, red = 9, green = 10;
int c = 0, t_on = 0, t_off = 0;
float T = 0, f = 0;

void setup() {

  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
}

/*
 * Red to Yellow: Red: HIGH  and Green: FADE UP
 * Yellow to Green: Green: HIGH and Red: FADE UP
 * Green to Cyan: Green: HIGH and Blue: FADE UP
 * Cyan to Blue: Blue: HIGH and Green: FADE UP
 * Blue to Magenta: Blue: HIGH and Red: FADE UP
 * Magenta to Red: Red: HIGH and Blue: FADE UP
 */

void loop() {


WriteColor('r','b','g','u');
// Termina con BLUE al maximo y GREEN al minimo
WriteColor('r','b','g','d');
//Termina con RED al maximo y BLUE al minimo

  for(int i = 0; i<=255; i++){
    
    for(int j = 0; j<=10; j++){
      digitalWrite(blue,LOW);
      analogWrite(red,255-i);
      analogWrite(green,i);
      delayMicroseconds(2000);
    }
  }
//Termina con GREEN al maximo y RED al minimo 
}

void WriteColor(char high, char fade_up, char low, char adress){
  
  int led_H = 0, fade = 0, led_L = 0;

  switch(high){
  case 'r': led_H = red; break;
  case 'b': led_H = blue; break;
  case 'g': led_H = green; break;
  }
  
  switch(fade_up){
  case 'r': fade = red; break;
  case 'b': fade = blue; break;
  case 'g': fade = green; break;
  }

  switch(low){
  case 'r': led_L = red; break;
  case 'b': led_L = blue; break;
  case 'g': led_L = green; break;
  }
  
 // digitalWrite(led_H,HIGH);
 // digitalWrite(led_L,LOW);

  
  switch(adress){
  case 'u': c = 0; break; 
  case 'd': c = 255; break;
  }

  while(c<=255 && c>=0){

     
     f = 500; // 500 Herzts
     T = (1/f)*1000*1000;  // x1000 ya que está en us 
     //c = Ciclo de trabajo en %
     t_on = (c*T)/255; // Tiempo en alto
     t_off = T - t_on; // Tiempo en bajo

     if(adress == 'u'){ analogWrite(green,255-c); digitalWrite(red,LOW); }
     if(adress == 'd'){ analogWrite(red, 255-c); digitalWrite(green,LOW); }

     for(int i = 0; i<=10; i++){  
  
       digitalWrite(fade,HIGH);
       delayMicroseconds(t_on);
       digitalWrite(fade,LOW);
       delayMicroseconds(t_off);
      }
      
     switch(adress){
     case 'u': c++; break;
     case 'd': c--; break;
     }
  }
}

