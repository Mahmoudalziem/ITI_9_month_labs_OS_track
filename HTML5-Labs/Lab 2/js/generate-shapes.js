var inputs=document.getElementsByTagName('input');
var canv=document.getElementById('my-canvas');


function drawLine()
{
    
    var cContext=canv.getContext("2d");
    var setX1=Math.random()*600;
    var setY1=Math.random()*450;

    var setX2=Math.random()*600;
    var setY2=Math.random()*450;
    cContext.beginPath();
    cContext.moveTo(setX1,setY1);
    cContext.lineTo(setX2,setY2);

    cContext.fillStyle="#F0B326"; 
    cContext.strokeStyle="#0FA30A";
    cContext.stroke();

}

function drawrect()
{
 
    var cContext=canv.getContext("2d");
    var setX1=Math.random()*600;
    var setY1=Math.random()*450;

    var setX2=Math.random()*600;
    var setY2=Math.random()*450;
    cContext.beginPath();
    cContext.fillStyle="#FF0000"; 
    
    cContext.fillRect(setX1,setY1,setX2,setY2);

}


function drawCircle()
{
   
    var cContext=canv.getContext("2d");
    var setX=Math.random()*650;
    var setY=Math.random()*500;
    var rad=Math.random()*50;
    cContext.beginPath();
    cContext.arc(setX,setY,rad,0,2*Math.PI);
    cContext.fillStyle="blue"; 
    cContext.fill();
   

}

function clearDraws()
{
    var cContext=canv.getContext("2d");
    cContext.beginPath();
    cContext.clearRect(0,0,canv.width,canv.height);

}

inputs[0].addEventListener('click' , drawLine)
inputs[1].addEventListener('click' , drawrect)
inputs[2].addEventListener('click' , drawCircle)
inputs[3].addEventListener('click' , clearDraws)

