var os=require('os');
var path=require('path');
/*資料庫連線功能*/
var db = require('./db.js');
var connection=db.createConnection();

/*序列埠通信設定*/
var SerialPort = require("serialport"); 
const Readline = SerialPort.parsers.Readline;
var portAddress=process.argv[2]; //輸入開發版的序列埠位置
var SP_port = new SerialPort(portAddress); 
const parser = SP_port.pipe(new Readline({ delimiter: '\r\n' }));

/*打開串口*/
SP_port.on('open',function(err){
    console.log('Serial Port: '+ portAddress +' is opened.');
    if(err){
        console.log('Error opening port: ',err.message);
    }
})

/*輸出Arduino回伝的結果*/
parser.on('data',line =>{
    console.log(line);
})


var express=require('express');
const { render } = require('express/lib/response');
const { connect } = require('http2');
const Connection = require('mysql/lib/Connection');
var app=express();
app.set('view engine','ejs');


/*Server監聽設定*/
var web_port=8081;
app.listen(web_port,function(){
    console.log('running in http://localhost:'+web_port);
})
/*導入導入Static檔案(img,css)*/
app.use(express.static('public'))  //標準
app.use(express.static(path.join(__dirname, '/views/ui'))) //設定絕對路徑

/*API接收回伝設定*/
app.get('/',function(req,res){
    var LED1,LED2,LED3,LED4;
    var queary = 'SELECT * FROM `sensor_switch` WHERE 1';
    connection.query(queary,function(err,rows,fields){
        res.render('web',{
            port: portAddress,
            'items': rows
        });
    })
    /*var LED1_var=connection.query('SELECT `LED1` FROM `sensor_switch` WHERE 1');
    var LED2_var=connection.query('SELECT `LED2` FROM `sensor_switch` WHERE 1');
    var LED3_var=connection.query('SELECT `LED3` FROM `sensor_switch` WHERE 1');
    var LED4_var=connection.query('SELECT `LED4` FROM `sensor_switch` WHERE 1'); 
    */
    connection.end();
})
app.get('/db_test',function(req,res){
    
    connection.query('SELECT 1 + 1 AS solution', function (error, results, fields) {
        var sendVar= results[0].solution;
        if(sendVar==2){
           var message = "Successful Connection";
           console.log('DB: Successful Connection ');
           res.send(message);
        }
        if(error){
            console.log('DB: Faile Connection');
            throw error;
        }
    });
});
app.get('/SP_port',function(req,res){
    res.send(portAddress);
});
app.get('/net',function(req,res){
    var net=os.networkInterfaces();
    res.send(net);
});

app.get('/LED/:mode',function(req,res){
    var mode=req.params.mode || req.param('mode');
    if(mode=='pilix'){
        SP_port.write('P');
        console.log("Server: GET /LED/pilix");
    }
    if(mode=='pwm'){
        SP_port.write('W');
        console.log("Server: GET /LED/pwm");
    }
    //return res.send('/LED/'+mode);
})
app.get('/:id/:action',function(req,res){
    var action=req.params.action || req.param('action');
    var id=req.params.id || req.param('id');
    if(id=='LED1'){
        if(action=='ON'){
            SP_port.write('A');
            console.log("Server: GET /LED1/ON");
            connection.query("UPDATE `sensor_switch` SET `LED1`=1 ", function (error, results, fields) {
                if (error) throw error;
            });
        }
        if(action=='OFF'){
            SP_port.write('a');
            console.log("Server: GET /LED1/OFF");
            connection.query("UPDATE `sensor_switch` SET `LED1`=0 ", function (error, results, fields) {
                if (error) throw error;
            });
        }
    }

    if(id=='LED2'){
        if(action=='ON'){
            SP_port.write('B');
            console.log("Server: GET /LED2/ON");
            connection.query("UPDATE `sensor_switch` SET `LED2`=1 ", function (error, results, fields) {
                if (error) throw error;
            });
        }
        if(action=='OFF'){
            SP_port.write('b');
            console.log("Server: GET /LED2/OFF");
            connection.query("UPDATE `sensor_switch` SET `LED2`=0 ", function (error, results, fields) {
                if (error) throw error;
            });
        }
    }

    if(id=='LED3'){
        if(action=='ON'){
            SP_port.write('C');
            console.log("Server: GET /LED3/ON");
            connection.query("UPDATE `sensor_switch` SET `LED3`=1 ", function (error, results, fields) {
                if (error) throw error;
            });
        }
        if(action=='OFF'){
            SP_port.write('c');
            console.log("Server: GET /LED3/OFF");
            connection.query("UPDATE `sensor_switch` SET `LED3`=0 ", function (error, results, fields) {
                if (error) throw error;
            });
        }
    }

    if(id=='LED4'){
        if(action=='ON'){
            SP_port.write('D');
            console.log("Server: GET /LED4/ON");
            connection.query("UPDATE `sensor_switch` SET `LED4`=1 ", function (error, results, fields) {
                if (error) throw error;
            });
        }
        if(action=='OFF'){
            SP_port.write('d');
            console.log("Server: GET /LED4/OFF");
            connection.query("UPDATE `sensor_switch` SET `LED4`=0 ", function (error, results, fields) {
                if (error) throw error;
            });
        }
    }

    if(id=='LED_ALL'){
        if(action=='ON'){
            SP_port.write('E');
            console.log("Server: GET /LED_ALL/ON");
            connection.query("UPDATE `sensor_switch` SET `LED1`=1,`LED2`=1,`LED3`=1,`LED4`=1 ", function (error, results, fields) {
                if (error) throw error;
            });
        }
        if(action=='OFF'){
            SP_port.write('e');
            console.log("Server: GET /LED_ALL/OFF");
            connection.query("UPDATE `sensor_switch` SET `LED1`=0,`LED2`=0,`LED3`=0,`LED4`=0 ", function (error, results, fields) {
                if (error) throw error;
            });
        }
    }
    
    //return res.send('/'+ id +'/'+ action);
})

