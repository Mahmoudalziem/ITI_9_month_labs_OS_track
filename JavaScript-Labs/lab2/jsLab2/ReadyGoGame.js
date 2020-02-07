
var color = ["red" ,"orange" , "green"];

var str = ["Ready" ,"Steady" , "Go"];
var num=1,count = 0;


function readGo(num)
{  
    var i,j;
    var imgs=document.getElementsByTagName('img');
    var praragraph=document.getElementsByClassName('message');

    for(j=0 ; j< imgs.length ; j++)
    {
        imgs[j].src="img/gray.png";
    }

    for(i=0 ; i< imgs.length ; i++)
    { 
        
        if(i == num-1)
        {
            imgs[i].src="img/"+color[i]+".png";
            praragraph[0].textContent= str[i];
            praragraph[0].style.color=color[i];
        
        } 
    }
}

var readGoVar = function(){

  
        if(count > 3)
        {
            num = 1;
            count = 0;
        }
  
        readGo(num);
        num++;
        count++;
       
    

        
};


setInterval(readGoVar,1000);
