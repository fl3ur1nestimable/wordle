let letters = ['A','Z','E','R','T','Y','U','I','O','P','Q','S','D','F','G','H','J','K','L','M','ENTER','W','X','C','V','B','N','DEL'];
let keys = [];

function setup(){
    var canva =createCanvas(windowWidth/2,windowHeight-110);
    var x = (windowWidth - width) / 2;
    var y = 105;
    canva.position(x, y);
    init_keyboard();
    setParams();
    console.log(longueur);
    console.log(essais);

}

function draw(){
    background(0);
    display_keyboard();
    for (let j = 0; j < keys.length; j++){
        keys[j].update();
    }
}

function mousePressed(){
    for (let j = 0; j < keys.length; j++){
        if (keys[j].hovered()) {
            keys[j].w -=10;
        }
    }
}

function mouseReleased(){
    for (let j = 0; j < keys.length; j++){
        if (keys[j].hovered()) {
            keys[j].w+=10;
        }
    }
}

function init_keyboard(){
    for (let i = 0; i < letters.length; i++) {
        k = new key(letters[i]);
        keys.push(k)
    }
    for (let j = 0; j <  keys.length; j++) {

        keys[j].w= width/12;
        
        if ((j>=0)&(j<10)) {
            keys[j].x = (j%10)*(keys[j].w+15)+48;
            keys[j].y = 3*height/5 +70;
        }
        if ((j>=10)&(j<20)) {
            keys[j].x = (j%10)*(keys[j].w+15)+48;
            keys[j].y = 3*height/5 + keys[j].w+85;
        }
        if ((j>=20)&(j<28)) {
            keys[j].x = (j%10)*(keys[j].w+15)+140;
            keys[j].y = 3*height/5 + 2*keys[j].w +100;
        }
    }
}

function display_keyboard(){ 
    for (let i = 0; i < keys.length; i++) {
        keys[i].show();
    }
}

function setParams(){
    if (longueur < 2) {
        longueur =2;
    }
    if (longueur > 15) {
        longueur =15;
    }
    if (essais < 3) {
        essais =3;
    }
    if (essais > 8) {
        essais =8;
    }
    if (typeof essais != "number") {
        essais=5;
    }
    if (typeof longueur != "number") {
        longueur=5;
    }
    longueur=floor(longueur);
    essais=floor(essais);
}

function saveGameData(){
    //enregistrement des données de la game
    //user ID ?
}