let letters = ['A','Z','E','R','T','Y','U','I','O','P','Q','S','D','F','G','H','J','K','L','M','ENTER','W','X','C','V','B','N','DEL'];
let keys = [];

function setup(){
    var canva =createCanvas(windowWidth/2,windowHeight-110);
    var x = (windowWidth - width) / 2;
    var y = 105;
    canva.position(x, y);
    init_keyboard();
}

function draw(){
    background(255);
    display_keyboard();
    for (let j = 0; j < keys.length; j++){
        keys[j].update();
    }
    keys[0].state=1;
    keys[5].state=2;
    keys[17].state=3;
    keys[23].state=1;
    keys[8].state=2;
    keys[10].state=3;
    keys[11].state=1;
    keys[21].state=2;

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
    for (let j = 0; j < keys.length; j++) {

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