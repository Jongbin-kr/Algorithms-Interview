/*
  [C++ FizzBuzz 심화 학습 노트 (Pythonic to C++)]

  1. 메모리 전략: reserve() vs 초기화 📏
     - 'vector<string> res(n)'은 n개의 string 객체를 생성(기본 생성자 호출)합니다.
     - 'res.reserve(n)'은 메모리 공간만 예약하고 객체는 생성하지 않습니다.
     - 대량의 데이터를 다룰 땐 reserve() 후 emplace_back()을 쓰는 것이 객체 생성/복사 비용을 줄이는 데 유리합니다.

  2. 객체 생성 최적화: emplace_back() vs push_back() 🚀
     - push_back(): 임시 객체를 만든 뒤 벡터로 '복사' 또는 '이동'합니다.
     - emplace_back(): 벡터가 가진 메모리 공간 안에서 객체를 '직접 생성'하여 중간 단계의 낭비를 없앱니다.

  3. 소유권 이전: std::move() 📦
     - 이미 생성된 큰 객체(긴 string 등)를 벡터에 넣을 때, 값을 복사하는 대신
       메모리 주소만 쏙 옮겨주는 '이동 연산'을 통해 성능을 극대화할 수 있습니다.

  4. 데이터 접근 효율성 📍
     - 인덱스 접근(res[i])은 경계 검사를 하지 않아 가장 빠르지만 위험할 수 있습니다.
     - 안전한 접근이 필요하다면 경계 검사를 수행하는 'res.at(i)' 사용을 고려합니다.
*/

#include <vector>

using namespace std;


#include <vector>

using namespace std;


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        // res.reserve(n);   // NOTE: 메모리 미리 할당해두기. 빈 값을 만드는 건 아님!
        
        for (int i=1; i<=n; i++){
            if ((i % 3 == 0) && (i % 5 == 0)) { res.push_back("FizzBuzz"); }
            else if (i % 3 == 0){ res.push_back("Fizz"); }
            else if (i % 5 == 0){ res.push_back("Buzz"); }
            else { res.push_back(to_string(i)); }
        }
        return res;
    }
    
};





// class Solution {
// public:
//     vector<string> fizzBuzz(int n) {
//         vector<string> res(n);
        
//         for (int i=1; i<=n; i++){
//             if ((i % 3 == 0) && (i % 5 == 0)) { res[i-1] = ("FizzBuzz"); }
//             else if (i % 3 == 0){ res[i-1] = ("Fizz"); }
//             else if (i % 5 == 0){ res[i-1] = ("Buzz"); }
//             else { res[i-1] = (to_string(i)); }
//         }
//         return res;
//     }
    
// };

