const express = require("express");
const cors = require("cors");
const mongoose = require("mongoose");

const app = express();

app.use(cors());
app.use(express.json());

mongoose.connect("mongodb://localhost:27017/local");

const User = mongoose.model(
  "users",
  {
    uname: String,
    pass: String,
  }
);

app.post("/demo", async (req, res) => {
  let user = await User.findOne(req.body);

  if (user)
    res.json("Login Success");
  else
    res.json("Invalid Username or Password");
});

app.listen(8080);