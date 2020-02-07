var i , k;
var newObj={class:0 , id:0 , name:0};

function countMeGame(str,object)
{
    var tags = document.getElementsByTagName(str);

    for(i=0 ; i<tags.length ; i++)
    {
        for(k in object)
        {
           if(tags[i].hasAttribute(k)&&tags[i].getAttribute(k).includes(object[k]))
           {
               newObj[k] +=1;
           }

          
        }
         //casting
         newObj.id=Boolean (newObj.id);
         newObj.all = tags.length;

         return newObj;
    }
}