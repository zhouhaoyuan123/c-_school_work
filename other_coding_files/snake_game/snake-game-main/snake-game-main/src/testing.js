ws = new WebSocket("ws://127.0.0.1:8082");//create websocket
function send() {
    var message = window.prompt()//user-typed message;
    ws.send(message);//send it
}
ws.addEventListener("open",(event)=>{
    console.log("opened!");
    send()//trigger alert
});//socket opened
ws.addEventListener("message",(event)=>{
    console.log("message:"+event.data);
    send();//alert
});//message received

