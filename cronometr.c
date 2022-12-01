//incompleto

//bibliotecas utilizadas
#include <avr/io.h>
#include <avr/interrupt.h>


//Variaveis globais para definir as portas
//TIMER1
int portA = 2;
int portB = 3;
int portC = 4;
int portD = 5;
int portE = 6;
int portF = 7;
int portG = 8;

//TIMER2
int portA2 = 40;
int portB2 = 41;
int portC2 = 42;
int portD2 = 43;
int portE2 = 44;
int portF2 = 45;
int portG2 = 46;


int aux = 1;
int timer_overflow1 = 0;
int timer_overflow2 = 0;


void reset(){
  digitalWrite(portA, HIGH);
  digitalWrite(portB, HIGH);
  digitalWrite(portC, HIGH);
  digitalWrite(portD, HIGH);
  digitalWrite(portE, HIGH);
  digitalWrite(portF, HIGH);
  digitalWrite(portG, HIGH);
  }

void reset2(){
  digitalWrite(portA2, HIGH);
  digitalWrite(portB2, HIGH);
  digitalWrite(portC2, HIGH);
  digitalWrite(portD2, HIGH);
  digitalWrite(portE2, HIGH);
  digitalWrite(portF2, HIGH);
  digitalWrite(portG2, HIGH);


}



void setup(){
  pinMode(portA,OUTPUT);
  pinMode(portB,OUTPUT);
  pinMode(portC,OUTPUT);
  pinMode(portD,OUTPUT);
  pinMode(portE,OUTPUT);
  pinMode(portF,OUTPUT);
  pinMode(portG,OUTPUT);

  pinMode(portA2,OUTPUT);
  pinMode(portB2,OUTPUT);
  pinMode(portC2,OUTPUT);
  pinMode(portD2,OUTPUT);
  pinMode(portE2,OUTPUT);
  pinMode(portF2,OUTPUT);
  pinMode(portG2,OUTPUT);

  //utilizando timer1
  TCCR1A = 0;
  TCCR1B = 0; //zerando o reg para limpar
  TCCR1B|=(1<<CS12); //setando prescaler para 256
  TCNT1 = 3085;
  

  TCCR2A = 0;
  TCCR2B = 0;
  TCCR2B |= (1<<CA20) | (1<<CA21) | (1<<CA22); //setando para 1024
  TCNT2 = 62;
  

  sei(); //interrupção global

  reset();
}

void n1(){

  //numeros com display
}
void n2(){

  //numeros com display
}
void n3(){

  //numeros com display
}
void n4(){

  //numeros com display
}
void n5(){

  //numeros com display
}
void n6(){

  //numeros com display
}
void n7(){

  //numeros com display
}
void n8(){

  //numeros com display
}
void n9(){

  //numeros com display
}


void loop(){
  if(aux > 9){
    aux = 1;
  }
  switch(aux){
    
    case 1:
    
    n1();
    
  
    break;

     case 2:
    n2();
    
    break;

     case 3:
    n3();
     

    break;

    case 4:
    n4();
     
    break;

     case 5:
    n5();
    
     break;

   case 6:
    n6();
    
     break;

     case 7:
    n7();
    
     break;

     case 8:
    n8();
    
     break;

     case 9:
    n9();
     break;
    
    
  }

}

ISR(TIMER1_OVF_vect){  //definindo a subrotina
  timer_overflow1++;


}

ISR(TIMER2_OVF_vect){
  timer_overflow2++

}




/*
tempo ciclo X prescaller X vezes pr estorar


----------------------------------------------------
TIMER1: 16bits = 1/16milhoes = 62,5ns = 0,0000000625  (x of 0,000016) menor q timer2
overflow:65535
------ 62450
prescaller:256
=1,04856
timer start = 3.085
= 1seg
conta o valor que mostra
----------------------------------------------------
TIMER2: 8bits  =  1/16milhoes = 62,5ns = 0,0000000625  (0,000016

0,000064 x overflow
								
overflow:200
prescaller:1024
=0,016384 (1estouro)
61 x 256
62 estouros = +-1seg
*/
