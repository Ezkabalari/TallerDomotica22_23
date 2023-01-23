const express = require(‘express’);
const app = express();
const http = require(‘http’);
const server = http.createServer(app);
app.get(‘/’, (req, res) => {
     res.sendFile(__dirname + ‘/public/index.html’);
})

server.listen(8080, () => {
     console.log(‘listening on *:8080’);
});
console.log(“Web Server Started go to ‘http://10.27.8.9:8080’ in your Browser.”);
