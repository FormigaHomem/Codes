var foto = document.createElement("img")
var div = window.document.querySelectorAll("div")
var hours = new Date()
var horas = hours.getHours()

var tempo = horas >= 5 && horas < 12? "Manhã" : horas >= 12 && horas <= 18? "Tarde" : "Noite";

foto.src= `${tempo}.jpg`
foto.className= "photo"
document.body.className= `${tempo.toLowerCase() }`

div[0].innerHTML += `${horas} horas e ${hours.getMinutes() } minutos`
div[1].appendChild(foto)

function capitalized(tempo){
    var tempo = tempo.split(" ")

    for(var i = 0; i < tempo.length; i++){
        tempo[i] = tempo[i].replace(tempo[i][0], tempo[i][0].toUpperCase() )
    }

    return tempo
}
