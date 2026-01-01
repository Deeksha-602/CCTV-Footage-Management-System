// Load existing data
let footageData = JSON.parse(localStorage.getItem("footageData")) || [];

/* ---------- ADD FOOTAGE ---------- */
function addFootage() {
    const cam = document.getElementById("cameraId").value.trim();
    const date = document.getElementById("date").value.trim();
    const time = document.getElementById("time").value.trim();
    const duration = document.getElementById("duration").value.trim();
    const location = document.getElementById("locationInput").value.trim();
    const status = document.getElementById("status");

    if (!cam || !date || !time || !duration || !location) {
        status.innerText = "All fields are mandatory!";
        status.style.color = "red";
        return;
    }

    const record = {
        cameraId: cam,
        date,
        time,
        duration,
        location
    };

    footageData.push(record);
    localStorage.setItem("footageData", JSON.stringify(footageData));

    status.innerText = "Footage saved successfully";
    status.style.color = "lightgreen";

    clearForm();
}

/* ---------- CLEAR FORM ---------- */
function clearForm() {
    document.getElementById("cameraId").value = "";
    document.getElementById("date").value = "";
    document.getElementById("time").value = "";
    document.getElementById("duration").value = "";
    document.getElementById("locationInput").value = "";
}

/* ---------- RENDER CARDS ---------- */
function renderCards() {
    const container = document.getElementById("cardContainer");
    if (!container) return;

    container.innerHTML = "";

    if (footageData.length === 0) {
        container.innerHTML = "<p style='color:white;'>No footage records found</p>";
        return;
    }

    footageData.forEach(f => {
        const card = document.createElement("div");
        card.className = "footage-card";

        card.innerHTML = `
            <h3>Camera ID: ${f.cameraId}</h3>
            <p><b>Date:</b> ${f.date}</p>
            <p><b>Time:</b> ${f.time}</p>
            <p><b>Duration:</b> ${f.duration} mins</p>
            <p><b>Location:</b> ${f.location}</p>
        `;

        container.appendChild(card);
    });
}

/* ---------- AUTO LOAD RECORDS ---------- */
document.addEventListener("DOMContentLoaded", renderCards);
