// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>
// #include <vector>
// #include <map>
// #include <regex>

// using std::cout;
// using std::endl;
// using std::stringstream;
// using std::string;
// using std::vector;
// using std::map;
// using std::regex;
// using std::smatch;


// int main(int argc, char** argv)
// {
//     std::ifstream file_in("auth.log");
//     map<string, int> ip_size;

//     vector<string> vector_log;
//     string tmp_log_str;
//     string tmp_log_re_ip;

//     if (!file_in.is_open())
//         throw std::logic_error("文件打开失败");
    
//     regex re_ip("((2(5[0-5]|[0-4]\\d))|[0-1]?\\d{1,2})(\\.((2(5[0-5]|[0-4]\\d))|[0-1]?\\d{1,2})){3}");
//     smatch re_ip_return_str;

//     for (int i = 1, is_find = 0; std::getline(file_in, tmp_log_str); ++i)
//     {
//         is_find = tmp_log_str.find("Failed password");

//         if (is_find != -1)
//         {
//             std::regex_search(tmp_log_str, re_ip_return_str, re_ip);
//             tmp_log_re_ip = re_ip_return_str.str();
//             vector_log.push_back(tmp_log_re_ip);

//             if (ip_size.count(tmp_log_re_ip) == 1)
//             {
//                 ip_size[tmp_log_re_ip] = ip_size[tmp_log_re_ip] +1;
//             }   
//             else
//                 ip_size[tmp_log_re_ip] = 1;
//         }

//     }

//     cout << vector_log.size() << endl;

//     for (auto a = ip_size.begin(); a != ip_size.end(); ++a)
//         cout << "爆破ip的为\t" << a->first << "\t爆破的次数为\t" << a->second << endl;
    

//     file_in.close();


//     return 0;
// }

#include <iostream>
#include "include/my_ini.h"

int main(int argc, char** argv)
{   
    my_ini tmp("test.ini");
    tmp.show();
}




















