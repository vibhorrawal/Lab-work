// console.log("hello");
var express = require("express");

var app = express();
var students = [{name:"vibhor",age:19}]
app.get("/",function(req,res){
    res.send("hello");
})

app.get("/mail",function(req,res){
    var name = req.query.name;
    for(var i=0;i<students.length;i++){
        if()
    }
})

    app.get("/mail",function(req,res){
        var params = req.query;
        res.send("mail");
})
app.listen(8888,function(){
    console.log("server started");
})