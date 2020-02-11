var str="";
var submitBtn=document.getElementById('saveForm');
var inputForm = document.getElementsByClassName('element text large');


var errorMsg=document.getElementById('error-messages');

var errorStyle = document.getElementsByClassName('errors');
var flag = true


 function isValidEmail(email){
    var regex = "^[\\w-_\\.+]*[\\w-_\\.]\\@([\\w]+\\.)+[\\w]+[\\w]$";
    return email.match(regex);
}



function checkInputs(event){
    str=""

    console.log(event);
     event.preventDefault();
    if(inputForm[0].value === "")
    {
     str += "<li> your name is required </li>";
    
    }
    
   if(inputForm[1].value === "" || !(isValidEmail(inputForm[1].value)))
    {
        str += "<li> email isn't valid </li>";
       
    }
    
    if(inputForm[2].value === "" || inputForm[2].value < 8)
    {
        str += "<li> Password must be 8 chars at least</li>";
    }
    
    if(inputForm[3].value === "" || inputForm[3].value < 8)
    {
        str += "<li> Password must be 200 chars at most</li>";
    }
    
    if(inputForm[4].value === "" || inputForm[4].value > 21)
    {
        str += "<li> Password must be lower than or equal 21</li>";
    }
   
   
    errorMsg.innerHTML = str;

    errorStyle[0].style.display="block";

    
  
}


submitBtn.addEventListener('click' , checkInputs);