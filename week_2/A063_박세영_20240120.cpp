class Solution {
public:
    string addBinary(string a, string b) {
        stack<char> reverse_ans;
        int carry =0; 
        int index_a = a.length()-1;
        int index_b = b.length()-1;

        while(1) {
            int integer_a = a[index_a] - '0';
            int integer_b = b[index_b] - '0';
            int sum = integer_a + integer_b + carry;

            if(sum ==0) {
                reverse_ans.push('0');
                carry = 0;
            } else if(sum ==1) {
                reverse_ans.push('1');
                carry = 0;
            }else if(sum ==2) {
                reverse_ans.push('0');
                carry = 1;
            }else {
                reverse_ans.push('1');
                carry = 1;
            }
            index_a --;
            index_b --;
            
            if(index_a <0) {
                while(index_b>=0){
                    integer_b = b[index_b] - '0';
                    sum = integer_b + carry;
                    if(sum ==0) {
                        reverse_ans.push('0');
                        carry = 0;
                    } else if(sum ==1) {
                        reverse_ans.push('1');
                        carry = 0;
                    }else if(sum ==2) {
                        reverse_ans.push('0');
                        carry = 1;
                    }
                    index_b --;
                }
                if(carry == 1) reverse_ans.push('1');
                break;
            }
            else if(index_b <0) {
                while(index_a>=0){
                    integer_a = a[index_a] - '0';
                    sum = integer_a + carry;
                    if(sum ==0) {
                        reverse_ans.push('0');
                        carry = 0;
                    } else if(sum ==1) {
                        reverse_ans.push('1');
                        carry = 0;
                    }else if(sum ==2) {
                        reverse_ans.push('0');
                        carry = 1;
                    }
                    index_a --;
                }
                if(carry == 1) reverse_ans.push('1');
                break;
            }
            
        }
        string ans;
        int i = 0;
        while(!reverse_ans.empty()) {
            ans += reverse_ans.top();
            reverse_ans.pop();
        }

        return ans;
    }
};

// char 벡터 생성 : 뒤에서부터 비교, 결과를 뒤집기 위함(새로운 변수를 만들고 뒤에서 부터 넣을 수 없다고 생각, 그리고 결과 길이도 일정하지 않기 때문)
        
//         길이가 다르기 때문에 각 길이를 구하고 인덱싱할 변수를 선언 
//         carry 변수 선언 하고 0 으로 초기화 

//         반복문
//             문자열들 끝에서부터 두개를 비교. 
//             ascii를 가지고 정수로 변경 
//             문자열들 + carry 의 합을 구함. 
//             0 이라면 벡터에 '0'을 저장 carry 에 0
//             1 이라면 벡터에 '1' 을 저장 carry 에 0
//             2 이라면 벡터에 '0' 을 저장 carry 에 1 
//             3 이라면 벡터에 '1' 을 저장 carry 에 1 
            
//             인덱싱 변수들 -1 
//             만약 둘중 하나가 0보다 작다. 
//                 나머지 연산 전 carry와 나머지를 더한 값을 저장한다. 
//                 나머지 연산을 위한 반복문 
//                     나머지 하나의 인덱스 변수가 0이 될때까지 
//                     벡터에 넣음 

//         결과물 문자열 생성
//         스택에서 꺼내면서 저장

// class Solution {
// public:
//     string addBinary(string a, string b) {
//         string result = "";
//         int temp = 0;
//         int size_a = a.size() - 1;
//         int size_b = b.size() - 1;
//         while (size_a >= 0 || size_b >= 0 || temp == 1){
//             temp += ((size_a >= 0)? a[size_a] - '0': 0);
//             temp += ((size_b >= 0)? b[size_b] - '0': 0);
//             result = char(temp % 2 + '0') + result;
//             temp /= 2;
//             size_a--; size_b--;
//         }
//    return result;
//     }
// };