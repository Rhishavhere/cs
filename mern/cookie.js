const express = require('express')
const cookieParser = require('cookie-parser')

const app = express()
app.use(cookieParser())

app.get('/setcookie', function(req,res){
  res.cookie('my-cookie', 'Welcome Here mf')
  res.send('Cookies Added')
})

app.get('/getcookie', function(req, res){
  res.send(req.cookies)
})

app.listen(3000, ()=>{
  console.log("Server Running on http://localhost:3000/setcookie")
  console.log("Server Running on http://localhost:3000/getcookie")
})