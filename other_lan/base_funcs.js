function checksearch(s,target) {
    for(var i = 0;i<s.length;i++) {
        if(s[i] == target) {
            return 1;
        }
    }
    return -1;
}