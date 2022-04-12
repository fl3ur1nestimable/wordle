class key{
    constructor(letter){
        this.letter=letter;
        this.x=null;
        this.y=null;
        this.state=0;
        this.w=50;
        this.sw=0;
        this.col=200;
    }

    show(){
        fill(this.col);
        stroke(0);
        strokeWeight(this.sw);
        rect(this.x,this.y,this.w,this.w,10);
        fill(0);
        stroke(0);
        strokeWeight(0.5);
        textAlign(CENTER);
        textSize(15);
        text(this.letter,this.x+this.w/2,this.y+this.w/2);
    }

    hovered(){
        if ((mouseX>=this.x)&(mouseX<=this.x+this.w)&(mouseY>=this.y)&(mouseY<=this.y+this.w)) {
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
    }

}