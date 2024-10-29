const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

let circles = [];
const CIRCLE_COUNT = 70; // Constant for the number of circles
const FADE_DURATION = 2000; // Duration for fade-in effect (in milliseconds)
const CONNECTION_DISTANCE = 110; // Max distance to connect circles

// Resize canvas to match its parent container dimensions
function resizeCanvas() {
    const parent = canvas.parentElement;
    canvas.width = parent.clientWidth;
    canvas.height = parent.clientHeight;
}

resizeCanvas();
window.addEventListener('resize', resizeCanvas);

// Function to create circles
function createCircles() {
    for (let i = 0; i < CIRCLE_COUNT; i++) {
        circles.push({
            x: Math.random() * canvas.width,
            y: Math.random() * canvas.height,
            radius: Math.random() * 5 + 2,
            angle: Math.random() * Math.PI * 2,
            speed: Math.random() * 1 + 0.5,
            creationTime: Date.now()
        });
    }
}

// Function to draw circles
function drawCircles() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    circles.forEach(circle => {
        const elapsed = Date.now() - circle.creationTime;
        const alpha = Math.min(elapsed / FADE_DURATION, 1);

        ctx.beginPath();
        ctx.arc(circle.x, circle.y, circle.radius, 0, Math.PI * 2);
        ctx.fillStyle = `rgba(224, 225, 221, ${alpha * 0.5})`;
        ctx.fill();

        updateCirclePosition(circle);
    });

    connectCircles();
}

// Update the position of the circle
function updateCirclePosition(circle) {
    circle.x += Math.cos(circle.angle) * circle.speed;
    circle.y += Math.sin(circle.angle) * circle.speed;

    if (circle.x + circle.radius > canvas.width) {
        circle.x = canvas.width - circle.radius;
        circle.angle = Math.PI - circle.angle;
    } else if (circle.x - circle.radius < 0) {
        circle.x = circle.radius;
        circle.angle = Math.PI - circle.angle;
    }

    if (circle.y + circle.radius > canvas.height) {
        circle.y = canvas.height - circle.radius;
        circle.angle = -circle.angle;
    } else if (circle.y - circle.radius < 0) {
        circle.y = circle.radius;
        circle.angle = -circle.angle;
    }
}

// Function to connect circles
function connectCircles() {
    ctx.lineWidth = 1;

    for (let i = 0; i < circles.length; i++) {
        for (let j = i + 1; j < circles.length; j++) {
            const dist = Math.hypot(circles[i].x - circles[j].x, circles[i].y - circles[j].y);
            const alphaI = Math.min((Date.now() - circles[i].creationTime) / FADE_DURATION, 1);
            const alphaJ = Math.min((Date.now() - circles[j].creationTime) / FADE_DURATION, 1);
            const minAlpha = Math.min(alphaI, alphaJ);

            const lineAlpha = (dist < CONNECTION_DISTANCE) ? minAlpha * 0.5 : 0;

            if (lineAlpha > 0) {
                ctx.strokeStyle = `rgba(224, 225, 221, ${lineAlpha})`;
                ctx.beginPath();
                ctx.moveTo(circles[i].x, circles[i].y);
                ctx.lineTo(circles[j].x, circles[j].y);
                ctx.stroke();
            }
        }
    }
}

// Animation loop
function animate() {
    drawCircles();
    requestAnimationFrame(animate);
}

createCircles();
animate();


// Typing animation for skills
let typed = new Typed("#skills-changing", {
    strings: [
        "Web Developer",
        "Coder",
        "Software Developer",
        "Programmer",
        "Computer Operator"
    ],
    typeSpeed: 100,
    backSpeed: 70,
    loop: true,
    showCursor: true,
    cursorChar: '|'
});
// Select all elements that should animate
const sections = document.querySelectorAll('.animation');
const observerOptions = { threshold: 0 };

// Create an intersection observer
const observer = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            entry.target.classList.add('animation-in-view');
        } else {
            entry.target.classList.remove('animation-in-view');
        }
    });
}, observerOptions);

// Observe all sections for scroll animations
sections.forEach(section => observer.observe(section));

