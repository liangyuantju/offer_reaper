#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

string getFileName(string path)
{
    int pos = path.rfind("\\");
    //cout<<"pos: "<<pos<<endl;
    return path.substr(pos+1);
}

string modifyName(string name)
{
    if(name.size() > 16)
    {
        return name.substr(name.size()-16);
    }
    return name;
}

struct ErrRecord{
    string filename;
    int line;
    int count;

    ErrRecord(string file, int line)
    {
        this->filename = file;
        this->line = line;
        this->count = 1;
    }

    bool operator ==(const ErrRecord &a)
    {
        return (a.filename == filename) && (a.line == line);
    }
};

int main()
{
    string file;
    int lineNo;
    vector<ErrRecord> myvec;
    while(cin >> file >> lineNo){
        ErrRecord record(getFileName(file),lineNo);
        vector<ErrRecord>::iterator res = find(myvec.begin(), myvec.end(), record);
        if(res == myvec.end()){
            myvec.push_back(record);
        } else {
            res->count++;
        }
    }

    int count = 0;
    for(vector<ErrRecord>::iterator it = myvec.begin(); it <= myvec.end(); it++) {
        if(count + 8 >= myvec.size()){
            cout<< modifyName(it->filename) << it->line << it->count <<endl;
        }
        count++;
    }
    return 0;
}