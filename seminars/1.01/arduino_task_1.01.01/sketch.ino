#define lmax 200

void setup() { // Код, выполняющийся в самом начале работы
  Serial.begin(9600);
  Serial.print("*************************************\n");
  Serial.print("*     Семинар 1.01. Задание №01     *\n");
  Serial.print("*************************************\n\n");
}

void loop() { // Код, выполняющийся циклично
  int n = 0, i, nmax;
  float s, a[lmax], max;

  do {
    Serial.print("Введите длину массива a [1:");
    Serial.print(lmax);
    Serial.print("]: ");
    Serial.read();
    while (Serial.available() == 0);
    n = Serial.parseInt();
  } while (n <= 0 || n > lmax);

  Serial.print("\nВведите элементы массива [1:");
  Serial.print(n);
  Serial.println("]:");
  for (i = 1; i <= n; i++) {
    Serial.print("\tВведите элемент ");
    Serial.print(i);
    Serial.print(": ");
    Serial.read();
    while (Serial.available() == 0);
    a[i] = Serial.parseFloat();
    Serial.print("\n");
  }

  Serial.print("Введенный массив [1:");
  Serial.print(n);
  Serial.print("]:");
  for (i = 1; i <= n; i++) {
    Serial.print("\n\t");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(a[i]);
  }

  // Поиск последнего максимума в массиве
  max = a[1];
  nmax = 1;
  for (i = 2; i <= n; i++) {
    if (a[i] >= max) {
      max = a[i];
      nmax = i;
    }
  }

  Serial.print("\n\nПолученный результат:\n\tНомер:    ");
  Serial.print(nmax);
  Serial.print("\n\tЗначение: ");
  Serial.print(max);
  Serial.print("\n");
}
