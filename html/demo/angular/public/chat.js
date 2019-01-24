angular.module("chatApp", ["firebase"])
.controller("chatCtrl", chatCtrl)

function chatCtrl ($firebaseArray,$firebaseAuth,$http){
  
      firebase.database().ref("chats") 

    var chat = this;
    var auth = $firebaseAuth();
    var chatRef = firebase.database().ref("chats")
    chat.messages = $firebaseArray(chatRef);
    console.log("hi");
   
    chat.send = function(t){
       chat.messages.$add({"text":t,"name":chat.name,"photo":chat.photo})
    }
     chat.login= function(){
        // login with Google
  auth.$signInWithPopup("google").then(function(firebaseUser) {
    console.log("Signed in as:", firebaseUser.user);
    console.log(firebaseUser.user.DisplayName,firebaseUser.user.photoURL)
    chat.name =firebaseUser.user.DisplayName;
    chat.photo = firebaseUser.user.photoURL

    var url = "https://api.genderize.io/?name=vibhor"
    $http.get(url).then(function(data){
     console.log(data)

    })
  }).catch(function(error) {
    console.log("Authentication failed:", error);
  });

    }
    chat.login
}
