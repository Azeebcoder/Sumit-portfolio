const content = document.querySelector("#code");
function getQueryParams() {
    const params = {};
    const queryString = window.location.search.substring(1);
    const pairs = queryString.split('&');
    pairs.forEach(pair => {
        const [key, value] = pair.split('=');
        params[decodeURIComponent(key)] = decodeURIComponent(value);
    });
    return params;
}
let add;
const data = getQueryParams();
window.addEventListener("load", async () => {

    try {
        alldata = await fetchData('/details/projects.json');
        const userIdToFind = data.name;
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