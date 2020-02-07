var str="";
var submitBtn=document.getElementById('saveForm');
var inputForm = document.getElementsByClassName('element text large');
var checkButton = document.getElementsByClassName('element radio');
var checkbox = document.getElementsByClassName('element checkbox');
var selectedDropList=document.getElementById('element_6');

var errorMsg=document.getElementById('error-messages');

var errorStyle = document.getElementsByClassName('errors');
var flag = true
submitBtn.addEventListener('click' , checkInputs);

 function isValidEmail(email){
    var regex = "^[\\w-_\\.+]*[\\w-_\\.]\\@([\\w]+\\.)+[\\w]+[\\w]$";
    return email.match(regex);
}

function checkboxNumber(checkbox)
{
    var i;
    var count=1;
    
    for(i=0 ;i < checkbox.length ;i++)
    {
        if(checkbox[i].checked)
          count++;
     
    }
    if(count< 2)
         flag = false;
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
    
    if(!(checkButton[0].checked) && !(checkButton[1].checked) )
    {
        str += "<li> Please select your gender</li>";
    } 

    if(flag){

        str += "<li> Please select at least two sports. </li>";
    } 
   
    if(selectedDropList.value === ""){
        str += "<li> Please select your country. </li>";
    } 
     
   

    errorMsg.innerHTML = str;

    errorStyle[0].style.display="block";

    
  
}


