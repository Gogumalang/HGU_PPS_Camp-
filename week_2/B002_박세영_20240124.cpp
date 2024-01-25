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
    int reculsive(vector<Employee*> employees, Employee* element) {
        int sum =0;
        if(element->subordinates.empty()) return element->importance;
        for(int i =0;i< element->subordinates.size();i++) {
            for(int j =0;j< employees.size();j++) {
                if(element->subordinates[i] == employees[j]->id) sum += reculsive(employees,employees[j]);
            }
        }
        sum += element->importance;
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int ans;
        for(int i =0;i< employees.size();i++) {
            if(id == employees[i]->id)  ans = reculsive(employees,employees[i]);
        }
        return ans;
    }
};