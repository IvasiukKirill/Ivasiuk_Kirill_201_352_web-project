let apiKey = "718962b4-44fd-4416-bdb1-1a6e94d61a38";
let apiUrl = "http://exam-2022-1-api.std-900.ist.mospolytech.ru/api/restaurants";
let restaurantsJson;

async function getRestaurants() {
    let url = new URL(apiUrl);
    url.searchParams.set('api_key', apiKey);
    let response = await fetch(url);

    let json = await response.json();
    restaurantsJson = json;
    return json;
}
function createRestaurantTableItem(record) {
    let item = document.querySelector("#tr-template").cloneNode(true)
    item.classList.remove("d-none")
    item.querySelector(".restaurant-name").innerHTML = record.name
    item.querySelector(".restaurant-type").innerHTML = record.typeObject
    item.querySelector(".restaurant-addr").innerHTML = record.address
    item.querySelector(".restaurant-id").value = record.id

    return item
}

function renderRecords(records) {
  let restaurantTable = document.querySelector("tbody");
  for (let i = 0; i < records.length; i++) {
    restaurantTable.append(createRestaurantTableItem(records[i]));
  }
  getFilter();
}





function filterRecords() {
  let selectedAdm = document.getElementById("area").value;
  let selectedDistrict = document.getElementById("district").value;
  let selectedType = document.getElementById("type").value;
  let selectedDiscount = document.getElementById("discount").value;

  let restaurantTable = document.querySelector("tbody");
  while (restaurantTable.children.length > 1) {
    restaurantTable.removeChild(restaurantTable.lastChild);
  }
    
  for (let i = 0; i < restaurantsJson.length; i++) {
    if (
        
      (selectedAdm == "Not selected" ||
        selectedAdm == restaurantsJson[i].admArea) &&
      (selectedDistrict == "Not selected" ||
        selectedDistrict == restaurantsJson[i].district) &&
      (selectedDiscount == "Not selected" ||
        selectedDiscount == restaurantsJson[i].socialPrivileges) &&
      (selectedType == "Not selected" ||
        selectedType == restaurantsJson[i].typeObject)
    ) {
      restaurantTable.append(createRestaurantTableItem(restaurantsJson[i]));
    }
  }
}

function getFilter() {
  var arrType = [];
  for (let i = 0; i < restaurantsJson.length; i++) {
    arrType.push(restaurantsJson[i].typeObject);
  }
  var unarr = new Set(arrType);

  for (let value of unarr) {
    let qwe = document.createElement("option");
    qwe.innerHTML = value;
    document.querySelector("#type").appendChild(qwe);
  }

  var arrAdm = [];
  for (let i = 0; i < restaurantsJson.length; i++) {
    arrAdm.push(restaurantsJson[i].admArea);
  }
  var unarr = new Set(arrAdm);

  for (let value of unarr) {
    let qwe = document.createElement("option");
    qwe.innerHTML = value;
    document.querySelector("#area").appendChild(qwe);
  }

  var arrDistrict = [];
  for (let i = 0; i < restaurantsJson.length; i++) {
    arrDistrict.push(restaurantsJson[i].district);
  }
  var unarr = new Set(arrDistrict);

  for (let value of unarr) {
    let qwe = document.createElement("option");
    qwe.innerHTML = value;
    document.querySelector("#district").appendChild(qwe);
  }
}

function renderSets() {
    let dish = document.querySelector("#card");
    let dishParent = dish.closest(".row");

    for (let i = 0; i < 9; i++) {
        let newDish = document.createElement("div");
        newDish.className = "col";
        newDish.innerHTML = dish.innerHTML;
        dishParent.appendChild(newDish);
    }

    let dishes = document.querySelectorAll(".card");

    let xhr = new XMLHttpRequest();
    xhr.open("GET", "http://161.97.92.112:30005/api/sets");
    xhr.responseType = "json";
    xhr.onload = function () {
        let data = this.response;
        for (let i = 0; i < data.length; i++) {
            dishes[i].querySelector("img").src = data[i]["img"];
            dishes[i].querySelector("h5").innerHTML = data[i]["name"];
            dishes[i].querySelector("p").innerHTML = data[i]["text"];
            dishes[i].querySelector("h6").innerHTML = filterRecords[i]["set_" + (i + 1).toString()] + "&#8381;";
        }
        filterRecords = data;
    }
    xhr.send();
}

function renderModal(count, options) {
    let setsList = document.querySelector(".list-group");
    let pattern = document.querySelector(".list-group-item.d-flex.justify-content-between").innerHTML;
    setsList.innerHTML = "";

    for (let i = 0; i < count.length; i++) {
        if (count[i] != 0) {
            let set = document.createElement("li");
            set.classList = "list-group-item d-flex justify-content-between";
            set.innerHTML = pattern;

            count[i] = options[0] ? count[i] * 2 : count[i];

            set.querySelector("img").src = `./img/${i + 1}.jpg`;
            set.querySelectorAll("h6")[0].innerHTML = setsBase[i].name;
            set.querySelector("p").innerHTML = count[i].toString() + "x" + filteredBase[currentRestaurant]["set_" + (i + 1).toString()] + "&#8381;";
            if (options[0]) {
                set.querySelectorAll("h6")[1].innerHTML = count[i] / 5 * filteredBase[currentRestaurant]["set_" + (i + 1).toString()] * 2.5 + "&#8381;"
            }
            else { 
                set.querySelectorAll("h6")[1].innerHTML = count[i] * filteredBase[currentRestaurant]["set_" + (i + 1).toString()] + "&#8381;"; 
            }

            setsList.append(set);
        }
    }

    let optionsContainer = document.querySelector("#options-container");
    optionsContainer.innerHTML = "";

    let firsOption = document.createElement("p");
    firsOption.innerHTML = options[0] ? "-10%" : "Нет";
    optionsContainer.appendChild(firsOption);

    let secondOption = document.createElement("p");
    secondOption.innerHTML = options[1] ? "+250% and x5 of sets" : "Нет";
    optionsContainer.appendChild(secondOption);

    document.querySelector("#modal-name").innerHTML = filteredBase[currentRestaurant].name;
    document.querySelector("#modal-AU").innerHTML = filteredBase[currentRestaurant].admArea;
    document.querySelector("#modal-district").innerHTML = filteredBase[currentRestaurant].district;
    document.querySelector("#modal-address").innerHTML = filteredBase[currentRestaurant].address;
    document.querySelector("#modal-rating").innerHTML = filteredBase[currentRestaurant].rate;
}


window.onload = function () {
  getRestaurants().then(renderRecords);
  document.querySelector("#find").onclick = filterRecords;
  renderSets();
  renderModal(count, options);
};
