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

const getColor = (distance) => {
    if (distance > 0 && distance < 200) {
        return "#0000ff";
    } else if (distance > 200 && distance < 400) {
        return "#00ff00";
    }
    return "#ff0000";
}

const drawLine = () => {
    ctx.beginPath();
    var distance = Math.round(
        Math.sqrt(
            Math.pow(Math.abs(dynamicRec.x - staticRec.x), 2)
            +
            Math.pow(Math.abs(dynamicRec.y - staticRec.y), 2)
        )
    );
    var color = getColor(distance);
    ctx.strokeStyle = color;
    ctx.moveTo(dynamicRec.x + dynamicRec.width, dynamicRec.y + dynamicRec.height);
    ctx.lineTo(staticRec.x, staticRec.y);
    ctx.fillText(
        distance,
        (dynamicRec.x + staticRec.x) / 2,
        (dynamicRec.y + staticRec.y) / 2
    );
    ctx.stroke();
}


const render = () => {
    clearCtx();
    drawLine();
    staticRec.draw();
    dynamicRec.draw();
}

render();

document.addEventListener('keydown', (event) => {
    if (event.key === "ArrowDown") {
        staticRec.goDown();
    } else if (event.key === "ArrowUp") {
        staticRec.goUp();
    } else if (event.key === "ArrowRight") {
        staticRec.goRight();
    } else if (event.key === "ArrowLeft") {
        staticRec.goLeft();
    }
    render();
});

let gotIt = false;
canvas.addEventListener('mousedown', (event) => {
    let x = event.x;
    let y = event.y;
    if ((dynamicRec.x <= x && x <= dynamicRec.downX()) && (dynamicRec.y <= y && y <= dynamicRec.downY())) {
        gotIt = true;
    } else {
        gotIt = false;
    }
});

canvas.addEventListener('mouseup', () => {
   gotIt = false; 
});

canvas.addEventListener('mousemove', (event) => {
    if (gotIt) {
        dynamicRec.moveTo(event.x, event.y);
        render();
    }
});