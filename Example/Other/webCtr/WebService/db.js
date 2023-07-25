const res = require("express/lib/response");
var mysql = require("mysql");

var connection = mysql.createConnection({
    host: '192.168.0.14',
    port: '3306',
    user: 'master',
    password: 'AA10bb17',
    database: 'test_DB'
});
function createConnection(){
    return connection;
};

module.exports.createConnection = createConnection;