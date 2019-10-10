
 

int fun(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; j = j*2) {
            doSmth();
        }
    }
}


int fun(int n) { 
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < i; j = j*2) {
            doSmth();
        }
    }
}

int fun(int n) {
    for (int j = 1; j < n; j = j*2) {
        for (int i = 0; i < n; ++i) {
            doSmth();
        }
    }
}

int fun(int n)
{
  int count = 0;
  for (int i = n; i > 0; i /= 2)
     for (int j = 0; j < i; j++)
        count += 1;
  return count;
}

int fun(int n)
{
  int count = 0;
  for (int i = 0; i < n; i++)
     for (int j = i; j > 0; j--)
        count = count + 1;
  return count;
} 

template<class T>
void Vector<T>::push_back(const T & v) { 
    if (_size >= _capacity) {
        reserve(1 << Log);
        Log++;
    }
    buffer [_size++] = v;
}


void fun(int n, int arr[])
{
    int i = 0, j = 0;
    for(; i < n; ++i)
        while(j < n && arr[i] < arr[j])
            j++;
}

void fun()
{
   int i, j;
   for (i=1; i<=n; i++)
      for (j=1; j<=log(i); j++)
         printf("");
}

int fun1(int n)
{
    if (n <= 1) return n;
    return 2*fun1(n-1);
}

int fun2(int n)
{
    if (n <= 1) return n;
    return fun2(n-1) + fun2(n-1);
}


// The space complexity of the above function is ?
double foo (int n)
{
    int i;
    double sum;
    if (n = = 0) return 1.0;
    else
    {
        sum = 0.0;
        for (i = 0; i < n; i++)
            sum += foo (i);
        return sum;
    }
}

int gcd(n,m)
{
  if (n%m ==0) return m;  
  n = n%m;
  return gcd(m, n);
}