#include <bits/stdc++.h>
using namespace std;

int point;
int finish;
int arr[6];

void xpickup(int pick);
void ypickup();
void prandomize();
void drop(int drop);

int main()
{
    cout << "Give Instruction to Robot\nstart_robot\n";
    cout << "\nRobot Moving Forward to Start Menu\n";

    int npickup, ndrop, ntimes;
    cout << "\nChoose Pickup Zone Destination: ";
    cin >> npickup;
    cout << "Choose Drop Zone Destination: ";
    cin >> ndrop;
    cout << "Choose The Number of Combinations: ";
    cin >> ntimes;

    cout << "\nRobot Instructed from Pick Up Number " << npickup << " to Drop Zone Number " << ndrop;
    cout << endl;

    if (npickup == 1)
    {
        point = 3;
    }
    else if (npickup == 2)
    {
        point = 2;
    }
    xpickup(point);
    ypickup();

    for (int i = 1; i <= ntimes; i++)
    {
        cout << "\nCombination " << i << ": ";
        prandomize();
    }

    if (ndrop == 1)
    {
        finish = 4;
    }
    else if (ndrop == 2)
    {
        finish = 3;
    }
    else if (ndrop == 3)
    {
        finish = 2;
    }
    else if (ndrop == 4)
    {
        finish = 1;
    }
    drop(finish);
    return 0;
}

void xpickup(int pick)
{
    for (int i = 0; i < pick; i++)
    {
        arr[i] = 1;
    }
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << arr[i];
    // }
}

void ypickup()
{
    for (int i = 3; i < 6; i++)
    {
        arr[i] = 2;
    }
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << arr[i];
    // }
    // cout << endl;
}

void forward()
{
    cout << "Robot moving forward 1 times";
}

void right()
{
    cout << "Robot turn right";
}

void left()
{
    cout << "Robot turn left";
}

void u()
{
    cout << "Robot moving U-turn";
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// void printArray(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";
//     cout << "\n";
// }

void prandomize()
{
    srand(time(NULL));
    for (int i = 6 - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
    // printArray(arr, 6);

    for (int j = 0; j < 6; j++)
    {
        cout << endl;
        if (arr[j] != 0)
        {
            if (arr[j] == 1 and j != 0 and arr[j - 1] == 2)
            {
                left();
                cout << endl;
                forward();
            }
            else if (arr[j] == 1)
            {
                forward();
            }
            else if (arr[j] == 2 and (j == 0 or arr[j - 1] == 1))
            {
                right();
                cout << endl;
                forward();
            }
            else if (arr[j] == 2)
            {
                forward();
            }
            else
            {
                cout << "";
                // arr[j]=arr[j-1];
            }
        }
        else if (j == 0)
        {
            arr[j] = 1;
        }
        else if (arr[j] == 0)
        {
            // cout << "ppp";
            arr[j] = arr[j - 1];
        }
        else
            break;
    }
    cout << "\nStuff have been picked up" << endl;
}

void drop(int finish)
{
    cout << endl;
    u();
    for (int i = 0; i < 6; i++)
    {
        cout << endl;
        forward();
    }
    cout << endl;
    int tmp;
    if (point < finish)
    {
        right();
        tmp = finish - point;
        for (int i = 0; i < tmp; i++)
        {
            cout << endl;
            forward();
        }
        cout << endl;
        left();
    }
    if (point > finish)
    {
        left();
        tmp = point - finish;
        for (int i = 0; i < tmp; i++)
        {
            cout << endl;
            forward();
        }
        cout << endl;
        right();
    }
    cout << "\nSuccess dropped the stuff!";
}