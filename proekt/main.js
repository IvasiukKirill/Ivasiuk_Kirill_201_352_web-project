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


window.onload = function () {
  getRestaurants().then(renderRecords);
  document.querySelector("#find").onclick = filterRecords;
};



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