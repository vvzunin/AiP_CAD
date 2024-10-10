#define lmax 10

void setup() {
  Serial.begin(9600);
  Serial.print("*************************************\n");
  Serial.print("*     Семинар 1.03. Задание №01     *\n");
  Serial.print("*************************************\n\n");
}

void loop() {
  int na, nb, A[lmax + 1], B[lmax + 1], i, j;
  float fv;

  do {
    Serial.print("Введите длину массива A[1:");
    Serial.print(lmax);
    Serial.print("]: \n");
    Serial.read();
    while (Serial.available() == 0);
    fv = Serial.parseFloat();
    na = (int) fv;
    while (Serial.available() > 0)
      Serial.read();
  } while (na <= 0 || na > lmax || na != fv);

  Serial.print("Введите элементы массива A[1:");
  Serial.print(na);
  Serial.println("]:");
  for (i = 1; i <= na; i++) {
    Serial.print("\tВведите элемент ");
    Serial.print(i);
    Serial.print(": ");
    Serial.read();
    while (Serial.available() == 0);
    A[i] = Serial.parseFloat();
    Serial.print("\n");
  }

  Serial.print("Введенный массив A [1:");
  Serial.print(na);
  Serial.print("]:");
  for (i = 1; i <= na; i++) {
    Serial.print("\n\t");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(A[i]);
  }
  Serial.print("\n");

  // Формирование массива B
  nb = 0;
  for (i = 1; i <= na; i++) {
    j = 1;
    while (j <= nb && (A[i] != B[j]))
      j = j + 1;
    if (j > nb) {
      nb = nb + 1;
      B[nb] = A[i];
    }
  }

  Serial.print("\nПолученный результат:\n");
  if (na == nb)
    Serial.print("Все элементы массива A неодинаковые!\n");
  else {
    Serial.print("Введенный массив B [1:");
    Serial.print(nb);
    Serial.print("]");
    for (i = 1; i <= nb; i++) {
      Serial.print("\n\t");
      Serial.print(i);
      Serial.print(": ");
      Serial.print(B[i]);
    }
  }
  Serial.print("\n\n");
}