#include "calculator.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include<assert.h>
#include<QLineEdit>
#include<QString>
using namespace std;

Calculator::Calculator()
{
    this->leg_cal=true;
    this->leg_trans=true;
    this->ill_id=0;
    init_op(this->ops);
    init_src_des(this->src,this->des);
    this->index=0;
}

string& Calculator::replace_all_distinct(string& str, const string& src, const string& des)
{
    for (string::size_type i = 0; i != string::npos; i += des.size())
    {
        i = str.find(src, i);
        if (i != string::npos)
        {
            str.replace(i, src.size(), des);
        }
        else
        {
            break;
        }
    }
    return str;
}

string& Calculator::n_replace(string& str, const vector<string>& src, const vector<string>& des)
{
    assert(src.size() > 0 && src.size() == des.size());
    for (vector<string>::size_type i = 0; i != src.size(); ++i)
    {
        replace_all_distinct(str, src[i], des[i]);
    }
    return str;
}

void Calculator::get_infix(QString& exp)
{
    this->inf.clear();
    this->memory.push_back(exp);
    this->index=memory.size()-1;
    string line;
    //getline(cin, line);
    line=exp.toStdString();
    n_replace(line, this->src, this->des);

    istringstream sin(line);
    string tmp;
    while (sin >> tmp)
    {
        this->inf.push_back(tmp);
    }
}

void Calculator::show(const vector<string>& hs)
{
    for (vector<string>::size_type i = 0; i != hs.size(); ++i)
    {
        cout << hs[i] << ' ';
    }
    cout << endl;
}

void Calculator::init_op(map<string, int>& ops)
{
    ops.clear();
    ops["+"] = 100;
    ops["-"] = 100;
    ops["*"] = 200;
    ops["/"] = 200;
    ops["("] = 1000;
    ops[")"] = 0;
}

