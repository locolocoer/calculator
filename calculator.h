#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <string>
#include <stack>
#include <map>
#include<QLineEdit>
#include<QString>
using namespace std;
class Calculator
{
private:
    map<string, int> ops;
    vector<string> inf;
    vector<QString> memory;
    size_t index;//memory中数据的索引
    vector<string> src, des;
    bool leg_trans;
    bool leg_cal;


    string& replace_all_distinct(string& str, const string& src, const string& des);
    string& n_replace(string& str, const vector<string>& src, const vector<string>& des);
    void show(const vector<string>& hs);
    void init_op(map<string, int>& ops);
    bool is_operator(const string& hs, const map<string, int>& ops);
    bool op_legal(const string& str, int& ill_id);
    void in2post(const vector<string>& inf, vector<string>& postf, map<string, int>& ops, bool& leg, int& ill_id);
    double cal_post(const vector<string>& postf, const map<string, int>& ops, bool& leg, int& ill_id);
    void init_src_des(vector<string>& src, vector<string>& des);
public:
    int  ill_id;
    Calculator();
    void get_infix(QString& exp);
    double cal_inf();
    QString get_next_me();
    QString get_forwd_me();
};

#endif // CALCULATOR_H
