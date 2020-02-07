
var p = document.getElementsByTagName('p');


function convertToLinks(){
    for(i=p.length-1 ; i>=0 ; i--)
    {
        
        
        var hyperLink=document.createElement('a');
        var myAttr=document.createAttribute('href');
        hyperLink.textContent = p[i].textContent;
        myAttr.value = "http://www." + p[i].textContent + ".com";
        hyperLink.setAttributeNode(myAttr);
        console.log(hyperLink);
        document.getElementsByTagName("body")[0].replaceChild(hyperLink,p[i])
       
    }
    
   

}