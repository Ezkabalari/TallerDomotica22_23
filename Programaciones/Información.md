Utilizar las siguientes líneas para cambiar de fondo/imagen en cada pantalla de la nextion.

Si está configurada como fondo de la página: //Ésto es importante, de ser una imagen y no un fondo, los botones/textos/íconos... "Desaparecerán" de la pantalla
página.pic=id de la foto
menu.pic=0

Para mandar datos desde arduino:
Serial.print ("menu.pic=0");
Serial.write(0xff);
Serial.write(0xff);
Serial.write(0xff);

Si queremos cambiar el fondo según el valor del sensor:
if (valor_sensor >= valor_medio){
  Serial.print ("menu.pic=0");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}
else(){
  Serial.print ("menu.pic=1");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}
