
var http = require('http');
const fs = require('fs');

var index = fs.readFileSync('index.html');

const { SerialPort } = require('serialport')
const { ReadlineParser } = require('@serialport/parser-readline');
const { Socket } = require('dgram');
const port = new SerialPort({ path: '/dev/cu.usbmodem1101', baudRate: 9600 })
const parser = new ReadlineParser()
port.pipe(parser)
// port.write('ROBOT PLEASE RESPOND\n')



var app = http.createServer(function(req, res){
    res.writeHead(200,{'Content-Type':'text/html'});
    res.end(index);
})

var io = require('socket.io').listen(app)

io.on('connection',function(data){
    console.log('node js is listening');
})

parser.on('data',function(data)
{   console.log(data);
    io.emit('data',data);
})


app.listen(3000);
