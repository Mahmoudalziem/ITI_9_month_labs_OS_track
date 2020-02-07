var Contacts = [];
var inputs = document.getElementsByClassName("text")
var button = document.getElementById("submit")
var count = 1;

var isUpdated=false;
var newContact;
var temp;
class Contactlist {
    constructor(name, email, phone) {
        this.namme = name
        this.email = email
        this.phone = phone
        this.id = count++

    }
}
const list = document.getElementById("contact_table_body");

function addContact(obj) {
    Contacts.push(obj)
    // console.log(obj)
    const row = document.createElement("tr");
    row.innerHTML = `<td>${obj.namme}</td>
   <td>${obj.email}</td>
   <td>${obj.phone}</td>
    <td><button id="edit_${obj.id}">edit</button>   <button id="delete_${obj.id}">delete</button></td>`;


    list.appendChild(row);
    document.getElementById(`edit_${obj.id}`).addEventListener("click",editContact);
    document.getElementById(`delete_${obj.id}`).addEventListener("click", deleteContact);

    clear()



}
function clear() {

    inputs[0].value = ""
    inputs[1].value = ""
    inputs[2].value = ""

}
function createContact(e) {

    e.preventDefault()
    if(isUpdated){
        Contacts[temp].name=inputs[0].value
        Contacts[temp].email=inputs[1].value
        Contacts[temp].phone=inputs[2].value
        isUpdated=false
       
    }
    else
    {  
        if(inputs[0].value!==""&&inputs[1].value!==""&&inputs[2].value!==""){
            var name = inputs[0].value
    var email = inputs[1].value
    var phone = inputs[2].value
     newContact = new Contactlist(name, email, phone)
    addContact(newContact)
        }

    
}}
function editContact(e) {

    var objId = e.target.id.split("_")[1]
     for (let i = 0; i < Contacts.length; i++) {
        if (Contacts[i].id == objId) {
             
    inputs[0].value = Contacts[i].namme
    inputs[1].value = Contacts[i].email
    inputs[2].value=Contacts[i].phone
    isUpdated=true;
    temp=i;
    var row = e.target.parentNode.parentNode ;
    list.removeChild(row);
    break;
        }
   }

}
function deleteContact(e) {
    var objId = e.target.id.split("_")[1]
    for (let i = 0; i < Contacts.length; i++) {
        if (Contacts[i].id == objId) {
            console.log(Contacts[i])
            var row = e.target.parentNode.parentNode ;
            list.removeChild(row);
            Contacts.splice(i, 1)
        }
    }


}

button.addEventListener("click", createContact)