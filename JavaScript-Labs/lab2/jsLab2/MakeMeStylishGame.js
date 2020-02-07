

var i , k;

function makeMeStylish(str,object)
{
      var tags = document.getElementsByTagName(str);
      for(i=0 ; i<tags.length ; i++)
      {
          for(k in object)
          {
              tags[i].style[`${k}`]=object[k];
          }
      }
}