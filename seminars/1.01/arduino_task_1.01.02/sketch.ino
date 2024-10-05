#define lmax 200

void setup() {
  // Здесь пишется код, выполняющийся в самом начале работы
  Serial.begin(9600);
  Serial.print("*************************************\n");
  Serial.print("*     Семинар 1.01. Задание №02     *\n");
  Serial.print("*************************************\n\n");
}

void loop() {
  // Здесь пишется код, выполняющийся циклично
  int n = 0, i, nmin;
  float s, a[lmax+1], x, y;
  Serial.print("Введите нижнюю границу условия x:  \n");
  while (Serial.available() == 0);
  x = Serial.parseFloat();
  Serial.print("Введите верхнюю границу условия y: \n");
  while (Serial.available() == 0);
  y = Serial.parseFloat();
  
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
  nmin = 0;
  for (i = 1; i <= n; i++) {
    if ((nmin == 0 || a[i] <= a[nmin]) && a[i] >= x && a[i] < y) {
      nmin = i;
    }
  }

  Serial.print("\nПолученный результат:\n");
  if (nmin == 0)
    Serial.print("Нет минимума\n");
  else {
    Serial.print("\tНомер:    ");
    Serial.print(nmin);
    Serial.print("\n\tЗначение: ");
    Serial.print(a[nmin]);
    Serial.print("\n");
  }
}
