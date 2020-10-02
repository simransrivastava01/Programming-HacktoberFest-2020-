for(var i=0;i<document.querySelectorAll(".drum").length;i++)
{
document.getElementsByClassName("drum")[i].addEventListener("click", function(){


var buttonInnerHtml= this.textContent;

switch(buttonInnerHtml){

case "w":{

  var audio=new Audio("./sounds/crash.mp3");
  audio.play();
   break;
}

case "a":{

    var audio=new Audio("./sounds/kick-bass.mp3");
    audio.play();
    break;

}
case "s":{

    var audio=new Audio("./sounds/snare.mp3");
    audio.play();
    break;

}
case "d":{

    var audio=new Audio("./sounds/tom-1.mp3");
    audio.play();
    break;

}
case "j":{

    var audio=new Audio("./sounds/tom-2.mp3");
    audio.play();
    break;

}case "k":{

    var audio=new Audio("./sounds/tom-3.mp3");
    audio.play();
    break;

}case "l":{

    var audio=new Audio("./sounds/tom-4.mp3");
    audio.play();
    break;

}
}

buttonAnimation(buttonInnerHtml);

    
});

   

}
  

document.addEventListener("keydown",function(event){

var key=event.key;

    switch(key){

        case "w":{
        
          var audio=new Audio("./sounds/crash.mp3");
          audio.play();
           break;
        }
        
        case "a":{
        
            var audio=new Audio("./sounds/kick-bass.mp3");
            audio.play();
            break;
        
        }
        case "s":{
        
            var audio=new Audio("./sounds/snare.mp3");
            audio.play();
            break;
        
        }
        case "d":{
        
            var audio=new Audio("./sounds/tom-1.mp3");
            audio.play();
            break;
        
        }
        case "j":{
        
            var audio=new Audio("./sounds/tom-2.mp3");
            audio.play();
            break;
        
        }case "k":{
        
            var audio=new Audio("./sounds/tom-3.mp3");
            audio.play();
            break;
        
        }case "l":{
        
            var audio=new Audio("./sounds/tom-4.mp3");
            audio.play();
            break;
        
        }
        }
        

 buttonAnimation(key);

})


var buttonAnimation=function(currentKey){


    document.querySelector("."+currentKey).classList.add("pressed")

setTimeout(function(){

    document.querySelector("."+currentKey).classList.remove("pressed")

},100)

}