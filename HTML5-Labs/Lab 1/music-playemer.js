var buttons = document.getElementsByTagName('input');
var canon_dream = document.getElementsByTagName('a');
var audio_player = document.getElementById('audio-player');

var arr_audio=[canon , dream]
var i=0;

function audio(){

    audio_player[i].innerHTML="<source src=arr[i]+'.mp3' type='audio/mpeg'> </source>";
    audio_player[i].play();
}

function playAudio(e){

    
        for(i=0 ; i < canon_dream.length ; i++)
        {
            e.target.src = arr[i]+'.mp3';

            e.target.play();
        }
       
    
}



for(i=0 ; i < canon_dream.length ; i++)
{
    canon_dream[i].addEventListener('click' , audio)
}


buttons[0].addEventListener('click' , playAudio())
// buttons[1].addEventListener('click' , shuffleAudio)
// buttons[2].addEventListener('click' , repeatAudio)