// Load projects button functionality
const projectbtn = document.querySelector("#show-more-btn");
const projectcontainer = document.getElementById('project-boxes');
const skillscontainer = document.getElementById('skill-boxes');
const skillbtn = document.querySelector('#show-skills-btn')

let allProjects = [];
let allskills = [];


window.addEventListener("load", async () => {
    showLoading(projectcontainer); // Show loading indicator

    try {
        allskills = await fetchData('./details/skills.json');
        console.log(allskills);
        allProjects = await fetchData('./details/projects.json');
        projectcontainer.innerHTML = '';
        skillscontainer.innerHTML = '';

        // Show only the first 4 projects initially
        displayProjects(allProjects.slice(0, 3));
        displayskills(allskills.slice(0,4));
    } catch (error) {
        showError(projectcontainer, 'Failed to load projects.');
        console.error('Error fetching JSON:', error);
    }
});

let flag = true;
projectbtn.addEventListener("click", () => {
    if (allProjects.length > 3 && flag) {
        displayProjects(allProjects.slice(3)); // Show all projects when button is clicked
        projectbtn.innerHTML = 'Hide Projects \u00A0 <i class="fa-solid fa-eye-slash"></i>'; // Change button text
        flag = false;
    } else{
        projectcontainer.innerHTML = '';
        displayProjects(allProjects.slice(0,3));
        projectbtn.innerHTML = 'Show Projects \u00A0 <i class="fa-solid fa-eye"></i>'; // Change button text
        flag = true;
    }
});
flag = true;
skillbtn.addEventListener("click", () => {
    if (allskills.length > 4 && flag) {
        displayskills(allskills.slice(4)); // Show all projects when button is clicked
        skillbtn.innerHTML = 'Hide skills \u00A0 <i class="fa-solid fa-eye-slash"></i>'; // Change button text
        flag = false;
    } else{
        skillscontainer.innerHTML = '';
        displayskills(allskills.slice(0,4));
        skillbtn.innerHTML = 'Show Skills \u00A0 <i class="fa-solid fa-eye"></i>';
        flag = true;
    }

});

function displayskills(skills){
    skills.forEach(skill => {
        const card = createskillcard(skill);
        skillscontainer.appendChild(card);
        
        // Observe the card for scroll animation
        observer.observe(card);
    });
}

function displayProjects(projects) {
    projects.forEach(item => {
        const card = createprojectcard(item);
        projectcontainer.appendChild(card);
        
        // Observe the card for scroll animation
        observer.observe(card);
    });
}

// Fetch data function with error handling
async function fetchData(url) {
    const response = await fetch(url);
    if (!response.ok) {
        throw new Error('Network response was not ok');
    }
    return await response.json();
}

function createskillcard(item){
    const card = document.createElement('div');
    card.classList.add("skill-box", "animation", "animation-bottom");

    // Set up the card's inner HTML structure
    card.innerHTML = `
        <img src="${item.image}" alt="${item.title}">
        <h2>${item.title}</h2>
    `;

    return card;
}

// Function to create each project card
function createprojectcard(item) {
    const card = document.createElement('div');
    card.classList.add('skill-box', 'project-box', 'animation', 'animation-bottom');

    // Set up the card's inner HTML structure
    card.innerHTML = `
        <div class="background-image" style="background-image: linear-gradient(rgba(0,0,0,.1),rgba(0,0,0,.4)),url('${item.image}');">
            <div class="project-content">
                <div class="project-box-content">
                    <h2>${item.title || 'Untitled Project'}</h2>
                    <p>${item.description || 'No description available.'}</p>
                    <div class="btns projects-btn">
                        <a href="${item.view || '#'}" class="btn btn-white" target="_blank" rel="noopener noreferrer">View</a>
                        <a href="${item.source || '#'}" class="btn btn-white" target="_blank" rel="noopener noreferrer">Source</a>
                    </div>
                </div>
            </div>
        </div>
    `;

    return card;
}

// Loading indicator
function showLoading(container) {
    const loadingMessage = document.createElement('p');
    loadingMessage.textContent = 'Loading projects...';
    loadingMessage.classList.add('loading-message');
    projectcontainer.appendChild(loadingMessage);
}

// Error message display
function showError(container, message) {
    projectcontainer.innerHTML = `<p class="error-message" style="color: red; text-align: center;">${message}</p>`;
}