class cell {
    constructor(letter = "", state = 0) {
        this.letter = letter;
        this.state = state;
        this.x = null;
        this.y = null;
        this.w = null;
        this.col = color(40,40,40);
    }

    show(){
        rectMode(CENTER);
        fill(this.col);
        stroke(100);
        strokeWeight(1.5);
        rect(this.x ,this.y,this.w,this.w,2);
        
        fill(255);
        stroke(0);
        strokeWeight(0.5);
        textAlign(CENTER);
        textSize(15);
        text(this.letter,this.x,this.y);
        
    }
}