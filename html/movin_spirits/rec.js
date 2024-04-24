class Rectangle {
    constructor(x, y, width, height, canvas) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.canvas = canvas;
        this.ctx = canvas.getContext('2d');
        this.draw();
    }

    printInfo = () => {
        console.log(`${this.x}\t${this.y} ---- ${this.width}\t${this.height}`)
    }

    downX = () => {
        return this.x + this.width;
    }

    downY = () => {
        return this.y + this.height;
    }

    clear() {
        this.ctx.beginPath();
        this.ctx.moveTo(this.x, this.y);
        this.ctx.clearRect(this.x, this.y, this.width, this.height);
    }

    goDown() {
        if (this.downY() < this.canvas.height) {
            this.moveTo(this.x, this.y + 1);
        }
    }

    goUp() {
        if (this.y > 0) {
            this.moveTo(this.x, this.y - 1);
        }
    }

    goRight() {
        if (this.downX() < this.canvas.width) {
            this.moveTo(this.x + 1, this.y);
        }
    }

    goLeft() {
        if (this.x > 0) {
            this.moveTo(this.x - 1, this.y);
        }
    }

    focus() {
        this.ctx.beginPath();
        this.ctx.moveTo(this.x, this.y);
    }

    clear() {
        this.focus();
        this.ctx.clearRect(this.x, this.y , this.width, this.height);
    }

    draw() {
        this.focus();
        this.ctx.fillRect(this.x, this.y , this.width, this.height);
    }

    moveTo(x, y) {
        this.clear();
        this.x = x;
        this.y = y;
        this.draw();
    }
}