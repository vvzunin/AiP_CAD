#define lmax 200

void setup() {
  // Здесь пишется код, выполняющийся в самом начале работы
  Serial.begin(9600);
  Serial.print("*************************************\n");
  Serial.print("*     Семинар 1.02. Задание №03     *\n");
  Serial.print("*************************************\n\n");

}

void loop() {
  // Здесь пишется код, выполняющийся циклично
  int n, n1, np, i;
  float A[lmax], s;

  do {
    Serial.print("Введите длину массива A [1:");
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
    A[i] = Serial.parseFloat();
    Serial.print("\n");
  }

  Serial.print("Введенный массив [1:");
  Serial.print(n);
  Serial.print("]:");
  for (i = 1; i <= n; i++) {
    Serial.print("\n\t");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(A[i]);
  }

  // Поиск первого и последнего отрицательных элементов
  for (n1 = np = 0, i = 1; i <= n; i++)
    if (A[i] < 0) {
      if (n1 == 0)
        n1 = i;
      np = i;
    }

  if (n1 == 0)
    Serial.print("\nНет отрицательных элементов!\n");
  else if (n1 == np){
    Serial.print("\nОдин отрицательный элемент:");
    Serial.print(A[n1]);
  }
  else {
    s = 0;
    for (i = n1; i <= np; i++)
      s = s + A[i];
    Serial.print("\nСумма=");
    Serial.print(s);
  }

  Serial.read();
  while (Serial.available() == 0);
}