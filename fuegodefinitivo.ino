// LED's efecto fuego 10 y11, activada por in 4                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          pwm led9
int entrada = 13; //led iluminacion diurna
int estadopin=0; // variable estado pin
int ledPin1 = 9; //led 1 de fuego amarillo
int ledPin2 = 10; // led 2 de fuego rojo
void setup()
{
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(entrada, INPUT);
}
void loop() {
/* aqui realiza por numero aleatorio el parpadeo de los led de fuego rojo y amarillo
*/
estadopin =digitalRead (entrada);
if (estadopin==HIGH){
analogWrite(ledPin1, random(120)+135);
analogWrite(ledPin2, random(120)+135);
delay (random(80));
}
else
//si no se cumple, apaga la hoguera
{
  digitalWrite (ledPin1,LOW);
  digitalWrite (ledPin2,LOW);
}
}
