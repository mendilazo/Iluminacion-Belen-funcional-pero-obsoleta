// iluminacion general (9)+estrella(10)+salida fuego (13)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         pwm led9
int ledPin = 9; //led iluminacion diurna
int ledPin1 = 10; //led iluminacion estrellas
int analogPin = 0; // potenciometro regulacion tiempo
int salida = 13; //salida exterior de fuego
int punto=0; //variable de punto actual
int disparo=50; //valor de referencia de salida fuego
void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(ledPin1, OUTPUT);
pinMode(salida, OUTPUT);
}
void loop() 
{
while (analogRead (analogPin) < 20)
{
  digitalWrite (ledPin1,LOW);
  digitalWrite (ledPin,LOW);
  digitalWrite (salida,LOW);
}
  /*
primer punto (amanecer,azimut)
*/
for (int i=0; i<=255; i++) // incremento de valor de i
{
int i2=255-i;
analogWrite (ledPin1, i2);
  analogWrite(ledPin, i); // configura el nivel brillo con el valor de i
delay(delayVal()); // espera un tiempo
int (punto=i);
if (punto <= (disparo)) {
digitalWrite (salida,HIGH);
}
if (punto >= (disparo)) {
digitalWrite (salida,LOW);
}
}
for (int i=0; i<=255; i++) // incremento de valor de i
{
delay(delayVal()); // espera un tiempo
int (punto=i);

}
/*
segundo punto (azimut, ocaso)
*/
for (int i=255; i>=0; i--) // decrementa el valor de i
{
int i2=255-i;
analogWrite (ledPin1, i2);
  analogWrite(ledPin, i); // configura el nivel de brillo con el valor de i
delay(delayVal()); // espera un tiempo
int (punto=i);
if (punto <= (disparo)) {
digitalWrite (salida,HIGH);
}
if (punto >= (disparo)) {
digitalWrite (salida,LOW);
}
}
/*
tercer punto (ocaso,medianoche)
*/
for (int i=0; i<=255; i++) // incremento de valor de i
{
delay(delayVal()); // espera un tiempo
int (punto=i);

}
/*
cuarto punto (medianoche,amanecer)
*/
for (int i=255; i>=0; i--) // decrementa el valor de i
{
delay(delayVal()); // espera un tiempo
int (punto=i);

}

}
int delayVal() // Método para recoger el tiempo de retardo
{int v; // crea una variable temporal (local)
v = analogRead(analogPin); // lee valor analogico
v /= 4;
// convierte el valor de 0-1024 a 0-128
return v; // devuelve el valor v

}





