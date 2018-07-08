#include <iostream>
#include <string>
#include <map>
#include <set>
#include <assert.h>
#include "myassert.h"

using namespace std;
using synonyms_dict = map<string, set<string>>;

void addSynonyms(synonyms_dict &synonyms, const string &f_word,
                 const string &s_word)
{
    synonyms[s_word].insert(f_word);
    synonyms[f_word].insert(s_word);
}


void testAddSynonyms()
{
    {
        synonyms_dict dict;
        addSynonyms(dict, "a", "b");
        const synonyms_dict expected = {
            {"a", {"b"}},
            {"b", {"a"}},
        };
        AssertEqual(dict, expected, "add empty case");
//        assert(dict == expected);
    }

    {
        synonyms_dict dict = {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}},
        };

        addSynonyms(dict, "a", "c");

        const synonyms_dict expected = {
            {"a", {"b", "c"}},
            {"b", {"a", "c"}},
            {"c", {"b", "a"}},
        };
//        assert(dict == expected);
    }
}


size_t getSynonymsCount(synonyms_dict &synonyms, const string &word)
{
    return synonyms[word].size();
}


void testCount()
{
    {
        synonyms_dict dict;
        AssertEqual(getSynonymsCount(dict, "a"),  0u, "empty case");
//        assert(getSynonymsCount(dict, "a") == 0);
    }

    {
        synonyms_dict dict =  {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}},
        };

//        AssertEqual(getSynonymsCount(dict, "a"), 1);
//        AssertEqual(getSynonymsCount(dict, "b"), 2);
//        AssertEqual(getSynonymsCount(dict, "c"), 1);
//        AssertEqual(getSynonymsCount(dict, "d"), 0);


//        assert(getSynonymsCount(dict, "a") == 1);
//        assert(getSynonymsCount(dict, "b") == 2);
//        assert(getSynonymsCount(dict, "c") == 1);
//        assert(getSynonymsCount(dict, "d") == 0);
    }
}

bool checkSynonyms(synonyms_dict &synonyms, const string &f_word,
                   const string &s_word)
{
    if (synonyms[f_word].count(s_word) == 1)
    {
        return true;
    }

    return false;
}

void testCheckSynonyms()
{
    {
        synonyms_dict dict;
        Assert(!checkSynonyms(dict, "a", "b"), "empty case");
//        assert(!checkSynonyms(dict, "a", "b"));
//        assert(!checkSynonyms(dict, "b", "a"));
    }

    {
        synonyms_dict dict =  {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}},
        };

//        assert(checkSynonyms(dict, "a", "b"));
//        assert(checkSynonyms(dict, "b", "c"));
//        assert(!checkSynonyms(dict, "c", "a"));

    }
}

void testAll()
{
//    testCount();
//    testCheckSynonyms();
//    testAddSynonyms();

//    try
//    {
//        testCount();
//    }
//    catch (runtime_error& e)
//    {
//        cout << "Test count fail" << endl;
//    }

    TestRunner test_run;
    test_run.runTest(testCount, "Count");
    test_run.runTest(testCheckSynonyms, "CheckSynonyms");
    test_run.runTest(testAddSynonyms, "AddSynonyms");
}

int main()
{

    testAll();
    return 0;


    int q;
    cin >> q;

    synonyms_dict synonyms;

    for(int i = 0; i < q; i++)
    {
        string operator_code;
        cin >> operator_code;

        if (operator_code == "ADD")
        {
            string first_word, second_word;
            cin >> first_word >> second_word;
            addSynonyms(synonyms, first_word, second_word);
//            synonyms[second_word].insert(first_word);
//            synonyms[first_word].insert(first_word);

        }
        else if (operator_code == "COUNT")
        {
            string word;
            cin >> word;
            cout << getSynonymsCount(synonyms, word) << endl;
//            cout << synonyms[word].size() << endl;
        }
        else if (operator_code == "CHECK")
        {
            string first_word, second_word;
            cin >> first_word >> second_word;
            if (checkSynonyms(synonyms, first_word, second_word))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }

    }
    return 0;
}
