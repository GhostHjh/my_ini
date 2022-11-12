## 这是一个很简单的 INI 解析器

# 1.ini 值的类型

> * 基础类型
>   ```c++
>   //m_ini()一共有 6 种类型
>   bool    (布尔类型)
>   int     (整数类型)
>   double  (浮点类型)
>   string  (字符串类型)
>   struct  (ini的结构类型, string为key, value为一个key为string, value为ini的map)
>
>   ```

# 2.构造方式

> * 使用 __类型__ 构造
>
>   ```c++
>   //可以直接使用变量进行构造
>   m_ini(true);
>   m_ini(123);
>   m_ini(123.123);
>   m_ini("string");
>
>
>   //也可以使用 "=" 来构造(注意, 使用这个方法时, 会销毁原来的值)
>   m_ini() = true;
>   m_ini() = 123;
>   m_ini() = 123.123;
>   m_ini() = "string";
>
>   ```
> * 使用 __ini格式文件__ 构造
>
>   ```c++
>   //使用一个INI文件来构造, m_ini将读取这个文件并解析它
>   m_ini("ini文件路径");
>   ```

# 3.获取值的方法

> * 使用 "=" 获取值
>
>   ```c++
>   //直接使用 "=" 来获取基础类型的值
>   bool   tmp_bool   = m_ini(ture);
>   int    tmp_int    = m_ini(123);
>   double tmp_double = m_ini(123.123);
>   string tmp_string = m_ini("string");
>
>
>   //获取 "strtus" 中的值
>   m_ini  tmp_int    = m_ini()["string"]["string"];     //数组
>   ```
> * 使用自带的函数来获取值
>
>   ```c++
>   bool   tmp_bool   = m_ini(ture).to_bool();
>   int    tmp_int    = m_ini(123).to_int();
>   double tmp_double = m_ini(123.123).to_double();
>   string tmp_string = m_ini("string").to_str();
>   ```

# 4.显示当前ini对象的内容

> * 直接显示
>
>   ```c++
>   m_ini().show();
>   ```

