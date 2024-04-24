let canvas = document.querySelector('canvas');
let ctx = canvas.getContext('2d');

let staticRec = new Rectangle(10, 10, 20, 20, canvas);
let dynamicRec = new Rectangle(10, 40, 20, 20, canvas);


const clearCtx = () => {
    ctx.beginPath();
    ctx.moveTo(0, 0);
    ctx.fillStyle = "#fff";
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    ctx.fillStyle = "#000";
}

const drawLine = () => {
    ctx.beginPath();
    ctx.moveTo(dynamicRec.x + dynamicRec.width, dynamicRec.y + dynamicRec.height);
    ctx.lineTo(staticRec.x, staticRec.y);
    ctx.stroke();
}

drawLine();

document.addEventListener('keydown', (event) => {
    if (event.key === "ArrowDown") {
        dynamicRec.goDown();
    } else if (event.key === "ArrowUp") {
        dynamicRec.goUp();
    } else if (event.key === "ArrowRight") {
        dynamicRec.goRight();
    } else if (event.key === "ArrowLeft") {
        dynamicRec.goLeft();
    }
    clearCtx();
    drawLine();
    staticRec.draw();
    dynamicRec.draw();
});