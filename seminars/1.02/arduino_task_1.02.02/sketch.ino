#define lmax 200

void setup() {
  // Здесь пишется код, выполняющийся в самом начале работы
  Serial.begin(9600);
  Serial.print("*************************************\n");
  Serial.print("*     Семинар 1.02. Задание №02     *\n");
  Serial.print("*************************************\n\n");
}

void loop() {
  // Здесь пишется код, выполняющийся циклично
  int n, m, i, nmin;
  float A[lmax], B[lmax];

  do {
    Serial.print("Введите длину массива A [1:");
    Serial.print(lmax);
    Serial.print("]: ");
    Serial.read();
    while (Serial.available() == 0);
    n = Serial.parseInt();
  } while (n <= 0 || n > lmax);

  Serial.print("\nВведите элементы массива A [1:");
  Serial.print(n);
  Serial.println("]:");
  for (i = 1; i <= n; i++) {
    Serial.print("\tВведите элемент ");
    Serial.print(i);
    Serial.print(": ");
    Serial.read();
    while (Serial.available() == 0);
    A[i] = Serial.parseFloat();
    Serial.print("\n");
  }

  do {
    Serial.print("Введите длину массива B [1:");
    Serial.print(lmax);
    Serial.print("]: ");
    Serial.read();
    while (Serial.available() == 0);
    m = Serial.parseInt();
  } while (m <= 0 || m > lmax);

  Serial.print("\nВведите элементы массива B [1:");
  Serial.print(m);
  Serial.println("]:");
  for (i = 1; i <= m; i++) {
    Serial.print("\tВведите элемент ");
    Serial.print(i);
    Serial.print(": ");
    Serial.read();
    while (Serial.available() == 0);
    B[i] = Serial.parseFloat();
    Serial.print("\n");
  }

  Serial.print("Введенный массив A [1:");
  Serial.print(n);
  Serial.print("]:");
  for (i = 1; i <= n; i++) {
    Serial.print("\n\t");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(A[i]);
  }
  Serial.print("\n");

  Serial.print("Введенный массив B [1:");
  Serial.print(m);
  Serial.print("]:");
  for (i = 1; i <= m; i++) {
    Serial.print("\n\t");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(B[i]);
  }
  Serial.print("\n");

// Поиск первого минимального элемента массива A
  nmin = 1;
  for (i = 2; i <= n; i++)
    if (A[i] < A[nmin])
      nmin = i;

  if (nmin != n)
    for (i=n; i >= nmin + 1; i--)
      A[i + m] = A[i];
  
  for (i=1; i <=m; i++)
    A[nmin + i] = B[i];

  Serial.print("\nИзмененный массив A [1:");
  Serial.print(n+m);
  for (i = 1; i <= n + m; i++) {
      Serial.print("\n\t");
      Serial.print(i);
      Serial.print(": ");
      Serial.print(A[i]);
  }
  Serial.read();
  while (Serial.available() == 0);
}