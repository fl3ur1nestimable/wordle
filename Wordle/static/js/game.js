let letters = ['A','Z','E','R','T','Y','U','I','O','P','Q','S','D','F','G','H','J','K','L','M','ENTER','W','X','C','V','B','N','DEL'];
let keys = [];
let grid = [[]];
let currentRow = 0;
let message = "";


function setup(){
    createCanvas(windowWidth,windowHeight);
    init_keyboard();
    // grille wordle
    grid = init_grid();
}

function draw(){
    background(40);
    display_grid();
    display_keyboard();
    for (let j = 0; j < keys.length; j++){
        if (mode==='pl'){
            keys[j].updatePL();
        }else{
        keys[j].update();
        }
    }
    fill(255);
    textSize(40);
    textFont('Arvo');
    text(message,0.7542*width,0.645*height,0.3289*width,0.483*height);
}

function windowResized(){
    resizeCanvas(windowWidth,windowHeight);
    for (let i = 0; i < essais; i++) {
        for (let j = 0; j < longueur; j++) {
            let c = grid[i][j];
            c.w = floor(height/(max(essais,longueur)+2));
            c.x = j*(c.w+10)+0.05*width;
            c.y = i*(c.w+10)+0.097*height;
            if (essais==8){
                c.w = floor(height/(max(essais,longueur)+3));
                c.y = i*(c.w+10)+0.05*height;
            }
            if (essais==7){
                c.w = floor(height/(max(essais,longueur)+3));
                c.y = i*(c.w+10)+0.05*height;
            }

        }
    }
    for (let j = 0; j < keys.length; j++) {

        keys[j].w= width*0.036;
        keys[j].wref= width*0.036;
        
        if ((j>=0)&(j<10)) {
            keys[j].x = (j%10)*(keys[j].w+15)+0.55*width;
            keys[j].y = height*0.22;
        }
        if ((j>=10)&(j<20)) {
            keys[j].x = (j%10)*(keys[j].w+15)+0.55*width;
            keys[j].y = height*0.24 + keys[j].w;
        }
        if ((j>=20)&(j<28)) {
            keys[j].x = (j%10)*(keys[j].w+15)+0.595*width;
            keys[j].y = height*0.26 + 2*keys[j].w;
        }
    } 
}

function mousePressed(){
    for (let j = 0; j < keys.length; j++){
        if (keys[j].hovered()) {
            keys[j].w -=10;
            keys[j].isClicked();
        }
    }
}

function mouseReleased(){
    for (let j = 0; j < keys.length; j++){
            keys[j].w=keys[j].wref;
    } 
}

function mouseDragged(){
    for (let j = 0; j < keys.length; j++){
        if (!keys[j].hovered()) {
            keys[j].w=keys[j].wref;
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
        keys[j].wref= width*0.036;
        
        if ((j>=0)&(j<10)) {
            keys[j].x = (j%10)*(keys[j].w+15)+0.55*width;
            keys[j].y = height*0.22;
        }
        if ((j>=10)&(j<20)) {
            keys[j].x = (j%10)*(keys[j].w+15)+0.55*width;
            keys[j].y = height*0.24 + keys[j].w;
        }
        if ((j>=20)&(j<28)) {
            keys[j].x = (j%10)*(keys[j].w+15)+0.595*width;
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
            c.x = j*(c.w+10)+0.05*width;
            c.y = i*(c.w+10)+0.097*height;
            if (essais==8){
                c.w = floor(height/(max(essais,longueur)+3));
                c.y = i*(c.w+10)+0.05*height;
            }
            if (essais==7){
                c.w = floor(height/(max(essais,longueur)+3));
                c.y = i*(c.w+10)+0.05*height;
            }
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

function state(s,guess){
    for (let i = 0; i < s.length; i++) {
        if (s[i]==2) {
            guess[i].state=2;
            for(let j=0;j<keys.length;j++){
                if(guess[i].letter==keys[j].letter){
                    keys[j].state=3;
                } 
            }
        }
    }
    for (let i = 0; i < s.length; i++) {
        if (s[i]==1) {
            guess[i].state=1;
            for(let h=0;h<keys.length;h++){
                if(guess[i].letter==keys[h].letter){
                    if(keys[h].state<2){
                        keys[h].state=2;
                    }
                }
            }
        }
    } 

    for (let i=0;i<longueur;i++){
        for(let h=0;h<keys.length;h++){
            if(guess[i].letter==keys[h].letter){
                if(keys[h].state<2){
                    keys[h].state=1;
                }
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

async function guessWord(){
    let win = undefined;
    let guess = grid[currentRow];
    let guessToSend="";
    for (let i = 0; i < guess.length; i++) {
        guessToSend+=(guess[i].letter);
    }
    let response=await fetch('/check?guess='+guessToSend);
    let res;
    let b;
    if (response.ok) {
        b = await response.json();
        let a= Promise.resolve(b);
        res=(await a).valueOf();
    }
    s=res["s"];
    guess_state=res["guess_state"];

    if (s.length==0 && guess_state=="incomplete") {
        message="Mot incomplet";
    }
    else if (s.length==0 && guess_state=="invalid") {
        message="Le mot n'existe pas";
    }
    else if (guess_state=="found") {
        win=true;
        message='Bravo !';
        state(s,guess);
        await sleep(500);
    }
    else if (guess_state=="incorrect"){
        message="Mot incorrect. Veuillez en choisir un autre";
        state(s,guess);
        currentRow += 1;
    }

    if (currentRow==essais) {
        win=false;
        await sleep(500);
    }
    if(win!=undefined){
        noLoop();
        let s = "";
        if (win==true) {
            s+="win";
        } else {
            s+="loss";
        }
        let tries =(s == 'win') ? String(currentRow+1) : String(currentRow);
        var http = new XMLHttpRequest();
        var url = "/save"
        data=[s,tries]
        http.open("POST",url,true);
        http.send(data);

        let response=await fetch('/response');
        let res;
        let b;
        if (response.ok) {
            b = await response.text();
            let a= Promise.resolve(b);
            res=(await a).valueOf();
        }
        switch (win) {
            case true:
                if (window.confirm("Bravo! Tu as trouvé la réponse!\nVeux-tu rejouer?")==true) {
                    window.location.href=(mode=='classique')?'/Jeu':'/JeuPL';
                }
                break;
            case false:
                if (window.confirm("Perdu! La réponse était : " + res +"\nVeux-tu rejouer?")==true) {
                    window.location.href=(mode=='classique')?'/Jeu':'/JeuPL';
                }
                break;
        }
    }
}

function sleep(millisecondsDuration){
  return new Promise((resolve) => {
    setTimeout(resolve, millisecondsDuration);
  })
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
}
