// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  if (count <> 0)
    return count;
  else
    return 0;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0, right = len - 1; left = 0;//границы массива
  while (left < right - 1) {//пока они не сошлись
    int middle = (right + left) / 2;//индекс среднего элемента
    if (value <= arr[middle])//сужаем массив
        left = middle;
    else 
      right = middle;
  }
  len = right - 1;
  for (int i = len; i <= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[i] + arr[j] == value)
        count++;
      if (arr[i] + arr[j] > value)
        break;
    }
  }
  if (count <> 0)
    return count;
  else
    return 0;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0, left = 0, right = len - 1;//границы массива
    while (left < right - 1) {//пока не сошлись
        int middle = (left + right) / 2;//индекс среднего эл-та
        if (arr[middle] <= value)//сужаем массив
            left = middle;
        else
            right = middle;
    }
    len = right - 1;
  for (int i = 0; i < len; i++) {
        left = i + 1, right = len - 1;
        int count2 = 0;
    while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] < (value - arr[i]))
                left = mid + 1;
            else
                right = mid;
        }
    while (arr[left] == (value - arr[i])) {
            count2++;
            left++;
        }
        count += count2;
    }
  if (count <> 0)
    return count;
  else
    return 0;
}
