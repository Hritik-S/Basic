const express =require('express');
const cors =require('cors');

const app=express();
app.use(cors());
app.use(express.json());
app.get("/get",async(req,res)=>{
    //console.log(req);
    res.send(req.query);
});
app.get("/",async(req,res)=>{res.send("Server is Running");});
const PORT = 6584;
const HOST = "localhost";
app.listen(PORT,HOST,()=>{
    console.log(`Server Running at http://${HOST}:${PORT}`);
})