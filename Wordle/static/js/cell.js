
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
        this.updateColor();
        fill(this.col);
        if (this.state==0){
            stroke(100);
            strokeWeight(1.5);
        }else{
            stroke(this.col);
            strokeWeight(1.5)
        }
        rect(this.x ,this.y,this.w,this.w,2);
        
        fill(255);
        stroke(0);
        strokeWeight(2);
        textAlign(CENTER,CENTER);
        textSize(height*0.06);
        text(this.letter,this.x,this.y+height*0.0217);
        
    }

    getLetter(){
        return this.letter;
    }

    updateColor(){
        switch(this.state){
            case 0 :
                this.col = color(40,40,40);
                break;
            
            case 1 :
                this.col = color(235,200,120);
                break;
            
            case 2 :
                this.col = color(150,235,120);
                break;
            
        }
    }
}


//let backgroundColor = color(40,40,40);
//let yellowColor = color(235,200,120);
//let greenColor = color(150,235,120);
//let alreadyUsedColor = color(100,100,100);