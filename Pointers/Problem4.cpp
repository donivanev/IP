#include <iostream>
using namespace std;

const int MAX_LEN = 1000;

// ����� ������, ��� ������� arr ������� � ���� �� ������� elem
bool contains(int* arr, int n, int elem)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == elem)
        {
            return true;
        }
    }
    return false;
}

bool commonel(int* arrays[], int npointers, int arrlenghts[])
{
    // ������ �������, ����� � ������� �� ������ ������ � arrays
    // ��� � ������� �� ������, �� ��� � ������� � �� ������ �����
    // � ����� ������ � ���������� �� �������� ���� ��� ������� �� 
    // ������ �����, ����� �� ������� ��� ������ ��������, ��� ���
    // �����, �� ��� � ��������� �
    for (int i = 0; i < arrlenghts[0]; i++) // ������� ����� ��� arrlenghts[0] �� ���� ��������
    {
        int x = arrays[0][i];
        int j = 1; // ��������� �� ������ �����
        // ������������ ������ ������� �����, ����� �� ������� � ��� �� ���� (� ������ �� ������ �� ��������)
        while (j < npointers && contains(arrays[j], arrlenghts[j], x))
        {
            j++;
        }

        // ��� ��� �������� �� ����, ����� �� ��� ������� �����, ����� �� ��
        // ������� (����� ������ ������ �������� � � ��� � ��� �������)
        if (j == npointers)
        {
            return true;
        }
        // � �������� ������ ������������ � �������� �� ������� ��������
    }
    return false;
}

int main()
{
    int arr1[] = { 1, 2, 3, 4 }; // 4 ��������
    int arr2[] = { 78, 99, 30, 11, 28, 42, 23, 1 }; // 8 ��������
    int* pointers[] = { arr1, arr2 };
    int arrlengths[] = { 4, 8 };
    cout << "Commonel: " << (commonel(pointers, 2, arrlengths) ? "true" : "false") << endl; // true ������ 1

    int arr3[] = { 100, 34, 89, 32, 66 }; // 5 ��������
    int* pointers2[] = { arr1, arr3 };
    int arrlengths2[] = { 4, 5 };
    cout << "Commonel: " << (commonel(pointers2, 2, arrlengths2) ? "true" : "false") << endl; // false ������ ���� ������� �������� � arr � arr3

}