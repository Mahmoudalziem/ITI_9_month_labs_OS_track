// var googleMapSrc = "http://maps.googleapis.com/maps/api/staticmap?center="+latlon+"&zoom=14&size=400x300&sensor=false";
var getloc=document.getElementById("get-loc");

var lat = document.getElementById('lat');
var long = document.getElementById('log');


var map = L.map('map').setView([51.505, -0.09], 13);

L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
}).addTo(map);

L.marker([51.5, -0.09]).addTo(map)
    .bindPopup('A pretty CSS3 popup.<br> Easily customizable.')
    .openPopup();


function locateMe()
{
navigator.geolocation.getCurrentPosition('click',function(pos)
{
      lat.textContent=pos.coords.latitude;
        long.textContent=pos.coords.longitude;
});
}



getloc.addEventListener('click',locateMe);