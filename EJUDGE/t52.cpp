template <int a, int b>
void f() { 
    if ( a <= b ) {
        new int[a - b - 1]; 
        // будет ошибка при попытке создания массива отрицательной длины
    }
}