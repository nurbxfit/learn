const express = require('express');
const redis = require('redis');
const path = require('path');

const app = express();
const client =  redis.createClient({
    host: 'redis-server',
    port: 6379
});

//init redis db
client.set('name',"");

//set our view engine
app.set('view engine','ejs');
app.set('views','views');

//set body parse to parse request body.
app.use(express.urlencoded({extended:false}));
app.use(express.static(path.join(__dirname,'public')));


//ROUTES
app.get("/",(req,res)=>{
    //get from redis
    client.get('name',(err,name)=>{
        if(err) return res.status(500).send("Something Bad Happend");
        res.status(200).render('index',{key:name});
    })
});

app.post("/submit",(req,res)=>{
    const {keyword} = req.body;
    client.set('name',keyword);
    res.redirect('/');

})


const PORT = 5000 || process.env.PORT
app.listen(PORT,()=>{
    console.log(`Server listening on http://localhost:${PORT}/`)
})