
/*
var str ="This is javaScript"
function getIndex(str , c)
{
    var arr=[];
     var i;
    for(i=0 ; i<str.length; i++)
    {
        if(str[i] == c)
          arr.push(i);
    }

    return arr;
}

convertInto(15.92);
function convertInto(num)
{
        var dollar= parseInt(num);
        var cent = (num - dollar) * 100;
        var quarter= Math.floor(cent/25);
        cent -= 25*quarter;
        var dim= Math.floor(cent/10);
        cent -= 10*dim;
        var nickel= Math.floor(cent/5);
        cent -= 5*nickel;
        console.log("You Have " + dollar + " doller, " + quarter + " quarter, "  + dim +" dim, " + nickel + " nickl, " + cent + " cent " );

}




function drawStars(num)
{
   var i , j ,x;
   var str ; 
   for(i=1 ; i <= num ; i++)
   {
       str="";
       for(j=num-i ; j >=0 ; j--)
       {
          str += " ";   
       } 
    for(x = 1 ; x <= i ; x++)
        {
            str += "*";
        }
       console.log(str +"\n");
       
   }
}
drawStars(5);



var arr;
function randomNames()
{
      arr=["ahmed" , "islam" ,  "sandra" , "Ali"];
      var x = Math.floor(Math.random()* arr.length);
      var y = Math.floor(Math.random()* arr.length);
      
      console.log(arr[x] + "  " + arr[y]);
}

*/
/*
function whoAmI()
{
    if(confirm("Are You Fly?"))
    {
        if(confirm("Are You Wild?"))
        {
            document.write("Engle");
        }
        else
        {
            document.write("Parrot");
        }
    }
    else
    {
        if(confirm("Do you live undersea?"))
        {
            if(confirm("Are You Wild?")) 
            {
                document.write("shark");
            }
            else
            {
                document.write("Dolphin");
            }

        }
        else
        {
            if(confirm("Are You Wild?")) 
            {
                document.write("Loin");
            }
            else
            {
                document.write("Cat");
            }

        }
    }

}
*/