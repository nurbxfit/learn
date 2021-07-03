const express = require('express');

const app = express();

app.get('/',(req,res,next)=>{
    res.send("Hello Docker");
})

const PORT = 4000 || process.env.PORT;
app.listen(PORT,()=>{
    console.log(`Server Started on port ${PORT}`)
})