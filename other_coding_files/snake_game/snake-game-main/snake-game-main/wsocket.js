function connect(addr) {
    return new WebSocket(addr);
}
function send(websocket,msg) {
    websocket.send(msg);
} 
