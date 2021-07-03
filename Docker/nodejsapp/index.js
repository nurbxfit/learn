const express = require('express');

const app = express();

app.get('/',(req,res,next)=>{
    res.send("<h1>Hello Mr. Docker </h1>");
})

const PORT = 4000 || process.env.PORT;
app.listen(PORT,()=>{
    console.log(`Server Started on port ${PORT}`)
})