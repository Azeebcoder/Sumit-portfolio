function navlinks_mobile() {
    let menubtn = document.querySelector(".menu");
    let linkbtns = document.querySelector(".right-nav");
    let links = document.querySelectorAll(".right-nav ul li a");
    console.log(links);

    menubtn.addEventListener("click", () => {
        menubtn.classList.toggle("toggle");
        linkbtns.classList.toggle("nav-show");
        links.forEach((link, index) => {
            link.style.animation = 'none';
            setTimeout(() => {
                link.style.animation = `navlinksfade 0.5s ease forwards ${index / 7}s`;
            }, 0);
        });
    })

}
navlinks_mobile();

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
        displayskills(allskills.slice(0, 4));
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
    } else {
        projectcontainer.innerHTML = '';
        displayProjects(allProjects.slice(0, 3));
        projectbtn.innerHTML = 'Show Projects \u00A0 <i class="fa-solid fa-eye"></i>'; // Change button text
        flag = true;
    }
});
let flag1 = true;
skillbtn.addEventListener("click", () => {
    if (allskills.length > 4 && flag1) {
        displayskills(allskills.slice(4)); // Show all projects when button is clicked
        skillbtn.innerHTML = 'Hide skills \u00A0 <i class="fa-solid fa-eye-slash"></i>'; // Change button text
        flag1 = false;
    } else {
        skillscontainer.innerHTML = '';
        displayskills(allskills.slice(0, 4));
        skillbtn.innerHTML = 'Show Skills \u00A0 <i class="fa-solid fa-eye"></i>';
        flag1 = true;
    }

});

function displayskills(skills) {
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

function createskillcard(item) {
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
        <div class="background-image" style="background-image: linear-gradient(rgba(0,0,0,.3),rgba(0,0,0,.8)),url('${item.image}');">
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


