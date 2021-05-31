const tray = document.querySelector(".tray__container");
const slots = document.querySelectorAll(".row .tray__slots:not(.empty)");
const count = document.getElementById("count");
const traySelect = document.getElementById("tray");
const trayname = document.getElementById("trayname");

trayname.innerText = traySelect.value;

let index = null;
//populate ui with localstorage data
function populateUI() {
  count.innerText = 0;
  const occupied = JSON.parse(localStorage.getItem(trayname.innerText));
  slots.forEach((slot) => {
    slot.classList.remove("empty");
    slot.classList.remove("selected");
  });
  if (occupied !== null) {
    console.log(occupied);
    occupied.forEach((element) => {
      slots[element].classList.add("empty");
    });
  }
}

function saveIndex() {
  if (index !== null) {
    localStorage.setItem(trayname.innerText, JSON.stringify(index));
    index = null;
  }
}
//add event listener
tray.addEventListener("click", function (e) {
  e.preventDefault();
  const slot = e.target;
  if (
    slot.classList.contains("tray__slots") &&
    !slot.classList.contains("empty")
  ) {
    // console.log(slot);
    slot.classList.toggle("selected");
    const selected = document.querySelectorAll(".row .tray__slots.selected");
    const scount = selected.length;
    count.innerText = scount;

    //store selected index
    index = JSON.parse(localStorage.getItem(trayname.innerText));
    const sindex = [...selected].map((egg) => [...slots].indexOf(egg));
    console.log("index:", index);
    console.log("sindex:", sindex);
    index = index !== null ? [...index, ...sindex] : [...sindex];
    //local storage take key value pair strings.
    console.log("Storing:", index);
  }
});

//tray select event
traySelect.addEventListener("change", (e) => {
  saveIndex();
  trayname.innerText = e.target.value;
  populateUI();
});

populateUI();
