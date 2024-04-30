let canvas = document.querySelector('canvas');
let ctx = canvas.getContext('2d');

let circle = new Circle(canvas.width / 2, 20, 10, canvas);

function clear() {
    ctx.beginPath();
    ctx.moveTo(0, 0);
    ctx.fillStyle = "#fff";
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    ctx.fillStyle = "#000";
}

function render() {
    circle.render();
}


canvas.addEventListener('click', (event) => {
    circle.setPos(event.x, event.y);
    render();
});