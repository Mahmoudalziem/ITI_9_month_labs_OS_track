var num;
function fizBuzz(num) {

    if(num % 3 == 0 && num % 5 != 0 )
        console.log("Fiz");
      
    else if(num % 5 == 0 && num % 3 != 0 )
        console.log("buzz");

    else if(num % 3 == 0 && num % 5 == 0 )
        console.log("Fiz Buzz");
    else
        console.log("None");
  }