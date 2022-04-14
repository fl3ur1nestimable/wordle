let letters = ['A','Z','E','R','T','Y','U','I','O','P','Q','S','D','F','G','H','J','K','L','M','ENTER','W','X','C','V','B','N','DEL'];
let keys = [];
let grid = [[]];
let currentRow = 0;
let mot = "amour";

function setup(){
    var canva =createCanvas(windowWidth,windowHeight);
    init_keyboard();
    // grille wordle
    grid = init_grid();
    setParams();
}

function draw(){
    background(40);
    display_grid();
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

        keys[j].w= width*0.033;
        
        if ((j>=0)&(j<10)) {
            keys[j].x = (j%10)*(keys[j].w+15)+0.54*width;
            keys[j].y = height*0.22;
        }
        if ((j>=10)&(j<20)) {
            keys[j].x = (j%10)*(keys[j].w+15)+0.54*width;
            keys[j].y = height*0.24 + keys[j].w;
        }
        if ((j>=20)&(j<28)) {
            keys[j].x = (j%10)*(keys[j].w+15)+0.581*width;
            keys[j].y = height*0.26 + 2*keys[j].w;
        }
    }
}

function display_keyboard(){ 
    for (let i = 0; i < keys.length; i++) {
        keys[i].show();
    }
}

function init_grid() {
    let grid = [];
    for (let i = 0; i < essais; i++) {
        let row = [];
        for (let j = 0; j < longueur; j++) {
            let c = new cell();
            c.w = floor(height/(max(essais,longueur)+2));
            c.x = j*(c.w+10)+0.102*width;
            c.y = i*(c.w+10)+0.097*height;
            row.push(c);
        }
        grid.push(row);
    }
    return grid;
}

function display_grid(){ 
    for (let i = 0; i < essais; i++) {
        for (let j = 0; j < longueur; j++) {
            grid[i][j].show();
        }
    }
}

function addLetter(letter){
    row = grid[currentRow];
    for(let i=0;i<longueur;i++){
        if (row[i].letter===""){
            row[i].letter=letter;
            return;
        }
    }

}

function removeLetter(){
    row = grid[currentRow];

    // ligne pleine
    if (row[longueur -1].letter!=""){
        row[longueur -1].letter = "";
        return;
    }

    // ligne vide
    if (row[0].letter===""){
        return;
    }

    for(let i=1;i<longueur;i++){
        if (row[i].letter===""){
            row[i-1].letter="";
            return;
        }
    }
}

function guessWord(){
    let guess = grid[currentRow];
    assert (guess.length<longueur)

    if (guess===mot){
        // TERMINER LE JEU et bravo
    }else{
        currentRow += 1;
        //envoyer message mot == mauvais 
        // mettre les couleurs 
    }

}


function keyPressed(){
    // Touche entrer
    if(keyCode===13){
        guessWord();
    }
    // Backspace
    if(keyCode===8){
        removeLetter();
    }

    if((65<=keyCode)&&(keyCode<=90)){
        addLetter(String.fromCharCode(keyCode));
    }

    console.log(grid);

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
