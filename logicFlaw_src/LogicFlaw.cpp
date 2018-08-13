#include <vector>
#include <cstring>
#include <sstream>
#include <conio.h>
#include <iostream>
#include <algorithm>

std::vector<int> CountingSort(std::vector<int> V) {
  std::vector<int> counting_array(V.size() + 10, 0);  // 초기값을 V.size() + 10 이 아니라 101으로 설정
  for (int i = 0; i < static_cast<int>(V.size()); ++i) {
    ++counting_array[V[i]];
  }
  std::vector<int> sorted_array;
  for (int i = 0; i < static_cast<int>(counting_array.size()); ++i) {
    for (int j = 0; j < counting_array[i]; ++j) {
      sorted_array.push_back(i);
    }
  }
  return sorted_array;
}

std::vector<int> InsertionSort(std::vector<int> V) {
  bool is_array_sorted = true;
  for (int i = 0; i < static_cast<int>(V.size()) - 1; ++i) {
    if (V[i] > V[i + 1]) {
      is_array_sorted = false;
      break;
    }
  }
  if (is_array_sorted) {
    return V;
  }

  for (int i = 0; i < static_cast<int>(V.size()) - 1; ++i) {
    int min_index = 0;  // min_index 의 초기값은 i 여야함
    for (int j = i; j < static_cast<int>(V.size()); ++j) {
      if (V[min_index] > V[j]) {
        min_index = j;
      }
    }
    int temp = V[min_index];
    V[min_index] = V[i];
    V[i] = temp;

  }
  return V;
}

std::vector<int> FilterLessThan(std::vector<int> V, int pivot) {
  std::vector<int> result;

  for (int elem : V) {
    if (elem < pivot) { // FilterLessThan 이나 FilterGreaterThan 의 한쪽에는 등호가 들어가야 함
      result.push_back(elem);
    }
  }

  return result;

}

std::vector<int> FilterGreaterThan(std::vector<int> V, int pivot) {
  std::vector<int> result;

  for (int elem : V) {
    if (elem > pivot) {
      result.push_back(elem);
    }
  }

  return result;

}

std::vector<int> QuickSort(std::vector<int> V) {
  if (static_cast<int>(V.size()) <= 1) {
    return V;
  }

  int pivot = V.back();
  V.pop_back();

  std::vector<int> result;
  for (int elem : QuickSort(FilterLessThan(V, pivot))) {
    result.push_back(elem);
  }
  result.push_back(pivot);
  for (int elem : QuickSort(FilterGreaterThan(V, pivot))) {
    result.push_back(elem);
  }

  return result;
}

/*********
 * MAIN  *
 *********/

std::string int_to_string(std::vector<int> input) {
  std::stringstream result;
  std::copy(input.begin(), input.end(), std::ostream_iterator<int>(result, " "));
  return result.str();
}

std::vector<int>(*SortFunc)(std::vector<int> V);

void setSortFunc(std::vector<int>(*TargetSortFunc)(std::vector<int> V)) {
  SortFunc = TargetSortFunc;
}

void assert(std::vector<int> input) {
  std::vector<int> expected = input;
  std::sort(expected.begin(), expected.end());

  std::vector<int> actual = SortFunc(input);

  if (expected == actual) {
    std::cout << "* PASS" << std::endl;
  }
  else {
    std::cout << "* FAIL Input : " << int_to_string(input) << std::endl;
    std::cout << "Expected : " << int_to_string(expected) << std::endl;
    std::cout << "Actual   : " << int_to_string(actual) << std::endl;
  }
}

int main() {
  std::vector<int>(*SortFuncList[3])(std::vector<int> V);

  SortFuncList[0] = CountingSort;
  SortFuncList[1] = InsertionSort;
  SortFuncList[2] = QuickSort;

  setSortFunc(SortFuncList[0]);

  std::cout << "## TEST START ##" << std::endl;

  std::vector<int> test_list0({ });
  assert(test_list0);

  std::vector<int> test_list1({ 3 });
  assert(test_list1);

  std::vector<int> test_list2({ 7, 4 });
  assert(test_list2);

  std::vector<int> test_list3({ 4, 9 });
  assert(test_list3);

  std::vector<int> test_list4({ 0 });
  assert(test_list4);

  std::vector<int> test_list5({ 4, 0 });
  assert(test_list5);

  std::vector<int> test_list6({ 4, 0, 4, 7, 4 });
  assert(test_list6);

  std::vector<int> test_list7({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
  assert(test_list7);

  std::vector<int> test_list8({ 4, 8, 9 });
  assert(test_list8);

  std::vector<int> test_list9({ 5, 5, 5, 5, 5 });
  assert(test_list9);

  std::vector<int> test_list10({ 5, 4, 3, 2, 1 });
  assert(test_list10);

  //*
  std::vector<int> test_list100({ 100, 4 });
  assert(test_list100);
  //*/

  std::cout << "## TEST END ##";
  _getch();

  return 0;
}