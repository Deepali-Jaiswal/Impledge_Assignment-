#include <bits/stdc++.h>   //importing the library
using namespace std;
using namespace std::chrono;


//.......................................implementing trie data structure........................................................

struct Trie                 
{
    Trie *nodes[26];
    bool flag;
    bool check(char ch)
    {
        return nodes[ch - 'a'] != NULL;
    }
    Trie *take(char ch)
    {
        return nodes[ch - 'a'];
    }
    void update(char ch, Trie *node)
    {
        nodes[ch - 'a'] = node;
        return;
    } 
    void set_false()
    {
        flag = false;
        return;
    }
    void set_complete()
    {
        flag = true;
        return;
    }
    bool is_complete()
    {
        return flag;
    } 
};

//.............................................implementing class and functions accordingly.............................................

class Compute                                    
{
    Trie *root;

public:
     Compute()
    {
        root = new Trie();
    }

    static bool comp(string first, string second)   //sorting the string
    { 
        if (first.length() == second.length())
            return first < second;
        return first.length() > second.length();
    }

    void word_initialization(string str)          // function for initializing the word in trie
    {
        Trie *node = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (!node->check(str[i]))
            {
                node->update(str[i], new Trie());
            }
            node = node->take(str[i]);
        }
        node->set_complete();
    }

    
    bool is_the_word_formed(string str, int index, Trie *temp_node)   // used to check formed by other words or not
    {
        if (index == str.length())
        {
            return temp_node->is_complete();
        }
        if (temp_node->is_complete())
        {
            if (is_the_word_formed(str, index, root))
                return true;
        }
        if (temp_node->check(str[index]))
        {
            return is_the_word_formed(str, index + 1, temp_node->take(str[index]));
        }
        else
        {
            return false;
        }
    }

    void reset_flag(string str, int ind, Trie *temp_node)   // function for reseting the flag
    {
        if (ind == str.length())
        {
            temp_node->set_false();
            return;
        }
        reset_flag(str, ind + 1, temp_node->take(str[ind]));
        return;
    }

    void find_Longest_Word(vector<string> &word)    //for finding the longest word for the given input
    {
        vector<string> answer;
        for (int i = 0; i < word.size(); i++)
        {
            answer.push_back(word[i]);
            word_initialization(word[i]);
        }
        sort(answer.begin(), answer.end(), comp);   // for finding the answer in less time we sort the answer vector from longest to shortest
        string answer1 = "", answer2 = "";
        for (int i = 0; i < answer.size(); i++)
        {
            reset_flag(answer[i], 0, root);                    //used to setting the flag again for second largest word

            if (is_the_word_formed(answer[i], 0, root))
            {
                if (answer1.length() == 0)
                    answer1 = answer[i];
                else
                {
                    answer2 = answer[i];
                    break;
                }
            }
            word_initialization(answer[i]);                // used to mark the end of the word
        }
        cout << "Longest Compounded word: " << answer1 << endl;
        cout << "Second Longest Compounded word: " << answer2 << endl;
        return;
    }
};

// from here the driver code starts

int main()
{
    Compute obj;
    fstream fs;
    vector<string> answer;                       //holding input data
    fs.open("Input_02.txt", ios::in);
    if (fs.fail())
    {
        cout << "file not imported";
    }
    else
    {
        string s;
        while (fs >> s)
        {
            answer.push_back(s);
        }
        fs.close();

        auto initial_time = high_resolution_clock::now();
        obj.find_Longest_Word(answer);
        auto end_time = high_resolution_clock::now();
        auto time_taken = duration_cast<milliseconds>(end_time - initial_time);  //typecasting
        cout << "Time taken to process the inupdate file: " << time_taken.count() << " milliseconds" << endl;
    }
    return 0;
}
