//init.js ---
var options = {
    'c' : "#FFDE00",
    '.' : "#3CFF00",
    '-' : "#000000",
    '*' : "#FF0000",
    '!' : "#E600FF",
    't' : "#001AFF",
    'e' : "#FF0000",
    ' ' : "#FFFFFF",
}
function refresh(can,gamemap) {
    can.clearRect(0,0,gamemap[0][0][0].length * 10,gamemap.length * 10);
    var x = -50;
    for(var i = 0;i<gamemap.length;i++) {
        x += 50;
        var y = -50;
        for(var j = 0;j<gamemap[i].length;j++) {
            y += 50;
            can.fillStyle = options[gamemap[i][j][0][0]];
            can.fillRect(y,x,50,50);
        }
    }
}