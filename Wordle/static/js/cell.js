
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
        switch(mode){
            case 'classique':
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

                break;
            
            case 'pl':
                rectMode(CENTER);
                stroke(40);
                strokeWeight(1.5);
                fill(40)
                rect(this.x ,this.y,this.w,this.w,2);

                this.updateColorPL();
                fill(this.col);
                if (this.state==0){
                    stroke(100);
                    strokeWeight(1.5);
                }else{
                    stroke(this.col);
                    strokeWeight(1.5)
                }

                const R = this.w/2.3;
                const xh = angle => R / 15.0 * 16 * Math.pow(Math.sin(angle), 3);
                const yh = p => R / 15.0 * (-13 * Math.cos(p) + 5 * Math.cos(2 * p) + 2 * Math.cos(3 * p) + Math.cos(4 * p));


                beginShape();
                let n = 200;
                for (let i = 0; i < n; i++) {
                    let x = this.x + xh(TAU * i / n);
                    let y = this.y + yh(TAU * i / n);
                    vertex(x, y);
                }
                endShape();
                break;
                
            }
            fill(255);
            stroke(0);
            strokeWeight(2);
            textAlign(CENTER,CENTER);
            textSize(this.w*0.45);
            text(this.letter,this.x,this.y+this.w*0.05);

        
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
                this.col = color(235, 200, 120);
                break;
            
            case 2 :
                this.col = color(150, 235, 120);
                break;
            
        }
    }

    updateColorPL(){
        switch(this.state){
            case 0 :
                this.col = color(40,40,40);
                break;
            
            case 1 :
                this.col = color(249, 141, 143);
                break;
            
            case 2 :
                this.col = color(226, 28, 38);
                break;
            
        }   
    }
}


//let backgroundColor = color(40,40,40);
//let yellowColor = color(235,200,120);
//let greenColor = color(150,235,120);
//let alreadyUsedColor = color(100,100,100);
//let pinkColor = color(249,141,143);
//let redColor = color(226,28,38);