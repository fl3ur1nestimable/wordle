class key{
    constructor(letter){
        this.letter=letter;
        this.x=null;
        this.y=null;
        this.state=0;
        this.submitted = false;
        this.w=null;
        this.wref=null;
        this.sw=0;
        this.col=color(217,217,217);
    }

    show(){
        rectMode(CENTER);
        fill(this.col);
        stroke(0);
        strokeWeight(this.sw);
        rect(this.x ,this.y,this.w,this.w,0.012*height);
        fill(0);
        stroke(0);
        strokeWeight(0.5);
        textAlign(CENTER);
        textSize(0.018*height);
        text(this.letter,this.x,this.y+0.00966*height);
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
    }

}