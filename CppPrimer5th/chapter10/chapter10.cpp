#include "chapter10.h"
#include "../chapter7/chapter7.h"

int exercise10_1()
{
    vector<int> vint;

    int temp = 0, target = 10, count = 0;

    cout << "Target is " << target << endl;
    while (cin >> temp)
    {
        vint.push_back(temp);
    }
    rangeForVector(vint);

    auto a = find(vint.cbegin(), vint.cend(), target);

    cout << "The target" << (a == vint.cend() ? " is not present" : " is present") << endl;

    while (a != vint.cend())
    {
        if (count == 0)
        {
            ++count;
        }
        else
        {
            //  REMEMBER: find returns the iterator that match the target!!!!
            a = find(a + 1, vint.cend(), target);
            count += (a == vint.cend()) ? 0 : 1;
        }
    }

    cout << "The target appears " << count << " times." << endl;
    return 0;
}

int exercise10_2()
{

    vector<string> vstr;

    string temp, target = "target";
    int count = 0;

    cout << "Target is " << target << endl;
    while (getline(cin, temp))
    {
        vstr.push_back(temp);
    }
    rangeForVector(vstr);

    auto a = find(vstr.cbegin(), vstr.cend(), target);

    cout << "The target" << (a == vstr.cend() ? " is not present" : " is present") << " at position " << (a - vstr.cbegin()) << endl;

    while (a != vstr.cend())
    {
        if (count == 0)
        {
            ++count;
        }
        else
        {
            //  REMEMBER: find returns the iterator that match the target!!!!
            a = find(a + 1, vstr.cend(), target);
            count += (a == vstr.cend()) ? 0 : 1;
        }
    }

    cout << "The target appears " << count << " times." << endl;
    return 0;
}
int exercise10_3()
{
    vector<int> vint;

    int temp = 0, target = 0;
    while (cin >> temp)
    {
        vint.push_back(temp);
    }
    rangeForVector(vint);

    target = accumulate(vint.cbegin(), vint.cend(), target);

    cout << "Sum of this vector is " << target << endl;

    return 0;
}

int exercise10_4()
{

    vector<double> vd;

    double temp, target;
    while (cin >> temp)
    {
        vd.push_back(temp);
    }
    rangeForVector(vd);

    // Answer: 0 is not type of double, but maybe the compiler will do the implicit conversion.
    target = accumulate(vd.cbegin(), vd.cend(), 0);

    cout << "Sum of this vector is " << target << endl;

    return 0;
}

int exercise10_5()
{
    // vector<char *> roster1{"abc", "def", "xyz"};
    // vector<char *> roster2{"abc", "def", "xyz"};

    // 在C++中，std::equal算法是用来比较两个序列是否相等的。
    // 当你使用std::equal来比较两个std::vector<char*>时，它实际上是在比较两个序列中的每一对指针是否相等，而不是比较它们所指向的字符串内容是否相等。
    // 这里roster1和roster2是两个不同的std::vector对象，但它们包含了相同的字符串字面量的指针。
    // 在C++中，字符串字面量通常存储在程序的只读内存段中，并且相同的字符串字面量往往会被合并，使得多个相同的字符串字面量实际上指向内存中的同一个位置。这是一种称为字符串字面量池化的优化。

    // cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());

    return 0;
}

int exercise10_6()
{
    vector<int> vint;

    int temp = 0, target = 0;
    while (cin >> temp)
    {
        vint.push_back(temp);
    }
    rangeForVector(vint);

    fill_n(vint.begin(), vint.size(), 0);

    rangeForVector(vint);

    return 0;
}
int exercise10_7()
{

    list<int> lst;
    int i;
    while (cin >> i)
    {
        lst.push_back(i);
    }
    vector<int> vec1(lst.size());
    copy(lst.cbegin(), lst.cend(), vec1.begin());
    rangeForVector(vec1);

    vector<int> vec2(10, 2);
    rangeForVector(vec2);
    fill_n(vec2.begin(), 10, 0);
    rangeForVector(vec2);
    return 0;
}

int exercise10_8()
{
    return 0;
}

void elimDups(vector<string> &words)
{
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());
    cout << "After sort: " << endl;
    rangeForVector(words);
    // unique words
    // The elements beyond that enc_unique still exist, but we don’t know what values they have
    // (MEANS: unique function may change the VALUE!!!).
    // auto end_unique = unique(words.begin(), words.end());
    // cout << "After unique: " << endl;
    // rangeForVector(words);
    // erase non-unique elements
    // words.erase(end_unique, words.end());
}

