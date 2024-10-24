const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

let circles = [];
const circleCount = 70;

// Resize canvas to match its parent container dimensions
function resizeCanvas() {
    const parent = canvas.parentElement;
    canvas.width = parent.clientWidth;
    canvas.height = parent.clientHeight;
}

resizeCanvas(); // Call once on initial load
window.addEventListener('resize', resizeCanvas);

function createCircles() {
    for (let i = 0; i < circleCount; i++) {
        circles.push({
            x: Math.random() * canvas.width,
            y: Math.random() * canvas.height,
            radius: Math.random() * 5 + 2, // Set a minimum radius to ensure visibility
            angle: Math.random() * Math.PI * 2,
            speed: Math.random() * 1 + 0.5, // Adjust speed for better movement
            creationTime: Date.now() // Track creation time
        });
    }
}

function drawCircles() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    circles.forEach(circle => {
        const elapsed = Date.now() - circle.creationTime;
        const alpha = Math.min(elapsed / 2000, 1); // Fade-in over 2 seconds

        ctx.beginPath();
        ctx.arc(circle.x, circle.y, circle.radius, 0, Math.PI * 2);
        ctx.fillStyle = `rgba(224, 225, 221, ${alpha * 0.5})`; // Apply alpha
        ctx.fill();

        // Update position based on angle and speed
        circle.x += Math.cos(circle.angle) * circle.speed;
        circle.y += Math.sin(circle.angle) * circle.speed;

        // Reset position if circles go off canvas (considering radius)
        if (circle.x + circle.radius > canvas.width) {
            circle.x = canvas.width - circle.radius; // Move back inside
            circle.angle = Math.PI - circle.angle; // Reverse direction
        } else if (circle.x - circle.radius < 0) {
            circle.x = circle.radius; // Move back inside
            circle.angle = Math.PI - circle.angle; // Reverse direction
        }

        if (circle.y + circle.radius > canvas.height) {
            circle.y = canvas.height - circle.radius; // Move back inside
            circle.angle = -circle.angle; // Reverse direction
        } else if (circle.y - circle.radius < 0) {
            circle.y = circle.radius; // Move back inside
            circle.angle = -circle.angle; // Reverse direction
        }
    });

    connectCircles();
}

function connectCircles() {
    ctx.lineWidth = 1;

    for (let i = 0; i < circles.length; i++) {
        for (let j = i + 1; j < circles.length; j++) {
            const dist = Math.hypot(circles[i].x - circles[j].x, circles[i].y - circles[j].y);
            const alphaI = Math.min((Date.now() - circles[i].creationTime) / 2000, 1);
            const alphaJ = Math.min((Date.now() - circles[j].creationTime) / 2000, 1);
            const minAlpha = Math.min(alphaI, alphaJ);

            // Control line alpha based on distance
            const lineAlpha = (dist < 110) ? minAlpha * 0.5 : 0;

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





// Select the about section
const Sections = document.querySelectorAll('.animation');

// Create the Intersection Observer
const observer = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            // Add the 'in-view' class when the element is in the viewport
            entry.target.classList.add('animation-in-view');
        } else {
            // Remove the 'in-view' class only when the element is completely out of the viewport
            if (entry.boundingClientRect.top > window.innerHeight || entry.boundingClientRect.bottom < 0) {
                entry.target.classList.remove('animation-in-view');
            }
        }
    });
}, {
    threshold: 0 // Trigger as soon as any part of the section is in the viewport
});
Sections.forEach(section => {
    observer.observe(section);
});
