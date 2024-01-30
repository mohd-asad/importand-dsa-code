int power(int a, int b)
{
    if(b == 0) return 1;

    a = a % m;
    int temp = power(a, b/2);
    if(b&1)
        return (((temp * temp) % m) * a) % m;
    else
        return (temp * temp) % m;
}