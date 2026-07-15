const express = require("express");
const cors = require("cors");
const mongoose = require("mongoose");

const app = express();

app.use(cors());
app.use(express.json());

mongoose.connect("mongodb://localhost:27017/local");

const Fruit = mongoose.model(
  "fruits",
  {
    fname: String,
    price: Number,
  }
);

app.post("/demo", async (req, res) => {
  let fruit = await Fruit.create(req.body);
  res.json(fruit);
});

app.get("/data", async (req, res) => {
  let fruits = await Fruit.find();
  res.json(fruits);
});

app.listen(8080);