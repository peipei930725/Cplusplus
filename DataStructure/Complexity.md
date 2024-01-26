# 資料結構筆記
 
### 複雜度

#### 空間複雜度(Time Complexity)

S(P)=C+Sp(I)
---

- C is a **fixed** part.

1. Independent of the size of input and output.(與輸入輸出不相干)
2. Space for instruction and static variables fixed-size structured variable,constants.

- Sp(I) is a **variable** part.

1. Depends on the specific problem instance.
2. Space of referenced variable and recursion stack space(與要處理哪個問題有關)

example1:
```
float ABC(float a,b,c){
    return a+b+b*c+(a+b-c)/(a+b)+4.0
}
```
- I=a,b,c
- C = space for the program + space for variable a,b,c, ABC=constant.

example2:
```
float Sum(float *A const int n){
    float s=0;
    for(int i=0; i<n; ++i){
        s+=A[i];
    }
    return s;
}
```
- I= n (number of elements to be summed)
- C=constant
- S(I)= 0 (A stores only the address of array)\
==實際上從外部看應該與 n 有關==
- S(Sum)= C+ Sum(I) = constant

example3:

```
float Rsum(float *A, const int n){
    if(n<=0) return A[0];
    else return (Rsum(A , n-1)+ A[n-1]);
}
```
- I=n(number of element to be summed)
- C=constant
- Each recursive call "Rsum" requires 4(1+1+1) = 12bytes  
==(函式本身，float*A，int n)==
- Number of calls: Rsum(A,n) -> Rsum(A,n-1)...Rsum(A,0) -> n+1 calls
- S(Rsum) = C + S(n) = const+ 12(n+1)

---

#### 時間複雜度(Time Complexity)

T(P)=C+Tp(I)
---

- C is a **constant**: Compile time
- Tp(I) is a **variable**: Execution time  
==多個運算還是算1 like : Tp(I)= a+b+c*c= 1==

example1: **O(2n+3)**
```
float Sum(float *A, const int n){
    float s=0;                  // 1
    for(int i=0; i<n ; i++)     // n+1
        s += A[i];              // n
    return s;                   // 1
}
```

example2: **O(2n+2)**
```
float Rsum(float *A, const int n){
    if(n<=0){
        return A[0];
    }
    else 
        return (Rsum(A, n-1) + A[n-1]);
}
```
- I = n (number of elements for summation)
- T(0)= 2
- T(n)= 2 + T(n-1)  
=2+ (2+T(n-2))...  
=2n+ T(0) = 2n+2

example3: **O(2mn + 2m +1)**
```
void Add(int **a, int **b, int **c, int m, int n){
    for(int i=0; i<m; i++){             //m+1
        for(int j=0; j<n; j++){         //m*(n+1)
            c[i][j] = a[i][j]+b[i][j];  //m*n
        }
    }
}
```
- I = m(rows),n(columns)
- T(I) = (m+1) + m(n+1) + mn  
=2mn + 2m + 1
- T(Add) = C + T(I)  
=const + (2mn + 2m + 1)

