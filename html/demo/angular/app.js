angular.module("todoApp", [])
.controller("todoCtrl", todoCtrl)

function todoCtrl (){
    var todo = this;
    // todo.task = "Do workshop";
    todo.tasks = [
        "task1",
        "task2",
        "task3",
        "task4",
    ];

    todo.addTask = function(){
        todo.tasks.push(todo.task)
        todo.task = ""
    }
}