const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

let circles = [];
const circleCount = 60; // Increased count for more circles

function createCircles() {
    for (let i = 0; i < circleCount; i++) {
        circles.push({
            x: Math.random() * canvas.width,
            y: Math.random() * canvas.height,
            radius: Math.random() * 5 + 0, // Small circles
            angle: Math.random() * Math.PI * 2,
            speed: Math.random() * 0.5 + .7, // Speed of movement
            creationTime: Date.now() // Track creation time
        });
    }
}

function drawCircles() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    circles.forEach(circle => {
        // Calculate elapsed time and determine alpha for fade-in
        const elapsed = Date.now() - circle.creationTime;
        const alpha = Math.min(elapsed / 2000, 1); // Fade-in over 2 seconds

        ctx.beginPath();
        ctx.arc(circle.x, circle.y, circle.radius, 0, Math.PI * 2);
        ctx.fillStyle = `rgba(224, 225, 221, ${alpha * 0.5})`; // Apply alpha
        ctx.fill();

        // Update position for movement
        circle.x += Math.cos(circle.angle) * circle.speed;
        circle.y += Math.sin(circle.angle) * circle.speed;

        // Reset position if circles go off canvas
        if (circle.x > canvas.width || circle.x < 0 || circle.y > canvas.height || circle.y < 0) {
            circle.x = Math.random() * canvas.width;
            circle.y = Math.random() * canvas.height;
            circle.angle = Math.random() * Math.PI * 2; // Randomize angle on reset
            circle.creationTime = Date.now(); // Reset creation time
        }
    });

    connectCircles();
}

function connectCircles() {
    ctx.lineWidth = 1;

    for (let i = 0; i < circles.length; i++) {
        for (let j = i + 1; j < circles.length; j++) {
            const dist = Math.hypot(circles[i].x - circles[j].x, circles[i].y - circles[j].y);
            const elapsedI = Date.now() - circles[i].creationTime;
            const elapsedJ = Date.now() - circles[j].creationTime;
            const alphaI = Math.min(elapsedI / 2000, 1); // Circle 1 fade-in
            const alphaJ = Math.min(elapsedJ / 2000, 1); // Circle 2 fade-in
            const minAlpha = Math.min(alphaI, alphaJ);

            // Control line alpha based on distance
            const lineAlpha = (dist < 110) ? minAlpha * 0.5 : 0; // Apply alpha only if within distance

            if (lineAlpha > 0) {
                ctx.strokeStyle = `rgba(224, 225, 221, ${lineAlpha})`; // Apply line alpha
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
