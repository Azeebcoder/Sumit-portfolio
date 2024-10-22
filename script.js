const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

let circles = [];
const circleCount = 80; // Increased count for more circles

function createCircles() {
    for (let i = 0; i < circleCount; i++) {
        circles.push({
            x: Math.random() * canvas.width,
            y: Math.random() * canvas.height,
            radius: Math.random() * 5 + 2, // Small circles
            angle: Math.random() * Math.PI * 2,
            speed: Math.random() * 0.5 + 1 // Speed of movement
        });
    }
}

function drawCircles() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    circles.forEach(circle => {
        ctx.beginPath();
        ctx.arc(circle.x, circle.y, circle.radius, 0, Math.PI * 2);
        ctx.fillStyle = 'rgba(224, 225, 221,0.5)';
        ctx.fill();

        // Update position for movement
        circle.x += Math.cos(circle.angle) * circle.speed;
        circle.y += Math.sin(circle.angle) * circle.speed;

        // Reset position if circles go off canvas
        if (circle.x > canvas.width || circle.x < 0 || circle.y > canvas.height || circle.y < 0) {
            circle.x = Math.random() * canvas.width;
            circle.y = Math.random() * canvas.height;
            circle.angle = Math.random() * Math.PI * 2; // Randomize angle on reset
        }
    });

    connectCircles();
}

function connectCircles() {
    ctx.strokeStyle = 'rgba(224, 225, 221,0.5)';
    ctx.lineWidth = 1;

    for (let i = 0; i < circles.length; i++) {
        for (let j = i + 1; j < circles.length; j++) {
            const dist = Math.hypot(circles[i].x - circles[j].x, circles[i].y - circles[j].y);
            if (dist < 100) { // Adjust the distance threshold as needed
                ctx.beginPath();
                ctx.moveTo(circles[i].x, circles[i].y);
                ctx.lineTo(circles[j].x, circles[j].y);
                ctx.stroke();
            }
        }
    }
}

function animate() {
    drawCircles();
    requestAnimationFrame(animate);
}

createCircles();
animate();
