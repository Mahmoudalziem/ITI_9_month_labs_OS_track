var audio = document.getElementById("music");

var songs = ["dream.mp3", "canon.mp3"]

var playBtn = document.getElementById("play").addEventListener("click", playSong);
var repeatBtn = document.getElementById("repeat").addEventListener("click", repeatSong);
var pauseBtn = document.getElementById("pause").addEventListener("click", pauseSong);
var shuffleBtn = document.getElementById("shuffle").addEventListener("click", shuffleSong);

function playSong(){
    audio.src = songs[0];
    audio.play();
}

function repeatSong(){
    audio.loop = true;
    console.log("The audio is looped to be working forever");
}

function pauseSong(){
    audio.pause();
}

function shuffleSong(){
    index = Math.ceil(Math.random() * songs.length)
    audio.src = songs[index-1]
    audio.play();
}
