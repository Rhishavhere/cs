const express = require("express");
const cors = require("cors");
const mongoose = require("mongoose");

const app = express();

app.use(cors());
app.use(express.json());

mongoose.connect("mongodb://127.0.0.1:27017/local")
  .then(() => console.log("DB Connected"));

const User = mongoose.model(
  "studs",
  new mongoose.Schema({
    usn: String,
    name: String,
    sem: Number,
    year: Number,
  })
);

app.post("/demo", async (req, res) => {
  const user = await User.create(req.body);
  console.log('Input Data : ', user);
  res.json(user);
});

app.get("/data", async (req, res) => {
  const users = await User.find();
  res.json(users);
});

app.listen(8080, () => {
  console.log("Server Started");
});