int exercise10_9()
{
    vector<string> wds{"abc", "bcd", "def", "abc", "bcd", "def", "abc", "bcd", "def", "abc", "bcd", "def"};
    cout << "Original: " << endl;
    rangeForVector(wds);

    elimDups(wds);

    cout << "After elimDups: " << endl;
    rangeForVector(wds);
    return 0;
}

int exercise10_10()
{
    return 0;
}

bool isShorter(const string &str1, const string &str2)
{
    return (str1.size() < str2.size()) ? true : false;
}

void elimDups_sort_shorter(vector<string> &words)
{
    sort(words.begin(), words.end(), isShorter);
    cout << "After sort shorter: " << endl;
    rangeForVector(words);
    // unique words
    // The elements beyond that enc_unique still exist, but we don’t know what values they have
    // (MEANS: unique function may change the VALUE!!!).
    auto end_unique = unique(words.begin(), words.end());
    cout << "After unique: " << endl;
    rangeForVector(words);
    // erase non-unique elements
    words.erase(end_unique, words.end());
}

void elimDups_stable_sort_shorter(vector<string> &words)
{
    stable_sort(words.begin(), words.end(), isShorter);
    cout << "After stable sort shorter: " << endl;
    rangeForVector(words);
    // unique words
    // The elements beyond that enc_unique still exist, but we don’t know what values they have
    // (MEANS: unique function may change the VALUE!!!).
    auto end_unique = unique(words.begin(), words.end());
    cout << "After unique: " << endl;
    rangeForVector(words);
    // erase non-unique elements
    words.erase(end_unique, words.end());
}

int exercise10_11()
{
    vector<string> wds{"abdce", "bcd", "abd", "defhhaserahoh", "abc", "abc", "abd"};
    vector<string> wds_copy(wds);
    cout << "Original: " << endl;
    rangeForVector(wds);

    elimDups_sort_shorter(wds);

    cout << "After sort shorter elimDups: " << endl;
    rangeForVector(wds);

    elimDups_stable_sort_shorter(wds_copy);

    cout << "After stable sort shorter elimDups: " << endl;
    rangeForVector(wds_copy);

    return 0;
}

bool compareIsbn(const Sales_data &a, const Sales_data &b)
{
    return (a.isbn() < b.isbn()) ? true : false;
}

int exercise10_12()
{
    Sales_data a("9", 10, 1.1);
    Sales_data b("A", 20, 2.2);
    Sales_data c("a", 30, 3.2);

    vector<Sales_data> vecSD{a, c, b};

    cout << "Before sort : " << endl;
    for (auto temp = vecSD.begin(); temp != vecSD.end(); ++temp)
    {
        print(cout, *temp);
        cout << endl;
    }

    sort(vecSD.begin(), vecSD.end(), compareIsbn);

    cout << "After sort : " << endl;
    for (auto temp = vecSD.begin(); temp != vecSD.end(); ++temp)
    {
        print(cout, *temp);
        cout << endl;
    }

    return 0;
}

bool atLeast5Chars(const string &a)
{
    return (a.size() >= 5) ? true : false;
}

int exercise10_13()
{

    vector<string> wds{"abdce", "bcd", "abd", "defhhaserahoh", "abc", "abc", "abd"};

    auto itWds = partition(wds.begin(), wds.end(), atLeast5Chars);

    cout << "true items:" << endl;
    for (auto temp = wds.begin(); temp != itWds; ++temp)
    {
        cout << *temp << ",";
    }

    cout << endl
         << "false items: " << endl;

    for (auto temp = itWds; temp != wds.end(); ++temp)
    {
        cout << *temp << ",";
    }

    return 0;
}

int exercise10_14()
{

    auto f1 = [](int a, int b) -> int
    { return a + b; };

    cout << f1(1, 2) << endl;

    return 0;
}

int exercise10_15()
{
    int sz = 100;

    auto f1 = [sz](int a) -> int
    { return a + sz; };

    cout << f1(1) << endl;

    return 0;
}

void biggies(vector<string> &words, vector<string>::size_type wordSize)
{
    elimDups(words);

    auto isShorterLambda = [](const string &str1, const string &str2) -> bool
    {
        return (str1.size() < str2.size()) ? true : false;
    };

    stable_sort(words.begin(), words.end(), isShorterLambda);

    auto it = std::find_if(words.begin(), words.end(), [wordSize](string &word)
                           { return (wordSize <= word.size()) ? true : false; });

    if (it != words.end())
    {
        cout << "Biggies found: ";
        while (it != words.end())
        {
            cout << *(it++) << " ";
        }
    }
    else
    {
        cout << "Biggies not found. ";
    }
    cout << endl;
}

