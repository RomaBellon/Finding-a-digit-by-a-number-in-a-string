
#include <iostream>
#include<string>
#include <cctype>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    int count,number;
    string stroka,result,number1;
    
    cout << "Введите фразу (строку): ";
    getline(cin, stroka);
    
    try{
    cout << "Введите номер цифры: "; // Проверка на ввод символов, а не цифры
    cin >> number1;
    number = stod(number1);
    }
    catch(const invalid_argument&){
        cout << "Номер цифры может быть только числом, введите данные заного"; 
        return -1;
    }
    
    
    for (int i; i < stroka.length(); i++){
        if (isdigit(stroka[i])){
            count += 1;
        }
        if (number == count){
            result = stroka[i];
            break;
        }
    }
    if (count < number){
        cout << "Цифры под номером " << number << " не существует"; // проверка на существование номера
        return -1;
    }
    
    if (count == 0){
        cout << "В вышей фразе (строке) нет ни одной цифры"; // проверка на наличие цифры в строке
        return -1;
    }

    
    cout << "Цифрой номер " << number << " является " << result << endl;
    

    return 0;
}



