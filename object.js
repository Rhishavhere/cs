const car ={
  brand: "Toyota",
  model: "Land Cruiser",
  year: 2023,
  color: "black"
}

console.log("Original")
for(let key in car){
  console.log(`${key}: ${car[key]}`)
}

const keys = Object.keys(car)
const secp = keys[1]
delete car[secp]
for(let key in car){
  console.log(`${key}: ${car[key]}`)
}

console.log('\nLength of the object:', keys.length);
console.log(car)