int exercise10_16()
{

    vector<string> wds{"bcded", "defhhaserahoh", "abc", "abdc"};
    cout << "Original: " << endl;
    rangeForVector(wds);

    biggies(wds, wds.size());
    return 0;
}

int exercise10_17()
{
    Sales_data a("9", 10, 1.1);
    Sales_data b("A", 20, 2.2);
    Sales_data c("a", 30, 3.2);

    vector<Sales_data> vecSD{b, c, a};

    cout << "Before sort : " << endl;
    for (auto temp = vecSD.begin(); temp != vecSD.end(); ++temp)
    {
        print(cout, *temp);
        cout << endl;
    }

    auto compareIsbnLambda = [](const Sales_data &a, const Sales_data &b) -> bool
    {
        return (a.isbn() < b.isbn()) ? true : false;
    };

    sort(vecSD.begin(), vecSD.end(), compareIsbnLambda);

    cout << "After sort : " << endl;
    for (auto temp = vecSD.begin(); temp != vecSD.end(); ++temp)
    {
        print(cout, *temp);
        cout << endl;
    }

    return 0;
}

void biggiesPartition(vector<string> &words, vector<string>::size_type wordSize)
{
    elimDups(words);

    auto isShorterLambda = [](const string &str1, const string &str2) -> bool
    {
        return (str1.size() < str2.size()) ? true : false;
    };

    stable_sort(words.begin(), words.end(), isShorterLambda);

    auto it = partition(words.begin(), words.end(), [wordSize](string &word)
                        { return (word.size() < wordSize) ? true : false; });

    if (it != words.end())
    {
        cout << "Biggies found: ";
        while (it != words.end())
        {
            cout << *(it++) << " ";
        }
    }
    else
    {
        cout << "Biggies not found. ";
    }
    cout << endl;
}

int exercise10_18()
{
    // vector<string> wds{"bcdede", "defhhaserahoh", "abc", "abdc", "bcdade"};
    vector<string> wds{"apple", "banana", "orange", "banana", "apple"};
    cout << "Original: " << endl;
    rangeForVector(wds);

    biggiesPartition(wds, wds.size());
    return 0;
}

void biggiesStablePartition(vector<string> &words, vector<string>::size_type wordSize)
{
    elimDups(words);

    auto isShorterLambda = [](const string &str1, const string &str2) -> bool
    {
        return (str1.size() < str2.size()) ? true : false;
    };

    stable_sort(words.begin(), words.end(), isShorterLambda);

    auto it = stable_partition(words.begin(), words.end(), [wordSize](string &word)
                               { return (word.size() < wordSize) ? true : false; });

    if (it != words.end())
    {
        cout << "Biggies found: ";
        while (it != words.end())
        {
            cout << *(it++) << " ";
        }
    }
    else
    {
        cout << "Biggies not found. ";
    }
    cout << endl;
}

int exercise10_19()
{
    // Actually,
    // vector<string> wds{"bcdede", "defhhaserahoh", "abc", "abdc", "bcdade"};
    vector<string> wds{"apple", "banana", "orange", "banana", "apple"};
    cout << "Original: " << endl;
    rangeForVector(wds);

    biggiesStablePartition(wds, wds.size());

    return 0;
}

int compare_sort_and_stable_sort()
{
    // Create a vector of pairs with first element as integer and second element as string
    std::vector<std::pair<int, std::string>> vec = {
        {3, "Three"},
        {1, "One"},
        {2, "Two"},
        {3, "Another Three"},
        {2, "Another Two"},
        {1, "Another One"}};

    // Copy the vector to perform two separate sorts
    std::vector<std::pair<int, std::string>> vec_sort = vec;
    std::vector<std::pair<int, std::string>> vec_stable_sort = vec;

    // Time measurement
    auto start_sort = std::chrono::steady_clock::now();
    sort(vec_sort.begin(), vec_sort.end());
    auto end_sort = std::chrono::steady_clock::now();

    auto start_stable_sort = std::chrono::steady_clock::now();
    stable_sort(vec_stable_sort.begin(), vec_stable_sort.end());
    auto end_stable_sort = std::chrono::steady_clock::now();

    // Output sorted vectors
    cout << "sort result:" << endl;
    for (const auto &elem : vec_sort)
    {
        cout << elem.first << ": " << elem.second << endl;
    }
    cout << endl;

    cout << "stable_sort result:" << endl;
    for (const auto &elem : vec_stable_sort)
    {
        cout << elem.first << ": " << elem.second << endl;
    }
    cout << endl;

    // Output time taken
    cout << "sort time: " << std::chrono::duration<double>(end_sort - start_sort).count() << " seconds" << endl;
    cout << "stable_sort time: " << std::chrono::duration<double>(end_stable_sort - start_stable_sort).count() << " seconds" << endl;

    return 0;
}

