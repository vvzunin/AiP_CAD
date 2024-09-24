#define lmax 200

void setup() {
  // Здесь пишется код, выполняющийся в самом начале работы
  Serial.begin(9600);
  Serial.print("*************************************\n");
  Serial.print("*     Семинар 1.02. Задание №01     *\n");
  Serial.print("*************************************\n\n");
}

void loop() {
  // Здесь пишется код, выполняющийся циклично
  int k, n, i;
  float A[lmax], B, L;

  do {
    Serial.print("Введите длину массива A [1:");
    Serial.print(lmax);
    Serial.print("]: ");
    Serial.read();
    while (Serial.available() == 0);
    k = Serial.parseInt();
  } while (k <= 0 || k > lmax);

  Serial.print("\nВведите элементы массива A [1:");
  Serial.print(k);
  Serial.println("]:");
  for (i = 1; i <= k; i++) {
    Serial.print("\tВведите элемент ");
    Serial.print(i);
    Serial.print(": ");
    Serial.read();
    while (Serial.available() == 0);
    A[i] = Serial.parseFloat();
    Serial.print("\n");
  }

  Serial.print("Введенный массив A [1:");
  Serial.print(k);
  Serial.print("]:");
  for (i = 1; i <= k; i++) {
    Serial.print("\n\t");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(A[i]);
  }

  Serial.print("\nВведите значение числа B");
  Serial.read();
  while (Serial.available() == 0);
  B = Serial.parseInt();
  Serial.print("\n");

  Serial.print("\nВведите значение числа L");
  Serial.read();
  while (Serial.available() == 0);
  L = Serial.parseInt();
  Serial.print("\n");

  Serial.print("Массив до удаления A [1:");
  Serial.print(k);
  Serial.print("]:");
  for (i = 1; i <= k; i++) {
    Serial.print("\n\t");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(A[i]);
  }

  // Удаление элементов по условию.
  n = 0;
  for (i = 1; i <= k; i++) {
    if ((A[i] > L) || (A[i] <= B)) {
      n = n + 1;
      A[n] = A[i];
    }
  }

  Serial.print("\nПолученный результат:\n");
  if (n == 0)
    Serial.print("Полное удаление!\n");
  else {
    if (n == k)
      Serial.print("Нет удаления!\n");
    else {
        Serial.print("Массив A после удаления [1:");
        Serial.print(n);
        Serial.print("]:");
        for (i = 1; i <= n; i++) {
          Serial.print("\n\t");
          Serial.print(i);
          Serial.print(": ");
          Serial.print(A[i]);
  }
    }
  }
  Serial.read();
  while (Serial.available() == 0);
}

