#define INT_MAX 2147483647
#define lmax 10

void setup() {
  Serial.begin(9600);
  Serial.print("*************************************\n");
  Serial.print("*     Семинар 1.03. Задание №02     *\n");
  Serial.print("*************************************\n\n");
}

void loop() {
  int na, ma, A[lmax + 1][lmax + 1], nb, B[lmax + 1];
  int i, j, k;
  int flag, min;
  float fv1, fv2;

  do {
    Serial.print("Введите размер матрицы A[1:");
    Serial.print(lmax);
    Serial.print("][1:");
    Serial.print(lmax);
    Serial.print("]: \n");
    Serial.read();
    while (Serial.available() == 0);
    fv1 = Serial.parseFloat();
    na = (int) fv1;
    fv2 = Serial.parseFloat();
    ma = (int) fv2;
    while (Serial.available() > 0)
      Serial.read();
  } while (na <= 0 || na > lmax || na != fv1 ||
           ma <= 0 || ma > lmax || ma != fv2);

  Serial.print("Введите элементы матрицы A[1:");
  Serial.print(na);
  Serial.print("][1:");
  Serial.print(ma);
  Serial.println("]:");
  for (i = 1; i <= na; i++) {
    for (j = 1; j <= ma; j++) {
      Serial.print("\tВведите элемент [");
      Serial.print(i);
      Serial.print("][");
      Serial.print(j);
      Serial.println("]:");
      Serial.read();
      while (Serial.available() == 0);
      A[i][j] = Serial.parseInt();
    }
    Serial.print("\n");
  }

  do {
    Serial.print("Введите длину массива B[1:");
    Serial.print(lmax);
    Serial.print("]: \n");
    Serial.read();
    while (Serial.available() == 0);
    fv1 = Serial.parseFloat();
    nb = (int) fv1;
    while (Serial.available() > 0)
      Serial.read();
  } while (nb <= 0 || nb > lmax || nb != fv1);

  Serial.print("Введите элементы массива B[1:");
  Serial.print(nb);
  Serial.println("]:");
  for (i = 1; i <= nb; i++) {
    Serial.print("\tВведите элемент ");
    Serial.print(i);
    Serial.print(": ");
    Serial.read();
    while (Serial.available() == 0);
    B[i] = Serial.parseFloat();
    Serial.print("\n");
  }

  Serial.print("Введенная матрица A[1:");
  Serial.print(na);
  Serial.print("][1:");
  Serial.print(ma);
  Serial.print("]:");
  for (i = 1; i <= na; i++) {
    for (j = 1; j <= ma; j++) {
      Serial.print("\n\tA[");
      Serial.print(i);
      Serial.print("][");
      Serial.print(j);
      Serial.print("]: ");
      Serial.print(A[i][j]);
    }
    Serial.print("\n");
  }
  Serial.print("Введенный массив B[1:");
  Serial.print(nb);
  Serial.print("]:");
  for (i = 1; i <= nb; i++) {
    Serial.print("\n\t");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(B[i]);
  }
  Serial.print("\n");

  // Поиск минимума
  for (min = INT_MAX, flag = 0, i = 1; i <= na; i++)
    for (j = 1; j <= ma; j++) {
      k = 1;
      while (k <= nb && A[i][j] != B[k])
        k = k + 1;
      if (k > nb && A[i][j] <= min) {
        min = A[i][j];
        flag = 1;
      }
    }

  Serial.print("\nПолученный результат:\n");
  if (flag == 0)
    Serial.print("Нет  минимума\n");
  else {
    Serial.print("min = ");
    Serial.print(min);
  }
  Serial.print("\n\n");
}