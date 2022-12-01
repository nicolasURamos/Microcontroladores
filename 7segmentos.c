//bibliotecas utilizadas
#include <avr/io.h>
#include <avr/interrupt.h>


//Variaveis globais para definir as portas
int portA = 2;
int portB = 3;
int portC = 4;
int portD = 5;
int portE = 6;
int portF = 7;
int portG = 8;
int aux = 1;
int timer_overflow = 0;


void reset(){
  digitalWrite(portA, HIGH);
  digitalWrite(portB, HIGH);
  digitalWrite(portC, HIGH);
  digitalWrite(portD, HIGH);
  digitalWrite(portE, HIGH);
  digitalWrite(portF, HIGH);
  digitalWrite(portG, HIGH);

}

void H() {
  reset();
  digitalWrite(portB, LOW);
  digitalWrite(portC, LOW);
  digitalWrite(portF, LOW);
  digitalWrite(portE, LOW);
  digitalWrite(portG, LOW);
}

void E() {
  reset();
  digitalWrite(portA, LOW);
  digitalWrite(portD, LOW);
  digitalWrite(portE, LOW);
  digitalWrite(portF, LOW);
  digitalWrite(portG, LOW);
}

void L() {
  reset();
  digitalWrite(portD, LOW);
  digitalWrite(portE, LOW);
  digitalWrite(portF, LOW);
}

void O() {
  reset();
  digitalWrite(portA, LOW);
  digitalWrite(portB, LOW);
  digitalWrite(portC, LOW);
  digitalWrite(portD, LOW);
  digitalWrite(portE, LOW);
  digitalWrite(portF, LOW);
}

void TR(){
  reset();
  digitalWrite(portG, LOW);

}
void A() {
  reset();
  digitalWrite(portA, LOW);
  digitalWrite(portB, LOW);
  digitalWrite(portC, LOW);
  digitalWrite(portF, LOW);
  digitalWrite(portE, LOW);
  digitalWrite(portG, LOW);
}

void T() {
  reset();
  digitalWrite(portA, LOW);
  digitalWrite(portB, LOW);
  digitalWrite(portC, LOW);
}

void num3() {
  reset();
  digitalWrite(portA, LOW);
  digitalWrite(portB, LOW);
  digitalWrite(portC, LOW);
  digitalWrite(portD, LOW);
  digitalWrite(portG, LOW);
}

void num2() {
  reset();
  digitalWrite(portA, LOW);
  digitalWrite(portB, LOW);
  digitalWrite(portD, LOW);
  digitalWrite(portE, LOW);
  digitalWrite(portG, LOW);
}

void num8() {
  reset();
  digitalWrite(portA, LOW);
  digitalWrite(portB, LOW);
  digitalWrite(portC, LOW);
  digitalWrite(portD, LOW);
  digitalWrite(portE, LOW);
  digitalWrite(portF, LOW);
  digitalWrite(portG, LOW);
}

void P() {
  reset();
  digitalWrite(portA, LOW);
  digitalWrite(portB, LOW);
  digitalWrite(portE, LOW);
  digitalWrite(portF, LOW);
  digitalWrite(portG, LOW);
}

void setup(){
  pinMode(portA,OUTPUT);
  pinMode(portB,OUTPUT);
  pinMode(portC,OUTPUT);
  pinMode(portD,OUTPUT);
  pinMode(portE,OUTPUT);
  pinMode(portF,OUTPUT);
  pinMode(portG,OUTPUT);

  //utilizando timer1
  TCCR1A = 0;
  TCCR1B = 0; //zerando o reg para limpar
  TCCR1B|=(1<<CS12); //setando prescaler para 256
  TCNT1 = 3035;
  TIMSK1 = 1; //habilitando interrupção

  //configurando int0 int1
  EICRA|= (1<<ISC11)|(0<<ISC10)|(1<<ISC01)|(0<<ISC00);
  //EICRA = 0b1010;
  //EICRA = 10;

  EIMSK|= (1<<INT1)|(1<<INT0);
  //EIMSK = 0b11;
  //EIMSK = 3;

  //configurando pinchange
  PCICR=0;
  PCICR|=(1<<PCIE0);

  PCMSK0 = 0;
  PCMSK0|=(1<<PCINT7);


  sei(); //interrupção global

  reset();
}

void loop(){
  if(aux > 12){
    aux = 1;
  }
  switch(aux){
    
    case 1:
    
    H();
    
  
    break;

     case 2:
    E();
    
    break;

     case 3:
    L();
     

    break;

    case 4:
    L();
     
    break;

     case 5:
    O();
    
     break;

   case 6:
    TR();
    
     break;

     case 7:
    A();
    
     break;

     case 8:
    T();
    
     break;

     case 9:
    num3();
    
     break;

     case 10:
    num2();
    
     break;

     case 11:
    num8();
    
     break;

     case 12:
    P();
    
     break;
    
    
  }

}

ISR(TIMER1_OVF_vect){  //definindo a subrotina
  timer_overflow++;
  if(timer_overflow == 5){
    aux++;
    timer_overflow=0;
  }

}

ISR(INT0_vect){
  aux--;
  if(aux<1){
    aux=12;
  }
}

ISR(INT1_vect){
  aux++;
  if(aux>12){
    aux=1;
  }
}

ISR(PCINT0_vect){
  aux=1;
}

/*calculo prescaler

tempo ciclo X prescaller X vezes pr estorar
1/16milhoes=62,5ns
overflow = 65535
começar o contador no :3035*/
