
//constiables
let mod = null;
let clicked = false;
var startX = 0;
var startY = 0;

const inputs = document.getElementsByTagName('input');

const canv = document.getElementById('my-canvas');
const rectCanv = canv.getBoundingClientRect();
const ctx = canv.getContext('2d');



//canvas events
canv.addEventListener('mousedown' , (e)=>{
    if(mod === 'free')
    {
        ctx.fillStyle='black';
        clicked = true;
        ctx.beginPath();
        ctx.moveTo(e.clientX-rectCanv.left , e.clientY-rectCanv.top); 
    }
    else if(mod === 'line')
    {
        ctx.fillStyle = 'black';
        clicked=true;
        ctx.beginPath();
        ctx.moveTo(e.clientX-rectCanv.left , e.clientY-rectCanv.top); 
        
    }
    else if(mod === 'rect')
    {
        
        ctx.fillStyle = 'black';
        clicked=true;
        ctx.beginPath();
        ctx.moveTo(e.clientX-rectCanv.left , e.clientY-rectCanv.top); 
        startX = e.clientX-rectCanv.left;
        startY = e.clientY-rectCanv.top;
        
    }
    else if(mod === 'circle')
    {

    }
});


canv.addEventListener('mousemove' , (e)=>{
    if(mod === 'free')
    {
        if(clicked)
        {   
            ctx.lineTo(e.clientX-rectCanv.left , e.clientY-rectCanv.top);
            ctx.stroke();
        }
    
    }

    //  if(mod === 'line')
    // {
    //     if(clicked)
    //     {
    //     ctx.lineTo(e.clientX-rectCanv.left , e.clientY-rectCanv.top);
    //     ctx.stroke();
    //     }
    // }

      if(mod === 'rect')
       {
        
        ctx.rect(startX , startY , e.clientX-rectCanv.left , e.clientY-rectCanv.top);
        
       }
    
});


canv.addEventListener('mouseup' , (e)=>{
    if(mod === 'free')
    {
    
      clicked = false;
      
    }
    else if(mod === 'line')
    {    
        ctx.lineTo(e.clientX-rectCanv.left , e.clientY-rectCanv.top);
        ctx.stroke();
        clicked = false;
        ctx.close();
    }
    else if(mod === 'rect')
    {
    
        ctx.stroke();
        clicked = false;
        ctx.close();

    }
    else if(mod == 'circle')
    {
         
    }
});

//free tool
inputs[0].addEventListener('click' , ()=>{
    mod = 'free';
});

//line tool
inputs[1].addEventListener('click' , ()=>{
    mod = 'line';
});

//rect tool
inputs[2].addEventListener('click' , ()=>{
    mod = 'rect';
});

//circle tool
inputs[3].addEventListener('click' , ()=>{
    mod = 'circle';
});


//eraser tool
inputs[4].addEventListener('click' , ()=>{
    mod = null;
});
























 





//inputs[1].addEventListener('click' , lineDraw);



// function erase() {
//     if (confirm("Want to clear")) {
//       const ctx = canvas.getContext("2d");
//       ctx.clearRect(0, 0, canvas.width, canvas.height);
//       document.getElementById("canvasimg").style.display = "none";
//     }
//   }


