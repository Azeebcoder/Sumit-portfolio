const content = document.querySelector("#code");

function getQueryParams() {
    const params = new URLSearchParams(window.location.search); // Get query parameters
    const name = params.get('name');
    return name;
}
const data = getQueryParams();
let value ;
window.addEventListener("load", async () => {

    try {
        alldata = await fetchData('../details/projects.json');
        const userIdToFind = data;
        const code = alldata.find(code => code.title === userIdToFind);
        fetch(code.codes)
            .then(response => {
                if (!response.ok) {
                    throw new Error('Network response was not ok');
                }
                return response.text();
            })
            .then(data => {
                const formattedCode = `${escapeHtml(data)}`;
                content.innerHTML = formattedCode;
                value = data;     
                hljs.highlightAll();
            })
    } catch (error) {
        console.log("error")
    }
});

async function fetchData(url) {
    const response = await fetch(url);
    if (!response.ok) {
        throw new Error('Network response was not ok');
    }
    return await response.json();
}



function escapeHtml(unsafe) {
    return unsafe
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;")
        .replace(/"/g, "&quot;")
        .replace(/'/g, "&#039;");
}

var copybtn = document.querySelector(".copy-code-btn button");
copybtn.addEventListener("click",copyText);
copybtn.addEventListener("click",()=>{
    copybtn.innerHTML = `<i class="fa-solid fa-check"></i> &nbsp; Copied`;
});

function copyText() {
    
    // Use the Clipboard API to copy text
    navigator.clipboard.writeText(value);
}