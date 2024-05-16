#include <iostream>
using namespace std;

class suchi
{
public:
    int n, p[100], bt[100], wt[100], tat[100], total_wt = 0, total_tat = 0;
    void input();
    void waiting_time();
    void turnaround_time();
    void avg_time();
};

void suchi::input(void)
{
    cout << "Enter the number of process: ";
    cin >> n;
    cout << "Enter the burst time: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> bt[i];
    }
}

void suchi::waiting_time(void)
{
    wt[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

void suchi::turnaround_time(void)
{
    for (int i = 1; i <= n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void suchi::avg_time(void)
{
    waiting_time();
    turnaround_time();
    cout << " Process "<< " Burst Time "<< " Waiting Time "<< " Turnaround Time " << endl;
    for (int i = 1; i <= n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    cout << "Average Waiting Time = " << (float)total_wt/ (float)n << endl;
    cout << "Average Turnaround Time = " << (float)total_tat / (float)n;
}

int main()
{
    suchi data;
    data.input();
    data.avg_time();
    return 0;
}
