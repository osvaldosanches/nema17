//Inclui a biblioteca para trabalhar com o motor
//junho/2023
#include <AccelStepper.h>
 
//Pinos de conexão e instância do motor
const int DIR = 4;
const int STEP = 7;
int comandoSubida = 6; 
int acaoSubida; 
 
#define InterfaceMotor 1
 
AccelStepper Stepper(InterfaceMotor, STEP, DIR);

//Define
//velocidade máxima
//fator de aceleração,
//velocidade inicial
//posição desejada 
//negativo desce a cortina - positivo sobre a cortina (de frente para o eixo - sentido horário)
void setup() {
  Stepper.setMaxSpeed(100);   
  Stepper.setAcceleration(100);   
  Stepper.setSpeed(100);  
  Stepper.moveTo(-1800);    
  //Serial.begin(9600);
  pinMode(comandoSubida, INPUT);
}

// Fluxo - mudar a direção quando o motor atingir a posição
void loop() {
  
  acaoSubida = digitalRead(comandoSubida);
  
  if (Stepper.distanceToGo() == 0 && acaoSubida == 1){

    if(-Stepper.currentPosition()>0){

      Stepper.moveTo(1800);
      
    }else{

      Stepper.moveTo(-1800);
    }

  }
  
  // move o motor um passo
  Stepper.run();
  
}
