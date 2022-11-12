#include "ini.h"
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::getline;
using std::stringstream;

/*m_ini_value*/
/***********************************************************************************************************/
m_ini_value::m_ini_value()                           { value_type = type_t::Nullptr; }
m_ini_value::m_ini_value(const m_ini_value& argv_tmp_ini_value)
{
    value_type = argv_tmp_ini_value.value_type;
    value = argv_tmp_ini_value.value;
}
m_ini_value::m_ini_value(const int& argv_value)      { *this = argv_value; }
m_ini_value::m_ini_value(const double& argv_value)   { *this = argv_value; }
m_ini_value::m_ini_value(const string& argv_value)   { *this = argv_value; }
m_ini_value::m_ini_value(const char* argv_value)     { *this = argv_value; }
m_ini_value::m_ini_value(const bool& argv_value)     { *this = argv_value; }

void m_ini_value::operator = (const int& argv_value)
{
    value_type = type_t::Int;
    value = std::to_string(argv_value);
}

void m_ini_value::operator = (const double& argv_value)
{
    value_type = type_t::Double;
    value = std::to_string(argv_value);
}

void m_ini_value::operator = (const string& argv_value)
{
    value_type = type_t::Str;
    value = argv_value;
}

void m_ini_value::operator = (const char* argv_value)
{
    value_type = type_t::Str;
    value = argv_value;
}

void m_ini_value::operator = (const bool& argv_value)
{
    value_type = type_t::Bool;
    if (argv_value)
        value = "true";
    else
        value = "false";
}

m_ini_value::operator int()
{
    return atoi(value.c_str());
}

m_ini_value::operator double()
{
    return atof(value.c_str());
}

m_ini_value::operator const char*()
{
    return value.c_str();
}

m_ini_value::operator string()
{
    return value;
}

m_ini_value::operator bool()
{
    return (value == "true");
}

int m_ini_value::to_int()          { return atoi(value.c_str()); }
double m_ini_value::to_double()    { return atof(value.c_str()); }
string& m_ini_value::to_str()      { return value; }
bool m_ini_value::to_bool()        { return (value == "true"); }
/***********************************************************************************************************/

m_ini::m_ini() {}
m_ini::m_ini(const string& argv_file_name)
{
    ifstream file_in(argv_file_name);

    if (!file_in.is_open())
        throw std::logic_error("文件打开失败");
    string name;
    string key;
    string value;
    string tmp_file_str;

    int l_fh = -1; 
    int r_fh = -1;
    int d_fh = -1;

    while (getline(file_in, tmp_file_str))
    {
        if (tmp_file_str.size() < 2)
            continue;

        d_fh = tmp_file_str.find_first_of('=');
        if (d_fh == -1)
        {
            l_fh = tmp_file_str.find('[');
            r_fh = tmp_file_str.find(']');
        }

        if (l_fh != -1 && r_fh  != -1)
        {
            string().swap(name);
            name = tmp_file_str.substr(l_fh +1, r_fh -1);
        }
        else if (d_fh != -1)
        {
            string().swap(key);
            string().swap(value);

            for (int i = 0; i < d_fh -1; ++i)
            {
                if (tmp_file_str[i] == ' ' || tmp_file_str[i] == '\t')
                    ++i;
                key += tmp_file_str[i];
            }

            for (int i = d_fh +1; i < tmp_file_str.size(); ++i)
            {
                if (tmp_file_str[i] == ' ' || tmp_file_str[i] == '\t' || tmp_file_str[i] == '\n' || tmp_file_str[i] == '\r')
                    ++i;
                value += tmp_file_str[i];
            }
            push_back(name, key, value);
        }

        l_fh = -1; 
        r_fh = -1;
        d_fh = -1;
    }

    file_in.close();
}


bool m_ini::count(const string& argv_key)
{
    return (ini_block.count(argv_key) == 1);
}

bool m_ini::count(const string& argv_name_key, const string& argv_value_name_key)
{
    if (count(argv_name_key))
    {
        return (ini_block[argv_name_key].count(argv_value_name_key) == 1);
    }

    return false;
}

bool m_ini::push_back(const string& argv_name, const string& argv_key, const string& argv_value)
{
    if (!count(argv_name))
    {
        ini_block[argv_name][argv_key] = argv_value;
        return true;
    }
    else if (!count(argv_name, argv_key))
    {
        ini_block[argv_name][argv_key] = argv_value;
        return true;
    }

    return false;  
}

m_ini_value m_ini::get(const string& argv_ini_block_name, const string& argv_ini_block_key)
{
    if (count(argv_ini_block_name, argv_ini_block_key))
        return ini_block[argv_ini_block_name][argv_ini_block_key];
    
    return m_ini_value();
}

void m_ini::show()
{
    for (auto a = ini_block.begin(); a != ini_block.end(); ++a)
    {
        cout << '[' << a->first << ']' << endl;

        for (auto b = (a->second).begin(); b != (a->second).end(); ++ b)
            cout << b->first << " : " << b->second.to_str() << endl;
        
        cout << endl << endl;
    }
}







