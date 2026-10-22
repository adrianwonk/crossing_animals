int gcd(int a, int b){
    int remainder;
    while (remainder = a % b, remainder != 0){
        a = b;
        b = remainder;
    }
    return b;
}
