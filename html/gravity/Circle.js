class Circle {
    constructor(x, y, radius, canvas)
    {
        this.x = x;
        this.y = y;
        this.radius = radius;
        this.canvas = canvas;
        this.ctx = canvas.getContext('2d');
    }

    setPos = (x, y) => {
        this.x = x;
        this.y = y;
    }

    downY = () => {
        return this.y + this.radius;
    }

    render = () => {
        this.ctx.beginPath();
        this.ctx.moveTo(this.x, this.y);
        this.ctx.arc(this.x, this.y, this.radius, 0, 2 * Math.PI);
        this.ctx.fill();
    }
}