bool Calculator::is_operator(const string& hs, const map<string, int>& ops)
{
    map<string, int>::const_iterator cit = ops.find(hs);
    if (cit != ops.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 判断操作数是否合法
bool Calculator::op_legal(const string& str, int& ill_id)
{
    assert(str.size() > 0);
    string::size_type i = 0;
    if (str[i] == '+' || str[i] == '-')
    {
        ++i;
        if (i == str.size())
        {
            ill_id = 3001;
            return false;
        }
    }
    int dot_num = 0;
    for (; i != str.size(); ++i)
    {
        if (isdigit(static_cast<int>(str[i])))
        {
            ;
        }
        else if (str[i] == '.')
        {
            ++dot_num;
        }
        else
        {
            ill_id = 3002;
            return false;
        }
    }
    if (dot_num > 1)
    {
        ill_id = 3003;
        return false;
    }
    return true;
}

void Calculator::in2post(const vector<string>& inf, vector<string>& postf, map<string, int>& ops, bool& leg, int& ill_id)
{
    if (inf.size() == 0)
    {
        leg = false;
        ill_id = 6001;
        return;
    }

    postf.clear();
    stack<string> op_st;
    // 记录左括号和右括号之间的数量关系
    int brac = 0;
    int op_op = 0;

    for (vector<string>::size_type i = 0; i != inf.size(); ++i)
    {
        if (!is_operator(inf[i], ops))
        {
            // 判断是否是正确的操作数
            int tmp = 0;
            if (!op_legal(inf[i], tmp))
            {
                leg = false;
                ill_id = tmp;
                return;
            }
            ++op_op;
            if (op_op > 1)
            {
                leg = false;
                ill_id = 5001;
                return;
            }
            postf.push_back(inf[i]);
        }
        else
        {
            if (inf[i] == "(")
            {
                ++brac;
                op_st.push(inf[i]);
            }
            else if (inf[i] == ")")
            {
                --brac;
                if (brac < 0)
                {
                    leg = false;
                    ill_id = 4001;
                    return;
                }
                while (!op_st.empty())
                {
                    if (op_st.top() == "(")
                    {
                        op_st.pop();
                        // !勘误!
                        // 如果inf[i] == ")"，当遇到"("，将"("弹栈后必须终止弹栈循环。
                        break;
                    }
                    else
                    {
                        postf.push_back(op_st.top());
                        op_st.pop();
                    }
                }
            }
            else // 若为其他运算符
            {
                --op_op;
                if (op_op < 0)
                {
                    leg = false;
                    ill_id = 5002;
                    return;
                }

                if (op_st.empty()) // 若为空栈，则直接入栈
                {
                    op_st.push(inf[i]);
                }
                else
                {
                    if (ops[inf[i]] > ops[op_st.top()])
                    {
                        // 如果当前操作符优先级高于站定操作符优先级
                        // 则直接入栈
                        op_st.push(inf[i]);
                    }
                    else
                    {
                        // 否则弹出栈中优先级大于等于当前操作符优先级
                        // 的操作符，并最后将当前操作符压栈
                        while (!op_st.empty() && ops[op_st.top()] >= ops[inf[i]] && op_st.top() != "(")
                        {
                            /* 等价于 && op_st.top != "("
                            if (op_st.top() == "(")
                            {
                                // 如果当前栈顶操作符为 "("
                                // 则终止操作，继续保留 "(" 的栈顶位置
                                break;
                            }
                            */
                            postf.push_back(op_st.top());
                            op_st.pop();
                        }
                        op_st.push(inf[i]);
                    }
                }
            }
        }
    }
    if (brac > 0)
    {
        leg = false;
        ill_id = 4002;
        return;
    }
    if (op_op != 1)
    {
        leg = false;
        ill_id = 5003;
        return;
    }

    while (!op_st.empty())
    {
        postf.push_back(op_st.top());
        op_st.pop();
    }
    leg = true;
    return;
}

double Calculator::cal_post(const vector<string>& postf, const map<string, int>& ops, bool& leg, int& ill_id)
{
    stack<double> or_st;
    double operand = 0.0, a = 0.0, b = 0.0, c = 0.0;
    for (vector<string>::size_type i = 0; i != postf.size(); ++i)
    {
        if (!is_operator(postf[i], ops))
        {
            operand = static_cast<double>(atof(postf[i].c_str()));
            or_st.push(operand);
        }
        else
        {
            switch (postf[i][0])
            {
            case '+':
                // 检测后缀表达式的合法性：操作数是否足够
                if (or_st.size() < 2)
                {
                    leg = false;
                    ill_id = 1001;
                    return -10000000000000.0;
                }
                b = or_st.top();
                or_st.pop();
                a = or_st.top();
                or_st.pop();
                c = a + b;
                or_st.push(c);
                break;
            case '-':
                // 检测后缀表达式的合法性：操作数是否足够
                if (or_st.size() < 2)
                {
                    leg = false;
                    ill_id = 1002;
                    return -10000000000000.0;
                }
                b = or_st.top();
                or_st.pop();
                a = or_st.top();
                or_st.pop();
                c = a - b;
                or_st.push(c);
                break;
            case '*':
                // 检测后缀表达式的合法性：操作数是否足够
                if (or_st.size() < 2)
                {
                    leg = false;
                    ill_id = 1003;
                    return -10000000000000.0;
                }
                b = or_st.top();
                or_st.pop();
                a = or_st.top();
                or_st.pop();
                c = a * b;
                or_st.push(c);
                break;
            case '/':
                // 检测后缀表达式的合法性：操作数是否足够
                if (or_st.size() < 2)
                {
                    leg = false;
                    ill_id = 1004;
                    return -10000000000000.0;
                }
                b = or_st.top();
                or_st.pop();
                a = or_st.top();
                or_st.pop();
                c = a / b;
                or_st.push(c);
                break;
            default:
                break;
            }
        }
    }
    if (or_st.size() == 1)
    {
        leg = true;
        return or_st.top();
    }
    else // 检测后缀表达式的合法性：操作数是否有多余
    {
        leg = false;
        ill_id = 2001;
        return -10000000000000.0;
    }
}

void Calculator::init_src_des(vector<string>& src, vector<string>& des)
{
    src.push_back("+");
    src.push_back("-");
    src.push_back("*");
    src.push_back("/");
    src.push_back("(");
    src.push_back(")");

    des.push_back(" + ");
    des.push_back(" - ");
    des.push_back(" * ");
    des.push_back(" / ");
    des.push_back(" ( ");
    des.push_back(" ) ");
}

// 将中缀表达式转换后缀表达式和计算后缀表达式封装合并
double Calculator::cal_inf()
{
    this->leg_trans = true;
    this->ill_id = 0;
    vector<string> postf;
    in2post(this->inf, postf, this->ops, this->leg_trans, this->ill_id);
    if (this->leg_trans)
    {
        show(postf);
    }
    else
    {
        cout << "Trans illegal: " << ill_id << '!' << endl << endl;
        return -10000000000000.0;
    }

    this->leg_cal = true;
    this->ill_id = 0;
    double ret = cal_post(postf, this->ops, this->leg_cal, this->ill_id);
    if (this->leg_cal)
    {
        return ret;
    }
    else
    {
        cout << "Cal illegal: " << this->ill_id << '!' << endl << endl;
        return -10000000000000.0;
    }
}

QString Calculator::get_next_me()
{
    size_t max_len=this->memory.size();
    if(max_len==0){
        return "";
    }
    if (index<max_len-1){
        index++;
    }
    QString temp = this->memory.at(index);
    return temp;
}

QString Calculator::get_forwd_me()
{
    size_t max_len=this->memory.size();
    if(max_len==0){
        return "";
    }
    if(index>0){
        index--;
    }
    QString temp = this->memory.at(index);
    return temp;
}
