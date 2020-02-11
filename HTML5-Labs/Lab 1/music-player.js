let audioPlayer = document.getElementById("audio-player");
let playBtn = document.getElementById("mp-play-mode");
let shuffleBtn = document.getElementById("mp-shuffle-mode");
let repeatBtn = document.getElementById("mp-repeat-mode");
let pauseBtn = document.getElementById("mp-pause-mode");
var selectFile = document.getElementById('al-add');

let songs = ["canon.mp3", "dream.mp3"]

selectFile.onchange = function () {
    console.log("this.value: " + selectFile.files.item(0).name)
    songs.push(selectFile.files.item(0).name);
};

playBtn.addEventListener('click', playAudio)

var i = -1;

function playAudio() {
    i++;
    if (i == songs.length) {
        i = -1;
        return;
    }

    audioPlayer.src = songs[i]
    audioPlayer.play();
    audioPlayer.addEventListener("ended", playAudio);
    // pauseBtn.
}


shuffleBtn.addEventListener('click', shuffle)

function shuffle() {
    let num = Math.floor(Math.random() * songs.length-1) + 1
    console.log("[shuffle] num: " + num)
    console.log("[shuffle] song: " + songs[num])
    audioPlayer.src = songs[num]
    audioPlayer.play();
    audioPlayer.addEventListener("ended", shuffle);
}

repeatBtn.addEventListener('click', repeat)

function repeat() {
    audioPlayer.loop = !audioPlayer.loop;
}


pauseBtn.addEventListener('click', pause)

function pause() {
    audioPlayer.pause();
}