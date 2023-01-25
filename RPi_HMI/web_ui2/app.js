var http = require('http');
var fs = require('fs');
var index = fs.readFileSync( 'index.html');

var SerialPort = require('serialport');

var port = new SerialPort('/dev/ttyACM0',{
	parser: SerialPort.parsers.readline('\n'),
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
});

port.pipe(parser);

var app = http.createServer(function(req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end(index);
});

var io = require('socket.io').listen(app);

io.on('connection', function(socket) {
    
    socket.on('lights',function(data){
        
        console.log( data );
        
        port.write( data.status );
    
    });

io.on('connection', function(socket) {
    
    socket.on('lights2',function(data){
        
        console.log( data );
        
        port.write( data.status );
    
    });

});
console.log("App started listening on port 3000. Go to http://localhost:3000 \nto access the web UI and control the leds.");
app.listen(3000);
