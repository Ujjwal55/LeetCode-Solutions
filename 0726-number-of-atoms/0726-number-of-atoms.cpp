class Solution {
public:
    map<string, int> helper(string formula)
    {
        map<string, int> m;
        string num;
        string atom;
        for(int i = 0; i < formula.size(); i++)
        {
            char c = formula[i];
            if(c == '(')
            {
                int cnt = 1;
                for(int j = i+1; j < formula.size(); j++)
                {
                    if(formula[j] == '(') cnt++;
                    if(formula[j] == ')') cnt--;
                    if(cnt == 0)
                    {
                        map<string, int> in = helper(formula.substr(i+1, j-i-1));
  
                        string num;
         
                        int k = j+1;
         
                        if(k < formula.size() && formula[k] >= '0' && formula[k] <= '9')
                        {
                            
                            while(k < formula.size() && formula[k] >= '0' && formula[k] <= '9')
                            {
                                num.push_back(formula[k]);
                                k++;
                            }
                        }
     
                        int p = num.size() == 0 ? 1 : stoi(num);
                        for(map<string, int>::iterator it = in.begin(); it != in.end(); it++)
                        {
                            m[it->first] += it->second*p;
                        }
                        i = k; i--;                        
                        break;
                    }
                }              
            }
            else if(c >= '0' && c <='9')
            {
                num.push_back(c);
            }
            else if(c >= 'A' && c <= 'Z')
            {
                atom.push_back(c);
            }
            else if(c >= 'a' && c <= 'z')
            {
                atom.push_back(c);
            }
            if(i == formula.size()-1 || (formula[i+1]>= 'A' && formula[i+1] <= 'Z'))
            {
                int cnt = num.size() == 0 ? 1 : stoi(num);
                if(atom.size()) m[atom] += cnt;
                num = "";
                atom = "";
            }
        }
        return m;
    }
    
    string countOfAtoms(string formula) {
        map<string, int> m = helper(formula);
        string out;
        for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            out += it->first + (it->second > 1 ? to_string(it->second) : "");    
        }
        return out;
    }
};