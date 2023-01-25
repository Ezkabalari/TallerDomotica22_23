const express = require('express');
const app = express();
const http = require('http');
const server = http.createServer(app);
// create a serial port ref https://stackoverflow.com/questions/52541287/node-serialport-is-not-a-constructor
var SerialPort = require('serialport');
var port = new SerialPort('/dev/ttyACM0',{ baudRate: 9600});
var dt = require('./examples/gettimedate');
// create global  variable brightness
global.brightness = 0; 
app.get('/', (req, res) => {
     res.sendFile(__dirname + '/public/index.html');
     //console.log(dt.myDateTime()+' : Movement on slider requested.');
})

server.listen(8000, () => {
     console.log('listening on *:8080');
});
console.log("Servidor web arrancado. Visita la URL 'http://10.27.8.9:8000' in your Browser.");
