class Solution {
public:
    int get_day_till_month(int month){
        int ans = 0;
        int arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 0; i<month-1; i++){
            ans += arr[i];
        }
        return ans;
    } //-244
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int a_arrive_day = 10 * (arriveAlice[3] - '0') + arriveAlice[4] - '0';
        int a_arrive_month = 10 * (arriveAlice[0] - '0') + arriveAlice[1] - '0';
        int b_arrive_day = 10 * (arriveBob[3] - '0') + arriveBob[4] -'0';
        int b_arrive_month = 10 * (arriveBob[0]-'0') + arriveBob[1] - '0';

        int a_a_d = get_day_till_month(a_arrive_month);
        a_a_d += a_arrive_day;

        int b_a_d = get_day_till_month(b_arrive_month);
        b_a_d += b_arrive_day;

        int a_dep_day = 10 * (leaveAlice[3] - '0') + leaveAlice[4] - '0';
        int a_dep_month = 10 * (leaveAlice[0] - '0') + leaveAlice[1] - '0';
        int b_dep_day = 10 * (leaveBob[3] - '0') + leaveBob[4] -'0';
        int b_dep_month = 10 * (leaveBob[0]-'0') + leaveBob[1] - '0';

        int a_l_d = get_day_till_month(a_dep_month);
        a_l_d += a_dep_day;
        
        int b_l_d = get_day_till_month(b_dep_month);
        b_l_d += b_dep_day;

        int ans = min(a_l_d,b_l_d) - max(a_a_d, b_a_d); 
        return ans>=0?ans+1:0;
    }
};