int exercise10_20()
{
    string::size_type length = 5;
    vector<string> wds{"bcdede", "defhhaserahoh", "abc", "abdc", "bcdade"};
    rangeForVector(wds);

    auto f1 = [](const string &str, string::size_type len) -> bool
    {
        if (str.size() <= len)
            return false;
        else
            return true;
    };
    // bind argument(实参) to the second parameter(形参).
    auto f2 = std::bind(f1, _1, length);

    auto result = std::count_if(wds.cbegin(), wds.cend(), f2);

    cout << "Words that have length more than " << length << " are: " << result << endl;

    return 0;
}

int exercise10_21()
{
    int t = 0;
    cin >> t;
    cout << "Input int is: " << t << endl;

    auto f1 = [&t]() -> bool
    {
        while (t > 0)
        {
            --t;
        }
        if (t == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    bool result = f1();
    cout << "current int is " << t << endl;
    cout << "Is the result of f1 equal to zero ? " << result << endl;

    return 0;
}
int exercise10_22()
{
    string::size_type length = 6;
    vector<string> wds{"bcdede", "defhhaserahoh", "abc", "abdc", "bcdade"};
    rangeForVector(wds);

    auto f1 = [](const string &str, string::size_type len) -> bool
    {
        if (str.size() <= len)
            return true;
        else
            return false;
    };
    // bind argument(实参) to the second parameter(形参).
    auto f2 = std::bind(f1, _1, length);

    auto result = std::count_if(wds.cbegin(), wds.cend(), f2);

    cout << "Words that have length less than or equal " << length << " are: " << result << endl;

    return 0;
}
int exercise10_23()
{
    return 0;
}

int exercise10_24()
{
    auto check_size = [](const string &str, string::size_type len) -> bool
    {
        if (str.size() >= len)
            return true;
        else
            return false;
    };

    vector<int> intV{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -100};
    string sample("wds");

    auto f2 = bind(check_size, sample, _1);

    auto itInt = find_if(intV.cbegin(), intV.cend(), f2);

    cout << *itInt << endl;

    return 0;
}

void biggiesUsingBind(vector<string> &words, vector<string>::size_type wordSize)
{
    elimDups(words);
    auto check_size = [](const string &str, string::size_type len) -> bool
    {
        if (str.size() < len)
            return true;
        else
            return false;
    };
    auto f2 = bind(check_size, _1, wordSize);
    auto it = stable_partition(words.begin(), words.end(), f2);

    if (it != words.end())
    {
        cout << "Biggies found: ";
        while (it != words.end())
        {
            cout << *(it++) << " ";
        }
    }
    else
    {
        cout << "Biggies not found. ";
    }
    cout << endl;
}

int exercise10_25()
{
    vector<string> wds{"bcdede", "defhhaserahoh", "abc", "abdc", "bcdade"};
    // vector<string> wds{"apple", "banana", "orange", "banana", "apple"};
    cout << "Original: " << endl;
    rangeForVector(wds);

    biggiesUsingBind(wds, wds.size());

    return 0;
}
int exercise10_26()
{
    return 0;
}
int exercise10_27()
{
    return 0;
}
int exercise10_28()
{
    return 0;
}
int exercise10_29()
{
    return 0;
}
int exercise10_30()
{
    return 0;
}
int exercise10_31()
{
    return 0;
}
int exercise10_32()
{
    return 0;
}
int exercise10_33()
{
    return 0;
}
int exercise10_34()
{
    return 0;
}
int exercise10_35()
{
    return 0;
}
int exercise10_36()
{
    return 0;
}
int exercise10_37()
{
    return 0;
}
int exercise10_38()
{
    return 0;
}
int exercise10_39()
{
    return 0;
}
int exercise10_40()
{
    return 0;
}
int exercise10_41()
{
    return 0;
}
int exercise10_42()
{
    return 0;
}