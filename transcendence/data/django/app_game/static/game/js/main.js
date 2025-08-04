GAME = {}
GAME.ratio;
GAME.intervalID;
GAME.paddleSpeed = 50;
GAME.scoreLeft = document.querySelector("#scoreLeft");
GAME.scoreRight = document.querySelector("#scoreRight");
GAME.menuButton = document.querySelector("#menuButton");
GAME.playButton = document.querySelector("#playButton");
GAME.quitButton = document.querySelector("#quitButton");
GAME.Board = {}
GAME.Board.container = document.querySelector("#gameContainer");
GAME.Board.gameBoard = document.querySelector("#gameBoard");
GAME.Board.context = GAME.Board.gameBoard.getContext("2d");
GAME.Board.width = GAME.Board.container.offsetWidth;
GAME.Board.height = GAME.Board.container.offsetHeight * 0.8;
GAME.Board.gameBoard.width = GAME.Board.width;
GAME.Board.gameBoard.height = GAME.Board.height;
GAME.Ball = {}
GAME.Ball.posX = GAME.Board.gameBoard.width / 2;
GAME.Ball.posY = GAME.Board.gameBoard.height / 2;
GAME.Ball.dirX = 0;
GAME.Ball.dirY = 0;
GAME.Ball.speed = 1;
GAME.Ball.radius = 12.5;
GAME.Ball.color = "white";
GAME.Players = {}
GAME.Players.Left = {}
GAME.Players.Left.score = 0;
GAME.Players.Left.Paddle = {}
GAME.Players.Left.Paddle.sizeX = 15;
GAME.Players.Left.Paddle.sizeY = 80;
GAME.Players.Left.Paddle.posX = 65;
GAME.Players.Left.Paddle.posY = 20;
GAME.Players.Left.Paddle.color = "white";
GAME.Players.Right = {}
GAME.Players.Right.score = 0;
GAME.Players.Right.Paddle = {}
GAME.Players.Right.Paddle.sizeX = 15;
GAME.Players.Right.Paddle.sizeY = 80;
GAME.Players.Right.Paddle.posX = GAME.Board.gameBoard.width - 80;
GAME.Players.Right.Paddle.posY = GAME.Board.gameBoard.height - 100;
GAME.Players.Right.Paddle.color = "white";


console.log("ratio : ", GAME.Board.gameBoard.width / 1000);
console.log("GAME.ratio : ", GAME.ratio);
console.log("width : ", GAME.Board.width);
console.log("heightContainer : ", GAME.Board.container.offsetHeight);
console.log("heightBoard : ", GAME.Board.height);


window.addEventListener("resize", resizeGameBoard);
window.addEventListener("keydown", changeDirection);
menuButton.addEventListener("click", clickMenu);
playButton.addEventListener("click", clickPlay);
quitButton.addEventListener("click", clickQuit);


function resizeGameBoard()
{
    tmpGameBoardWidth = GAME.Board.gameBoard.width;
    
    GAME.Board.width = GAME.Board.container.offsetWidth;
    GAME.Board.height = GAME.Board.container.offsetHeight * 0.8;
    GAME.Board.gameBoard.width = GAME.Board.width;
    GAME.Board.gameBoard.height = GAME.Board.height;

    GAME.ratio = GAME.Board.width / 1000;

    GAME.Players.Left.Paddle.sizeX = 15 * GAME.ratio;
    GAME.Players.Left.Paddle.sizeY = 80 * GAME.ratio;
    GAME.Players.Left.Paddle.posX = 65 * GAME.ratio;
    GAME.Players.Left.Paddle.posY = 20 * GAME.ratio;

    GAME.Players.Right.Paddle.sizeX = 15 * GAME.ratio;
    GAME.Players.Right.Paddle.sizeY = 80 * GAME.ratio;
    GAME.Players.Right.Paddle.posX = GAME.Board.gameBoard.width - (80 * GAME.ratio);
    GAME.Players.Right.Paddle.posY = GAME.Board.gameBoard.height - (100 * GAME.ratio);

    drawPaddles();
}

function changeDirection(event)
{
    const keyPressed = event.keyCode;
    console.log(keyPressed);
}


 gameStart();


function gameStart()
{
    GAME.ratio = GAME.Board.width / 1000;
    drawPaddles();
    createball();
    nextTick();
}

function nextTick()
{
    GAME.intervalID = setTimeout(() => {
        //clearBoard();
        drawPaddles();
        moveBall();
        drawBall(ballX, ballY);
        checkCollision();
        nextTick();
    }, 10)
}

// function clearBoard()
// {
//     context.fillRect(0, 0, gameBoard.width, gameBoard.height);
// }

function drawPaddles()
{
    GAME.Board.context.fillStyle = GAME.Players.Left.Paddle.color;
    GAME.Board.context.fillRect(GAME.Players.Left.Paddle.posX, GAME.Players.Left.Paddle.posY, GAME.Players.Left.Paddle.sizeX, GAME.Players.Left.Paddle.sizeY);
    GAME.Board.context.strokeRect(GAME.Players.Left.Paddle.posX, GAME.Players.Left.Paddle.posY, GAME.Players.Left.Paddle.sizeX, GAME.Players.Left.Paddle.sizeY); 

    GAME.Board.context.fillStyle = GAME.Players.Right.Paddle.color;
    GAME.Board.context.fillRect(GAME.Players.Right.Paddle.posX, GAME.Players.Right.Paddle.posY, GAME.Players.Right.Paddle.sizeX, GAME.Players.Right.Paddle.sizeY);
    GAME.Board.context.strokeRect(GAME.Players.Right.Paddle.posX, GAME.Players.Right.Paddle.posY, GAME.Players.Right.Paddle.sizeX, GAME.Players.Right.Paddle.sizeY); 
}

