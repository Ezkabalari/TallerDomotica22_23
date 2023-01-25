// declare pin to which the led is connected
var led = 13;
var express = require('express');
app = express();
server = require('http').createServer(app);
io = require('socket.io')(server);
var SerialPort = require("serialport")
// set COM port and baud rate
var serialPort = new SerialPort("/dev/ttyACM0", { baudRate: 9600 });

// start server
server.listen(8000);

io.sockets.on('conecction', function (socket) {
	socket.on('led', function (data) {
		brightness = data.value;
		buf.writeUInt8(brightness, 0);
		serialPort.write(buf);
		io.sockets.emit('led', {value: brightness});
	});
	socket.emit('led', {value: brightness});
});

// print something on console
console.log("Web Server Started go to 'http://localhost:8000' in your Browser.");
