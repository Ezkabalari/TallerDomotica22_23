var http = require('http');
var dt = require('./gettimedate');

http.createServer(function (req, res) {
  res.writeHead(200, {'Content-Type': 'text/html'});
  res.write("La fecha y tiempo actuales son: "+dt.myDateTime());
  res.end('Hello World!');
}).listen(8080);
