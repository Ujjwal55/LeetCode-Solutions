/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int calculateImportance(vector<Employee*> employees, vector<int> ids, int n){
        if(ids.size() == 0) return 0;
        int imp = 0;
        for(int i = 0 ; i < ids.size() ; i++){
            for(int j = 0 ; j < n ; j++){
                if(ids[i] == employees[j]->id){
                    imp += employees[j]->importance;
                    imp += calculateImportance(employees, employees[j]->subordinates, n);
                }
            }
        }
        return imp;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        int imp = 0;
        for(int i = 0 ; i < n ; i++){
            if(employees[i]->id == id){
                imp += employees[i]->importance;
                imp += calculateImportance(employees, employees[i]->subordinates, n);
            }
        }
        return imp;
    }
};