function createball(){};

function moveBall(){};

function drawBall(ballX, ballY){};

function checkCollision(){};

function updateScore(){};

function clickMenu(){};

function clickPlay(){};

function clickQuit(){};





























// ratioX = 1
// ratioY = 1

// baseSizeX = 800
// gameBoard.width
// function calculateRatioX()
// {
//     ratioX = gameBoard.width /  baseSizeX
// }

// function translateX( val )
// {
//     return val * ratioX
// }

// function translateY( val )
// {
//     return val * ratioY
// }

// function createPaddle( x, y, w, h )
// {
//     PADDLE = {}
//     PADDLE.x = x
//     PADDLE.y = y
//     PADDLE.w = w
//     PADDLE.h = h

//     return PADDLE
// }

// const canvas = document.getElementById("gameBoard");
// const context = canvas.getContext("2d");

// let scoreOne = 0;
// let scoreTwo = 0;

// //key movement
// window.addEventListener("keydown", doKeyDown, false);

// function doKeyDown(e)
// {
//     const key = e.key;
//     if (key == "ArrowUp" && playerOne.y - playerOne.gravity > 0)
//         playerOne.y -= playerOne.gravity * 4;
//     else if (key == "ArrowDown" && playerOne.y + playerOne.height + playerOne.gravity < canvas.height)
//         playerOne.y += playerOne.gravity * 4;
//     if (key == "w" && playerTwo.y - playerTwo.gravity > 0)
//         playerTwo.y -= playerTwo.gravity * 4;
//     else if (key == "s" && playerTwo.y + playerTwo.height + playerTwo.gravity < canvas.height)
//         playerTwo.y += playerTwo.gravity * 4;
// }

// class Element
// {
//     constructor(options)
//     {
//         this.x = options.x;
//         this.y = options.y;
//         this.width = options.width;
//         this.height = options.height;
//         this.color = options.color;
//         this.speed = options.speed || 2;
//         this.gravity = options.gravity;
//     }
// }

// //first paddle
// const playerOne = new Element
// ({
//     x: 10,
//     y: 200,
//     width: 15,
//     height: 80,
//     color: "#fff",
//     gravity: 2,
// });

// //second paddle
// const playerTwo = new Element
// ({
//     x: 625,
//     y: 200,
//     width: 15,
//     height: 80,
//     color: "#fff",
//     gravity: 2,
// });

// //ball
// const ball = new Element
// ({
//     x: 650/2,
//     y: 400/2,
//     width: 15,
//     height: 15,
//     color: "#20C20E",
//     speed: 1,
//     gravity: 1,
// });

// //player one score text
// function displayScoreOne()
// {
//     context.front = "18px Arial";
//     context.fillStyle = "#fff";
//     context.fillText(scoreOne, canvas.width / 2 - 60, 30);
// }

// //player two score text
// function displayScoreTwo()
// {
//     context.front = "18px Arial";
//     context.fillStyle = "#fff";
//     context.fillText(scoreTwo, canvas.width / 2 + 60, 30);
// }

// //make ball bounce
// function ballBounce()
// {
//     if (ball.y + ball.gravity <= 0 || ball.y + ball.gravity >= canvas.height)
//     {
//         ball.gravity = ball.gravity * -1;
//         ball.x += ball.speed;
//         ball.y += ball.gravity;
//     }
//     else
//     {
//         ball.x += ball.speed;
//         ball.y += ball.gravity;  
//     }
//     ballWallCollision();
// }

// //detect collision
// function ballWallCollision()
// {
//     if (ball.y + ball.gravity <= playerTwo.y + playerTwo.height
//         && ball.x + ball.width + ball.speed >= playerTwo.x
//         && ball.y + ball.gravity > playerTwo.y
//         || ball.y + ball.gravity <= playerOne.y + playerOne.height
//         && ball.x + ball.width + ball.speed >= playerOne.x
//         && ball.y + ball.gravity > playerOne.y)
//             ball.speed = ball.speed * -1;
//         else if (ball.x + ball.speed < playerOne.x)
//         {
//             scoreTwo += 1;
//             ball.speed = ball.speed * -1;
//             ball.x = 100 + ball.speed;
//             ball.y += ball.gravity;
//         }
//         else if (ball.x + ball.speed > playerTwo.x + playerTwo.width)
//         {
//             scoreOne += 1;
//             ball.speed = ball.speed * -1;
//             ball.x = 100 + ball.speed;
//             ball.y += ball.gravity;
//         }
//     drawElements();
// }

// //draw element
// function drawElement(element)
// {
//     context.fillStyle = element.color;
//     context.fillRect(element.x, element.y, element.width, element.height);
// }

// function drawElements()
// {
//     context.clearRect(0, 0, canvas.width, canvas.height);
//     drawElement(playerOne);
//     drawElement(playerTwo);
//     drawElement(ball);
//     displayScoreOne();
//     displayScoreTwo();
// }

// function loop()
// {
//     ballBounce();
//     window.requestAnimationFrame(loop);
// }
// loop();
























