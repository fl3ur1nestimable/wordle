class key{
    constructor(letter){
        this.letter=letter;
        this.x=null;
        this.y=null;
        this.state=0;
        this.w=null;
        this.sw=0;
        this.col=color(217,217,217);
    }

    show(){
        rectMode(CENTER);
        fill(this.col);
        stroke(0);
        strokeWeight(this.sw);
        rect(this.x ,this.y,this.w,this.w,10);
        fill(0);
        stroke(0);
        strokeWeight(0.5);
        textAlign(CENTER);
        textSize(15);
        text(this.letter,this.x,this.y);
    }

    hovered(){
        if ((mouseX>=this.x-this.w/2)&(mouseX<=this.x+this.w/2)&(mouseY>=this.y-this.w/2)&(mouseY<=this.y+this.w/2)) {
            return true;
        }
        return false;
    }

    update(){
        if (this.hovered()) {
            this.sw=2;
        }
        else{
            this.sw=0;
        }
        switch (this.state){
            case 1:
                this.col=color(255,0,0);
                break;
            case 2:
                this.col=color(255,255,26);
                break;
            case 3:
                this.col=color(128,128,128);
                break;
        }
    }

}