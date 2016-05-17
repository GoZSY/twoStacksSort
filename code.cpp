/****************************************************************************
使用新建的栈来保存暂时已经找到的最大值，并且由原始栈弹出的值实时更新新栈，直到
所有的数据都从旧栈弹出。
*****************************************************************************/

class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) 
    {
        // write code here
        vector<int> order;
        while(!numbers.empty())
        {
            int temp = numbers.back();
            numbers.pop_back();
            if(order.empty())
                order.push_back(temp);
            else
            {
                int num = 0;//记录从新栈返回旧站的次数，待新元素插入后将压入旧栈的元素重新放回新栈
                while(!order.empty() && temp > order.back())
                {
                    numbers.push_back(order.back());
                    order.pop_back();
                    num++;
                }
                order.push_back(temp);
                if(num--)
                {
                   order.push_back(numbers.back()) ;
                   numbers.pop_back();
                }
            }
         
        }
        return order;
    }
};
