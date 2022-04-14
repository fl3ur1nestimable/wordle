let letters = ['A','Z','E','R','T','Y','U','I','O','P','Q','S','D','F','G','H','J','K','L','M','ENTER','W','X','C','V','B','N','DEL'];
let keys = [];
let grid = [[]];
let currentRow = 0;
let word = ['A','M','O','U','R'];
let message = "";



function setup(){
    var canva =createCanvas(windowWidth,windowHeight);
    init_keyboard();
    // grille wordle
    grid = init_grid();
    
}

function draw(){
    background(40);
    display_grid();
    display_keyboard();
    for (let j = 0; j < keys.length; j++){
        keys[j].update();
    }
    fill(200,0,0);
    textSize(40);
    textFont('Arvo')
    text(message,1350,700,600,400);
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

        keys[j].w= width*0.036;
        
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


function getWord(cellTab){
    let w = [];
    for(let i=0;i<cellTab.length;i++){
        w.push(cellTab[i].letter);
    }
    return w;
}

function state(guess,word){
    // Copie du tableau du mot à trouver (on va modifier ses valeurs)
    let w = [].concat(word);
    // Résultat renvoyé - tableau des états
    // 1ere boucle pour trouver les lettres bien placées
    for (let i=0;i<longueur;i++){
        if(guess[i].letter===w[i]){
            guess[i].state=2;
            w[i]="";
            }
        }
    // 2e boucle pour trouver les lettres mal placées 
    for (let i=0;i<longueur;i++){
        for (let j=0;j<longueur;j++){
            if (guess[i].letter===w[j]){
                guess[i].state=1;
                w[j]="";
            }
        }
    }
    return state;
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

    if(guess[longueur -1].letter===""){ // Si la ligne n'est pas remplie
        return;
    }


    // Vérifier que le mot se trouve dans la liste --> Faire la fonction exist()
    else if(!true){
        message = "Mot incorrect, veuillez en choisir un autre " 
        return;
    }
    
    else{
        state(guess,word);
        console.log(grid[0][0].col);
        currentRow += 1;


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
    if (longueur == null) {
        longueur =5;
    }
    if (essais ==null){
        essais =5;
    }

}




