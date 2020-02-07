
var allButtons=document.getElementsByTagName('button');
var imgs=document.getElementsByTagName("img");

var i = 0;
var intervalId;
var color = ["red" ,"orange" , "green","gray"];

var intervalFun = function(){


    if(i > 3)
    {
      i = 0;
    }
    
    imgs[0].src="img/"+color[i]+".png";
    i++;


};


function playAction(){
   

    intervalId = setInterval(intervalFun,1000);
   
    
}

function stopAction(){

     clearInterval(intervalId);
    
    
}

function previousImage()
{
  if(i < 0)
    {
      i = 3;
    }
    
    imgs[0].src="img/"+color[i]+".png";
    i--;


}

function firstImage()
{
    
    i = 0;
    imgs[0].src="img/"+color[i]+".png";

}

function lastImage()
{
    
    i = 3;
    imgs[0].src="img/"+color[i]+".png";

}




allButtons[0].addEventListener('click',playAction);
allButtons[1].addEventListener('click',stopAction);
allButtons[2].addEventListener('click',firstImage );
allButtons[3].addEventListener('click',previousImage);
allButtons[4].addEventListener('click',intervalFun );
allButtons[5].addEventListener('click',lastImage );
